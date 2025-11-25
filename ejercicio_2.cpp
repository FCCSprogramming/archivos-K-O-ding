/*
    Autor: Manuel Rojas
*/

#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

struct Vertice
{
    double x;
    double y;
};


int main()
{
    cout<<"Calculando area...\n";

    ifstream in("laguna.txt");
    ofstream out("area.txt");

    if (!in.is_open())
    {
        cout<< "error, no se pudo abrir el archivo 'laguna.txt'.\n";
    } else if (!out.is_open())
    {
        cout << "error, no se pudo crear el archivo 'area.txt'.\n";
    } else
    {
        int nt, nv;
        
        in >> nt >> nv;

        Vertice * vertices = new Vertice[nv];

        for (int i = 0; i < nv; i++)
        {
            in >> vertices[i].x >> vertices[i].y; 
        }

        int v1, v2, v3;
        double x1, y1, x2, y2, x3, y3;
        double area = 0;

        for (int i = 0; i < nt; i++)
        {
            in >> v1 >> v2 >> v3;

            x1 = vertices[v1 - 1].x;
            y1 = vertices[v1 - 1].y;

            x2 = vertices[v2 - 1].x;
            y2 = vertices[v2 - 1].y;

            x3 = vertices[v3 - 1].x;
            y3 = vertices[v3 - 1].y;

            area += abs( x1*(y3-y2) + x2*(y1-y3) + x3*(y2-y1) ) / 2;

        }
        
        out << area <<endl;

        cout << "El area se ha calculado y agregado al archivo 'area.txt'.\n";

        delete[] vertices;
        vertices = nullptr;

        out.close();
        in.close();
    }

    return 0;
}
