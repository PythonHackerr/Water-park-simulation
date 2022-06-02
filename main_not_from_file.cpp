#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "simulation.h"

int main()
{
    int start_hour = 10;
    int finish_hour = 20;
    Cashier cashier1(1, "a", "b");
    Cashier cashier2(2, "c", "d");
    Instructor instructor1(3, "e", "f");
    Instructor instructor2(4, "g", "h");
    Lifeguard lifeguard1(5, "i", "j");
    Lifeguard lifeguard2(6, "k", "l");
    std::vector<Employee> employee_list{cashier1, cashier2,
        instructor1, instructor2, lifeguard1, lifeguard2};
    Jacuzzi jacuzzi1(1);
    Jacuzzi jacuzzi2(2);
    LanePool lanepool1(3, 3);
    LanePool lanepool2(4, 2.5);
    Slides slides1(5);
    Slides slides2(6);
    SwimmingPoolForChildren pool_for_children1(7);
    SwimmingPoolForChildren pool_for_children2(8);
    std::vector<WaterAttraction> attraction_list{jacuzzi1, jacuzzi2, lanepool1,
        lanepool2, slides1, slides2, pool_for_children1, pool_for_children2};
    int n_clients = 30;

    Simulation simulation(start_hour, finish_hour, employee_list, attraction_list, n_clients);

    simulation.run();

    return 0;
}