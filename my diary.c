#include<stdio.h>
#include<conio.h>
int myscmp(char x[10],char y[10])
{  int z=0;
   for(z=0;x[z]!='\0';z++)
   {  if(x[z]!=y[z])
         break;
   }
   if(z==strlen(y))
        return 1;
   else
        return 0;
}
int getint(void)
{  int a;
   printf("enter your choice: ");
   scanf("%d",&a);
   return a;
}   
main(){
    FILE *fp=NULL,*fp1=NULL;
    char pwd[10],epwd[10],gpwd[10],npwd[10],len[10],le[1000],dt[10],n[1],ans,rd;
    int ch1,x,y=0;
    printf("******************************WELCOME TO MY DIARY*******************************");
    fp=fopen("pwd.jpg","r");
    fscanf(fp,"%s",len);
    if(strlen(len)>10)
    {  fclose(fp);
       fp=fopen("pwd.jpg","w");
       printf("set a password (maxium 10 character): ");
       gets(pwd);
       fprintf(fp,"%s",pwd);
       fclose(fp);
       fp=NULL;
    }    
    do
    {  for(x=0;x<80;x++)
           printf("-");
       printf("enter the password: ");
       gets(epwd);
       fp=fopen("pwd.jpg","r");
       fscanf(fp,"%s",gpwd);
       fclose(fp);
       fp=NULL;
       if(myscmp(epwd,gpwd))
       {  printf("correct password\n");
          do
          {  for(x=0;x<80;x++)
                printf("-");
             printf("enter your choice\n");
             printf("1.edit diary\n2.reset password\n3.see diary\n4.exit\n");
             ch1=getint();
             gets(n);
             switch(ch1)
             {  case 1:printf("welcome to MY DIARY program\n");
                       printf("enter date (e.g:- 03.07.1996): ");
                       gets(dt);
                       printf("enter description: \n");
                       gets(le);
                       fp1=fopen("diary.jpg","a");
                       fprintf(fp1,"date: %s\n\nlife event:\n\n",dt);
                       fprintf(fp1,"%s\n\n\n",le);
                       fclose(fp1);
                       break;
                case 2:printf("want to change the password?? Y/N\n");
                       ans=getch();
                       if(ans=='Y'||ans=='y')
                       {  fp=fopen("pwd.jpg","w");
                          do
                          {  printf("enter a new password(maxium 10 characters): ");
                             gets(pwd);
                          }
                          while(strlen(pwd)<5);
                             printf("Reenter password: ");
                             gets(npwd);
                          if(myscmp(pwd,npwd))
                             fprintf(fp,"%s",pwd);
                          fclose(fp);
                          fp=NULL;
                          printf("password updated\n");
                       }
                       break;
                case 3:printf("//***********************see MY DIARY**********************//\n\n");
                       fp1=fopen("diary.jpg","r");
                       if(fp1==NULL)
                          printf("no diary to see\n");
                       else
                       {  while(!feof(fp1))
                          {  rd=fgetc(fp1);
                             putch(rd);
                          }
                          printf("end of file\n");
                          getch();
                       }
                          fclose(fp1);
                          break;
               default:break;
             }
          }
          while(ch1!=4);
       }
       else
       {  printf("acess denied\n");
          y++;
       }
   }
   while(myscmp(epwd,gpwd)==0 && y<3);      
   return 0;
}
