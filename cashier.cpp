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
    Timesheet timesheet = Timesheet(Pair(9, 16), Pair(9, 16), Pair(9, 15), Pair(9, 15), Pair(9, 12));
    this -> timesheet = timesheet;
}


Cashier cashier(1, "imie", "nazwisko");
string name = cashier.get_name();