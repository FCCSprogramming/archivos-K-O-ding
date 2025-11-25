/*
    Autor: Manuel Rojas
*/

#include<iostream>
#include<fstream>
using namespace std;

void escribirFibonacciBinario(){
    cout<<"Funcion escribirFibonacciBinario:\n";

    ofstream out("fibonacci.bin", ios::binary);
    if (!out)
    {
        cout<< "error, no se pudo abrir el archivo\n";
    } else
    {
        int fib[20];
        fib[0] = 0;
        fib[1] = 1;

        for (int i = 0; i < 18; i++)
        {
            fib[i+2] = fib[i] + fib[i+1];
        }
        
        out.write(reinterpret_cast<char*>(fib), sizeof(fib));
        out.close();

        cout<< "Terminos de Fibonacci escritos en el archivo correctamente.\n";
    }
}
void leerFibonacciBinario(){
    cout<<"\nFuncion leerFibonacciBinario:\n";

    fstream in("fibonacci.bin", ios::in | ios::binary);
    
    if (!in)
    {
        cout<< "error, no se pudo abrir el archivo\n";
    } else
    {
        int a;
        int counter = 1;
        
        while (in.read(reinterpret_cast<char*>(&a), sizeof(a)))
        {
            cout<< "Termino "<<counter<<": "<<a<<endl;
            counter++;
        }

        in.close();
    }
}

int main(){
    escribirFibonacciBinario();
    leerFibonacciBinario();
    return 0;
}
