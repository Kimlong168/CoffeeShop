#include<iostream>
int mainDisplay(){
	cout<<"\t\t=========================\n";
	cout<<"\t\t=======COFFEE SHOP=======\n";
	cout<<"\t\t=========================\n\n";

	int opt;

	cout<<"\t1.Order Product\n";
	cout<<"\t2.View Selling History\n";
	cout<<"\t3.View All Products\n";
	cout<<"\t4.View Member\n";
	cout<<"\t5.Manage Account\n";
	cout<<"\t6.Exit program\n";
	cout<<"\t==>Select one option:"; cin>>opt;
	return opt;
}
