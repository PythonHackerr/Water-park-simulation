#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
#include "timesheet.h"

using std::string;

class Employee
{
    protected:
        int id; // -1 - invalid id
        string name;
        string surname;
        int salary; //weekly salary
        Timesheet timesheet;

    public:
        Employee();
        Employee(int id, string name, string surname);
        void set_id(int id);
        int get_id() const;
        void set_name(string name);
        string get_name() const;
        void set_surname(string surname);
        string get_surname() const;
        virtual void calculate_salary();
        int get_salary() const;
        virtual void create_timesheet();
        Timesheet get_timesheet() const;
        int get_hours() const;

        friend std::ostream& operator<<(std::ostream& os, const Employee& employee);

};
#endif