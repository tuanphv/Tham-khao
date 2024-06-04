#include <iostream>
#include <fstream>
using namespace std;
FILE *fi = fopen("num_input.txt", "r");
FILE *fo = fopen("num_output.txt", "w");
void read_File(int &n, int *&a)
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

void cau_a(int n, int *a)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (snt(a[i]))
            count++;
    fprintf(fo, "%d\n", count);
}
void cau_b(int n, int *a)
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
    int n, *a;
    read_File(n, a);
    cau_a(n, a);
    cau_b(n, a);
    fclose(fi);
    fclose(fo);
    delete[] a;
    return 0;
}