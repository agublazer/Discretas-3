#include"cifrado_afin.h"

int main()
{
    afin hola;
    //hola.generar_clave();
    string m = "Fredy Alvarez 151-10-34749";
    string g,y;
    cout<<hola.get_claveA()<<" "<<hola.get_claveB()<<endl;
    g = hola.cifrar(m);
    cout<<g<<endl;
    afin fredy(hola.get_claveA(), hola.get_claveB());
    y = fredy.descifrar(g);
    cout<<y<<endl;

    afin fredy2(hola.get_claveA());
    y = fredy2.descifrar(g);
    cout<<y<<endl;
}
