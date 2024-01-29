#include <stdio.h>

int areBracketsBalanced(char* s) {
    int openingBracketCount = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            openingBracketCount++;
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (openingBracketCount <= 0) {
                return 0;
            }
            openingBracketCount--;
        }
    }

    return openingBracketCount == 0;
}

int main() {
    char expr[] = "{()}[]";

    if (areBracketsBalanced(expr)) {
        printf("The brackets are Balanced\n");
    } else {
        printf("The brackets are not Balanced\n");
    }

    return 0;
}




