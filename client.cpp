#include "client.h"

Client::Client()
{
    set_id(-1);
    set_ticket_id(-1);
}

Client::Client(int id, int ticket_id)
{
    set_id(id);
    set_ticket_id(ticket_id);
}

void Client::set_id(int id)
{
    this -> id = id;
}

int Client::get_id()const
{
    return id;
}

void Client::set_ticket_id(int ticket_id)
{
    this -> ticket_id = ticket_id;
}

int Client::get_ticket_id()const
{
    return ticket_id;
}

std::ostream& operator<<(std::ostream& os, const Client& client)
{
    os << "Client #" << client.get_id();
    return os;
}
