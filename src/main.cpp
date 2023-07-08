#include "iostream"
#include "../lib/rrColor.h"
#include "../lib/rrUtility.h"

using namespace std;

int main()
{
    rrSetTextColor(textColorMagenta);
    rrMostrarDatos();

    rrSetTextColor(textColorGreen);

    if( loginUsuario() )
    {
        cout << "Bienvenido al juego del lobillo"<< rrExtraerNombre(rrUsuario);
         
    }

    return 0;
     
}
