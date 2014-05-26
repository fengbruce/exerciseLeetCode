#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

// Definition for binary tree
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x)
	:val(x), left(NULL), right(NULL){}
	};

class Solution{
public:
vector<int> postorderTraversal(TreeNode *root)
{
	vector<int> ret;
	vector<int> tmpqi;
	if(root == 0) return ret;
	vector<TreeNode*> tmp;
	tmp.push_back(root);
	while(!tmp.empty()){
		TreeNode * tn = tmp.back();
		tmpqi.push_back(tn->val);
		tmp.pop_back();
		TreeNode * tnLeft = tn->left;
		TreeNode * tnRight = tn->right;
		if(tnLeft != 0)	tmp.push_back(tnLeft);	
		if(tnRight != 0) tmp.push_back(tnRight);

	}
	while(!tmpqi.empty()){
		ret.push_back(tmpqi.back());
		tmpqi.pop_back();
	}
	return tmpqi;
}
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> tmpqi;
		if(root == 0) return ret;
		vector<TreeNode*> tmp;
		tmp.push_back(root);
		while(!tmp.empty()){
			TreeNode * tn = tmp.back();
			tmpqi.push_back(tn->val);
			tmp.pop_back();
			TreeNode * tnLeft = tn->left;
			TreeNode * tnRight = tn->right;
			if(tnRight != 0) tmp.push_back(tnRight);
			if(tnLeft != 0)	tmp.push_back(tnLeft);	
		}

		return tmpqi;
        
    }
	void show(TreeNode * root){
		if(root == 0) return;
		cout<<root->val<<" ";
		show(root->left);
		show(root->right);
	}
};

int main()
{
	int src[] = {1,2,3,4,5,6,7};
	TreeNode tn(src[0]);
	queue<TreeNode*> tmp;
	tmp.push(&tn);
	int len = sizeof(src)/sizeof(int);
	int i=0;
	while(!tmp.empty()){
		TreeNode * lotn = tmp.front();
		tmp.pop();
		if(++i < len && src[i] != -1){
			lotn->left = new TreeNode(src[i]);
			tmp.push(lotn->left);
		}
		if(++i < len && src[i] != -1){
			lotn->right = new TreeNode(src[i]);
			tmp.push(lotn->right);
		}
		
	}
	Solution so;
	so.show(&tn);
	cout<<endl;
	vector<int> ret = so.postorderTraversal(&tn);
	i=0;
	while(i < ret.size()){
		cout<<ret[i]<<" ";
		++i;
	}
	return 0;
}
