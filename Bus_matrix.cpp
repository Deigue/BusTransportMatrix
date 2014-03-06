#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

class bus
{      	protected:

	int seat[15][4];
	char name[16];
	char dest[50];
	char time[20];
	public:
	bus(char n[], char d[], char t[])      //constructor
	{
	strcat(name,n);
	strcat(dest,d);
	strcat(time,t);
	 for(int i=0;i<8,i++)
	 {   for(int j=0;j<4;j++)
		seat[i][j]=0;
	}
	}
	void display()
	{
	puts(name);
	cout<<"\t ";
	puts(dest);
	cout<<"\t ";
	puts(time);
	}
	void menu()
	{ st:
	cout<<"\n1.Reservation\n";
	cout<<"2.Cancellation\n";
	cout<<"3.Seat Listing(admin)\n";
	cout<<"4.Goto Main menu\n";
	int ch;
	cout<<"Enter your choice(1-4)";
	cin>>ch;
	switch(ch)
	{
	case 1: person P;
		P.reserve();
		ofstream fout("List.dat",ios::binary|ios::out|ios::app);
		fout.write((char*)&P,sizeof(P));
		break;
	case 2: person P;
		char fno[50];
		cout<<"\nEnter passenger name";
		gets(fno);
		ifstream fio("List.dat",ios::binary|ios::in);
		ofstream file("temp.dat",ios::binary|ios::out);
		char found='f', confirn='n';

		while(fio)
		{
			fio.read((char*)&P,sizeof(P));

			if(strcmpi(fno,P.fname)==0)

			{ P.display();
			found='t';
			cout<<"\n Are you sure you want to delete?";
			cin>>confirm;
			if(confirm!='y')
			file.write((char*)&P,sizeof(P));
			}
			else
			file.write((char*)&P,sizeof(P));

		}
		remove("bus.dat");
		rename("temp.dat","bus.dat");

		break;
	case 3: ifstream fin;
		fin.open("List.dat",ios::binary|ios::in);
		while(fin)
		{ fin.read((char*)&P,sizeof(P));
		 puts(fname);
		 cout<<"\t";
		 puts(linit);
		 cout<<"\t Row "<<row<<" Col "<<col<<"\n";
		}
		break;
	case 4: goto mainmen:
		break;
	default: cout<<"\nEnter valid number 1 to 4 ";
		 goto st;
	}





       ~bus();



};

class bus2 : public bus
{
	int seat[8][4];
	bus2(char n[], char d[], char t[]):bus( n[],d[],t[])
	{ for(int i=0;i<8,i++)
	{ 	for(int j=0;j<4;j++)
			seat[i][j]=0;
	}
	~bus2();

};



class person
	{    private:
		char fname[30];
		char linit;
		int row;
		int col;
	     public:
	     void display()
	     {puts(fname);
	     cout<<"\n";
	     cout<<linit;
	     cout<<"\n Row number ="<<row;
	     cout<<"\n Column number ="<<col;
	     }
	     void reserve()
	     {cout<<"\nEnter passengers name";
	      gets(fname);
	      cout<<"\nEnter passengers last initial";
	      cin>>linit;
	      entr:
	      cout<<"Enter row number of seat (1-15)";
		      cin>>row;
	      cout<<"Enter column number of seat(1-4)";
		      cin>>col;
	      if(seat[row][col]==1)
	      { cout<<"\nSeat is already occupied . Chose another position";
		goto entr;
	      }
	      seat[row][col]=1;

	     }
};



void main()
{
	clrscr();
	cout<<"\t GK Bus reservation software \n\n";
	mainmen:
	cout<<"Menu:";
	bus A("MH56343","Nagpur","10:00"),B("KA56382","Bangalore","12:00");
	bus C("TN56918","Hyderabad","15:00");
	bus2 D("MH82749","Pune","17:00"),E("MH91238","Bhusawal","09:00");
	bus2 G("JK21214","Chandigarh","07:00");

	cout<<"\n\n   Bus Reg no. \t Destination \t Departure Time \n\n";
	cout<<"1."<<A.display()<<"\n";
	cout<<"2."<<B.display()<<"\n";
	cout<<"3."<<C.display()<<"\n";
	cout<<"4."<<D.display()<<"\n";
	cout<<"5."<<E.display()<<"\n";
	cout<<"6."<<G.display()<<"\n\n";
	cout<<"7.Exit the Program\n";

	int ch;
	choice:
	cout<<"Chose one of the available buses(1-6) \n";
	cin>>ch;
	switch(ch)
	{
		case 1:A.menu();break;
		case 2:B.menu();break;
		case 3:C.menu();break;
		case 4:D.menu();break;
		case 5:E.menu();break;
		case 6:G.menu();break;
		case 7:exit(0);break;
		default: cout<<"Wrong number . Please try again\n";
				goto choice;

	 }
