#include<iostream>
#include<string>
using namespace std;

class vallas{
private:
    int clave;
public:
    vallas(int c)
    {
        clave=c;
    }

    string cifrar(string &msj1)
    {
        while(msj1.size()<clave)
        {
            msj1+="w";
        }
        int n = clave;
        while(msj1.size()>n)
        {
            n+=(clave-2)+clave;
        }
        n-=msj1.size();
        for(int i=0;i<n;i++)
        {
            msj1+="w";
        }

        string msj2 = msj1;

        int salida=0;
        int entrada=0;
        int cons1 = 2*(clave-1);
        int cons2 = 0;
        for(int i=0;i<clave;i++)
        {
            entrada=i;
            while(entrada<=msj1.size())
            {
                if (cons1>0)
                {
                    if (entrada<msj1.size())
                    {
                        msj2[salida]=msj1[entrada];
                        salida++;
                    }
                    entrada+=cons1;
                }
                if (cons2>0)
                {
                    if(entrada<msj2.size())
                    {
                        msj2[salida]=msj1[entrada];
                        salida++;
                    }
                    entrada+=cons2;
                }
            }
            cons1-=2;
            cons2+=2;
        }
        return msj2;
    }
    string descifrar(string &msj1)
    {
        string msj2 = msj1;

        int salida=0;
        int entrada=0;
        int cons1 = 2*(clave-1);
        int cons2 = 0;
        for(int i=0;i<clave;i++)
        {
            entrada=i;
            while(entrada<=msj1.size())
            {
                if (cons1>0)
                {
                    if (entrada<msj1.size())
                    {
                        msj2[entrada]=msj1[salida];
                        salida++;
                    }
                    entrada+=cons1;
                }
                if (cons2>0)
                {
                    if(entrada<msj2.size())
                    {
                        msj2[entrada]=msj1[salida];
                        salida++;
                    }
                    entrada+=cons2;
                }
            }
            cons1-=2;
            cons2+=2;
        }
        int x=msj2.size()-1;

        while(msj2[x]=='w')
        {
            msj2.pop_back();
            x--;
        }
        return msj2;
    }
};

