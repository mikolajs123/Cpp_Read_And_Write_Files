//
//  main.cpp
//  Temp_C++
//
//  Created by Mikołaj Semeniuk on 04/04/2020.
//  Copyright © 2020 Mikołaj Semeniuk. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct client
{
    int client_number;
    double debt;
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

double how_high_is_debt (vector<struct client> vect)
{
    double debt = 0.0;
    for (int i = 0; i < vect.size(); i++)
    {
        debt += vect[i].debt;
    }
    return debt;
}

void open_and_read_file (vector<struct client> &vect, string path)
{
    std::ifstream fin;
    fin.open(path);
    int client_number;
    double debt;
    while (fin >> client_number >> debt)
    {
        vect.push_back({ client_number, debt });
    }
}

void write_file (vector<struct client> vect, string path)
{
    ofstream MyFile(path);
    static_cast<void>(MyFile << "How many clients in debt: " << how_many_clients_in_debt(vect) << "\nTotal sum of debt: " << how_high_is_debt(vect));
}

int main(int argc, const char * argv[]) {

    std::vector<struct client> clients;
    string input = "/Users/mikolajsemeniuk/Desktop/klienci.txt", output = "/Users/mikolajsemeniuk/Desktop/wynik.txt";
    open_and_read_file(clients, input);
    write_file(clients, output);
    return 0;
}
