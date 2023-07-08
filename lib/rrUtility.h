/**
 * @author : Ruth.Rueda
 * libreria de utilitarios
 **/

#include "iostream"
#include "string"
#include <string.h>
#include "unistd.h"
#include "vector"
#include "conio.h"
#include "algorithm"
#include "cstring"
#include "iomanip"

using namespace std;

//const string WHITESPACE = " \n\r\t\f\v";
const string WHITESPACE = " ";
#define SLEEP 50000

const string CEDULA = "1003781018";
const string NOMBRE = "Ruth Fernanda Rueda Rueda";
const string CORREO = "ruth.rueda@epn.edu.ec";

string rrUsuario = "";

enum rrMenuOpc {SOLO = 0, LOBO, CAPERUCITA, UVAS, SALIR};

/**
 * rrMayusculasCadena: retorna una cadena en mayusculas
 * @param str   : cadena de caracteres
*/
string rrMayusculasCadena(string str)
{
    for (long long unsigned int i=0; i < str.length(); i++)
        str[i] = toupper(str[i]);
    return str;
}

/**
 * rrMinusculasCadena: retorna una cadena en mayusculas
 * @param str   : cadena de caracteres
*/
string rrMinusculasCadena(string str)
{
    for (long long unsigned int i=0; i < str.length(); i++)
        str[i] = tolower(str[i]);
    return str;
}

/**
 * quitarEspaciosIz: elimina los espacios en blanco de la izquierda
 * @param s   : cadena de caracteres
*/
void rrMostrarDatos()
{
    cout << "\t\tRECUPERACION EXAMEN PROGRA I"<< endl << endl;
    cout << "\t\t[+] Datos Personales: "<< endl;
    cout << "\t\t -  Cedula: "<< CEDULA << endl;
    cout << "\t\t -  Correo: "<< rrMinusculasCadena(CORREO) << endl;
    cout << "\t\t -  Nombre: "<< rrMayusculasCadena(NOMBRE) << endl;
    cout << "\t\t -  Fecha : 27/06/2023"<< endl;
    
}

/**
 * getNumeroPositivo : Obtiene un numero entero positivo
 * @param label : Nombre de la etiqueta
*/
int getNumeroPositivo(string label) 
{
    int numero;
    bool Validar = false;
    string str;

    do
    {
        cout << "\n" << label;
        getline(cin, str);

        cin.clear();
        fflush(stdin);
        try {
            numero = stoi(str);
            Validar = true;
        } catch (const std::exception& e) {
            Validar = false;
        }
    } while (!Validar);
    return numero;  
}

/**
 * rrGetNumeroIntervalo: Obtiene un numero entero entre un límite inferior y superior
 * @param label  : Nombre de la etiqueta
 * @param liminf : int limite inferior del intervalo
 * @param limsup : int limite superior del intervalo
*/
int rrGetNumeroIntervalo(string label, int liminf, int limsup)
{
    int rrNumero;
    bool rrValidar = false;
    string str;

    do {
        cout<<label;
        getline (cin,str);

        rrValidar = false;
        cin.clear();
        fflush(stdin);

        try
        {
            rrNumero = stoi(str);
            if ((rrNumero >= liminf) && (rrNumero <= limsup))
                rrValidar = true;
        }
        catch(const std::exception& e)
        {
            rrNumero = liminf-1;
        }
    } while (!rrValidar);

    return rrNumero;
}

/**
 * getContrasena : Reemplaza cada caracter con un * 
 * @param label : Nombre de la etiqueta
*/
string getContrasena(string label)
{
    int i=0;
    char con[10] = { 0 };

    cout<<label;

	while ((con[i] = _getch()) && int(con[i++])!= 13)
		_putch('*');

	con[--i] ='\0';
	cin.clear();
    fflush(stdin);
	cout<<"\n";
	return con;
}

/**
 * getCadenaSinEspaciosSimple : Obtiene una cadena de caracteres 
 * @param label : Nombre de la etiqueta
*/

string rrGetCadenaSinEspaciosSimple(string label)
{
    string str;
    
    cout << "\n" << label;
    getline(cin, str);
    
    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
    cin.clear();
    fflush(stdin);
    return str;
}


int rrMenu ()
{
    cout<< "\t\t" << SOLO <<  " Solo" <<endl;
    cout<< "\t\t" << LOBO <<  " Lobo" <<endl;
    cout<< "\t\t" << CAPERUCITA <<  " Caperucita" <<endl;
    cout<< "\t\t" << UVAS <<  " Uvas" <<endl;
    cout<< "\t\t" << SALIR <<  " Salir" <<endl;
    return rrGetNumeroIntervalo("\t\t>> Ingresa Opcion: ", 0 , 4); 

}

bool loginUsuario()
{
    int numIntento = 3;
    vector<string> usuarios = {CORREO+CEDULA, "profe1234"};

    do
    {
        cout << endl << "\t\t............................" << endl;
        string user = rrGetCadenaSinEspaciosSimple("\t\t+ usuario: ");
        string pass = getContrasena("\t\t+ clave: ");
        cout << "\t\t............................" << endl;
        cout<< "\t\t *Nro de intentos: " << --numIntento << endl <<endl;
        for(auto &&up : usuarios)
        {
            if(user+pass == up)
            {
                rrUsuario = rrMayusculasCadena(user);
                cout << endl << endl << "\t\t:: Bienvenido " << rrUsuario << endl <<endl;
                return true;
            }
        }
         
    } while (numIntento>0);

    cout<< "Usuario y clave incorrectos..." << endl;
    return false;
    
}

string rrExtraerNombre(string rrStr)
{
    //string rrNombre;
    int rrPos=0;

    for(long long unsigned int i = 0; i < rrStr.length(); i++)
    {
        if(rrStr[i] == '@')
        {
            rrPos = i;
        }
    }

    string rrNombre = rrStr.substr(0,rrPos);

    return rrNombre;

}



void rrBarca()
{
    string rrNombre = rrExtraerNombre(rrUsuario);
}
