#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "WaterAttraction.cpp"

using namespace std;

class Slides : public WaterAttraction
{
public:
    Slides(int id, vector<Client> clients) : WaterAttraction(id, clients)
    {
        this->id = id;
        this->name = "Slides";
        this->clients = clients;
    }

    void DisplayInfo() override
    {
        WaterAttraction::DisplayInfo();
        // cout << "Current people" << max_people << endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Slides& slides)
    {
        os << "Slides #" << slides.id;
        return os;
    }
};
