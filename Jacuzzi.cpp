#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "WaterAttraction.cpp"
using namespace std;

class Jacuzzi : public WaterAttraction
{
public:
    Jacuzzi(int id, string name, vector<Client> clients) : WaterAttraction(id, name, clients)
    {
        this->id = id;
        this->name = name;
        this->clients = clients;
    }
    void DisplayInfo() override
    {
        WaterAttraction::DisplayInfo();
    }
};
