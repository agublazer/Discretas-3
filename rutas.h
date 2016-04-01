#include<iostream>
#include<string>
using namespace std;

void verificar_string(string &frase, int clave)
{
    int a=frase.size();
    if(a%clave !=0)
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
    string cifrar(string msj1)
    {
        int n1=1;
        int n2=1;
        int n3=0;
        string msj2;
        verificar_string(msj1,clave);
        msj2=msj1;
        int x=0;
        int entrada=0;
        int salida=0;
        int c=msj1.size()/clave;
        bool g = true;

        msj2[0]=msj1[0];
        sub1(msj1,msj2,entrada,salida,n1,clave,c,1);
        sub2(msj1,msj2,entrada,salida,n2,clave,1);
        sub3(msj1,msj2,entrada,salida,n1,clave,c,1);
        n2++;
        n1++;

        while(true)
        {
            if (x==0)
            {
                g = (clave-n2)>0;
                if(g==false){return msj2;}
                sub4(msj1,msj2,entrada,salida,n2,clave,1);
                n2++;
                n3=0;
                x=1;
            }
            if (x==1)
            {
                g = (c-n1)>0;
                if(g==false){return msj2;}
                sub1(msj1,msj2,entrada,salida,n1,clave,c,1);
                n1++;
                n3=1;
                x=2;
            }
            if (x==2)
            {
                g = (clave-n2)>0;
                if(g==false){return msj2;}
                sub2(msj1,msj2,entrada,salida,n2,clave,1);
                n2++;
                n3=2;
                x=3;
            }
            if (x==3)
            {
                g = (c-n1)>0;
                if(g==false){return msj2;}
                sub3(msj1,msj2,entrada,salida,n1,clave,c,1);
                n1++;
                n3=3;
                x=0;
            }
        }
        return msj2;
    }

    string d_1(string msj1)
    {
        int n1=1;
        int n2=1;
        string msj2;
        msj2=msj1;
        int x=0;
        int entrada=0;
        int salida=0;
        int c=msj1.size()/clave;
        bool g = true;

        msj2[0]=msj1[0];
        sub1(msj1,msj2,entrada,salida,n1,clave,c,0);
        sub2(msj1,msj2,entrada,salida,n2,clave,0);
        sub3(msj1,msj2,entrada,salida,n1,clave,c,0);
        n2++;
        n1++;
            while(true)
        {
            if (x==0)
            {
                g = (clave-n2)>0;
                if(g==false){return msj2;}
                sub4(msj1,msj2,entrada,salida,n2,clave,0);
                n2++;
                x=1;
            }
            if (x==1)
            {
            g = (c-n1)>0;
                if(g==false){return msj2;}
                sub1(msj1,msj2,entrada,salida,n1,clave,c,0);
                n1++;
                x=2;
            }
            if (x==2)
            {
                g = (clave-n2)>0;
                if(g==false){return msj2;}
                sub2(msj1,msj2,entrada,salida,n2,clave,0);
                n2++;
                x=3;
            }
            if (x==3)
            {
                g = (c-n1)>0;
                if(g==false){return msj2;}
                sub3(msj1,msj2,entrada,salida,n1,clave,c,0);
                n1++;
                x=0;
            }
        }
        return msj2;
    }
    string descifrar(string m)
    {
        string n = d_1(m);
        int x=n.size()-1;
        while(n[x]=='w')
        {
            n.pop_back();
            x--;
        }
        return n;
    }
};
