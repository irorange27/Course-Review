// test04.cpp
// ͨ��¼�ࣨclass TXL;����ģ���ֻ�ͨ��¼������һ����ϵ�ˣ������ṩ�������ֻ���������������Ϣ��
// �û��ɸ�����Ҫ��Ϊ��ͬ����ϵ������ֶΣ��ֶε�������һ����ͬ��ÿ���ֶΰ������ֶ����ơ�����ֵ����
#include <iostream>
#include <iomanip>
using namespace std;

class TXL
{
public:
	TXL(const char *Name="", const char *Phone="");
	TXL(const TXL &t);
	virtual ~TXL();
	TXL & operator=(const TXL &t);
	void AddField(const string &f, const string &v);

	friend ostream & operator<<(ostream &out, const TXL &t)
	{
		out << setw(14) << t.name << '\t' << t.phone << endl;
		for(int i=0; i<t.num; i++)
			out << setw(14) << t.fieldname[i] << '\t' << t.value[i] << endl;
		return out;
	}
private:
	string name, phone;			// �������ֻ�����
	string *fieldname, *value;	// �ֶ����ơ���Ӧ��ֵ�������ݣ�
	int num;					// ��¼���ӵ��ֶ�����
};

TXL::TXL(const char *Name, const char *Phone)
	: name(Name), phone(Phone), fieldname(NULL), value(NULL), num(0)
{
}

TXL::TXL(const TXL &t) : fieldname(NULL), value(NULL), num(0)
{
	*this = t;
}

TXL::~TXL()
{
	if(fieldname!=NULL) delete [] fieldname;
	if(value!=NULL) delete [] value;
	fieldname = value = NULL;
	num = 0;
}

TXL & TXL::operator=(const TXL &t)
{
	if(this == &t) return *this;
	this->~TXL();
	name = t.name;
	phone = t.phone;
	if(t.num==0 || t.fieldname==NULL || t.value==NULL)
		return *this;
	num = t.num;
	fieldname = new string[num];
	value = new string[num];
	for(int i=0; i<num; i++)
	{
		fieldname[i] = t.fieldname[i];
		value[i] = t.value[i];
	}
	return *this;
}

void TXL::AddField(const string &f, const string &v)
{
	TXL temp(*this);
	if(fieldname!=NULL) delete [] fieldname;
	if(value!=NULL) delete [] value;
	num++;
	fieldname = new string[num];
	value = new string[num];
	for(int i=0; i<temp.num; i++)
	{
		fieldname[i] = temp.fieldname[i];
		value[i] = temp.value[i];
	}
	fieldname[temp.num] = f;
	value[temp.num] = v;
}

int Test04()
{
	TXL a[200] = { TXL("������", "13312345678"), TXL("���ķ�", "13937213824") };

	cout << a[0] << endl;
	cout << a[1] << endl;
	a[0].AddField("�����ַ", "sfzhang@tj.com.cn");
	a[0].AddField("������λ", "̫���������޹�˾");
	a[0].AddField("��ע", "�����ݷ���ר��");

	a[1].AddField("�̶��绰", "021-12345678");
	a[1].AddField("��ע", "Сѧͬѧ");
	cout << a[0] << endl;
	cout << a[1] << endl;
	
	TXL b, c(a[1]);
	b = a[0];
	cout << b << endl;
	cout << c << endl;
	return 0;
}
