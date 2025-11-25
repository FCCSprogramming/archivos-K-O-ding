/*
    Autor: Manuel Rojas
*/

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

struct Fecha
{
    int dia, mes;
};

struct Carga
{
    int numPasajeros;
    Fecha* fecha;
};

int main(){

    srand(time(0));

    const int NUM_CARGAS = 360;

    Carga cargas[NUM_CARGAS];

    for (int i = 0; i < NUM_CARGAS; i++)
    {
        (cargas + i)->numPasajeros = rand() % 201 + 500;
        (cargas + i)->fecha = new Fecha;
    }

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            (cargas + i*30 + j)->fecha->dia = j+1;
            (cargas + i*30 + j)->fecha->mes = i+1;
        }
    }
    
    int counter = 0;
    for (int i = 0; i < NUM_CARGAS; i++)
    {
        if ((cargas + i)->numPasajeros >= 665)
        {
            counter ++;
        }   
    }
    cout<<"\nSe encontraron " <<counter << " dias con carga minima de 665 pasajeros:\n";

    for (int i = 0; i < NUM_CARGAS; i++)
    {
        if ((cargas + i)->numPasajeros >= 665)
        {
            cout<<(cargas + i)->fecha->dia << "/ "<< (cargas + i)->fecha->mes << " :\t" << (cargas + i)->numPasajeros << " pasajeros\n";
        }
        
    }
    
    for (int i = 0; i < NUM_CARGAS; i++)
    {
        delete (cargas + i)->fecha;
        (cargas + i)->fecha = nullptr;
    }

    return 0;
}