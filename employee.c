#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_COMPANY_SIZE 5
#define MAX_NAME_SIZE 11
void printMenu(void);

struct date
{				/* date stucture */
  int day;
  int month;
  int year;
};
typedef struct date date_t;

struct employeelist
{				/* employeelist structure */
  char name[MAX_NAME_SIZE];
  float fte;
  date_t birthday;
};
typedef struct employeelist employeelist_t;
employeelist_t employeelist[MAX_COMPANY_SIZE];

/* Add employee*/
int addEmployee(employeelist_t *emp,int index)
{
   if(index>=MAX_COMPANY_SIZE){
      printf("Maximum number of employees reached.\n");
   }
   else{
     /* */
    printf("Enter name>");
    scanf("%10s",emp[index].name);
    while ((getchar()) != '\n'); 

  /*Check Invalid Birthday Day Input*/
  while(1){
    printf("Enter birthday: day>");
    scanf("%d",&emp[index].birthday.day);
    if(emp[index].birthday.day >=1 && emp[index].birthday.day <=31){
      break;
    }
    else{
      while((emp[index].birthday.day=getchar())!='\n'&&emp[index].birthday.day !=EOF);
      printf("Invalid day. ");
    }
  }

  /*Check Invalid Birthday Month Input*/
  while(1){
    printf("Enter birthday: month>");
    scanf("%d",&emp[index].birthday.month);
    if(emp[index].birthday.month >=1 && emp[index].birthday.month<=12){
      break;
    }
    else{
      while((emp[index].birthday.month=getchar())!='\n'&&emp[index].birthday.month !=EOF);
      printf("Invalid month. ");
    }
  }

  /*Check Invalid Birthday Year Input*/
  while(1){
    printf("Enter birthday: year>");
    scanf("%d",&emp[index].birthday.year);
    if(emp[index].birthday.year >=1800 && emp[index].birthday.year <=2017){
      break;
    }
    else{
      while((emp[index].birthday.year=getchar())!='\n' && emp[index].birthday.year !=EOF);
      printf("Invalid year. ");
    }
  }
  /*Check Invalid FTE Input*/
  while(1){
    printf("Enter FTE>");
    scanf("%f",&emp[index].fte);
    if(emp[index].fte >=0 && emp[index].fte <=1){
      break;
    }
    else{
      while((emp[index].fte=getchar())!='\n' && emp[index].fte !=EOF);
      printf("Invalid FTE. ");
    }
  }
   }
  index++;
  /*printf("%d", index);*/
  return index;
}
  
 

/* Delete Employee*/
int deleteEmployee(int index){
  if (index<=0){
    printf("No employee.\n");
  }
  else{
    index--;
  }
  return index;
}

/* Display Employee*/
void displayEmployee(employeelist_t *emp,int index){
  int i;
  if(index<=0){
    printf("No employee.\n");
  }
  else{
  printf("Name       Birthday   FTE\n");
  printf("---------- ---------- ------\n");
  for(i=0;i<index;i++){
    printf("%-11s",emp[i].name);
    printf("%02d-%02d-%4d ",emp[i].birthday.day,emp[i].birthday.month,emp[i].birthday.year);
    printf("%.4f\n", emp[i].fte);
    };
  }
}

/* Save employee */
void saveEmployee(employeelist_t *emp,int index){
   FILE *file;
   int i;
   file=fopen("database.txt","w");
   if(!file){
       printf("File not found\n");
   }
   else{
       for(i=0;i<index;i++){
        fprintf(file,"%-11s",emp[i].name);
        fprintf(file,"%d %d %d ",emp[i].birthday.day,emp[i].birthday.month,emp[i].birthday.year);
        fprintf(file,"%f\n", emp[i].fte);
        }/*Save Employee To File*/
   }
   fclose(file);  
}

/* Read Employee*/
int readEmployee(char *file,employeelist_t *emp){
   FILE *fp;
   int i=0;
   fp=fopen(file,"r");
   if(fp==NULL){
       printf("Read error\n");
   }
   else{
     while(fscanf(fp,"%s %d %d %d %f",emp[i].name,&emp[i].birthday.day,&emp[i].birthday.month,&emp[i].birthday.year,&emp[i].fte)!=EOF){
       i++;
     }
   }/*Adding to the end of file*/  
    /* calculating the size of the file*/
   return i;
}


int main ()
{
  int choice;
  int index =0;
  do
    {
      printMenu ();
      printf ("Enter your choice>");
      scanf ("%d", &choice);
      switch (choice){
	          case 1:
                index = addEmployee(employeelist,index);
	              break;
	          case 2:
                index = deleteEmployee(index);
	              break;
	          case 3:
                displayEmployee(employeelist,index);
	              break;
	          case 4:
	              saveEmployee(employeelist,index);
	              break;
	          case 5:
                index=readEmployee("database.txt",employeelist);
	              break;
	          case 6:
	              break;
	          default:
	              printf("Invalid choice.\n");
                break;
            };
      }
  while (choice != 6);
  return 0;
}

void printMenu (void)
{
    printf ("\n\n"
	  "1. add employee\n"
	  "2. delete last employee\n"
	  "3. display employee list\n"
	  "4. save the employee list to the database\n"
	  "5. read the employee list from the database\n"
	  "6. exit the program\n");
}