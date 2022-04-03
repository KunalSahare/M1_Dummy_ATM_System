///used for exit();
#include <stdlib.h>   
#include <stdio.h> 
///used for string related operations(eg: strcmp,strcpy,etc)     
#include <string.h>    

/**
 * @brief //Person_FORMAT_IN is used for the deserialization of the data(basically reading data from the file in the manner specified in the Person_format_in). This format is able to distinguish between two Strings because of ',' in between them,meaning whenever a ',' is encountered the next string will be stored in the next structure variable.
 */

const char* PERSON_FORMAT_IN = "(%d,%[^,],%[^,],%[^,],%d,%[^,],%f,%[^,],%ld)\n";   
/**
 * @brief //PERSON_FORMAT_OUT is used for the serialization(writing the stream of bytes to the file) of the data which the user inputs into the database2.txt file(basically writing data to the file in the manner specified in the Person_format_out). The data is first stored into the structure Variables then it is written to the database2.txt file using the format specified.
 * 
 */
const char* PERSON_FORMAT_OUT = "(%d,%s,%s,%s,%d,%s,%.2f,%s,%ld)\n";         

typedef struct{
    int acc_no;
    char firstname[50];
    char lastname[50];
    char username[50];
    char acc_type[20];
    long int phone;
    int pin;
    float balance;
    char city_name[50];  
} bank_acc;

void new_User_Registration(); 
void deposit(int id,int p);
void withdraw(int id);
int check();
void display(int id,int p);
int existinguser();


int main(){                               
    int kk,k1;
    int c;
    int num =1;
    printf("------Welcome to the ATM----\n");
    printf("------Enter your choice:----\n");
    printf("1>--------New User--------\n");
    printf("2>------Existing User------\n");
    printf("3>----------Exit------------\n");
    scanf("%d",&c);
    while(num!=0){
    switch(c){
        case 1:
        k1 = check();
        if(k1 == 1){
        existinguser();
        }
        else{
        new_User_Registration();
        }
        break;
        case 2:
        kk = existinguser();
        if(kk == 1){
            new_User_Registration();
        }
        printf("Thank You");
        break;
        case 3:
        exit(0);
        break;
        default :
        printf("invalid input");
        break;
    }
    return 0;
}
    
}



int check(){
    FILE * foo;
    foo = fopen("database2.txt","r");
    bank_acc acc0;
    int i,j;
    int ff = 1;
    printf("Checking for Account No:  ");
    scanf("%d",&i);
    while(fscanf(foo,PERSON_FORMAT_IN,&acc0.acc_no,acc0.username,acc0.firstname,acc0.lastname,&acc0.pin,acc0.acc_type,&acc0.balance,acc0.city_name,&acc0.phone)!=EOF){
        if(acc0.acc_no == i){
            ff = 0;
            printf("User already Exists");
            getchar();
            getchar();
        printf("Would you like to Login: Press 1 for 'Yes' Or 2 To Continue for New User Registration(Enter Different Account Number):\n");
        scanf("%d",&j);
        return j;    
        }
    }
    return j;
}


int existinguser(){
    int de;
    int uid;
    int pp;
    int cc;
    int n=1;
    printf("Enter your Account Number: ");
    scanf("%d",&uid);
    printf("Enter your pin: ");
    scanf("%d",&pp);

    bank_acc acc1;
    FILE *foo;
    foo = fopen("database2.txt","r");
    fseek(foo,0,SEEK_SET);
    int f = 0;

    while(fscanf(foo,PERSON_FORMAT_IN,&acc1.acc_no,acc1.username,acc1.firstname,acc1.lastname,&acc1.pin,acc1.acc_type,&acc1.balance,acc1.city_name,&acc1.phone)!=EOF){
        if(acc1.acc_no==uid && acc1.pin==pp){
            f = 1;
            printf("User Exists..\n");
            fclose(foo);
            while(n!=0){
            printf("\n----Welcome User-----\n");
            printf("1>-Display your Account Information--\n");
            printf("2>-Deposit Money---\n");
            printf("3>-Withdraw Money--\n");
            printf("4>----Exit------\n");
            printf("---Enter your choice--:");
            scanf("%d",&cc);
            switch(cc){
                case 1:
                display(uid,pp);
                break;
                case 2:
                deposit(uid,pp);
                break;
                case 3:
                withdraw(uid);
                break;
                case 4:
                exit(0);
                break;
                default: 
                printf("Invalid Input..");
                break;

            }
            }
        }
        else{
            f = 0;
        }
    }
if(f == 0){
printf("No such user Exists");
getchar();
getchar();
printf("Do you want to register as a new User:\n");
printf("Press 1 for Yes or 2 For No: \n");
scanf("%d",&de);
return de;
}
return 0;
}


void new_User_Registration(){
    bank_acc acc2;
    printf("Welcome to the ATM....\n");
    printf("Enter the New Account Number(Numbers Only): ");
    scanf("%d",&acc2.acc_no);
    fflush(stdin);
    printf("Enter the Username which will be use(Characters and Numbers Both allowed):");
    scanf("%[^\n]s",acc2.username);
    fflush(stdin);
    printf("Enter the First Name of the Account Holder(Characters Only): ");
    scanf("%[^\n]s",acc2.firstname);
    fflush(stdin);
    printf("Enter the Last Name of the Account Holder(Characters Only): ");
    scanf("%[^\n]s",acc2.lastname);
    fflush(stdin);
    printf("Enter the 4 digit Pin for the new Account:(Numbers Only): ");
    scanf("%d",&acc2.pin);    
    fflush(stdin);
    printf("Enter the Account Type(Savings or Current)(Characters Only): ");
    scanf("%[^\n]s",acc2.acc_type);
    fflush(stdin);   
    printf("Enter the Amount of Money you wish to Deposit initially:(Numbers Only) ");
    scanf("%f",&acc2.balance);
    fflush(stdin);
    printf("Enter the Name of the city you live in:(Characters Only) ");
    scanf("%[^\n]s",acc2.city_name);
    fflush(stdin);
    printf("Enter the phone Number:(Numbers Only) ");
    scanf("%ld",&acc2.phone);
    fflush(stdin);

    FILE * foo;
    foo = fopen("database2.txt","a+");
    if(foo == NULL){
        printf("File Does NOt Exist..");
    }
    else{
        fprintf(foo,PERSON_FORMAT_OUT,acc2.acc_no,acc2.username,acc2.firstname,acc2.lastname,acc2.pin,acc2.acc_type,acc2.balance,acc2.city_name,acc2.phone);
        fclose(foo);
        printf("Values successfully added to the file....");
        printf("Press Enter to Continue...");
        getchar();
        getchar();
        main();
    }
    fclose(foo);
}  



void deposit(int id,int p){
    float depo_amt;
    ///creating a new bank_acc structure variable.
    bank_acc acc3;
    

    FILE *foo,*temp;
    foo = fopen("database2.txt","r");
    temp = fopen("temp.txt","w");
    fseek(foo,0,SEEK_SET); 
    fseek(temp,0,SEEK_SET);

 
    while(!feof(foo)){
        fscanf(foo,PERSON_FORMAT_IN,&acc3.acc_no,acc3.username,acc3.firstname,acc3.lastname,&acc3.pin,acc3.acc_type,&acc3.balance,acc3.city_name,&acc3.phone);
        if(acc3.acc_no!=id){
            fprintf(temp,PERSON_FORMAT_OUT,acc3.acc_no,acc3.username,acc3.firstname,acc3.lastname,acc3.pin,acc3.acc_type,acc3.balance,acc3.city_name,acc3.phone);
        }
        else if(acc3.acc_no==id && acc3.pin==p){
            printf("Enter the Amount of Money to be deposited: ");
            scanf("%f",&depo_amt);
            acc3.balance += depo_amt;
            printf("Balance Now: ");
            printf("%.2f\n",acc3.balance);
            fprintf(temp,PERSON_FORMAT_OUT,acc3.acc_no,acc3.username,acc3.firstname,acc3.lastname,acc3.pin,acc3.acc_type,acc3.balance,acc3.city_name,acc3.phone);
            printf("Money Deposited successfully");
            getchar();
            getchar();
        }

    }

    ///closing the files
    fclose(foo);
    fclose(temp);
    ///deleting the contents of the file database2.txt
    foo = fopen("database2.txt","w");
    fclose(foo);

    ///reopening both database2.txt file and temp.txt file.
    foo = fopen("database2.txt","a+");    
    temp = fopen("temp.txt","r");
    ////seek the pointer of the file to the initial location
    fseek(foo,0,SEEK_SET); 
    fseek(temp,0,SEEK_SET);
    while(!feof(temp)){
        fscanf(temp,PERSON_FORMAT_IN,&acc3.acc_no,acc3.username,acc3.firstname,acc3.lastname,&acc3.pin,acc3.acc_type,&acc3.balance,acc3.city_name,&acc3.phone);
        fprintf(foo,PERSON_FORMAT_OUT,acc3.acc_no,acc3.username,acc3.firstname,acc3.lastname,acc3.pin,acc3.acc_type,acc3.balance,acc3.city_name,acc3.phone);
    }

    fclose(foo);
    fclose(temp);
//deleting the contents of the file temp.txt
    temp = fopen("temp.txt","w"); 
    fclose(temp);
    ///deleting the contents of the file
    remove("temp.txt");  

}    





void withdraw(int id){
    float with_amt;
    bank_acc acc4;
    
    FILE *foo,*temp2;
    foo = fopen("database2.txt","r");
    temp2 = fopen("temp2.txt","w");
    fseek(foo,0,SEEK_SET); 
    fseek(temp2,0,SEEK_SET);

   
    int f2 = 0;
    while(fscanf(foo,PERSON_FORMAT_IN,&acc4.acc_no,acc4.username,acc4.firstname,acc4.lastname,&acc4.pin,acc4.acc_type,&acc4.balance,acc4.city_name,&acc4.phone)!=EOF){
        if(acc4.acc_no!=id){
            fprintf(temp2,PERSON_FORMAT_OUT,acc4.acc_no,acc4.username,acc4.firstname,acc4.lastname,acc4.pin,acc4.acc_type,acc4.balance,acc4.city_name,acc4.phone);
        }
        else{
            printf("Do not give a value which is more than your accoutnt balance.\n");
            printf("%s%f\n","Amount before Withdrawl:",acc4.balance);
            printf("Enter the Amount of Money to be Withdrawn: ");
            scanf("%f",&with_amt);
            float money_gone;
            money_gone = acc4.balance - with_amt;
            printf("%s%f\n","Amount before Withdrawl:",acc4.balance);
            printf("Do not give a value which is more than your accout ");
                acc4.balance = money_gone; 
                fprintf(temp2,PERSON_FORMAT_OUT,acc4.acc_no,acc4.username,acc4.firstname,acc4.lastname,acc4.pin,acc4.acc_type,acc4.balance,acc4.city_name,acc4.phone);
                printf("%s%f\n","Amount after Withdrawl:",acc4.balance);
                printf("\nMoney Withdrawl successfully\n");
                
        }

    }


    fclose(foo);
    fclose(temp2);

    foo = fopen("database2.txt","w"); //deleting contents of file database2.txt
    fclose(foo);


    foo = fopen("database2.txt","a+");    
    temp2 = fopen("temp2.txt","r");
    fseek(foo,0,SEEK_SET); 
    fseek(temp2,0,SEEK_SET);
    while(!feof(temp2)){
        fscanf(temp2,PERSON_FORMAT_IN,&acc4.acc_no,acc4.username,acc4.firstname,acc4.lastname,&acc4.pin,acc4.acc_type,&acc4.balance,acc4.city_name,&acc4.phone);
        fprintf(foo,PERSON_FORMAT_OUT,acc4.acc_no,acc4.username,acc4.firstname,acc4.lastname,acc4.pin,acc4.acc_type,acc4.balance,acc4.city_name,acc4.phone);
    }

    fclose(foo);
    fclose(temp2);

    temp2 = fopen("temp2.txt","w"); //deleting contents of file temp2.txt
    fclose(temp2);


}    

void display(int id,int p){
    char n[50];
    bank_acc acc5;
    

    int ch;
    int f3 = 1;
    char ps[50];

    FILE *foo;
    foo = fopen("database2.txt","r");
    fseek(foo,0,SEEK_SET);
   
   
    while(fscanf(foo,PERSON_FORMAT_IN,&acc5.acc_no,acc5.username,acc5.firstname,acc5.lastname,&acc5.pin,acc5.acc_type,&acc5.balance,acc5.city_name,&acc5.phone)!=EOF){
        if(id==acc5.acc_no && acc5.pin==p){
            printf("Account Holder's First Name: %s\n",acc5.firstname);
            printf("Account Holder's Last Name: %s\n",acc5.lastname);
            printf("Account Holder's ID: %d\n",acc5.acc_no);
            printf("Balance of the Account Holder: %.2f\n",acc5.balance);
            printf("City where the Account Holder resides in: %s\n",acc5.city_name);
            printf("Phone Number of the Account Holder: %ld\n",acc5.phone);
            printf("Press enter to continue...\n");
            getchar();
            getchar();
            f3 = 0;
            printf("-------------------------------");
            
        }
    }
    
        if(f3==1){
            printf("No such User Exists..");
            getchar();
            getchar();
        }

    
    fclose(foo);
}



