#include<stdio.h>
#include<windows.h>
#include<time.h>

int main(){

    system("color 6F");
    int pin=1234, option, enteredpin, count=0, amount=1;
    float balance = 112000;
    int continueTransaction = 1;

    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t\t\t       %s", ctime(&now));
    printf("\n\t\t\t******************** Welcome To EXPRESS CASH ATM Machine ********************");

    //PIN SECTION
    while(pin != enteredpin){
        printf("\n\n\t\t\t Please Enter Your Pin : ");
        scanf("%d", &enteredpin);
        if(enteredpin != pin){
            Beep(610,500);
            printf("\n\t\t\t INVALID PIN!!!");
        }
        count++;
        if(count == 2 && pin != enteredpin){
            exit(0);
        }
    }

    //TRANSACTION SECTION

    printf("\n\t\t\t************************** Available  Transactions **************************");
    printf("\n\n\t\t\t 01. Withdrawl \n");
    printf("\t\t\t 02. Deposit \n");
    printf("\t\t\t 03. Check Balance");

    printf("\n\n\t\t\t Please Enter Which Service You Need : ");
    scanf("%d", &option);

    switch(option){
        case 1 :
            //WITHDRAWL SECTION
            while(amount % 500 != 0){
                printf("\n\t\t\t Enter The Amount : ");
                scanf("%d", &amount);
            if(amount % 500 != 0)
                printf("\n\t\t\t Minimum Amount Of Withdrawn Is BDT.500");
            }
            if(balance < amount){
                printf("\n\t\t\t Sorry Insufficient Balance.");
                printf("\n\n\n\t\t\t****************** Thank You For Banking EXPRESS CASH ATM. ******************");
                amount = 1;
                break;
            }
            else{
                balance -= amount;
                printf("\n\t\t\t You Have Withdrawn BDT. %d\n\t\t\t Your New Balance Is BDT. %0.2f", amount, balance);
                printf("\n\n\n\t\t\t****************** Thank You For Banking EXPRESS CASH ATM. ******************");
                amount = 1;
                break;
            }

        case 2 :
            //DEPOSIT SECTION
            printf("\n\t\t\t Enter The Amount : ");
            scanf("%d", &amount);
            balance += amount;
            printf("\n\t\t\t You Have Deposited BDT. %d.\n\t\t\t Your New Balance Is BDT. %0.2f", amount, balance);
            printf("\n\n\n\t\t\t****************** Thank You For Banking EXPRESS CASH ATM. ******************");
            amount = 1;
            break;

        case 3 :
            printf("\n\t\t\t Your Balance Is BDT. %0.2f", balance);
            printf("\n\n\n\t\t\t****************** Thank You For Banking EXPRESS CASH ATM. ******************");
            break;

        default :
            Beep(610, 500);
            printf("\n\t\t\t Invalid Option You Chossen.");
    }

    getch();
}
