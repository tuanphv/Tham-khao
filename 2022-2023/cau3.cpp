#include <iostream>
#include <fstream>
using namespace std;

// Mở file
FILE *fi = fopen("table.txt", "r");
FILE *fo = fopen("table_result.txt", "w");

void sum_row(int **a, int n, int *&b)
{
    b = new int[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = 0;
        for (int j = 0; j < n; j++)
            b[i] += a[i][j];
        fprintf(fo, "%d ", b[i]);
    }
}

int mang_Doi_xung(int **a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (a[i][j] != a[j][i])
                return 0;
    return 1;
}

void sap_xep(int n, int *b)
{
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < n; j++)
            if (b[j] == i)
                fprintf(fo, "%d ", j + 1);
}
int main()
{
    // Nhập dữ liệu
    int n;
    fscanf(fi, "%d", &n);
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
            fscanf(fi, "%d", &a[i][j]);
    }

    // Câu a
    int *b;
    sum_row(a, n, b);

    // Câu b
    fprintf(fo, "\n%d\n", mang_Doi_xung(a, n));

    // Câu c
    sap_xep(n, b);

    // Xoá bộ nhớ mảng động
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    // Đóng file
    fclose(fi);
    fclose(fo);
    return 0;
}