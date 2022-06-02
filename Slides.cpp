#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "WaterAttraction.cpp"

using namespace std;

class Slides : public WaterAttraction
{
public:
    Slides(int id) : WaterAttraction(id)
    {
        this->id = id;
        this->name = "Slides";
    }

    friend std::ostream& operator<<(std::ostream& os, const Slides& slides)
    {
        os << "Slides #" << slides.id;
        return os;
    }
};
