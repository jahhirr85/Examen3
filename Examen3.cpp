#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include <iostream>

using namespace std;
HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
void gotoxy(int x ,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}

void cuadro(int x1, int y1, int x2, int y2)
{
	int i;
	
	for (i=x1; i<=x2;i++)
	{
		gotoxy(i,y1); printf("%c",205);   
		gotoxy(i,y2); printf("%c",205);   
	}

	for (i=y1; i<=y2;i++)
	{
		gotoxy(x1,i); printf("%c",186);  
		gotoxy(x2,i); printf("%c",186);   
	}

	
	gotoxy(x1,y1); printf("%c",201);   
	gotoxy(x1,y2); printf("%c",200);  
	gotoxy(x2,y1); printf("%c",187);  
	gotoxy(x2,y2); printf("%c",188);  

}
	
int encontrado = -1;
bool finded=false;

struct Fecha{
	int dia, mes, anio;
};

struct Viajero {  
string id;  
string nombre;  
string direccion; 
string nacionalidad; 
};

struct Ingreso {  
int idViajero;  
string fecha_ingreso;  
string lugar_ngreso;
Fecha fech_in;  
};

 

struct Salida {  
int idViajero;  
string fecha_salida;  
string lugar_salida;
Fecha fech_out;  
}datos_salid[100]; 

struct Datos{
	Viajero cedula;
	Viajero name;
	Viajero address;
	Viajero pais;
	Ingreso fech_ingreso;
	Ingreso lugar_ingreso;
	Salida fech_salida;
	Salida lugar_salida;
};

Datos data[100];
int numViajeros=0;

void Agregar (int tipo)
{
	
	char opcion;
	if (tipo==-1){
	
/*	do {*/
	system("cls");
	cout<<"Ingrese el nombre del viajero: "<<endl;
	cin>> data[numViajeros].name.nombre;
	cout<<"Ingrese el numero de Id: "<<endl;
	cin>>data[numViajeros].cedula.id;
	cout<<"Ingrese direccion del Viajero: "<<endl;
	cin>> data[numViajeros].address.direccion;
	cout<<"Ingrese nacionalidad del Viajero: "<<endl;
	cin>> data[numViajeros].pais.nacionalidad;
	numViajeros++;


/*	 }while (opcion=='s');*/
	}else {
	system("cls");
	cout<<"Ingrese el nombre del viajero: "<<endl;
	cin>> data[numViajeros].name.nombre;
	cout<<"Ingrese el numero de Id: "<<endl;
	cin>>data[numViajeros].cedula.id;
	cout<<"Ingrese direccion del Viajero: "<<endl;
	cin>> data[numViajeros].address.direccion;
	cout<<"Ingrese nacionalidad del Viajero: "<<endl;
	cin>> data[numViajeros].pais.nacionalidad;
	}

}
void Reporte(int pos)
{
	system("cls");
	if (pos!=-1)
	{
		cout<<"Nombre: "<<data[pos].name.nombre<<endl;
		cout<<"ID: "<<data[pos].cedula.id<<endl;
		cout<<"Direccion: "<<data[pos].address.direccion<<endl;
		cout<<"Nacionalidad: "<<data[pos].pais.nacionalidad<<endl<<endl;
	    
	}else {
	
	
	system("cls");
	for(int a=0;a<numViajeros;a++)
	{
		cout<<"Viajero "<<a+1<<endl;
		cout<<"Nombre: "<<data[a].name.nombre<<endl;
		cout<<"ID: "<<data[a].cedula.id<<endl;
		cout<<"Direccion: "<<data[a].address.direccion<<endl;
		cout<<"Nacionalidad: "<<data[a].pais.nacionalidad<<endl<<endl;
		cout<<"Fecha de ingreso: "<<data[a].fech_ingreso.fech_in.dia<<"-"<<data[a].fech_ingreso.fech_in.mes<<"-"<<data[a].fech_ingreso.fech_in.dia<<endl;
		cout<<"Fecha de salida: "<<data[a].fech_salida.fech_out.dia<<"-"<<data[a].fech_salida.fech_out.mes<<"-"<<data[a].fech_salida.fech_out.dia<<endl;
	}

	}
	
	
}
void Buscar ()
{
	char opc;
	string criterio;
	
//	do { 
	//	system("cls");
		cout<<"Digite el Id del viajero: "<<endl;
		cin>>criterio;
			
			for (int a=0;a<numViajeros;a++)
			{
				if(criterio==data[a].cedula.id)
				{
				Reporte(a);
				encontrado=a;
				finded=true;
				}
			}
			if (finded==false) {
				cout<<"ID no encontrado"<<endl;
				
			}
		
		}
	

void Registro_IN_OUT()
{
	int opc_registro;
	string persona;
	system("cls");
	cout<<"Seleccione la opcion que desea registrar:"<<endl<<endl;
	cout<<"[ 1 ] Registrar Ingreso"<<endl;
	cout<<"[ 2 ] Registrar Salida"<<endl;
	cin>>opc_registro;
	if (opc_registro==1)
	{
	system("cls");
	cout<<"******REGISTRO DE INGRESO AL PAIS**********"<<endl;
	cout<<"Digite el numero de ID del viajero: "<<endl;
	cin>>persona;
		for (int a=0;a<numViajeros;a++)
			{
				if(persona==data[a].cedula.id)
				{
				encontrado=a;
			}
	}
	cout<<"Digite el dia de ingreso: "<<endl;
	cin>>data[encontrado].fech_ingreso.fech_in.dia;
	cout<<"Digite el mes de ingreso: "<<endl;
	cin>>data[encontrado].fech_ingreso.fech_in.mes;
	cout<<"Digite el anio de ingreso: "<<endl;
	cin>>data[encontrado].fech_ingreso.fech_in.anio;
	
}if (opc_registro==2){
	system("cls");
	cout<<"******REGISTRO DE SALIDA AL PAIS**********"<<endl;
	cout<<"Digite el numero de ID del viajero: "<<endl;
	cin>>persona;
		for (int a=0;a<numViajeros;a++)
			{
				if(persona==data[a].cedula.id)
				{
				encontrado=a;
			}
	}
	cout<<"Digite el dia de salida: "<<endl;
	cin>>data[encontrado].fech_salida.fech_out.dia;
	cout<<"Digite el mes de salida: "<<endl;
	cin>>data[encontrado].fech_salida.fech_out.mes;
	cout<<"Digite el anio de salida: "<<endl;
	cin>>data[encontrado].fech_salida.fech_out.anio;
}
}
void Eliminar()
{
	char opc;
	system("cls");
	Buscar();
	cout<<"Desea Eliminarlo: s/n"<<endl;
	opc=getch();
	if (opc=='s')
		{
		for (int i = encontrado;i<numViajeros;i++)
			{
   			data[i].name.nombre=data[i+1].name.nombre;
   			data[i].cedula.id=data[i+1].cedula.id;
   			data[i].address.direccion=data[i+1].address.direccion;
   			data[i].pais.nacionalidad=data[i+1].pais.nacionalidad;
			}
		numViajeros--;	
	cout<<"ID Eliminado"<<endl;
	}else if (opc!='s') {
		
	}
}

void menu()
{
	char opc,conti,opc2, opc3, opc4, opc5;
	do	{
		system("cls");
		SetConsoleTextAttribute (hConsoleHandle, 10);
		cuadro(16,2,65,6);
		cuadro(8,8,72,23);
		cuadro(8,24,72,26); 
		cuadro(15,20,27,22);
		SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(22,4);cout<<" ******* SISTEMA DE MIGRACION *******";
        SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(15,10);cout<<"[1]  Ingresar viajero";
		gotoxy(15,12);cout<<"[2]  Registro Ingreso / Salida";
		gotoxy(15,14);cout<<"[3]  Borrar Registros";
		gotoxy(15,16);cout<<"[4]  Consultar";
		gotoxy(15,18);cout<<"[5]  Generar Reporte";
		gotoxy(16,21);cout<<"<[6] SALIR>";
		
		SetConsoleTextAttribute(hConsoleHandle,14);
		gotoxy(15,25);cout<<"Su opcion es: ";
		opc=getch();

		switch(opc)
			{
			case '1': 
			do {
			Agregar(-1);
			cout<<"Desea ingresar otro contacto: s/n";
			opc3=getch();
			}while (opc3=='s');
			break;
			case '2': Registro_IN_OUT();
			break;
			case '3':
			do {
			 Eliminar();
			 cout<<"Desea realizar otra modificacion: s/n"<<endl;
			 opc4=getch(); 
		}while (opc4=='s');
			 break;
			case '4': 
			do {
			 Buscar();
			 cout<<"Desea realizar eliminar otro contacto: s/n"<<endl;
			 opc5=getch(); 
		}while (opc5=='s');
			 break;
			case '5': 
			Reporte(-1); 
			getch();
			break;
			case '6': 
				
			system("cls");
			gotoxy(20,10);cout<<"Estas seguro Que Deseas Salir del Sistema";
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(20,15);cout<<"Desea Continuar S/N";
			conti=getch();

			if (conti=='N' || conti=='n')
			menu();
			else if (conti=='S' || conti=='s')
			break; 
			}
		}while(opc!='6');
}

int main(int argc, char** argv) {
	menu();
	return 0;
}
