#include "simulation.h"

// obtain a seed from the system clock:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator (seed);  // mt19937 is a standard mersenne_twister_engine

Simulation::Simulation(int start_hour, int finish_hour, vector<Employee> employee_list,
    vector<WaterAttraction> attraction_list, int n_clients)
{
    this -> start_hour = start_hour;
    this -> finish_hour = finish_hour;
    this -> current_hour = start_hour;
    this -> step = 1;
    this -> employee_list = employee_list;
    this -> attraction_list = attraction_list;
    this -> n_clients = n_clients;
    this -> client_list = vector<Client> {};
}

int Simulation::get_start_hour() const
{
    return start_hour;
}

int Simulation::get_finish_hour() const
{
    return finish_hour;
}

int Simulation::get_current_hour() const
{
    return current_hour;
}

int Simulation::get_step() const
{
    return step;
}

vector<Employee> Simulation::get_employee_list() const
{
    return employee_list;
}

int Simulation::get_n_clients() const
{
    return n_clients;
}

vector<WaterAttraction> Simulation::get_attraction_list() const
{
    return attraction_list;
}

string Simulation::get_cycle_message() const
{
    return cycle_message;
}

void Simulation::place_lifeguards()
{
    for(int i=0; i<employee_list.size(); i++)
    {
        if(employee_list[i].get_class_name() == "Lifeguard")
        {
            int index = generator() % attraction_list.size();
            cout << employee_list[i] << " is guarding " << attraction_list[index] << endl;
        }
    }
    cout<<endl;
}

int Simulation::get_clients_per_hour() const
{
    return n_clients / (finish_hour - start_hour);
}

void Simulation::get_new_clients()
{
    int clients_per_hour = get_clients_per_hour();
    int current_n_clients = (current_hour-start_hour)*clients_per_hour;
    for(int i=1; i<=clients_per_hour; i++)
    {
        int n_cashiers = 0;
        int n_instructors = 0;
        for(int j=0; j<employee_list.size(); j++)
        {
            if(employee_list[j].get_class_name() == "Cashier")
            {
                n_cashiers++;
            }
            else if (employee_list[j].get_class_name() == "Instructor")
            {
                n_instructors++;
            }
        }
        int cashier_number = (generator() % n_cashiers)+1;
        int id = current_n_clients+i;
        int duration = (generator() % (get_finish_hour() - get_current_hour())) + 1;
        Ticket ticket = Ticket(id, duration, current_hour+duration, false);
        int instructor_chance = generator() % 5;
        if(instructor_chance == 0)
        {
            ticket.set_with_instructor(true);
        }
        int place_index = (generator() % attraction_list.size());
        client_list.push_back(Client(id, ticket, attraction_list[place_index]));
        for(int j=0; j<employee_list.size(); j++)
        {
            if(employee_list[j].get_class_name() == "Cashier")
            {
                cashier_number--;
            }
            if(cashier_number == 0)
            {
                cout << employee_list[j] << " sold ticket to " << client_list.back()<<endl;
                break;
            }
        }
        if(client_list.back().get_ticket().is_with_instructor())
        {
            int instructor_number = (generator() % n_instructors)+1;
            for(int j=0; j<employee_list.size(); j++)
            {
                if(employee_list[j].get_class_name() == "Instructor")
                {
                    instructor_number--;
                }
                if(instructor_number==0)
                {
                    cout<<client_list.back()<<" went to "<<client_list.back().get_place()<<" with "<<employee_list[j]<<endl;
                    break;
                }
            }
        }
        else
        {
            cout << client_list.back() << " went to " << client_list.back().get_place() << endl;
        }
        cout<<endl;
        time_stop();
    }
}

void Simulation::clients_leave()
{
    for(int i=0; i<client_list.size(); i++)
    {
        if(client_list[i].get_ticket().get_final_hour() == current_hour)
        {
            cout<<client_list[i]<<" leaves\n"<<endl;
            time_stop();
        }
    }
}

void Simulation::time_stop()
{
    std::this_thread::sleep_for (std::chrono::milliseconds(750));
}

void Simulation::cycle()
{
    cout<<"Current hour: "<<current_hour<<endl;
    clients_leave();
    get_new_clients();
    current_hour += step;
    cout<<endl;
}

void Simulation::run()
{
    while (current_hour != finish_hour)
    {
        cycle();
    }
    cout<<"Current hour: "<<current_hour<<endl;
    clients_leave();
    cout<<"Pool has closed"<<endl;

}

std::ostream& operator<<(std::ostream& os, const Simulation& simulation)
{
    os << simulation.get_cycle_message();
    return os;
}
