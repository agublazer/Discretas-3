#ifndef CIFRADO_AFIN_H_INCLUDED
#define CIFRADO_AFIN_H_INCLUDED

#include<time.h>
#include<stdlib.h>

#include"funciones.h"

class afin
{
private:
    int clave_a;
    int clave_b;
public:
    string alfabeto;
    int tamano_alfabeto;
    afin()
    {
        srand(time(NULL));
        clave_b = rand()%5000+1;
        clave_a = 0;
        alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789.,-_";
        tamano_alfabeto = alfabeto.size();
        this->generar_claveA();
    }

    afin(int a)
    {
        clave_a = a;
        srand(time(NULL));
        clave_b = 0;
        alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789.,-_";
        tamano_alfabeto = alfabeto.size();
        this->generar_claveB();
    }

    afin(int a, int b)
    {
        clave_a=a;
        clave_b=b;
        alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789.,-_";
        tamano_alfabeto = alfabeto.size();
    }

    void generar_claveA()
    {
        srand(time(NULL));
        clave_a = rand()%tamano_alfabeto+1;
        int m = mcd(clave_a,clave_b);
        while(m != 1)
        {
            clave_a = rand()%tamano_alfabeto+1;
            m = mcd(clave_a,clave_b);
        }
    }
    void generar_claveB()
    {
        srand(time(NULL));
        clave_b = rand()%5000+1;
        int m = mcd(clave_a,clave_b);
        while(m != 1)
        {
            clave_b = rand()%5000+1;
            m = mcd(clave_a,clave_b);
        }
    }


    string cifrar(string mensaje)
    {
        if (clave_a==0)
            return "clave no generada";

        string salida;
        salida.resize(mensaje.size(),'$');
        int a;
        int b;
        int c = mensaje.size();
        for(int i=0;i<c;i++)
        {
            a = alfabeto.find(mensaje[i]);
            b = (clave_a*a) + clave_b;
            if (a+b >= tamano_alfabeto)
            {
                salida[i]=alfabeto[mod(b,tamano_alfabeto)];
            }
            else
            {
                salida[i]=alfabeto[b];
            }
        }
        return salida;
    }
    string descifrar(string mensaje)
    {
        string salida;
        salida.resize(mensaje.size(),'$');
        int a,b,x,y;
        euclides_ext(clave_a,tamano_alfabeto,x,y);
        if (x<0)
            x =mod(x,tamano_alfabeto);

        int c = mensaje.size();
        for(int i=0;i<c;i++)
        {
            a = alfabeto.find(mensaje[i]);
            b = x*(a-clave_b);
            if (b<0 or b>=tamano_alfabeto)
            {
                salida[i]=alfabeto[mod(b,tamano_alfabeto)];
            }
            else
                salida[i]=alfabeto[b];

        }
        return salida;
    }
    int get_claveA(){return clave_a;}
    int get_claveB(){return clave_b;}
};

#endif // CIFRADO_AFIN_H_INCLUDED
