#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "employee.h"

class Instructor : public Employee
{
    public:
        Instructor(int id, string name, string surname);
        void calculate_salary() override;
        void create_timesheet() override;

};
#endif