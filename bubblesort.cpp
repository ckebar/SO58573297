#include <iostream>
using namespace std;
class node{
	public:
		node *next;
		node *prev;
		int data;
		node(int x, node *p, node *n)
		{
			next = n;
			prev = p;
			data = x;
		}
};
class list{
	private:
	node *head;
	node *tail;
	public:
	list()
	{
		head = NULL;
		tail = NULL;
	}
	void addtoend(int x)
	{
		if(head == NULL)
		{
			head = new node (x,NULL,NULL);
			tail = head;
		}
		else if(tail->prev == NULL)
		{
			tail = new node(x,head,NULL);
			head->next = tail;
		}
		else
		{
			node *temp = tail;
			tail = new node(x,tail,NULL);
			temp->next = tail;

		}
	}
	void bubblesort()
	{
	    bool is_sorted = false;
		node *temp = head;
	    while (!is_sorted)
        {
            is_sorted = true;
            temp = head;
            while (temp->next != NULL)
            {
				if(temp->next->data < temp->data)
                {
                    is_sorted = false;
                    if(temp == head)
                    {
                        //temp->prev->next = temp->next; // 1. (impossible)
                        temp->next->prev = NULL;         // 2.
                        head = temp->next;
                    }
                    else
                    {
                        temp->prev->next = temp->next;   // 1.
                        temp->next->prev = temp->prev;   // 2.
                    }
                    temp->prev = temp->next;             // 3.
                    if(temp->next == tail)
                    {
                        temp->next = NULL;               // 4.
                        tail = temp;
                        //temp->next->prev = temp2;      // 5. (impossible)
                    }
                    else
                    {
                        temp->next = temp->next->next;   // 4.
                        temp->next->prev = temp;         // 5.
                    }
                    temp->prev->next = temp;             // 6.
                    temp = temp->prev;
                }
                temp = temp->next;
            }
        }
        display();
        display0();
	}
	void display()
	{
		node *temp = head;
		while(temp != NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
	void display0()
	{
		node *temp = tail;
		while(temp != NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->prev;
		}
		cout<<endl;
	}
};
int main()
{
	list l1;
	int x[10] = {17,15,8,12,10,5,4,1,7,2};
	for(int i=0;i<10;i++)
	{
		l1.addtoend(x[i]);
	}
	l1.display();
	l1.bubblesort();
	l1.display();
	return 0;
}


