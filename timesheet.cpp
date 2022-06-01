#include "timesheet.h"

Pair::Pair(int first, int second) : first(first), second(second)
{}

int Pair::get_first() const
{
    return first;
}

int Pair::get_second() const
{
    return second;
}

Timesheet::Timesheet():mon(Pair(0, 0)), tue(Pair(0, 0)), wed(Pair(0, 0)), thu(Pair(0, 0)), fri(Pair(0, 0))
{}

Timesheet::Timesheet(Pair mon, Pair tue, Pair wed, Pair thu, Pair fri) :
    mon(mon), tue(tue), wed(wed), thu(thu), fri(fri)
{}

int Timesheet::get_hours() const
{
    int total_hours=0;
    total_hours += (mon.get_second() - mon.get_first());
    total_hours += (tue.get_second() - tue.get_first());
    total_hours += (wed.get_second() - wed.get_first());
    total_hours += (thu.get_second() - thu.get_first());
    total_hours += (fri.get_second() - fri.get_first());
    return total_hours;
}

std::ostream& operator<<(std::ostream& os, const Timesheet& timesheet)
{
    os << "Monday: " << timesheet.mon.get_first() << " - " << timesheet.mon.get_second() << "\n";
    os << "Tuesday: " << timesheet.tue.get_first() << " - " << timesheet.tue.get_second() << "\n";
    os << "Wednesday: " << timesheet.wed.get_first() << " - " << timesheet.wed.get_second() << "\n";
    os << "Thursday: " << timesheet.thu.get_first() << " - " << timesheet.thu.get_second() << "\n";
    os << "Friday: " << timesheet.fri.get_first() << " - " << timesheet.fri.get_second() << "\n";
    return os;
}