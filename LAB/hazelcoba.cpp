#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char UserId[100][17];
char UserName[100][101];
char UserEmail[100][101];
char UserNIM[100][11];
int IsMale[100];

int userCount =0;
void printMenu(){
	printf("1. Insert User\n");
	printf("2. View User\n");
	printf("3. Update User\n");
	printf("4. Delete User\n");
	printf("5. Exit\n");
	printf(">> ");
}

void pauseConsole(){
	printf("Press Enter to continue...");
	getchar();
}

void clearConsole(){
	system("clear");
}

int genderValidation(int gender){
	if(gender !=0 || gender !=1){
		return 0;
	}
	
	return 1;
}


void insertUsername(int index){
	char temp[101];
	while(1){
		printf("Insert Username: ");
		scanf("%[^\n]", temp); getchar();
	
		if(strlen(temp) < 5){
			printf("username length must above 5 char\n");
		} else {
			strcpy(UserName[index],temp);
			break;
		}
	}
}

void insertNIM(int index){
	char temp[101];
	while(1){
		printf("Insert NIM: ");
		scanf("%[^\n]", temp); getchar();
	
		if(strlen(temp) != 10){
			printf("NIM length must be 10 characters\n");
		} else {
			strcpy(UserNIM[index],temp);
			break;
		}
	}
}

void insertGender(int index){
	int temp = -1;
	while(1){
		printf("Insert Gender (1 Male / 0 Female): ");
		scanf("%d", &temp); getchar();
		
		if(temp != 0 && temp != 1){
			printf("Gender must be either 1(Male) or 0(Female)\n");
		} else {
			IsMale[index] = temp;
			break;
		}
	}
}

void insertEmail(int index){
	char temp[101];
	int adaAt = 0;
	int adaDot = 0;
	while(1){
		printf("Insert Email: ");
		scanf("%[^\n]", temp); getchar();
		
		for(int i =0; i < strlen(temp); ++i){
			if(temp[i] == '@'){
				adaAt = 1;
			}
			
			if(adaAt && temp[i] == '.'){
				adaDot = 1;
			}
		}
	
		if(adaAt && adaDot){
			strcpy(UserEmail[index],temp);
			break;
		} else {
			printf("Input valid email\n");
		}
	}
}

void insertUser( int index){
	insertUsername(index);
	insertEmail(index);
	insertNIM(index);
	insertGender(index);
}

void insertNewUser(){
	insertUser(userCount);
	userCount++;
}

void viewUser(){
	for(int i = 0; i < userCount; ++i){
		printf("No %d.\n", i+1);
		printf("UserID : %s\n", UserId[i]);
		printf("Username : %s\n", UserName[i]);
		printf("Email : %s\n", UserEmail[i]);
		printf("NIM : %s\n", UserNIM[i]);
		printf("Male : %d\n", IsMale[i]);
		printf("====================\n");
	}
	
	pauseConsole();
}

void updateUser(){
	char tempName[101];
	printf("Input Target Name: "); 
	scanf("%[^\n]", tempName); getchar();
	
	int index = 0;
	while(1){
		if(strcmp(tempName, UserName[index]) == 0){
			insertUser(index);
			break;
		}
		
		if(index == userCount){
			printf("user not found !!!\n");
			break;
		}
		
		index++;
	}
	
	pauseConsole();
}

void deleteUser(){
	char tempName[101];
	printf("Input Target Name: "); 
	scanf("%[^\n]", tempName); getchar();
	
	int index = 0;
	while(1){
		if(strcmp(tempName, UserName[index]) == 0){
			
			for(int i = index; i < userCount - 1; ++i){
				strcpy(UserId[i],UserId[i+1]);
				strcpy(UserName[i],UserName[i+1]);
				strcpy(UserEmail[i],UserEmail[i+1]);
				strcpy(UserNIM[i],UserNIM[i+1]);
				IsMale[i] = IsMale[i+1];
			}
			printf("user deleted succesfully !!!\n");
			break;
		} 
		
		if(index == userCount){
			printf("user not found !!!\n");
			break;
		}
		
		index++;
	}
	
	pauseConsole();
	userCount--;
}


int nextInput(){
	int temp = 0;
	while(1){
		scanf("%d", &temp);	getchar();
		if(temp < 1 || temp > 5 ){
			printf("Please input valid choice (1-5)\n");
		} else {
			break;
		}
	}
	return temp;
}

int main(){
	int choice = 0;
	while(1){
		clearConsole();
		printMenu();
		choice = nextInput();
		switch(choice){
			case 1:
				insertNewUser();
				break;
			case 2:
				viewUser();
				break;
			case 3:
				updateUser();
				break;
			case 4:
				deleteUser();
				break;
			case 5:
				return 0;
				break;
		}
	}
}