#include<iostream>
#include<iomanip>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<sstream>
#include <ctime>

using namespace std;
#include"mainDisplay.h"
#include"coffeeList.h"
#include"MemberList.h"
#include"loading.h"
#include"login.h"
#include"orderProduct.h"
#include"view_history.h"
#include"viewMember.h";
#include"manageAccount.h"
//#include"viewProduct.h"

struct addData{
    string c_name;
    string c_id;
    float c_price;
};

struct AddMember{
    string id;
    string name;
    string dob;
    string pob;
    string major;
    string university;
    string career;
    string telephone;
    string facebook;
};

void addProductToList(List *L1){
    struct addData add;
    fstream inFile;
    inFile.open("database.txt",ios::in);
    if(!inFile){
        cout<<"Cannot open file!!!";
    }
    string line, word;
    istringstream iss;
    while (!inFile.eof()){
        getline (inFile, line);
        if (inFile.good()){
            iss.clear();
            iss.str(line);
            int i=0;
            while (iss.good()){
                iss >> word;
                if(word=="-") goto nextLine;
                if(i==0){
                    add.c_id=word;
                }else if(i==1){
                    add.c_name=word;
                }else if(i==2){
                    add.c_price= stof(word);
                }
                i++;
            }
            AddCoffee(L1,add.c_id,add.c_name,add.c_price);
        }
        nextLine:
        cout<<" ";
    }
    inFile.close();
}

void addMemberToList(M_list *L2){

    struct AddMember member;
    fstream inFile;
    inFile.open("member_info.txt",ios::in);
    if(!inFile){
        cout<<"Cannot open file!!!";
    }
    string line, word;
    istringstream iss;
    while (!inFile.eof()){
        getline (inFile, line);
        if (inFile.good()) {
            iss.clear();
            iss.str(line);
            int i=0;
            while (iss.good()){
                iss >> word;
                if(word=="-") goto nextLine;
                if(i==0){
                  member.id=word;
                }else if(i==1){
                    member.name=word;
                }else if(i==2){
                    member.dob=word;
                }else if(i==3){
                    member.pob=word;
                }else if(i==4){
                    member.major=word;
                }else if(i==5){
                    member.university=word;
                }else if(i==6){
                    member.career=word;
                }else if(i==7){
                    member.telephone=word;
                }else if(i==8){
                    member.facebook=word;
                }
                i++;
            }
            AddMember(L2,member.id,member.name,member.dob,member.pob,member.major,member.university,member.career,member.telephone,member.facebook);
        }
        nextLine:
        cout<<" ";
    }
    inFile.close();
}
int main(){

    system("color 0A");

    //login
    login:
    login();

    //loading
    loading();
    system("color 0A");

    List *L1;
    L1=createEmptyList();
    M_list *L2;
    L2=createEmptyM_list();


    //add data to the list
    addProductToList(L1);

    //add member to the list
    addMemberToList(L2);

    //displayMember(L2);
    //displayCoffee(L1);
    //getch();

    mainScreen:
    system("cls");
    int opt=mainDisplay();
    switch(opt){
        case 1:{
            //order product
            orderProduct(L1);
            break;
        }
        case 2:{
            //view selling history
            viewSellingHistory("Selling_History.txt");
            break;
        }
        case 3:{
            //view products
            displayCoffee(L1);
            //viewProduct(L1);
            break;
        }
        case 4:{
            //view member
            viewMember(L2);
            //displayMember(L2);
            break;
        }
        case 5:{
            //Lock program
            int login=manageAccount();
            if(login==1) goto login;
            //goto login;
            break;
        }
        case 6:{
            //exit
            exit(0);
            break;
        }
        default:{
            cout<<"This option does not exist!!!\n";
            cout<<"\nPlease press any keys to select option again!!!";
            getch();
            break;
        }
    }
    goto mainScreen;

	return 0;
}
