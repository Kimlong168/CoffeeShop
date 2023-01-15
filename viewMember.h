#include<iostream>
#include<iomanip>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<sstream>
using namespace std;
int viewMemberMenu(){
    cout<<"\t\t=========================\n";
	cout<<"\t\t=======VIEW MEMBER=======\n";
	cout<<"\t\t=========================\n\n";

	cout<<"\t1.CHANN KIMLONG\n";
	cout<<"\t2.CHOUB CHHENGLUN\n";
	cout<<"\t3.CHEA CHUNGHEANG\n";
	cout<<"\t4.CHAM STEYTOCH\n";
	cout<<"\t5.BOU TAIIHOR\n";
	cout<<"\t0.EIXT\n";
	cout<<"\tPlease select one option to view:";
    int opt=getch();
    return opt;
}
void searchAndDisplay(M_list *L2,string id){
    Member *tmp;
    tmp=L2->head;
    system("cls");
    cout<<"\t\t================================\n";
	cout<<"\t\t=======MEMBER INFORMATION=======\n";
	cout<<"\t\t================================\n\n";
    while(tmp!=NULL){
        if(tmp->id==id){
            cout<<"\tName           : "<<tmp->name<<endl;
            cout<<"\tDate of Birth  : "<<tmp->dob<<endl;
            cout<<"\tPlace of Birth : "<<tmp->pob<<endl;
            cout<<"\tMajor          : "<<tmp->major<<endl;
            cout<<"\tUniversity     : "<<tmp->university<<endl;
            cout<<"\tCareer Goal    : "<<tmp->career<<endl;
            cout<<"\tTelephone      : "<<tmp->telephone<<endl;
            cout<<"\tFacebook       : "<<tmp->facebook<<endl<<endl<<endl;
            break;
        }
        tmp=tmp->next;
    }
}

void viewMember(M_list *L2){

    again:
    system("cls");
    int opt = viewMemberMenu();

    switch(opt){
       case  49:{
           //chann kimlong
            searchAndDisplay(L2,"1");
            break;
       }
       case  50:{
           //choub chhenglun
           searchAndDisplay(L2,"2");
            break;
       }
       case  51:{
           //chea chungheang
           searchAndDisplay(L2,"3");
            break;
       }
       case  52:{
           //cham sreytoch
           searchAndDisplay(L2,"4");
            break;
       }
       case  53:{
           //bou taiihor
           searchAndDisplay(L2,"5");
            break;
       }
       case  48:{
            //exit
            goto exit;
            break;
       }
       default:{
            cout<<"  This option doesn't exist!!!\n\n";
       }
    }
    cout<<"\t==>Press Any Keys to Choose Option again!!!";
    getch();
    goto again;
    exit:
    cout<<" ";
}
