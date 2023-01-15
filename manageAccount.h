
int manageAccountMenu(){
    system("cls");
    cout<<"\t\t============================\n";
	cout<<"\t\t=======MANAGE ACCOUNT=======\n";
	cout<<"\t\t============================\n\n";

	int opt;
	cout<<"\t\t1.Log Out\n";
	cout<<"\t\t2.Change Password\n";
	cout<<"\t\t3.Delete Account\n";
	cout<<"\t\t0.Exit\n";
	cout<<"\t\tPlease select one option:"; cin>>opt;
	return opt;
}

int changPassword(){
    inputAgain:
    system("cls");
    cout<<"\t\t\t============================================\n";
	cout<<"\t\t\t=======WELOCOME TO COFFEE SHOP SYSTEM=======\n";
	cout<<"\t\t\t============================================\n\n";

	string username,password,correct_username,correct_password;
	cout<<"\t\t\t|>>>>>>>>>>|Change Password|<<<<<<<<<<|\n\n";
	cout<<"\t\t\tPlease input your current username and password\n\n";
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

    string newPassword;
    if(correct_password==password && correct_username==username){
        system("cls");
        fstream outFile;
        outFile.open("login.txt",ios::out);
        cout<<"\t\t\tPlease Input new password\n\n";
        reinputPassword:
        cout<<"\t\t\tNew Password:"; cin>>newPassword;

         //check strong password
        if(newPassword.length()<8){
            cout<<"\n\t\t\tYour password is not strong enough\n";
            goto reinputPassword;
        }else{
            outFile<<username<<endl;
            outFile<<newPassword<<endl;
            system("cls");
            cout<<"\n\n\t\t\tYour Password have been changed successfully!!!\n";
            getch();
        }
        outFile.close();
        return 1;
    }else{
        system("color 0C");
        cout<<"\n\n\t\t   Your Username and Password are incorrect\n\n\n";
        cout<<"\t\t =>Please Input Username and Password again or press 0 to exit";
        int exit=getch();
        system("color 0A");
        if(exit==48) return 0;
        goto inputAgain;
    }

}

int deleteAccount(){
    inputAgain:
    system("cls");
    cout<<"\t\t\t============================================\n";
	cout<<"\t\t\t=======WELOCOME TO COFFEE SHOP SYSTEM=======\n";
	cout<<"\t\t\t============================================\n\n";

	string username,password,correct_username,correct_password;
	cout<<"\t\t\t|>>>>>>>>>>|Delete Account|<<<<<<<<<<|\n\n";
	cout<<"\t\t\tPlease input your current username and password\n\n";
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
        cout<<"\n\n\t\tYour account have been deleted successfully!!!\n";
        return 1;
    }else{
        system("color 0C");
        cout<<"\n\n\t\t   Your Username and Password are incorrect\n\n\n";
        cout<<"\t\t =>Please Input Username and Password again or press 0 to exit";
        int exit=getch();
        system("color 0A");
        if(exit==48) return 0;
        goto inputAgain;
    }
}

int manageAccount(){
    again:
    int opt= manageAccountMenu();

    switch(opt){
        case 1:{
            //log out
            return 1;
        }
        case 2:{
            //change password
            int check=changPassword();
            if(check==1) return 1;
            else return 0;
            break;
        }
        case 3:{
            //delete account
            system("cls");
            cout<<"\n\n\n\t\t\t Are you sure you want to delete your account permanently?(Enter=Yes)\n";

            int check=getch();
            if(check==13){
                int del=deleteAccount();
                if(del==1){
                    remove("login.txt");
                    return 1;
                }else{
                    return 0;
                }
            }
        }
        case 0:{
            return 0;
        }
        default:{
            cout<<"  This option doesn't exist!!!\n\n";
            cout<<"\t==>Press Any Keys to Choose Option again!!!";
            getch();
            goto again;
            cout<<" ";
        }
    }
}
