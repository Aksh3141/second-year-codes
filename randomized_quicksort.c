/* 
 NAME :- ANKUR KUMAR
 ROLL NO:- 21043
 PROGRAM TO SORT NUMBERS OF A RANDOMLY GENERATED ARRAY USING RANDOMIZED QUICK SORT
     AND DOING THAT 100 TIMES AND REPORTING THE AVERAGE CPU TIME
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//funtion to generate a randomly genrated array of numbers
int * generate_random_list(int a){
	int * temp;
	temp = (int *)malloc(sizeof(int)*a);
	for(int i =0; i<a; i++){
		temp[i]=rand();
		}	
	return temp;
	}
	
//function to PRINT a given array of a given size
void print_list(int * list, int a){
	for(int i=0; i<a; i++){
		printf("%d\t",list[i]);
		}
	printf("\n");	
	}

//fucntion for randomized QUICK SORT	
void quick_sort(int * list,int left,int right){
	if(left>=right){return;}
	int pivot=right;
	int num = (rand()%(right-left+1))+left;  //selecting a random index from the array
	int h = list[num]; list[num]= list[right]; list[right]=h;      // swapping it with the pivot
	int i=left; int j=right-1;
	while(i<=j){
		while(list[i]<list[pivot] && i<=j){
			i++;}
		while(list[j]>list[pivot] && i<=j){
			j--;}
		if(i<=j){int temp=list[i]; list[i]=list[j]; list[j]=temp;
			i++;j--;}
		}
	
	int var = list[i]; list[i]=list[pivot]; list[pivot]=var;
	quick_sort(list,left,i-1); quick_sort(list,i+1,right);   //recursion step----
	}

	
int main(){
	clock_t start,end; double sum=0;
	srand(time(NULL));
	for(int k=1;k<=100;k++){
		int a=1000000;
		int * list;
		list = generate_random_list(a);
		//print_list(list,a);
		start=clock();
		quick_sort(list,0,a-1);
		end=clock();
		//printf("-------------------------------\n");
		//print_list(list,a);
		printf("sorted %d times\n",k);
		double t=(double)(end-start)/CLOCKS_PER_SEC;
		printf("Time taken to sort: %f\n",t);
		printf("-------------------------------\n");
		sum=sum+t;
		free(list);
		}
	printf("\n\nTHE AVERAGE CPU TIME TO SORT MILLION NUMBERS USING RANDOMIZED QUICKSORT WAS :- %f sec\n\n",sum/100);
	return 0;
	}
	
