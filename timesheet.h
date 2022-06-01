#ifndef TIMESHEET_H
#define TIMESHEET_H

#include <iostream>

using std::pair;

class Timesheet
{
    private:
        pair <int, int> mon;
        pair <int, int> tue;
        pair <int, int> wed;
        pair <int, int> thu;
        pair <int, int> fri;

    public:
        Timesheet();
        Timesheet(pair <int, int> mon, pair <int, int> tue, pair <int, int> wed,
                pair <int, int> thu, pair <int, int> fri);
        int get_hours() const;

        friend std::ostream& operator<<(std::ostream& os, const Timesheet& timesheet);

};
#endif