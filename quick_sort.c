#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int * generate_random_list(int a){
	int * temp;
	temp = (int *)malloc(sizeof(int)*a);
	for(int i =0; i<a; i++){
		temp[i]=rand()%1000;
		}	
	return temp;
	}
	
void print_list(int * list, int a){
	for(int i=0; i<a; i++){
		printf("%d\t",list[i]);
		}
	printf("\n");	
	}
	
void swapping(int * a, int *b){
	int temp=*a; *a=*b; *b=temp;}
	
void quick_sort(int * list,int left,int right){
	if(left>=right){return;}
	int pivot=right;
	int i=left; int j=right-1;
	while(i<=j){
		while(list[i]<list[pivot] && i<=j){
			i++;}
		while(list[j]>list[pivot] && i<=j){
			j--;}
		if(i<=j){swapping(&list[i],&list[j]); i++;j--;}
		}
	
	swapping(&list[i],&list[pivot]);
	quick_sort(list,left,i-1); quick_sort(list,i+1,right);
	}
	
int main(){
	clock_t start,end;
	int a;
	printf("Enter the size of the list: "); scanf("%d",&a);
	int * list;
	list = generate_random_list(a);
	print_list(list,a);
	start=clock();
	quick_sort(list,0,a-1);
	end=clock();
	printf("-------------------------------\n");
	print_list(list,a);
	printf("Time taken to sort: %f\n",(double)(end-start)/CLOCKS_PER_SEC);
	printf("-------------------------------\n");
	free(list);
	return 0;
	}
	
	
