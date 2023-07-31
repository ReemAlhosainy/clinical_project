#ifndef STD_Types

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "STD_Types.h"

#define S_2      0
#define S_2_30   1
#define S_3      2
#define S_3_30   3
#define S_4      4
#define S_4_30   5


/* 1- Data Type for node */


typedef struct node_type
{
	u8 age;
	u8 gender[7];
	u8 name[51];
	u32 value;
	struct node_type *next;

} node;

struct patient
{
	u8 state;
	u32 id;
};

struct patient arrs[6];
	

void passfunc(u32 pass);
void adminMode();
void userMode();


void viewOnePat();
void cancel(u32 _id);
void addnew(u32 id);
void addNewPet(u32 id, u8 name[],u8 gender[],u8 age);
void reserve(u32 _id);
void edit(u32 id);
void PRintTodayRes();






#endif