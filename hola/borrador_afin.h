#include"cifrado_afin.h"

int main()
{
    afin hola;
    hola.generar_clave();
    string m = "holaquetal";
    string g,y;
    cout<<hola.get_claveA()<<" "<<hola.get_claveB()<<endl;
    g = hola.cifrar(m);
    cout<<g<<endl;
    afin fredy(hola.get_claveA(), hola.get_claveB());
    y = fredy.descifrar(g);
    cout<<y<<endl;


}
