#include <iostream>
#include <memory>
#include <odb/sqlite/database.hxx>
#include <odb/transaction.hxx>
#include <odb/schema-catalog.hxx>

#include "DatabaseManager.hxx"
#include "Employee.hpp"
#include "Menu.hpp"

int main() {
    DatabaseManager dbManager("employees.db");
    Employee employee(dbManager);
    Menu menu;
    if (!employee.create_table()) {
        std::cerr << "Failed to create employee table.\n";
        return 1;
    }

    int choice;
    bool running = true;

    while (running) {
        menu.show_menu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: menu.create_Employee(employee); break;
        case 2: menu.update_Employee(employee); break;
        case 3: menu.delete_Employee(employee); break;
        case 4: menu.list_Employees(employee); break;
        case 5: running = false; break;
        default: std::cout << "Invalid choice. Please Try again.\n"; break;
        }
    }

    return 0;
}
