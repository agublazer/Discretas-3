#include"vallas.h"

int main()
{
    string x="hola que tal";
    vallas a(5);
    string m1 = a.cifrar(x);
    cout<<m1<<endl;
    string m2=a.descifrar(m1);
    cout<<m2<<endl;
}
