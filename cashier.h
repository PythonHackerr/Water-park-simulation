#ifndef CASHIER_H
#define CASHIER_H

#include "employee.h"

class Cashier : public Employee
{
    public:
        Cashier(int id, string name, string surname);
        void calculate_salary() override;
        void create_timesheet() override;

        friend std::ostream& operator<<(std::ostream& os, const Cashier& cashier);
};
#endif