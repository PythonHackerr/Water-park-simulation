#include "timesheet.h"

Timesheet::Timesheet():mon(pair<int,int>(0, 0)), tue(pair<int,int>(0, 0)),
    wed(pair<int,int>(0, 0)), thu(pair<int,int>(0, 0)), fri(pair<int,int>(0, 0))
{}

Timesheet::Timesheet(pair <int, int> mon, pair <int, int> tue, pair <int, int> wed,
                pair <int, int> thu, pair <int, int> fri) :
    mon(mon), tue(tue), wed(wed), thu(thu), fri(fri)
{}

int Timesheet::get_hours() const
{
    int total_hours=0;
    total_hours += (mon.second - mon.first);
    total_hours += (tue.second - tue.first);
    total_hours += (wed.second - wed.first);
    total_hours += (thu.second - thu.first);
    total_hours += (fri.second - fri.first);
    return total_hours;
}

std::ostream& operator<<(std::ostream& os, const Timesheet& timesheet)
{
    os << "Monday: " << timesheet.mon.first << " - " << timesheet.mon.second << "\n";
    os << "Tuesday: " << timesheet.tue.first << " - " << timesheet.tue.second << "\n";
    os << "Wednesday: " << timesheet.wed.first << " - " << timesheet.wed.second << "\n";
    os << "Thursday: " << timesheet.thu.first << " - " << timesheet.thu.second << "\n";
    os << "Friday: " << timesheet.fri.first << " - " << timesheet.fri.second << "\n";
    return os;
}