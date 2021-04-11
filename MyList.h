#pragma once
template <class T>
struct Node
{
public:
	T  p;
	Node* NextNode = nullptr;
	int num = 0;
};

template <class T>
class MyList :public Node<T>
{
public:
	MyList() {}
	~MyList() {}
	Node<T>* HeadNode;
	Node<T>* EndNode;
	int size = 0;
	void Push_Back(T p);
	void Push_Front(T p);
	void erase(int num);
	void Pop_Back();
	void Pop_Front();

	T Begin();
	T End();
	T Find(int num);
	int Size() { return size; };
};

template<class T>
inline void MyList<T>::erase(int num)
{
	Node <T>* node1 = HeadNode, * node2 = nullptr, * NewNode = HeadNode;
	size--;
	if (num == 1)
	{
		Pop_Front();
		return;
	}
	if (num == size)
	{
		Pop_Back();
		return;
	}
	for (int i = 1; i <= num+1; i++)
	{
		NewNode = NewNode->NextNode;
		if (i == num)
		{
			node2 = NewNode;
			break;

		}
	}
	for (int i = 1; i <= num+1 ; i++)
	{
		node1 = node1->NextNode;
		if (i == num-2 )
		{
			node1->NextNode = node2;
			break;
		}
	}
}
template<class T>
inline void MyList<T>::Pop_Back()
{
	size--;
	free(EndNode);
	Node<T>* no = HeadNode;
	for (int i = 0; i < size; i++)
	{
		if (i < size - 1)
			no = no->NextNode;

	}
	EndNode = no;
}
template<class T>
inline void MyList<T>::Pop_Front()
{
	HeadNode = HeadNode->NextNode;
	size--;
}
template<class T>
inline void MyList<T>::Push_Back(T  p)
{
	Node<T>* newp = new Node<T>;
	newp->p = p;

	if (HeadNode == nullptr)
	{
		HeadNode = newp;
		EndNode = newp;
	}
	else

		EndNode->NextNode = newp;
	EndNode = newp;

	size++;
}
template<class T>
inline void MyList<T>::Push_Front(T  p)
{
	Node<T>* newp = new Node<T>;
	newp->p = p;

	newp->NextNode = HeadNode;
	HeadNode = newp;

	size++;
}
template<class T>
inline T MyList<T>::Find(int num)
{
	Node<T>* NowNode = HeadNode;
	if (num >= Size())
		return EndNode->p;
	for (int i = 0; i < num; i++)
		NowNode = NowNode->NextNode;
	if (num == 0)
	{
		return HeadNode->p;
	}
	return NowNode->p;
}

template<class T>
inline T MyList<T>::Begin()
{
	return HeadNode->p;
}

template<class T>
inline T MyList<T>::End()
{
	return EndNode->p;
}
