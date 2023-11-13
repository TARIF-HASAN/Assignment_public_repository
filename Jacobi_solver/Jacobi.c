#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    /*Reading Kmat.txt file into A matrix*/
   int N , count =0 ,i,j;
 printf("Enter order of matrix: ");
 scanf("%d",&N);
 FILE *f1;
 f1 = fopen("Kmat.txt","r");
 double A[N][N] ;
 i=0;
 while(i != N)
 {
     if(count > N-1)
        {
            i++;
            count = 0;
        }
    fscanf(f1,"%lf", &A[i][count]);
     count++;
 }
 fclose(f1);

int size=N;
double x[size],x_upd[size],sum=0;

   /*Reading Fvec.txt into B matrix*/
 f1 = fopen("Fvec.txt","r");

 double B[N] ;
 i=0;
 while(i != N)
 {
    fscanf(f1,"%lf", &B[i]);
     i++;
 }

fclose(f1);


   /*Initializing x with initial guess value*/
   for (i=0; i<size; i++)
   {
       x[i]=1;
       x_upd[i]=1;
   }

   double eps_max=1.0e-6;
   double error=1.0;
   int itr=0;
double abs;
   while (error>eps_max)
   {
       itr+=1;
       error=0;
       for (i=0; i<size; i++)
       {
           sum=0;
           for (j=0;j<size;j++)
           {
               sum+=(A[i][j]*x[j]);
           }
           sum=sum-(A[i][i]*x[i]);
           x_upd[i]=(B[i]-sum)/A[i][i];

       }

       for (i=0;i<size;i++)
       {
           abs=(x_upd[i]-x[i]);
           if (abs<0)
            abs=-abs;

          if (abs>error)
          {
              error=abs;
          }
          x[i]=x_upd[i];
       }

   }
  printf("%d",itr);

return 0;
}
