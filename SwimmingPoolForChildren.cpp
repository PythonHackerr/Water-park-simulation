#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "WaterAttraction.cpp"
using namespace std;

class SwimmingPoolForChildren : public WaterAttraction
{
public:
    SwimmingPoolForChildren(int id) : WaterAttraction(id)
    {
        this->id =id;
        this->name = "SwimmingPoolForChildren";
    }

    friend std::ostream& operator<<(std::ostream& os, const SwimmingPoolForChildren& pool)
    {
        os << "Pool for children #" << pool.id;
        return os;
    }
};
