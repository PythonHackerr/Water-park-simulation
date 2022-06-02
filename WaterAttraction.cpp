#pragma once
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "client.h"

using namespace std;

class WaterAttraction
{
protected:
    int id;
    string name;

public:
    WaterAttraction()
    {
        this->id = -1;
        this->name = "WaterAttraction";
    }

    WaterAttraction(int id)
    {
        this->id = id;
        this->name = "WaterAttraction";
    }

    string GetName()
    {
        return name;
    };

    int GetId()
    {
        return id;
    }

    friend std::ostream& operator<<(std::ostream& os, const WaterAttraction& water_attraction)
    {
        os << water_attraction.name << " #" << water_attraction.id;
        return os;
    }
};
/*
std::ostream& operator<<(std::ostream& os, const WaterAttraction& water_attraction)
{
    os << "Water attraction #" << water_attraction.id;
    return os;
}*/