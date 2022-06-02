#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "simulation.h"
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

void split_str(string const &str, const char delim,
               vector<string> &out)
{
    stringstream s(str);
    string s2;
    while (getline(s, s2, delim))
    {
        out.push_back(s2);
    }
}

WaterAttraction GetAttractionWithId(vector<WaterAttraction> attractions, int id)
{
    for (int i = 0; i < attractions.size(); i++)
    {
        if (attractions[i].GetId() == id)
        {
            return attractions[i];
        }
    }
    throw "No such attraction!";
}

/*vector<Client> InitClients(string filePath, vector<WaterAttraction> attractions)
{
    fstream newfile;
    newfile.open(filePath, ios::in);
    vector<Client> clients;
    if (newfile.is_open())
    {
        string line;
        vector<string> seperated_info;
        while (getline(newfile, line))
        {
            split_str(line, ' ', seperated_info);
            int id = stoi(seperated_info[0]);
            int ticket_id = stoi(seperated_info[1]);
            int ticket_duration = stoi(seperated_info[2]);
            int ticket_final_hour = stoi(seperated_info[3]);
            bool ticket_with_instructor = false;
            if (seperated_info[4] == "true")
            {
                ticket_with_instructor = true;
            }
            Ticket ticket(ticket_id, ticket_duration, ticket_final_hour, ticket_with_instructor);
            int attraction_id = 0;
            WaterAttraction attraction = GetAttractionWithId(attractions, attraction_id);
            Client new_client(id, ticket, attraction);
            clients.push_back(new_client);
        }
        newfile.close();
    }
    else
    {
        throw "File does not exists";
    }
    return clients;
}*/

vector<Employee> GetEmployeesInfo(string filePath, vector<WaterAttraction> attractions)
{
    fstream newfile;
    newfile.open(filePath, ios::in);
    vector<Employee> employees;
    if (newfile.is_open())
    {
        string line;
        while (getline(newfile, line))
        {
            vector<string> seperated_info;
            split_str(line, ' ', seperated_info);
            int id = stoi(seperated_info[0]);
            string name = seperated_info[2];
            string surname = seperated_info[3];
            string type = seperated_info[1];
            if (type == "Cashier")
            {
                Cashier new_employee(id, name, surname);
                employees.push_back(new_employee);
            }
            else if (type == "Lifeguard")
            {
                Lifeguard new_employee(id, name, surname);
                employees.push_back(new_employee);
            }
            else if (type == "Instructor")
            {
                Instructor new_employee(id, name, surname);
                employees.push_back(new_employee);
            }
        }
        newfile.close();
    }
    else
    {
        throw "File does not exists";
    }
    return employees;
}

void GetSimulationInfo(string filePath, int &start_hour, int &finish_hour, int &n_clients)
{
    fstream newfile;
    newfile.open(filePath, ios::in);
    vector<Employee> employees;
    if (newfile.is_open())
    {
        string line;
        int line_number = 0;
        while (getline(newfile, line))
        {
            vector<string> seperated_info;
            split_str(line, ' ', seperated_info);
            if (line_number == 0)
            {
                start_hour = stoi(seperated_info[1]);
            }
            else if (line_number == 1)
            {
                finish_hour = stoi(seperated_info[1]);
            }
            else if (line_number == 2)
            {
                n_clients = stoi(seperated_info[1]);
            }
            line_number += 1;
        }
        newfile.close();
    }
}

vector<WaterAttraction> GetAttractionInfo(string filePath)
{
    fstream newfile;
    newfile.open(filePath, ios::in);
    vector<WaterAttraction> waterAttractions;
    if (newfile.is_open())
    {
        string line;
        vector<string> seperated_info;
        string type;
        ability required_ability;
        while (getline(newfile, line))
        {
            split_str(line, ' ', seperated_info);
            int id = stoi(seperated_info[0]);
            string type = seperated_info[1];
            if (type == "LanePool")
            {
                float height = stof(seperated_info[2]);
                string required_ability_txt = seperated_info[3];
                if (required_ability_txt == "cant_swim")
                {
                    required_ability = cant_swim;
                }
                else if (required_ability_txt == "noob_swimmer")
                {
                    required_ability = noob_swimmer;
                }
                else if (required_ability_txt == "amatuer_swimmer")
                {
                    required_ability = amatuer_swimmer;
                }
                else if (required_ability_txt == "pro_swimmer")
                {
                    required_ability = pro_swimmer;
                }
                else if (required_ability_txt == "god_swimmer")
                {
                    required_ability = god_swimmer;
                }
                LanePool lanePool_attracion(id, height, required_ability);
                waterAttractions.push_back(lanePool_attracion);
            }
            else if (type == "Jacuzzi")
            {
                Jacuzzi jacuzzi_attracion(id);
                waterAttractions.push_back(jacuzzi_attracion);
            }
            else if (type == "SwimmingPoolForChildren")
            {
                SwimmingPoolForChildren swimmingPoolForChildren_attraction(id);
                waterAttractions.push_back(swimmingPoolForChildren_attraction);
            }
            else if (type == "Slides")
            {
                Slides slides_attracion(id);
                waterAttractions.push_back(slides_attracion);
            }
        }
        newfile.close();
    }
    return waterAttractions;
}

// int main()
// {
//     int start_hour = 0;
//     int finish_hour = 0;
//     int n_clients = 0;
//     string simulation_info_path = "SimulationInfo.txt";
//     GetEmployeesInfo(simulation_info_path, start_hour, finish_hour, n_clients);
//     /*Cashier cashier1(1, "a", "b");
//     Cashier cashier2(2, "c", "d");
//     Instructor instructor1(3, "e", "f");
//     Instructor instructor2(4, "g", "h");
//     Lifeguard lifeguard1(5, "i", "j");
//     Lifeguard lifeguard2(6, "k", "l");*/
//     Jacuzzi jacuzzi1(1);
//     Jacuzzi jacuzzi2(2);
//     LanePool lanepool1(3, 3);
//     LanePool lanepool2(4, 2.5);
//     Slides slides1(5);
//     Slides slides2(6);
//     SwimmingPoolForChildren pool_for_children1(7);
//     SwimmingPoolForChildren pool_for_children2(8);
//     vector<WaterAttraction> attraction_list{jacuzzi1, jacuzzi2, lanepool1,
//                                             lanepool2, slides1, slides2, pool_for_children1, pool_for_children2};

//     vector<Employee> employee_list = GetEmployeesInfo("Employees.txt", attraction_list);
//     vector<Client> clients_list = InitClients("Clients.txt", attraction_list);

//     Simulation simulation(start_hour, finish_hour, employee_list, attraction_list, n_clients);

//     simulation.run();

//     return 0;
// }

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "Incorrect number of command line arguments - expected 4, got " << argc << endl;
        return 1;
    }

    string simulation_info_path = "";
    string employees_info_path = "";
    string attractions_info_path = "";
    stringstream stream;
    stream << argv[1];
    stream >> simulation_info_path;
    stream.clear();
    stream << argv[2];
    stream >> employees_info_path;
    stream.clear();
    stream << argv[3];
    stream >> attractions_info_path;

    int start_hour = 0;
    int finish_hour = 0;
    int n_clients = 0;
    GetSimulationInfo(simulation_info_path, start_hour, finish_hour, n_clients);
    /*Cashier cashier1(1, "a", "b");
    Cashier cashier2(2, "c", "d");
    Instructor instructor1(3, "e", "f");
    Instructor instructor2(4, "g", "h");
    Lifeguard lifeguard1(5, "i", "j");
    Lifeguard lifeguard2(6, "k", "l");*/
    /*
        Jacuzzi jacuzzi1(1);
        Jacuzzi jacuzzi2(2);
        LanePool lanepool1(3, 3);
        LanePool lanepool2(4, 2.5);
        Slides slides1(5);
        Slides slides2(6);
        SwimmingPoolForChildren pool_for_children1(7);
        SwimmingPoolForChildren pool_for_children2(8);*/
    vector<WaterAttraction> attraction_list = GetAttractionInfo(attractions_info_path);

    vector<Employee> employee_list = GetEmployeesInfo(employees_info_path, attraction_list);
    // vector<Client> clients_list = InitClients("Clients.txt", attraction_list);

    Simulation simulation(start_hour, finish_hour, employee_list, attraction_list, n_clients);

    simulation.run();

    return 0;
}
