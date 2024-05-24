#include <iostream>
using namespace std;
double cau_a(int n)
{
    if (n == 0)
        return 1;
    return 0.5 * cau_a(n - 1);
}
double cau_b(int n)
{
    double a = 1;
    for (int i = 1; i <= n; i++)
        a *= 0.5;
    return a;
}
double cau_c(int n)
{
    double a = 1, S = 0;
    for (int i = 0; i <= n; i++)
    {
        S += a;
        a *= 0.5;
    }
    return S;
}
int main()
{
    int n;
    cin >> n;
    cout << cau_c(n);
    return 0;
}