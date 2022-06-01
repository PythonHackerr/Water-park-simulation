#ifndef TIMESHEET_H
#define TIMESHEET_H

#include <iostream>

class Pair //krotka dwoch elementow
{
    private:
        int first;
        int second;

    public:
        Pair(int first, int second);
        int get_first() const;
        int get_second() const;
};

class Timesheet
{
    private:
        Pair mon;
        Pair tue;
        Pair wed;
        Pair thu;
        Pair fri;

    public:
        Timesheet();
        Timesheet(Pair mon, Pair tue, Pair wed, Pair thu, Pair fri);
        int get_hours() const;

        friend std::ostream& operator<<(std::ostream& os, const Timesheet& timesheet);

};
#endif