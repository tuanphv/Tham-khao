#include <iostream>
#include <string.h>
using namespace std;
void cau_a(char *s)
{
    int n_am = 0, p_am = 0;
    for (int i = 0; i < strlen(s); i++)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            n_am++;
        else if (s[i] != ' ')
            p_am++;
    cout << n_am << ' ' << p_am << '\n';
}
int cau_b(char *s)
{
    int so_tu = 1;
    for (int i = 0; i < strlen(s); i++)
        if (s[i] == 32)
            so_tu++;
    return so_tu;
}
void cau_c(char *s)
{
    int n = cau_b(s);
    char **str = new char *[n];
    int d = 0;
    str[d++] = strtok(s, " ");
    while (d < n)
    {
        str[d++] = strtok(NULL, " ");
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(str[i], str[j]) == 1)
            {
                char *tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
    for (int i = 0; i < n; i++)
        cout << str[i] << ' ';
}
int main()
{
    char s[256];
    gets(s);
    cau_a(s);
    cout << cau_b(s) << '\n';
    cau_c(s);
    return 0;
}