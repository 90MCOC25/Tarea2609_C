#include <iostream>
#include <string.h>
using namespace std;
const char *nombre_archivo = "archivo.dat";
struct Estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};
void crear();
void leer();
void actualizar();
void eliminar ();
main(){
	leer();
	crear();
	actualizar();
	eliminar ();
}
void leer(){
		system("cls");
		FILE* archivo = fopen(nombre_archivo,"rb");	
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");	
		}
		Estudiante estudiante;
		int id=0;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"____________________________________________"<<endl;
		cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombres"<<"|"<<"Apellidos"<<"|"<<"Telefono"<<endl;
		do{
		cout<<"____________________________________________"<<endl;
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;	
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;	
		}while(feof(archivo)==0);
		fclose(archivo);
		cout<<endl;
}
void actualizar(){
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	Estudiante estudiante;
	string nombre,apellido;
	cout<<"Ingres el ID que desa Modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
	
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	fclose(archivo);
	leer();
}
void crear(){
	char continuar;
	FILE* archivo = fopen(nombre_archivo,"ab");
	Estudiante estudiante;
	string nombre,apellido;
	do{
		fflush(stdin);
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese los Nombres:";
		getline(cin,nombre);
		strcpy(estudiante.nombres,nombre.c_str());
		cout<<"Ingrese los Apellidos:";
		getline(cin,apellido);
		strcpy(estudiante.apellidos,apellido.c_str());
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Dese Agregar otro Estudiante (s/n):";
		cin>>continuar;
	} while ( (continuar=='s') || (continuar=='S') );
	fclose(archivo);
	leer();
	
void eliminar (){
	if(archivo!=0){
		bool band=false;
		int codigo;
		
		cout<<"Ingrese el numero de Id de estudiante a Eliminar:";
		cin>>codigo;
		
		for (int i=0; i<codigo; i++){
        if(dato == estudiante[i].id){
            cout<<":::Datos a Eliminar:::"<<endl;
            cout << "========================" << endl;
            cout<<"codigo: "<<estudiante[i].id<<endl;
            cout<<"Nombres: "<<estudiante[i].nombres<<endl;
            cout<<"Apellidos: "<<estudiante[i].apellidos<<endl;
            cout<<"Telefono: "<<estudiante[i].telefono<<endl;
            cout << "========================" << endl;
            cout << "\nEstudiante eliminado correctamente\n" << endl;
            system ("pause");

            band=true;

            Codigo[i].id = 0;
            Nombres[i].nombre[0]='\0';
            *Apellidos[i].apellido=0;
            *Telefono[i].telefono=0;
           
            archivo--;
        }
    }
    if(band==false){
        cout<<"\nEl estudiante ingresado no existe\n"<<endl;
        system("pause");
    }
}
else{
  cout<<"\nNo hay estudiantes registrados\n"<<endl;
  system ("pause");
}


	

