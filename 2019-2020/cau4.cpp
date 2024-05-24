#include <iostream>
#include <fstream>
using namespace std;
FILE *fi = fopen("INPUT.TXT", "r");
FILE *fo = fopen("OUTPUT.TXT", "w");
void Nhap(int *&a, int &n)
{
    fscanf(fi, "%d", &n);
    a = new int[n];
    for (int i = 0; i < n; i++)
        fscanf(fi, "%d", a + i);
}
int snt(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}
void cau_a(int *a, int n)
{
    int count_prime = 0;
    for (int i = 0; i < n; i++)
        if (snt(a[i]))
            count_prime++;
    fprintf(fo, "%d\n", count_prime);
}
void cau_b(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
    for (int i = 0; i < n; i++)
        fprintf(fo, "%d ", a[i]);
}
int main()
{
    int *a, n;
    Nhap(a, n);
    cau_a(a, n);
    cau_b(a, n);
    fclose(fi);
    fclose(fo);
    delete[] a;
    return 0;
}