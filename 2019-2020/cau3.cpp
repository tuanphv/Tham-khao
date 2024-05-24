#include <iostream>
#include <string.h>
using namespace std;

void cau_a(char *s)
{
    char str[256];
    strcpy(str, s);
    char *token = strtok(str, " ");
    while (token)
    {
        cout << strlen(token) << ' ';
        token = strtok(NULL, " ");
    }
    cout << '\n';
}
void cau_b(char *s)
{
    char str[256];
    strcpy(str, s);
    char *token = strtok(str, " ");
    int max = 0;
    char *tmp;
    while (token)
    {
        if (strlen(token) > max)
        {
            max = strlen(token);
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
    return 0;
}