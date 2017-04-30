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
	//delete _val;//��Ҫô��
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
			return this->_lnode;//˵������û�и�Ҷ�ڵ㣬����Ҫ����һ��ָ��null��ָ�������
		}
	}
	else if (val > _val)
	{
		if (_rnode != 0)return _rnode->findval(val,_rnode);
		else
		{
			return this->_lnode;//˵������û�и�Ҷ�ڵ㣬����Ҫ����һ��ָ��null��ָ�������
		}
	}
	else
		return FarNodePToThis;//���ظ��׽ڵ���ָ�򱾽ڵ��ָ������á�
}
template<typename Type>
BTnode<Type>&BTnode<Type>::findlleaf()//��ȫ���Բ��õݹ飬�õݹ鷴��������ջ����
{
	if (_lnode != nullptr)
	{
		return _lnode->findlleaf();
	}
	else
	{
		return *this;//������ڵ��lnodeΪnull��ô���ر��ڵ������
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

	BTnode<Type> *&oldroot = find_val(val);//���ص���ָ��ɾ���ڵ�ĸ��ڵ��ָ�������
	if (oldroot == nullptr)//���û�ҵ�Ҫɾ���ĵ㣬��ôֱ�ӷ���false
	{
		cerr << "The Val to remove do not exit!" << endl;
		return false;
	}

	BTnode<Type>*oldleft = oldroot->_lnode;//����������Ϊ�����Ϊnull
	BTnode<Type>*oldrnode = oldroot->_rnode;
	//��Ҫɾ���ĵ�����ӽڵ�Ϊ��ʱ�������������ҲΪ�գ���ôɾ���ڵ�ֱ�ӷ��أ������������Ϊ�գ���ô�������ӽڵ��Ϊ�ýڵ㱾��
	if (oldrnode == nullptr)
	{
		if (oldleft == nullptr)
		{
			delete oldroot;
			oldroot = nullptr;//˵��ɾ������Ҷ�ڵ㣬ֱ�ӽ�����ڴ淵�ظ��ڴ棬��oldroot��Ϊnull��û���ã�ֻ�ǽ�oldroot������������ֵ��Ϊ0�ˣ���
			return true;//��û�н��丸�ڵ�ָ������ڴ��ָ����Ϊnull������Ȼָ������ڴ档������Ҫfind_val�����丸�ڵ�ָ������ڵ�ָ������ã�
		}
		else
		{
			//*oldroot = *oldleft;//�޷�����bt����_root������Ϊ�㲢��֪��ɾ�����ǲ��Ǹ��ڵ�!
			//ͬʱҲ����Ҫ��Ҫɾ���ڵ��lnode��rnode��Ϊnull����Ϊ�Ѿ�����ֵΪ�µ�ֵ��
			//delete oldleft;//����Ҫ������Ǹ��ڵ�Ļ�����Ὣ_rootָ����ڴ����¹��츳ֵ��ɾ����ֻ�Ǵ�����ڵ���Ǹ��ڵ�
			//oldleft = nullptr;
			//���õİ취
			BTnode<Type>*tmp = oldroot;//��ָ��ɾ���ڵ��ָ�����������ɾ���ڵ��ʱ��ʹ��
			oldroot = oldleft;//��ָ��ɾ���ڵ�ĸ��ڵ��ָ��ֵ����Ϊָ������ڵ�
			delete tmp;//��ԭ���ķ����Ƚϣ�����һ��node�Ĺ��죬����ָ��Ĺ��졣
			return true;
		}
	}
	else
	{
		//*oldroot = *newroot;//ʹ�����صĸ�ֵ����������Ҫɾ���ڵ��val����lnode��rnode������Ϊ���ҽڵ��ֵ��
		//����ԭ�����ҽڵ����û��ɾ����
		//delete newroot;//��ԭ�����ӽڵ���ڴ���գ�������_val,�Լ����ڵ�ָ�루�洢ָ��ı������Զ�����ô����
		BTnode<Type>*tmp = oldroot;//��ָ��ɾ���ڵ��ָ�����������ɾ���ڵ��ʱ��ʹ��
		oldroot = oldrnode;//��ָ��ɾ���ڵ�ĸ��ڵ��ָ��ֵ����Ϊָ��ɾ���ڵ���ҽڵ�
		delete tmp;//��ԭ���ķ����Ƚϣ�����һ��node�Ĺ��죬����ָ��Ĺ��졣
		if (oldleft == nullptr)
			return true;
		else
		{
			if (oldroot->_lnode != 0)//����µĽڵ��������������ô�ҵ��µĽڵ������ڵ�
									//����ɾ���ڵ���������Ƶ�����ڵ�����ӽڵ�
			{
				BTnode<Type>&lleaf = oldroot->findlleaf();
				lleaf._lnode = oldleft;
			}
			else
			{
				oldroot->_lnode = oldleft;//����ɾ���ڵ���������Ƶ����ڽڵ�����ӽڵ���
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

