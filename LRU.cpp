#include <list>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
	node(int k, int v)
		:key(k), value(v){}
	int key, value;
};
struct HitTest{
	HitTest(int k):key(k){}
	bool operator()(const node& n)
	{
		return n.key == key;
	}
	int key;
};
class LRUCache{
public:
	list<node> nodes;
	int maxsize;
	int size;
    LRUCache(int capacity) {
		maxsize = capacity;
		size = 0;
        // nodes.resize(capacity);
    }
    
    int get(int key) {
		if(nodes.size() == 0) return -1;

		list<node>::iterator cc = nodes.begin();
		bool hit = false;
		while(cc != nodes.end()){
			if(cc->key == key){
				hit = true; break;
			}
			++cc;
		}
		if(!hit) return -1;

		node nn(*cc);

		nodes.erase(cc);

		nodes.push_front(nn);
		return nn.value;
    }
    
    void set(int key, int value) {
		if(size < maxsize)
			++size;
		else
			nodes.pop_back();

		nodes.push_front(node(key, value));
    }
};
struct myequal{
	myequal(int aa)
		:a(aa)
	{}
	bool operator ()(int b)
	{
		return a == b;
	}
	int a;
};
int main()
{
	LRUCache lc(1);
	lc.set(2,1);
	lc.get(1);
	cout<<"END"<<endl;

	int src[] = {3};
	list<int> l1(src,src+sizeof(src) / sizeof(int));
	cout<<l1.size()<<endl;
	// cout<<l1.max_size()<<endl;
	// l1.push_back(9);
	list<int>::iterator lit = l1.begin();
	while(lit != l1.end())
		{
		cout<<*lit<<" ";
		++lit;
		}
	// cout<<l1.front()<<endl;
	// list<int>::iterator;
	cout<<endl;
	myequal me(3);

	lit = find_if(l1.begin(), l1.end(), me);
	if(lit!=l1.end())
	cout<<*lit<<endl;
	l1.erase(lit);
lit = l1.begin();
	while(lit != l1.end())
		{
		cout<<*lit<<" ";
		++lit;
		}
	cout<<l1.size()<<endl;
	// cout<<*l1.end()<<endl;
	// cout<<l1[3]<<endl;

	return 0;
}
