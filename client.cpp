#include "client.h"

Client::Client()
{
    set_id(-1);
    set_ticket(Ticket());
    set_place(WaterAttraction());
}

Client::Client(int id, Ticket ticket, WaterAttraction place)
{
    set_id(id);
    set_ticket(ticket);
    set_place(place);
}

void Client::set_id(int id)
{
    this -> id = id;
}

int Client::get_id()const
{
    return id;
}

void Client::set_ticket(Ticket ticket)
{
    this -> ticket = ticket;
}

Ticket Client::get_ticket()const
{
    return ticket;
}

void Client::set_place(WaterAttraction place)
{
    this -> place = place;
}

WaterAttraction Client::get_place() const
{
    return place;
}

std::ostream& operator<<(std::ostream& os, const Client& client)
{
    os << "Client #" << client.get_id();
    return os;
}
