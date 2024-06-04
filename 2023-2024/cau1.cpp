#include <iostream>
#include <cmath>
using namespace std;

double S_a(int n, double x)
{
    if (n == 1)
        return sqrt(x);
    return sqrt(x + S_a(n - 1, x));
}
double S_b(int n, double x)
{
    double S = 0;
    for (int i = 1; i <= n; i++)
        S = sqrt(x + S);
    return S;
}
int main()
{
    cout << S_a(5, 2);
    return 0;
}
