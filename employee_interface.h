#ifndef EMPLOYEE_INTERFACE_H
#define EMPLOYEE_INTERFACE_H

#include <iostream>
#include "timesheet.h"

class Employee_Interface
{
    public:
        virtual void calculate_salary()=0;
        virtual int get_salary() const=0;
        virtual void create_timesheet()=0;
        virtual Timesheet get_timesheet() const=0;
        virtual int get_hours() const=0;
};
#endif