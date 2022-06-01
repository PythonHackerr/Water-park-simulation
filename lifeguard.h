#ifndef LIFEGUARD_H
#define LIFEGUARD_H

#include "employee.h"

class Lifeguard : public Employee
{
    public:
        Lifeguard(int id, string name, string surname);
        void calculate_salary() override;
        void create_timesheet() override;

};
#endif