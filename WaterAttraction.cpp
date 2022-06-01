#pragma once
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "employee.h"
#include "client.h"

using namespace std;

class WaterAttraction
{
private:
    string name;
    vector<Client> clients; // currently using this attraction
    vector<Employee> employees;

public:
    WaterAttraction(string name, vector<Client> clients, vector<Employee> employees)
    {
        this->name = name;
        this->clients = clients;
        this->employees = employees;
    }

    string GetName()
    {
        return name;
    };

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

    bool CheckIfPersonExists(int person_id)
    {
        for (int i = 0; i < clients.size(); i++)
        {
            if (clients[i].get_id() == person_id)
            {
                return true;
            }
        }
        return false;
    };
    void RemovePerson(int person_id)
    {
        if (CheckIfPersonExists(person_id) == false)
        {
            throw "No such person!";
            return;
        }
        vector<Client> new_clientss;
        for (int i = 0; i < clients.size(); i++)
        {
            if (person_id != clients[i].get_id())
            {
                new_clientss.push_back(clients[i]);
            }
        }
        SetClients(new_clientss);
    };
    void AddClient(Client client)
    {
        if (CheckIfPersonExists(client.get_id()) == true)
        {
            throw "Person already exists!";
            return;
        }
        clients.push_back(client);
    };
    void AddEmployee(Employee employee)
    {
        if (CheckIfPersonExists(employee.get_id()) == true)
        {
            throw "Person already exists!";
            return;
        }
        employees.push_back(employee);
    };

    virtual void DisplayInfo()
    {
        cout << "Attraction: " << name << endl;
        cout << "Current clients: " << endl;
        // cout << ";  Max people: " << max_people;
        // cout << ";  Swimming ability required: " << swimming_ability;
        // cout << ";  Minimum age: " << min_age << endl;
        // cout << "People currently using this attraction: " << endl;
        for (int i = 0; i < clients.size(); i++)
        {
            cout << clients[i] << "; ";
        }
    }
};