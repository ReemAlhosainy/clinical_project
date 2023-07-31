#include "func_int.h"
// #include <conio.h>

node head;
u32 value,pos, ListLength=0;

void viewOnePat()
{
	printf("\n\n----------------------\n");

	/* at lease 1 node is created */
	if (ListLength > 0) {
		node *current = &head;
		u32 i = 1;

		/* Print the list head */
		printf("%ld- name is %s   ,ID is %ld    ,Gender is %s \n", 
		i,current->name,current -> value,current->gender);

		/*** Print all nodes util you find the last node
		*	which has the next pointer equals to NULL  
		***/
		while ((current -> next) != NULL){
			i++;
			current = current -> next; /* Move to next node */
			printf("%ld- name is %s   ,ID is %ld    ,Gender is %s \n", 
			i,current->name,current -> value,current->gender);
		}
	}else{
		printf("List is Empty\n");
	}
	
	printf("----------------------\n\n\n");
	
}

void cancel(u32 _id)
{
	u8 flag=0;
	for(u8 i =0;i<6;i++)
	{
		if (_id==arrs[i].id)
		{
			/*make it free again*/
			arrs[i].state=0;flag=1;  break;
		}
	}
			if(flag==0){printf("this id isnot found");}

}

void addnew(u32 id)
{           
	node *current = &head;
	while(current != NULL)
	{
		if(current->value == id)
		{
			//id found
			printf("ID %ld is already exist  \n", id);
			return;
		}
		current = current -> next;
	}

	u8 i=0;u16 age;
	u8 arr[51];u8 gender[7];         

	printf("What is the patient name?\n");
	fflush(stdout);

	scanf("%s",arr);
	printf("%s",arr);  

	printf("What is the patient gender?\n");
	fflush(stdout);

	scanf("%s",gender);
	printf("%s",gender);

	printf("THEN ,What is the patient age?\n");
	fflush(stdout);

	scanf("%hd", &age);
	printf("The new patient has been added successfully with...		\
	\nName:%s | Gender:%s | Age:%hd \n", arr, gender, age);

	addNewPet(id, arr, gender, age);



}
 
void addNewPet(u32 id, u8 name[],u8 gender[],u8 age)
{   
	node *last = NULL;
	if (ListLength == 0){

		head.value = id ;
		head.next  = NULL; 
		strcpy(head.name,name);
		strcpy(head.gender,gender);
		last = &head;
	}else{
		/* 1- Allocate the new node */
		node *new = (node*) malloc(sizeof(node));
		/* 2- Assign the received value to the new node */
		new -> value = id;
		strcpy(new->gender,gender);
		strcpy(new->name,name);
		/* 3- Make the new node next pointer to Null, as it will 
		be added to the end of the list */
		new -> next  = NULL;
		/* 4- Search for the last node */
		last = &head;
		while( (last -> next) != NULL ){
			last = (last -> next); /* go to next node */
		} /* pinter last has address last node */
		/* 5- last node point to new node */
		last -> next = new;

	}
	
	/* Increase the list length by one node */
	ListLength++;	
}

void reserve(u32 _id)
{
	u32 u;
	printf("Dear,    the slots are :						\
    \nfirst slot is at 2 pm  PRESS 0 TO CHOOSE IT			\
    \nsecond slot is at 2:30 pm PRESS 1 TO CHOOSE IT		\
    \nthird slot is at 3 pm PRESS 2 TO CHOOSE IT			\
    \nfourth slot is at 3:30 pm PRESS 3 TO CHOOSE IT		\
    \nfifth slot is at 4 pm PRESS 4 TO CHOOSE IT			\
    \nsixth slot is at 4:30 pm PRESS 5 TO CHOOSE IT			\
	When do you want to reserve?\n");
	fflush(stdout);

	scanf("%ld",&u);


    for(u8 i=0;i<6;i++)
	{
		if(i==u)
		{
			if(arrs[i].state==0){

				arrs[i].id=_id;
				arrs[i].state=1; printf("the slot has been reserved successfully !");
				break;

			}else{

			printf("this slot id=s reserved before");
			
			}

		}
	}
		
}

void edit(u32 id)
{   
	int choice;
	
	node *current = &head;
	while(current != NULL)
	{
		if(current->value==id)
		{	 
			printf("if you want to edit the name press 1	\
			\nif you want to edit the gender press 2		\
			\nif you want to edit the age press 3\n");
			
			u8 ag, c=' ';
			u8 *GENDER = (u8*) malloc(sizeof(GENDER)); 
			u8 *NAME =  (u8*) malloc(sizeof(u8)*10000);
			

			scanf("%d", &choice);
			switch(choice)
			{
				case 1: 
					printf("What is the name you want ");
					fflush(stdout);
				
					getchar();
					scanf("%s", NAME);
					printf("%s",NAME);

					strcpy(current->name,NAME);
					break;

				case 2:
					printf("What is the patient gender?\n");
					fflush(stdout);
					fgets(GENDER,sizeof(GENDER),stdin);
					puts(GENDER);
					strcpy(current->gender,GENDER);
					break;

				case 3:

					printf("What is the patient age?\n");
					fflush(stdout);
					getchar();
					scanf("%c",&ag);
					current->age = ag;
					break;
			}

		}
	
		current = current->next;
	}
	
}

void PRintTodayRes(void)
{
	int flag=1;
	for(int i=0;i<6;i++)
	{
		if(arrs[i].state==1)
		{
			printf("%ld\t",arrs[i].id);
			switch(i)
			{
				case 0: printf("at 2 pm \n"); break;
				case 1: printf("at 2:30 pm \n"); break;
				case 2: printf("at 3 pm \n"); break;
				case 3: printf("at 3:30 pm \n"); break;
				case 4: printf("at 4 pm \n"); break;
				case 5: printf("at 4:30 pm \n"); break;
			}
		}
		else{
			flag=0;
		}
	}
	if(flag==0){printf("there is no resrvation!\n");}
	
}