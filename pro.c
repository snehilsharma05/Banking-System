#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
void menu();
void admin();
struct data{
    float amount;
    int number,age;
    char mobile[11];
    char name[100];
    char addr[300];
    char l;
};
int account()
{
    int choice;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t1.TO Continue\n\t\t\t\t\t2.Go Back\n\n\t\t\t\t\tEnter your choice:");
    scanf("%d",&choice);
    if(choice==1){
            struct data d,d1;
            FILE *fp;
            int a=0;
            fp=fopen("record.dat","r");
        printf("\n\n\t\t\t\t\tEnter your account number:");
        scanf("%d",&d.number);
         while(fscanf(fp,"%d %s %d %f %s %c\n",&d1.number,d1.name,&d1.age,&d1.amount,d1.mobile,&d1.l)!=EOF)
            if(d.number==d1.number)
         {printf("\nThis account number already exists..Please Choose Another..Taking You Back To Menu"); fclose(fp); a=1; menu();}
         if(a==0){ fclose(fp); fp=fopen("record.dat","a+"); }
        printf("\n\n\t\t\t\t\tEnter your name:");
        scanf("%s",d.name);
        printf("\n\n\t\t\t\t\tEnter your age:");
        scanf("%d",&d.age);
        printf("\n\n\t\t\t\t\tEnter your Mobile number:");
        scanf("%s",d.mobile);
        if(strlen(d.mobile)!=10)
        {printf("\n\t\tPLEASE ENTER CORRECT MOBILE NUMBER(10 digits Only) :"); scanf("%s",d.mobile);}
        printf("\n\n\t\t\t\t\tEnter the amount you want to desposit:");
        scanf("%f",&d.amount);
        printf("\n\n\t\t\t\t\tLocker Facility (Y/N)?:\n\t\t\t\t\tEnter Your Choice:");
        scanf("%c",&d.l);
        scanf("%c",&d.l);
        fprintf(fp,"%d %s %d %f %s %c\n",d.number,d.name,d.age,d.amount,d.mobile,d.l);
        fclose(fp);
        printf("\n\n\n\t\t\t\t\tYour account has been successfully created!!!!");
        menu();
    }
    else if(choice==2)
          menu();
          else {printf("\n\n\t\t\t\t\tInvalid option added"); menu();}

}
int show()
{
    FILE *fp;
    struct data d;
    int required;
    system("cls");
    fp=fopen("record.dat","r");
    printf("\n\n\n\n\n\n\n\n\t\t\tEnter the account number whose data you want to look:");
    scanf("%d",&required);
    while(fscanf(fp,"%d %s %d %f %s %c\n",&d.number,d.name,&d.age,&d.amount,d.mobile,&d.l)!=EOF)
    {
        if(d.number==required)
        {printf("\tACCOUNT NO.\tNAME\t        AGE\t\tAMOUNT\t\t\tMOBILE\t\tLocker\n");
          printf("\t%d\t\t%s\t\t%d\t\t%.2f\t\t%s\t\t%c\n",d.number,d.name,d.age,d.amount,d.mobile,d.l); fclose(fp); menu();}
    }
    if(d.number!=required)
       {
           printf("No such account found");
            fclose(fp);
           //fordelay(1000000000);
            menu();
       }
}

void admin()
{
    system("cls");
     char password[]="snehil";
    char pass[100];
    int choice;
    struct data d;
    printf("\n\n\n\n\n\n\n\n\t\t\tEnter the super password:");
   scanf("%s",pass);
   if(strcmp(pass,password)!=0)
   {printf("Password Invalid\n");
     printf("\n1.Try again\n2.Menu\n\nEnter your choice:");
      scanf("%d",&choice);
      if(choice==1)
          admin();
          else if(choice==2)
            menu();
          else printf("\nInvalid Option");
   }
   else {
        FILE *q;
        q=fopen("record.dat","r");
        printf("\tACCOUNT NO.\tNAME\t        AGE\t\tAMOUNT\t\t MOBILE\t\t     Locker\n");
       while(fscanf(q,"%d %s %d %f %s %c\n",&d.number,d.name,&d.age,&d.amount,d.mobile,&d.l)!=EOF)
         printf("\t%d\t\t%s\t\t%d\t\t%.2f\t\t%s\t\t%c\n",d.number,d.name,d.age,d.amount,d.mobile,d.l);
        fclose(q);
   }

   printf("\nThis is the info of all accounts");
   menu();
}
void fordelay(int j)
{
    int i,k;
    for(i=0;i<j;i++)
        k=i;
}
void delacc()
{
    FILE *p,*n;
    int no,result=0;
    struct data d;
    p=fopen("record.dat","r");
    n=fopen("new.dat","w");
    printf("Enter your account no. which you want to delete:");
    scanf("%d",&no);
        while(fscanf(p,"%d %s %d %f %s %c\n",&d.number,d.name,&d.age,&d.amount,d.mobile,&d.l)!=EOF)
        {
            if(d.number==no)
                result=1;
          if(d.number!=no)
            fprintf(n,"%d %s %d %f %s %c\n",d.number,d.name,d.age,d.amount,d.mobile,d.l);
        }
        if(result==0)
            printf("No. Such Account Exists");
         fclose(p);
         fclose(n);
         remove("record.dat");
                 rename("new.dat","record.dat");
         if(result==1)
         printf("\nAccount Successfully Deleted");
         menu();
}
void update()
{
    char str[11];
    FILE *p,*n;
    int choice,no,age,result=0,k;
    struct data d;
    p=fopen("record.dat","r");
    n=fopen("new.dat","w");
    printf("What do you want to Update?\n1.Mobile No.\n2.Age\nEnter your choice:");
    scanf("%d",&choice);
    printf("Enter your Account Number:");
    scanf("%d",&no);

    while(fscanf(p,"%d %s %d %f %s %c\n",&d.number,d.name,&d.age,&d.amount,d.mobile,&d.l)!=EOF)
    {
        if(d.number==no && choice==1)
        {
            result=1;
            printf("Enter your new Mobile number:");
            scanf("%s",str);
            fprintf(n,"%d %s %d %f %s %c\n",d.number,d.name,d.age,d.amount,str,d.l);
        }
        else if(d.number==no && choice==2)
        {
            result=1;
            printf("\nPlease provide Your ID Proofs to the Bank");
             for(k=0;k<=6;k++)
             {fordelay(100000);
                printf(".");}
             printf("\nEnter your Correct Age:");
             scanf("%d",&age);
            fprintf(n,"%d %s %d %f %s %c\n",d.number,d.name,age,d.amount,d.mobile,d.l);
        }
        else fprintf(n,"%d %s %d %f %s %c\n",d.number,d.name,d.age,d.amount,d.mobile,d.l);

    }
    if(choice!=1 && choice !=2)
        {printf("\nInvalid Choice Entered"); fclose(p); fclose(n); remove("record.dat"); rename("new.dat","record.dat"); menu();}
    else if(result!=1 )
        {  printf("\nNo such Account Exists"); fclose(p); fclose(n); remove("record.dat"); rename("new.dat","record.dat"); menu();}
    else {  printf("\nInformation Successfully Updated"); fclose(p); fclose(n); remove("record.dat"); rename("new.dat","record.dat"); menu();}
}
void menu()
{
    int a;
    printf("\n\t\t\t\t\tPRESS ANY KEY TO CONTINUE...");
    getch();
    fordelay(100000000);
    system("cls");
    printf("\n\n\n\t\t\t\t\tWELCOME TO MAIN MENU");
    printf("\n\n\n\n\n\t\t\t\t\t1.Create New account\n\t\t\t\t\t2.Show Data\n\t\t\t\t\t3.Transaction\n\t\t\t\t\t4.View all Info(Admin Only)\n\t\t\t\t\t5.Update Account Information\n\t\t\t\t\t6.Apply(CARDS/LOCKER)\n\t\t\t\t\t7.Delete Account\n\t\t\t\t\t8.Exit\n\n\n\n\t\t\t\t\tEnter Your Choice:");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        account();
          break;
    case 2:
        show();
        break;
    case 3:c();
          break;
    case 4:
          admin();
          break;
    case 5:
        update();
        break;
   case 6: apply();
        break;
    case 7:
        delacc();
        break;
    case 8:
        exit(0);
         break;
    }

}
void c()
{
    int a=0;
    FILE *q,*w;
    struct data d1;
    int an,choice;
    float money;
    q=fopen("record.dat","r+");
    w=fopen("a.dat","w");
     printf("\nEnter your account number:");
    scanf("%d",&an);
    printf("\n1.Withdraw\n2.Deposit\nEnter your choice:");
    scanf("%d",&choice);
    if(choice!=1 && choice!=2)
    { printf("\nInavalid Option"); fclose(q); fclose(w); remove("a.dat"); }
    else{
        while(fscanf(q,"%d %s %d %f %s %c\n",&d1.number,d1.name,&d1.age,&d1.amount,d1.mobile,&d1.l)!=EOF)
        {
            if(d1.number==an && choice==1)
            {
                a=1;
               printf("Enter the ammount:");
                    scanf("%f",&money);
                if(money>d1.amount)
                   {
                    printf("\nYour account doesn't have sufficient balance\nAmount available in your account:%.2f",d1.amount);
                    fprintf(w,"%d %s %d %f %s %c\n",d1.number,d1.name,d1.age,d1.amount,d1.mobile,d1.l);}
                else { d1.amount=d1.amount-money; money=d1.amount; fprintf(w,"%d %s %d %f %s %c\n",d1.number,d1.name,d1.age,money,d1.mobile,d1.l); printf("\nTransaction completed successfully");}
            }
            else if(d1.number==an && choice==2)
            {
                a=1;
                printf("\nEnter the amount:");
                    scanf("%f",&money);
                    money=d1.amount+money;
                    fprintf(w,"%d %s %d %f %s %c\n",d1.number,d1.name,d1.age,money,d1.mobile,d1.l); printf("\nTransaction completed successfully");
            }
            else {fprintf(w,"%d %s %d %f %s %c\n",d1.number,d1.name,d1.age,d1.amount,d1.mobile,d1.l);}
        }
        fflush(q); fflush(w);
        fclose(q); fclose(w);
        remove("record.dat");
        rename("a.dat","record.dat");
        if(a==0)
            printf("\nOOPS No Such Account Found!!!CAN'T PROCESS Your TRANSACTION");
    }
printf("\nPress 1 to go to main menu and 0 to exit:");
scanf("%d",&choice);
if(choice==1)
    menu();
}

void apply()
{
    int choice,num,a=0;
    printf("1.CARDS (ATM/VISA/RUPAY/MASTERCARD)\n2.LOCKER\nEnter Your Choice:");
    scanf("%d",&choice);
    if(choice==1)
    {
        int acc,b=0;
        struct data d2; FILE *a;
        printf("Enter your Account Number:"); scanf("%d",&acc);
        a=fopen("record.dat","r");
        while(fscanf(a,"%d %s %d %f %s %c\n",&d2.number,d2.name,&d2.age,&d2.amount,d2.mobile,&d2.l)!=EOF)
        {
            if(d2.number==acc)
            {
                b=1;
            }
        }
        fclose(a);
        if(b==1){
        printf("WHICH CARD YOU WANT TO HAVE?\n1.VISA       (INR 250/YEAR)\n2.MASTERCARD (INR 250/YEAR)\n3.RUPAY     (INR 150/YEAR)\n\nEnter Your Choice:");
        scanf("%d",&choice); printf("\n");
        if(choice==1) printf("VISA CARD WILL BE DELIEVED TO YOU");
        else if(choice==2) printf("MASTERCARD CARD WILL BE DELIEVED TO YOU");
        else if(choice==3) printf("RUPAY CARD WILL BE DELIEVED TO YOU");
        else {printf("PLEASE ENTER A VALID CARD NUMBER"); printf("Press 1 to Go to Main Menu\n0 to exit:"); scanf("%d",&choice); if(choice==1) menu();
           else exit(0);
        }
        }
        else printf("\nNo Such Account Number found");
        printf("\n\n Press 1 to go to Main Menu\nPress 0 to exit:"); scanf("%d",&choice); if(choice==1) menu();
               else exit(0);
    }
    else if(choice==2)
    {
        FILE *fp,*n;
        struct data d1;
        printf("Please Enter Your Account Number:"); scanf("%d",&num);
        fp=fopen("record.dat","r"); n=fopen("new.dat","w");
        while(fscanf(fp,"%d %s %d %f %s %c\n",&d1.number,d1.name,&d1.age,&d1.amount,d1.mobile,&d1.l)!=EOF)
           {
               if(d1.number==num)
              {
                if(d1.l=='y' || d1.l=='Y')
                {printf("\nYou Already Have A Locker In The Bank");
                fprintf(n,"%d %s %d %f %s %c\n",d1.number,d1.name,d1.age,d1.amount,d1.mobile,d1.l);
                a=1;}
                else if(d1.l=='n' || d1.l=='N')
                    {printf("\nLocker Has Been alloted To You");
                    d1.l='Y';
                fprintf(n,"%d %s %d %f %s %c\n",d1.number,d1.name,d1.age,d1.amount,d1.mobile,d1.l);
                a=1;}

               }
            else
                fprintf(n,"%d %s %d %f %s %c\n",d1.number,d1.name,d1.age,d1.amount,d1.mobile,d1.l);
           }
           fclose(fp); fclose(n);
           remove("record.dat");
           rename("new.dat","record.dat");
           if(a==0)
           {
               printf("\nNo Such Account Found\n Press 1 to go to Main Menu\nPress 0 to exit:"); scanf("%d",&choice); if(choice==1) menu();
               else exit(0);
           }
           else
           {
               printf("\n\nPress 1 to go to Main Menu\nPress 0 to exit:"); scanf("%d",&choice); if(choice==1) menu();
               else exit(0);
           }

    }
    else {printf("\nINVALID CHOICE ENTERED\nPress 1 to Continue 0 to Exit"); scanf("%d",choice); if(choice==1) menu(); else exit(0);}

}
int main()
{

   int i;
    printf("\n\n\n\n\n\n\n\t\t\t\t\tWELCOME");
    for(i=0;i<=6;i++){
    fordelay(100000000);
    printf(".");
    }

    menu();
    return 0;
}
