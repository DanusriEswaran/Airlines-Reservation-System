#include<iostream>
#include<string.h>
#include<fstream>
#define max 50
using namespace std;
int pass = 100;
int seat[max];
void menu();

/*----------node structure--------------*/
struct node
{
	string fname,lname,way,phonenum,email;
	string passnum;
	int age,passenger;
	int seat_num;
	node *next;
};
struct node *head;
struct node *temp;
struct node *link;

/*----------class structure------------*/
class airline
{
	public:
		airline();
		void create();
		void cancel();
		void search();
		void display();
}air;




bool b1 = false;
bool seatno(int y)
{
    for(int i=0;i<max;i++)
    {
        if(seat[i]== -1)
        {
			b1 = true;
			int j=1;
			while(j<max+1)
			{
				if(seat[j-1] == -1)
					j++;
				else
				{
					cout<<"[" << j << "]"<<"    ";
					if(j%5 ==0)
						cout<<endl;
					j++;
				}
            }
            
	   }
    }
    if(b1==true)
    {
		cout<<"\nThe seat was already booked. \n";
   		cout<<"\nPlease choose another seat !\n"<<endl;		
	}
}

/*--------constructor-------------*/
airline :: airline()
{
	head = NULL;
}
/*---------Create Reservation-------------*/
void airline :: create()
{
	int x;
	temp = new node;
	cout<<"\nenter your first name : ";
	cin>>temp->fname;
	cout<<"\nenter your last name  : ";
	cin>>temp->lname;
	cout<<"\nenter your age at the time of travelling : ";
	cin>>temp->age;
	cout<<"\nenter you mobile number : ";
	cin>>temp->phonenum;
	cout<<"\nenter your passport number : ";
	cin>>temp->passnum;
	cout<<"\nenter your email id : ";
	cin>>temp->email;
	cout<<"\nplease enter the way of travelling \n";
	cout<<"\n(roundtrip | one-way | multi-city) :  ";
	cin>>temp->way;
	do
	{
		cout<<"\nenter your seat number : ";
		cin>>x;
		while(x>max)
		{
			cout<<"\nplease select some other seat...\n";
			cin>>x;	
		}
		if((seat[x-1])>-1)
			b1 = false;
		else
			seatno(x);
	    seat[x-1] = -1;
		temp->seat_num = x;
	}while(b1==true);
	
	pass++;
	temp->passenger = pass;
	cout<<"\n---------------------------------------------\n";
	cout<<"Please note your Passenger id :   '"<<temp->passenger<<"' "<<endl;
	cout<<"\n---------------------------------------------\n";
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
	}
	else
	{
		link = head;
		while(link->next != NULL)
		{
			link = link->next;
		}
		link->next = temp;
	}
}
/*----------display the reservations---------------*/
void airline :: display()
{
	
	temp = head;
	if(temp == NULL)
	{
		cout<<"\n-----------end of reservations----------------\n";
	}
	else
	{
		int count = 1;
		while(temp != NULL)
		{
			cout<<"\nPERSONAL DETAILS\n";
			cout<<"\ns.no       : "<<count<<endl;
			cout<<"\nFirst name : "<<temp->fname;
			cout<<"\nLast name  : "<<temp->lname;
			cout<<"\nage        : "<<temp->age;
			cout<<temp->passnum<<endl;
			cout<<"\nCONTACT DETAILS\n"<<endl;
			cout<<"\nemail             : "<<temp->email<<endl;
			cout<<"\nPhone num         : "<<temp->phonenum<<endl;
			cout<<"\nway of travelling : "<<temp->way<<endl;
			//cout<<"seat number  : ";
			cout<<"\nseat number       : "<<temp->seat_num<<endl;
			//cout<<"passenger :   ";
			cout<<"\npassenger         : "<<temp->passenger<<endl;
			temp = temp->next;
			cout<<endl<<endl;
			count++;
		}
	}
}

/*--------------cancel reservation------------------*/
void airline :: cancel ()
{
	int num;
	cout<<"please enter your passenger id :  ";
	cin>>num;
	node *find = head;
	if(find != NULL)
	{
		if(find->passenger == num)
		{
			node *remove = head;
			head = head->next;
			delete remove;
			seat[0] = 0;
			cout<<"\nThe reservation has been cancelled!!\n";
			return;
		}
		else
		{
			node *newnode , *find;
			newnode = head;
			find = head->next;
			while(find != NULL)
			{
				if(find->passenger == num)
				{
					break;
				}
				newnode = find;
				find = find->next;
				cout<<"\nThe reservation has been cancelled!!\n";
			}
			seat[find->seat_num-1] = 0;
			if(find != NULL)
			{
				newnode->next = find->next;
			}
		}	
	}
	else
	{
		cout<<"\n---------------------------------\n";
		cout<<"\nInvalid Entry\n";
		cout<<"\n---------------------------------\n";
	}
}

/*----------search passenger-------------------*/
void airline :: search()
{
	int search;
	cout<<"enter the passenger id to search : ";
	cin>>search;
	node *find;
	find = head;
	while(find != NULL)
	{
		if(find->passenger == search)
		{
			temp = temp->next;
			cout<<"\nPERSONAL DETAILS\n";
			cout<<"\nFirst name : "<<find->fname;
			cout<<"\nLast name  : "<<find->lname;
			cout<<"\nage        : "<<find->age;
			cout<<"\npassport number : "<<find->passnum<<endl;
			cout<<"\nCONTACT DETAILS\n"<<endl;
			cout<<"\nemail             : "<<find->email<<endl;
			cout<<"\nPhone num         : "<<find->phonenum<<endl;
			cout<<"\nway of travelling : "<<find->way<<endl;	
			cout<<"\nseat number       : "<<find->seat_num<<endl;
			cout<<"\npassenger         : "<<find->passenger<<endl;
			return;
		}
		find = find->next;
	}
	cout<<"\nsorry no such reservation was found......\n";
}

void menu()
{
	int option;
	cout<<"\n\n\n\t\t\t\t\t\t__________________________________________________________\n";
	cout<<"\t\t\t\t\t\t__________________________________________________________\n";
	cout<<"\n\t\t\t\t\t\t\t\tAIRLINES RESERVATION\n";
	cout<<"\t\t\t\t\t\t__________________________________________________________\n";
	cout<<"\t\t\t\t\t\t__________________________________________________________\n";
	do
	{
	cout<<"\nMENUS\n";
	cout<<"\n1.Create Reservation\n";
	cout<<"\n2.Cancel Reservation\n";
	cout<<"\n3.Search Reservation\n";
	cout<<"\n4.Display the list\n";
	cout<<"\n5.Exit\n";
	cout<<"\nOption -  ";
	cin>>option;
	
	switch(option)
	{
		case 1:
			air.create();
			break;
		case 2:
			air.cancel();
			break;
		case 3:
			air.search();
			break;
		case 4:
			air.display();
			break;
	}
    }while(option != 5);
}

void login()
{
	int cnt=0;
	char username[20];
	char password[20];
	do
	{
	cout<<"\nplease enter username : ";
	cin>>username;
	cout<<"\nenter password : ";
	cin>>password;
	
		if(strcmp(username,"team")==0)
		{
			if(strcmp(password,"****")==0)
			{	
				cout<<"login successfull!!";
				return;
			}
			else
			{
				cout<<"\ninvalid password...!\n";
				cnt=0;	
			}
		}
		else
		{
			cout<<"\ninvalid username......!\n";
			cnt=0;
		}
	}while(cnt==0);
	
}
int main()
{
	login();
	menu();
}
