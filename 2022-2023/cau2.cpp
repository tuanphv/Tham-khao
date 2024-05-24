#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[] = "java was originally developed by james gosling at sun microsystems";
    char *token = strtok(s, " ");
    char *tmp;
    int max = 0;
    cout << "ket qua cau a: ";
    while (token)
    {
        int len = strlen(token);
        cout << len << ' ';
        if (len > max)
        {
            max = len;
            tmp = token;
        }
        token = strtok(NULL, " ");
    }
    cout << "\nket qua cau b: " << tmp;
    return 0;
}