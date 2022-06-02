#include "catch.hpp"
#include "../employee.h"
#include "../cashier.h"
#include "../instructor.h"
#include "../lifeguard.h"
#include "../client.h"
#include "../WaterAttraction.cpp"
#include <sstream>

TEST_CASE("employees tests")
{
    Employee employee(1, "e", "E");
    Cashier cashier(2, "c", "C");
    Instructor instructor(3, "i", "I");
    Lifeguard lifeguard(4, "l", "L");

    SECTION("employee - id, class_name, name, surname, busy")
    {
        Employee default_employee;
        CHECK(default_employee.get_id() == -1);
        CHECK(default_employee.get_class_name() == "Employee");
        CHECK(default_employee.get_name() == "no name");
        CHECK(default_employee.get_surname() == "no surname");
        CHECK(default_employee.is_busy() == false);

        CHECK(employee.get_id() == 1);
        CHECK(employee.get_class_name() == "Employee");
        CHECK(employee.get_name() == "e");
        CHECK(employee.get_surname() == "E");
        CHECK(employee.is_busy() == false);
        employee.set_id(10);
        CHECK(employee.get_id() == 10);
        employee.set_name("nowe_imie");
        CHECK(employee.get_name() == "nowe_imie");
        employee.set_surname("nowe_nazwisko");
        CHECK(employee.get_surname() == "nowe_nazwisko");
        employee.set_busy(true);
        CHECK(employee.is_busy() == true);
    }


    SECTION("cashier - id, class_name, name, surname, busy")
    {
        CHECK(cashier.get_id() == 2);
        CHECK(cashier.get_class_name() == "Cashier");
        CHECK(cashier.get_name() == "c");
        CHECK(cashier.get_surname() == "C");
        CHECK(cashier.is_busy() == false);
        cashier.set_id(11);
        CHECK(cashier.get_id() == 11);
        cashier.set_name("nowe_imie");
        CHECK(cashier.get_name() == "nowe_imie");
        cashier.set_surname("nowe_nazwisko");
        CHECK(cashier.get_surname() == "nowe_nazwisko");
        cashier.set_busy(true);
        CHECK(cashier.is_busy() == true);
    }


    SECTION("instructor - id, class_name, name, surname, busy")
    {
        CHECK(instructor.get_id() == 3);
        CHECK(instructor.get_class_name() == "Instructor");
        CHECK(instructor.get_name() == "i");
        CHECK(instructor.get_surname() == "I");
        CHECK(instructor.is_busy() == false);
        instructor.set_id(12);
        CHECK(instructor.get_id() == 12);
        instructor.set_name("nowe_imie");
        CHECK(instructor.get_name() == "nowe_imie");
        instructor.set_surname("nowe_nazwisko");
        CHECK(instructor.get_surname() == "nowe_nazwisko");
        instructor.set_busy(true);
        CHECK(instructor.is_busy() == true);
    }


    SECTION("lifeguard - id, class_name, name, surname, busy")
    {
        CHECK(lifeguard.get_id() == 4);
        CHECK(lifeguard.get_class_name() == "Lifeguard");
        CHECK(lifeguard.get_name() == "l");
        CHECK(lifeguard.get_surname() == "L");
        CHECK(lifeguard.is_busy() == false);
        lifeguard.set_id(13);
        CHECK(lifeguard.get_id() == 13);
        lifeguard.set_name("nowe_imie");
        CHECK(lifeguard.get_name() == "nowe_imie");
        lifeguard.set_surname("nowe_nazwisko");
        CHECK(lifeguard.get_surname() == "nowe_nazwisko");
        lifeguard.set_busy(true);
        CHECK(lifeguard.is_busy() == true);
    }


    SECTION("tests of operator<<")
    {
        std::stringstream ss_employee;
        ss_employee << employee;
        CHECK(ss_employee.str() == "Employee #1");

        std::stringstream ss_cashier;
        ss_cashier << cashier;
        CHECK(ss_cashier.str() == "Cashier #2");

        std::stringstream ss_instructor;
        ss_instructor << instructor;
        CHECK(ss_instructor.str() == "Instructor #3");

        std::stringstream ss_lifeguard;
        ss_lifeguard << lifeguard;
        CHECK(ss_lifeguard.str() == "Lifeguard #4");
    }
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
    Client client(1, Ticket(1, 1, 12, false), WaterAttraction(1));

    SECTION("client - getters, setters")
    {
        CHECK(default_client.get_id() == -1);

        CHECK(client.get_id() == 1);
        CHECK(client.get_ticket().get_id() == 1);
        client.set_id(2);
        CHECK(client.get_id() == 2);
        client.set_ticket(Ticket(2, 2, 12, false));
        CHECK(client.get_ticket().get_id() == 2);
    }

    SECTION("client - operator<<")
    {
        std::stringstream ss;
        ss<<client;
        CHECK(ss.str() == "Client #1");
    }
}
