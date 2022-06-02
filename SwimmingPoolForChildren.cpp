#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "WaterAttraction.cpp"
using namespace std;

class SwimmingPoolForChildren : public WaterAttraction
{
public:
    SwimmingPoolForChildren(int id, vector<Client> clients) : WaterAttraction(id, clients)
    {
        this->id =id;
        this->name = "SwimmingPoolForChildren";
        this->clients = clients;
    }

    void DisplayInfo() override
    {
        WaterAttraction::DisplayInfo();
        // cout << "Current people" << max_people << endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const SwimmingPoolForChildren& pool)
    {
        os << "Pool for children #" << pool.id;
        return os;
    }
};
