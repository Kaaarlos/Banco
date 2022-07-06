#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include<iostream>
#include<stdlib.h>
using namespace std;

class cola{
	private:
		int inicio,fin;
		//int  dato[20];

	public:
	        cola();
	        int lleno();
	        int vacio();
               void llenar(double);
               void consultar_inicio();
               void consultar_final();
               void mostrar_cola();
               void eliminar();
               int dato[100]={-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2};

};
cola::cola(){
	fin=-1;
	inicio=0;
}
 void cola::llenar(double n){
	 if(lleno()==0){
	 	fin ++;
 		dato[fin]=n;

	 }
 }

void cola::consultar_inicio(){
	if(vacio()==0){
		int aux=0;
		cout<<"|"<< dato[aux] <<"|"<<endl;
	}
}

void cola::consultar_final(){
	if(vacio()==0){
		cout<< dato[fin] <<endl;

	}
}

void cola::mostrar_cola(){
	if(vacio()==0){
	system("cls");
			printf("\n\n\t\t%c%c%c%c%c  \n",201,205,205,205,187);
		    for(int i=9;i>=0;i--){
		     if(dato[i]!=-2){
		 		     printf("\t\t%c ",186,205);
		 				 if(i==0){
		 					 cout<<dato[i]; printf(" %c\n",186);
		 	 		    printf("\t\t%c%c%c%c%c\n",200,205,205,205,188);

		 				 }
		 				 else{
		 					 cout<<dato[i]; printf(" %c\n",186);
		 	 		    printf("\t\t%c%c%c%c%c\n",204,205,205,205,185);
		 				 }
	            }
		    }


	}

}

void cola::eliminar(){
	if(vacio()==0){
		for(int i=0;i<=fin;i++){
			dato[i]=dato[i+1];
		}
		dato[fin]=-2;
		fin--;
	}
}

int cola::lleno(){
	if(fin==20){
		cout<<"LA COLA ESTA LLENA"<<endl;
		system("pause");
		return 1;
	}else{
		return 0;
	}
}
int cola::vacio(){
	if(fin==-1){
		return 1;
	} else{
		return 0;
	}
}


#endif // COLA_H_INCLUDED
