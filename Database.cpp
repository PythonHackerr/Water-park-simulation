#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include "WaterAttraction.cpp"
using namespace std;

class Database
{
private:
    vector<WaterAttraction> attractions;
    vector<Client> clients;
    vector<Employee> employees;

public:
    Database(vector<WaterAttraction> attractions)
    {
        this->attractions = attractions;
    }

    vector<Client> GetClients()
    {
        return clients;
    };
    void SetClients(vector<Client> clients)
    {
        this->clients = clients;
    };

    vector<Employee> GetEmployees()
    {
        return employees;
    };
    void SetEmployees(vector<Employee> employees)
    {
        this->employees = employees;
    };

    vector<Employee> GetEmployeesAtAttraction(string attraction_name)
    {
        vector<Employee> new_employees;
        for (int i = 0; i < attractions.size(); i++)
        {
            if (attractions[i].GetName() != attraction_name)
            {
                continue;
            }
            for (int i = 0; i < attractions[i].GetEmployees().size(); i++)
            {
                new_employees.push_back(attractions[i].GetEmployees()[i]);
            }
            break;
        }
        return new_employees;
    }

    vector<Client> GetClientsAtAttraction(string attraction_name)
    {
        vector<Client> new_clientss;
        for (int i = 0; i < attractions.size(); i++)
        {
            if (attractions[i].GetName() != attraction_name)
            {
                continue;
            }
            for (int i = 0; i < attractions[i].GetClients().size(); i++)
            {
                new_clientss.push_back(attractions[i].GetClients()[i]);
            }
            break;
        }
        return new_clientss;
    }

    bool CheckIfAttractionExists(WaterAttraction attraction)
    {
        for (int i = 0; i < attractions.size(); i++)
        {
            if (attractions[i].GetName() == attraction.GetName())
            {
                return true;
            }
        }
        return false;
    }

    void AddAttraction(WaterAttraction attraction)
    {
        if (CheckIfAttractionExists(attraction) == true)
        {
            throw "Attraction already exists!!!";
        }
        attractions.push_back(attraction);
    };
    void RemoveAttraction(string name)
    {
        bool removed = false;
        vector<WaterAttraction> new_attractions;
        for (int i = 0; i < attractions.size(); i++)
        {
            if (attractions[i].GetName() != name)
            {
                new_attractions.push_back(attractions[i]);
                removed = true;
                break;
            }
        }
        if (removed == false)
        {
            throw "No such attraction!";
            return;
        }
        attractions = new_attractions;
    };

    void DisplayAttractionData(string attraction_name)
    {
        bool displayed = false;
        vector<WaterAttraction> new_attractions;

        for (int i = 0; i < attractions.size(); i++)
        {
            if (attractions[i].GetName() == attraction_name)
            {
                attractions[i].DisplayInfo();
                displayed = true;
                break;
            }
        }
        if (displayed == false)
        {
            throw "No such attraction!";
        }
    }

    void DisplayAllAttractionsData()
    {
        for (int i = 0; i < attractions.size(); i++)
        {
            attractions[i].DisplayInfo();
        }
    }
    void DisplayAllEmployeesData()
    {
        for (int i = 0; i < employees.size(); i++)
        {
            cout << employees[i] << endl;
        }
    }
};
