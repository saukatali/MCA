#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char infix[50], postfix[50], s[50], ch;
    int top = -1, len, i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    len = strlen(infix);
    s[++top] = '#';   // stack bottom marker

    for (i = 0; i < len; i++)
    {
        ch = infix[i];

        if (isalnum(ch))     // operand
        {
            postfix[j++] = ch;
        }
        else if (ch == '^')
        {
            for (; s[top] == '^'; top--)
                postfix[j++] = s[top];
            s[++top] = ch;
        }
        else if (ch == '*' || ch == '/')
        {
            for (; s[top] == '^' || s[top] == '*' || s[top] == '/'; top--)
                postfix[j++] = s[top];
            s[++top] = ch;
        }
        else if (ch == '+' || ch == '-')
        {
            for (; s[top] == '^' || s[top] == '*' || s[top] == '/' ||
                   s[top] == '+' || s[top] == '-'; top--)
                postfix[j++] = s[top];
            s[++top] = ch;
        }
        else if (ch == '(')
        {
            s[++top] = ch;
        }
        else if (ch == ')')
        {
            for (; s[top] != '('; top--)
                postfix[j++] = s[top];
            top--;   // remove '('
        }
    }

    for (; s[top] != '#'; top--)
        postfix[j++] = s[top];

    postfix[j] = '\0';

    printf("Postfix expression = %s\n", postfix);

    return 0;
}
