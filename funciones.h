#include<iostream>
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
