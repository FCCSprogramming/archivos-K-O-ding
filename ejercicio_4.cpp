/*
    Autor: Manuel Rojas
*/

#include<iostream>
using namespace std;

int main(){

    int pol1[5] = {0, 2, 2, 2, 1};
    int pol2[4] = {0, 4, 3, 2};
    int result[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int nuevo_coef, nuevo_exp;

    cout << "\nPrimer polinomio:\n";
    for (int i = 5; i >= 0; i--)
    {
        if (pol1[i] != 0)
        {
            cout<<pol1[i] <<"x^"<< i;
            if (i != 0 && pol1[i-1] != 0)
            {
                cout << " + ";
            }
        }
    }

    cout << "\nSegundo polinomio:\n";
    for (int i = 4; i >= 0; i--)
    {
        if (pol2[i] != 0)
        {
            cout<<pol2[i] <<"x^"<< i;
            if (i != 0 && pol2[i-1] != 0)
            {
                cout << " + ";
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            nuevo_coef = pol1[i] * pol2[j];
            nuevo_exp = i + j;

            result[nuevo_exp] += nuevo_coef; 
        }
    }
    
    cout << "\nPolinomio resultante:\n";
    for (int i = 7; i >= 0; i--)
    {
        if (result[i] != 0)
        {
            cout<<result[i] <<"x^"<< i;
            if (i != 0 && result[i-1] != 0)
            {
                cout << " + ";
            }
        }
    }
    

    return 0;
}