#include<iostream>
#include <iomanip>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<sstream>
//-----------------coffee List-----------------//
void header(){
    cout<<setw(10)<<"ID"<<setw(12)<<"NAME"<<setw(13)<<"PRICE"<<endl;
}

struct Element{
    string name;
    string id;
    float price;

    Element *next;
};

struct List{
    int n;
    Element *head;
    Element *tail;
};

List *createEmptyList(){
    List *L=new List;

    L->n=0;
    L->head=NULL;
    L->tail=NULL;

    return L;
}

void AddCoffee(List *L,string id,string name,float price){
    //add from begin
    Element *newCoffee;
    newCoffee= new Element;

    newCoffee->id=id;
    newCoffee->name=name;
    newCoffee->price=price;

    newCoffee->next= NULL;

    if(L->n==0){
        L->head=newCoffee;
        L->tail=newCoffee;
        L->n=L->n+1;
    }else{
        newCoffee->next=L->head;
        L->head=newCoffee;
        L->n=L->n+1;
    }
}
void removeCoffee(List *L){
    //remove from begin
    Element *tmp;

    tmp=L->head;
    if(L->n==0){
        cout<<"There is no coffee in the list to remove!!!\n";
    }else{
        L->head=L->head->next;
        delete tmp;
        L->n=L->n-1;
    }
}

void displayCoffee(List *L){
    //display from begin

    Element *tmp;
    stay:
    system("cls");
    tmp=L->head;
    header();
    while(tmp!=NULL){
        cout<<setw(10)<<tmp->id<<setw(12)<<tmp->name<<setw(12)<<tmp->price<<"$"<<endl;
        tmp=tmp->next;
    }

    cout<<"\n\t==>Press ESC Key to Exit";
    int key=getch();

    if(key!=27) goto stay;
}










