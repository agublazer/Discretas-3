#include"rutas.h"

int main()
{
    rutas a(4);
    string x="holaquetalctmreabeldemrdoiasdjas";
    string g= a.cifrar(x);
    cout<<g<<endl;
    string y=a.descifrar(g);
    cout<<y<<endl;

}
