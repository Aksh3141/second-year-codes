#include<stdio.h>
#include<stdlib.h>

typedef struct student{
	int Rollno;
	struct student * next;
	}student;

void create_linked_list(student *point, student ** pointer){
	student * new_node; int a;
	new_node= (student *)malloc(sizeof(student));
	printf("Enter the Roll number: ");
	scanf("%d",&a);
	new_node->Rollno = a;
	new_node->next=NULL;
	*pointer = new_node;
	if(point != NULL){
		point->next=new_node;}
	}
	
void print_linked_list(student * ptr){
	if(ptr==NULL){
		printf("The list is EMPTY!!\n");
		}	
	else{
		printf("ELEMENT OF THE LIST IS: %d\n",ptr->Rollno);
		print_linked_list(ptr->next);
		}
	
	}
	
void free_linked_list(student * ptr){
	student * temp;
	temp = ptr->next;
	free(ptr);
	if(temp == NULL){
		return;}
	free_linked_list(temp);
	}

int main(){
	int a; student * ptr=NULL; student * head=NULL; int flag=0;
	
	while(1){
		printf("Enter 1 to add data: ");
		scanf("%d",&a);
		if(a==1){
			create_linked_list(ptr,&ptr);
			if(flag==0){head=ptr; flag=1;}
			}
		else{
			break;}
	
		}
	print_linked_list(head);
	free_linked_list(head);
	return 0;
	}
