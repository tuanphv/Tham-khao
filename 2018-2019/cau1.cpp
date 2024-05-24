#include <iostream>
using namespace std;
int X(int n)
{
    int *x = new int[n];
    x[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        x[i] = 0;
        for (int j = 1; j < i; j++)
            x[i] += x[j];
        x[i] *= i;
    }
    for (int i = 1; i <= n; i++)
        cout << x[i] << ' ';
    return x[n];
}
int main()
{
    X(7);
    return 0;
}