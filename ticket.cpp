#include "ticket.h"

Ticket::Ticket()
{
    set_id(-1);
    set_duration(0);
    set_final_hour(0);
    set_with_instructor(false);
    set_price(0);
}

Ticket::Ticket(int id, int duration, int final_hour, bool with_instructor)
{
    set_id(id);
    set_duration(duration);
    set_final_hour(final_hour);
    set_with_instructor(with_instructor);
    set_price(calculate_price());
}

void Ticket::set_id(int id)
{
    this -> id = id;
}

int Ticket::get_id() const
{
    return id;
}

void Ticket::set_duration(int duration)
{
    this -> duration = duration;
}

int Ticket::get_duration() const
{
    return duration;
}

void Ticket::set_final_hour(int final_hour)
{
    this -> final_hour = final_hour;
}

int Ticket::get_final_hour() const
{
    return final_hour;
}

void Ticket::set_with_instructor(bool with_instructor)
{
    this -> with_instructor = with_instructor;
}

bool Ticket::is_with_instructor() const
{
    return with_instructor;
}

void Ticket::set_price(int price)
{
    this -> price = price;
}

int Ticket::get_price() const
{
    return price;
}

int Ticket::calculate_price() const
{
    int base_price_per_hour = 15;
    int price_with_instructor_per_hour = 25;
    if(is_with_instructor())
    {
        return get_duration() * price_with_instructor_per_hour;
    }
    else
    {
        return get_duration() * base_price_per_hour;
    }
}
