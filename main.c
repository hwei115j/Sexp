#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define SPAC(A) do{printf("\n");for(int _i = 0; _i < A; _i++) printf(" ");}while(0)

enum {
    Word = 100, Lparen, Rparen, Key_word, expr
};
static char str[1000];
static int __nn = 0;

static void node();
static void read_word()
{
    int ch, i = 0;

    while(!isspace((ch = getchar())) && ch != '(' && ch != ')')
        str[i++] = ch;
    ungetc(ch, stdin);
    str[i] = '\0';
}

static int gettoken()
{
    int ch;

    while((ch = getchar()) != '\n' && isspace(ch));
    while(ch == '\n' || ch == ' ')
        ch = getchar();
    if(__nn) {
        ungetc(ch, stdin);
        switch(ch) {
        case ')':
            return Rparen;
        case '(':
            return Lparen;
        default:
            return -1;
        }
    }
    switch(ch) {
    case 'A' ... 'Z':
        ungetc(ch, stdin);
        read_word();
        return Key_word;
    case '+':
    case '-':
    case '*':
    case '/':
    case '&':
    case '|':
    case '=':
    case '!':
    case '>':
    case '<':
        ungetc(ch, stdin);
        read_word();
        return expr;
    case '(':
        return Lparen;
        break;
    case ')':
        return Rparen;
        break;
    case EOF:
        exit(0);
        break;
    default:
        ungetc(ch, stdin);
        read_word();
        return Word;
    }
}

static int peek_token()
{
    int reg;
    __nn = 1;
    reg = gettoken();
    __nn = 0;
    return reg;
}

static void node(int space, int flag)
{
    int tok = gettoken();

    while(tok != Rparen) {
        if(tok == Lparen) {
            printf("(");
            node(space, 0);
            if(flag && peek_token() != Rparen){ SPAC(space-1);}
        } 
        else if(tok == Key_word) {
            space += printf("%s", str) + 2;
            if(flag && peek_token() != Rparen){ SPAC(space-1);}
            flag = 1;
        } 
        else if(tok == expr) {
            printf("%s", str);
            flag = 0;
        } 
        else if(tok == Word) {
            printf("%s", str);
            if(flag && peek_token() != Rparen){ SPAC(space-1);}
        }
        if(peek_token() != Rparen)
            printf(" ");
        tok = gettoken();
    }
    printf(")");
}
int main() 
{
    int tok = gettoken();
    printf("(");

    while(tok != Rparen) {
        node(0, 0);
        printf("\n");
    }
}
