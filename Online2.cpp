#include<bits/stdc++.h>
#define eps 0.00000001
using namespace std;
int coef[4];
int maxp=3;
float maxroot(float a,float b)
{
    return (-b/a);
}
float hornermethod(float x0)
{
    float fx1=0;
    for(int i=maxp; i>=1; i--) fx1+=coef[i] * (pow(x0,i)) ;
    fx1+=coef[0];
    return fx1;
}

float fx(float x0)
{
    return hornermethod(x0);
}
int main()
{
    float x1,x2,x3;
    int iter=1;
    coef[3]=1;
    coef[2]=2;
    coef[1]=10;
    coef[0]=-20;
    cout <<"first guess : ";
    cin >>x2;
    x1=maxroot(coef[0],coef[1]);
    cout<<"iteration approx root absolute error"<<endl;
    while(1)
    {

        x3 = x2-((fx(x2)*(x2-x1))/(fx(x2)- fx(x1)));

        if(fabs((x3-x2)/x3)<= eps) break;
        else
        {
            cout <<" "<<iter++<<" "<<x3<<" "<<fabs((x3-x2))/x2<<endl;
            x1 = x2;
            x2 = x3;
        }
    }
    cout <<"The root is :" <<x3<<endl;

    return 0;
}
