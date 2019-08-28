#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
using namespace std;
struct movie{
	string name;
	string time[4];
	string screen[4];
};
char toupp(char a){
	if(a>='a')
	{
		a=a-32;
		return a;
	}
	else
	{
		return a;
	}
}
void Setcursor(int x,int y){
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={x,y};
	SetConsoleCursorPosition(output,pos);
}
void filled (int x,int y){	
	for (int i=1;i<5;i++)
	{
		Setcursor(x,y+i);
		for (int j=1;j<=5;j++)
		{
			cout<<"*";
		}
	}
}
void empty (int x,int y){
	for (int i=1;i<6;i++)
	{
		Setcursor(x,y+i);
		for (int j=1;j<=6;j++)
		{	
			if (i==1 || i==5)
			{
			cout<<"*";
			}
			else 
			{
				if (j==1 || j==6 )
				{
					cout<<"*";
				}
				else
				{
					cout <<" ";
				}		
			}
		}
		
	}
}
void title()
{
	int n = 11,c; 
	int i, j;
	cout<<"\n\n\n\n";
	for (i = n - 1; i >= 0; i--) 
	{
		cout<<"\t\t";
		for (j = n - 1; j > i; j--) 
		{ 
			cout <<" "; 
		} 
		cout <<"##"; 
		for (j = 1; j < (i * 2); j++) 
			cout <<" "; 

		if (i >= 1) 
			cout <<"##";
			cout <<"\n";  
	}
	Setcursor(44,8);
	cout<<"=========";
	Setcursor(44,10);
	cout<<"=========";
	Setcursor(56,4);	
	for(int i=1;i<=n;i++)
	{
		cout<<"##";
		if( i==1 || i==2 || i==5 || i==6)
		{
			for(int j=1;j<=n-5;j++)
			{
				cout<<"##";
			}
		}
		cout<<"\n";
		Setcursor(56,4+i);
	}
	Setcursor(76,4);
	for(int i=1;i<=n;i++)
	{
		cout<<"##";
		if(i == n-1 || i == n)
		{
			for(int j=1;j<=n-5;j++)
			{
				cout<<"##";
			}
		}
		cout<<"\n";
		Setcursor(76,4+i);
	}
	Setcursor(96,4);
	for(int i=1;i<=n;i++)
	{
		cout<<"##";
		if( i==1 || i==2 || i==6 || i==7 || i==10 ||i==11)
		{
			for(int j=1;j<=n-5;j++)
			{
				cout<<"##";
			}
		}
		cout<<"\n";
		Setcursor(96,4+i);
	}
	n=9,c;
    c = n*2 - 1;
		Setcursor(116,4);
    for(int i=1; i<=c; i++)
    {
        for(int j=1; j<=c; j++)
        {
            if(j==i || (j==c-i+1))
            {
                printf("##");
            }
            else
            {
                printf(" ");
            }
        }
		printf("\n");
		Setcursor(116,4+i);
    }
}
void border(int x,int y)
{
	for (int u=1;u<=17;u++)
	{
		Setcursor(x,y+u);
		cout<<"=";
		for (int n=1;n<=50;n++)
		{
			if(u==1 || u==5 || u==9 || u==13 || u==17)
			{
				cout<<"=";
			}
			else 
			{
				cout<<" ";
			}
		}
		cout<<"=";
		cout<<"\n";
	}
}
void border2(int x,int y)
{
	for (int i=1;i<=25;i++)
			{
				Setcursor(x,y+i);
				cout<<"=";
				for(int j=1;j<=50;j++)
				{
					if(i == 1 || i == 5 || i == 9 || i == 13 || i == 17 || i == 21 || i == 25)
					{
						cout<<"=";
					}
					else 
					{
						cout<<" ";
					}
				}
				cout<<"=";
				cout<<"\n";
			}
}
char maindis()
{
	system("CLS");
	title();
	char a;
	border(50,30);
	Setcursor(71,33);
	cout<<"1. GUEST"<<endl;
	Setcursor(71,37);
	cout<<"2. MEMBER"<<endl;
	Setcursor(71,41);
	cout<<"3. ADMIN"<<endl;
	Setcursor(71,45);
	cout<<"0. EXIT"<<endl;
	a=getch();
	fflush(stdin);
	if(a!='1'&&a!='2'&&a!='3'&&a!='0')
	{
		return maindis();
	}else 
	{
		return a;
	}
}
void blank (int a,int b)
{
	int i,j;
	for(i=1;i<=10;i++)
	{
		cout<<"*";
	for(j=1;j<=22;j++)
	{
		cout<<"*";
	}
		Setcursor(a,b+i-1);
	}
}
void table()
{
	int n=51,m=96;	
	for(int i=1;i<=n;i++)
	{	
	cout<<"\t\t\t";
	cout<<"=";
	if(i == 1 || i==11 || i==21 || i==31 || i==41 || i==51)
		{
			for(int j=1;j<=m;j++)
			{
			cout<<"=";
			}
		}
		else 
		{
			for(int k=1;k<=4;k++)
			{
			cout<<"\t\t\t";
			cout<<"=";
			}
		}
		cout<<"\n";
	}
}
class cinema
{
	private:
	public:
		virtual void display()=0;
		
};
class Registeration: public cinema
{
		
		public:
		void ticketinitialize()
		{
			fstream fi;
			fi.open("Booking.txt",ios::trunc|ios::out);
			fi<<" ";
			fi.close();
			fi.open("Tickets.txt",ios::out);
			for(int i=0;i<5;i++){
				for(int j=0;j<4;j++){
					fi<<i;
					fi<<" ";
					fi<<j;
					fi<<"  ";
					for(int x=0;x<50;x++)
					{
						fi<<1;
						fi<<" ";
					}
					fi<<"\n";
				}
				
			}
			fi.close();
		}
		void userbooking(int a,string name, string movie,string screen,string time,int price,int tickets,int seats[50][2])
		{
			fstream fo;
			fo.open("Booking.txt",ios::out | ios::app);
			if(fo)
			{
				fo<<a;
				fo<<" ";
				fo<<name;
				fo<<" ";
				fo<<movie;
				fo<<" ";
				fo<<screen;
				fo<<" ";
				fo<<time;
				fo<<" ";
				fo<<price;
				fo<<" ";
				fo<<tickets;
				fo<<" ";
				for(int i=0;i<tickets;i++)
				{
					fo<<seats[i][0]<<seats[i][1];
					fo<<" ";
				}
				fo<<"\n";
			}
			fo.close();
		}
		void searchbook(int a)
		{
			int b,fl;
			string name, movie, screen,time,n;
			int price ,tickets, seats[50][2];
			fstream fo;
			fo.open("Booking.txt",ios::in);
			while(fo)
			{
				fo>>b;
				if(a==b)
				{
					fo>>name;
					fo>>movie;
					fo>>screen;
					fo>>time;
					fo>>price;
					fo>>tickets;
					for(int i=0;i<tickets;i++)
					{
						fo>>seats[i][0];
					}
					fl=1;
					break;
				}
				else
				{
				getline(fo,n);
				}
				fl=0;
			}
			system("CLS");
			if(fl==0)
			{
				fo.close();
				Setcursor(44,30);
				cout<<"INVALID REGISTERATION";
				getch();
				system("CLS");
				return;
			}
			Setcursor(36,16);
			cout<<b;
			Setcursor(36,19);
			cout<<"CUSTOMER NAME : "<<name;
			Setcursor(36,22);
			cout<<"MOVIE NAME : "<<movie;
			Setcursor(36,25);
			cout<<screen;
			Setcursor(36,28);
			cout<<"TIME : "<<time;
			Setcursor(36,31);
			cout<<"PRICE : "<<price;
			Setcursor(36,34);
			cout<<"TICKETS : "<<tickets;
			Setcursor(36,35);
			cout<<"SEAT : ";
			for(int i=0;i<tickets;i++)
			{
				if(seats[i][0]<1)
				{
					Setcursor(36+i*3,37);
					cout<<"00 ";
				}
				else if(seats[i][0]<10)
				{
					Setcursor(36+i*3,37);
					cout<<"0"<<seats[i][0]<<" ";
				}
				else
				{
					Setcursor(36+i*3,37);
					cout<<seats[i][0]<<" ";
				}	
			}
			
			fo.close();
		}
};
class Queries: public cinema
{
	private:
		string name;
		string complain[10];
		string n;
	public:
		void complaintable()
		{
			int i,j,n,m;
			for(int i=1;i<=30;i++)
			{
				Setcursor(30,13+i);
				cout<<"#";
				if(i == 1 || i==30 || i==5)
				{
					for(int j=1;j<=58;j++)
					{
						cout<<"#";
					}
				}
				else
				{
					cout<<"\t\t\t\t\t\t\t\t";
					cout<<"#";
				}
				cout<<"\n";
			}
		}
		void querysearch()
		{
			size_t pos;
			ifstream file;
			file.open("Queries.txt",ios::in);
			while(file)
			{
				Setcursor(5,5);
				cout<<"PRESS ANY KEY FOR NEXT QUERY";
				if(file){	
					getline(file,n);
				while ((pos = n.find("@")) != string::npos) 
				{
					complaintable();
					//pos=n.find("@");
					name=n.substr(0,pos);
					n.erase(0,pos+1);
					Setcursor(32,15);
					cout<<"NAME:";
					Setcursor(32,16);
					transform(name.begin(),name.end(),name.begin(),::toupper);
					cout<<name;
					Setcursor(32,20);
					cout<<"COMPLAIN:";
					Setcursor(32,21);
					for(int i=0;i<10;i++)
					{
					Setcursor(32,21+i);
					if(n.find(" ")<52)
					{
						cout<<n.substr(0,52)<<"-";
						n.erase(0,52);
					}
					else
					{
						cout<<n.substr(0,52);
						n.erase(0,52);
					}
				}
				}
				}
				else
				{
					cout<<"Error! file does not exist"<<endl;
				}
				getch();
				system("CLS");
				
			}
		}
		void query()
		{
			ofstream fin;
			int n;
			string line;
			string name;
			fin.open("Queries.txt",ios::app);
			if(fin)
			{
			while(n!=50)
			{
				fflush(stdin);
				Setcursor(20,16);
				cout<<"ENTER YOUR NAME :";
				Setcursor(20,17);
				cout<<"ENTER QUERY :";
				Setcursor(39,16);
				getline(cin,name);
				transform(name.begin(),name.end(),name.begin(),::tolower);
				fin<<name<<"@";
				Setcursor(25,18);
				getline(cin,line);
				fin<<line<<"\n";
				Setcursor(43,40);
				cout<<"DO YOU HAVE ANY MORE COMPLAINS 1.YES / 2.NO";
				n=getch();
				system("CLS");
			}
			}
			else
			{
				cout<<"Error! file does not exist"<<endl;
			}
			fin.close();
		}
};
class admin:virtual Registeration,virtual Queries
{
	private:
		string username;
		char pas[10];
	public:
		int coun()
		{
			int n;
			string i;
			fstream fi;
			fi.open("Movies.txt",ios::in);
			while(fi){
				getline(fi,i);
				n++;
			}
			fi.close();
			return n-1;
		}
		void addmovie()
		{
			int mov_count=coun();
			system("CLS");
			ofstream fp;
			int num1,count=0,count2=0;
			string MovieName,MovieTiming;
			fp.open("Movies.txt",ios::out| ios::in | ios::app);
			if(!fp)
			{
				cout<<"Error! Unable to open the file.";
				getch();
				exit(1);
			}
			
			do
			{	
				mov_count=coun();
				system("CLS");
				Setcursor(35,20);
				cout<<"Do you want to enter a movie? Yes-1,No-2:   ";
				num1=getch();
				fflush(stdin);
				
				if(num1==49)
				{
					system("CLS");
					if(mov_count>=5)
					{
						Setcursor(35,25);
						cout<<"5 MOVIES ALREADY ADDED";
						getch();
						break;
					}
					Setcursor(35,20);
					cout<<"ENTER MOVIE  NAME : ";
					getline(cin,MovieName);
					fflush(stdin);
					
				 	transform(MovieName.begin(), MovieName.end(), MovieName.begin(), ::tolower); 
					fp<<MovieName<<"@";
					do
					{
						Setcursor(35,24);
						cout<<"How many screens you'll play for this movie:   ";
						cin>>count;
						fflush(stdin);
						
						if(count<=4)
						{
							break;
						}
						else
						{
							Setcursor(35,25);
							cout<<"Cannot have more than 4 screens";
							getch();
							Setcursor(35,24);
							cout<<"\t\t\t\t\t\t\t\t\t\t\t\n\t\t\t\t\t\t\t\t\t";
						
							continue;
						}
				}
				while(count >=4);
				for(int i=0;i<count;i++)
				{
					int f=4*i;
					Setcursor(35,29+f);	
					cout<<"ENTER MOVIE TIMINGS : ";
					cin>>(MovieTiming);
					fflush(stdin);
					fp<<MovieTiming<<"@";
					Setcursor(35,30+f);	
					cout<<"SCREEN FOR THIS MOVIE : ";
					cin>>count2;
					fflush(stdin);
					fp<<"screen"<<count2<<"@";
					if(i==count-1)
					{
						fp<<"\n";
					}
				}
					
				}
				else
				{
					fp.close();
				}
			}
			while(fp);
		}
		void DeleteMovie()
		{
			string movieline[100];
			int countline=0,count1=0,count2=0,count3=0,n=0;
			fstream fp;
			fp.open("Movies.txt",ios::in | ios::out);
			while(fp)
			{
			getline(fp,movieline[countline]);
				countline++;
			}
			fp.close();
			fflush(stdin);
			Setcursor(35,20);
			cout<<"Do you wanna delete any movie?(1 for yes,2 for No)"<<endl;
			count2=getch();
				fflush(stdin);
			if(count2=='1')
			{
				if(coun()==0){
					system("CLS");
					Setcursor(50,20);
					cout<<"NO MOVIES LEFT TO DELETE";
					return;
				}
				for(int i=0;i<countline-1;i++)
				
				{
					count1=movieline[i].find("@");
					Setcursor(35,22+i*2);
					cout<<i+1<<".  "<<movieline[i].substr(0,count1)<<endl;
			}
			Setcursor(35,22+countline*2);
			cout<<"Write the serial number of the movie you want to delete:  ";
			cin>>count3;
			fflush(stdin);
			fp.open("Movies.txt",ios::trunc|ios::in |ios::out);
			while(n<countline-1)
			{
			if(n==(count3)-1)
			{
				n+=1;
				system("CLS");
				Setcursor(56,30);
				cout<<"MOVIE DELETED!!!";
				continue;	
			}
			else
			{
				fp<<movieline[n]<<endl;
				fflush(stdin);
				n+=1;	
			}
			}
			}
			fp.close();
		}
		void operator --(){
			DeleteMovie();
		}
		void operator ++(){
		 addmovie();	
		}
		friend void table();
		int verify() 
		{
			if(strcmp("ADMIN",username.c_str())==0&&strcmp("WORD",pas)==0)
			{
				return 1;
			}
			return 0;
		}
		void callsearch()
		{
			system("CLS");
			Setcursor(44,24);
			cout<<"ENTER REGISTERATION ID : ";
			int d;
			cin>>d;
			Registeration::searchbook(d);
			Setcursor(36,40);
			cout<<"Do You Want To Search Any More Registerations?(1.yes/2.no)";
			char p;
			p=getch();
			if(p=='1')
			{
				callsearch();
			}
		}
		void callquery()
		{
			Queries::querysearch();
		}
		
		void ticketcall()
		{
			Registeration::ticketinitialize();
		}
		
		void displaymovie()
		{
			table();
			int pos,count=0,count1=0,x=0;
			string n;
			struct movie s[5];
			fstream fp;
			fp.open("Movies.txt",ios::in);
			while(fp)
			{
				getline(fp,n);
					count1=0;
					pos =n.find("@");
					s[count].name = n.substr(0, pos);
		    		n.erase(0, pos +1);
				while ((pos = n.find("@")) != string::npos) 
				{
					Setcursor(28+count1*24,2+count*10);
					cout<<s[count].name<<endl;
		    		s[count].time[count1] = n.substr(0, pos);
		    		Setcursor(32+count1*25,3+count*10);
		    		char o='A'+count*4+count1;
					cout<<o;
		    		Setcursor(32+count1*25,5+count*10);
		    		cout << s[count].time[count1] <<endl;
		    		n.erase(0, pos +1);
		    		pos =n.find("@");
		    		s[count].screen[count1] = n.substr(0, pos);
		    		Setcursor(32+count1*25,7+count*10);
		    		cout << s[count].screen[count1] <<endl;
		    		n.erase(0, pos +1);
		    		count1+=1;
		    		x+=1;
				}
				while(count1<4)
				{
					Setcursor(49+24*(count1-1),1+10*count);
					blank(49+24*(count1-1),1+10*count);
					count1+=1;
				}
		
				count+=1;
				if(count>4)
				{
					break;
				}	
			}
			while(count<5)
			{
				count1=0;
				while(count1<4)
				{	
					Setcursor(49+24*(count1-1),1+10*count);
					blank(49+24*(count1-1),1+10*count);
					count1+=1;
				}
				count+=1;
				if(count>4)
				{
					break;
				}
			}
			fp.close();
		}
		
		
		void display (){
			return;
		}
		int display(int i)
		{
			int u;
			system("CLS");
			for(int j=1;j<=10;j++)
			{
				Setcursor(48,20+j);
				cout<<"#";
				if(j==2 || j==3 || j==4 || j==7 || j==8 || j==9){
					cout<<"\t\t\t\t\t\t\t\t";
					cout<<"#";
				}
				else 
				{
					for(int k=1;k<=64;k++)
					{
						cout<<"#";
					}
				}
					Setcursor(48,20+j);
				}
					char ch;
					Setcursor(51,23);
					cout<<"ADMIN : ";
					Setcursor(51,28);
					cout<<"PASSWORD : ";
					Setcursor(59,23);
					cin>>username;
					Setcursor(62,28);
					for(int j=0;j<4;j++)//encrypting
					{
						ch = getch();
						pas[j]=ch;
						ch = '*' ;
						cout<<ch;
					}
			if(verify()==0)
			{
				system("CLS");
				Setcursor(64,9);
				cout<<"WRONG PASSWORD!!!";
				u=getch();
				if(u==9){
					return 0;
				}
				else
				{
					i+=1;
					if(i<=3)
					{
						Setcursor(64,10);
						cout<<"Try "<<i<<endl;
						getch();
						display(i);
					}
					else
					{
						return 0;
					}
				}
			}
			else
			{
				return 1;
			}
		}
		int display2()
		{
			system("CLS");
			int i;
			border2(50,18);
			Setcursor(65,21);
			cout<<"1. ADD A MOVIE";
			Setcursor(65,25);
			cout<<"2. DISPLAY MOVIE";
			Setcursor(65,29);
			cout<<"3. DELETE A MOVIE";
			Setcursor(65,33);
			cout<<"4. SEARCH REGISTERATION";
			Setcursor(65,37);
			cout<<"5. CHECK QUERIES";
			Setcursor(65,41);
			cout<<"6. RESET TICKETS";
			Setcursor(1,0);
			cout<<"Press TAB to Exit";
			i=getch();
			fflush(stdin);
			if(i==9)
			{
				return 0;
			}
			else if( i>'6'|| i<'1')
			{
				return display2();
			}
			else
			{
				return i;
			}
		}
		void menu()
		{
			char b;
			int flag;
			b=display(1);
			if(b==1)
			{
				system("CLS");
				Setcursor(36,8);
				cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$  WELCOME ADMIN  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
				getch();
				while(b==1){
					b=display2();
					if(b==0){
						continue;
					}
					else
					{
						while(b!=0){
							switch (b)
							{
								case '1':{
									operator ++();
									break;
								}
								case '2':{
									system("CLS");
									displaymovie();
									Setcursor(1,0);
									cout<<"Press Tab to exit";
									flag=0;
									while(flag!=9){
									flag=getch();
									}
									break;
								}
								case '3':{
									system("CLS");
									operator --();
									getch();
									break;
								}
								case '4':{
									
									callsearch();
									break;
								}
								case '5':{
									system("CLS");
									callquery();
									break;
								}
								case '6':{
									ticketcall();
									system("CLS");
									Setcursor(56,29);
									cout<<"TICKETS INITIALIZED";
									getch();
									break;
								}
							}
							b=1;
							break;
						}
						}
					}
			}else{
				return;
			}		
		}
};
class guest:virtual Registeration,virtual Queries{
	public:	
	friend void table();
void SearchAndWrite(int a,int b,int c[5][10]){
	int x,y;
	string o;
	fstream fo;
	fo.open("Tickets.txt", ios::out |ios::in);
	while(fo){
		fo>>x;
		fo>>y;
		if(a==x && b==y){
		fo<<"  ";
			for(int u=0;u<=4;u++){
					for(int j=0;j<=9;j++){
						fo<<c[u][j];
						fo<<" ";
					}
			}
			fo<<"\n";
			break;
		}else{
			getline(fo,o);
		}
	}
	fo.close();
}
void SearchAndRead(int a,int b,int c[5][10]){
	int x,y;
	string o;
	fstream fo;
	fo.open("Tickets.txt", ios::out |ios::app |ios::in);
	while(fo){
		fo>>x;
		fo>>y;
		if(a==x && b==y){

			for(int u=0;u<5;u++){
				for(int j=0;j<10;j++){
				
				fo>>c[u][j];
			}
			}
			break;
		}else{
			getline(fo,o);
		}
	}
fo.close();
}
void ContactUsDisplay(){
	for (int i=1;i<=20;i++)
	{
		Setcursor(25,5+i);
		cout<<"=";
		for (int j=1;j<=50;j++)
		{
			if(i==1 || i==8 || i==12 || i==16 || i==20)
			{
				cout<<"=";
			}
			else 
			{
				cout<<" ";
			}
		}
		cout<<"=";
		cout<<"\n";
	}
}
void ContactUs(){
	ContactUsDisplay();
	Setcursor(27,8);
	cout<<"CONTACT NUMBERS : ";
	Setcursor(47,9);
	cout<<"021-36907915";
	Setcursor(47,10);
	cout<<"021-36907916";
	Setcursor(47,11);
	cout<<"021-36907917";
	Setcursor(27,14);
	cout<<"FAX NUMBER : ";
	Setcursor(47,15);
	cout<<"0322-2062163";
	Setcursor(27,18);
	cout<<"E-MAIL : ";
	Setcursor(47,19);
	cout<<"VFLEX.CINEMA@Gmail.pk";
	Setcursor(27,22);
	cout<<"SOCIAL MEDIA : ";
	Setcursor(47,23);
	cout<<"FACEBOOK => VFLEX CINEMA";
	Setcursor(47,24);
	cout<<"INSTRAGM => VFLEX_CINEMA";
}
void display(){
	return;
}
void display (int tickets[5][10]){
	for(int i=0;i<5;i++){
			for(int j=0;j<10;j++)
			{
				if(tickets[i][j]==1){
					if(j<3){
						empty(10+(10*j),4+(8*i));
						Setcursor(11+(10*j+1),5+(8*i+1));
						cout<<i<<j;
					}else if (j<7){
						empty(17+(10*j),4+(8*i));	
						Setcursor(18+(10*j+1),5+(8*i+1));
						cout<<i<<j;
					}else{
						empty(24+(10*j),4+(8*i));	
						Setcursor(25+(10*j+1),5+(8*i+1));
						cout<<i<<j;
						
					}	
				}else{
					if(j<3){
						empty(10+(10*j),4+(8*i));
						filled(11+(10*j),5+(8*i));	
					}else if (j<7){
						empty(17+(10*j),4+(8*i));
						filled(18+(10*j),5+(8*i));	
					}else{
						empty(24+(10*j),4+(8*i));
						filled(25+(10*j),5+(8*i));	
					}
				}
			}
	}
}
void displaymovie(struct movie *s){
	table();
	int pos,count=0,count1=0,x=0;
	string n;
	fstream fp;
	fp.open("Movies.txt",ios::in);
	while(fp){
		getline(fp,n);
			count1=0;
			pos =n.find("@");
			s[count].name = n.substr(0, pos);
    		n.erase(0, pos +1);
		while ((pos = n.find("@")) != string::npos) {
			Setcursor(28+count1*24,2+count*10);
			cout<<s[count].name<<endl;
    		s[count].time[count1] = n.substr(0, pos);
    		Setcursor(32+count1*25,3+count*10);
    		char o='A'+count*4+count1;
			cout<<o;
    		Setcursor(32+count1*25,5+count*10);
    		cout << s[count].time[count1] <<endl;
    		n.erase(0, pos +1);
    		pos =n.find("@");
    		s[count].screen[count1] = n.substr(0, pos);
    		Setcursor(32+count1*25,7+count*10);
    		cout << s[count].screen[count1] <<endl;
    		n.erase(0, pos +1);
    		count1+=1;
    		x+=1;
		}
		
		while(count1<4){
			Setcursor(49+24*(count1-1),1+10*count);
			blank(49+24*(count1-1),1+10*count);
			count1+=1;
		}
		count+=1;
		if(count>4){
					break;
				}	
	}
	while(count<5){
		count1=0;
		while(count1<4){	
			Setcursor(49+24*(count1-1),1+10*count);
			blank(49+24*(count1-1),1+10*count);
			count1+=1;
		}
		count+=1;
	}
	fp.close();
}
void MainMenu(){
	int num1,num2=0,a,b=0,count=0;
	fstream fp1;
	int bin1=0;
	int bin2=0;
	string name;
	int option1;
	int seats [50][2];
	int sum,y,r_id;
	string o;
	while(option1!='0'){
	system("CLS");
	border2(40,7);
	Setcursor(44,10);
	cout<<"----|Choose any one option to proceed|----"<<endl;
	Setcursor(44,14);
    cout<<"1. MOVIE DETAILS";
	Setcursor(44,18);
	cout<<"2. BOOKING";
	Setcursor(44,22);
	cout<<"3. Contact Us";
	Setcursor(44,26);
	cout<<"4. ANY QUERIES ?";
    Setcursor(44,30);
    cout<<"0.  EXIT";
	option1=getch();
    system("CLS");
    fflush(stdin);
	switch(option1){
		case '1':{
			struct movie s[5];
			system("CLS");
			displaymovie(s);
			Setcursor(1,0);
			cout<<"Press Tab to exit";
			int flag=0;
			while(flag!=9){
				flag=getch();
			}
			break;
			}
			//END OF CASE 1
		case '2':{
			struct movie s[5];
			int tickets[5][10];
			char option2;
			Setcursor(30,25);
			cout<<"ENTER YOUR NAME : ";
			cin>>name;
			system("CLS");
			displaymovie(s);
			Setcursor(15,52);
			cout<<"\n|--Select movie and its screen--|:    ";
			cin>>option2;
			fflush(stdin);
			option2=toupp(option2);
			try{
				if(option2>'T'||option2<'A'){
					throw(option2);
				}
			}
			catch(char a){
				system("CLS");
				Setcursor(50,25);
				cout<<"invalid input";
				getch();
				break;
			}
			switch(option2){
				case 'A':{
					bin1=0;
					bin2=0;
				break;
				}
				case 'B':{
					bin1=0;
					bin2=1;
				break;
				}
				case 'C':{
					bin1=0;
					bin2=2;
				break;
				}
				case 'D':{
					bin1=0;
					bin2=3;
				break;
				}
				case 'E':{
					bin1=1;
					bin2=0;
				break;
				}
				case 'F':{
					bin1=1;
					bin2=1;
				break;
				}
				case 'G':{
					bin1=1;
					bin2=2;
				break;
				}
				case 'H':{
					bin1=1;
					bin2=3;
				break;
				}
				case 'I':{
					bin1=2;
					bin2=0;
				break;
				}
				case 'J':{
					bin1=2;
					bin2=1;
				break;
				}
				case 'K':{
					bin1=2;
					bin2=2;
				break;
				}
				case 'L':{
					bin1=2;
					bin2=3;
				break;
				}
				case 'M':{
					bin1=3;
					bin2=0;
				break;
				}
				case 'N':{
					bin1=3;
					bin2=1;
				break;
				}
				case 'O':{
					bin1=3;
					bin2=2;
				break;
				}
				case 'P':{
					bin1=3;
					bin2=3;
				break;
				}
				case 'Q':{
					bin1=4;
					bin2=0;
				break;
				}
				case 'R':{
					bin1=4;
					bin2=1;
				break;
				}
				case 'S':{
					bin1=4;
					bin2=2;
				break;
				}
				case 'T':{
					bin1=4;
					bin2=3;
				break;
				}
			}
			system("CLS");
			Setcursor(20,0);
			cout<<s[bin1].name<<"     "<<s[bin1].screen[bin2]<<"    "<<s[bin1].time[bin2];
			SearchAndRead(bin1,bin2,tickets);
			do{
				char comma;
				system("CLS");
				display(tickets);
				Setcursor(30,52);
				cout<<"SELECT SEAT NUMBER YOU WANT TO REGISTER (0,0) : ";
				cin>>a>>comma>>b;
				
				if(tickets[a][b]==0){
					Setcursor(30,54);
					cout<<"SEAT TAKEN";
					getch();
					fflush(stdin);
					system("CLS");
					display(tickets);
					continue;
				}else{
					tickets[a][b]=0;
					system("CLS");
					Setcursor(30,25);
					seats[count][0]=a;
					seats[count][1]=b;
					cout<<"Do you want to book more tickets (1=yes/2=no):";
					cin>>y;
					count++;
				}
			}while(y==1);
			SearchAndWrite(bin1,bin2,tickets);
			system("CLS");
			Setcursor(30,25);
			cout<<"You have booked "<<count<<" tickets";
			Setcursor(30,27);
			cout<<"Under The name "<<name;
			Setcursor(30,29);
			sum=count*500;
			cout<<"Your total Price for "<<count<<" tickets is "<<sum;
			Setcursor(30,31);
			srand(time(NULL));
			r_id=rand()%9000 +1000;
			cout<<"Your registeration ID is: "<<r_id;
			Setcursor(30,33);
			cout<<"Do not lose this ID or you will not be given your tickets";
			Setcursor(30,36);
			cout<<"you have booked the seats";
			for(int i=0;i<count;i++){
			Setcursor(30+i*7,37);
			cout<<seats[i][0]<<seats[i][1];
			}
			Setcursor(0,0);
			title();
			getch();
			userbooking(r_id,name,s[bin1].name,s[bin1].screen[bin2],s[bin1].time[bin2],sum,count,seats);
			break;
		}
			//END OF CASE 2
		case '3':{
				ContactUs();
				Setcursor(1,0);
				cout<<"Press Tab to exit";
				int flag=0;
				while (flag!=9){
					flag=getch();
				}
				break;
			}
			//END OF CASE 3
		case '4':{
				query();;
				break;
			}
			//END OF CASE 4
	}
	}
	
}
};
class member:virtual Registeration,virtual Queries{
	public:
		friend void table();
		void Menu1Dis (){
			Setcursor(1,0);
			cout<<"Press Tab to exit";
			for (int i=1;i<=17;i++)
			{
				Setcursor(48,8+i);
				cout<<"=";
				for(int j=1;j<=50;j++)

				{
					if(i == 1 || i == 5 || i == 9 || i == 13 || i == 17)
					{
						cout<<"=";
					}
					else 
					{
						cout<<" ";
					}
				}
				cout<<"=";
				cout<<"\n";
			}
		}
		void display (int tickets[5][10]){
			Setcursor(1,0);
			cout<<"Press Tab to exit";
	for(int i=0;i<5;i++){
			for(int j=0;j<10;j++)
			{
				if(tickets[i][j]==1){
					if(j<3){
						empty(10+(10*j),4+(8*i));
						Setcursor(11+(10*j+1),5+(8*i+1));
						cout<<i<<j;
					}else if (j<7){
						empty(17+(10*j),4+(8*i));	
						Setcursor(18+(10*j+1),5+(8*i+1));
						cout<<i<<j;
					}else{
						empty(24+(10*j),4+(8*i));	
						Setcursor(25+(10*j+1),5+(8*i+1));
						cout<<i<<j;
						
					}	
				}else{
					if(j<3){
						empty(10+(10*j),4+(8*i));
						filled(11+(10*j),5+(8*i));	
					}else if (j<7){
						empty(17+(10*j),4+(8*i));
						filled(18+(10*j),5+(8*i));	
					}else{
						empty(24+(10*j),4+(8*i));
						filled(25+(10*j),5+(8*i));	
					}
				}
			}
	}
}
		void SearchAndWrite(int a,int b,int c[5][10]){
			int x,y;
			string o;
			fstream fo;
			fo.open("Tickets.txt", ios::out |ios::in);
			while(fo){
				fo>>x;
				fo>>y;
				if(a==x && b==y){
				fo<<"  ";
					for(int u=0;u<=4;u++){
							for(int j=0;j<=9;j++){
								fo<<c[u][j];
								fo<<" ";
							}
					}
					fo<<"\n";
					break;
				}else{
					getline(fo,o);
				}
			}
			fo.close();
		}
		void SearchAndRead(int a,int b,int c[5][10]){
			int x,y;
			string o;
			fstream fo;
			fo.open("Tickets.txt", ios::out |ios::app |ios::in);
			while(fo){
				fo>>x;
				fo>>y;
				if(a==x && b==y){
		
					for(int u=0;u<5;u++){
						for(int j=0;j<10;j++){
						
						fo>>c[u][j];
					}
					}
					break;
				}else{
					getline(fo,o);
				}
			}
		fo.close();
		}
		void MenuDis(){
			for (int i=1;i<=13;i++)
			{
				Setcursor(48,8+i);
				cout<<"=";
				for(int j=1;j<=50;j++)
				{
					if(i == 1 || i == 5 || i==9 || i==13)
					{
						cout<<"=";
					}
					else 
					{
						cout<<" ";
					}
				}
				cout<<"=";
				cout<<"\n";
			}
		}
		void Screen (){
			for(int i=1;i<=10;i++)
			{
				Setcursor(45,i+20);
				cout<<"#";
				if(i==2 || i==3 || i==4 || i==7 || i==8 || i==9)
				{
					cout<<"\t\t\t\t\t\t\t\t\t";
					cout<<"#";
				}
				else 
				{
					for(int j=1;j<=67;j++)
					{
						cout<<"#";
					}
				}
				cout<<"\n";
			}
		}
		void ContactDis (){
			Setcursor(1,0);
			cout<<"Press Tab to exit";
			for (int i=1;i<=20;i++)
			{
				Setcursor(45,5+i);
				cout<<"=";
				for (int j=1;j<=50;j++)
				{
					if(i==1 || i==8 || i==12 || i==16 || i==20)
					{
						cout<<"=";
					}
					else 
					{
						cout<<" ";
					}
				}
				cout<<"=";
				cout<<"\n";
			}
		}
		void con (){
			ContactDis ();
			Setcursor(47,8);
			cout<<"CONTACT NUMBERS : ";
			Setcursor(67,9);
			cout<<"021-36907915";
			Setcursor(67,10);
			cout<<"021-36907916";
			Setcursor(67,11);
			cout<<"021-36907917";
			Setcursor(47,14);
			cout<<"FAX NUMBER : ";
			Setcursor(67,15);
			cout<<"0322-2062163";
			Setcursor(47,18);
			cout<<"E-MAIL : ";
			Setcursor(67,19);
			cout<<"VFLEX.CINEMA@Gmail.pk";
			Setcursor(47,22);
			cout<<"SOCIAL MEDIA : ";
			Setcursor(67,23);
			cout<<"FACEBOOK => VFLEX CINEMA";
			Setcursor(67,24);
			cout<<"INSTRAGM => VFLEX_CINEMA";
		}
		int check (string p){
			fstream userl;
			userl.open("USER.txt");
			string user,pass;
			string n;
			int i;
			size_t pos;
			while(userl)
				{
					getline(userl,n);
					pos=n.find("@");
					user=n.substr(0,pos);
					if(strcmp(user.c_str(),p.c_str())==0)
					{	
						i= 1;
						break;	
					}else{
						i=0;
					}
				}	
				userl.close();
				return i;
		}
		void MD(struct movie *s){
					table();
			int pos,count=0,count1=0,x=0;
			string n;
			fstream fp;
			fp.open("Movies.txt",ios::in);
			while(fp){
				getline(fp,n);
					count1=0;
					pos =n.find("@");
					s[count].name = n.substr(0, pos);
		    		n.erase(0, pos +1);
				while ((pos = n.find("@")) != string::npos) {
					Setcursor(28+count1*24,2+count*10);
					cout<<s[count].name<<endl;
		    		s[count].time[count1] = n.substr(0, pos);
		    		Setcursor(32+count1*25,3+count*10);
		    		char o='A'+count*4+count1;
					cout<<o;
		    		Setcursor(32+count1*25,5+count*10);
		    		cout << s[count].time[count1] <<endl;
		    		n.erase(0, pos +1);
		    		pos =n.find("@");
		    		s[count].screen[count1] = n.substr(0, pos);
		    		Setcursor(32+count1*25,7+count*10);
		    		cout << s[count].screen[count1] <<endl;
		    		n.erase(0, pos +1);
		    		count1+=1;
		    		x+=1;
				}
				
				while(count1<4){
					Setcursor(49+24*(count1-1),1+10*count);
					blank(49+24*(count1-1),1+10*count);
					count1+=1;
				}
				count+=1;
				if(count>4){
					break;
				}	
			}
			while(count<5){
				count1=0;
				while(count1<4){	
					Setcursor(49+24*(count1-1),1+10*count);
					blank(49+24*(count1-1),1+10*count);
					count1+=1;
				}
				count+=1;
			}
			fp.close();
		
		}
		void MD(){
			table();
			Setcursor(1,0);
			cout<<"Press Tab to exit";
			int pos,count=0,count1=0,x=0;
			string n;
			struct movie s[5];
			fstream fp;
			fp.open("Movies.txt",ios::in);
			while(fp){
				getline(fp,n);
					count1=0;
					pos =n.find("@");
					s[count].name = n.substr(0, pos);
		    		n.erase(0, pos +1);
				while ((pos = n.find("@")) != string::npos) {
					Setcursor(28+count1*24,2+count*10);
					cout<<s[count].name<<endl;
		    		s[count].time[count1] = n.substr(0, pos);
		    		Setcursor(32+count1*25,3+count*10);
		    		char o='A'+count*4+count1;
					cout<<o;
		    		Setcursor(32+count1*25,5+count*10);
		    		cout << s[count].time[count1] <<endl;
		    		n.erase(0, pos +1);
		    		pos =n.find("@");
		    		s[count].screen[count1] = n.substr(0, pos);
		    		Setcursor(32+count1*25,7+count*10);
		    		cout << s[count].screen[count1] <<endl;
		    		n.erase(0, pos +1);
		    		count1+=1;
		    		x+=1;
				}
				
				while(count1<4){
					Setcursor(49+24*(count1-1),1+10*count);
					blank(49+24*(count1-1),1+10*count);
					count1+=1;
				}
				count+=1;	
				if(count>4){
					break;
				}
			}
			while(count<5){
				count1=0;
				while(count1<4){	
					Setcursor(49+24*(count1-1),1+10*count);
					blank(49+24*(count1-1),1+10*count);
					count1+=1;
				}
				count+=1;
			}
			fp.close();
			Setcursor(0,1);
		}		
		void Register(){
			system ("CLS");
			Setcursor(80,20);
			cout<<"REGISTER";
			Screen ();
			string username;
			char rpass[10],ch1;
			char y;
			int i,flag;
			Setcursor(53,23);
			cout<<"USERNAME : ";
			Setcursor(53,28);
			cout<<"PASSWORD <4 digit pin> : ";
			Setcursor(64,23);
			cin>>username;
			Setcursor(78,28);
			for(int i=0;i<4;i++)//encrypting
			{
				ch1 = getch();
				rpass[i]=ch1;
				ch1 = '*' ;
				cout<<ch1;
			}
			string registerpass(rpass);
			flag = check(username);
			if(flag == 1)
			{
				system ("CLS");
				Setcursor(65,16);
				cout<<"PRESS TAB TO GO TO MAIN MENU";
				Setcursor(65,18);
				cout<<"PRESS ANY KEY TO REGISTER";
				Setcursor(60,20);
				cout<<"ACCOUNT WITH SAME NAME ALREADY REGISTERED";
				y=getch ();
				while(y==9){
					return;
				}
				Register();
			}
			else
			{
				fstream userR;
				userR.open("USER.txt",ios::app|ios::out);
				if (!userR)
				{
					cout<<"File Not Found !!!!";
					getch();
					exit(1);
				}
				else
				{
					fflush(stdin);
					userR<<username<<"@"<<registerpass<<"\n";
					system("CLS");
					Setcursor(60,20);
					cout<<"REGISTERED";
					getch ();
					userR.close();
				}
				userR.close();
		
			}
		}
		int LOGIN(){
			system("CLS");
			Setcursor(75,20);
			cout<<"LOGIN";
			Screen();
			int l;
			int flag=0;
			char pas[10],ch;
			string name;
			Setcursor(48,23);
			cout<<"USERNAME : ";
			Setcursor(48,28);
			cout<<"PASSWORD : ";
			Setcursor(59,23);
			cin>>name;
			Setcursor(59,28);
			for(int i=0;i<4;i++)//encrypting
			{
				ch = getch();
				pas[i]=ch;
				ch = '*' ;
				cout<<ch;
			}
			string password(pas);//changing char to string
			fstream userf;//file object
			userf.open("USER.txt",ios::in);
			string user,pass;
			string n;
			size_t pos;
			while(userf)
			{
						getline(userf,n);
						pos=n.find("@");
						user=n.substr(0,pos);
						if(strcmp(user.c_str(),name.c_str())==0)
						{
							n.erase(0,pos+1);
							pos=n.find(" ");
							pass=n.substr(0,pos);
							if(strcmp(password.c_str(),pass.c_str())==0)
							{
								n.erase(0,pos);
								system ("CLS");
								userf.close();
								flag=1;
								menu1 ();
								break;
							}
							flag=0;	
						}
		}
			
			userf.close();
			return flag;
		}
		void menu1 (){
			system("CLS");
			int l,y;
			string name;
			Menu1Dis();
			Setcursor(69,11);
			cout<<"1) MOVIE DETAILS";
			Setcursor(69,15);
			cout<<"2) CONTACT US";
			Setcursor(69,19);
			cout<<"3) QUERY";
			Setcursor(69,23);
			cout<<"4) TICKETING";
			Setcursor(50,29);
		    l=getch();
			switch (l)
			{
				case '1' :{
					system ("CLS");
					MD();
					while(y!=9){
							y = getch ();
						}
					system ("CLS");
					menu1();
					break;
				}
				case '2' :{
					system ("CLS");
					con ();
					while(y!=9){
							y = getch ();
						}
					system ("CLS");
					menu1();
					break;
				}
				case '3':{
					system ("CLS");
					Queries::query();
					menu1();			
					break;
				}
				case '4':{
					system("CLS");
					int sum=0,r_id=0,count=0,count1=0,bin1=0,bin2=0,a,b,seats[50][2];
					struct movie s[5];
					int tickets[5][10];
					char option1,option2;
					Setcursor(30,25);
					cout<<"Enter your name :";
					cin>>name;
					system("CLS");
					MD(s);
					Setcursor(15,52);
					cout<<"\n|--Select movie and its screen--|:    ";
					cin>>option2;
					fflush(stdin);
					option2=toupp(option2);
					try{
						if(option2>'T'||option2<'A'){
							throw(option2);
						}
					}
					catch(char a){
						system("CLS");
						Setcursor(50,25);
						cout<<"invalid input";
						getch();
						menu1();
					}
						
					switch(option2){
						case 'A':{
							bin1=0;
							bin2=0;
						break;
						}
						case 'B':{
							bin1=0;
							bin2=1;
						break;
						}
						case 'C':{
							bin1=0;
							bin2=2;
						break;
						}
						case 'D':{
							bin1=0;
							bin2=3;
						break;
						}
						case 'E':{
							bin1=1;
							bin2=0;
						break;
						}
						case 'F':{
							bin1=1;
							bin2=1;
						break;
						}
						case 'G':{
							bin1=1;
							bin2=2;
						break;
						}
						case 'H':{
							bin1=1;
							bin2=3;
						break;
						}
						case 'I':{
							bin1=2;
							bin2=0;
						break;
						}
						case 'J':{
							bin1=2;
							bin2=1;
						break;
						}
						case 'K':{
							bin1=2;
							bin2=2;
						break;
						}
						case 'L':{
							bin1=2;
							bin2=3;
						break;
						}
						case 'M':{
							bin1=3;
							bin2=0;
						break;
						}
						case 'N':{
							bin1=3;
							bin2=1;
						break;
						}
						case 'O':{
							bin1=3;
							bin2=2;
						break;
						}
						case 'P':{
							bin1=3;
							bin2=3;
						break;
						}
						case 'Q':{
							bin1=4;
							bin2=0;
						break;
						}
						case 'R':{
							bin1=4;
							bin2=1;
						break;
						}
						case 'S':{
							bin1=4;
							bin2=2;
						break;
						}
						case 'T':{
							bin1=4;
							bin2=3;
						break;
						}
					}
					system("CLS");
					Setcursor(20,0);
					cout<<s[bin1].name<<"     "<<s[bin1].screen[bin2]<<"    "<<s[bin1].time[bin2];
					SearchAndRead(bin1,bin2,tickets);
					do{
						char comma;
						system("CLS");
						display(tickets);
						Setcursor(30,52);
						cout<<"Select seat number you want to register(0,0):";
						cin>>a>>comma>>b;
						
						if(tickets[a][b]==0){
							Setcursor(30,54);
							cout<<"Seat taken";
							getch();
							fflush(stdin);
							system("CLS");
							display(tickets);
							continue;
						}else{
							tickets[a][b]=0;
							system("CLS");
							Setcursor(30,25);
							seats[count][0]=a;
							seats[count][1]=b;
							cout<<"Do you want to book more tickets (1=yes/2=no):";
							cin>>y;
							count++;
						}
					}while(y==1);
					SearchAndWrite(bin1,bin2,tickets);
					system("CLS");
					Setcursor(30,25);
					cout<<"You have booked "<<count<<" tickets";
					Setcursor(30,27);
					cout<<"Under The name "<<name;
					Setcursor(30,29);
					sum=count*500;
					int dsum = sum*0.80;
					cout<<"Your total Price for "<<count<<" tickets was "<<sum;
					Setcursor(30,30);
					cout<<"Your total Price After Membership discount is "<<dsum;
					Setcursor(30,32);
					srand(time(NULL));
					r_id=rand()%9000 +1000;
					cout<<"Your registeration ID is: "<<r_id;
					Setcursor(30,34);
					cout<<"Do not lose this ID or you will not be given your tickets";
					Setcursor(30,37);
					cout<<"you have booked the seats";
					for(int i=0;i<count;i++){
					Setcursor(30+i*7,38);
					cout<<seats[i][0]<<seats[i][1];
					}
					Setcursor(0,0);
					title();
					getch();
					userbooking(r_id,name,s[bin1].name,s[bin1].screen[bin2],s[bin1].time[bin2],dsum,count,seats);
					menu1();
					break;
				}	
			}
		}
		void display(){
			system("CLS");
			int n,x;
			char y;
			MenuDis();
			Setcursor(69,11);
			cout<<"1) LOGIN";
			Setcursor(69,15);
			cout<<"2) REGISTER";
			Setcursor(69,19);
			cout<<"0) MAIN MENU";
			Setcursor(69,8);
			cout<<"MEMBER";
			Setcursor(0,0);
			cin>>n;
			switch(n)
			{
				case 1 :{
					x=LOGIN ();	
					if(x==0){
					system("CLS");
					Setcursor(60,20);
					cout<<"USER NOT FOUND\n";
					getch ();
					}else{
						break;
					}
					
					system("CLS");
					Setcursor(60,20);
					cout<<"REGISTER YOURSELF";
					getch();
					system ("CLS");
					display();
					break;
				}
				case 2 :{
					Register();
					system ("CLS");
					display();
					break;
				}
				case 0:{
					
					return;
					break;
				}
			}
		}
};

int main(){
	system("color 4F");
	char x;
	int b,flag;
	while(x!='0'){
		system("CLS");
	switch(maindis()){
		case'1':{
			guest g;
			g.MainMenu();
			break;
		}
		case'2':{
			member m;
			system("CLS");
			m.display();
			break;
		}
		case'3':{
			admin a;
			a.menu();
		break;
		}
				
		default:{
			x='0';
			break;
		}
			
	}
}
}
