#include <iostream>
#include <string.h>
using namespace std;
char kt_dacbiet[] = ",.?!:;";
void cau_a(char *s)
{
    int kytu_trang = 0, kytu_db = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
            kytu_trang++;
        if (strchr(kt_dacbiet, s[i]))
            kytu_db++;
    }
    cout << "Cau a): " << kytu_trang << ' ' << kytu_db << '\n';
}
int dodai_tu(char *s)
{
    int len = 0;
    for (int i = 0; i < strlen(s); i++)
        if (isalpha(s[i]))
            len++;
    s[len] = '\0';
    return len;
}
void cau_b(char *s)
{
    char str[256];
    strcpy(str, s);
    char *token = strtok(str, " ");
    cout << "Cau b): ";
    while (token)
    {
        cout << dodai_tu(token) << ' ';
        token = strtok(NULL, " ");
    }
    cout << '\n';
}
void cau_c(char *s)
{
    char str[256];
    strcpy(str, s);
    char *token = strtok(str, " ");
    char *tmp;
    int max = 0;
    cout << "Cau c): ";
    while (token)
    {
        if (dodai_tu(token) > max)
        {
            max = dodai_tu(token);
            tmp = token;
        }
        token = strtok(NULL, " ");
    }
    cout << tmp;
}
int main()
{
    char s[256];
    gets(s);
    cau_a(s);
    cau_b(s);
    cau_c(s);
    return 0;
}