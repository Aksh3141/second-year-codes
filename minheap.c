#include<stdio.h>
#include<stdlib.h>
void swapping(int * a, int *b){
	int temp=*a; *a= *b; *b=temp;}
	
int minimum_index(int * a, int *b, int j){
	if(*a<=*b){
		return 2*j;}
	else
		return 2*j+1;	
	}
	
int * generate_random_list(int a){
	int * temp;
	temp = (int *)malloc(sizeof(int)*a);
	for(int i =0; i<a; i++){
		temp[i]=rand()%10000000;
		}	
	return temp;
	}
	
void print_list(int * list, int a){
	for(int i=0; i<a; i++){
		printf("%d\t",list[i]);
		}
	printf("\n");	
	}
	
void min_heapify(int * list, int i, int a){
	int m;
	if(2*i>a){
		return;}
	if(2*i+1<=a){
		m=minimum_index(&list[2*i-1],&list[2*i],i);
		if(list[i-1]>list[m-1]){
			swapping(&list[i-1],&list[m-1]);}
		}
	if(2*i<=a && 2*i+1>a){
		m=2*i;
		if(list[i-1]>list[m-1]){
			swapping(&list[i-1],&list[m-1]);}
		}
	min_heapify(list,m,a);
	}

void build_min_heap(int * list, int a){
	for(int i=(int)(a/2); i>=1; i--){
		min_heapify(list,i,a);}		
	}


void minheap_sort(int  * list, int a){
	build_min_heap(list,a); int b=a;
	for(int i=0;i<b; i++){
		swapping(&list[0],&list[a-1]);
		printf("%d\t",list[a-1]);
		list= (int *)realloc(list,sizeof(int)*(a-1));a--;
		min_heapify(list,1,a);
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
	printf("-------------------------------\n");
	minheap_sort(list,a);
	return 0;
	}
	
	
	
	
