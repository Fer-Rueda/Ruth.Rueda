/**
 * @author : Fer-Rueda
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
#define DELAY 100000

const string CEDULA = "1003781018";
const string NOMBRE = "Ruth Fernanda Rueda Rueda";
const string CORREO = "ruth.rueda@epn.edu.ec";

string rrUsuario = "";

enum actor{obse=0,lobo,cape,uvas};

bool obseEstaIzq = true;
int opcionmenu = -1,anchoRio=15;
string arrIzq[] ={"obse","lobo","cape","uvas"},
       arrDer[] ={"","","",""},
       actorCruza= "";

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
    cout << "\t\t -  Fecha : 07/07/2023"<< endl;
    
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
 * rrGetContrasena : Reemplaza cada caracter con un * 
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
 * rrGetCadenaSinEspaciosSimple : Obtiene una cadena de caracteres 
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

/**
 * getCadenaSinEspaciosSimple : Obtiene una cadena de caracteres 
 * @param label : Nombre de la etiqueta
*/
string rrExtraerNombre(string rrStr)
{
    int pos = rrStr.find('@');
    string rrUsername = rrStr.substr(0, pos);
    return rrUsername;
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
                rrUsuario = rrExtraerNombre(rrMayusculasCadena(user));
                cout << endl << endl << "\t\t:: Bienvenid@ " << rrUsuario << " al juego del lobito" <<endl <<endl;
                return true;
            }
        }
         
    } while (numIntento>0);

    cout<< "Usuario y clave incorrectos..." << endl;
    return false;
    
}

string showactor(const string arr[])
{
    string personaje="";
    for (int i = 0; i < 4; i++)
        personaje+=arr[i]+", ";
    return personaje;
}

string showrio(int lenRio)
{
    string rio="";
    for (int i = 0; i < lenRio-1; i++)
    {
        rio+=" - ";
    }
    return rio;
}

bool menu()
{
    cout<<"\n\t\t0.Solo\n\t\t1.Lobo\n\t\t2.Caperucita\n\t\t3.Uvas\n\t\t4.Salir";
   do
   {
        try
        {
            string str="";
            cout<<"\n\t\t>Cruzar: ";
            cin>>str;
            opcionmenu= stoi(str);
            actorCruza= (obseEstaIzq) ? arrIzq[opcionmenu]:arrDer[opcionmenu];
            if(opcionmenu==4) exit(0);
            
            if (actorCruza.empty())
            {
                throw invalid_argument("No hay personaje");
            }
            
        }
        catch(...)
        {
            actorCruza="";
            opcionmenu=-1;
            cout << "Lo siento, opcion no valida :(" << endl;//tambien funciona con cout
        }
        
   } while (opcionmenu<0);
   //try catch es un controlador de eventualidades, obliga al programa a cerrarse si no se cumple pero con la cpacidad de recuperar
    return true;
}

void validarReglas()
{
    string msg ="";
     bool todosCruzan=(!arrDer[obse].empty() && !arrDer[lobo].empty()
                      && !arrDer[cape].empty() && !arrDer[uvas].empty());
     bool lobCap = (obseEstaIzq)
                 ? (!arrDer[lobo].empty() && !arrDer[cape].empty()) 
                 : (!arrIzq[lobo].empty() && !arrIzq[cape].empty())  ;
     bool CapUva = (obseEstaIzq)
                 ? (!arrDer[cape].empty() && !arrDer[uvas].empty()) 
                 : (!arrIzq[cape].empty() && !arrIzq[uvas].empty())  ;

     msg+=(lobCap)?"===perdiste===" : "" ;
     cout << endl;
     msg+=(CapUva)?"===perdiste===": "" ;
     cout << endl;
     msg = (todosCruzan) ? "===GANASTE===" : msg;

     if (!msg.empty())   
     {
        cout << "FINAL DEL JUEGO" << endl << msg <<endl;
        exit(0);

     }              

}
void navegar()
{
    obseEstaIzq=!obseEstaIzq;
    arrIzq[obse]=arrIzq[opcionmenu]=arrDer[obse]=arrDer[opcionmenu]= "";
    if(obseEstaIzq)
     {
        arrIzq[obse]= "obse";
        arrIzq[opcionmenu]= actorCruza;
     }
     else
     {
        arrDer[obse]= "obse";
        arrDer[opcionmenu]= actorCruza;
     }

    string barca = "\\_obsee_,_"+actorCruza+"_/",
           actorIzq=showactor(arrIzq),
           actorDer=showactor(arrDer);

    if(!obseEstaIzq)
      for(int pos = 0;pos < anchoRio;pos++)
        {
            cout <<"\r"+actorIzq+showrio(pos)+barca+showrio(anchoRio-pos)+actorDer;
            usleep(DELAY);
        }
    else
        for(int pos = anchoRio;pos >= 0;pos--)
        {
            cout <<"\r"+actorIzq+showrio(pos)+barca+showrio(anchoRio-pos)+actorDer;
            usleep(DELAY);
        }
    validarReglas();
           
}
