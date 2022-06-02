#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "WaterAttraction.cpp"
using namespace std;

enum ability{cant_swim, noob_swimmer, amatuer_swimmer, pro_swimmer, god_swimmer };

class LanePool : public WaterAttraction
{
private:
    enum ability swimming_ability;
    float depth;

public:
    LanePool(int id, string name, vector<Client> clients, float depth, enum ability swimming_ability = amatuer_swimmer) : WaterAttraction(id, name, clients)
    {
        this->id = id;
        this->name = name;
        this->clients = clients;
        this->depth = depth;
        this->swimming_ability = swimming_ability;
    }

    enum ability GetSwimmingAbility()
    {
        return swimming_ability;
    };
    void SetSwimmingAbility(enum ability swimming_ability)
    {
        this->swimming_ability = swimming_ability;
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
