#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include "DatabaseManager.hxx"

class Employee {
private:
    DatabaseManager& database;

public:
    explicit Employee(DatabaseManager& dbManager);

    bool create_table();
    bool add_employee(const std::string& name);
    bool update_employee_name(int id, const std::string& newName);
    bool delete_employee(int id);
    void list_all_employees();
};

#endif EMPLOYEE_HPP