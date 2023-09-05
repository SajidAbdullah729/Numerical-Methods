#include<bits/stdc++.h>
using namespace std;
int main()
{
    float n, valueOfX, valueOfY, x, sum=0;
    vector<float> xValues;
    vector<float> yValues;
    cout << "Linear Regression\n";
    cout << "-----------------\n";
    cout << "ENTER TOTAL NO. OF INPUTS: ";
    cin >> n;
    for(int k=0; k<n; k++)
    {
        float temp;
        cout << "Y" << k+1 << " = ";
        cin >> temp;
        xValues.push_back(temp);
        cout << "G" << k+1 << " = ";
        cin >> temp;
        yValues.push_back(temp);
        cout << endl;
    }
    float sumX = 0;
    float sumX2 = 0;
    float sumY = 0;
    float sumXY = 0;
    for(int i=0; i<n; i++)
    {
        sumX += xValues[i];
        sumX2 += xValues[i] * xValues[i];
        sumY += yValues[i];
        sumXY += xValues[i] * yValues[i];
    }
    float b = (n *sumXY - sumX * sumY) / (n *sumX2 - sumX * sumX);
    float a = (sumY - b * sumX) / n;
    cout << "y = " << a << " + " << b << "x\n";

    cout << "\nTo calculate G, Enter value of Y: ";
    cin >> x;

    cout << "\nFor X = " << x <<" the value of Y: " << (a+b*x) << "\n";
    for(int i=0; i<n; i++)
    {
        sum += pow(yValues[i] - (a+b*xValues[i]), 2);
    }
    cout << "\nMean Square Error: " << (sum/n)*100 << "%";
    cout << endl;
    return 0;
}

/*
5
0 0
30000 9.8100
60000 9.7487
90000 9.6879
120000 9.5682
55000

*/
