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

	//动态申请vector 并对vector建堆
	vector<int> vet;
	vet.resize(90);
	vector<int> *pvet = &vet;
// new vector<int>(0);
	pvet->assign(a, a + MAXN);

	//建堆
	PrintfVectorInt(*pvet);
	make_heap(pvet->begin(), pvet->end());
	PrintfVectorInt(*pvet);

	//加入新数据 先在容器中加入，再调用push_heap()
	pvet->push_back(25);
	push_heap(pvet->begin(), pvet->end());
	PrintfVectorInt(*pvet);

	//删除数据  要先调用pop_heap()，再在容器中删除
	pop_heap(pvet->begin(), 9+pvet->begin());
	pvet->pop_back();
	// pop_heap(pvet->begin(), pvet->end());
	// pvet->pop_back();
	cout<<"AA?"<<endl;
	PrintfVectorInt(*pvet);

	//堆排序
	sort_heap(pvet->begin(), pvet->end());
	PrintfVectorInt(*pvet);

	delete pvet;
	return 0;
}
