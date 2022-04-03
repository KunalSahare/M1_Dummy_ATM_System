# Project Details:
## Dummy Atm System.

## Implemented Using : 
    1> C
    2> File Handling 

This is a C Mini Project that Mimics the Functionality of a ATM Machine.
This project uses C and File Handling to achive the simulation of a ATM Machine.

I created this mini project so i can understand how c and file Handling works . I am open to any kind of suggestions regarding the implimentaion and issues.

I have currently Implemented the following features into the ATM program:
    1>New User registration
    2>Deposit Money
    3>Withdraw Money
    4>Display Authorized users information
    5>Exit(The Program will not exit until and unless the user opts to do so).

I am currently working on two more FEATURES that are still 'NOT Implemented' within the project:
1> Transfer of Money from one account to another account.
2> Letting the Authorized user change the fields such as :
    Firstname
    Lastname
    PhoneNumber
    City Name
    UserName
    Cahnge Pin Number


NOTE: ALL the values in the Files are Dummy values.

To implement the program one must have all read,write and execute permissions within the directory in which the program resides.

For some reason i was not able to split the file into 3 parts due to const* char errors.


This C miniproject will run on both Windows gcc compilers as well as Linux gcc Compilers(NOTE: Some gcc compilers may give some WARNINGS.)


The file database2.txt is a dummy file for the demonstration of the ATM Transaction therefore it is Necessary.

All the File read and Write Operations are performed in this database2.txt file

A Makefile has been created for both Windows and Linux gcc Compilation and Execution.

FOR Windows Machines:
    To Compile for Windows gcc compiler(Mingw):
        make compileWin
    To Execute:
        make executeWin

FOR Linux AND MAC Machines:
    To Compile for Mac And Linux Machines:
        make compileLin
    To Execute:
        make executeLin



Note: I would like to implement a proper database like mysql or postgresql but i wasn't able to perform so. So if anyone is willing to help me ,I would really be grateful.

The Functions in the Program are:
1>New User Registration
2>Deposit Amount.
3>Withdraw Amount.
4>Display Information
5>Exit

New User REgistration: - Lets the user create a new user

Deposit: - Lets the Authorized user deposit money

Withdraw:- lets the Authorized user withdraw money

display: - displays the information of the authorized user.

exit: - exits the program

More details in the documentation present in the 3_implementation>documentation

Created by Kunal Sahare