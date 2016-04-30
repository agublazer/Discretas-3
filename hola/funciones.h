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
int mod_inv(int a, int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1)
        return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0)
        x1 += b0;
	return x1;
}


int exp_mod(int a,int exp, int n)
{
    int result = 1;
    while(exp>0)
    {
        if (mod(exp,2)==1)
            result = mod(result*a,n);

        a = mod(a*a,n);
        exp = exp/2;
    }
    return result;
}
#endif // FUNCIONES_H_INCLUDED
