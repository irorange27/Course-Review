// main.cpp
#include <iostream>
#include <conio.h>
using namespace std;
	
int Test02(), Test0301(), Test0302(), Test0303(), Test04();	// ����ԭ�����ں�������

int main()
{
	int (*f[])() = {Test02, Test0301, Test0302, Test0303, Test04};
					// ����ָ������ڵ�ַ��ָ�����飬�����Ѿ����ڵĺ������г�ʼ��
	int n = sizeof(f)/sizeof(*f), choice;					// nΪ����f��Ԫ�ظ���
	// �����������Ҫ����һ�����Ժ���������Ҫ�ڵ�6����������10�����һ����ʼ��Ԫ�ء�
	// ���Ҫ����һ�����Ժ��������ڵ�10��ɾ����Ӧ�����ʼ��Ԫ�ؼ��ɡ������������ಿ�ֲ����޸�

	while(true)
	{
		cout << "Testing 1 -- " << n << ", (0--exit): ";
		choice = getche()-'0';
		cout << endl;
		if(choice<=0)
			break;
		if(choice<=n)
			f[choice-1]();
	}
	return 0;
}
