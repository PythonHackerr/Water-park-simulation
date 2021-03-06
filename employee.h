#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
#include "timesheet.h"
#include "employee_interface.h"

using std::string;

class Employee : public Employee_Interface
{
    protected:
        int id; // -1 - invalid id
        string class_name;
        string name;
        string surname;
        bool busy;
        int salary; //weekly salary
        Timesheet timesheet;

    public:
        Employee();
        Employee(int id, string name, string surname);
        void set_id(int id);
        int get_id() const;
        void set_class_name(string class_name);
        string get_class_name() const;
        void set_name(string name);
        string get_name() const;
        void set_surname(string surname);
        string get_surname() const;
        void set_busy(bool busy);
        bool is_busy() const;
        virtual void calculate_salary();
        int get_salary() const;
        virtual void create_timesheet();
        Timesheet get_timesheet() const;
        int get_hours() const;

        friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
};
#endif