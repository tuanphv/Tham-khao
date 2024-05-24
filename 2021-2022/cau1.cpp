#include <iostream>
using namespace std;
int cau_a(int a[], int n)
{
    return a[n] += cau_a(a, n);
}
void cau_b(int n, int k)
{
    string s = "";
    char ky_so[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (n > 0)
    {
        s = ky_so[n % k] + s;
        n /= k;
    }
    cout << s;
}
int main()
{
    cau_b(2022, 16);
    return 0;
}