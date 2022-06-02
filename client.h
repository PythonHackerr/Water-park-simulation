#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include "ticket.h"
#include "WaterAttraction.cpp"

class Client
{
    private:
        int id; // -1 - invalid id
        Ticket ticket;
        WaterAttraction place;

    public:
    Client();
    Client(int id, Ticket ticket, WaterAttraction place);
    void set_id(int id);
    int get_id() const;
    void set_ticket(Ticket ticket);
    Ticket get_ticket() const;
    void set_place(WaterAttraction place);
    WaterAttraction get_place() const;

    friend std::ostream& operator<<(std::ostream& os, const Client& client);

};
#endif