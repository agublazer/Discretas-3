#include"cifrado_afin.h"
#include"rsa.h"
int main()
{
    string m="Fredy Alvarez Bejar 151-10-34749",n,q;
    afin a;
    n=a.cifrar(m);
    cout<<n<<endl;
    q=a.descifrar(n);
    cout<<q<<endl;

    rsa b(11,17);
    rsa c(17,19);
    int o = 60,s,t;
    s=b.cifrar(o,c);
    cout<<s<<endl;
    t = c.descifrar(s);
    cout<<t<<endl;

}
