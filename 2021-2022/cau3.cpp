#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
void Nhap(int **&a, int &m, int &n)
{
    FILE *fi = fopen("table.inp", "r");
    fscanf(fi, "%d%d", &m, &n);
    a = new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
            fscanf(fi, "%d", a[i] + j);
    }
    fclose(fi);
}
void cau_a(int **a, int m, int n)
{
    FILE *fo = fopen("square_file.txt", "w");
    int count = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (sqrt(a[i][j]) == int(sqrt(a[i][j])))
                count++;
    fprintf(fo, "%d\n", count);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (sqrt(a[i][j]) == int(sqrt(a[i][j])))
                fprintf(fo, "%d %d %d\n", a[i][j], i + 1, j + 1);

    fclose(fo);
}
void cau_b(int **a, int m, int n)
{
    FILE *fo = fopen("oddeven_file.txt", "w");
    int odd = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] % 2)
                odd++;
    fprintf(fo, "%d\n", odd);
    int d = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] % 2)
            {
                d++;
                fprintf(fo, "%d ", a[i][j]);
                if (d % 11 == 0)
                    fprintf(fo, "\n");
            }
    fprintf(fo, "\n%d\n", m * n - odd);
    d = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] % 2 == 0)
            {
                d++;
                fprintf(fo, "%d ", a[i][j]);
                if (d % 11 == 0)
                    fprintf(fo, "\n");
            }
    fclose(fo);
}
void cau_c(int **a, int m, int n)
{
    FILE *fo = fopen("sort_file.txt", "w");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m - 1; j++)
            for (int k = j + 1; k < m; k++)
                if (a[j][i] > a[k][i])
                {
                    int tmp = a[j][i];
                    a[j][i] = a[k][i];
                    a[k][i] = tmp;
                }
    fprintf(fo, "%d %d\n", m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            fprintf(fo, "%d ", a[i][j]);
        fprintf(fo, "\n");
    }
    fclose(fo);
}
int main()
{
    int **a, m, n;
    Nhap(a, m, n);
    cau_a(a, m, n);
    cau_b(a, m, n);
    cau_c(a, m, n);
    for (int i = 0; i < m; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}