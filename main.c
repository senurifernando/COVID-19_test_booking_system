#include<stdio.h>
#include<stdlib.h>
#include"detailsoftest.c"
#include"declare.c"
#include<string.h>

struct detailsoftest person[200];
int count=0;
int idnum2=100;
int main()
{
    int **seatnumber,choice,price=600,selection,j;
    seatnumber=(int **)calloc(101,sizeof(int *));
    for (j=0;j<3;j++) *(seatnumber+j)=(int *)calloc(101,sizeof(int ));

    int y;
    while(y!=5)
    {
        choice=choicenew();

        switch(choice)
        {
            case 1:
                price= changeprice(price);
                break;
            case 2:
                testdetails();
                break;
            case 3:
                selection=test();
                reserveticket(seatnumber[selection-1],price,selection);
                count++;
                break;
            case 4:
                selection=cantest();
                canceltest(seatnumber[selection-1]);
                break;
            case 5:
                y=5;
                break;
            default:
                printf("Your choice is not available\n");
                break;
        }
    }
}
//Change the price
int changeprice(int price){
    char admin[15],pak[10]= "admin";
    printf("\t\t\tEnter your password to change the price of a ticket: ");
    scanf("%s", &admin);

    if(strcmp(admin,pak)==0)
    {
        printf("\t\t\tPlease enter the new price: ");
        scanf("%d", &price);
        system("PAUSE");
        system("CLS");
    }
    else
        printf("The password you entered is wrong");
    return price;
}
//book seat and select test
void reserveticket(int *array,int price,int selection){
    int j,k;
    printf("\n\t\t\t                      SCREEN\n\n\n");
    for(j=1;j<=100;j++){
        if(array[j]==0)
            printf("%d\t",j);
        else
            printf("*\t",j);
        if(j%10==0)
            printf("\n\n");
    }
    printf("\tPlease enter your name:");
    scanf(" %19[^\n]%*[^\n]", &person[count].pname);
    printf("\tEnter your phone number: ");
    scanf("%u", &person[count].phonenum);
    printf("\tSelect seat number?");
    scanf("%d", &k);


    if(array[k]==1)
    {
        printf("Sorry! this appointment is already booked, please select another seat.\n");
        scanf("%d", &k);
    }
    else
        array[k]=1;
    person[count].seatnumber=k;
    if(selection==1)
        ticket1(k,person[count].pname,idnum2,price);
    else if(selection==2)
        ticket2(k,person[count].pname,idnum2,price);
    else
        ticket3(k,person[count].pname,idnum2,price);
    idnum2++;
}
int choicenew(void)
{
    int choice;
    printf("\n");
    printf("\n");
    printf(" \t\t\t                COVID-19 TEST TICKET BOOKING SYSTEM\n");
    printf("\n");
    printf(" \t\t\t =================================================================================\n");
    printf("\t\t\t *             Enter number 1 To edit price of ticket (only admin can access):    *\n");
    printf("\t\t\t *             Enter number 2 To view reserved tickets (only admin can access):   *\n");
    printf("\t\t\t *             Enter number 3 To purchase your ticket:                            *\n");
    printf("\t\t\t *             Enter number 4 To cancel the seat:                                 *\n");
    printf("\t\t\t *             Enter number 5 To Exit the system:                                 *\n");
    printf("\t\t\t *================================================================================*\n");
    printf("\n");
    printf("\t\t\t   Enter your choice: ");
    scanf("%d",&choice);
    return choice;
}
//Cancel Booking
void canceltest(int *array)
{
    int Cseatnumber,j,stop;
    printf("\t\t\tPlease enter ID number of ticket: ");
    scanf("%d",&Cseatnumber);
    for (j=0;j<300;j++)
    {
        if(Cseatnumber==person[j].id)
        {
            stop=6;
            system("cls");
            printf("\n\n");
            printf("\t\t\t%s your seat number %d is cancelled",person[j].pname,person[j].seatnumber);
            printf("\n\n\n");
            array[person[j].seatnumber]=0;
            j=300;
        }
    }
    if (stop!=6)
        printf("\t\t\tTicket ID number is incorrect please enter right one to cancel ticket: \n");
}
void ticket1(int choice,char pname[20],int idnum2,int price)
{
    system("cls");
    printf("\n\n");
    printf("\t\t\t*******************************PCR TICKET********************************\n");
    printf("\t\t\t================================================================================\n");
    printf("\t\t\t Booking ID : %d \t\t\tTest Name : PCR\n",idnum2);
    printf("\t\t\t Patient   : %s\n",pname);
    printf("\t\t\t\t\t                              Date      : 09-02-2022\n");
    printf("\t\t\t                                              Time      : 07:30am\n");
    printf("\t\t\t                                              Hall      : 02\n");
    printf("\t\t\t                                              seats No. : %d  \n",choice);
    printf("\t\t\t                                              price     : %d  \n\n",price);
    person[count].id=idnum2;
    printf("\t\t\t=================================================================================\n");
    return;
}
void testdetails(void)
{
    int j;
    char admin[15],pak[10]= "admin";
    printf("\t\t\tEnter the password to see details: ");
    scanf("%s",&admin);
    if (strcmp(admin,pak)==0)
    {
        for (j=0;j<count;j++)
        {
            printf("\t\t\tseat no: %d is booked by %s booking id is %d\n",person[j].seatnumber,person[j].pname,person[j].id);
        }
    }
    else
        printf("Entered password is wrong! \n");
    system("PAUSE");
    system("CLS");

}
int test(void)
{
    int j;
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t\tWhich Test you want to have?\n");
    printf("\n\n\n");
    printf("\t\t\t\tpress 1 - PCR Test \n\n");
    printf("\t\t\t\tpress 2 - Rapid Antigen Test(RAT)\n\n");
    printf("\t\t\t\tpress 3 - PCR and RAT\n");
    printf("\n\n");
    printf("\t\tEnter: ");
    scanf("%d",&j);
    system("cls");
    return j;
}
void ticket2(int choice,char pname[20],int idnum2,int price)
{
    system("cls");
    printf("\n\n");
    printf("\t*********************RAT TICKET******************\n");
    printf("\t============================================================\n");
    printf("\t Booking ID : %d \t\t\tTest Name : Rapid Antigen Test(RAT)\n",idnum2);
    printf("\t Patient  : %s\n",pname);
    printf("\t\t\t                              Date      : 10-02-2022\n");
    printf("\t                                              Time      : 01:00pm\n");
    printf("\t                                              Hall      : 03\n");
    printf("\t                                              seats No. : %d  \n",choice);
    printf("\t                                              price . : %d  \n\n",price);
    person[count].id=idnum2;
    printf("\t============================================================\n");
    printf("\n");
    return;
}
int cantest(void)
{
    int j;
    printf("\n");
    printf("\t\t\tWhich Test Appointment you want to cancel?\n");
    printf("\t\t\t-------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\t\t\tpress 1 - PCR\n\n");
    printf("\t\t\tpress 2 - Rapid Antigen Test(RAT)\n\n");
    printf("\t\t\tpress 3 - PCR and RAT\n");
    printf("\n");
    printf("\t\t\t");
    printf("Enter: ");
    scanf("%d",&j);
    return j;
}

void ticket3(int choice,char pname[20],int idnum2,int price)
{
    system("cls");
    printf("\n\n");
    printf("\t***************PCR & RAT BOOKING TICKET***************\n");
    printf("\t============================================================\n");
    printf("\t Booking ID : %d \t\t\tTest Name : PCR & RAT \n",idnum2);
    printf("\t Patient  : %s\n",pname);
    printf("\t\t\t                              Date      : 10-02-2022\n");
    printf("\t                                              Time      : 07:30am\n");
    printf("\t                                              Hall      : 04\n");
    printf("\t                                              seats No. : %d  \n",choice);
    printf("\t                                              price . : %d  \n\n",price);
    person[count].id=idnum2;
    printf("\t============================================================\n");
    return;
}

