#ifndef TICKET_H
#define TICKET_H

class Ticket
{
    private:
        int id;
        int duration;
        int final_hour;
        bool with_instructor;
        int price;

    public:
        Ticket(int id, int duration, int final_hour, bool with_instructor);
        void set_id(int id);
        int get_id() const;
        void set_duration(int duration);
        int get_duration() const;
        void set_final_hour(int final_hour);
        int get_final_hour() const;
        void set_with_instructor(bool with_instructor);
        bool is_with_instructor() const;
        void set_price(int price);
        int get_price() const;
        int calculate_price() const;
};
#endif