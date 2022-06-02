#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>
#include <vector>
#include "employee.h"
#include "cashier.h"
#include "instructor.h"
#include "lifeguard.h"
#include "client.h"
#include "timesheet.h"
#include "WaterAttraction.cpp"
#include "Jacuzzi.cpp"
#include "LanePool.cpp"
#include "Slides.cpp"
#include "SwimmingPoolForChildren.cpp"

using std::string;
using std::vector;

class Simulation
{
    private:
        int start_hour;
        int finish_hour;
        int current_hour;
        int step; // how much time passes in one cycle
        vector<Employee> employee_list;
        vector<WaterAttraction> attraction_list;
        int n_clients;
        vector<Client> client_list;

    public:
        Simulation(int start_hour, int finish_hour, vector<Employee> employee_list,
            vector<WaterAttraction> attraction_list, int n_clients);
        int get_start_hour() const;
        int get_finish_hour() const;
        int get_current_hour() const;
        int get_step() const;
        vector<Employee> get_employee_list() const;
        int get_n_clients() const;
        vector<WaterAttraction> get_attraction_list() const;
};
#endif