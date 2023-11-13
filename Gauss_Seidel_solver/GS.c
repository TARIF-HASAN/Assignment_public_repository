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
               if (i>j)
               {
               sum+=(A[i][j]*x_upd[j]);
               //printf("%f\n",sum);
               }
               else
               {
                   sum+=(A[i][j]*x[j]);
               }

           }
           sum=sum-(A[i][i]*x[i]);
           //printf("%f\n",A[i][i]);
           //printf("%f\n",sum);
           x_upd[i]=(B[i]-sum)/A[i][i];
           //printf("%f\n",x_upd[i]);

       }

       for (i=0;i<size;i++)
       {
           abs=(x_upd[i]-x[i]);
           if (abs<0)
            abs=-abs;

             //printf("%f\n",error);

          if (abs>error)
          {
              error=abs;
             //printf("%f\n",error);
          }
          x[i]=x_upd[i];
       }

   }
  printf("%d",itr);

  return 0;
}
