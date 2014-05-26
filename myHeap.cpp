#include <iostream>
#include <stdlib.h>
// using namespace std;

class node{
public:
	int key;
	int value;
	node * next;
	node * pre;
	node * left;
	node * right;
	node(int k, int val, node * n, node * p, node * l, node * r)
		:key(k), value(val), next(n), pre(p), left(l), right(r)
	{}
	void show(node * root)
	{
		if(root == 0) return;
		if(root->right)
			show(root->right);
		std::cout<<root->key<<" ";
		if(root->left)
			show(root->left);
	}
};
class heap{
public:
	node * root;
	node * first;

	heap()
	{
		root = 0;
		first = 0;
	}
	void push(node * n)
	{
		if(first == 0){
			n->next = 0;
			n->pre = n;
			first = n;
		}else{
			n->next = first;
			n->pre = first->pre;
			first->pre = n;
			first = n;
		}

		if(root == 0){
			root = n;
			return;
		}
		node * tmp = root;
		int val = n->key;
		while(1){
			node * &pp = tmp->key < val ? tmp->left : tmp->right;
			if(pp)
				tmp = pp;
			else{
				pp = n;
				break;
			}
		}
	}
	void delete_last()
	{
		if(first == 0) return;

		int val = first->pre->key;
		if(first->pre == first)
			first = 0;
		else
			first->pre = first->pre->pre;

		find_delete(val);

	}
	int find_delete(int key)
	{
		node * before = root;
		node * cur = root;
		int dir = 0;
		while(1){
			if(cur == 0 || cur->key == key){
				break;
			}else{
				before = cur;
				if(cur->key < key){
					dir = 1;
					cur = cur->left;
				}else{
					dir = 2;
					cur = cur->right;
				}
			}
		}
		if(cur == 0) return -1;
		int ret = cur->value;
		if(dir == 0) root = pop(cur);
		if(dir == 1) before->left = pop(cur);
		if(dir == 2) before->right = pop(cur);
		return ret;
	}
	node * pop(node * const loc_root)
	{
		if(loc_root == 0) return 0;
		node * left = loc_root->left;
		node * right = loc_root->right;
		node * candidate;
		node * before = loc_root;
		if(left == 0 && right == 0){
			delete loc_root;
			return 0;
		}else if(left == 0){
			candidate = right;
			while(candidate->left != 0){
				before = candidate;
				candidate = candidate->left;
			}
			if(before == loc_root)
				before->right = candidate->right;
			else
				before->left = candidate->right;
		}else if(right == 0){
			candidate = left;
			while(candidate->right != 0){
				before = candidate;
				candidate = candidate->right;
			}
			if(before == loc_root)
				before->left = candidate->left;
			else
				before->right = candidate->left;
		}else if(rand()%2 == 0){
			candidate = right;
			while(candidate->left != 0){
				before = candidate;
				candidate = candidate->left;
			}
			if(before == loc_root)
				before->right = candidate->right;
			else
				before->left = candidate->right;
		}else{
			candidate = left;
			while(candidate->right != 0){
				before = candidate;
				candidate = candidate->right;
			}
			if(before == loc_root)
				before->left = candidate->left;
			else
				before->right = candidate->left;
		}
	
		candidate->right = loc_root->right;
		candidate->left = loc_root->left;
		delete loc_root;
		return candidate;
	}
	void pop(){
		root = pop(root);
	}
	void show()
	{
		if(root != 0)
			root->show(root);
	}
};

int main()
{
	heap h;
	int len = 20;
	int maxN = 100;
	for(int i=0; i<len; ++i){
		node * n = new node(i, 0, 0, 0, 0, 0);
// rand()%maxN, 0,0);
		h.push(n);
	}
	h.show();
	for(int i=0; i<10; ++i){
		// h.pop();
		// h.find_delete(0);
		h.delete_last();
		std::cout<<std::endl;
		// std::cout<<"key: "<<nn->key<<std::endl;
		// h.root->show(h.root);
		h.show();
	}
	return 0;
}
