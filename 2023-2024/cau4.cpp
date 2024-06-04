#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
FILE *fi = fopen("str_input.txt", "r");
FILE *fo = fopen("str_output.txt", "w");
int main()
{
    int max_len = 0;
    char tmp[512];
    char s[512];
    while (fgets(s, 512, fi))
    {
        if (s[strlen(s) - 1] == '\n')
            s[strlen(s) - 1] = '\0';
        if (strlen(s) > max_len)
        {
            max_len = strlen(s);
            strcpy(tmp, s);
        }
        fprintf(fo, "%s\n", strrchr(s, ' ') + 1);
    }
    fputs(tmp, fo);
    fclose(fi);
    fclose(fo);
    return 0;
}