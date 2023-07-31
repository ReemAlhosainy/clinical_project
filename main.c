#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "STD_Types.h"
#include "func_int.h"

	

int flag=1, first;

int main()
{
	
	addNewPet(32, "reemoo", "female", 55);
	addNewPet(50, "remoo", "female", 45);
	
	//  addnew(54);
	/*  viewOnePat();
	for(u8 i =0;i<6;i++)
	{ /*0 if not reserved*/
	/*	arrs[i].state=0;
	/*	arrs[i].id=0;
	}
	*/
	/*while(flag==1)
	{*/

	while(1){
	
		printf("Hello!\nPlease if you are a user ,Press 0		\
		\nif you are an admin ,Press 1							\
		\nShutdown the system, Press 5							\
		\nYour choice is :   ");
		fflush(stdout);

		scanf("%d",&first);

		switch(first){
			case 1:
				/*admin mode ->0*/
				adminMode();
				break;

			case 0:
				/*user mode*/
				userMode();  
				break;
			case 5:
				return 0;
			default:
				printf("Invalid!! Please Read instructions and Try again\n");		
		}
	}
}

