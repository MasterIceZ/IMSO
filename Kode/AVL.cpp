#ifndef __IMPLE_AVL__
#define __IMPLE_AVL__

#include <algorithm>
#include <iostream>

using namespace std;

class AVL{
private:
	struct Node{
		int val, height;
		Node *l, *r;
	};
	Node* root;
	int height(Node* tree){
		return (tree == NULL ? -1: tree->height);
	}
	Node* rotateRight(Node* &tree){
		Node* now = tree->l;
		tree->l = now->r;
		now->r = tree;
		tree->height = max(height(tree->l), height(tree->r)) + 1;
		now->height = max(height(now->l), height(now->r)) + 1;
		return now;
	}
	Node* rotateLeft(Node* &tree){
		Node* now = tree->r;
		tree->r = now->l;
		now->l = tree;
		tree->height = max(height(tree->l), height(tree->r)) + 1;
		now->height = max(height(now->l), height(now->r)) + 1;
		return now;
	}
	Node* rotateRightRight(Node* tree){
		tree->l = rotateLeft(tree->l);
		return rotateRight(tree);
	}
	Node* rotateLeftLeft(Node* tree){
		tree->r = rotateRight(tree->r);
		return rotateLeft(tree);
	}
	Node* insert(int v, Node* tree){
		if(tree == NULL){
			tree = new Node;
			tree->val = v;
			tree->height = 0;
			tree->l = tree->r = NULL;
		}
		else if(v < tree->val){
			tree->l = insert(v, tree->l);
			if(height(tree->l) - height(tree->r) == 2){
				if(tree->l->val > v){
					tree = rotateRight(tree);
				}
				else{
					tree = rotateRightRight(tree);
				}
			}
		}
		else if(v > tree->val){
			tree->r = insert(v, tree->r);
			if(height(tree->r) - height(tree->l) == 2){
				tree = rotateLeft(tree);
			}
			else{
				tree = rotateLeftLeft(tree);
			}
		}
		tree->height = max(height(tree->l), height(tree->r));
		return tree;
	}
	void dfs(Node* tree){
		if(tree == NULL){
			return ;
		}
		dfs(tree->l);
		cout << tree->val << " ";
		dfs(tree->r);
	}
public:
	AVL(){
		root = NULL;
	}
	void insert(int v){
		root = insert(v, root);
	}
	void show(){
		dfs(root);
		cout << "\n";
	}
};
#endif

AVL tree;

int main(){
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.show();
	return 0;
}
