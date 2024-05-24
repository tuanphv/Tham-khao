#include <iostream>
#include <fstream>

using namespace std;
FILE *fi = fopen("songuyen.inp", "r");
FILE *fo = fopen("ketqua.out", "w");
void cau_a(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] < a[j])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
    int max1 = a[0], max2;
    int i = 1;
    while (max1 == a[i])
        i++;
    max2 = a[i];
    fprintf(fo, "%d %d\n", max1, max2);
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
void cau_b(int *a, int n)
{
    int d = 0;
    for (int i = 0; i < n; i++)
    {
        int x = 1, check = 0;
        if (!snt(a[i]))
            continue;
        while (check == 0)
        {
            if (snt(a[i] - x))
                check++;
            if (snt(a[i] + x))
                check++;
            x++;
        }
        if (check == 2)
            d++;
    }
    fprintf(fo, "%d", d);
}
int main()
{

    int n;
    fscanf(fi, "%d", &n);
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        fscanf(fi, "%d", a + i);
    cau_a(a, n);
    cau_b(a, n);
    delete[] a;
    fclose(fi);
    fclose(fo);
    return 0;
}