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

        rrSetTextColor(textColorBlue);
        while (menu())
        {
            cout <<"\t\tEsta cruzando:"<< actorCruza << endl;
            navegar();
        }
            
    }

    return 0;
     
}
