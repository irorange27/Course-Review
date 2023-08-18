#include <iostream>
#include <cstring>
using namespace std;

int main_test31()
{
	char str[] = "smart";
	cout << str+2 << endl;
	return 0;
}

/////////////////////////////////
int pos(char c, const char *str)
{
	for(int k=0; str[k]!='\0'; k++)
		if(str[k]==c)
			return k;
	return -1;
}

int main_test32()
{
	cout << pos('H', "Hello world") << ','
		 << pos('L', "Hello world") << ','
		 << pos(' ', "Hello world") << ','
		 << pos('\0', "Hello world") << endl;
	return 0;
}

////////////////////////////////////
char *substr(char *dest, const char *source, int pos, int len)
{
	int i, length = strlen(source);
	if(pos<0) pos = 0;
	for(i=0; i<len && pos+i<length; i++)
		dest[i] = source[pos+i];
	dest[i] = '\0';
	return dest;
}

int main_test33()
{
	char str1[] = "constructing", str2[80];
	cout << "\"" << substr(str2, str1, 3, 6) << "\", ";
	cout << "\"" << substr(str2, str1, 0, 5) << "\", ";
	cout << "\"" << substr(str2, str1, 0, 80) << "\"" << endl;
	return 0;
}

//////////////////////////////////////
int main_test34()
{
	int m=0, n;
	for(n=24680; n!=0; n/=10)
	{
		m = 10*m + n%10;
		cout << m << ' ';
	}
	return 0;
}

//////////////////////////////////////
int f(int n)
{
	if(n<=0)
		return 1;
	return n*f(n-1);
}

int main_test35()
{
	cout << f(3) << ' ' << f(2) << ' ' << f(1) << ' ' << f(0) << endl;
	return 0;
}

///////////////////////////////////////
#include <cmath>
int solver(double a, double b, double c, double &x1, double &x2)
{
	double d = b*b-4*a*c;
	if(d<0) return 0;
	d = sqrt(d);
	x1 = (-b-d)/(2*a);
	x2 = (-b+d)/(2*a);
	return 1;
}

int main_test36()
{
	double x1, x2;
	int flag;
	flag = solver(1, 2, 3, x1, x2);
	cout << "(" << flag << ": " << x1 << ", " << x2 << ")\t";
	flag = solver(1, 2, -3, x1, x2);
	cout << "(" << flag << ": " << x1 << ", " << x2 << ")" << endl;
	return 0;
}

///////////////////////////////////////
struct Node
{
	int x;
	Node *next;
};

void Create(Node *&head, int *a, int n)
{
	Node *p;
	for(int i=n-1; i>=0; i--)
	{
		p = new Node;
		p->x = a[i];
		p->next = head;
		head = p;
	}
}

void ShowList(const Node *head)
{
	cout << "head";
	for( ; head!=NULL; head=head->next)
		cout << " -> " << head->x;
	cout << " -> NULL" << endl;
}

void FreeList(Node *&head)
{
	Node *p;
	while(head)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

int main_test37()
{
	int a[] = {1, 2, 3, 4, 5, 6};
	Node *head = NULL;
	Create(head, a, sizeof(a)/sizeof(*a));
	cout << "原链表" << endl;
	ShowList(head);
	Node *p1 = head->next;
	// 题设条件已经准备就绪
	delete head;
	head = p1;
	// 语句执行后，查看结果
	cout << "删除原首结点之后的链表" << endl;
	ShowList(head);
	FreeList(head);
	return 0;
}

///////////////////////////////////////
int main_test38()
{
	int a[] = {1, 2, 3, 4, 5, 6};
	Node *head = NULL;
	Create(head, a, sizeof(a)/sizeof(*a));
	cout << "原链表" << endl;
	ShowList(head);
	Node *pGuard=head, *p;
	while(pGuard->next->x != 5)
		pGuard = pGuard->next;
	p = pGuard->next;
	// 题设条件已经准备就绪
	pGuard->next = p->next;
	delete p;
	// 语句执行后，查看结果
	cout << "删除数据成员为 5 的结点之后的链表" << endl;
	ShowList(head);
	FreeList(head);
	return 0;
}
