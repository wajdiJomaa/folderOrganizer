#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *extension(char *filename);
void slash_before_parenthes(char *filename);
void main()
{
    char trim[] = "find . -type f -name \"* *\" -exec bash -c 'mv \"$0\" \"${0// /_}\"' {} \\;";
    system(trim);
    system("ls > systemm");
    system("mkdir no_ext");

    FILE *file = fopen("systemm", "r");
    char filename[150];
    while (fscanf(file, "%s", filename) != EOF)
    {

        char dir[200] = "[ -d '";
        strcat(dir, filename);
        strcat(dir, "' ]");
        if (system(dir))
        {
            slash_before_parenthes(filename);
                char *ext = extension(filename);
                if (ext != NULL)
                {
                    char ls[150] = "ls ";
                    strcat(ls, ext);

                    if (system(ls))
                    {
                        char mkdir[120] = "mkdir ";
                        strcat(mkdir, ext);
                        system(mkdir);
                    }
                    char mv[130] = "mv ";
                    strcat(mv, filename);
                    strcat(mv, " ");
                    strcat(mv, ext);
                    system(mv);
                }
                else if (strcmp(filename, "system") != 0 && strcmp(filename, "systemm") != 0)
                {
                    char mv[130] = "mv ";
                    strcat(mv, filename);
                    strcat(mv, " no_ext");
                    system(mv);
                    printf("%s\n", filename);
                }
        }
    }
    fclose(file);
    system("rm systemm");
}

char *extension(char *filename)
{
    char *dot = strrchr(filename, '.');
    if (!dot || dot == filename)
        return NULL;
    return dot + 1;
}
void slash_before_parenthes(char *filename)
{
    char result[150];
    int j = 0;
    for (int i = 0, n = strlen(filename); i < n; i++)
    {
        if (filename[i] == '(' || filename[i] == ')'|| filename[i]==',')
        {
            result[j++] = '\\';
        }
        result[j++] = filename[i];
    }
    strcpy(filename,result);
    
}
