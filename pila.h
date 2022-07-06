#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include<iostream>
#include <cctype>
#include<stdlib.h>
#include<windows.h>
using namespace std;

class pila
{
private:
    double datos[2000];
    int tope,last;
public:

    pila();
    void push(double);
    void pop();
    int  vacia();
    int llena();
    void mostrar_tope();
    void mostrar_pila();
    void gotoxy(int,int);
};

pila::pila()
{
    tope=-1;
}
void pila::push(double n)
{
    if(llena()==0)
        {
        tope ++;
        datos[tope]=n;
        }
}
void pila::pop()
{
    if(vacia()==0)
        {
        datos[tope ]= 0;
        tope --;
        }

}
void pila::mostrar_tope()
{
    if(vacia()==0)
        {
        printf("\n\n\t\t%c%c%c%c%c%c%c \n",201,205,205,205,205,187);
        printf("\t\t%c ",186,205);
        cout<<datos[tope];
        printf(" %c\n ",186);
        printf("\t\t%c%c%c%c%c%c\n",200,205,205,205,205,188);
        }
}

void pila::mostrar_pila()
{
    int i;
    system("cls");
    if(vacia()==0)
        {
        printf("\n\n\t\t%c%c%c%c%c  \n",201,205,205,205,187);
        for(i=tope; i>=0; i--)
            {
            system("cls");
            printf("\t\t%c ",186,205);
                cout<<datos[i];
                printf(" %c\n",186);
                printf("\t\t%c%c%c%c%c\n",200,205,205,205,188);
                }
            }
        }

int  pila::vacia()
{
    if(tope==-1)
        {
        system("cls");
        cout<<"LA PILA ESTA VACIA"<<endl;
        system("pause");

        return 1;
        }
    else
        {
        return 0;
        }
}
int  pila::llena()
{
    if(tope==50)
        {
        system("cls");
        cout<<"LA PILA ESTA LLENA "<<endl;
        system("pause");
        return 1;

        }
    else
        {
        return 0;
        }
}

void pila:: gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

#endif // PILA_H_INCLUDED
