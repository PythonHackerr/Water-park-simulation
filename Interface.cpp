#include <iostream>
#include <fstream>
#include "Database.cpp"
#include "Jacuzzi.cpp"
#include "LanePool.cpp"
#include "Slides.cpp"
#include "SwimmingPoolForChildren.cpp"
#include <sstream>
#include <string>
using namespace std;

void split_str(string const &str, const char delim,
               vector<string> &out)
{
    // create a stream from the string
    stringstream s(str);

    string s2;
    while (getline(s, s2, delim))
    {
        out.push_back(s2); // store the string in s2
    }
}

vector<Client> InitClients(string filePath)
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
            string name = seperated_info[1] + " " + seperated_info[2];
            int age = stoi(seperated_info[3]);
            int ticket_id = stoi(seperated_info[4]);
            string special_ability = seperated_info[5];

            Client new_client(id, ticket_id);
            clients.push_back(new_client);
            // if (special_ability == "cant_swim")
            // {
            //     new_client.set_ability(cant_swim);
            // } ...
        }
        newfile.close();
    }
    return clients;
}

vector<Employee> InitEmployees(string filePath)
{
    fstream newfile;
    newfile.open(filePath, ios::in);
    vector<Employee> employees;
    if (newfile.is_open())
    {
        string line;
        vector<string> seperated_info;
        while (getline(newfile, line))
        {
            split_str(line, ' ', seperated_info);
            int id = stoi(seperated_info[0]);
            string name = seperated_info[1] + " " + seperated_info[2];
            int age = stoi(seperated_info[3]);
            int ticket_id = stoi(seperated_info[4]);
            string special_ability = seperated_info[5];

            Employee new_employee(id, name, name);
            employees.push_back(new_employee);
        }
        newfile.close();
    }
    return employees;
}

void InitAttractionsData(Database &database)
{
    vector<Client> clients = database.GetClientsAtAttraction("Super Slides");
    vector<Employee> employees = database.GetEmployeesAtAttraction("Super Slides");
    Slides slides_attraction("Super Slides", clients, employees, 10);
    database.AddAttraction(slides_attraction);

    vector<Client> clients = database.GetClientsAtAttraction("Super Lane Pool");
    vector<Employee> employees = database.GetEmployeesAtAttraction("Super Lane Pool");
    LanePool lanePool_attraction("Super Lane Pool", clients, employees, 15, 165, pro_swimmer, 16);
    database.AddAttraction(lanePool_attraction);

    vector<Client> clients = database.GetClientsAtAttraction("Super Swimming Pool");
    vector<Employee> employees = database.GetEmployeesAtAttraction("Super Swimming Pool");
    SwimmingPoolForChildren swimmingPool_attraction("Super Swimming Pool", clients, employees, 20);
    database.AddAttraction(swimmingPool_attraction);

    vector<Client> clients = database.GetClientsAtAttraction("Ultra Swimming Pool");
    vector<Employee> employees = database.GetEmployeesAtAttraction("Ultra Swimming Pool");
    SwimmingPoolForChildren swimmingPool_attraction2("Ultra Swimming Pool", clients, employees, 200);
    database.AddAttraction(swimmingPool_attraction2);

    vector<Client> clients = database.GetClientsAtAttraction("Super Jacuzzi");
    vector<Employee> employees = database.GetEmployeesAtAttraction("Super Jacuzzi");
    Jacuzzi jacuzzi_attraction("Super Jacuzzi", clients, employees, 6, 18);
    database.AddAttraction(jacuzzi_attraction);
}

void interface()
{
    Database database({});
    bool run = true;
    string employees_path;
    string clients_path;
    vector<Employee> employees;
    vector<Client> clients;
    while (run)
    {
        cout << "\n\n";
        cout << "Input file path for list of employees: ";
        cin >> employees_path;
        cout << "Input file path for list of clients: ";
        cin >> clients_path;

        employees = InitEmployees(employees_path);
        clients = InitClients(clients_path);

        database.SetClients(clients);
        database.SetEmployees(employees);
        run = false;
    }
    InitAttractionsData(database);
}

int main()
{
    interface();
    return 0;
}
