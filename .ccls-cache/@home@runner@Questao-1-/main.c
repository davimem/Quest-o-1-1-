#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

double** LeMatriz(char nome[20],int *m, int *n)
{
  FILE *arq;
  int i,j;
  double **a;
  
  arq=fopen(nome,"r");
  
  fscanf(arq,"%d",m);
  fscanf(arq,"%d",n);

  a=(double **) malloc(sizeof(double *) * *m);
  
  for(i=0; i<*m; i++) a[i]=(double *)malloc(*n * sizeof(double));
  
  for(i=0; i<*m; i++)
  {
    for(j=0;j<*n; j++)
    {
      fscanf(arq,"%lf",&a[i][j]);
    }
  }
  return a;
}

void ImprimeMatriz(double **M, int m, int n)
{
  int i,j;
  for (i=0; i<m; i++) 
  {
    for(j=0;j<n;j++)
    {
      printf("%.2lf ",M[i][j]);
    }
    puts("");
  }  
}

int ComparaMatriz(double **M,double **N,int m1,int m2)
{
  int i,c=1;
  if(m1!=m2) return 1;

  for(i=0; i<m1; i++)
  {
    c=memcmp(M[i], N[i], m1*sizeof(*M[i]));
    printf("%d\n",c);
    if(c!=0) return 1;
  }
  return 0;
}

int main (int argc, char **argv)
{
  double **M1,**M2;
  int m1,n1,m2,n2,i;

  M1=LeMatriz(argv[1], &m1, &n1);
  M2=LeMatriz(argv[2], &m2, &n2);
  
  i=ComparaMatriz(M1, M2, m1, m2);//aaaa
  
  if(i==0) printf("As matrizes sao iguais!\n");
  else printf("As matrizes sao diferentes!\n");
}