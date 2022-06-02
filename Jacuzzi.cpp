#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "WaterAttraction.cpp"
using namespace std;

class Jacuzzi : public WaterAttraction
{
public:
    Jacuzzi(int id) : WaterAttraction(id)
    {
        this->id = id;
        this->name = "Jacuzzi";
    }

    friend std::ostream& operator<<(std::ostream& os, const Jacuzzi& jacuzzi)
    {
        os << "Jacuzzi #" << jacuzzi.id;
        return os;
    }
};
