#include<stdio.h>
#include<string.h>
#include<stdlib.h>
    int userchoice;
typedef struct
{
    char HouseName[30];
    char location[30];
    float price;
    int code;
}houses;

char fname[10],sname[10],username[20],password[20];
long idNo;

int user()
{
    char password[20];

    int choice=0,secim=0;
char House[100];
int tenantNo=0;
while(1)
{

printf("Welcome to this program\n 1.Create Account\n 2.Log in to existing account\n");
scanf("%d",&choice);
if(choice==1)
{
    FILE*fpointer=fopen("bilgi2.txt","a");
    printf("Enter your full names please\n");
    printf("First Name:");
    scanf("%s",fname);
    printf("Surname:");
    scanf("%s",sname);
    printf("Welcome to This platform Mr/Mrs %s %s\n",fname,sname);
    printf("Enter username of your account:");
    scanf("%s",username);
    while(1)
    {
         printf("Enter password(not less than 8 characters):");
    scanf("%s",password);
    if(strlen(password)<8)
    {
        printf("Password less than minimum required, Try again\n");
        continue;
    }
    else
    {
        printf("Account successfully created\n");
         fprintf(fpointer,"USERNAME: %s PASSWORD: %s\n",username,password);
    fclose(fpointer);
        break;
    }
    }

break;
}
else if(choice==2)
{
    int logged_in=0;
    while(!logged_in)
    {
       printf("Enter username:");
    scanf("%s",username);
    printf("Enter password:");
    scanf("%s",password);
    FILE *fpointer = fopen("bilgi2.txt","r");
     char line[100];
     while(fgets(line,sizeof(line),fpointer)!=NULL)
     {
         char stored_user[20], stored_pass[20];
                if (sscanf(line, "USERNAME: %s PASSWORD: %s", stored_user, stored_pass) == 2)
                 {
                    if (strcmp(stored_user, username) == 0 && strcmp(stored_pass,password) == 0)
                    {
                        printf("Logged in successfully\n");
                        logged_in = 1;
                        break;
                    }
                }
     }
     fclose(fpointer);
     if(!logged_in)
     {
         printf("Wrong username or password, Try again please\n");
     }
    }
    break;


}
else{
    printf("inavlid choice!!Try again please\n");
    continue;
}

}

while(1)
{
   printf("Welcome to this program\n MAIN MENU\n");
printf(" 1. See Available Houses\n 2. Make house reservation\n 3. View reservation status\n 4. Close\n");
scanf("%d",&userchoice);
if(userchoice==1)
{
    FILE *fpointer = fopen("Houselist.txt", "r");
 printf("\nAvailable Houses:\n");
        while (fgets(House, sizeof(House), fpointer) != NULL) {
            printf("%s", House);
        }
        fclose(fpointer);
        printf("1. Go back to Main Menu\n 2. Close\n");
        scanf("%d",&secim);
        if(secim==1)
        {
            continue;
        }
        else if(secim==2)
        {
            break;
        }
}
else if(userchoice==2)
{
    int code=0;
   printf("\n\n\nWhich house do you prefer\n**********************\n Choose house by writing its code\n");
   scanf("%d",&code);
   FILE *fptr;
   fptr=fopen("Reservations.txt","a");
   fprintf(fptr,"USERNAME: %s Reserved House Code: %d\n",username,code);
   fclose(fptr);
           printf("1. Go back to Main Menu\n 2. Close\n");
        scanf("%d",&secim);
         if(secim==1)
        {
            continue;
        }
        else if(secim==2)
        {
            break;
        }
}
else if(userchoice==3)
{
  FILE *ptr2;
  ptr2=fopen("Reservations.txt","r");
    char line[100];
    printf("\n\n\nYour Reservations:\n");
    while (fgets(line, sizeof(line), ptr2)!=NULL)
        {
    if (strstr(line, username)) {
                        printf("%s", line);
                    }
        }
}

else
{
    printf("\n\n\n!!!!!!!!!!!!!**********Goodbye and Thank you for Choosing This Platform********!!!!!!!!!!!!");
    break;
}

}
}

int owner()
{
    houses house[100];
    char choice2;
    int HouseCount=0;
    int i,position;
    char fname[20],sname[20];

   printf("Welcome to Nyumbani rental systems\nEnter your name and password to continue\n");
   printf("Name: ");
   scanf("%s %s",&fname,&sname);
   printf("What would you like to do today Mr %s %s\n",fname,sname);
   printf(" 1.Add house to list\n 2.Check tenants details\n 3.Remove a House\n");
   scanf("%d",&userchoice);
   if(userchoice==1)
   {
   while(1)
   {
       FILE *fpointer;
       fpointer=fopen("Houselist.txt","a");
       printf("Enter House Name: ");
       scanf("%s",&house[HouseCount].HouseName);
       printf("Enter House code(Three letter code):");
       scanf("%d",&house[HouseCount].code);
       printf("Enter House Location: ");
       scanf("%s",house[HouseCount].location);
       printf("Enter House Rent per month: ");
       scanf("%f",&house[HouseCount].price);
       fprintf(fpointer,"House Name: %s\nCode: %d\nLocation: %s\nRent: %2.f\n\n",house[HouseCount].HouseName,house[HouseCount].code,house[HouseCount].location,house[HouseCount].price);
       fclose(fpointer);
       HouseCount++;
       printf("Do you wish to continue adding houses? sir\n Y for Yes N for No\n");
       getchar();
       scanf("%c",&choice2);
       if(choice2=='Y')
       {
          continue;
       }
       else if(choice2=='N')
       {
           break;
       }
   }
   }
   while(userchoice==3)
   {
       char HouseName[20];
       printf("Enter House Name to be deleted\n");
       scanf("%s",HouseName);
        FILE *fpointer = fopen("Houselist.txt", "r");
    FILE *tempPointer = fopen("temp.txt", "w");
    char line[100];
    int skip = 0;

    while (fgets(line, sizeof(line), fpointer) != NULL) {

        if (strstr(line, HouseName) != NULL) {
            skip = 1;
        }


        if (!skip) {
            fprintf(tempPointer, "%s", line);
        }


        if (skip && strstr(line, "Rent:") != NULL) {
            skip = 0;
        }
    }

    fclose(fpointer);
    fclose(tempPointer);


    remove("Houselist.txt");
    rename("temp.txt", "Houselist.txt");

    printf("House removed successfully!\n");
     printf("Do you wish to remove another house?\n Y for yes and N for No\n");
       scanf("%c",choice2);
       if(choice2=='Y')
       {
           userchoice=3;
       }
       else if(choice2=='N')
       {
           userchoice=0;
       }
   }



}
int main()
{
    int choice;
    printf("Welcome to this Rental system\n");
    printf("*******************************\n");
    do{
         printf("Choose who you are\n");
    printf("1.House Owner\n2.Tenant\n");
    scanf("%d",&choice);
    switch(choice)
    {
case 1:
     owner();
     choice=0;
    break;
case 2:
     user();
     choice=0;
    break;
default:
    printf("Invalid choice, Try again\n");
    }
    }
    while(choice!=0);
}
