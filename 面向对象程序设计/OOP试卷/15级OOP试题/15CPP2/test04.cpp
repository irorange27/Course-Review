// test04.cpp
// 通信录类（class TXL;）简单模拟手机通信录。对于一个联系人，必须提供姓名、手机号码两个基本信息。
// 用户可根据需要，为不同的联系人添加字段，字段的数量不一定相同。每个字段包括“字段名称”、“值”。
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
	string name, phone;			// 姓名、手机号码
	string *fieldname, *value;	// 字段名称、对应的值（即内容）
	int num;					// 记录增加的字段数量
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
	TXL a[200] = { TXL("张三丰", "13312345678"), TXL("李四丰", "13937213824") };

	cout << a[0] << endl;
	cout << a[1] << endl;
	a[0].AddField("邮箱地址", "sfzhang@tj.com.cn");
	a[0].AddField("工作单位", "太极电子有限公司");
	a[0].AddField("备注", "大数据分析专家");

	a[1].AddField("固定电话", "021-12345678");
	a[1].AddField("备注", "小学同学");
	cout << a[0] << endl;
	cout << a[1] << endl;
	
	TXL b, c(a[1]);
	b = a[0];
	cout << b << endl;
	cout << c << endl;
	return 0;
}
