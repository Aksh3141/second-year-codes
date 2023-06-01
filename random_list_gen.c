#include<stdio.h>
#include<stdlib.h>

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

int main(){
	printf("Enter the size of random list you want: ");
	int a;
	scanf("%d",&a);
	int * list;
	list = generate_random_list(a);
	print_list(list,a);
	free(list);
	}
