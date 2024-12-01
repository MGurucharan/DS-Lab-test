#include<stdio.h>
#include<stdlib.h>

int main()
{
  int m,n,p,q,choice;
  printf("Enter the order of matrxi 1: \n");
  scanf("%d %d",&m,&n);

  printf("Enter the order of matrxi 2: \n");
  scanf("%d %d",&p,&q);

  int*A[m],*B[p];

  for(int i=0;i<m;i++)
  {
    A[i]=(int*)malloc(n*sizeof(int));
  }

  for(int i=0;i<p;i++)
  {
    B[i]=(int*)malloc(q*sizeof(int));
  }

  printf("Enter the elements of matrix 1: \n");
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      printf("mat1[%d][%d] = ",i,j);
      scanf("%d",A[i]+j);
    }
  }

  printf("Enter the elements of matrix 2: \n");
  for(int i=0;i<p;i++)
  {
    for(int j=0;j<q;j++)
    {
      printf("mat2[%d][%d] = ",i,j);
      scanf("%d",B[i]+j);
    }
  }

  while(1)
  {
    printf("1-> ADD   2->MUL    3->EXIT\n");
    printf("Enter your choice: \n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
          if(m!=p || n!=q)
          {
            printf("SUM NOT POSSIBLE!!!\n");
          }
          else
          {
          int *C[m];
          for(int i=0;i<m;i++)
          {
            C[i]=(int*)malloc(n*sizeof(int));
          }
          for(int i=0;i<m;i++)
          {
            for(int j=0;j<n;j++)
            {
              *(C[i]+j)= *(A[i]+j) + *(B[i]+j);
            }
          }
          printf("The Addition matrix is: \n");
          for(int i=0;i<m;i++)
          {
            for(int j=0;j<n;j++)
            {
              printf("C[%d][%d] = %d\n",i,j,*(C[i]+j));
            }
          }
          }
          break;
      case 2:
          if(n!=p)
          {
            printf("MULTIPLICATION NOT POSSIBLE\n");
          }
          else
          {
            int *C[m];
            for(int i=0;i<m;i++)
            {
              C[i]=(int*)malloc(q*sizeof(int));
            }
            for(int i=0;i<m;i++)
            {
              for(int j=0;j<q;j++)
              {
                *(C[i]+j)=0;
                for(int k=0;k<n;k++)
                {
                  *(C[i]+j)=*(C[i]+j) + (*(A[i]+k) * *(B[k]+j));
                }
              }
            }
            printf("The Multiplication matrix is: \n");
            for(int i=0;i<m;i++)
            {
              for(int j=0;j<q;j++)
              {
                printf("C[%d][%d] = %d\n",i,j,*(C[i]+j));
              }
            }
          }
          break;
        case 3:
            exit(1);
            break;
        default:
            printf("Enter a valid option\n");
            break;
    }
  }
}