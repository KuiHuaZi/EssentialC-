#include"BinaryTree.h"
template<typename valType>
BTnode<valType>::BTnode(const valType &val)
	:_lnode(0),_rnode(0),_val(val),_cnt(0)
{
	
}
template<typename valType>
BTnode<valType>::BTnode(const BTnode&node)
	: _lnode(node._lnode), _rnode(node._rnode), _val(node._val), _cnt(node._cnt)
{

}
template<typename valType>
BTnode<valType>::~BTnode()
{
	_lnode = nullptr;
	_rnode = nullptr;
	//delete _val;//需要么？
}
template<typename valType>
BTnode<valType> & BTnode<valType>::operator=(const BTnode &node)
{
	if (this != &node)
	{

		_lnode = node._lnode;
		_rnode = node._rnode;
		_val = node._val;
		_cnt = node._cnt;
	}
	return *this;
}
template<typename valType>
void BTnode<valType>::insert_val(const valType &val)
{
	if (val == _val)
		_cnt++;
	else if (val > _val)
	{
		if (_rnode != 0)
			_rnode->insert_val(val);
		else
			_rnode = new BTnode(val);
	}
	else if (val < _val)
	{
		if (_lnode != 0)
			_lnode->insert_val(val);
		else
			_lnode = new BTnode(val);
	}
	return;
}
template<typename Type>
void BTnode<Type>::inorder(ostream&out)
{
	if (_lnode != 0)
	{
		_lnode->inorder(out);
	}
	out << _val<<" ";
	if (_rnode != 0)
	{
		_rnode->inorder(out);
	}
	return;
}
template<typename Type>
void BTnode<Type>::preorder(ostream&out)
{
	out << _val << " ";
	if (_lnode != 0)
	{
		_lnode->preorder(out);
	}
	if (_rnode != 0)
	{
		_rnode->preorder(out);
	}
	return;
}
template<typename Type>
void BTnode<Type>::postorder(ostream&out)
{
	
	if (_lnode != 0)
	{
		_lnode->postorder(out);
	}
	if (_rnode != 0)
	{
		_rnode->postorder(out);
	}
	out << _val << " ";
	return;
}
template<typename Type>
void BTnode<Type>::clear()
{
	if (_lnode != 0)
	{
		_lnode->clear();
	}
	if (_rnode != 0)
	{
		_rnode->clear();
	}
	delete this;
}
template<typename Type>
BTnode<Type>*&BTnode<Type>::findval(const Type &val,BTnode*&FarNodePToThis)
{
	if (val < _val)
	{
		if (_lnode != 0)return _lnode->findval(val,_lnode);
		else
		{
			return this->_lnode;//说明本树没有该叶节点，但是要返回一个指向null的指针的引用
		}
	}
	else if (val > _val)
	{
		if (_rnode != 0)return _rnode->findval(val,_rnode);
		else
		{
			return this->_lnode;//说明本树没有该叶节点，但是要返回一个指向null的指针的引用
		}
	}
	else
		return FarNodePToThis;//返回父亲节点里指向本节点的指针的引用。
}
template<typename Type>
BTnode<Type>&BTnode<Type>::findlleaf()//完全可以不用递归，用递归反而增加了栈开销
{
	if (_lnode != nullptr)
	{
		return _lnode->findlleaf();
	}
	else
	{
		return *this;//如果本节点的lnode为null那么返回本节点的引用
	}
		
	
}
template<typename Type>
BinaryTree<Type>::BinaryTree()
	:_root(0), _cnt(0)
{

}
template<typename Type>
BinaryTree<Type>::BinaryTree(const BinaryTree&tree)
{
	if (this != &tree)
	{
		clear();
		_cnt = tree._cnt;
		copy(_root, tree._root);
	}
}
template<typename Type>
BinaryTree<Type>::~BinaryTree()
{
	if (_root = 0)return;
	clear();
}
template<typename Type>
BinaryTree<Type>& BinaryTree<Type>::operator=(const BinaryTree&tree)
{
	if (this != tree)
	{
		clear();
		copy(_root, tree._root);
	}
	return *this;
}
template<typename Type>
void BinaryTree<Type>::insert(const Type&val)
{
	if (_root ==0)
	{
		
		_root = new BTnode<Type>(val);
	}
	else
	{
		_root->insert_val(val);
	}
	return;
	
}
template<typename Type>
void BinaryTree<Type>::inorderPrint(ostream &out)
{
	out << "inorder: ";
	if (_root != nullptr)
	{
		_root->inorder(out);
	}
	out << "\n";
	return;

}
template<typename Type>
void BinaryTree<Type>::preorderPrint(ostream &out)
{
	out << "preorder: ";
	if (_root != nullptr)
	{
		_root->preorder(out);
	}
	out << "\n";
	return;

}
template<typename Type>
void BinaryTree<Type>::postorderPrint(ostream &out)
{
	out << "postorder: ";
	if (_root != nullptr)
	{
		_root->postorder(out);
	}
	out << "\n";
	return;

}
template<typename Type>
void BinaryTree<Type>::clear()
{
	if (_root == 0)return;
	_root->clear();
	_root = 0;
}
template<typename Type>
BTnode<Type>*& BinaryTree<Type>::find_val(const Type &val)
{
	if (_root == nullptr)return _root;
	return _root->findval(val,_root);
}
template<typename Type>
bool BinaryTree<Type>::remove(const Type& val)
{

	BTnode<Type> *&oldroot = find_val(val);//返回的是指向被删除节点的父节点的指针的引用
	if (oldroot == nullptr)//如果没找到要删除的点，那么直接返回false
	{
		cerr << "The Val to remove do not exit!" << endl;
		return false;
	}

	BTnode<Type>*oldleft = oldroot->_lnode;//不用引用因为其可能为null
	BTnode<Type>*oldrnode = oldroot->_rnode;
	//当要删除的点的右子节点为空时，如果其左子树也为空，那么删除节点直接返回，如果左子树不为空，那么将其左子节点变为该节点本身
	if (oldrnode == nullptr)
	{
		if (oldleft == nullptr)
		{
			delete oldroot;
			oldroot = nullptr;//说明删除的是叶节点，直接将这块内存返回给内存，将oldroot赋为null并没有用，只是将oldroot这个变量里面的值设为0了，。
			return true;//并没有将其父节点指向这块内存的指针设为null，其依然指向这块内存。所以需要find_val返回其父节点指向这个节点指针的引用！
		}
		else
		{
			//*oldroot = *oldleft;//无法更新bt树的_root啊，因为你并不知道删除的是不是根节点!
			//同时也不需要将要删除节点的lnode和rnode置为null，因为已经被赋值为新的值了
			//delete oldleft;//不需要，如果是根节点的话，你会将_root指向的内存重新构造赋值，删除的只是代替根节点的那个节点
			//oldleft = nullptr;
			//更好的办法
			BTnode<Type>*tmp = oldroot;//将指向被删除节点的指针存下来，在删除节点的时候使用
			oldroot = oldleft;//将指向被删除节点的父节点的指针值更新为指向其左节点
			delete tmp;//和原来的方法比较，少了一次node的构造，多了指针的构造。
			return true;
		}
	}
	else
	{
		//*oldroot = *newroot;//使用重载的赋值操作符，将要删除节点的val，和lnode，rnode都更新为其右节点的值。
		//可是原来的右节点好像没有删除？
		//delete newroot;//将原来右子节点的内存回收，包括了_val,以及其内的指针（存储指针的变量会自动回收么）会
		BTnode<Type>*tmp = oldroot;//将指向被删除节点的指针存下来，在删除节点的时候使用
		oldroot = oldrnode;//将指向被删除节点的父节点的指针值更新为指向被删除节点的右节点
		delete tmp;//和原来的方法比较，少了一次node的构造，多了指针的构造。
		if (oldleft == nullptr)
			return true;
		else
		{
			if (oldroot->_lnode != 0)//如果新的节点存在左子树，那么找到新的节点的最左节点
									//将被删除节点的左子树移到最左节点的左子节点
			{
				BTnode<Type>&lleaf = oldroot->findlleaf();
				lleaf._lnode = oldleft;
			}
			else
			{
				oldroot->_lnode = oldleft;//将被删除节点的左子树移到现在节点的左子节点上
			}
		}
	}
	
	return true;

}
void btree()
{
	printf("input '+'with number to insert, '-'with number to remove,'c' to clear,'i' to inorder,'r' to preorder,'o' to postorder!\n");
	BinaryTree<int> bt;
	while (true)
	{
		char cmd;
		cin >> cmd;
		int i;
		switch (cmd)
		{
		case'+':
			cin >> i;
			bt.insert(i);
			break;
		case'-':
			cin >> i;
			if (bt.remove(i))
				cout << "remove success" << endl;
			else
				cout << "remove failed" << endl;
			break;
		case'c':
			bt.clear();
			break;
		case'i':
			bt.inorderPrint(cout);
			break;
		case'r':
			bt.preorderPrint(cout);
			break;
		case'o':
			bt.postorderPrint(cout);
			break;
		default:
			break;
		}

	}
}

