//
//  main.cpp
//  pomoc
//
//  Created by Mikołaj Semeniuk on 21/03/2020.
//  Copyright © 2020 Mikołaj Semeniuk. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct client
{
    int client_number;
    int debt;
};

int how_many_clients_in_debt (vector<struct client> vect)
{
    int counter = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i].debt > 0)
            counter++;
    }
    return counter;
}

int how_high_is_debt (vector<struct client> vect)
{
    int debt = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        debt += vect[i].debt;
    }
    return debt;
}

void open_and_read_file (vector<struct client> &vect)
{
    std::ifstream fin;
    fin.open("/Users/mikolajsemeniuk/Projects/C++/pomoc/pomoc/klienci.txt");
    int client_number, debt;
    while (fin >> client_number >> debt)
    {
        vect.push_back({ client_number, debt });
    }
}

void write_file (vector<struct client> vect)
{
    ofstream MyFile("/Users/mikolajsemeniuk/Projects/C++/pomoc/pomoc/wynik.txt");
    static_cast<void>(MyFile << "How many clients in debt: " << how_many_clients_in_debt(vect) << "\nTotal sum of debt: " << how_high_is_debt(vect));
}

int main(int argc, const char * argv[]) {

    std::vector<struct client> clients;
    open_and_read_file(clients);
    write_file(clients);
    return 0;
}
