#include<stdio.h>
#include<stdlib.h>

int main()
{
  int size,choice,x,pos,key;
  printf("Enter the size of the array: \n");
  scanf("%d",&size);
  int * arr;
  arr=(int*)malloc(size*sizeof(int));

  printf("Enter the elements of the array: \n");
  for(int i=0;i<size;i++)
  {
    printf("*(arr+%d) = ",i);
    scanf("%d",(arr+i));
  }

  while(1)
  {
    printf("1-> INSERT    2->DELETE   3->SEARCH   4->EXIT\n");
    printf("Enter the choice: \n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
          printf("Enter the element which is to be inserted: \n");
          scanf("%d",&x);
          printf("Enter the position: \n");
          scanf("%d",&pos);
          size++;
          for(int i=size-1;i>=pos;i--)
          {
            *(arr+i)=*(arr+i-1);
          }
          *(arr+pos-1)=x;
          printf("Updated array is: \n");
          for(int i=0;i<size;i++)
          {
            printf("*(arr+%d) = %d\n",i,*(arr+i));
          }
          break;

      case 2:
          printf("Enter the position to be deleted: \n");
          scanf("%d",&pos);
          for(int i=pos;i<=size;i++)
          {
            *(arr+i-1)=*(arr+i);
          }
          size--;
          printf("Updated array is: \n");
          for(int i=0;i<size;i++)
          {
            printf("*(arr+%d) = %d\n",i,*(arr+i));
          }
          break;

      case 3:
          printf("Enter the key element to search: \n");
          scanf("%d",&key);
          int found=0;
          for(int i=0;i<size;i++)
          {
            if(*(arr+i)==key)
            {
              printf("%d found at index %d\n",key,i);
              found=1;
              break;
            }
          }
          if(found==0)
          {
            printf("%d not found\n",key);
          }
          break;
      
      case 4:
          exit(1);
    }
  }
}