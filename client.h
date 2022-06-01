#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>

class Client
{
    private:
        int id; // -1 - invalid id
        int ticket_id; // -1 - invalid id
        //

    public:
    Client();
    Client(int id, int ticket_id);
    void set_id(int id);
    int get_id() const;
    void set_ticket_id(int ticket_id);
    int get_ticket_id() const;

    friend std::ostream& operator<<(std::ostream& os, const Client& client);

};
#endif