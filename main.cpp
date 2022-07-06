#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include <cstdlib>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<time.h>

#include "pila.h"
#include "cola.h"

void gotoxy(int x,int y);
void movimiento1();
void movimiento3();
int validacion(char n[1000],char n2[1000]);
int validacionunica(char n[1000]);
int valido;
void OcultarCursor();
void mostrarTickets();
void abajo();
void movimientoAtm();
void Eliminar();
int vec[]={3,1,2,4,2,3,1,4};
int vec1[]={2,1,3,4,3,2,1,4};

int i,j,sel;
double num;
pila p;
cola queue_uno;
cola queueDos;
cola queue_tres;

int cont1;
int cont2;
int cont3;
int cont4;


using namespace std;

int main()
{
    OcultarCursor();
    srand(time(NULL));
    for (int c=0; c<8; c++)
        {
        sel=1+rand()%4;
        switch (vec[c])
            {
            case 1:
                movimiento1();
                break;
            case 2:
                abajo();
                break;
            case 3:
                movimiento3();
                break;
            case 4:
                movimientoAtm();
                break;
            }
        }
        system("cls");
    cout<<"_______________________"<<endl;
    cout<<"|Movimientos:        "<<cont1<<" |"<<endl;
    cout<<"|Cambio de cheque:   "<<cont2<<" |"<<endl;
    cout<<"|Servicio a cliente: "<<cont3<<" |"<<endl;
    cout<<"|Cajero:             "<<cont4<<" |"<<endl;
    cout<<"|_____________________|"<<endl;
    return 0;
}
//desaparecer el ultimo para que se recorran

void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);
}
void movimiento1()
{
    for(int o=0; o<16; o=o+2)
        {
        if(o%3==0)
            {
            gotoxy(1,1);
            cout<<"BANCO MICHI"<<endl;
            cont1++;
            p.push(num=10+rand()%50);
            queue_uno.llenar(num);
            for (int x=0; x<68-o; x++)
                {
                gotoxy(90,10);
                queue_uno.consultar_inicio();
                gotoxy(10,9);
                cout<<" ____________________                                 __________________ MOVIMIENTO "<<endl;
                gotoxy(100,8);
                p.mostrar_tope();
                //////////////7
                gotoxy(10+x,10);
                cout<<"  o "<<endl;
                gotoxy(10+x,11);
                cout<<" /|\\ "<<endl;
                if(x%2==0)
                    {
                    gotoxy(10+x,12);
                    cout<<" | "<<endl;
                    }
                else
                    {
                    gotoxy(10+x,12);
                    cout<<" / \\ "<<endl;
                    }

                ////////////////////
                gotoxy(10,13);
                cout<<" ____________________                                 __________________  "<<endl;
                gotoxy(10,15);
                cout<<"                                                      __________________ CAMBIO DE CHEQUE "<<endl;
                gotoxy(10,20);
                cout<<"                                                      __________________ SERVICIO A CLIENTE "<<endl;
                gotoxy(10,24);
                cout<<"                                                      __________________ "<<endl;
                cout<<"                                      _______ "<<endl;
                for (j=0; j<3; j++)
                    {
                    cout<<"                                     |  ATM  | " <<endl;
                    }
                cout<<"                                      _______ "<<endl;
                Sleep(30);
                }
            }
        if(cont1==4)
            {
            queue_uno.eliminar();
            }
        }
    ///////////////////////
    for(int o=0; o<2; o=o+2)
        {
        if(o%3==0)
            {
            for (int x=30; x<68-o; x++)
                {
                gotoxy(90,10);
                queue_uno.consultar_inicio();
                gotoxy(10,9);
                cout<<" ____________________                                 __________________ MOVIMIENTO "<<endl;
                gotoxy(100,8);
                p.mostrar_tope();
                //////////////7
                gotoxy(10+x,10);
                cout<<"    "<<endl;
                gotoxy(10+x,11);
                cout<<"      "<<endl;
                if(x%2==0)
                    {
                    gotoxy(10+x,12);
                    cout<<"   "<<endl;
                    }
                else
                    {
                    gotoxy(10+x,12);
                    cout<<"      "<<endl;
                    }

                ////////////////////
                gotoxy(10,13);
                cout<<" ____________________                                 __________________  "<<endl;
                gotoxy(10,15);
                cout<<"                                                      __________________ CAMBIO DE CHEQUE "<<endl;
                gotoxy(10,20);
                cout<<"                                                      __________________ SERVICIO A CLIENTE "<<endl;
                gotoxy(10,24);
                cout<<"                                                      __________________ "<<endl;
                cout<<"                                      _______ "<<endl;
                for (j=0; j<3; j++)
                    {
                    cout<<"                                     |  ATM  | " <<endl;
                    }
                cout<<"                                      _______ "<<endl;
                Sleep(30);
                }
            }
        }
}
void movimiento3()
{
    for(int o=0; o<16; o=o+2)
        {
        if(o%3==0)
            {
            gotoxy(1,1);
            cout<<"BANCO MICHI"<<endl;
            cont3++;
            p.push(num=10+rand()%50);
            queue_tres.llenar(num);
            gotoxy(90,22);
            queue_tres.consultar_inicio();
            for (int x=20; x<30; x++)
                {
                gotoxy(10,9);
                cout<<" ____________________                                 __________________ MOVIMIENTO"<<endl;
                gotoxy(100,8);
                p.mostrar_tope();
                gotoxy(10+x,10);
                cout<<"  o "<<endl;
                gotoxy(10+x,11);
                cout<<" /|\\ "<<endl;
                if(x%2==0)
                    {
                    gotoxy(10+x,12);
                    cout<<" | "<<endl;
                    }
                else
                    {
                    gotoxy(10+x,12);
                    cout<<" / \\ "<<endl;
                    }
                gotoxy(10,13);
                cout<<" ____________________                                 __________________ "<<endl;
                //segunda fila
                gotoxy(14,15);
                cout<<"                                                  __________________ CAMBIO DE CHEQUE"<<endl;
                //tercera fil
                gotoxy(10,20);
                cout<<"                                                      __________________ SERVICIO A CLIENTE "<<endl;
                gotoxy(10,24);
                cout<<"                                                      __________________ "<<endl;
                cout<<"                                      _______ "<<endl;
                for (j=0; j<3; j++)
                    {
                    cout<<"                                     |  ATM  | "<<endl;
                    }
                cout<<"                                      _______ "<<endl;
                Sleep(30);
                /////////////eliminar mono enmedio
                gotoxy(10+x,10);
                cout<<"   "<<endl;
                gotoxy(10+x,11);
                cout<<"      "<<endl;
                if(x%2==0)
                    {
                    gotoxy(10+x,12);
                    cout<<"   "<<endl;
                    }
                else
                    {
                    gotoxy(10+x,12);
                    cout<<"     "<<endl;
                    }
                }
            //_______________________________________
            for (int x=20; x<36-o; x++)
                {
                //primer fila
                gotoxy(10,9);
                cout<<" ____________________                                 __________________ MOVIMIENTO"<<endl;
                gotoxy(10,13);
                cout<<" ____________________                                 __________________ "<<endl;
                //segunda fila
                gotoxy(14,20);
                cout<<"                                                  __________________ CAMBIO DE CHEQUE"<<endl;
                gotoxy(100,8);
                p.mostrar_tope();
                gotoxy(43+x,21);
                cout<<"  o  "<<endl;
                gotoxy(43+x,22);
                cout<<" /|\\ "<<endl;
                if(x%2==0)
                    {
                    gotoxy(43+x,23);
                    cout<<" | "<<endl;
                    }
                else
                    {
                    gotoxy(43+x,23);
                    cout<<" / \\ "<<endl;
                    }
                gotoxy(10,20);
                cout<<"                                                      __________________ SERVICIO A CLIENTE "<<endl;
                gotoxy(10,24);
                cout<<"                                                      __________________ "<<endl;
                cout<<"                                      _______ "<<endl;
                for (j=0; j<3; j++)
                    {
                    cout<<"                                     |  ATM  | "<<endl;
                    }
                cout<<"                                      _______ "<<endl;
                Sleep(30);

                }
            }
        if(cont3==4)
            {
            queue_tres.eliminar();
            }
        }
    ///////////////////////elimjanar cola
    for(int o=0; o<16; o=o+2)
        {
        if(o%3==0)
            {
            gotoxy(90,22);
            queue_tres.consultar_inicio();
            for (int x=20; x<30; x++)
                {
                gotoxy(10,9);
                cout<<" ____________________                                 __________________ MOVIMIENTO"<<endl;
                gotoxy(100,8);
                p.mostrar_tope();
                gotoxy(10+x,10);
                cout<<"    "<<endl;
                gotoxy(10+x,11);
                cout<<"      "<<endl;
                if(x%2==0)
                    {
                    gotoxy(10+x,12);
                    cout<<"   "<<endl;
                    }
                else
                    {
                    gotoxy(10+x,12);
                    cout<<"      "<<endl;
                    }
                gotoxy(10,13);
                cout<<" ____________________                                 __________________ "<<endl;
                //segunda fila
                gotoxy(14,15);
                cout<<"                                                  __________________ CAMBIO DE CHEQUE"<<endl;
                //tercera fil
                gotoxy(10,20);
                cout<<"                                                      __________________ SERVICIO A CLIENTE "<<endl;
                gotoxy(10,24);
                cout<<"                                                      __________________ "<<endl;
                cout<<"                                      _______ "<<endl;
                for (j=0; j<3; j++)
                    {
                    cout<<"                                     |  ATM  | "<<endl;
                    }
                cout<<"                                      _______ "<<endl;
                Sleep(30);
                /////////////eliminar mono enmedio
                gotoxy(10+x,10);
                cout<<"   "<<endl;
                gotoxy(10+x,11);
                cout<<"      "<<endl;
                if(x%2==0)
                    {
                    gotoxy(10+x,12);
                    cout<<"   "<<endl;
                    }
                else
                    {
                    gotoxy(10+x,12);
                    cout<<"     "<<endl;
                    }
                }
            //_______________________________________
            for (int x=20; x<36-o; x++)
                {
                //primer fila
                gotoxy(10,9);
                cout<<" ____________________                                 __________________ MOVIMIENTO"<<endl;
                gotoxy(10,13);
                cout<<" ____________________                                 __________________ "<<endl;
                //segunda fila
                gotoxy(14,20);
                cout<<"                                                  __________________ CAMBIO DE CHEQUE"<<endl;
                gotoxy(100,8);
                p.mostrar_tope();
                gotoxy(43+x,21);
                cout<<"     "<<endl;
                gotoxy(43+x,22);
                cout<<"      "<<endl;
                if(x%2==0)
                    {
                    gotoxy(43+x,23);
                    cout<<"   "<<endl;
                    }
                else
                    {
                    gotoxy(43+x,23);
                    cout<<"      "<<endl;
                    }
                gotoxy(10,20);
                cout<<"                                                      __________________ SERVICIO A CLIENTE "<<endl;
                gotoxy(10,24);
                cout<<"                                                      __________________ "<<endl;
                cout<<"                                      _______ "<<endl;
                for (j=0; j<3; j++)
                    {
                    cout<<"                                     |  ATM  | "<<endl;
                    }
                cout<<"                                      _______ "<<endl;
                Sleep(30);

                }
            }
        }
}

void OcultarCursor()
{
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 50;
    cci.bVisible= false;
    SetConsoleCursorInfo(hCon, &cci);
}

void abajo()
{
    for(int o=0; o<16; o=o+2)
        {
        if(o%3==0)
            {
            gotoxy(1,1);
            cout<<"BANCO MICHI"<<endl;
            cont2++;
            p.push(num=10+rand()%50);
            queueDos.llenar(num);
            gotoxy(8,1);
            for (int x=20; x<30; x++)
                {
                gotoxy(90,16);
                queueDos.consultar_inicio();
                gotoxy(10,9);
                cout<<" ____________________                                 __________________ MOVIMIENTO"<<endl;
                for(j=0; j<4; j++)
                    gotoxy(100,8);
                p.mostrar_tope();
                gotoxy(10+x,10);
                cout<<"  o "<<endl;
                gotoxy(10+x,11);
                cout<<" /|\\ "<<endl;
                if(x%2==0)
                    {
                    gotoxy(10+x,12);
                    cout<<" | "<<endl;
                    }
                else
                    {
                    gotoxy(10+x,12);
                    cout<<" / \\ "<<endl;
                    }
                gotoxy(10,13);
                cout<<" ____________________                                 __________________ "<<endl;
                //segunda fila
                gotoxy(14,15);
                cout<<"                                                 __________________ CAMBIO DE CHEQUE"<<endl;

                gotoxy(14,19);
                cout<<"                                                 __________________ "<<endl;
                //tercera fila
                gotoxy(14,20);
                cout<<"                                                 __________________ SERVICIO A CLIENTE"<<endl;
                gotoxy(14,24);
                cout<<"                                                 __________________ "<<endl;
                cout<<"                                      _______ "<<endl;
                for (j=0; j<3; j++)
                    {
                    cout<<"                                     |  ATM  | "<<endl;
                    }
                cout<<"                                      _______ "<<endl;
                Sleep(30);
                /////////////eliminar mono enmedio
                gotoxy(10+x,10);
                cout<<"   "<<endl;
                gotoxy(10+x,11);
                cout<<"      "<<endl;
                if(x%2==0)
                    {
                    gotoxy(10+x,12);
                    cout<<"   "<<endl;
                    }
                else
                    {
                    gotoxy(10+x,12);
                    cout<<"     "<<endl;
                    }
                }

            //_______________________________________
            for (int x=20; x<38-o; x++)
                {
                //primer fila
                gotoxy(10,9);
                cout<<" ____________________                                 __________________ MOVIMIENTO "<<endl;
                for(j=0; j<4; j++)
                    gotoxy(10,13);
                cout<<" ____________________                                 __________________ "<<endl;
                //segunda fila
                gotoxy(14,15);
                cout<<"                                                 __________________ CAMBIO DE CHEQUE"<<endl;
                gotoxy(100,8);
                p.mostrar_tope();
                gotoxy(40+x,16);
                cout<<"  o "<<endl;
                gotoxy(40+x,17);
                cout<<" /|\\ "<<endl;
                if(x%2==0)
                    {
                    gotoxy(40+x,18);
                    cout<<" | "<<endl;
                    }
                else
                    {
                    gotoxy(40+x,18);
                    cout<<" / \\ "<<endl;
                    }
                ////////////////////
                gotoxy(14,19);
                cout<<"                                                 __________________ "<<endl;
                //tercera fila
                gotoxy(14,20);
                cout<<"                                                 __________________ SERVICIO A CLIENTE"<<endl;
                gotoxy(14,24);
                cout<<"                                                 __________________" <<endl;
                cout<<"                                      _______ "<<endl;
                for (j=0; j<3; j++)
                    {
                    cout<<"                                     |  ATM  | "<<endl;
                    }
                cout<<"                                      _______ "<<endl;
                Sleep(30);
                }
            Sleep(30);
            }
        if(cont2==4)
            {
            queueDos.eliminar();
            }
        }
    for(int o=0; o<16; o=o+2)
        {
        if(o%3==0)
            {
            for (int x=20; x<30; x++)
                {
                gotoxy(90,16);
                queueDos.consultar_inicio();
                gotoxy(10,9);
                cout<<" ____________________                                 __________________ MOVIMIENTO"<<endl;
                for(j=0; j<4; j++)
                    gotoxy(100,8);
                p.mostrar_tope();
                gotoxy(10+x,10);
                cout<<"    "<<endl;
                gotoxy(10+x,11);
                cout<<"      "<<endl;
                if(x%2==0)
                    {
                    gotoxy(10+x,12);
                    cout<<"   "<<endl;
                    }
                else
                    {
                    gotoxy(10+x,12);
                    cout<<"      "<<endl;
                    }
                gotoxy(10,13);
                cout<<" ____________________                                 __________________ "<<endl;
                //segunda fila
                gotoxy(14,15);
                cout<<"                                                 __________________ CAMBIO DE CHEQUE"<<endl;

                gotoxy(14,19);
                cout<<"                                                 __________________ "<<endl;
                //tercera fila
                gotoxy(14,20);
                cout<<"                                                 __________________ SERVICIO A CLIENTE"<<endl;
                gotoxy(14,24);
                cout<<"                                                 __________________ "<<endl;
                cout<<"                                      _______ "<<endl;
                for (j=0; j<3; j++)
                    {
                    cout<<"                                     |  ATM  | "<<endl;
                    }
                cout<<"                                      _______ "<<endl;
                Sleep(30);
                /////////////eliminar mono enmedio
                gotoxy(10+x,10);
                cout<<"   "<<endl;
                gotoxy(10+x,11);
                cout<<"      "<<endl;
                if(x%2==0)
                    {
                    gotoxy(10+x,12);
                    cout<<"   "<<endl;
                    }
                else
                    {
                    gotoxy(10+x,12);
                    cout<<"     "<<endl;
                    }
                }

            //_______________________________________
            for (int x=20; x<38-o; x++)
                {
                //primer fila
                gotoxy(10,9);
                cout<<" ____________________                                 __________________ MOVIMIENTO "<<endl;
                for(j=0; j<4; j++)
                    gotoxy(10,13);
                cout<<" ____________________                                 __________________ "<<endl;
                //segunda fila
                gotoxy(14,15);
                cout<<"                                                 __________________ CAMBIO DE CHEQUE"<<endl;
                gotoxy(100,8);
                p.mostrar_tope();
                gotoxy(40+x,16);
                cout<<"    "<<endl;
                gotoxy(40+x,17);
                cout<<"      "<<endl;
                if(x%2==0)
                    {
                    gotoxy(40+x,18);
                    cout<<"   "<<endl;
                    }
                else
                    {
                    gotoxy(40+x,18);
                    cout<<"      "<<endl;
                    }
                ////////////////////
                gotoxy(14,19);
                cout<<"                                                 __________________ "<<endl;
                //tercera fila
                gotoxy(14,20);
                cout<<"                                                 __________________ SERVICIO A CLIENTE"<<endl;
                gotoxy(14,24);
                cout<<"                                                 __________________" <<endl;
                cout<<"                                      _______ "<<endl;
                for (j=0; j<3; j++)
                    {
                    cout<<"                                     |  ATM  | "<<endl;
                    }
                cout<<"                                      _______ "<<endl;
                Sleep(30);
                }
            Sleep(30);
            }
        }
}

void movimientoAtm()
{
    for(int o=0; o<8; o=o+4)
        {
        if(o%2==0)
            {
            gotoxy(1,1);
            cout<<"BANCO MICHI"<<endl;
            cont4++;
            gotoxy(14,1);
            p.push(num=10+rand()%50);
            for (int x=0; x<30; x++)
                {
                gotoxy(10,9);
                cout<<" ____________________                                 __________________ MOVIMIENTO "<<endl;
                gotoxy(100,8);
                p.mostrar_tope();
                //////////////7
                gotoxy(10+x,10);
                cout<<"  o "<<endl;
                gotoxy(10+x,11);
                cout<<" /|\\ "<<endl;
                if(x%2==0)
                    {
                    gotoxy(10+x,12);
                    cout<<" | "<<endl;
                    }
                else
                    {
                    gotoxy(10+x,12);
                    cout<<" / \\ "<<endl;
                    }
                ////////////////////
                gotoxy(10,13);
                cout<<" ____________________                                 __________________ "<<endl;
                gotoxy(10,15);
                cout<<"                                                      __________________ CAMBIO DE CHEQUE"<<endl;
                gotoxy(10,20);
                cout<<"                                                      __________________ "<<endl;
                gotoxy(10,24);
                cout<<"                                                      __________________ SERVICIO A CLIENTE"<<endl;
                cout<<"                                      _______ "<<endl;
                for (j=0; j<3; j++)
                    {
                    cout<<"                                     |  ATM  | " <<endl;
                    }
                cout<<"                                      _______ "<<endl;
                Sleep(30);
                /////////////eliminar mono enmedio
                gotoxy(10+x,10);
                cout<<"   "<<endl;
                gotoxy(10+x,11);
                cout<<"      "<<endl;
                if(x%2==0)
                    {
                    gotoxy(10+x,12);
                    cout<<"   "<<endl;
                    }
                else
                    {
                    gotoxy(10+x,12);
                    cout<<"     "<<endl;
                    }
                }

            ////////////////////
            ////________________________________________
            for (int x=40; x<52; x++)
                {
                gotoxy(10,9);
                cout<<" ____________________                                 __________________ "<<endl;
                gotoxy(100,8);
                p.mostrar_tope();
                //////////////7
                gotoxy(40,21-o);
                cout<<"  o "<<endl;
                gotoxy(40,22-o);
                cout<<" /|\\ "<<endl;
                if(x%2==0)
                    {
                    gotoxy(40,23-o);
                    cout<<" | "<<endl;
                    }
                else
                    {
                    gotoxy(40,23-o);
                    cout<<" / \\ "<<endl;
                    }
                ////////////////////
                gotoxy(10,13);
                cout<<" ____________________                                 __________________ "<<endl;
                gotoxy(10,15);
                cout<<"                                                      __________________ "<<endl;
                gotoxy(10,20);
                cout<<"                                                      __________________ "<<endl;
                gotoxy(10,24);
                cout<<"                                                      __________________ "<<endl;
                cout<<"                                      _______ "<<endl;
                for (j=0; j<3; j++)
                    {
                    cout<<"                                     |  ATM  | " <<endl;
                    }
                cout<<"                                      _______ "<<endl;
                Sleep(30);
                }
            }
        }
    ///////////////eliminar cola
    for(int o=0; o<8; o=o+4)
        {
        if(o%2==0)
            {
            gotoxy(14,1);
            p.push(num=10+rand()%50);
            for (int x=30; x<30; x++)
                {
                gotoxy(10,9);
                cout<<" ____________________                                 __________________ MOVIMIENTO "<<endl;
                gotoxy(100,8);
                p.mostrar_tope();
                //////////////7
                gotoxy(10+x,10);
                cout<<"    "<<endl;
                gotoxy(10+x,11);
                cout<<"      "<<endl;
                if(x%2==0)
                    {
                    gotoxy(10+x,12);
                    cout<<"   "<<endl;
                    }
                else
                    {
                    gotoxy(10+x,12);
                    cout<<"      "<<endl;
                    }
                ////////////////////
                gotoxy(10,13);
                cout<<" ____________________                                 __________________ "<<endl;
                gotoxy(10,15);
                cout<<"                                                      __________________ CAMBIO DE CHEQUE"<<endl;
                gotoxy(10,20);
                cout<<"                                                      __________________ "<<endl;
                gotoxy(10,24);
                cout<<"                                                      __________________ SERVICIO A CLIENTE"<<endl;
                cout<<"                                      _______ "<<endl;
                for (j=0; j<3; j++)
                    {
                    cout<<"                                     |  ATM  | " <<endl;
                    }
                cout<<"                                      _______ "<<endl;
                Sleep(30);
                /////////////eliminar mono enmedio
                gotoxy(10+x,10);
                cout<<"   "<<endl;
                gotoxy(10+x,11);
                cout<<"      "<<endl;
                if(x%2==0)
                    {
                    gotoxy(10+x,12);
                    cout<<"   "<<endl;
                    }
                else
                    {
                    gotoxy(10+x,12);
                    cout<<"     "<<endl;
                    }
                }

            ////////////////////
            ////________________________________________
            for (int x=40; x<52; x++)
                {
                gotoxy(10,9);
                cout<<" ____________________                                 __________________ "<<endl;
                gotoxy(100,8);
                p.mostrar_tope();
                //////////////7
                gotoxy(40,16-o);
                cout<<"    "<<endl;
                gotoxy(40,17-o);
                cout<<"      "<<endl;
                if(x%2==0)
                    {
                    gotoxy(40,18-o);
                    cout<<"    "<<endl;
                    }
                else
                    {
                    gotoxy(40,19-o);
                    cout<<"      "<<endl;
                    }
                ////////////////////
                gotoxy(10,13);
                cout<<" ____________________                                 __________________ "<<endl;
                gotoxy(10,15);
                cout<<"                                                      __________________ "<<endl;
                gotoxy(10,20);
                cout<<"                                                      __________________ "<<endl;
                gotoxy(10,24);
                cout<<"                                                      __________________ "<<endl;
                cout<<"                                      _______ "<<endl;
                for (j=0; j<3; j++)
                    {
                    cout<<"                                     |  ATM  | " <<endl;
                    }
                cout<<"                                      _______ "<<endl;
                Sleep(30);
                }
            }
        }
}



