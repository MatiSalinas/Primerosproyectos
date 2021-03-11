#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream er("dEventos.txt");
ifstream rt("datos.txt");
 const int n=50;
struct agendas{
    string nombre;
    string apellido;
    string direccion;
    int telefono;
    bool ocupado=0;

};


struct calendarios{
    string evento;
    int dia,mes,anio;
    int hora,minuto;
    string lugar;
    bool ocupado = 0;


};
agendas a[n];
calendarios b[n];
void menu();

void cargar(){
    for (int i= 0 ; i < n ; i++)
    {

            rt>>a[i].nombre;
            rt>>a[i].apellido;
            rt>>a[i].direccion;
            rt >> a[i].telefono;
            rt >> a[i].ocupado;



           er >> b[i].evento ;
           er >> b[i].dia ;
            er>> b[i].mes ;
            er>> b[i].anio ;
           er>> b[i].hora ;
          er>> b[i].minuto ;
           er>> b[i].lugar ;
           er>>b[i].ocupado ;
        }
    }






void mostrarA(){
    for (int i = 0 ; i < n ; i++)
    {
        if (a[i].ocupado==1)
        {
            cout <<" ------------------------ "<< endl;
            cout << "nombre : " << a[i].nombre << endl;
            cout << "apellido : " << a[i].apellido << endl;
            cout << "direccion : " << a[i].direccion << endl;
            cout << "numero : " << a[i].telefono << endl;
        }
    }



menu();
}


void guardar(){
    ofstream kt("datos.txt");
    ofstream ew("dEventos.txt");
 for (int i = 0 ; i < n ; i++)
    {

        if (a[i].ocupado==1)
        {


             kt << a[i].nombre << endl;
              kt << a[i].apellido << endl;
            kt<< a[i].direccion << endl;
           kt << a[i].telefono << endl;
           kt << a[i].ocupado << endl;
        }
        if (b[i].ocupado==1)
        {
            ew << b[i].evento << endl;
            ew<< b[i].dia << endl;
            ew<< b[i].mes << endl;
            ew<< b[i].anio << endl;
           ew << b[i].hora << endl;
           ew<< b[i].minuto << endl;
           ew << b[i].lugar << endl;
           ew << b[i].ocupado << endl;

        }

    }

}
void aAgenda()
{
  for (int i = 0; i < n ; i++)
  {
      if (a[i].ocupado==0){

      cout << "ingrese el nombre " << endl;
        cin >> a[i].nombre;
        cout << "ingrese el apellido " << endl;
        cin >> a[i].apellido;
      cout << "ingrese la direccion" << endl;
      cin >> a[i].direccion;
      cout << "ingrese el numero" << endl;
      cin >> a[i].telefono;
      a[i].ocupado=1;
      break;
      }

  }
  menu();
}
void bAgenda(){
string aux;
cout << "ingrese el nombre del contacto a borrar" << endl;
cin >> aux;

for(int i = 0 ; i  < n ; i++)
{
    if (aux == a[i].nombre)
    {
        a[i].ocupado=0;
        cout << "se borro correctamente \n";
        break;
    }
}
menu();
}
void mAgenda(){


string aux;
cout << "ingrese el nombre del contacto a modificar" << endl;
cin >> aux;

for(int i = 0 ; i  < n ; i++)
{
    if (aux == a[i].nombre)
    {

      cout << "ingrese el nombre " << endl;
      cin >> a[i].nombre;
      cout << "ingrese la direccion" << endl;
      cin >> a[i].direccion;
      cout << "ingrese el numero" << endl;
      cin >> a[i].telefono;

    }
}
menu();
}


void aCalendario()
{
      for (int i = 0; i < n ; i++)
  {
      if (b[i].ocupado==0){

      cout << "ingrese el nombre del evento " << endl;
      cin >> b[i].evento;
      cout << "ingrese el dia" << endl;
      cin >> b[i].dia;
      cout << "ingrese el mes" << endl;
      cin >> b[i].mes;
      cout << "ingrese el anio" << endl;
      cin >> b[i].anio;
      cout << "ingrese la hora" << endl;
      cin >> b[i].hora;
      cout << "ingrese el minuto" << endl;
      cin >> b[i].minuto;
      cout << "ingrese el lugar" << endl;
      cin >> b[i].lugar;
      b[i].ocupado=1;
      break;
      }

  }
  menu();
}

void bCalendario(){
string aux;
cout << "ingrese el nombre del evento a borrar" << endl;
cin >> aux;

for(int i = 0 ; i  < n ; i++)
{
    if (aux == b[i].evento)
    {
        b[i].ocupado=0;
         cout << "se borro correctamente \n";
        break;
    }
}
menu();}

void mostrarEvento(){ for (int i = 0 ; i < n ; i++)
    {
        if (b[i].ocupado==1)
        {
            cout << "nombre del evento : " << b[i].evento << endl;
            cout << "Fecha : " << b[i].dia << "/" << b[i].mes<< "/" << b[i].anio << endl;
            cout << "Hora: " << b[i].hora << ":" << b[i].minuto << endl;
            cout << "lugar: " << b[i].lugar << endl;
        }
    }



menu();}

int main()
{
    cargar();
    menu();


    return 0;
}
void menu(){
    int op;
cout << "Que accion desea realizar?" << endl;
cout << "1. Agregar un contacto" << endl;
cout << "2. eliminar un contacto" << endl;
cout << "3. modificar un contacto" << endl;
cout << "4. Ver todos los contactos" << endl;
cout << "5. Agregar un evento" << endl;
cout << "6. eliminar un evento" << endl;
cout << "7. ver todos los eventos" << endl;
cout << "8.Guardar" << endl;

while (op!=9){
cin >> op;
switch (op){
case 1:
    aAgenda();
    break;
case 2:
    bAgenda();
    break;
case 3:
    mAgenda();
    break;
case 4:
    mostrarA();
    break;
case 5:
    aCalendario();
    break;
case 6:
    bCalendario();
    break;
case 7:
    mostrarEvento();
    break;
case 8:
    guardar();
    break;
case 9:
    break;



}

}
}
