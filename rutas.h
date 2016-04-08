#ifndef RUTAS_H_INCLUDED
#define RUTAS_H_INCLUDED
#include"funciones.h"

void verificar_string(string &frase, int clave)
{
    int a=frase.size();
    if(mod(a,clave) !=0)
    {
        int res=a/clave;
        res++;
        int b=res*clave;
        for(int i=0;i<(b-a);i++)
            frase+="w";
    }
}

void sub1(string msj1, string &msj2,int &entrada,int &salida, int n1, int k, int c, int modo)
{
    if (modo==1)
    {
        for(int i=0;i<c-n1;i++)
        {
            salida++;
            entrada+=k;
            msj2[salida]=msj1[entrada];
        }
    }
    else
    {
        for(int i=0;i<c-n1;i++)
        {
            salida++;
            entrada+=k;
            msj2[entrada]=msj1[salida];
        }
    }
}

void sub2(string msj1, string &msj2,int &entrada,int &salida, int n2, int k,int modo)
{
    if(modo==1)
    {
        for(int i=0;i<k-n2;i++)
        {
            salida++;
            entrada++;
            msj2[salida]=msj1[entrada];
        }
    }
    else
    {
        for(int i=0;i<k-n2;i++)
        {
            salida++;
            entrada++;
            msj2[entrada]=msj1[salida];
        }
    }
}

void sub3(string msj1, string &msj2,int &entrada,int &salida, int n1, int k, int c,int modo)
{
    if(modo==1)
    {
        for(int i=0;i<c-n1;i++)
        {
            salida++;
            entrada-=k;
            msj2[salida]=msj1[entrada];
        }
    }
    else
    {
        for(int i=0;i<c-n1;i++)
        {
            salida++;
            entrada-=k;
            msj2[entrada]=msj1[salida];
        }
    }
}

void sub4(string msj1, string &msj2,int &entrada,int &salida, int n2, int k, int modo)
{
    if(modo==1)
    {
        for(int i=0;i<k-n2;i++)
        {
            salida++;
            entrada--;
            msj2[salida]=msj1[entrada];
        }
    }
    else
    {
        for(int i=0;i<k-n2;i++)
        {
            salida++;
            entrada--;
            msj2[entrada]=msj1[salida];
        }
    }
}

class rutas{
private:
    int clave;
public:
    rutas(int c)
    {
        clave=c;
    }
    string op(string msj1, int modo)
    {
        if (modo==1)
            verificar_string(msj1,clave);

        int n1=1;
        int n2=1;
        string msj2;

        msj2=msj1;
        int entrada=0;
        int salida=0;
        int c=msj1.size()/clave;
        
        if (c==1)
            return msj1;
        
        bool g = true;

        msj2[0]=msj1[0];
        sub1(msj1,msj2,entrada,salida,n1,clave,c,modo);
        sub2(msj1,msj2,entrada,salida,n2,clave,modo);
        sub3(msj1,msj2,entrada,salida,n1,clave,c,modo);
        n2++;
        n1++;

        while(g==true)
        {
            g = (clave-n2)>0;
            sub4(msj1,msj2,entrada,salida,n2,clave,modo);
            n2++;

            g = (c-n1)>0;
            sub1(msj1,msj2,entrada,salida,n1,clave,c,modo);
            n1++;

            g = (clave-n2)>0;
            sub2(msj1,msj2,entrada,salida,n2,clave,modo);
            n2++;

            g = (c-n1)>0;
            sub3(msj1,msj2,entrada,salida,n1,clave,c,modo);
            n1++;
        }
        return msj2;
    }
    string cifrar(string &m)
    {
        return op(m,1);
    }
    string descifrar(string m)
    {
        string n = op(m,0);
        int x=n.size()-1;
        while(n[x]=='w')
        {
            n.pop_back();
            x--;
        }
        return n;
    }
};
#endif // RUTAS_H_INCLUDED
