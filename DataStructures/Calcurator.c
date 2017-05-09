//
//  Calcurator.c
//  DataStructures
//
//  Created by JoYongJin on 2016. 11. 5..
//  Copyright © 2016년 JoYongJin. All rights reserved.
//


#include "ListBaseStack.h"
#include "Calcurator.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int GetOpPrec(char op) //연산자의 순위 반환
{
    switch (op) {
        case '*':
        case '/':
            return 5;
        case '+':
        case '-':
            return 3;
        case '(':
            return 1;
    }
    return -1;
}

int WhoPrecOp(char op1, char op2) //반환된 순위 반환
{
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);
    
    if(op1Prec > op2Prec)
        return 1;
    else if(op1Prec < op2Prec)
        return -1;
    else
        return 0;
}

void ConvToRPENxp(char exp[])
{
    Stack stack;
    int expLen = strlen(exp);
    char * convExp = (char*)malloc(expLen+1); //수식 저장 공간
    
    int i, idx=0; //for문용 i와 개수를 세는 인덱스 변수
    char tok, popOp; //
    
    memset(convExp, 0, sizeof(char)*expLen+1);
    StackInit(&stack);
    
    for(i=0; i<expLen; i++)
    {
        tok = exp[i];
        if(isdigit(tok))
        {
            convExp[idx++] = tok;
        }
        else
        {
            switch (tok) {
                case '(':
                    SPush(&stack, tok);
                    break;
                case ')':
                    while (1){
                        popOp = SPop(&stack);
                        if(popOp == '(')
                            break;
                        convExp[idx++] =popOp;
                    }
                    break;
                case '+': case '-': case '*': case '/':
                    while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok)>=0)
                      convExp[idx++]=SPop(&stack);
                    SPush(&stack, tok);
                    break;
            }
        }
            
    }
    
    while(!SIsEmpty(&stack)) //스택에 남아 있는 모든 '연산자'를 이동
        convExp[idx++] = SPop(&stack);
    
    strcpy(exp, convExp);
    free(convExp);
}

int EvalRPNExp(char exp[])
{
    int length = (int)strlen(exp);
    int tok;
    Stack stac;
    StackInit(&stac);
    for(int i=0; i<length; i++)
    {
        tok = exp[i];
        
        if(isdigit(tok))
        {
            SPush(&stac, tok-'0');
        }
        else
        {
            int b = SPop(&stac);
            int a = SPop(&stac);
            
            switch (tok) {
                case '+':
                    SPush(&stac, a+b);
                    break;
                case '-':
                    SPush(&stac, a-b);
                    break;
                case '*':
                    SPush(&stac, a*b);
                    break;
                case '/':
                    SPush(&stac, a/b);
                    break;
            }
        }

    }
    return SPop(&stac);
}

int Calculator (char exp[])
{
    int len = (int)strlen(exp);
    int result;
    char * temp = (char*)malloc(len+1);
    strcpy(temp, exp);
    
    ConvToRPENxp(temp);
    result = EvalRPNExp(temp);
    free(temp);
    
    return result;
    
}



int main()
{
    char exp1[] = "1+2+3";
    char exp2[] = "(1+2)+3";
    char exp3[] = "((1+2)+3)*(5-2)";
    
    ConvToRPENxp(exp1);
    ConvToRPENxp(exp2);
    ConvToRPENxp(exp3);
    
    printf("%s \n", exp1);
    printf("%s \n", exp2);
    printf("%s \n", exp3);
    
    printf("%d \n", EvalRPNExp(exp1));
    printf("%d \n", EvalRPNExp(exp2));
    printf("%d \n", EvalRPNExp(exp3));
    
    printf("%d \n", EvalRPNExp("42*8+"));
    
    printf("%d \n", Calculator("(((1+3)*2)+5)*9/4"));
    return 0;
}
