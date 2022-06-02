#include "employee.h"
#include "timesheet.h"

using std::string;

Employee::Employee()
{
    set_id(-1);
    set_class_name("Employee");
    set_name("no name");
    set_surname("no surname");
    set_busy(false);
    calculate_salary();
    create_timesheet();
}

Employee::Employee(int id, string name, string surname)
{
    set_id(id);
    set_class_name("Employee");
    set_name(name);
    set_surname(surname);
    set_busy(false);
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

void Employee::set_class_name(string class_name)
{
    this -> class_name = class_name;
}

string Employee::get_class_name() const
{
    return class_name;
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

void Employee::set_busy(bool busy)
{
    this -> busy = busy;
}

bool Employee::is_busy() const
{
    return busy;
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
    os << employee.get_class_name() << " #" << employee.get_id();
    return os;
}