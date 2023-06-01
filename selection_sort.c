#include<stdio.h>
#include<stdlib.h>

void swap(int * a, int * b){
	int temp;
	temp = *a;
	*a=*b;
	*b=temp;	
	}



void selection_sort(int * ptr, int a){
	for(int i =0; i<a; i++){
		for(int j=i; j<a; j++){
			if(ptr[i]>ptr[j]){
				swap(&ptr[i],&ptr[j]);}
				}
		}	
	}

void print_my_array(int * arr, int size){
	for(int i =0; i<size; i++){
		printf("%d ",arr[i]);}
	printf("\n");
	
	}


int main(){
	int num;
	printf("Enter the number of elements: ");
	scanf("%d",&num);
	int * array;
	array = (int *)malloc(sizeof(int)*num);
	for(int i =0; i<num; i++){
		int a;
		printf("Enter element:" );
		scanf("%d",&a);
		array[i]=a;
		}
	printf("The Entered array is:\n" );
	print_my_array(array,num);
	selection_sort(array,num);
	printf("The sorted array is:\n" );
	print_my_array(array,num);
	free(array);
	return 0;	
	}
