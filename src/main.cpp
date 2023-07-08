#include "iostream"
#include "../lib/rrColor.h"
#include "../lib/rrUtility.h"

using namespace std;

int main()
{
    rrSetTextColor(textColorMagenta);
    rrMostrarDatos();

    rrSetTextColor(textColorGreen);

    if( rrLoginUsuario() )
    {

        rrSetTextColor(textColorBlue);
        while (rrMenu())
        {

            cout <<"\t\tEsta cruzando:"<< rrActorCruza << endl <<endl;
            rrNumViajes++;
            rrNavegar();
        }
            
    }

    return 0;
     
}
