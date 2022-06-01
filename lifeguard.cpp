#include "lifeguard.h"

Lifeguard::Lifeguard(int id, string name, string surname)
{
    Employee(id, name, surname);

    set_id(id);
    set_name(name);
    set_surname(surname);
    calculate_salary();
    create_timesheet();
}

void Lifeguard::calculate_salary()
{
    int hours = get_hours();
    salary = 300 + 16*hours;
    this -> salary = salary;
}

void Lifeguard::create_timesheet()
{
    Timesheet timesheet = Timesheet(Pair(10, 16), Pair(10, 16), Pair(10, 15), Pair(10, 15), Pair(9, 12));
    this -> timesheet = timesheet;
}