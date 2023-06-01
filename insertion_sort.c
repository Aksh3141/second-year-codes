#include<stdio.h>
#include<stdlib.h>

void swapping(int *a, int *b){	
	int temp;
	temp= *a;
	*a=*b;
	*b=temp;
	}

int * generate_random_list(int num){
	int * array;
	array= (int *)malloc(num*sizeof(int));
	for(int i=0; i<num; i++){
		array[i]= rand()%1000;
		}		
	return array;
	}
	
void print_list(int * list, int a){
	for(int i=0; i<a; i++){
		printf("%d\t",list[i]);}
	printf("\n");	
	}
	
void insertion_sort(int * list, int a){
	for(int i=1;i<a; i++){
		int j=i;
		for(int k=i-1;i>=0;k--){
			if(list[k]<=list[j]){
				break;}
			if(list[k]>list[j]){
				swapping(&list[k],&list[j]); j--;}
			}
		}		
	}

int main(){
	printf("Enter the size of list you want:" );
	int a;
	scanf("%d",&a);
	int * list;
	list=generate_random_list(a);
	print_list(list,a);
	insertion_sort(list,a);
	printf("--------------------------\n");
	print_list(list,a);
	free(list);
	return 0;	
	}
