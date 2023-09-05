#include<bits/stdc++.h>
using namespace std;
double fun(double x)
{
    return x*x*x-x-1;
}
bool methodoffalsepositon(double a,double b)
{
    if(fun(a)*fun(b)>=0) return false;
    double f1,f2,f0;
    double root,prevroot=0.0;
    do
    {
        f1=fun(a);
        f2=fun(b);
        root=(a*f2-b*f1)/(f2-f1);
        f0=fun(root);
        if(f0==0) break;
        if(f0*f1<0)
        {
            b=root;
            f2=f0;
        }
        else
        {
            a=root;
            f1=f0;
        }
        cout<<"root: "<<root<<endl;
        cout<<"Absolute error: "<<abs(prevroot-root)<<endl;
        cout<<"relative error: "<<abs((prevroot-root)/prevroot)<<endl;
        prevroot=root;
    }
    while(abs(f0)>0.000001);
    return true;
}

int main()
{

    int k=methodoffalsepositon(1,2);
    if(!k) cout<<"Wrong choice"<<endl;
    return 0;
}
