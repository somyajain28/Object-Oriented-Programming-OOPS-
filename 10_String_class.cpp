#include<iostream>
using namespace std;

class String
{
	char str[10];
	int l;
	public:
		friend istream& operator >>(istream &is, String &s);
		friend ostream& operator <<(ostream &os, String &s);
		int length();
		String rev();
		String operator +(String s);
		bool operator ==(String s);
		bool operator >(String s);
};

istream& operator >>(istream &is, String &s)
{
	cout<<"Enter a string: ";
	is>>s.str;
	return is;
}
ostream& operator <<(ostream &os, String &s)
{
	os<<s.str;
	return os;
}
int String::length()
{
	int i = 0,l = 0;
	while(str[i]!='\0')
	{
		l++;
		i++;
	}
	return l;
}
String String::rev()
{
	String s;
	int i;
	int len1 = this->length();
	for(i =0;str[i]!='\0';i++)
		s.str[i] = str[len1-i-1]; 
	s.str[i] = '\0';
	return s;
}
String String::operator +(String s)
{
	String s1;
	int i;
	if(this->length()+s.length() > 10)
	{
		cout<<"concatination not possible"<<endl;
		return *this;
	}
	int len = this->length();
	for(i=0;str[i] !='\0';i++)
		s1.str[i] = str[i];
	for(i=0;s.str[i] !='\0';i++)
		s1.str[len+i] = s.str[i];
	s1.str[i] = '\0';
	return s1;
}
bool String::operator ==(String s)
{
	if(this->length() != s.length())
		return false;
	for(int i=0;i!='\0';i++)
	{
		if(str[i] != s.str[i])
			return false;
	}
	return true;
}
bool String::operator >(String s)
{
	for(int i=0;str[i]!='\0'&&s.str[i]!='\0';i++)
	{
		if(str[i]>s.str[i])
			return true;
		return false;
	}	
	return false;		
}

int main()
{
	String s1,s2,s3;
	int l,ch,c;
	do
	{
		cout<<"\n*--MENU--*"<<endl;
		cout<<"1.Length of string\n2.Reverse string\n3.Compare string\n4.Conactinate string\n5.Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cin>>s1;
				l = s1.length();
				cout<<"The length of stirng is: "<<l<<endl;
				break;
			case 2:
				cin>>s1;
				s2 = s1.rev();
				cout<<"Reverse string is: "<<s2<<endl;
				break;
			case 3:
				cout<<"First string: "<<endl;
				cin>>s1;
				cout<<"Second string: "<<endl;
				cin>>s2;
				if(s1==s2)
					cout<<"Both strings are equal"<<endl;
				else if(s1> s2)
					cout<<s1<<" is greater"<<endl;
				else 
					cout<<s2<<" is greater"<<endl;
				
				break;
			case 4:
				cout<<"First string: "<<endl;
				cin>>s1;
				cout<<"Second string: "<<endl;
				cin>>s2;
				s3 = s1 + s2;
				cout<<s3;
				break;
			case 5:
				exit(0);
			default:
				cout<<"Invalid choice"<<endl;;
		}
	}while(1);
	return 0;	
}

