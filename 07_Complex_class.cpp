#include<iostream>
using namespace std;

class Complex{
	float r,i;
	public:
		Complex(){
			r = 0;
			i = 0;
		}	
		void getdata(){
			cout<<"\nEnter the value of real part: ";
			cin>>r;
			cout<<"\nEnter the value of imaginery part: ";
			cin>>i;
		}
		void showdata(){
			if(i>=0)
				cout<<r<<" + "<<i<<"i"<<endl;
			else
				cout<<r<<" "<<i<<"i"<<endl;
		}
		Complex operator +(Complex c);
		Complex operator -(Complex c);
		Complex operator *(Complex c);
		Complex operator /(Complex c);
};
Complex Complex :: operator +(Complex c){
	Complex c1;
	c1.r = r + c.r;
	c1.i = i + c.i;
	return c1;
}
Complex Complex :: operator -(Complex c){
	Complex c1;
	c1.r = r - c.r;
	c1.i = i - c.i;
	return c1;
}
Complex Complex :: operator *(Complex c){
	Complex c1;
	c1.r = (r*c.r)-(i*c.i);
	c1.i = (r*i)+(c.i*c.i);
	return c1;
}
Complex Complex :: operator /(Complex c){
	Complex c1;
	float d =  (c.r*c.r)+(c.i*c.i);
	c1.r = ((r*c.r)+(i*c.i))/d;
	c1.i = ((i*c.r)-(r*c.i))/d;
	return c1;
}

int main(){
	Complex c1,c2,c3;
	int ch;
	do
	{
		cout<<"\n*--MENU--*"<<endl;
		cout<<"1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>ch;
		if(ch>=1&&ch<=4)
		{
			cout<<"\nEnter value of first complex number "<<endl;
			c1.getdata();
			cout<<"\nEnter value of second complex number "<<endl;
			c2.getdata();
			cout<<"\nThe value of first complex number: ";
			c1.showdata();
			cout<<"\nThe value of second complex number: ";
			c2.showdata();
		}
		switch(ch)
		{
			case 1:
				c3 = c1 + c2;
				break;
			case 2:
				c3 = c1 - c2;
				break;
			case 3:
				c3 = c1 * c2;
				break;
			case 4:
				c3 = c1 / c2;
				break;
			case 5:
				exit(0);
			default:
				cout<<"Invalid choice"<<endl;;
		}
		if(ch>=1&&ch<=4){
			cout<<"\nResult: ";
			c3.showdata();
		}
	}while(1);
	return 0;
}
