#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		Node()
		{
		}
		Node(int v)
		{
			data = v;
			next = nullptr;
		}
		~Node()
		{
			cout<<"Destructor of node"<<endl;
		}
};

class List
{
	Node *start;
	public:
		List()
		{
			start = nullptr;
		}
		Node* createnode(int v)
		{
			Node *nn;
			nn = new Node;
			nn->data = v;
			nn->next = nullptr;
			return nn;
		}
		void ins_beg(int v)
		{
			Node *nn;
			nn = createnode(v);
			if(start == nullptr)
				start = nn;
			else
			{
				nn->next = start;
				start = nn;
			}
		}
		void del_beg()
		{
			Node *temp;
			if(start == nullptr)
				cout<<"Empty List"<<endl;
			else
			{
				temp = start;
				start = start->next;
				delete temp;
			}
		}
		void disp()
		{
			Node *temp;
			temp = start;
			if(temp == nullptr)
				cout<<"Empty List"<<endl;
			else
			{
				while(temp)
				{
					cout<<temp->data<<"\t";
					temp = temp->next;
				}
				cout<<endl;
			}
		}
		~List()
		{
			Node *temp;
			while(start)
			{
				temp=start;
				start = temp->next;
				delete temp;
			}
			
			cout<<"Destructor of list"<<endl;
		}
};

int main()
{
	List l;
	int ch,v;
	do
	{
		cout<<"\n*--MENU--*"<<endl;
		cout<<"1.Insert\n2.Delete\n3.Display\n4.Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		if(ch == 4)
			break;
		switch(ch)
		{
			case 1:
				cout<<"Enter value to insert : ";
				cin>>v;
				l.ins_beg(v);
				break;
			case 2:
				l.del_beg();
				break;
			case 3:
				l.disp();
				break;
			default:
				cout<<"Invalid choice"<<endl;
		}
	}while(1);
	return 0;
}