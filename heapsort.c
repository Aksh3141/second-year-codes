/* 
 NAME :- ANKUR KUMAR
 ROLL NO:- 21043
 PROGRAM TO SORT NUMBERS OF A RANDOMLY GENERATED ARRAY USING HEAPSORT
     AND DOING THAT 100 TIMES AND REPORTING THE AVERAGE CPU TIME
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//funtion to swap 

// function to generate random array of numbers
int * generate_random_list(int a){
	int * temp;
	temp = (int *)malloc(a*sizeof(int));
	for(int i=0; i<a; i++){
		temp[i]= rand()%1000;
		}
		return temp;
	}

//function to print a array	
void print_list(int * list, int a){
	for(int i=0; i<a; i++){
		printf("%d\t",list[i]);
		}
	printf("\n");
	}

//This fucntion checks for a single voilation in the max heap property and corrects it-------
void max_heapify(int * list, int j,int a){
	if(j*2 >a){
		return;}
	int m;
	//----if parent node has two children
	if(a>=(2*j +1)){
		if(list[2*j-1]>=list[2*j]){m=2*j;}
		else{m=2*j+1;}
		
		if(list[m-1]>list[j-1]){
			int temp=list[j-1]; list[j-1]=list[m-1]; list[m-1]=temp;}
		}
		
	//---if parent node has a single child
	if(a>=(2*j) && (2*j+1)>a){
		m=2*j;
		if(list[j-1]<list[2*j-1]){
			int temp=list[j-1]; list[j-1]=list[2*j-1]; list[2*j-1]=temp;
			}
		}
	max_heapify(list,m,a);	
	}


// function for Heap sort 	
int * heap_sort_array(int * list, int a){
	for(int i=(int)(a/2); i>=1; i--){
		max_heapify(list,i,a);}
	int b=a;
	for(int i=0; i<b; i++){
		int temp=list[0]; list[0]=list[a-1]; list[a-1]=temp;
		a=a-1;
		max_heapify(list,1,a);
		}	
	return list;
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
		heap_sort_array(list,a);
		end= clock();
		//print_list(list,a);
		double t= (double)(end-start)/CLOCKS_PER_SEC;
		printf("sorted %d times\n", j);
		printf("time taken to sort: %f\n", t);
		printf("----------------------------------\n");
		sum=sum+t;
		free(list);}
	printf("\n\nTHE AVERAGE CPU TIME TO SORT MILLION NUMBERS USING HEAPSORT WAS :- %f sec\n\n",sum/100);	
	return 0;
	}
