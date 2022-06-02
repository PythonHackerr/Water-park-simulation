#include "simulation.h"

Simulation::Simulation(int start_hour, int finish_hour, vector<Employee> employee_list,
    vector<WaterAttraction> attraction_list, int n_clients)
{
    this -> start_hour = start_hour;
    this -> finish_hour = finish_hour;
    this -> current_hour = start_hour;
    this -> step = 1;
    this -> employee_list = employee_list;
    this -> attraction_list = attraction_list;
    this -> n_clients = n_clients;
    this -> client_list = vector<Client> {};
}

int Simulation::get_start_hour() const
{
    return start_hour;
}

int Simulation::get_finish_hour() const
{
    return finish_hour;
}

int Simulation::get_current_hour() const
{
    return current_hour;
}

int Simulation::get_step() const
{
    return step;
}

vector<Employee> Simulation::get_employee_list() const
{
    return employee_list;
}

int Simulation::get_n_clients() const
{
    return n_clients;
}

vector<WaterAttraction> Simulation::get_attraction_list() const
{
    return attraction_list;
}
