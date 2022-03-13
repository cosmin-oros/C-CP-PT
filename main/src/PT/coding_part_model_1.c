#include <stdio.h>
#include <ctype.h>

void readAndPrintANFields(){
     int c;
    for (int line = 1; (c = getchar()) != EOF; line++)
    {
        ungetc(c, stdin);

        int fields = 0;
        int isAlpha = 1;
        while ((c = getchar()) != '\n' && c != EOF)
        {
            if (!isalpha(c) && c != ',')
            {
                isAlpha = 0;
            }

            if (isAlpha && c == ',')
            {
                fields++;
            }

            if (!isAlpha && c == ',')
            {
                isAlpha = 1;
            }
        }
        if (isAlpha)
        {
            fields++;
        }
        printf("Line %d has %d alphanumerical fields\n", line, fields);
    }
}

int main(){
    readAndPrintANFields();
    return 0;
}