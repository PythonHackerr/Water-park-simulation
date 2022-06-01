#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "WaterAttraction.cpp"
using namespace std;

class SwimmingPoolForChildren : public WaterAttraction
{
private:
    string name;
    int max_people;
    vector<Client> clients; // currently using this attraction
    vector<Employee> employees;

public:
    SwimmingPoolForChildren(string name, vector<Client> clients, vector<Employee> employees, int max_people) : WaterAttraction(name, clients, employees)
    {
        this->name = name;
        this->clients = clients;
        this->employees = employees;
        this->max_people = max_people;
    }

    int GetMaxPeople()
    {
        return max_people;
    };
    void SetMaxPeople(int max_people)
    {
        this->max_people = max_people;
    };

    void DisplayInfo() override
    {
        WaterAttraction::DisplayInfo();
        // cout << "Current people" << max_people << endl;
    }
};
