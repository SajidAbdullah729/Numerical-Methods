#include<bits/stdc++.h>
using namespace std;
double proterm(int i, double value, double x[])
{
    float pro = 1;
    for (int j = 0; j < i; j++)
    {
        pro = pro * (value - x[j]);
    }
    return pro;
}
void dividedDiffTable(double x[], double y[][10], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = (y[j][i - 1] - y[j + 1]
                       [i - 1]) / (x[j] - x[i + j]);

        }
    }
}
void printDiffTable(double y[][10],int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << setprecision(4) <<
                 y[i][j] << "\t ";

        }
        cout << "\n";
    }
}
double applyFormula(double value, double x[],

                    double y[][10], int n)

{
    double sum = y[0][0];
    for (int i = 1; i < n; i++)
    {
        sum = sum + (proterm(i, value, x) * y[0][i]);
    }
    return sum;
}

double errorre(double funx,double y)
{
    return ((funx-y)*(funx-y));
}
int main()
{
    int n = 5;
    double value[10], sum, y[10][10],ans[10];

    double x[] = { 0, 5, 10, 15,20 };
    y[0][0] = 12.9;
    y[1][0] = 11.3;
    y[2][0] = 10.1;
    y[3][0] = 9.03;
    y[4][0]= 8.17;

    dividedDiffTable(x, y, n);

    for(int i=0; i<=6; i++)
    {
        value[i]=40+(5*i);
        cout << "\nValue at " << value[i] << " is " << applyFormula(value[i], x, y, n) << endl;
//ans[i]=(applyFormula(value[i],x,y,n)-y[0][0]);
    }
    return 0;

}
