#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "WaterAttraction.cpp"
using namespace std;

class SwimmingPoolForChildren : public WaterAttraction
{
public:
    SwimmingPoolForChildren(int id, string name, vector<Client> clients) : WaterAttraction(id, name, clients)
    {
        this->id =id;
        this->name = name;
        this->clients = clients;
    }

    void DisplayInfo() override
    {
        WaterAttraction::DisplayInfo();
        // cout << "Current people" << max_people << endl;
    }
};
