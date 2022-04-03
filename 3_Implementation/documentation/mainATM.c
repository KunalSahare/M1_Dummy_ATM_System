/**
 * @mainpage Dummy Atm Project.
 *  GO to > Files > mainATM.c
 * 
 * Files used within the project.
 * 
 * 1> mainATM.c
 * 
 * 2> database2.txt
 * 
 */
/**
 * @file mainATM.c
 * @author Kunal Narendra Sahare
 * @date March 30 2022
 */
#include <stdlib.h>   
#include <stdio.h> 
    
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

/**
 * @brief a struct named 'bank_acc' is being created so the data taken from the user can be read and written to the database2.txt file in a 'STRUCTURED manner'.Every operation will be done through this structure :-
 * reading,writing,appending. 
 */
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

/**
 * @brief line 54 - 59 are all function declarations
 * Each function will be explained when they are encountered below.
 */
void new_User_Registration(); 
void deposit(int id,int p);
void withdraw(int id);
int check();
void display(int id,int p);
int existinguser();



/**
 * @brief The main function is where the program starts from .
 * The user is shown the initial screen of 'Welcome to the ATM',
 * and asked to perform one of the diplayed functions.
 * A switch case has been implemented whenever the user opts to select
 * one of the options.
 * 
 * This is the detailed one. More details 
 * A switch case has been implemented, so the user chooses one of the      options.
 * 1.> When the user presses '1' the user will be taken to the Check() function which will ask the user for a account id, which will be checked across the database2.txt and if a match is found then the user is prompted to either log in or they are given a choice to register as a new user, but if a match is not found within the database2.txt file the user is direclty  taken to the New user Registration function.
 * 
 * 2.> The Second option is for the existing user, when the user presses  '2' the user is asked to enter their account id and account pin which will be checked across the database2.txt and when a match is found the 
 * the user is redirected to a set of switch cases which are only accessed when an id match is found.
 * 
 * 3.> The Third option is for the Exit functoin which will simply exit 
 * entire program.
 * 
 * 
 * @note The program will not terminate until and unless the user selects to exit the program ,but once a user is authenticated they are presented with a new set of options which will let the user to manipulate the 'data',but only relating to that specific user only and not anyone else.
 *  
 * @attention inputing alphabetic or wrong numberic values will lead to the function displaying 'Invalid Input'
 * 
 * @return int 
 */
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


/**
 * @brief Check() function simply checkes for existing user data can is accessed when New User case is selected. if the entered account Number exits then the user is promted to select one of the options
 * 
 * 1> when the user presses '1' then the user will be sent to the existinguser() function where the user will login.
 * 
 * 2> when the user presses '2' then the user will be sent to the new user registration() function where the user will give the details to register as a new user ,after all the values are successfully added the values will be then added to the database2.txt file.
 * 
 * @return int 
 */
int check(){
    FILE * foo;
    foo = fopen("database2.txt","r");
    bank_acc acc0;
    int i,j;
    int ff = 1;
    printf("Checking for Account No:  ");
    scanf("%d",&i);
    /**
     * @brief while(fscanf) reads the entire file from start to END.
     * 
     */
    while(fscanf(foo,PERSON_FORMAT_IN,&acc0.acc_no,acc0.username,acc0.firstname,acc0.lastname,&acc0.pin,acc0.acc_type,&acc0.balance,acc0.city_name,&acc0.phone)!=EOF){
        /**
         * @brief checking whether the acc_accno is already present within the database2.txt or not.
         * 
         */
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

/**
 * @brief The existinguser() function is accessed when the user selects the second option or when the user enters a matching account id in the 'New user' section.
 * 
 * This is the detailed one. More deatails
 * 
 * The user enters the the account Number and pin if they exists then the 
 * user is given a different set of switch cases.
 * These are:-
 * 
 * 1> Displays the user's Information 
 *    
 * 2> Deposit Money(Deposits the money)
 * 
 * 3> Withdraw Money("Withdrawl of the money")
 * 
 * 4> Exit the function.
 * 
 *  if the entered account No and password does not exist in the database then the user will be prompted with the message 'Do you want to register as a new user' 1 for 'yes' and 2 for 'No'.
 * 
 * @return int 
 */
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
///if the account id and pin matches then the user is presented with a new switch case statements. 
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

/**
 * @brief Void new_User_Registration
 * 
 * when no existing user is detected and user wants to register as a new user, new_User_Rgistration() is called.
 * 
 */
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
    printf("Enter the 4 digit Pin for the new Account:(Numbers Only) ");
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




/**
 * @brief void deposit(int id,int p)
 * When the user has been authenticated and wants to perform the deposit action on their account.
 * 
 * This is the detailed description.
 * 
 * Step wise changes:
 * 
 * Since File handling can only perform read,write and append operations modification of the original file becomes a challenge. But update functionality can be achieved through a series of operations done below.
 * 
 * 1>First the database2.txt file is completely read through the fscanf function , all the fields which are not matching from the user account number and pin are stored into a temporary file called 'temp.txt'.
 *  
 * 2> After all the non matching fileds are read from the database2.txt and then stored into temp.txt. The one field that matches with the acc_no and pin are then accessed and the user is prompted to enter the amount of money that needs to be deposited. 
 * 
 * 3> New amount of money is stored into a new variable and then through the structure bank_acc the acc_balance is accessed and the amount is changed in the acc_balance variable .This acc_balance will be now written into the temp.txt file by using the fprintf function().
 * 
 * 4> This changed value will now be written into the temp.txt file and the original database2.txt contents will be deleted , this operation is done through opening the file in 'write' mode and closing it without adding any values in it.
 * 
 * 5> Now the original database2.txt file has been completely wiped but not deleted, but the temp.txt contains all the fields , therefore all the contents of the temp.txt file will be copied into the database2.txt and the temp file will be wiped and then deleted.
 * 
 * @param id This parameter is taking the User Account number.
 * @param p This parameter is taking the user's pin.
 */
void deposit(int id,int p){
    float depo_amt;
    ///creating a new bank_acc structure variable.
    bank_acc acc3;
    
///opening the files database2.txt and temp.txt
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
/// deleting all the contents of the database2.txt so that it can be rewritten after the changes are done.
    foo = fopen("database2.txt","w");
    fclose(foo);

    ///reopening both database2.txt file and temp.txt file.
    foo = fopen("database2.txt","a+");    
    temp = fopen("temp.txt","r");
    ////seek the pointer of the file to the initial location
    fseek(foo,0,SEEK_SET); 
    fseek(temp,0,SEEK_SET);
    ///reading the contents of the temp file and writing them to the original database2.txt file.
    while(!feof(temp)){
        fscanf(temp,PERSON_FORMAT_IN,&acc3.acc_no,acc3.username,acc3.firstname,acc3.lastname,&acc3.pin,acc3.acc_type,&acc3.balance,acc3.city_name,&acc3.phone);
        fprintf(foo,PERSON_FORMAT_OUT,acc3.acc_no,acc3.username,acc3.firstname,acc3.lastname,acc3.pin,acc3.acc_type,acc3.balance,acc3.city_name,acc3.phone);
    }
///closing the files again.
    fclose(foo);
    fclose(temp);

    temp = fopen("temp.txt","w"); //deleting contents of file temp.txt
    fclose(temp);
    ///deleting the  file temp.txt
    remove("temp.txt");  

}    




/**
 * @brief void withdrawl(int id)
 * 
 * When the user has been authenticated and wants to perform the deposit action on their account.
 * 
 * This is the detailed description.
 * 
 * Step wise changes:
 * 
 * Since File handling can only perform read,write and append operations modification of the original file becomes a challenge. But update functionality can be achieved through a series of operations done below.
 * 
 * 1>First the database2.txt file is completely read through the fscanf function , all the fields which are not matching from the user account number and pin are stored into a temporary file called 'temp2.txt'.
 *  
 * 2> After all the non matching fileds are read from the database2.txt and then stored into temp2.txt. The one field that matches with the acc_no is  then accessed and the user is prompted to enter the amount of money that needs to be withdrawn. 
 * 
 * 3> The amount  of money to be withdrawn is stored into a new variable and then through the structure bank_acc the acc_balance is accessed and the amount is changed in the acc_balance variable . A check is performed if the entered amount of money to be withdrawn is more than the Account Holder's balance than the user will be prompted to 'Enter lower amount of money to be withdrawn '. Once acceptable amount is withdrawn from the account then the acc_balance will be now written into the temp2.txt file by using the fprintf function().
 * 
 * 4> This changed value will now be written into the temp2.txt file and the original database2.txt contents will be deleted , this operation is done through opening the file in 'write' mode and closing it without adding any values in it.
 * 
 * 5> Now the original database2.txt file has been completely wiped but not deleted, but the temp2.txt contains all the fields , therefore all the contents of the temp2.txt file will be copied into the database2.txt and the temp2 file will be wiped and then deleted.
 * 
 * @param id This parameter is taking the User Account number.
 * 
 */
void withdraw(int id){
    float with_amt;
    bank_acc acc4;
    
    FILE *foo,*temp2;
    foo = fopen("database2.txt","r");
    temp2 = fopen("temp2.txt","w");
    fseek(foo,0,SEEK_SET); 
    fseek(temp2,0,SEEK_SET);

///reading all the contents of the database2.txt file using the while(fscanf()), all the non-matching id values are copied to the temp2.txt file and when there is a match for one of the id the then the user is asked to enter the amount of money to be withdrawn.
    while(fscanf(foo,PERSON_FORMAT_IN,&acc4.acc_no,acc4.username,acc4.firstname,acc4.lastname,&acc4.pin,acc4.acc_type,&acc4.balance,acc4.city_name,&acc4.phone)!=EOF){
        if(acc4.acc_no!=id){
            fprintf(temp2,PERSON_FORMAT_OUT,acc4.acc_no,acc4.username,acc4.firstname,acc4.lastname,acc4.pin,acc4.acc_type,acc4.balance,acc4.city_name,acc4.phone);
        }
        else{
            printf("Enter the Amount of Money to be Withdrawn: ");
            scanf("%f",&with_amt);
            float money_gone;
            money_gone = acc4.balance - with_amt;
            printf("%s%f\n","Amount before Withdrawl:",acc4.balance);
            if(money_gone<0){
                printf("\nNot Enough Amount...");
                printf("\nEnter a Lower Amount..");
                getchar();
                getchar();
                withdraw(id);
            }
            else{
            acc4.balance = money_gone; 
            fprintf(temp2,PERSON_FORMAT_OUT,acc4.acc_no,acc4.username,acc4.firstname,acc4.lastname,acc4.pin,acc4.acc_type,acc4.balance,acc4.city_name,acc4.phone);
            printf("%s%f\n","Amount after Withdrawl:",acc4.balance);
            printf("\nMoney Withdrawl successfully\n");
            getchar();
            getchar();
            }
               
        }

    }

///closing the files database2.txt and temp2.txt.
    fclose(foo);
    fclose(temp2);
/// deleting all the contents of the database2.txt so that it can be rewritten after the changes are done.
    foo = fopen("database2.txt","w");
    fclose(foo);

///reopening the files and reading all the contents of the temp2.txt and writing it into the original database2.txt file.
    foo = fopen("database2.txt","a+");    
    temp2 = fopen("temp2.txt","r");
    fseek(foo,0,SEEK_SET); 
    fseek(temp2,0,SEEK_SET);
    while(!feof(temp2)){
        fscanf(temp2,PERSON_FORMAT_IN,&acc4.acc_no,acc4.username,acc4.firstname,acc4.lastname,&acc4.pin,acc4.acc_type,&acc4.balance,acc4.city_name,&acc4.phone);
        fprintf(foo,PERSON_FORMAT_OUT,acc4.acc_no,acc4.username,acc4.firstname,acc4.lastname,acc4.pin,acc4.acc_type,acc4.balance,acc4.city_name,acc4.phone);
    }
///closing the files.
    fclose(foo);
    fclose(temp2);

    temp2 = fopen("temp2.txt","w"); //deleting contents of file temp2.txt
    fclose(temp2);
    ///removing the temp2.txt(deleting) from the directory.
    remove("temp2.txt");

}    


/**
 * @brief Displays the content of the Authorized user
 * 
 * This function simply matches the the account Number from the user with the account number in the database2.txt , same for the pin number, if both the fields match then the information regarding the user is displayed on the screen.
 * 
 * @param id The id parameter is the Account holder's account Number.
 * @param p The p parameter is the Account's pin.
 */
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



