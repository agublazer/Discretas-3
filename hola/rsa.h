#ifndef RSA_H_INCLUDED
#define RSA_H_INCLUDED
#include "funciones.h"

class rsa{
private:
    int p,q;
    long long clave_publica, clave_privada;
    int n;
    long long nx;
public:
    rsa(int p,int q)
    {
        this->p=p;
        this->q=q;
        n = p*q;
        nx=(p-1)*(q-1);
        this->generar_publica();
        this->generar_privada();

    }
    void generar_publica()
    {
        srand(time(NULL));
        clave_publica= rand()%nx + 1;
        while (mcd(nx,clave_publica)!=1)
        {
            //srand(time(NULL));
            clave_publica= rand()%nx+1;
        }
    }
    void generar_privada()
    {
        clave_privada = mod_inv(clave_publica,nx);
    }
    long cifrar(long m,rsa g)//int m,int k_publica, int n)
    {
        return exp_mod(m,g.clavePublica(),g.getN());
    }
    long descifrar(long m)//int m,int k_publica, int n)
    {
        return exp_mod(m,clave_privada,n);
    }
    int clavePrivada() {return clave_privada;};
    int clavePublica() {return clave_publica;};
    int getN() {return n;}
    int getNX() {return nx;}
};


#endif // RSA_H_INCLUDED

