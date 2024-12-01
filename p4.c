#include<stdio.h>

int top=-1;
char stack[20],infix[20],postfix[20];

void push(char ch)
{
  top++;
  stack[top]=ch;
}

char pop()
{
  char popped = stack[top];
  top--;
  return popped;
}

void display()
{
  printf("%s",postfix);
}

int pri(char ch)
{
  int p;
  switch(ch)
  {
    case '+':
    case '-':
          p=1;
          break;
    case '*':
    case '/':
          p=2;
          break;
    case '^':
    case '$':
          p=3;
          break;
    case '(':
          p=0;
          break;
    case '#':
          p=-1;
          break;
    default:
          p=-1;
          break;
  }
  return p;
}

void convert()
{
  int i=0,p=0;
  push('#');
  while(infix[i]!='\0')
  {
    char ch=infix[i];
    switch(ch)
    {
      case '(':
            push(ch);
            break;
      case ')':
            while(stack[top]!='(')
            {
              postfix[p]=pop();
              p++;
            }
            pop();
            break;
      case '+':
      case '-':
      case '/':
      case '*':
      case '^':
      case '$':
            while(pri(stack[top])>=pri(ch))
            {
              postfix[p]=pop();
              p++;
            }
            push(ch);
            break;
      default:
          postfix[p]=ch;
          p++;
          break;
    }
    i++;
  }
  while(stack[top]!='#')
  {
    postfix[p]=pop();
    p++;
  }
}

int main()
{
  printf("Enter the infix expression: \n");
  scanf("%s",infix);
  convert();
  printf("The converted postfix expression is: \n");
  display();
  return 0;
}