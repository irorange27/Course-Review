// test04.cpp	�γ̼�ѧ���ɼ���
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Course
{
public:
	Course(const string &Id="", const string &Name="", int Credit=0)
		: id(Id), name(Name), credit(Credit) {}
	friend ostream & operator<<(ostream &out, const Course &c)
	{
		out << c.id << '\t' << setw(20)<< left << c.name << '\t' << c.credit;
		return out;
	}
private:
	string id, name;	// �γ̱�š��γ�����
	int credit;			// �γ̵�ѧ��
};

class Student
{
public:
	Student(const string &Id="", const string &Name="", int Num=0, const Course *array=NULL);	// �ٹ��캯��
	Student(const Student &s);										// �ڿ������캯��
	virtual ~Student();												// ����������
	void Set(const string &Id, const string &Name);					// �����ã��޸ģ�ѧ����ѧ�š�����
	void Set(int Num, const Course *array, const double *Score);	// �����ã��޸ģ�ѧ����ѡ�γ̡����γ̳ɼ�

	Student & operator=(const Student &s)							// ��ֵ���������
	{
		if(&s==this) return *this;
		if(course!=NULL) delete [] course;
		if(score!=NULL) delete [] score;
		id = s.id;
		name = s.name;
		if(s.num==0 || s.course==NULL || s.score==NULL)
		{
			num = 0;
			course = NULL;
			score = NULL;
		}
		else
		{
			num = s.num;
			course = new Course[num];
			score = new double[num];
			for(int i=0; i<num; i++)
			{
				course[i] = s.course[i];
				score[i] = s.score[i];
			}
		}
		return *this;
	}
	friend ostream & operator<<(ostream &out, const Student &s)		// ����������������Ԫ������
	{
		out << "ѧ��: " << s.id << ", ����: " << s.name << endl;
		for(int i=0; i<s.num; i++)
			out << s.course[i] << '\t' << s.score[i] << '\t' << endl;
		return out;
	}
private:
	string id, name;	// ѧ����ѧ�š�����
	int num;			// ��ѧ����ѡ�γ�����
	Course *course;		// ����Ŀγ���Ϣ��ռ��Դ�ռ�ĵ�ַ
	double *score;		// ���γ̵ĳɼ�
};

int Test04()
{
	Course array[] = {Course("08305121", "�������������", 5),
					  Course("08305071", "�����߼�A", 5),
					  Course("08305072", "�����߼�ʵ��", 1),
					  Course("01034119", "��ѧ����(3)", 4),
					  Course("03004403", "��ѧӢ��D��(4)", 4)};
	double score[] = {90, 85, 80, 75, 80};
	int n = sizeof(array)/sizeof(*array);
	Student Zhang("16123721", "����", n, array), Li;

	cout << Zhang << '\n' << Li << "===========" << endl;

	Zhang.Set(n, array, score);
	Li.Set("16127890", "����");
	Li.Set(3, array, score);
	cout << Zhang << '\n' << Li << endl;
	return 0;
}

// �� ���캯��
Student::Student(const string &Id, const string &Name, int Num, const Course *array)
	: id(Id), name(Name), num(Num), course(NULL), score(NULL)
{
	if(num<=0)
	{
		num = 0;
		return;
	}
	course = new Course[num];
	score = new double[num];
	for(int i=0; i<num; i++)
	{
		course[i] = (array!=NULL ? array[i] : Course(""));
		score[i] = 0;
	}
}

// �ڿ������캯��
Student::Student(const Student &s) : num(0), course(NULL), score(NULL)
{
	*this = s;
}

// ����������
Student::~Student()
{
	if(course!=NULL) delete [] course;
	if(score!=NULL) delete [] score;
	num = 0;
	course = NULL;
	score = NULL;
}

// �����ã��޸ģ�ѧ����ѧ�š�����
void Student::Set(const string &Id, const string &Name)
{
	id = Id;
	name = Name;
}

// �����ã��޸ģ�ѧ����ѡ�γ̡����γ̳ɼ�
void Student::Set(int Num, const Course *array, const double *Score)
{
	Student temp(id, name, Num, array);
	for(int i=0; i<Num; i++)
		temp.score[i] = Score[i];
	*this = temp;
}
