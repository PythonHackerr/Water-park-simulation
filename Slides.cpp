#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "WaterAttraction.cpp"

using namespace std;

class Slides : public WaterAttraction
{
private:
    string name;
    int min_age;
    vector<Client> clients; // currently using this attraction
    vector<Employee> employees;

public:
    Slides(string name, vector<Client> clients, vector<Employee> employees, int min_age) : WaterAttraction(name, clients, employees)
    {
        this->name = name;
        this->clients = clients;
        this->employees = employees;
        this->min_age = min_age;
    }

    int GetMinAge()
    {
        return min_age;
    };
    void SetMinAge(int min_age)
    {
        this->min_age = min_age;
    };

    void DisplayInfo() override
    {
        WaterAttraction::DisplayInfo();
        // cout << "Current people" << max_people << endl;
    }
};
