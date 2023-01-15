#include<iostream>
#include<iomanip>
#include<cmath>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<sstream>
#include <ctime>
//---------------menu----------------------
int viewProductMenu(){
    cout<<"\t\t======================\n";
    cout<<"\t\t=====View Product=====\n";
    cout<<"\t\t======================\n\n";

    int opt;
    cout<<"\t1.Search Product\n\t2.View All product\n\t3.Exit\n";
    cout<<"\t==>Choose one option:"; cin>>opt;
    return opt;
}

//-----------search product--------------

void searchProduct(List *L1){
    string sID;
    cout<<"Enter ID: "; cin>>sID;

}
void viewProduct(List *L1){
    int opt = viewProductMenu();

    switch(opt){
        case1:{
            //search
            searchProduct(L1);
            break;
        }
        case 2:{
            //view all
            //displayCoffee(L1);
            break;
        }
        case 3:{
           //exit
            break;
    }
}
