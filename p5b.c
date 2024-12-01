#include<stdio.h>
/*
A-> SOURCE
B-> TEMP/AUX
C-> DESTINATION
*/
void tower_of_hanoi(int n,char A,char B, char C)
{
  if(n==1)
  {
    printf("MOVE DISK 1 FROM PEG %c to PEG %c\n",A,C);
    return NULL;
  }
  tower_of_hanoi(n-1,A,C,B);
  printf("MOVE DISK %d FROM PEG %c to PEG %c\n",n,A,C);
  tower_of_hanoi(n-1,B,A,C);
}

int main()
{
  int n;
  printf("Enter the number n: \n");
  scanf("%d",&n);
  tower_of_hanoi(n,'A','B','C');
  return 0;
}