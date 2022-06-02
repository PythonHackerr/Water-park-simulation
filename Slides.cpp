#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "WaterAttraction.cpp"

using namespace std;

class Slides : public WaterAttraction
{
public:
    Slides(int id, string name, vector<Client> clients) : WaterAttraction(id, name, clients)
    {
        this->id = id;
        this->name = name;
        this->clients = clients;
    }

    void DisplayInfo() override
    {
        WaterAttraction::DisplayInfo();
        // cout << "Current people" << max_people << endl;
    }
};
