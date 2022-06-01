#include "instructor.h"

Instructor::Instructor(int id, string name, string surname)
{
    set_id(id);
    set_name(name);
    set_surname(surname);
    calculate_salary();
    create_timesheet();
}

void Instructor::calculate_salary()
{
    int hours = get_hours();
    salary = 500 + 10*hours;
    this -> salary = salary;
}

void Instructor::create_timesheet()
{
    Timesheet timesheet = Timesheet(Pair(9, 14), Pair(9, 14), Pair(9, 14), Pair(9, 12), Pair(9, 12));
    this -> timesheet = timesheet;
}