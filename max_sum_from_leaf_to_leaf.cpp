#include <iostream>
using namespace std;

long long max_sum = INT_MIN;
struct node{
	long data;
	node *left, *right;
};

node* insert(long long val){
	node * temp = new node();
	temp->data = val;
	temp->left = temp->right = NULL;
	return temp;
}

long long find_max_sum(node * root){
	if (root == NULL)
	{
		return 0;
	}

	long long ls = find_max_sum(root->left);
	long long rs = find_max_sum(root->right);
	long long sum = ls+rs+root->data;
	if(sum>max_sum){
		max_sum = sum;
	}
	if (root->left!=NULL && root->right!=NULL)
	{
		return max(ls,rs)+root->data;
	}
	else if(root->left==NULL){
		return rs + root->data;
	}
	else{
		return ls + root->data;
	}

}



int main(){

	struct node* root = insert(5);
	root->left = insert(1);
	root->right = insert(16);
	root->left->left = insert(-8);
	// root->left->right = insert(1);

	find_max_sum(root);

	cout<<max_sum<<"\n";
}