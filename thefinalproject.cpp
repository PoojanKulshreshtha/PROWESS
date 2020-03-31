//HOTEL MANAGEMENT SYSTEM
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<ctype.h>
#include<cstdlib>
using namespace std;
// Creation of class in this project
class account
{
	long int customer_id;
	char customer_name[50];
	char room_type;
	char breakfast;
	char customer_location[100];
	long long phone_num;
	public:
	void create_account()
	{
		cout<<"\n\n====NEW ACCOUNT ENTRY FORM====\n\n";
		cout<<"\nEnter The customer id : ";
		cin>>customer_id;
		cout<<"\nEnter The Name of The customer : ";
		cin>>customer_name;
		cout<<"\nEnter Type of The room (D for delux/C for classic) : ";
		cin>>room_type;
		room_type=toupper(room_type);
		cout<<"\nEnter the customer location:";
		cin>>customer_location;
		cout<<"\nEnter the contact number:";
		cin>>phone_num;
		cout<<"\nEnter confirmation if breakfast needed (Y for yes/N for no) : ";
		cin>>breakfast;
		cout<<"\n\n\nYour Account Created Successfully ..";
	}
	void show_account()
	{
		cout<<"\n\n----ACCOUNT STATUS----\n";
		cout<<"\ncustomer id : "<<customer_id;
		cout<<"\ncustomer Name : "<<customer_name;
		cout<<"\nType of room : "<<room_type;
		cout<<"\nLocation of customer :"<<customer_location;
		cout<<"\nContact number :"<<phone_num;
		cout<<"\nBreakfast needed? : "<<breakfast;
	}
	void modify_account()
	{
		cout<<"\ncustomer id : "<<customer_id;
		cout<<"\nModify customer Name : ";
		cin>>customer_name;
		cout<<"Modify Type of room : ";
		cin>>room_type;
		cout<<"Modify customer location : ";
		cin>>customer_location;
		cout<<"Modify contact number : ";
		cin>>phone_num;
		cout<<"Modify customer need :";
		cin>>breakfast;
	}
	void report()
	{
		cout<<customer_id<<"\t"<<customer_name<<"\t\t"<<room_type<<"\t"<<customer_location<<"\t\t"<<phone_num<<"\t\t"<<breakfast<<endl;
	}
	int retcustomer_id()
	{
		return customer_id;
	}
	char retroom_type()
	{
		return room_type;
	}
	char retbreakfast()
	{
		return breakfast;
	}
};	 	//class ends here


// 	global declaration for stream object, object



 fstream fp;
 account ac;


// 	function to write in file


int write_account()
{
	fp.open("accountt.dat",ios::out|ios::app);
	ac.create_account();
	fp.write((char*)&ac,sizeof(account));
	fp.close();
}


// 	function to read specific record from file



int display_sp()
{
	int n;
	cout<<"\n\n====CUSTOMER DETAILS====";
	cout<<"\n\nEnter the customer id : ";
	cin>>n;
	int flag=0;
	fp.open("accountt.dat",ios::in);					
	while(fp.read((char*)&ac,sizeof(account)))
	{
		if(ac.retcustomer_id()==n)
		{
			ac.show_account();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
		cout<<"\n\nAccount Number does not exist";
	return 0;
}/*
char poojan_1()
{
	cout<<"The customers with delux room type:-";
	fp.open("accountt.dat",ios::in);
	while(fp.read((char*)&ac,sizeof(account)))
	{
		if(ac.retroom_type()=='D')
		{
			ac.show_account();
		}
	}

	fp.close();
	return 0;
}
char poojan_2()
{
	cout<<"The customers who want breakfast in their rooms:-";
	fp.open("accountt.dat",ios::in);
	while(fp.read((char*)&ac,sizeof(account)))
	{
		if(ac.retbreakfast()=='Y')
		{
			ac.show_account();
		}
	}

	fp.close();
	return 0;
}


// 	function to modify record of file

*/
int modify_account()
{
	int no,found=0;
	cout<<"\n\n====MODIFY RECORD====";
	cout<<"\n\nEnter the customer id : ";
	cin>>no;
	fp.open("accountt.dat",ios::in|ios::out);
	while(fp.read((char*)&ac,sizeof(account)) && found==0)
	{
		if(ac.retcustomer_id()==no)
		{
			ac.show_account();
			cout<<"\n\n\n----Enter the New Details----\n";
			ac.modify_account();
			int pos=-1*sizeof(ac);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&ac,sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}
	fp.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
	return 0;
}


// 	function to delete record of file

int delete_account()
{
	int no;
	cout<<"\n\n====Delete Record====";
	cout<<"\n\nEnter The Account No. : ";
	cin>>no;
	fp.open("accountt.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Tempp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&ac,sizeof(account)))
	{
		if(ac.retcustomer_id()!=no)
		{
			fp2.write((char*)&ac,sizeof(account));
		}
	}
	fp2.close();
	fp.close();
	remove("accountt.dat");
	rename("Tempp.dat","accountt.dat");
	cout<<"\n\n\tRecord Deleted ..";
	return 0;
}


// 	function to display all accounts deposit list


int display_all()
{
	fp.open("accountt.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
		return 0;
	}
	cout<<"\n\n\t\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"=======================================================================================\n";
	cout<<"A/c no.\tNAME\t\tType\tLocation\t\tCONTACTno.\t\tBREAKFAST\n";
	cout<<"=======================================================================================\n";
	while(fp.read((char*)&ac,sizeof(account)))
	{
		ac.report();
	}
	fp.close();
	return 0;
}   
//***************************************************************
// 	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
	int ch;
	//intro();
	cout<<"\n\t\t\t";					//gotoxy(5,7);
	cout<<"\t\t\t\t==============================";
	cout<<"\n\t\t   \t\t";			//gotoxy(18,11);
	cout<<"\t\t\t\t     HOTEL";
	cout<<"\n\t\t\t\t";			//gotoxy(15,14);
	cout<<"\t\t\t\t  MANAGEMENT";
	cout<<"\n\t\t  \t\t";		//gotoxy(17,17);
	cout<<"\t\t\t\t    SYSTEM";
	cout<<"\n\t\t\t";		//gotoxy(5,21);
	cout<<"\t\t\t\t==============================";
	cout<<"\n\n\n\t\t\t";	//gotoxy(5,24);
	cout<<"\t\t\t\tMADE BY : POOJAN KULSHRESHTHA";
	cout<<"\n\t\t\t\t\t\t\t          NUPUR RAJESHIRKE";
	cout<<"\n\t\t\t\t\t\t\t          NEEL RAYAL";
	do
	{
		cout<<"\n\n\n\t\t\t\t\t\t\tMAIN MENU";
		cout<<"\n\n\t\t\t\t\t\t\t01. NEW ACCOUNT";
		cout<<"\n\n\t\t\t\t\t\t\t02. BALANCE ENQUIRY";
		cout<<"\n\n\t\t\t\t\t\t\t03. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t\t\t\t\t\t\t04. CLOSE AN ACCOUNT";
		cout<<"\n\n\t\t\t\t\t\t\t05. MODIFY AN ACCOUNT";
		cout<<"\n\n\t\t\t\t\t\t\t    ****SPECIFIC TASK GROUP MEMBER 1****";
		cout<<"\n\n\t\t\t\t\t\t\t06. ALL CUSTOMERS HAVING ROOM TYPE AS DELUX";
		cout<<"\n\n\t\t\t\t\t\t\t07. ALL THE CUSTOMERS WHO ARE CHECKING OUT TODAY";
		cout<<"\n\n\t\t\t\t\t\t\t08. ALL THE CUSTOMERS WHO WANT BREAKFAST SERVICE IN ROOM:";
		cout<<"\n\n\t\t\t\t\t\t\t    ****SPECIFIC TASK GROUP MEMBER 2****";
		cout<<"\n\n\t\t\t\t\t\t\t09. TO BE DONE BY NUPUR";
		cout<<"\n\n\t\t\t\t\t\t\t10. TO BE DONE BY NUPUR";
		cout<<"\n\n\t\t\t\t\t\t\t11. TO BE DONE BY NUPUR";
		cout<<"\n\n\t\t\t\t\t\t\t    ****SPECIFIC TASK GROUP MEMBER 3****";
		cout<<"\n\n\t\t\t\t\t\t\t12. TO BE DONE BY NEEL";
		cout<<"\n\n\t\t\t\t\t\t\t13. TO BE DONE BY NEEL";
		cout<<"\n\n\t\t\t\t\t\t\t14. TO BE DONE BY NEEL";
		cout<<"\n\n\t\t\t\t\t\t\t15. EXIT";
		cout<<"\n\n\t\t\t\t\t\t\tSelect Your Option (1-15) ";
		cin>>ch;
		switch(ch)
		{
			case '1': write_account();
				break;
			case '2': display_sp();
				break;
			case '3': display_all();
				break;
			case '4': delete_account();
				break;
			case '5': modify_account();
				break;
/*			case '6': poojan_1();
				break;
			case '7': poojan_2();
				break;
		/*	case '8': poojan_3();
				break;
			case '9': nupur_1();
				break;
			case '10': nupur_2();
				break;
			case '11': nupur_3();
				break;
			case '12': neel_1();
				break;
			case '13': neel_2();
				break;			*/
			case '8': exit(0);
			default : cout<<"\a";
		}
	}while(ch!='8');
	return 0;
}


