#include<stdio.h>
#include<math.h>
#include<ctype.h>

float stack[20];
int top=-1;

void push(float ele)
{
  top++;
  stack[top]=ele;
}

float pop()
{
  float popped=stack[top];
  top--;
  return popped;
}

float eval(char postfix[])
{
  int i=0;
  float op1,op2,res;
  while(postfix[i]!='\0')
  {
    char ch=postfix[i];
    if(isdigit(ch))
    {
      push(ch-'0');
    }
    else
    {
      op2=pop();
      op1=pop();
      switch(ch)
      {
        case '+':
            res=op1+op2;
            break;
        case '-':
            res=op1-op2;
            break;
        case '*':
            res=op1*op2;
            break;
        case '/':
            res=op1/op2;
            break;
        case '^':
        case '$':
            res=pow(op1,op2);
            break;
      }
      push(res);
    }
    i++;
  }
  return pop();
}

int main()
{
  char postfix[20];
  printf("Enter the postfix expression: \n");
  scanf("%s",postfix);
  float res =eval(postfix);
  printf("The result is: %.2f\n",res);
  return 0;
}