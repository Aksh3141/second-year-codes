#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	int rollno;
	int batchno;
	struct student * next;
	}student;

//------------------------------------------------------------------------
// Function to insert element into the linked list....
void insert_element(student * current, student ** pointer, student ** header ){
	int x,y;
	printf("Enter the Roll number: ");
	scanf("%d",&x);
	printf("Enter the Batch number: ");
	scanf("%d",&y);
	student * node;
	node = (student *)malloc(sizeof(student));
	node->rollno=x;
	node->batchno=y;
	node->next=NULL;

	if (current == NULL){
		*header = node;
		}
	else{
		current->next= node;	
		}
	*pointer = node;
	}
//-----------------------------------------------------------------------
//These are search related function which return the pointer after searching
student * search_by_roll(student * pointer, int roll){
	if(pointer->rollno == roll){
		return pointer;}
	if(pointer->next != NULL){
		return(search_by_roll(pointer->next,roll));}	
	if(pointer->next == NULL){
		return NULL;}
	}
	
student * search_by_batch(student * pointer, int bat){
	if(pointer->batchno == bat){
		return pointer;}
	if(pointer->next != NULL){
		return(search_by_batch(pointer->next,bat));}
	if(pointer->next == NULL){
		return NULL;}	
	}	

student * search_by_next(student * pointer, student * next){
	if(pointer->next == next){
		return pointer;}
	if(pointer->next != NULL){
		return(search_by_next(pointer->next,next));}
	}
//--------------------------------------------------------------------------
//function to search element by roll number or by batch in linked list
void search_linked_list(student * pointer){
	student * temp;
	printf("1 to search by Roll number and 2 to search by batch: ");
	int num; int roll,bat;
	scanf("%d",&num);
	if(num==1){
		printf("Enter Roll number: ");
		scanf("%d",&roll);
		temp = search_by_roll(pointer,roll);
		if(temp == NULL){
			printf("NOT FOUND!!\n");}
		else{
			printf("ELEMENT FOUND!!\n");}
		}
	if(num==2){
		printf("Enter Batch number: ");
		scanf("%d",&bat);
		temp = search_by_batch(pointer,bat);
		if(temp == NULL){
			printf("NOT FOUND!!\n");}
		else{
			printf("ELEMENT FOUND!!\n");}
		}	
	}
//----------------------------------------------------------------------------	
//functions to delete element in linked list
void delete_by_roll(student * pointer, int roll, student ** point){
	student * var1;student * var2;
	var1=search_by_roll(pointer,roll);
	if(var1==NULL){
		printf("ELEMENT NOT FOUND!!");
		return;}
	if(var1==pointer){
		*point=var1->next;
		free(var1);
		return;}
	var2=search_by_next(pointer,var1);
	var2->next=var1->next;
	free(var1);
	}	
	
void delete_by_batch(student * pointer, int bat,student ** point){
	student * var1;student * var2;
	var1=search_by_batch(pointer,bat);
	if(var1==NULL){
		printf("ELEMENT NOT FOUND!!");
		return;}
	if(var1==pointer){
		*point=var1->next;
		free(var1);
		return;}
	var2=search_by_next(pointer,var1);
	var2->next=var1->next;
	free(var1);
	}		
//-----------------------------------------------------------------------

		
void delete_linked_list(student * pointer,student ** point){
	while(1){
	printf("1 to delete by Roll number and 2 to delete by batch: ");
	int num; int roll,bat;
	scanf("%d",&num);
	if(num==1){
		printf("Enter Roll number: ");
		scanf("%d",&roll);
		delete_by_roll(pointer,roll,point);
		}
	if(num==2){
		printf("Enter Batch number: ");
		scanf("%d",&bat);
		delete_by_batch(pointer,bat,point);
		}
	if(num != 1 && num !=2){
		break;}	
	}	
	}
//--------------------------------------------------------------------------
void free_linked_list(student * point){
	student * holder;
	holder=point->next;
	free(point);
	if(holder == NULL){
		return;}
	free_linked_list(holder);
	}

void print_linked_list(student * printer){
	printf("Roll number: %d, Batch number: %d\n",printer->rollno,printer->batchno);	
	if (printer->next != NULL){
		print_linked_list(printer->next);}
	}
//----------------------------------------------------------------------------

int main(){
 	student * ptr=NULL; student * head=NULL; int a,b;
 	while(1){
 		printf("To insert element in the linked list enter 1: ");
 		scanf("%d",&a);
 		if(a!=1){
 			break;}
 		insert_element(ptr,&ptr,&head);
 		}
 	while(1){
 		printf("To search element in the linked list enter 1: ");
 		scanf("%d",&b);
 		
 		if(b!=1){
 			break;}
 		search_linked_list(head);
 		}
 	print_linked_list(head);
 	delete_linked_list(head,&head);
 	print_linked_list(head);
 	free_linked_list(head);
 	return 0;
 	}
