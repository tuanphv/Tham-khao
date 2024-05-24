#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
int main()
{
    FILE *fi = fopen("str.txt", "r");
    FILE *fo = fopen("str_result.txt", "w");
    char s[512];
    while (fgets(s, 512, fi))
    {
        fputs(strtok(s, " "), fo);
        fprintf(fo, "\n");
    }
    fclose(fi);
    fclose(fo);
    return 0;
}