#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MaxSize 100
typedef int DataType;
typedef struct
{
    DataType data[MaxSize];
    int top;
} Stack;
void InitStack(Stack *S)
{
    S->top = -1;
}
int EmptyStack(Stack *S)
{
    if (S->top == -1)
       return 1;
    else
       return 0;   
}
int Push (Stack *S, DataType x)
{
    if (S->top == MaxSize - 1)
    {
        printf("\n ջ�������޷���ջ��");
        return 0;
    }
    S->top++;
    S->data[S->top] = x;
    return 1;
}
DataType Pop(Stack *S)
{
    DataType x;
    if (EmptyStack(S))
    {
        printf("\n ջ�գ��޷���ջ");
        exit(1);
    }
    x = S->data[S->top];
    S->top--;
    return x;
}
void DectoOthers(int n, int b)
{
    char B[] = "0123456789ABCDEF";
    int x;
    Stack st;
    InitStack(&st);
    while (n)
    {
        Push(&st, n % b);
        n = n / b;
    }
    while (!EmptyStack(&st))
    {
        x = Pop(&st);
        printf("%c", B[x]);
    }
}
int main()
{
    Stack S;
    int n;
    InitStack(&S);
    printf("������һ��ʮ��������");
    scanf("%d", &n);
    printf("��ʮ������ %d ת��Ϊ���������Ľ��Ϊ��", n);
    DectoOthers(n, 2);
    printf("B\n��ʮ������ %d ת��Ϊ�˽������Ľ��Ϊ��", n);
    DectoOthers(n, 8);
    printf("O\n��ʮ������ %d ת��Ϊʮ���������Ľ��Ϊ��", n);
    DectoOthers(n, 16);
    printf("H\n");
    return 0;
} 