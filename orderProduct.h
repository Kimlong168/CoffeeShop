#include<iostream>
#include<iomanip>
#include<cmath>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<sstream>
#include <ctime>

struct userInput{
    string id;
    int quantity;
};

struct boughtProduct{
    string name;
    string id;
    float price;
    int quantity;
    float totalPrice;
};

//----------------------global variable
const int size=20;
int index=0,check=0;
float totalPayment=0;
float discount=0;
struct userInput user;
struct boughtProduct buy[size];

//-----------------------display menu
int menu(){
	cout<<"\t\t==================\n";
	cout<<"\t\t=======MENU=======\n";
	cout<<"\t\t==================\n\n";

    int opt;
	cout<<"\t1.Drink\n";
	cout<<"\t2.Food\n";
    if(check==1) cout<<"\t3.Order now\n";
	cout<<"\t0.Exit\n";
	cout<<"\t==>Select one option to order:"; cin>>opt;
	return opt;
}
void productHeader(){
    cout<<setw(10)<<"----------------------------------------------\n";
    cout<<setw(10)<<"ID"<<setw(12)<<"NAME"<<setw(13)<<"PRICE"<<endl;
    cout<<setw(10)<<"----------------------------------------------\n";
}
void invoiceHeader(){
    cout<<setw(10)<<"-------------------------------------------------------------\n";
    cout<<setw(10)<<"ID"<<setw(12)<<"NAME"<<setw(16)<<"QUANTITY"<<setw(14)<<"PRICE"<<endl;
    cout<<setw(10)<<"-------------------------------------------------------------\n";
}

//------------------------read data from file to display
void displayProduct(string filename){
    system("cls");
    fstream inFile;
    inFile.open(filename,ios::in);
    if(!inFile){
        cout<<"Cannot open file!!!";
    }
    string line, word;
    istringstream iss;
    productHeader();
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
                    cout<<setw(10)<<word;
                }else if(i==1){
                    cout<<setw(12)<<word;
                }else if(i==2){
                    cout<<setw(13)<<word;
                }
                i++;
            }
            cout<<endl;
        }
        nextLine:
        cout<<"";
    }
    cout<<setw(10)<<"----------------------------------------------\n";
    inFile.close();
}

//--------------------------to process buying product
void buyProduct(List *L1){

    do{
        cout<<"\n\tEnter id of product to order:"; cin>>user.id;
        Element *tmp;
        tmp=L1->head;
        int check_product=0;

        while(tmp!=NULL){
            if(user.id==tmp->id){

                cout<<"\tQuantity: "; cin>>user.quantity;
                if(user.quantity==0){
                    check_product=1;
                    goto cancle;
                }

                //in case we re-input the same code of product more than one time
                for(int i=0;i<index;i++){
                    if(user.id==buy[i].id){
                        buy[i].quantity+=user.quantity;
                        buy[i].totalPrice= buy[i].quantity * buy[i].price;
                        index--;
                        goto continue_buy;
                    }
                }

                buy[index].id=tmp->id;
                buy[index].name=tmp->name;
                buy[index].price=tmp->price;
                buy[index].quantity=user.quantity;
                buy[index].totalPrice= buy[index].quantity * buy[index].price;

                continue_buy:

                check_product=1;
                check=1;
                index++;
            }
            cancle:
            tmp=tmp->next;
        }
        if(check_product==0 && user.id!="0"){
            cout<<"\t    No Product\n";
        }
    }while(user.id!="0");
}

//----------------------------------find change function
void calculate_change(float totalPayment){
    float cash,change,change_kh,rate;
    float KHexchange_rate=4000;

    fstream inFile;
    inFile.open("KHexchange_rate.txt",ios::in);
    if(!inFile){
        cout<<"Cannot open file!!!";
    }
    string line;
    istringstream iss;
    while (!inFile.eof()){
        getline (inFile, line);
        KHexchange_rate=stof(line);
    }
    inFile.close();

    cout<<"\n\t\t>>>>>Choose Currency<<<<<\n";
    cout<<"\t1.Riel\n\t2.Dollar\n\t3.Other\n";
    int opt=getch();

    switch(opt){
        case 49:{
            //riel
            cout<<"\n\tExchange Rate:"<<KHexchange_rate<<" R"<<endl;
            cout<<"\n\tTotal Payment(R): "<<totalPayment*KHexchange_rate<<" R";
            cout<<"\n\tEnter Cash(R): "; cin>>cash;
            change=(cash/KHexchange_rate) - totalPayment;
            break;
        }
        case 50:{
            //dollar
            cout<<"\n\tExchange Rate:"<<KHexchange_rate<<" R"<<endl;
            cout<<"\n\tEnter Cash($): "; cin>>cash;
            change=cash - totalPayment;
            break;
        }
        case 51:{
            //other
            cout<<"\n\tEnter Exchange Rate:"; cin>>rate;
            cout<<"\n\tTotal Payment(?): "<<totalPayment*rate;
            cout<<"\n\tEnter Cash(?): "; cin>>cash;
            change=(cash/rate) - totalPayment;
        }
    }
    change_kh= change*KHexchange_rate;
    cout<<"\n\tChange(R) : "<<round(change_kh)<<" R"<<endl;
    cout<<"\tChange($) : "<<change<<" $"<<endl;
}

//------------------------date and time function
void displayDate(){
    time_t tim = time(0);
    tm *gottime = localtime(&tim);
    bool checkAM=true;
    int hour;

    //check AM or PM
    if(gottime->tm_hour>12){
        hour=gottime->tm_hour-12;
        checkAM=false;
    }else{
        hour=gottime->tm_hour;
    }
    if(gottime->tm_hour==12) checkAM=false;
    if(gottime->tm_hour==24) checkAM=true;

    cout<<"\n\tDate: ";
    if(gottime->tm_mon+1<10) cout<<"0";
    cout<<gottime->tm_mon+1<<"\\";
    if(gottime->tm_mday<10) cout<<"0";
    cout<<gottime->tm_mday<<"\\";
    cout<<gottime->tm_year+1900<<"\t\t";

    cout<<"Time: "<<hour<<":";
    if(gottime->tm_min<10) cout<<"0";
    cout<<gottime->tm_min<<":";
    if(gottime->tm_sec<10) cout<<"0";
    cout<<gottime->tm_sec;
    if(checkAM==true) cout<<" AM\n";
    else cout<<" PM\n";
}


//-------------------------write to history file
void writeHistory(){
    fstream outFile;
    outFile.open("Selling_History.txt",ios::app);
    if(!outFile){
        cout<<"Error in creating file"<<endl;
    }

    //date and time
    time_t tim = time(0);
    tm *gottime = localtime(&tim);
    bool checkAM=true;
    int hour;

    //check AM or PM
    if(gottime->tm_hour>12){
        hour=gottime->tm_hour-12;
        checkAM=false;
    }else{
        hour=gottime->tm_hour;
    }
    if(gottime->tm_hour==12) checkAM=false;
    if(gottime->tm_hour==24) checkAM=true;

    outFile<<"\n\tDate: ";
    if(gottime->tm_mon+1<10) outFile<<"0";
    outFile<<gottime->tm_mon+1<<"\\";
    if(gottime->tm_mday<10) outFile<<"0";
    outFile<<gottime->tm_mday<<"\\";
    outFile<<gottime->tm_year+1900<<"\t\t";

    outFile<<"Time: "<<hour<<":";
    if(gottime->tm_min<10) outFile<<"0";
    outFile<<gottime->tm_min<<":";
    if(gottime->tm_sec<10) outFile<<"0";
    outFile<<gottime->tm_sec;
    if(checkAM==true) outFile<<" AM\n";
    else outFile<<" PM\n";

    outFile<<setw(10)<<"-------------------------------------------------------------\n";
    outFile<<setw(10)<<"ID"<<setw(12)<<"NAME"<<setw(16)<<"QUANTITY"<<setw(14)<<"PRICE"<<endl;
    outFile<<setw(10)<<"-------------------------------------------------------------\n";
    for(int i=0;i<index;i++){
        outFile<<setw(10)<<buy[i].id<<setw(12)<<buy[i].name<<setw(16)<<buy[i].quantity<<setw(13)<<buy[i].price<<"$"<<endl;
    }
    outFile<<setw(10)<<"-------------------------------------------------------------\n";
    outFile<<"\n\tDiscount:"<<discount<<" %"<<endl;
    outFile<<"\tTotal payment:"<<totalPayment<<" $"<<endl<<endl<<endl;

    outFile.close();
}

//---------------------to process ordering product
int order(){
    int opt;

    //input discount
    cout<<"\n\tDiscount(%):"; cin>>discount;
    //discount();

    system("cls");
    //data and time
    displayDate();

    //print invoice
    invoiceHeader();
    for(int i=0;i<index;i++){
        cout<<setw(10)<<buy[i].id<<setw(12)<<buy[i].name<<setw(16)<<buy[i].quantity<<setw(13)<<buy[i].price<<"$"<<endl;
        totalPayment+=buy[i].totalPrice;
    }
    cout<<setw(10)<<"-------------------------------------------------------------\n";

    //find total payment
    totalPayment*=(1-(discount/100));
    cout<<"\n\tDiscount     : "<<discount<<" %"<<endl;
    cout<<"\tTotal Payment: "<<totalPayment<<" $"<<endl;

    //find change
    cout<<"\n\tPress key TAB to enable find change function or Press any keys to continue";
    int key=getch();

    if(key==9){
        calculate_change(totalPayment);
    }

    cout<<"\n\n\tDo you want to buy more or exit?(Buy=1,Exit=0):"; cin>>opt;

    if(opt==0){
        //write to file
        writeHistory();

        //reset value to store data of new invoice
        discount=0;
        totalPayment=0;
        index=0;

    }else if(opt==1){
        totalPayment=0;
    }
    return opt;
}


//---------------------------major function of main menu
void orderProduct(List *L1){
	menu:
    system("cls");
    int opt=menu();
    switch (opt){
        case 1:{
            //drink
            displayProduct("drink.txt");
            buyProduct(L1);
            goto menu;
        }
        case 2:{
            //food
            displayProduct("food.txt");
            buyProduct(L1);
            goto menu;
        }
        case 3:{
            //order
            int op=order();
            if(op==0){
                break;
            }
            goto menu;
        }
        case 0:{
            //exit
        break;
        }
        default:{
    		cout<<"\tThis option does not exist!!!\n";
			cout<<"\n\tPlease press any keys to select option again!!!";
      		getch();
			goto menu;
		}
    }

}
