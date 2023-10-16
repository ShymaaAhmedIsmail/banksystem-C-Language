#include"banksystem.h"

node*head=NULL;

node*current =NULL;
node*temp =NULL;
node *display=NULL;
node *del=NULL;
node *update=NULL;
node *update_money=NULL;
int main()
{
    system("color 74");
    MAIN_MENU();

    return 0;
}
void MAIN_MENU()
{

    int choice;
    unsigned short x;
    unsigned short y,z,a;
    printf("   Welecome to account system\n");
    printf("    to create new account press 1 \n");
    printf("    to edit account press 2 \n");
    printf("    to delete account press 3\n");
    printf("    to display your account press 4 \n");
    printf("    to show all customers sorting press 5 \n");
    printf("    to transact press 6 \n");
    printf("    to show your account list press 7 \n");
    printf("    to close press 8 \n");
    scanf("%d",&choice);


    switch(choice)
    {
    case 1:
        NEW_ACCOUNT();
        MAIN_MENU();
        break;
    case 2:
        printf("enter id ");
        scanf("%d",&y);
        CUSTOMER_EDIT(y);
        MAIN_MENU();
        break;
    case 3:
        printf("enter id ");
        scanf("%d",&x);
        DELETE_ACCOUNT(x);
        MAIN_MENU();
        break;
    case 4:
        printf("enter id ");
        scanf("%d",&z);
        display_specific_account(z);
        MAIN_MENU();
        break;
    case 5:
        sort_accounts();
        CUSTOMER_LIST();
        MAIN_MENU();
        break;
    case 6:
        printf("enter id ");
        scanf("%d",&a);
        TRANSACT(a);
        MAIN_MENU();
        break;

    case 7:
        printf("enter id ");
        scanf("%d",&z);
        ACCOUNT_LIST(z);
        MAIN_MENU();
        break;
    case 8:
        close();
        break;
    default:
        break;

    }
}
void NEW_ACCOUNT()
{
    char x;
    //dynamic allocate memory
    current = ( node*)malloc(sizeof( node));
    //dynamic allocate memory
    temp = ( node*)malloc(sizeof( node));

    printf("please enter your name\n ");
    fflush(stdin);
    scanf("%s",&current->info.name);
    printf("please enter your id number\n ");
    fflush(stdin);
    scanf("%d",&current->info.id);
    fflush(stdin);
    printf("please enter your account number \n ");
    scanf("%d",&current->info.acc_no);
    printf("Enter the date of birth(mm/dd/yyyy)\n");
    fflush(stdin);
    scanf("%d/%d/%d",&current->info.dob.month,&current->info.dob.day,&current->info.dob.year);
    printf("please enter your age\n ");
    scanf("%d",&current->info.age);
    printf("please enter your phone\n ");
    scanf("%d",&current->info.phone);
    printf("please enter your address\n ");
    scanf("%s",&current->info.address);
    printf("please enter your national id\n ");
    scanf("%d",&current->info.national_id);
    printf("Your account has successfully created\n ");
    current->next=NULL;
    current->info.numOftransuctions=1;
    //dynamic allocate memory
    current->info.transuctions=(transuct*)malloc(1*sizeof(transuct));


//empty list
    if(head==NULL)
    {

        head=current;
        //printf("%shead\n",head->info.name);
        return 1;
    }
    else
    {
        temp=head;
        //printf("%stemp\n",head->info.name);
        //find the last node
        while(temp->next!=NULL)
        {

            temp=temp->next;
        }
        //add the new node in the end of the linked list
        temp->next=current;
    }
}
void display_specific_account(unsigned short key3)
{


    display=head;
    node*prev3=NULL;


//if the key = the id of the head
    if (display!=NULL&&display->info.id==key3)
    {

        printf("your name is %s\n",display->info.name);
        printf("your id is %d\n",display->info.id);
        printf("your age is %d\n",display->info.age);
        printf("your account number is %d\n",display->info.acc_no);
        printf("your address is %s\n",display->info.address);
        printf("your national id is %d\n",display->info.national_id);
        printf("your phone is %d\n",display->info.phone);
        printf("your date of birthday is %d/%d/%d\n",display->info.dob.month,display->info.dob.day,display->info.dob.year);
        printf("your money%f\n",display->info.money);

        return ;
    }

    //search the right node and print its
    while(display!=NULL&&display->info.id!=key3)
    {
        prev3=display;
        display=display->next;
        if(display->info.id==key3)
        {
            printf("your name is %s\n",display->info.name);
            printf("your id is %d\n",display->info.id);
            printf("your age is %d\n",display->info.age);
            printf("your account number is %d\n",display->info.acc_no);
            printf("your address is %s\n",display->info.address);
            printf("your national id is %d\n",display->info.national_id);
            printf("your phone is %d\n",display->info.phone);
            printf("your date of birthday is %d/%d/%d\n",display->info.dob.month,display->info.dob.day,display->info.dob.year);
            printf("your money money%f\n",display->info.money);

            return 1;
        }

    }

}
void CUSTOMER_LIST()
{
    node*ptr ;
    // current=head;

    if(head!=NULL)
    {
        for(ptr=head; ptr!=NULL; ptr=ptr->next)
        {
            printf("your name is %s\n",ptr->info.name);
            printf("your id is %d\n",ptr->info.id);
            printf("your age is %d\n",ptr->info.age);
            printf("your account number is %d\n",ptr->info.acc_no);
            printf("your address is %s\n",ptr->info.address);
            printf("your national id is %d\n",ptr->info.national_id);
            printf("your phone is %d\n",ptr->info.phone);
            printf("your date of birthday is %d/%d/%d\n",ptr->info.dob.month,ptr->info.dob.day,ptr->info.dob.year);
            printf("Your money%f\n",ptr->info.money);

        }
    }
    else
    {

        printf("empty");
    }
}
void DELETE_ACCOUNT(unsigned short key)
{
    del=head;
    node*prev=NULL;
    //if the key = the id of the head
    if (del!=NULL&&del->info.id==key)
    {

        head=del->next;
        free(del);
        printf("the account delete sucessfully\n");
        return 1;
    }
    //serach the right node
    while(del!=NULL&&del->info.id!=key)
    {
        prev=del;
        del=del->next;
    }
    if(del==NULL)
    {
        return 1;
    }
    prev->next=del->next;
    //remove the node
    free(del);
    printf("the account delete suceefully\n");
}
void CUSTOMER_EDIT(unsigned short key2)
{
    update=head;
    node*prev2=NULL;
    //if the key2 = the id of the head
    if (update!=NULL&&update->info.id==key2)
    {
        printf("please enter your name\n ");
        fflush(stdin);
        scanf("%s",&update->info.name);
        printf("please enter your id number\n ");
        fflush(stdin);
        scanf("%d",&update->info.id);
        fflush(stdin);
        printf("please enter your account number \n ");
        scanf("%d",&update->info.acc_no);
        printf("Enter the date of birth(mm/dd/yyyy)\n");
        fflush(stdin);
        scanf("%d/%d/%d",&update->info.dob.month,&update->info.dob.day,&update->info.dob.year);
        printf("please enter your age\n ");
        scanf("%d",&update->info.age);
        printf("please enter your phone\n ");
        scanf("%d",&update->info.phone);
        printf("please enter your address\n ");
        scanf("%s",&update->info.address);
        printf("please enter your national id\n ");
        scanf("%d",&update->info.national_id);
        printf("Your account has successfully updated\n ");


        return 1;
    }

//edit the data of the account
    while(update!=NULL&&update->info.id!=key2)
    {
        prev2=update;
        update=update->next;
        if(update->info.id==key2)
        {
            printf("please enter your name\n ");
            fflush(stdin);
            scanf("%s",&update->info.name);
            printf("please enter your id number\n ");
            fflush(stdin);
            scanf("%d",&update->info.id);
            fflush(stdin);
            printf("please enter your account number \n ");
            scanf("%d",&update->info.acc_no);
            printf("Enter the date of birth(mm/dd/yyyy)\n");
            fflush(stdin);
            scanf("%d/%d/%d",&update->info.dob.month,&update->info.dob.day,&update->info.dob.year);
            printf("please enter your age\n ");
            scanf("%d",&update->info.age);
            printf("please enter your phone\n ");
            scanf("%d",&update->info.phone);
            printf("please enter your address\n ");
            scanf("%s",&update->info.address);
            printf("please enter your national id\n ");
            scanf("%d",&update->info.national_id);
            printf("Your account has successfully updated\n ");
            return 1;
        }
    }
}
void TRANSACT(unsigned short key3)
{
    update_money=head;
    node*prev3=NULL;
    int choice;
    float amount_money;
    transuct newtransuction;
    printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Enter the amount you want to deposit:$ ");
        fflush(stdin);
        scanf("%f",&amount_money);
        if (update_money!=NULL&&update_money->info.id==key3)
        {
            update_money->info.money+=amount_money;
            printf("\n\nDeposited successfully!");
            printf("The new money%f\n",update_money->info.money);
            newtransuction.operation="deposit";
            newtransuction.amount=amount_money;
            time_t t=time(NULL);
            newtransuction.tm = *localtime(&t);
            update_money->info.transuctions[update_money->info.numOftransuctions-1]=newtransuction;
            update_money->info.numOftransuctions++;
            update_money->info.transuctions= realloc(update_money->info.transuctions,update_money->info.numOftransuctions*sizeof(transuct));
            return 1;
        }

        while(update_money!=NULL&&update_money->info.id!=key3)
        {
            prev3=update_money;
            update_money=update_money->next;
            if(update_money->info.id==key3)
            {
                update_money->info.money+=amount_money;
                printf("\n\nDeposited successfully!");
                printf("The new money%f\n",update_money->info.money);
                newtransuction.operation="deposit";
                newtransuction.amount=amount_money;
                time_t t=time(NULL);
                newtransuction.tm = *localtime(&t);
                update_money->info.transuctions[update_money->info.numOftransuctions-1]=newtransuction;
                update_money->info.numOftransuctions++;
                update_money->info.transuctions= realloc(update_money->info.transuctions,update_money->info.numOftransuctions*sizeof(transuct));
                return 1;
            }

        }
    }
    else
    {
        printf("Enter the amount you want to withdraw:$ ");
        fflush(stdin);
        scanf("%f",&amount_money);
        if (update_money!=NULL&&update_money->info.id==key3)
        {

            update_money->info.money-=amount_money;
            printf("\n\withdraw successfully!");
            printf("The new money%f\n",update_money->info.money);
            newtransuction.operation="withdraw";
            newtransuction.amount=amount_money;
            time_t t=time(NULL);
            newtransuction.tm = *localtime(&t);
            update_money->info.transuctions[update_money->info.numOftransuctions-1]=newtransuction;
            update_money->info.numOftransuctions++;
            update_money->info.transuctions= realloc(update_money->info.transuctions,update_money->info.numOftransuctions*sizeof(transuct));
            return 1;
        }
        else
        {
            printf("your id is not correct");
        }
        while(update_money!=NULL&&update_money->info.id!=key3)
        {
            prev3=update_money;
            update_money=update_money->next;
            if(update_money->info.id==key3)
            {
                update_money->info.money-=amount_money;
                printf("\n\withdraw successfully!");
                printf("The new money%f\n",update_money->info.money);
                newtransuction.operation="withdraw";
                newtransuction.amount=amount_money;
                time_t t=time(NULL);
                newtransuction.tm = *localtime(&t);
                update_money->info.transuctions[update_money->info.numOftransuctions-1]=newtransuction;
                update_money->info.numOftransuctions++;
                update_money->info.transuctions= realloc(update_money->info.transuctions,update_money->info.numOftransuctions*sizeof(transuct));
                return 1;
            }

        }
    }

}
void sort_accounts()
{
    node *tempaccount=head;
    while(tempaccount!=NULL)
    {
        node *tempaccount1=tempaccount->next;
        while(tempaccount1!=NULL)
        {
            int res=strcmp(tempaccount->info.name,tempaccount1->info.name);

            if(res>0)
            {
                int temp=tempaccount->info.acc_no;
                tempaccount->info.acc_no=tempaccount1->info.acc_no;
                tempaccount1->info.acc_no=temp;
                temp=tempaccount->info.age;
                tempaccount->info.age=tempaccount1->info.age;
                tempaccount1->info.age=temp;
                temp=tempaccount->info.id;
                tempaccount->info.id=tempaccount1->info.id;
                tempaccount1->info.id=temp;
                temp=tempaccount->info.national_id;
                tempaccount->info.national_id=tempaccount1->info.national_id;
                tempaccount1->info.national_id=temp;
                temp=tempaccount->info.numOftransuctions;
                tempaccount->info.numOftransuctions=tempaccount1->info.numOftransuctions;
                tempaccount1->info.numOftransuctions=temp;
                temp=tempaccount->info.phone;
                tempaccount->info.phone=tempaccount1->info.phone;
                tempaccount1->info.phone=temp;
                float fl=tempaccount->info.money;
                tempaccount->info.money=tempaccount1->info.money;
                tempaccount1->info.money=fl;
                char ch[60]="a";
                strcpy(ch,tempaccount->info.name);
                strcpy(tempaccount->info.name,tempaccount1->info.name);
                strcpy(tempaccount1->info.name,ch);
                char chadd[60]="a";
                strcpy(chadd,tempaccount->info.address);
                strcpy(tempaccount->info.address,tempaccount1->info.address);
                strcpy(tempaccount1->info.address,chadd);
                struct date da=tempaccount->info.dob;
                tempaccount->info.dob=tempaccount1->info.dob;
                tempaccount1->info.dob=da;
                transuct* tr=tempaccount->info.transuctions;
                tempaccount->info.transuctions=tempaccount1->info.transuctions;
                tempaccount1->info.transuctions=tr;
            }
            tempaccount1=tempaccount1->next;
        }
        tempaccount=tempaccount->next;
    }
}
void ACCOUNT_LIST(unsigned short id)
{
    node* temp_account=head;
    while(temp_account!=NULL)
    {
        if(temp_account->info.id==id)
        {
            for(int i=0; i<temp_account->info.numOftransuctions-1; i++)
            {
                printf("date: %d-%02d-%02d %02d:%02d:%02d", temp_account->info.transuctions[i].tm.tm_year + 1900,
                       temp_account->info.transuctions[i].tm.tm_mon + 1,
                       temp_account->info.transuctions[i].tm.tm_mday,
                       temp_account->info.transuctions[i].tm.tm_hour,
                       temp_account->info.transuctions[i].tm.tm_min,
                       temp_account->info.transuctions[i].tm.tm_sec);
                printf("\nOperation: %s",temp_account->info.transuctions[i].operation);
                printf("\namount: %f\n",temp_account->info.transuctions[i].amount);
            }
        }
        temp_account=temp_account->next;
    }
}
void close()
{
    printf("thank you for visiting bank system ");

}
void serialize(node* root)
{
    FILE* file = fopen("list.txt", "w");
    if (file == NULL)
    {
        exit(1);
    }

    for (node* curr = root; curr != NULL; curr = curr->next)
    {
        fprintf(file,"%s %d %d %d\%d\%d %d %d %s %d\n",current->info.name,current->info.id,current->info.acc_no,current->info.dob.month,current->info.dob.day,current->info.dob.year,current->info.age,current->info.phone,current->info.address,current->info.national_id);
    }
    fclose(file);
}

void deserialize(node** root)
{
    FILE* file = fopen("list.txt", "r");
    if (file == NULL)
    {
        exit(2);
    }


    while(fscanf(file,"%s %d %d %d\%d\%d %d %d %s %d\n",&current->info.name,&current->info.id,&current->info.acc_no,&current->info.dob.month,&current->info.dob.day,&current->info.dob.year,&current->info.age,&current->info.phone,&current->info.address,&current->info.national_id) > 0)
    {
        NEW_ACCOUNT();
    }
    fclose(file);
}
