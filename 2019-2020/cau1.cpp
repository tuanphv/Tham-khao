#include <iostream>
using namespace std;
int cau_a(int n)
{
    if (n == 1)
        return 1;
    int Xn = n;
    for (int i = 1; i < n; i++)
        Xn += cau_a(i);
    return Xn;
}
int cau_b(int n)
{
    int *a = new int[n + 1];
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = i;
        for (int j = 1; j < i; j++)
            a[i] += a[j];
    }
    int Xn = a[n];
    delete[] a;
    return Xn;
}
int main()
{
    for (int i = 1; i <= 10; i++)
        cout << cau_a(i) << ' ';
    cout << '\n';
    for (int i = 1; i <= 10; i++)
        cout << cau_b(i) << ' ';
    return 0;
}