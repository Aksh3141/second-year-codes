#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
	int data;
	struct queue * next;
	}queue;

void create_queue(queue ** start, queue ** end){
	*start = NULL; *end = NULL;	
	}
	
void enqueue(queue ** start , queue ** end){
	int value;
	printf("Enter the value to be added: ");
	scanf("%d",&value);	
	queue * pointer;
	pointer = (queue *)malloc(sizeof(queue));
	pointer->data=value;
	pointer->next=NULL;
	if (*start == NULL && *end == NULL){
		*start = pointer; *end = pointer;
		}
	else{
		(*end)->next=pointer;
		*end=pointer;
		}
	}
	
int dequeue(queue ** start, queue ** end){
	queue * point;
	if (*start == NULL && *end== NULL){
		printf("The queue is empty");}
	else if(*start == *end){
		point= *start;
		*start = NULL ; *end = NULL;
		return (point->data);
		}		
	else{
		point = *start;
		*start= (*start)->next;
		return (point->data);
		}
	}
	
void free_queue(queue *start){
	queue * temp;
	temp=(start)->next;
	free((start));
	if(temp!=NULL){
		free_queue(temp);}	
	}
	
void print_queue(queue *start){
	queue * temp;
	temp=(start)->next;
	printf("Element in queue: %d\n",start->data);
	if(temp!=NULL){
		print_queue(temp);}	
	}

int main(){
	queue * start ; queue * end; int a,b;
	create_queue(&start, &end);
	while(1){
		printf("To enqueue enter 1: ");
		scanf("%d",&a);
		if(a !=1){
			break;}
		enqueue(&start,&end);
		}
	printf("----------------------\n");
	printf("Printing the queue:\n");
	print_queue(start);
	printf("----------------------\n");
	b=dequeue(&start,&end);
	printf("The element out of queue is: %d\n",b);
	printf("----------------------\n");
	print_queue(start);
	return 0;
	}
