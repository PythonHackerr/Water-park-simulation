#include "employee.h"
#include "timesheet.h"

using std::string;

Employee::Employee()
{
    set_id(-1);
    set_name("no name");
    set_surname("no surname");
    calculate_salary();
    create_timesheet();
}

Employee::Employee(int id, string name, string surname)
{
    set_id(id);
    set_name(name);
    set_surname(surname);
    calculate_salary();
    create_timesheet();
}

void Employee::set_id(int id)
{
    this -> id = id;
}

int Employee::get_id()const
{
    return id;
}

void Employee::set_name(string name)
{
    this -> name = name;
}

string Employee::get_name() const
{
    return name;
}

void Employee::set_surname(string surname)
{
    this -> surname = surname;
}

string Employee::get_surname() const
{
    return surname;
}

void Employee::calculate_salary()
{
    this -> salary = 0;
}

int Employee::get_salary() const
{
    return salary;
}

void Employee::create_timesheet()
{
    Timesheet timesheet = Timesheet(pair<int,int>(0, 0), pair<int,int>(0, 0),
        pair<int,int>(0, 0), pair<int,int>(0, 0), pair<int,int>(0, 0));
    this -> timesheet = timesheet;
}

Timesheet Employee::get_timesheet() const
{
    return timesheet;
}

int Employee::get_hours() const
{
    return timesheet.get_hours();
}

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
    os << "Employee #" << employee.get_id();
    return os;
}