#include"func_int.h"

void passfunc(u32 pass)
{
	
	int c,flaag=0;u32 id;
	if(pass == 1234){

			while(flaag == 0){
				printf("the patient ID is :   ");
				fflush(stdout);
				scanf("%ld",&id);
				
				printf("What do you wanna to do? 								\
				\nIf you wanna to add new patient record enter 1				\
				\nIf you wanna to edit patient record enter 2					\
				\nIf you wanna to reserve a slot with the doctor enter 3		\
				\nIf you wanna to cancel reservation enter 4					\
				\nYour choice is :   ");
				fflush(stdout);
				
				getchar();
				scanf("%d",&c);
				
				
				switch(c){
					case 1:
						addnew(id);
						flaag=1;
						break;
					case 2:
						edit(id);
						flaag=1;
						break;
					case 3:
						reserve(id);
						flaag=1;
						break;
					case 4:
						cancel(id);
						flaag=1;
						break;
					default:
						printf("Invalid!! Please Read instructions and Try again\n");		
					
				}

			}

	}else{
			
		for(u8 i=0;i<3;i++)
		{
			printf("The password is uncorrect! Please try again\n");
			fflush(stdout);
			scanf("%ld",&pass);
			if(pass==1234){passfunc(1234);   break;}
			if (i==1){printf("No more trials...Good Bye\n"); break;}
		}
	}

	
}

void adminMode()
{
	u32 pas;
	u8 Id, flag = 1;

	printf("You are now in admin node		\
	\nOK ^ ^ Can you Enter the password ");
	fflush(stdout);

	scanf("%ld",&pas);		
	passfunc(pas);
	flag=0;
}

void userMode()
{	
	int cho;
	u8 Id, flag=1;

  	printf("You are now in user mode								\
	\nWhat do you wanna to do?										\
	\nIf you wanna to view a patient record Enter 1					\
	\nIf you wanna to view all today patient reservation Enter 2	\
	\nYour choice is :   ");
	fflush(stdout);

	scanf("%d",&cho);
	switch(cho)
	{
		case 1:
			printf("the patient ID is :   ");
			fflush(stdout);
			//scanf("%c",&Id);	//why ?
			viewOnePat(); 
			break;
		case 2: 
			PRintTodayRes(); 
			break;
	}		

	flag=0;	
}