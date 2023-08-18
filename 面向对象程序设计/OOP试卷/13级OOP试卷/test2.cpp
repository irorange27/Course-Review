#include <iostream>
using namespace std;

class LinkList;						// ÌáÇ°ÉùÃ÷

class Node
{
public:
	Node(int x=0) : data(x) {}
	friend class LinkList;
private:
	int data;
	Node *next;
};

class LinkList
{
private:
	Node *head;
public:
	LinkList(int n=0, int *array=NULL)
	{
		Node *p;
		head = NULL;
		for(int i=n-1; i>=0; i--)
		{
			p = new Node;
			p->data = (array!=NULL)?array[i]:0;
			p->next = head;
			head = p;
		}
	}
	LinkList(const LinkList &link)
	{
		head = NULL;
		*this = link;
	}
	virtual ~LinkList()
	{
		FreeList();
 	}
	LinkList & operator=(const LinkList &link)
	{
		if(&link == this)
			return *this;
		FreeList();
		Node *p, *q;
		for(p=link.head; p!=NULL; p=p->next)
		{
			if(head==NULL)
				head = q = new Node(p->data);
			else
			{
				q->next = new Node(p->data);
				q = q->next;
			}
		}
		q->next = NULL;
		return *this;
	}
	void FreeList()
	{
		Node *p;
		while(head != NULL)
		{
			p = head;
			head = head->next;
			delete p;
		}
	}
	void ShowList(ostream &out) const 
	{
		out << "head";
		for(Node *p=head; p!=NULL; p=p->next)
			out << " -> " << p->data;
		out << " -> NULL";
	}
};

ostream & operator<<(ostream &out, const LinkList &link)
{
	link.ShowList(out);
	return out;
}

int main_test2()
{
	int n, a[] = {3, 7, 2, 1};
	n = sizeof(a)/sizeof(*a);
	LinkList linkA(n, a), linkB(linkA), linkC;
	cout << linkA << '\n' << linkB << '\n' << linkC << endl;
	linkC = linkA;
	cout << linkC << endl;
	return 0;
}
