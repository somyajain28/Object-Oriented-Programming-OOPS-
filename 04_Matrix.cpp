#include<iostream>
using namespace std;
const int MAX = 10;

class matrix
{
	int m[MAX][MAX];
	int r,c;
	public:
		matrix()
		{
			r = 0;
			c = 0;
			for(int i = 0;i<MAX;i++)
			{
				for(int j = 0;j<MAX;j++)
					m[i][j] = 0;
			}
		}
		void getdata();
		void showdata();
		void add(matrix m2);
		void sub(matrix m2);
		void mul(matrix m2);
		void transpose();
		bool isdiagonal();
		
};
void matrix::getdata()
{
	cout<<"Enter the no.of rows: ";
	cin>>r;
	cout<<"Enter the no.of columns: ";
	cin>>c;
	cout<<endl;
	cout<<"Enter the elements of the matrix:"<<endl;
	for(int i=0;i<r;i++)
	{
		for(int j = 0;j<c;j++)
			cin>>m[i][j];
	}
}
void matrix::showdata()
{
	cout<<"The matrix is :"<<endl;
	for(int i=0;i<r;i++)
	{
		for(int j = 0;j<c;j++)
			cout<<m[i][j]<<"\t";
		cout<<endl;
	}
}
void matrix::add(matrix m2)
{
	matrix m3;
	if(r != m2.r || c != m2.c)
	{
		cout<<"Addition not possible."<<endl;
		return;
	}
	m3.r = r;
	m3.c = c;
	for(int i=0;i<r;i++)
	{
		for(int j = 0;j<c;j++)
			m3.m[i][j] = m[i][j] + m2.m[i][j];
	}
	m3.showdata();
}
void matrix::sub(matrix m2)
{
	matrix m3;
	if(r != m2.r || c != m2.c)
	{
		cout<<"Subtraction not possible."<<endl;
		return;
	}
	m3.r = r;
	m3.c = c;
	for(int i=0;i<r;i++)
	{
		for(int j = 0;j<c;j++)
			m3.m[i][j] = m[i][j] - m2.m[i][j];
	}
	m3.showdata();
}
void matrix::mul(matrix m2)
{
	matrix m3;
	if(c != m2.r)
	{
		cout<<"Multiplication not possible."<<endl;
		return;
	}
	m3.r = r;
	m3.c = m2.c;
	for(int i=0;i<m3.r;i++)
	{
		for(int j = 0;j<m3.c;j++)
		{
			for(int k = 0;k<r;k++)
				m3.m[i][j] += m[i][k] * m2.m[k][j];
		}
	}
		m3.showdata();
}
void matrix::transpose()
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cout<<m[j][i]<<"\t";
		cout<<endl;
	}
}
bool matrix::isdiagonal()
{
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<r;j++)
		{
			if(i !=j && m[i][j] != 0)
				return false;
		}
	}
	return true;
}

int main()
{
	matrix m1,m2;
	int ch;
	do
	{
		cout<<"\n*--MENU--*\n";
		cout<<"\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Transpose\n5.Check diagonal\n6.Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		if(ch>=1 && ch<=3)
		{
			cout<<"First matrix: "<<endl;
			m1.getdata();
			cout<<"Second matrix: "<<endl;
			m2.getdata();
		}
		switch(ch)
		{
			case 1:
				m1.add(m2);
				break;
			case 2:
				m1.sub(m2);
				break;
			case 3:
				m1.mul(m2);
				break;
			case 4:
				m1.getdata();
				m1.showdata();
				cout<<"Transpose matrix: "<<endl;
				m1.transpose();
				break;
			case 5:
				m1.getdata();
				m1.showdata();
				if(m1.isdiagonal())
					cout<<"Diagonal Matrix"<<endl;
				else 
					cout<<"Not a Diagonal Matrix"<<endl;
				break;
			case 6:
				exit(0);
			default:
				cout<<"Invalid choice"<<endl;
		}
	}while(1);
	return 0;
}






















