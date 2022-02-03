#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
using namespace std;

struct product
{
   int sid;
   char name[50];
   double price;
};

void input()
{
  ofstream f2;
  f2.open("rwp.bat",ios::binary);
  ifstream f1;
  f1.open("data.bat",ios::binary);
  product a;

  while(f1)
  {
	f1.read((char*)&a,sizeof(a));
	f2.write((char*)&a,sizeof(a));
  }

  cout<<"\nenter code\n";
  cin>>a.sid;
  fflush(stdin);
  cout<<"enter name\n";
  fflush(stdin);
  gets(a.name);
  fflush(stdin);
  cout<<"enter price\n";
  cin>>a.price;

  f2.write((char*)&a,sizeof(a));

  cout<<"data added\n";
  f1.close();
  f2.close();

  remove("data.bat");
  rename("rwp.bat","data.bat");

  char ch;
  cout<<"\n***WANT TO ADD MORE?(y/n)***\n";
  cin>>ch;

  if(ch=='y'|| ch=='Y')
  input();

}

void show()
{
  product a;
  ifstream f2("data.bat",ios::binary);
  f2.read((char*)&a,sizeof(a));
  while(f2)
  {
    cout<<"\n\ncode is";
    cout<<"\n"<<a.sid<<"\n";
    cout<<"name is\n";
    puts(a.name);
    cout<<"price is\n";
    cout<<a.price;

    f2.read((char*)&a,sizeof(a));
  }
  f2.close();
}

void edit()
{
  int i;
  cout<<"enter id\n";
  cin>>i;
  product a;
  int z,x=0;
  ifstream f2("data.bat",ios::binary);
  ofstream f3;
  f3.open("rp.bat",ios::binary);

  f2.read((char*)&a,sizeof(a));
  while(f2)
  {

    if((a.sid==i)&&(x<1))
    {
    system("cls");
    cout<<"\ncode is";
    cout<<"\n"<<a.sid<<"\n";
    cout<<"name is\n";
    puts(a.name);
    cout<<"price is\n";
    cout<<a.price;
    cout<<"\nenter field to edit....\n";
    cout<<"1.name\n2.price\n3.exit\n";
    cin>>z;

	fflush(stdin);

    if(z==1)
    {
     cout<<"Enter the New name: ";
     gets(a.name);
    }
    else if(z==2)
    {
     cout<<"Enter the New price: ";
     cin>>a.price;
    }
    ++x;
    }
    f3.write((char*)&a,sizeof(a));
    f2.read((char*)&a,sizeof(a));
  }
  if(x==0)
  {cout<<"sorry...no such record found"; }
  f2.close();
  f3.close();

   remove("data.bat");
  rename("rp.bat","data.bat");

  char ch;
  cout<<"\n***WANT TO EDIT MORE?(y/n)***\n";
  cin>>ch;

  if(ch=='y'|| ch=='Y')
  edit();
 }

void bill()
{
  system("cls");
  int i,j=0;
  int k[50];
  cout<<"\n\n\t\tENTER THE CODES OF PRODUCT U WANT\n\n";
  cin>>i;
  while(i!=0)
  {
    k[++j]=i;
    cin>>i;
    }

  product a;
  int z;
  ifstream f2("data.bat",ios::binary);

  double total=0;
  int n,m;

   /*for(int m=1;m<=j;++m)
   {
	cout<<k[m]<<endl;
	}  */
   cout<<"\tSNO.\tCODE\tNAME\tPRICE\n";
  for(m=1;m<=j;++m)
  {
   ifstream f2("data.bat",ios::binary);
   f2.read((char*)&a,sizeof(a));
   n=0;
  while(f2)
  {

    if((a.sid==k[m])&&(n<1))
    {
      cout<<"\t"<<m<<"\t"<<a.sid<<"\t"<<a.name<<"\t"<<a.price<<"\n";

      total=total+a.price;
      n=1;
    }

    f2.read((char*)&a,sizeof(a));
  }

  f2.seekg(ios::beg);

  f2.close();
  }
  cout<<"\n\n\t\t\tTOTAL\t"<<total;

  char ch;
  cout<<"\n***WANT MORE BILL?***(y/n)\n";
  cin>>ch;

  if(ch=='y'|| ch=='Y')
  bill();

}
void set()
{
	system("cls");
	int i;
	cout<<"\n\n\t\t*** SETTING *** \n";
	cout<<"\n\t1.TO SHOW ALL \n\t2.TO ADD";
	cout<<"\n\t3.TO EDIT\n\t4.TO DELETE ALL\n";
	cin>>i;
	if(i==1)
	show();
	else if(i==2)
	input();
	else if(i==3)
	edit();
	else if(i==4)
	remove("data.bat");
}
int main()
{   
	system("cls");
	int i;
	cout<<"\n\n\t\tENTER THE ACTION U WANT\n";
	cout<<"\n\t1.BILLING\n\n\t2.SETTING \n";
//	fflush(stdin);
	cin>>i;
	if(i==2)
	set();
	else if(i==1)
	bill();
	char ch;
	cout<<"\n\n***ANY OTHER TASK?(y/n)***\n";
	cin>>ch;

	if(ch=='y' || ch=='Y')
	main();


	return 0;

}
