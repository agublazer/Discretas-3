int mcd(int a, int b, int &u, int &v, int &x, int &y, int &A, int &B, int &C, int &D)
{
    while (u%2 == 0)
    {
        u = u/2;
        if (A == B and B == 0)
        {
            A = A/2;
            B = B/2;
        }
        else
        {
            A = (A+b)/2;
            B = (B-a)/2;
        }
    }
    while (v%2 == 0)
    {
        v = v/2;
        if (C == D and D == 0)
        {
            C = C/2;
            D = D/2;
        }
        else
        {
            C = (C+b)/2;
            D = (D-a)/2;
        }
    }
    if (u>=v)
    {
        u = u-v;
        A = A-C;
        B = B-D;
    }
    else
    {
        v = v-u;
        C = C-A;
        D = D-B;
    }
    if (u==0)
    {
        x = C;
        y = D;
        return 0;
    }
    else
        return mcd(a,b,u,v,x,y,A,B,C,D);

}


int main()
{
    int x, y;
    int A = 1, B = 0, C = 0, D = 1;
    int a = 103, b = 15;
    int u = 103, v = 15;
    mcd(a,b,u,v,x,y,A,B,C,D);
    cout<<x<<" "<<y<<endl;
    return 0;
}
