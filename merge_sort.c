/* 
 NAME :- ANKUR KUMAR
 ROLL NO:- 21043
 PROGRAM TO SORT NUMBERS OF A RANDOMLY GENERATED ARRAY USING MERGESORT
     AND DOING THAT 100 TIMES AND REPORTING THE AVERAGE CPU TIME
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to print an array 
void print_list(int * list, int a){
	for(int i=0; i<a; i++){
		printf("%d\t",list[i]);
		}
	printf("\n");	
	}
// function for merge sort 
void merge_sort(int * list, int a){
	if(a==1){return;}
	int x;
	if(a%2==0){x=a/2;}
	else{x=(a+1)/2;}
	int * temp1;int * temp2;
	temp1=(int *)malloc(sizeof(int)*x);
	temp2=(int *)malloc(sizeof(int)*(a-x));
	for(int i=0; i<a; i++){
		if(i<x){
			temp1[i]=list[i];}
		else{
			temp2[i-x]=list[i];}
		}
	
	merge_sort(temp1,x); merge_sort(temp2,a-x);
	
	// -----merging two sorted list to form a bigger sorted list-----
	
	int i=0,j=0,k=0;
	while(x>i && a-x>j){
		if(temp1[i]<=temp2[j]){
			list[k]=temp1[i];
			k++; i++;}
		else{
			list[k]=temp2[j];
			k++; j++;}
		}
	if(x==i){
		while(a-x>j){
			list[k]=temp2[j];
			k++;j++;}
		}
	if(a-x==j){
		while(x>i){
			list[k]=temp1[i];
			k++;i++;}
		}
	free(temp1); free(temp2); // freeing the two list used for merging 
	}
	
// function to generate a random array of numbers	
int * generate_random_list(int a){
	int * temp;
	temp = (int *)malloc(sizeof(int)*a);
	for(int i =0; i<a; i++){
		temp[i]=rand();
		}	
	return temp;
	}
	

int main(){
	clock_t start,end; double sum;
	srand(time(NULL));
	for(int j=1;j<=100;j++){
		int a=1000000;
		int * list;
		list = generate_random_list(a);
		//print_list(list,a);
		start = clock();
		merge_sort(list,a);
		end= clock();
		//print_list(list,a);
		double t= (double)(end-start)/CLOCKS_PER_SEC;
		printf("sorted %d times\n", j);
		printf("time taken to sort: %f\n", t);
		printf("----------------------------------\n");
		sum=sum+t;
		free(list);}
	printf("\n\nTHE AVERAGE CPU TIME TO SORT MILLION NUMBERS USING MERGESORT WAS :- %f sec\n\n",sum/100);	
	return 0;
	}
	
	
	
	
	
	
	
	
	
	
