#include "catch.hpp"
#include "../employee.h"
#include "../cashier.h"
#include "../instructor.h"
#include "../lifeguard.h"
#include "../client.h"
#include <sstream>

TEST_CASE("employees tests")
{
    Employee employee(1, "e", "E");
    Cashier cashier(2, "c", "C");
    Instructor instructor(3, "i", "I");
    Lifeguard lifeguard(4, "l", "L");

    SECTION("employee - id, name, surname")
    {
        Employee employee1;
        CHECK(employee1.get_id() == -1);
        CHECK(employee1.get_name() == "no name");
        CHECK(employee1.get_surname() == "no surname");

        CHECK(employee.get_id() == 1);
        CHECK(employee.get_name() == "e");
        CHECK(employee.get_surname() == "E");
        employee.set_id(10);
        CHECK(employee.get_id() == 10);
        employee.set_name("nowe_imie");
        CHECK(employee.get_name() == "nowe_imie");
        employee.set_surname("nowe_nazwisko");
        CHECK(employee.get_surname() == "nowe_nazwisko");
    }


    SECTION("cashier - id, name, surname")
    {
        CHECK(cashier.get_id() == 2);
        CHECK(cashier.get_name() == "c");
        CHECK(cashier.get_surname() == "C");
        cashier.set_id(11);
        CHECK(cashier.get_id() == 11);
        cashier.set_name("nowe_imie");
        CHECK(cashier.get_name() == "nowe_imie");
        cashier.set_surname("nowe_nazwisko");
        CHECK(cashier.get_surname() == "nowe_nazwisko");
    }


    SECTION("instructor - id, name, surname")
    {
        CHECK(instructor.get_id() == 3);
        CHECK(instructor.get_name() == "i");
        CHECK(instructor.get_surname() == "I");
        instructor.set_id(12);
        CHECK(instructor.get_id() == 12);
        instructor.set_name("nowe_imie");
        CHECK(instructor.get_name() == "nowe_imie");
        instructor.set_surname("nowe_nazwisko");
        CHECK(instructor.get_surname() == "nowe_nazwisko");
    }


    SECTION("lifeguard - id, name, surname")
    {
        CHECK(lifeguard.get_id() == 4);
        CHECK(lifeguard.get_name() == "l");
        CHECK(lifeguard.get_surname() == "L");
        lifeguard.set_id(13);
        CHECK(lifeguard.get_id() == 13);
        lifeguard.set_name("nowe_imie");
        CHECK(lifeguard.get_name() == "nowe_imie");
        lifeguard.set_surname("nowe_nazwisko");
        CHECK(lifeguard.get_surname() == "nowe_nazwisko");
    }

    /*
    SECTION("tests of operator<<")
    {
        std::stringstream stream_zero;
        stream_zero << zero;
        CHECK(stream_zero.str() == "(0 + 0i)");

        std::stringstream stream_one_real;
        stream_one_real << one_real;
        CHECK(stream_one_real.str() == "(1 + 0i)");

        std::stringstream stream_one_imag;
        stream_one_imag << one_imag;
        CHECK(stream_one_imag.str() == "(0 + 1i)");

        std::stringstream stream_one_real_one_imag;
        stream_one_real_one_imag << one_real_one_imag;
        CHECK(stream_one_real_one_imag.str() == "(1 + 1i)");

        std::stringstream stream_some_number;
        stream_some_number << some_number;
        CHECK(stream_some_number.str() == "(2.4 + 3.9i)");
    }*/
}

TEST_CASE("timesheet tests")
{
    pair<int,int> mon = pair<int,int>(9, 16);
    pair<int,int> tue = pair<int,int>(9, 15);
    pair<int,int> wed = pair<int,int>(9, 14);
    pair<int,int> thu = pair<int,int>(9, 13);
    pair<int,int> fri = pair<int,int>(9, 12);
    Timesheet timesheet(mon ,tue, wed, thu, fri);

    SECTION("timesheet - constructors")
    {
        CHECK(timesheet.mon == pair<int,int> (9,16));
        CHECK(timesheet.tue == pair<int,int> (9,15));
        CHECK(timesheet.wed == pair<int,int> (9,14));
        CHECK(timesheet.thu == pair<int,int> (9,13));
        CHECK(timesheet.fri == pair<int,int> (9,12));
    }

    SECTION("timesheet - get_hours")
    {
        CHECK(timesheet.get_hours() == 25);
    }

    SECTION("timesheet - operator<<")
    {
        std::stringstream ss;
        ss<<timesheet;
        CHECK(ss.str() == "Monday: 9 - 16\nTuesday: 9 - 15\nWednesday: 9 - 14\nThursday: 9 - 13\nFriday: 9 - 12\n");
    }
}

TEST_CASE("client tests")
{
    Client default_client;
    Client client(1, 1);

    SECTION("client - getters, setters")
    {
        CHECK(default_client.get_id() == -1);
        CHECK(default_client.get_ticket_id() == -1);

        CHECK(client.get_id() == 1);
        CHECK(client.get_ticket_id() == 1);
        client.set_id(2);
        CHECK(client.get_id() == 2);
        client.set_ticket_id(3);
        CHECK(client.get_ticket_id() == 3);
    }

    SECTION("client - operator<<")
    {
        std::stringstream ss;
        ss<<client;
        CHECK(ss.str() == "Client #1");
    }
}
