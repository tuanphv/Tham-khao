#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[] = "ChatGPT provides excellent support for research as well as many other tasks";
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