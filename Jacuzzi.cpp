#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "WaterAttraction.cpp"
using namespace std;

class Jacuzzi : public WaterAttraction
{
private:
    string name;
    int max_people;
    int min_age;
    vector<Client> clients; // currently using this attraction
    vector<Employee> employees;

public:
    Jacuzzi(string name, vector<Client> clients, vector<Employee> employees, int max_people, int min_age = 0) : WaterAttraction(name, clients, employees)
    {
        this->name = name;
        this->clients = clients;
        this->employees = employees;
        this->max_people = max_people;
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
    }
};
