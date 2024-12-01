#include<stdio.h>
#define SIZE 5
struct BOOK
{
  int ISBN;
  char author[20];
  char title[20];
  float price;
};

struct stack
{
  struct BOOK b[SIZE];
  int top;
};

void push(struct stack *ps,struct BOOK b);
struct BOOK pop(struct stack*ps);
void display(struct stack*ps);

int main()
{
  struct stack s;
  struct BOOK b1,r1;
  s.top=-1;
  int choice;
  while(1)
  {
    printf("1->PUSH     2->POP    3->DISPLAY    4->EXIT\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
          printf("Enter the ISBN-author-title-price details of the book: \n");
          scanf("%d %s %s %f",&b1.ISBN,b1.author,b1.title,&b1.price);
          push(&s,b1);
          break;
      
      case 2:
          r1=pop(&s);
          if(r1.ISBN!=-1)
          {
            printf("The details of the book popped are: \n");
            printf("%d %s %s %.2f\n",r1.ISBN,r1.author,r1.title,r1.price);
          }
          else
          {
            printf("STACK UNDERFLOW CANNOT POP FROM EMPTY STACK!!!\n");
          }
          break;

      case 3:
          display(&s);
          break;
      case 4:
          return 0;
    }
  }
}

void push(struct stack *ps,struct BOOK b)
{
  if(ps->top==SIZE-1)
  {
    printf("STACK OVERFLOW!!!\n");
  }
  else
  {
    (ps->top)++;
    ps->b[ps->top]=b;
  }
}

struct BOOK pop(struct stack *ps)
{
  struct BOOK r;
  if(ps->top==-1)
  {
    r.ISBN=-1;
    return r;
  }
  else
  {
    r=ps->b[ps->top];
    (ps->top)--;
    return r;
  }
}

void display(struct stack *ps)
{
  for(int i=ps->top;i>=0;i--)
  {
    printf("%d %s %s %.2f\n",ps->b[i].ISBN,ps->b[i].author,ps->b[i].title,ps->b[i].price);
  }
}