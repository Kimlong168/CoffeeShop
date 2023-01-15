#include<iostream>
#include <iomanip>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<sstream>
//-----------------Member List-----------------//
struct Member{
    string id;
    string name;
    string dob;
    string pob;
    string major;
    string university;
    string career;
    string telephone;
    string facebook;
    Member *next;
};

struct M_list{
    int n;

    Member *head;
    Member *tail;
};

M_list *createEmptyM_list(){
    M_list *L=new M_list;

    L->n=0;
    L->head=NULL;
    L->tail=NULL;

    return L;
}


void AddMember(M_list *L,string id,string name,string dob,string pob,string major,string university,string career,string telephone,string facebook){
    //add from begin
    Member *newMember;
    newMember= new Member;

    newMember->id=id;
    newMember->name=name;
    newMember->dob=dob;
    newMember->pob=pob;
    newMember->major=major;
    newMember->university=university;
    newMember->career=career;
    newMember->telephone=telephone;
    newMember->facebook=facebook;

    newMember->next= NULL;

    if(L->n==0){
        L->head=newMember;
        L->tail=newMember;
        L->n=L->n+1;
    }else{
        newMember->next=L->head;
        L->head=newMember;
        L->n=L->n+1;
    }
}


void displayMember(M_list *L){
    //display from begin
    Member *tmp;
    stay:
    system("cls");
    tmp=L->head;
    while(tmp!=NULL){
        cout<<"\n\tID             : "<<tmp->id<<endl;
        cout<<"\tName           : "<<tmp->name<<endl;
        cout<<"\tDate of Birth  : "<<tmp->dob<<endl;
        cout<<"\tPlace of Birth : "<<tmp->pob<<endl;
        cout<<"\tMajor          : "<<tmp->major<<endl;
        cout<<"\tUniversity     : "<<tmp->university<<endl;
        cout<<"\tCareer Goal    : "<<tmp->career<<endl;
        cout<<"\tTelephone      : "<<tmp->telephone<<endl;
        cout<<"\tFacebook       : "<<tmp->facebook<<endl<<endl<<endl;
        tmp=tmp->next;
    }

    cout<<"\n\t==>Press ESC Key to Exit";
    int key=getch();

    if(key!=27) goto stay;
}


