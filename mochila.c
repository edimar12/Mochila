
#include<stdio.h>
#include<stdlib.h>
 

int max(int a, int b) { return (a > b)? a : b; }
 

void mochila(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];

   for (i = 0; i <= n; i++)
   {
	//printf("\n ");
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
	   //printf("%d " ,  K[i][w]);
       }
   }
   i--;
   w--;
   printf("value : %d \n",K[n][W]);
   printf("posicoes escolhidas : ");
   //printf("produtos escolhidos : ");	
	
   while(K[i][w]){
	if(K[i][w] == K[i-1][w])
		i--;	
	else{
		printf(" %d ", i);
		i--;
		w = w - wt[i];
		//printf(" %d ", wt[i]);

	}	
   }

  
}
int main(int argc, char** argv){
	if (argc < 1) exit(EXIT_FAILURE);
	int size, bag, i ;
	scanf("%d", &size);
	scanf("%d", &bag);
	int * weight = (int*) malloc(sizeof(int)*size);
	for(i = 0; i < size; i++)
		scanf("%d", &weight[i]);

	int * value = (int*) malloc(sizeof(int)*size);
	for(i = 0; i < size; i++)
		scanf("%d", &value[i]);
	

	mochila(bag, weight, value, size);
	return 0;
} 

