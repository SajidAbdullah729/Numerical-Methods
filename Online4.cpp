#include<bits/stdc++.h>
using namespace std;
float Matrix[10][10];
void gaussElimination(int N)
{
    float temp, s;
    float x[N];
    int i, j, k;
    for (j = 0; j < N - 1; j++)
    {
        for (i = j + 1; i < N; i++)
        {
            temp = Matrix[i][j] / Matrix[j][j];
            for (k = 0; k < N + 1; k++)
                Matrix[i][k] -= Matrix[j][k] * temp;
        }
    }
    for (i = N - 1; i >= 0; i--)
    {
        s = 0;
        for (j = i + 1; j < N; j++)
            s += Matrix[i][j] * x[j];
        x[i] = (Matrix[i][N] - s) / Matrix[i][i];
    }
    cout << "\nThe solution of linear equations is:\n";
    for (i = 0; i < N; i++)
        cout << "x[" << i + 1 << "]: " << x[i] << endl;
}
int main()
{
    cout<<"Enter order: ";
    int val;
    cin>>val;
    for(int i=0; i<val; i++)
    {
        for(int j=0; j<=val; j++)
        {
            cin>>Matrix[i][j];
        }
    }
    gaussElimination(val);
    return 0;
}
