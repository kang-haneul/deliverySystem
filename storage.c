#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storage.h"

/* 
  definition of storage cell structure ----
  members :
  int building : building number of the destination
  int room : room number of the destination
  int cnt : number of packages in the cell
  char passwd[] : password setting (4 characters)
  char *contents : package context (message string)
*/
typedef struct {
	int building;
	int room;
	int cnt;
	char passwd[PASSWD_LEN+1];
	
	char *context;
} storage_t;  // 위의 구조체들의 변수들을 모두 srorage_t에 넣었다는 의미. 즉 stroage_t를 출력하면 저 위의 구조체가 나온다. 포인터야  


static storage_t** deliverySystem; 			//deliverySystem
static int storedCnt = 0;					//number of cells occupied
static int systemSize[2] = {0, 0};  		//row/column of the delivery system
static char masterPassword[PASSWD_LEN+1];	//master password




// ------- inner functions ---------------

//print the inside context of a specific cell
//int x, int y : cell to print the context
static void printStorageInside(int x, int y) {
	printf("\n------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n");
	if (deliverySystem[x][y].cnt > 0)
		printf("<<<<<<<<<<<<<<<<<<<<<<<< : %s >>>>>>>>>>>>>>>>>>>>>>>>>>>>\n", deliverySystem[x][y].context);
	else
		printf("<<<<<<<<<<<<<<<<<<<<<<<< empty >>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		
	printf("------------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------------\n\n");
}

//initialize the storage
//set all the member variable as an initial value 
//and allocate memory to the context pointer
//int x, int y : cell coordinate to be initialized
static void initStorage(int x, int y) {


//initialize the storage

	int building =0;
	int room=0;
	int cnt =0;
	char passwd[]= masterPassword; 
	char *context = NULL; //set all the member variable as an initial value
	
	//and allocate memory to the context pointer
	
	int x=0;
	int y=0; //int x, int y : cell coordinate to be initialized
	
	 
}

//get password input and check if it is correct for the cell (x,y)
//int x, int y : cell for password check
//return : 0 - password is matching, -1 - password is not matching
static int inputPasswd(int x, int y) {
	
	int storage_t** deliverySystem;
	

	char input_passwd[];
	input_passwd = (char)getIntegerInput(); //input password
	
	
	if(input_passwd=passwd) //password is matching
		return 0;

	else 					// password is not matching
		return -1;
	
	
}





// ------- API function for main.c file ---------------

//backup the delivery system context to the file system
//char* filepath : filepath and name to write
//return : 0 - backup was successfully done, -1 - failed to backup
int str_backupSystem(char* filepath) {
	
	FILE* fp;
	
	fp=fopen("const char* filepath","w"); //char* filepath : filepath and name to write
	
	
	if (fp ==NULL)
		{
			return -1; // fail to backup
		}
	
	
	fclose(fp);
	
	
	retrun 0; //sucessfully backup
}


//메모리 할당 
//create delivery system on the double pointer deliverySystem
//char* filepath : filepath and name to read config parameters (row, column, master password, past contexts of the delivery system
//return : 0 - successfully created, -1 - failed to create the system
int str_createSystem(char* filepath) {
	
	int i;
	FILE* fp;
	char buffer[100];
	
	int **deliverySystem
	deliverySystem=(int**)malloc(sizeof(int*)*x);
	
	for(i=0;i<x;i++)
		{
			deliverySystem[i] = (int*)malloc(sizwof(int)*y);
			
		}
	
	 for(i=0;i<x;i++)
	 	{
	 		free(deliveryStstem[i]);
		 }
	 
	 free(deliverySystem);  //create delivery system on the double pointer deliverySystem
	 

	FILE *fp=fopen("const char* filepath","r");
	
	fgets(buffer,sizeof(buffer),fp);
	
	if(fp==NULL)
		{
			return -1; //failed to creat the system
		}
	
	fclose(fp); //file path and name to read 
	
	return 0; //successfully created
	
	 
	 
}


//메모리 해제 
//free the memory of the deliverySystem 
void str_freeSystem(void) {
	
	int i;	
	storage_t** deliverySystem;
	
	deliverySystem = (stoage_t**)malloc x*sizeof(storage_t*);
	for(i=0;i<x;i++)
		deliverySystem[i] = (storage_t*)malloc(y*sizeof(storage_t));
		
	for(i=0;i<x;i++)
		free(deliverySystem[i]);
	free(deliverySystem);
	
	
}



//print the current state of the whole delivery system (which cells are occupied and the destination of the each occupied cells)
void str_printStorageStatus(void) {
	int i, j;
	printf("----------------------------- Delivery Storage System Status (%i occupied out of %i )-----------------------------\n\n", storedCnt, systemSize[0]*systemSize[1]);
	
	printf("\t");
	for (j=0;j<systemSize[1];j++)
	{
		printf(" %i\t\t",j);
	}
	printf("\n-----------------------------------------------------------------------------------------------------------------\n");
	
	for (i=0;i<systemSize[0];i++)
	{
		printf("%i|\t",i);
		for (j=0;j<systemSize[1];j++)
		{
			if (deliverySystem[i][j].cnt > 0)
			{
				printf("%i,%i\t|\t", deliverySystem[i][j].building, deliverySystem[i][j].room);
			}
			else
			{
				printf(" -  \t|\t");
			}
		}
		printf("\n");
	}
	printf("--------------------------------------- Delivery Storage System Status --------------------------------------------\n\n");
}



//check if the input cell (x,y) is valid and whether it is occupied or not
int str_checkStorage(int x, int y) {
	if (x < 0 || x >= systemSize[0])
	{
		return -1;
	}
	
	if (y < 0 || y >= systemSize[1])
	{
		return -1;
	}
	
	return deliverySystem[x][y].cnt;	
}


//put a package (msg) to the cell
//input parameters
//int x, int y : coordinate of the cell to put the package
//int nBuilding, int nRoom : building and room numbers of the destination
//char msg[] : package context (message string)
//char passwd[] : password string (4 characters)
//return : 0 - successfully put the package, -1 - failed to put
int str_pushToStorage(int x, int y, int nBuilding, int nRoom, char msg[MAX_MSG_SIZE+1], char passwd[PASSWD_LEN+1]) {
	
	str_checkStorage(x,y);
	
	struct storage_t.[x][y]; //int x, int y : coordinate of the cell to put the package
	
	[x][y].building = nBuilding;
	[x][y].room=nRoom;						//	int nBuilding, int nRoom : building and room numbers of the destination
	strcpy([x][y].msg,&char msg[]);			//char msg[] : package context (message string)
	strcpy([x][y].passwd,&char passwd[]);		//char passwd[] : password string (4 characters)
	
	
	 storage_t.[x][y];
	 
	 if( storage_t.[x][y] ==NULL) //fail to put
	 	{
	 		return -1;
		 }
		 
		 
	 return 0; //sucessfully put
	
	
	
}



//extract the package context with password checking
//after password checking, then put the msg string on the screen and re-initialize the storage
//int x, int y : coordinate of the cell to extract
//return : 0 - successfully extracted, -1 = failed to extract
int str_extractStorage(int x, int y) {
	
	
	str_checkStorage(x,y); //show the situatiom
		
		
	int x,y; //coordinate of the cell to extract
	char passwd[4];
		
	printf("input your coordinate(x y): ");
	scanf("%d%d",&x&y);
	
	storage_t.[x][y];
	
	printf("input password(4 characters): ");
	scanf("%4s",passwd[]);
	
	if(storage_t.passwd==passwd[])
		{
			printf("%100s",storage_t.msg);
			
			initStorage;
			
			return 0; //sucessfully extract
			
			}	
	
	else
		{
			printf("wrong");
			
			return -1;  //failed to extract
		}
	
}

//find my package from the storage
//print all the cells (x,y) which has my package
//int nBuilding, int nRoom : my building/room numbers
//return : number of packages that the storage system has
int str_findStorage(int nBuilding, int nRoom) {
	
	str_checkStorage(x,y); //print all the cells (x,y) which has my package
	
	
	return cnt; ////return : number of packages that the storage system has
	
	
}































