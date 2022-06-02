#include "instructor.h"

Instructor::Instructor(int id, string name, string surname)
{
    set_id(id);
    set_class_name("Instructor");
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
    Timesheet timesheet = Timesheet(pair<int,int>(9, 14), pair<int,int>(9, 14),
        pair<int,int>(9, 14), pair<int,int>(9, 12), pair<int,int>(9, 12));
    this -> timesheet = timesheet;
}

std::ostream& operator<<(std::ostream& os, const Instructor& instructor)
{
    os << "Instructor #" << instructor.get_id();
    return os;
}
