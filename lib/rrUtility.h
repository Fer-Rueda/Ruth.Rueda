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
#define DELAY 100000

int rrNumViajes=0;

const string CEDULA = "1003781018";
const string NOMBRE = "Ruth Fernanda Rueda Rueda";
const string CORREO = "ruth.rueda@epn.edu.ec";

string rrNombreUsuario = "";

enum actor{obse=0,lobo,cape,uvas};

bool rrObseEstaIzq = true;
int rrOpcionMenu = -1,rrAnchoRio=15;
string rrArrIzq[] ={"obse","lobo","cape","uvas"},
       rrArrDer[] ={"","","",""},
       rrActorCruza= "";

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
 * rrGetNumeroPositivo : Obtiene un numero entero positivo
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
string rrGetContrasena(string label)
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
    int rrPos = rrStr.find('@');
    string rrUsername = rrStr.substr(0, rrPos);
    return rrUsername;
}

bool rrLoginUsuario()
{
    int numIntento = 3;
    vector<string> rrUsuarios = {CORREO+CEDULA, "profe1234"};

    do
    {
        cout << endl << "\t\t...................................." << endl;
        string user = rrGetCadenaSinEspaciosSimple("\t\t+ usuario: ");
        string pass = rrGetContrasena("\t\t+ clave: ");
        cout << "\t\t...................................." << endl;
        cout<< "\t\t *Nro de intentos: " << --numIntento << endl <<endl;
        for(auto &&up : rrUsuarios)
        {
            if(user+pass == up)
            {
                rrNombreUsuario = rrExtraerNombre(rrMayusculasCadena(user));
                cout << endl << endl << "\t\t:: Bienvenid@ " << rrNombreUsuario << " al juego del lobito" <<endl <<endl;
                return true;
            }
        }
         
    } while (numIntento>0);

    rrSetTextColor(textColorBlue);
    cout<< "\t\tUsuario o clave incorrectos..." << endl;
    return false;
    
}

string rrShowActor(const string rrArr[])
{
    string rrPersonaje="";
    for (int i = 0; i < 4; i++)
        rrPersonaje+=rrArr[i]+", ";
    return rrPersonaje;
}

string rrShowRio(int rrLenRio)
{
    string rrRio="";
    for (int i = 0; i < rrLenRio-1; i++)
    {
        rrRio+=" _ ";
    }
    return rrRio;
}

bool rrMenu()
{
    cout<<"\n\t\t0.Solo\n\t\t1.Lobo\n\t\t2.Caperucita\n\t\t3.Uvas\n\t\t4.Salir";
   do
   {
        try
        {
            string rrStr="";
            cout<<"\n\t\t>Cruzar: ";
            cin>>rrStr;
            rrOpcionMenu= stoi(rrStr);
            rrActorCruza= (rrObseEstaIzq) ? rrArrIzq[rrOpcionMenu]:rrArrDer[rrOpcionMenu];
            if(rrOpcionMenu==4)
            {
                rrSetTextColor(textColorGreen);
                cout<< "\n\t\tNumero de Viajes: " << rrNumViajes <<endl;
                cout<< "\n\t\tSaliste del juego del lobito, adiós " << rrNombreUsuario <<endl;
                exit(0);
            }
            
            if (rrActorCruza.empty())
            {
                throw invalid_argument("No hay personaje");
            }
            
        }
        catch(...)
        {
            rrActorCruza="";
            rrOpcionMenu=-1;
            cout << "\n\t\tLo siento, opcion no valida :(" << endl;//tambien funciona con cout
        }
        
   } while (rrOpcionMenu<0);
   //try catch es un controlador de eventualidades, obliga al programa a cerrarse si no se cumple pero con la cpacidad de recuperar
    return true;
}

void rrValidarReglas()
{
    string rrMsg ="";
     bool rrTodosCruzan=(!rrArrDer[obse].empty() && !rrArrDer[lobo].empty()
                      && !rrArrDer[cape].empty() && !rrArrDer[uvas].empty());
     bool rrLobCap = (rrObseEstaIzq)
                 ? (!rrArrDer[lobo].empty() && !rrArrDer[cape].empty())
                 : (!rrArrIzq[lobo].empty() && !rrArrIzq[cape].empty())  ;
     bool rrCapUva = (rrObseEstaIzq)
                 ? (!rrArrDer[cape].empty() && !rrArrDer[uvas].empty()) 
                 : (!rrArrIzq[cape].empty() && !rrArrIzq[uvas].empty())  ;
    
     if(rrLobCap && rrCapUva)
     {
        rrMsg+=(rrLobCap)?"Perdiste!!! Se comieron todos" : "" ;
        cout << endl;
     }
     else
     {
        rrMsg+=(rrLobCap)?"Perdiste!!! El Lobito se comio a Caperucita" : "" ;
        cout << endl;
        rrMsg+=(rrCapUva)?"Perdiste!!! La Caperucita se comio las Uvas": "" ;
        cout << endl;
     }

     rrMsg = (rrTodosCruzan) ? "Ganaste, Felicitaciones!!!" : rrMsg;

     if (!rrMsg.empty())   
     {
        rrSetTextColor(textColorGreen);
        cout << "\t\tFIN DEL JUEGO" << endl <<"\t\t"<< rrMsg <<endl;
        cout<< "\t\tNumero de Viajes: " << rrNumViajes <<endl;
        exit(0);

     }              

}
void rrNavegar()
{
    rrObseEstaIzq=!rrObseEstaIzq;
    rrArrIzq[obse]=rrArrIzq[rrOpcionMenu]=rrArrDer[obse]=rrArrDer[rrOpcionMenu]= "";
    if(rrObseEstaIzq)
     {
        rrArrIzq[obse]= "obse";
        rrArrIzq[rrOpcionMenu]= rrActorCruza;
     }
     else
     {
        rrArrDer[obse]= "obse";
        rrArrDer[rrOpcionMenu]= rrActorCruza;
     }

    string rrBarca = "\\_"+rrNombreUsuario+"_,_"+rrActorCruza+"_/ ",
           rrActorIzq=rrShowActor(rrArrIzq),
           rrActorDer=rrShowActor(rrArrDer);

    if(!rrObseEstaIzq)
      for(int rrPos = 0;rrPos < rrAnchoRio;rrPos++)
        {
            cout <<"\r"+rrActorIzq+rrShowRio(rrPos)+rrBarca+rrShowRio(rrAnchoRio-rrPos)+rrActorDer;
            usleep(DELAY);
        }
    else
        for(int rrPos = rrAnchoRio;rrPos >= 0;rrPos--)
        {
            cout <<"\r"+rrActorIzq+rrShowRio(rrPos)+rrBarca+rrShowRio(rrAnchoRio-rrPos)+rrActorDer;
            usleep(DELAY);
        }
    rrValidarReglas();
           
}
