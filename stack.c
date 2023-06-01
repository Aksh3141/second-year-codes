#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
	int data;
	struct stack * next;
	}stack;

void create_stack(stack ** pointer){
	*pointer = NULL;		
	}

void push_in_stack(stack * pointer , stack ** point){
	int a;
	printf("Enter the element you want to push: ");
	scanf("%d",&a);
	stack * node;
	node = (stack *)malloc(sizeof(stack));
	node->data=a; node->next= pointer;
	*point = node;
	}
	
int pop_from_stack(stack * pointer, stack ** point){
	int poper;
	poper=pointer->data;
	*point=pointer->next;
	free(pointer);
	return poper;	
	}

void free_stack(stack * ptr){
	stack * temp;
	temp=ptr->next;
	free(ptr);
	if(temp != NULL){
		free_stack(temp);
		}
	}
	
void print_stack(stack * ptr){
	stack * temp;
	temp=ptr->next;
	printf("%d\n",ptr->data);
	if(temp != NULL){
		print_stack(temp);
		}
	}

int main(){
	stack * top; int num;
	create_stack(&top);
	while(1){
		printf("Enter 1 to push element in stack: ");
		scanf("%d",&num);
		if(num != 1){
			break;}
		push_in_stack(top,&top);
		}
	int a;
	print_stack(top);
	printf("---------------\n");
	a=pop_from_stack(top,&top);
	printf("The element popped form stack is : %d",a);
	print_stack(top);
	printf("---------------\n");
	free_stack(top);
	return 0;	
	}
