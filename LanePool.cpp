#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "WaterAttraction.cpp"
using namespace std;

class LanePool : public WaterAttraction
{
private:
    string name;
    vector<Client> clients; // currently using this attraction
    vector<Employee> employees;
    int max_people;
    enum ability swimming_ability;
    int min_age;
    float depth;

public:
    LanePool(string name, vector<Client> clients, vector<Employee> employees, int max_people, float depth, enum ability swimming_ability = amatuer_swimmer, int min_age = 0) : WaterAttraction(name, clients, employees)
    {
        this->name = name;
        this->clients = clients;
        this->employees = employees;
        this->max_people = max_people;
        this->depth = depth;
        this->swimming_ability = swimming_ability;
        this->min_age = min_age;
    }

    enum ability GetSwimmingAbility()
    {
        return swimming_ability;
    };
    void SetSwimmingAbility(enum ability swimming_ability)
    {
        this->swimming_ability = swimming_ability;
    };
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
    int GetDepth()
    {
        return depth;
    };
    void SetDepth(int depth)
    {
        this->depth = depth;
    };

    void DisplayInfo() override
    {
        WaterAttraction::DisplayInfo();
    }
};
