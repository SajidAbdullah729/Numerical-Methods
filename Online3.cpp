#include<bits/stdc++.h>
using namespace std;
#define error 0.001
double a[10];
double b[10];
int n;
int degree;
double fun(double x)
{
    double ans = 0.00;
    for(int i=n; i>=0; i--) ans+=(a[i]*pow(x,i));
    return ans;
}
double der(double x)
{
    double ans=0.00;
    for(int i=n; i>=1; i--)
    {
        ans+=(a[i]*(i*pow(x,i-1)));
    }
    return ans;
}
double maxroot()
{
    return ((-a[0]*1.00)/a[1]);
}
void syntheticdivision(double x)
{
    b[n]=0;
    for(int i=n; i>=0; i--)
    {
        b[i-1]=a[i]+x*b[i];
    }
    for(int i=n-1; i>=0; i--)
    {
        a[i]=b[i];
    }
    n-=1;
}
void newtonraphson(double x)
{
    double x1,e,f1,f2;
    n=degree;
    int rr=0;
//x=x;
    while(n>0)
    {
        int it=0;
        do
        {
            f1=fun(x);
            f2=der(x);
            x1=x-(f1/f2);
            e=fabs((x1-x)/x);
            x=x1;
            it++;
        }

        while(e>error);
//approx root x
        printf("%d %0.6lf\n",rr,x);
        syntheticdivision(x);
        rr++;
    }
//cout<<"total roots: "<<rr<<endl;
}
int main()
{
    cout<<"System is well conditioned"<<endl;
    cout<<"Enter the degree of the equation: ";
    cin>>degree;
    cout<<"Enter the co-efficinet of the equation: ";
    for(int i=degree; i>=0; i--)
    {
        cin>>a[i];
    }
    double xx;
    cout<<"Enter the initial value: ";
    cin>>xx;
//cout<<"largest possible root: "<<xx<<endl;
    cout<<"iteration approx root "<<endl;
    newtonraphson(xx);
    return 0;
}
