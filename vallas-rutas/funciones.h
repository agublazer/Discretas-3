#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include<iostream>
#include<string>
using namespace std;

int mod(int a, int b)
{
    int q,r;
    q = a/b;
    r = a-(q*b);
    if (r<0)
        return r+b;
    return r;
}

int mcd(int a, int b)
{
    int r1,r2,c;
    c = a/b;
    r1 = a-(b*c);

    if (r1 == 0)
        return b;

    while(r1>0)
    {
        a = b;
        b = r1;
        r2 = r1;

        c = a/b;
        r1 = a - (b*c);
    }
    return r2;
}

void euclides_ext(int a, int b, int &fin1,int &fin2)
{
    int q,x,x_1,y,y_1,t;

    if (a == 0)
    {
        fin1 = 1;
        fin2 = 0;
    }

    if (b > a)
    {
        t = a;
        a = b;
        b = t;
    }

    x = 0;
    y = 1;
    x_1 = 1;
    y_1 = 0;

    while (b != 0)
    {
        q = a/b;
        t = mod(a,b);
        a = b;
        b = t;


        t = x;
        x = x_1 - q*x;
        x_1 = t;

        t = y;
        y = y_1 - q*y;
        y_1 = t;

    }
    fin1=x_1;
    fin2=y_1;
}

#endif // FUNCIONES_H_INCLUDED
