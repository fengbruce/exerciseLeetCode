//by MoreWindows( http://blog.csdn.net/MoreWindows )
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
void PrintfVectorInt(vector<int> &vet)
{
	for (vector<int>::iterator pos = vet.begin(); pos != vet.end(); pos++)
		printf("%d ", *pos);
	putchar('\n');
}
int main()
{
	const int MAXN = 20;
	int a[MAXN];
	int i;
	for (i = 0; i < MAXN; ++i)
		a[i] = rand() % (MAXN * 2);

	//��̬����vector ����vector����
	vector<int> vet;
	vet.resize(90);
	vector<int> *pvet = &vet;
// new vector<int>(0);
	pvet->assign(a, a + MAXN);

	//����
	PrintfVectorInt(*pvet);
	make_heap(pvet->begin(), pvet->end());
	PrintfVectorInt(*pvet);

	//���������� ���������м��룬�ٵ���push_heap()
	pvet->push_back(25);
	push_heap(pvet->begin(), pvet->end());
	PrintfVectorInt(*pvet);

	//ɾ������  Ҫ�ȵ���pop_heap()������������ɾ��
	pop_heap(pvet->begin(), 9+pvet->begin());
	pvet->pop_back();
	// pop_heap(pvet->begin(), pvet->end());
	// pvet->pop_back();
	cout<<"AA?"<<endl;
	PrintfVectorInt(*pvet);

	//������
	sort_heap(pvet->begin(), pvet->end());
	PrintfVectorInt(*pvet);

	delete pvet;
	return 0;
}
