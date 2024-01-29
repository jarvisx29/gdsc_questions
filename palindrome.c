#include <stdio.h>
#include <string.h>

int isPal(char w[]) {
    int len = strlen(w);

    for (int i = 0; i < len / 2; i++) {
        if (w[i] != w[len - i - 1]) {
            return 0;
        }
    }

    return 1;
}

void makePal(char s[]) {
    char delim[] = " ";
    char *tok = strtok(s, delim);

    while (tok != NULL) {
        if (!isPal(tok)) {
            char rev[100];
            int len = strlen(tok);

            for (int i = 0; i < len; i++) {
                rev[i] = tok[len - i - 1];
            }
            rev[len] = '\0';

            strcat(tok, rev);
        }

        printf("%s ", tok);

        tok = strtok(NULL, delim);
    }
}

int main() {
    char inp[500];

    printf("Enter a sentence: ");
    fgets(inp, sizeof(inp), stdin);

    printf("Modified sentence: ");
    makePal(inp);

    return 0;
}
