#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "WaterAttraction.cpp"
using namespace std;

class Jacuzzi : public WaterAttraction
{
public:
    Jacuzzi(int id, vector<Client> clients) : WaterAttraction(id, clients)
    {
        this->id = id;
        this->name = "jacuzzi";
        this->clients = clients;
    }
    void DisplayInfo() override
    {
        WaterAttraction::DisplayInfo();
    }

    friend std::ostream& operator<<(std::ostream& os, const Jacuzzi& jacuzzi)
    {
        os << "Jacuzzi #" << jacuzzi.id;
        return os;
    }
};
