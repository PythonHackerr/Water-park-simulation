#include "cashier.h"

Cashier::Cashier(int id, string name, string surname)
{
    set_id(id);
    set_name(name);
    set_surname(surname);
    calculate_salary();
    create_timesheet();
}

void Cashier::calculate_salary()
{
    int hours = get_hours();
    salary = 400 + 5*hours;
    this -> salary = salary;
}

void Cashier::create_timesheet()
{
    Timesheet timesheet = Timesheet(pair<int,int>(9, 16), pair<int,int>(9, 16),
        pair<int,int>(9, 15), pair<int,int>(9, 15), pair<int,int>(9, 12));
    this -> timesheet = timesheet;
}
