#include<iostream>
#include<iomanip>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<sstream>
#include <ctime>

void signUpMenu(){
    system("cls");
    cout<<"\t\t ============================================\n";
	cout<<"\t\t =======WELOCOME TO COFFEE SHOP SYSTEM=======\n";
	cout<<"\t\t ============================================\n\n";

	cout<<"\t\t\t|>>>>>>>>>>|Sign Up|<<<<<<<<<<|\n";
	cout<<"\n\n\t\t     You don't have account - sign up now\n";
	cout<<"\n\n\n\t\t\t    Press Enter to Sign up";
	getch();
}
int loginMenu(){
    system("cls");
    cout<<"\t\t ============================================\n";
	cout<<"\t\t =======WELOCOME TO COFFEE SHOP SYSTEM=======\n";
	cout<<"\t\t ============================================\n\n";
	string username,password,correct_username,correct_password;
	cout<<"\t\t\t|>>>>>>>>>>|Login|<<<<<<<<<<|\n\n";
    cout<<"\t\t\tUsername:"; cin>>username;
	cout<<"\t\t\tPassword:"; cin>>password;

    fstream inFile;
    inFile.open("login.txt",ios::in);
    if(!inFile){
        cout<<"Cannot open file!!!";
    }
    string line;
    int i=0;
    while (!inFile.eof()){
        getline (inFile, line);
        if(i==0){correct_username=line;}
        else if(i==1){correct_password=line;}
        i++;
    }
    inFile.close();
    if(correct_password==password && correct_username==username){
        system("cls");
        cout<<"\n\n\n\t\t\t\tlogin Successfully\n";
        getch();
        return 1;
    }else{
        system("color 0C");
        cout<<"\n\n\t\t   Your Username and Password are incorrect\n\n\n";
        cout<<"\t\t =>Please Input Username and Password again...";
        getch();
        system("color 0A");
        return 0;
    }
}
void login(){
    login:

    fstream inFile;
    inFile.open("login.txt",ios::in);

    if(!inFile){
        //have not signed up yet
        fstream outFile;
        outFile.open("login.txt",ios::out);
        signUpMenu();
        system("cls");
        string username,password;
        cout<<"\t\tPlease Input Some Information to Sign Up\n\n";
        cout<<"\t\tUsername: "; cin>>username;
        reinputPassword:
        cout<<"\t\tPassword: "; cin>>password;

        //check strong password
        if(password.length()>=8){
            outFile<<username<<endl;
            outFile<<password<<endl;
            outFile.close();
        }else{
            cout<<"\n\t\tYour password is not strong enough\n";
            goto reinputPassword;
        }
        goto login;
    }else{
        //already signed up
        int check=loginMenu();
        if(check==0) goto login;
    }
    inFile.close();
}
