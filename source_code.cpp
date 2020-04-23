#include<iostream>
#include<conio.h>
#include<iomanip>
#include<cstring>
#include<string> 
#include<fstream>
#include <cstdlib>
using namespace std;
int options,options_st,options_tr,options_seat,economy,lowac,business;
string des,timing,seat; 
double ticket_no;
void record(string des, string train, int fare, string timing,double ticket_no,string seat);
double ticket();
void login();
void interface_front();
void main()
{
	 login();
	interface_front();

	_getch();
}
void login()
{
	string username,password;
	cout<<"\t\t*******************PAKISTAN RAILWAY (2018)******************* \n \t\t\t  ------Employee Login Screen.------  \n"<<endl;
	cout<<"Project by:\n\t\t\t\t Muhammad Abbas Bangash\n \t\t\t\tBS. Software Engineering(I)\n \t\t\t\t"<<setw(10)<<"Section A "<<endl<<" \t\t\t\tCMS ID:051-18-0007"<<endl;
	cout<<"\t***\t***\t***\t***\t***\t***\t***\t***\t***\t*** "<<endl;
	cout<<"-----------------------------------------------------------------------------------"<<endl;
	do{
		cout<<"Enter username please: "<<endl;
			getline(cin,username);
			if(username=="mabbasbangash" )
				{
					cout<<"Enter password:"<<endl;
					cin>>password;
					cin.ignore();
				}
	}
	while(username!="mabbasbangash" || password != "12345");
	system("cls");
	int options=0;
	ifstream start_interface;
	char railway;
	start_interface.open("LOGO.txt");
	while(!start_interface.eof())
	{
	start_interface.get(railway);
	cout<<railway;
	} 
	cout<<setw(10)<<"Enter any key to proceede..."<<endl;
	_getch();
	system("cls");
}
void interface_front()
{
	int options,options_st,options_tr,options_seat,economy,lowac,business;
	string des,timing,train; 
	double ticket_no;
	bool flag=true;
	ifstream open_obj;
	cout<<setw(10)<<"\t\t\t\t[1] Press 1 for booking a new ticket.\n"<<endl;
	cout<<setw(10)<<"\t\t\t\t[2] Press 2 for checking your ticket(s) detail using ticket number.\n"<<endl;
	cout<<setw(10)<<"\t\t\t\t[3] Press 3 to EXIT!\n"<<endl;
	cin>>options;
	system("cls");
	switch(options)
	{
			case 1:
			{	
				cout<<"\t\tSelect ur destination from the following cities:\n";
				cout<<"\t\t\t[1] HYDERABAD\n"
					  "\t\t\t[2] NAWABSHAH\n"
					  "\t\t\t[3] ROHRI\n"
					  "\t\t\t[4] MULTAN\n"
					  "\t\t\t[5] LAHORE\n"
					  "\t\t\t[6] RAWALPINDI\n"
					  "\t\t\t[7] PESHAWAR\n";
				cin>>options_st;
				system("cls");
				while(flag)
				{	
					cout<<"\t\tPlease Select your train."<<endl;
					cout<<"\t\t\t[1] Akbar\n";
					cout<<"\t\t\t[2] Jaffar\n";
					cout<<"\t\t\t[3] Shalimar\n";
					cout<<"\t\t\t[4] Greenline(Premiuim Fast Train)\n";
					cin>>options_tr;
					system("cls");
					switch(options_tr)
					{
					case 1:
					open_obj.open("akbar.txt");
					train="AKBAR";
					flag=false;
					break;
					case 2:
					open_obj.open("jaffar.txt");
					train="Jaffar";
					flag=false;
					break;
					case 3:
					open_obj.open("shalimar.txt");
					train="Shalimar";
					flag=false;
					break;
					case 4:
					open_obj.open("greenline.txt");
					train="Greenline";
					flag=false;
					break;
					default:
						cout<<"Invalid entry!"<<endl;
					}
				}
					for(int i=1;i<=options_st;i++)
					{
						open_obj>>des>>economy>>lowac>>business>>timing;
					}
					ticket_no=ticket();
					flag=true;
					while(flag)
					{
					cout<<"\t\tSelect your ticket-type."<<endl;
					cout<<"\t\t\t[1] Economy\n"
						  "\t\t\t[2] Lower Ac\n"
					      "\t\t\t[3] Business\n";
					cin>>options_seat;
					system("cls");
					cout<<"Ticket Booking Successful!"<<endl;
					cout<<"Ticket Details: ";
				switch(options_seat)
				{	
				case 1:
					cout<<"\n\t\tDestination: "<<des;
					cout<<"\n\t\tEconomy";
					cout<<"\n\t\tFair:Rs. "<<economy;
					cout<<"\n\t\tTiming: "<<timing;
					cout<<"\n\t\tTicket No: "<<ticket_no;
					seat="Economy Class";
					record(des,train,economy,timing,ticket_no,seat);
					flag=false;
					break;
				case 2:
					cout<<"\n\t\tDestination: "<<des;
					cout<<"\n\t\tLower Ac";
					cout<<"\n\t\tFair:Rs. "<<lowac;
					cout<<"\n\t\tTiming: "<<timing;
					cout<<"\n\t\tTicket No:"<<ticket_no;
					seat="Lower AC Class";
					record(des,train,lowac,timing,ticket_no,seat);
					flag=false;
					break;
				case 3:
					cout<<"\n\t\tDestination: "<<des;
					cout<<"\n\t\tBusiness";
					cout<<"\n\t\tFair:Rs. "<<business;
					cout<<"\n\t\tTiming: "<<timing;
					cout<<"\n\t\tTicket No:"<<ticket_no;
					seat="Business Class";
					record(des,train,business,timing,ticket_no,seat);
					flag=false;
					break;
				default:
					cout<<" Invalid Entry!"<<endl;
					break;
				}
					}
				break;
			}	
			case 2:
				{
					string line;
					bool isFound=false;
					int ticket_number,search_ticket;
					ifstream open_obj;
					open_obj.open("record.txt");
					getline(open_obj,line);
					cout<<"Enter the ticket number: "<<endl;
					cin>>search_ticket;

					while(!open_obj.eof())
					{
						open_obj>>ticket_number;
						getline(open_obj,line);
						if(search_ticket == ticket_number)
						{
							cout<<ticket_number;
							cout<<line<<endl;
							isFound=true;
							break;
						}
					}
					if(!isFound)
						{
						cout<<"No ticket Found on the ticket number you provided!"<<endl;
						break;
						}		
					break;
			}
			case 3:		
				{
				 exit(0) ;
				}
			}
	}
double ticket()
{
	double ticket;
	ifstream read("ticket.txt");
	read>>ticket;
	read.close();
	ticket+=19;
	ofstream write("ticket.txt");
	write<<ticket;
	write.close();
	return ticket;
}
void record(string des, string train,int fare, string timing,double ticket_no,string seat)
{
	ofstream open_obj;
	open_obj.open("record.txt",ios::app);
	open_obj<<setw(10)<<ticket_no<<"   "<<setw(10)<<train<<"   "<<setw(10)<<des<<"   "<<setw(10)<<timing<<"   "<<setw(10)<<seat<<"   "<<setw(10)<<"Rs."<<fare<<endl;
	open_obj.close();
}
