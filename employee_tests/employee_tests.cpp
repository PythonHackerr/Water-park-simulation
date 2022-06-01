#include "catch.hpp"
#include "../employee.h"
#include "../cashier.h"
#include "../instructor.h"
#include "../lifeguard.h"
#include <sstream>

TEST_CASE("employees tests", "[employee]")
{
    Employee employee(1, "e", "E");
    Cashier cashier(2, "c", "C");
    Instructor instructor(3, "i", "I");
    Lifeguard lifeguard(4, "l", "L");

    SECTION("employee - id, name, surname")
    {
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
    SECTION("comparison tests")
    {
        ComplexNumber another_zero;
        ComplexNumber another_one_real(1.0, 0.0);
        ComplexNumber another_one_imag(0.0, 1.0);
        ComplexNumber another_one_real_one_imag(1.0, 1.0);
        ComplexNumber another_some_number(2.4, 3.9);

        CHECK(zero == zero);
        CHECK(zero == another_zero);
        CHECK(one_real == one_real);
        CHECK(one_real == another_one_real);
        CHECK(some_number == some_number);
        CHECK(another_some_number == some_number);
        CHECK(another_one_imag == one_imag);
        CHECK(one_real_one_imag == another_one_real_one_imag);
        CHECK_FALSE(zero == another_some_number);
        CHECK_FALSE(one_imag == one_real_one_imag);

        CHECK_FALSE(zero != another_zero);
        CHECK_FALSE(another_one_real != one_real);
        CHECK_FALSE(one_imag != another_one_imag);
        CHECK_FALSE(another_one_real_one_imag != one_real_one_imag);
        CHECK_FALSE(some_number != another_some_number);
        CHECK(one_real != one_real_one_imag);
        CHECK(one_real_one_imag != another_some_number);
    }

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
