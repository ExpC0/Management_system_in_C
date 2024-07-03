/*Developed Under linux system some library func. may vary for other system like windows*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void start(void); //func to print first menu
void gotoxy(int x,int y); //gotoxy is not available in linux by default
void clean_stdin(void);  //fflush is  not available in linux so..it is defined for that job

void admin1(void); //func for  admin menu
void t_panel(void); //teacher menu func
void st_panel (void); //student menu func


int main()
{


      struct tinfo   //struct for teacher's info.
  {

  char nm[50],course[30];
  int id;

  };

  struct tinfo sir;


    struct sinfo  //struct for student's info.
  {
  char name[50];
  int roll,marks;

  };

  struct sinfo std;

  struct login // struct for login info for both students & teachers
  {

  char susr[40],tusr[40];
  int spass,tpass;

  };

  struct login ac;



  char ch,ch1,another='Y',adusrnm[40],tusrnm[40],susrnm[40];
  int adpass,thpass,stpass,flag = 0,flag1 = 0,search_roll,search_roll2,count=0;

  start()  ;

  ch = getchar();     //getchar may vary in windows


  switch(ch)
  {

  case '1': // 1 for admin login

  system("clear");  // using it instead of clrscr(); for linux
  gotoxy(20,8);
  printf("<< loign here >>");
  gotoxy(20,10);
  printf("Admin's username: ");
  scanf("%s",adusrnm);
  gotoxy(20,12);
  printf("Password: ");
  scanf("%d",&adpass);


  if ((strcmp(adusrnm,"admin")==0) && (adpass == 15907))
  {
  admin1();

  clean_stdin();
  ch1 = getchar();

  switch(ch1)
  {

   case '1': // admin's job 1 >> create ac. for teachers

    system("clear");
    FILE *fp;
    fp=fopen("t_info","w+");

    fseek(fp,0,SEEK_END);

    while( another == 'Y')
    {

    printf("Enter New Username and Password: ");
    scanf("%s %d",ac.tusr,&ac.tpass);
    fwrite(&ac,sizeof(ac),1,fp);
    printf("Create Another AC. ( Y or N): ");

    clean_stdin();
    another = getchar();


    }

    fclose(fp);

    break;



    case '2': //admin's job 2 >> create ac. for students

    system("clear");
    FILE *fp1;
    fp1=fopen("s_info","w+");

    fseek(fp1,0,SEEK_END);

    while( another == 'Y')
    {

    printf("Enter New Username and Password: ");
    scanf("%s %d",ac.susr,&ac.spass);
    fwrite(&ac,sizeof(ac),1,fp1);
    printf("Create Another AC. ( Y or N): ");

    clean_stdin();
    another = getchar();


    }
    fclose(fp1);

    break;


    case '3':   //admin's  job 3 >> updating student's information


    system("clear");
    FILE *fp2;
    fp2=fopen("s_info2","w+");

    fseek(fp2,0,SEEK_END);

    while( another == 'Y')
    {

    printf("Enter Student's Name,Roll,Marks(CT) : ");
    scanf("%s %d %d",std.name,&std.roll,&std.marks);
    fwrite(&std,sizeof(std),1,fp2);
    printf(" Add Another Info. ( Y or N): ");

    clean_stdin();
    another = getchar();


    }
    fclose(fp2);

    break;

    case '4':  //admin's job 4 >> updating teacher's information

    system("clear");
    FILE *fp3;
    fp3=fopen("t_info2","w+");

    fseek(fp3,0,SEEK_END);

    while( another == 'Y')
    {

    printf("Enter Teacher's Name,ID,Course: ");
    scanf("%s %d %s",sir.nm,&sir.id,sir.course);
    fwrite(&sir,sizeof(sir),1,fp3);
    printf(" Add Another Info. ( Y or N): ");

    clean_stdin();
    another = getchar();


    }
    fclose(fp3);

    break;



}

}
  else
  {

  gotoxy(20,14);
  printf("Incorrect username or password!!!!!\n\n");

  }

  break;


  case '2':  // 2 for teacher's login

    system("clear");
  gotoxy(20,8);
  printf("<< loign here >>");
  gotoxy(20,10);
  printf("Teacher's username: ");
  scanf("%s",tusrnm);
  gotoxy(20,12);
  printf("Password: ");
  scanf("%d",&thpass);

  FILE *ft;

  ft = fopen("t_info","r");
  while ( fread(&ac,sizeof(ac),1,ft)==1)
{

  if ( strcmp(ac.tusr,tusrnm)== 0 && (ac.tpass == thpass))
  {
  t_panel();

  clean_stdin();
  ch = getchar();

  switch(ch)
  {
   case '1': //teacher's job 1 >> updating Students CT marks

    system("clear");
    FILE *fk;
    fk=fopen("s_info2","w+");

    fseek(fk,0,SEEK_END);

    while( another == 'Y')
    {

    printf("Enter Student's Name,Roll,Marks(CT) : ");
    scanf("%s %d %d",std.name,&std.roll,&std.marks);
    fwrite(&std,sizeof(std),1,fk);
    printf(" Add Another Info. ( Y or N): ");

    clean_stdin();
    another = getchar();


    }
    fclose(fk);

    break;


    case '2':  //teacher's job 2 >> search student's info.


    system("clear");
    FILE *fk1;
    fk1=fopen("s_info2","r");


    while( another == 'Y')
    {

    printf("Enter Student's Roll to view info. : ");
    scanf("%d",&search_roll);
    while(fread(&std,sizeof(std),1,fk1)==1 && (search_roll==std.roll) )
    {

    printf("Name : %s Roll : %d CT Marks : %d",std.name,std.roll,std.marks);
    break;
    }


    printf(" \nSearch Again ( Y or N): ");

    clean_stdin();
    another = getchar();


    }
    fclose(fk1);

    break;


    case '3': // teacher's job 3 >> listing all students info & counting total number

    system("clear");
    FILE *fk2;
    fk2=fopen("s_info2","r");


    while(fread(&std,sizeof(std),1,fk2)==1 )
    {

    printf("Name : %s Roll : %d CT Marks : %d",std.name,std.roll,std.marks);
    count++;

    }

    printf("\nIN TOTAL : %d\n",count);

    fclose(fk2);

    break;





    }


  flag = 1;
  break;
  }

}

if ( flag == 0)
{

  gotoxy(20,14);
  printf("Incorrect username or password!!!!!\n\n");
}

  fclose(ft);

  break;





  case '3':  // 3  for student's login

  system("clear");
  gotoxy(20,8);
  printf("<< loign here >>");
  gotoxy(20,10);
  printf("Student's username: ");
  scanf("%s",susrnm);
  gotoxy(20,12);
  printf("Password: ");
  scanf("%d",&stpass);

  FILE *ft1;

  ft1 = fopen("s_info","r");
  while ( fread(&ac,sizeof(ac),1,ft1)==1)
{

  if ( strcmp(ac.susr,susrnm)== 0 && (ac.spass == stpass))
  {

  st_panel();

  clean_stdin();
  ch = getchar();

  if ( ch = '1')
  {

    system("clear");
    FILE *fl;
    fl=fopen("s_info2","r");


    while( another == 'Y')
    {

    printf("Enter Student's Roll to view info. : ");
    scanf("%d",&search_roll2);
    while(fread(&std,sizeof(std),1,fl)==1 && (search_roll2==std.roll) )
    {

    printf("\nName : %s Roll : %d CT Marks : %d",std.name,std.roll,std.marks);
    break;
    }


    printf(" \n\n View Again ( Y or N): ");

    clean_stdin();
    another = getchar();


    }
    fclose(fl);


  }

  flag1 = 1;
  break;
  }

}

if ( flag1 == 0)
{

  gotoxy(20,14);
  printf("Incorrect username or password!!!!!\n\n");
}

  fclose(ft1);

  break;



  }


}


void start(void)
{



  system("clear");
  gotoxy(20,10);
  printf(".......Login as ......");
  gotoxy (20,12);
  printf("1.Admin");
  gotoxy(20,14);
  printf("2.Teacher");
  gotoxy(20,16);
  printf("3.Student");
  gotoxy(20,18);
  printf("---------------Enter Your Choice------------------");
  printf("\n");
  gotoxy(20,20);


}

void admin1(void)
{


system("clear");
gotoxy(20,10);
printf("------------- Welcome to admin panel -----------");
gotoxy(20,12);
printf("1.Create Account for Teacher");
gotoxy(20,14);
printf("2.Create Account for Student");
gotoxy(20,16);
printf("3.Update Student's Information");
gotoxy(20,18);
printf("4.Update Teacher's Information");
gotoxy(20,20);
printf("----------------Enter Your Choice------------\n");
gotoxy(20,22);

}

void t_panel ( void)
{


system("clear");
gotoxy(20,10);
printf("------------- Welcome to Teacher's panel -----------");
gotoxy(20,12);
printf("1.Update CT marks");
gotoxy(20,14);
printf("2.Search any student's information");
gotoxy(20,16);
printf("3.Total listed students");
gotoxy(20,18);
printf("----------------Enter Your Choice------------\n");
gotoxy(20,20);

}

void st_panel (void)
{


system("clear");
gotoxy(20,10);
printf("------------- Welcome to Student's panel -----------");
gotoxy(20,12);
printf("1.View CT marks");
gotoxy(20,14);
printf("----------------Enter Your Choice------------\n");
gotoxy(20,16);

}


//gotoxy func definition

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}



// cleaning stdin func definition

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
