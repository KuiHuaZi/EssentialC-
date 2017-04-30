#pragma once
#include<iostream>
#include<vector>
using namespace std;
template<typename Type>
class BinaryTree;
void btree();
template<typename valType>

class BTnode
{
	friend class BinaryTree<valType>;
public:
	
	BTnode(const valType &val);
	
	~BTnode();
	
private:
	BTnode&operator =(const BTnode&);//应该私有，因为只在btree类中使用。在外面不能让其被copy构造和=
	BTnode(const BTnode&);
	BTnode();
	valType _val;
	BTnode *_lnode;
	BTnode *_rnode;
	int _cnt;
	void insert_val(const valType &val);
	void inorder(ostream&out = cout);
	void preorder(ostream&out = cout);
	void postorder(ostream&out = cout);
	void clear();
	BTnode*&findval(const valType &,BTnode*&);
	BTnode&findlleaf();
};
template<typename Type>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(const BinaryTree&);
	~BinaryTree();
	BinaryTree& operator=(const BinaryTree&);
	bool empty() { return _root == 0; }
	void insert(const Type &val);
	void inorderPrint(ostream &out = cout);
	void preorderPrint(ostream &out = cout);
	void postorderPrint(ostream &out = cout);
	bool remove(const Type&val);
	void clear();
private:
	BTnode<Type>*_root;
	int _cnt;
	bool copy(BTnode <Type>*tar, BTnode<Type>*src);
	BTnode<Type>*&find_val(const Type &val);


};


