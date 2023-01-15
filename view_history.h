#include<iostream>
#include<iomanip>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<sstream>

void viewHistoryHeader(){
    cout<<"\t\t=============================\n";
	cout<<"\t\t=======SELLING HISTORY=======\n";
	cout<<"\t\t=============================\n\n";
}

void viewSellingHistory(string filename){
    stay:
    system("cls");
    viewHistoryHeader();
    fstream inFile;
    inFile.open(filename,ios::in);
    if(!inFile){
        cout<<"Cannot open file!!!";
    }
    string line;
    //istringstream iss;
    while (!inFile.eof()){
        getline (inFile, line);
        cout<<line<<endl;
    }
    inFile.close();

    cout<<"\n\t==>Press ESC Key to Exit";
    int key=getch();

    if(key!=27) goto stay;
}
