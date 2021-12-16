#pragma once

#include "../../Utility/utility.h"

template<typename T> class StackNode
{
public:
	StackNode() = default;
	StackNode(T val, StackNode<T>* pNode = nullptr) :
		m_Val(val), m_NextNode(pNode)
	{

	}
	~StackNode()
	{
		cout << "StackNode destructor:" << m_Val << endl;
	}

	StackNode(const StackNode<T>& node) = delete;
	StackNode<T>& operator=(const StackNode<T>& node) = delete;

public:
	T GetVal()const { return m_Val; }
	void SetVal(const T& val) { m_Val = val; }

	StackNode<T>* GetNextNode()const { return m_NextNode; }
	void SetNextNode(StackNode<T>* val) { m_NextNode = val; }

private:
	T m_Val;
	StackNode<T>* m_NextNode = nullptr;
};

template<typename T> class StackClass
{
public:
	StackClass() = default;

	~StackClass()
	{
		cout << "StackClass destructor!" << endl;
		auto pNode = m_Head;
		while (pNode)
		{
			auto pTemp = pNode;
			pNode = pNode->GetNextNode();
			delete pTemp;
		}
	}

	StackClass(const StackClass<T>& stack) = delete;
	StackClass<T>& operator=(const StackClass<T>& stack) = delete;

public:
	void Push(const T& val);
	T Pop();
	T Peek();
	bool IsEmpty();
	int GetSize();

public:
	StackNode<T>* GetHead() const { return m_Head; }

private:
	StackNode<T>* m_Head = nullptr;
};

template<typename T> void StackClass<T>::Push(const T& val)
{
	StackNode<T>* pNewNode = new StackNode<T>(val);
	if (pNewNode == nullptr) return;

	if (m_Head == nullptr)
	{
		m_Head = pNewNode;
		return;
	}
	
	pNewNode->SetNextNode(m_Head);
	m_Head = pNewNode;
	return;
}

template<typename T> T StackClass<T>::Pop()
{
	static T defVal;
	if (m_Head == nullptr) return defVal;

	auto node = m_Head;
	m_Head = m_Head->GetNextNode();
	T val = node->GetVal();
	delete node;
	return val;
}

template<typename T> T StackClass<T>::Peek()
{
	static T defVal;
	if (m_Head == nullptr) return defVal;

	return m_Head->GetVal();
}

template<typename T> bool StackClass<T>::IsEmpty()
{
	return (m_Head == nullptr);
}

template<typename T> int StackClass<T>::GetSize()
{
	int size = 0;
	auto pNode = m_Head;
	while (pNode)
	{
		++size;
		pNode = pNode->GetNextNode();
	}
	return size;
}

template<typename T> void PrintStack(const StackClass<T>& stack)
{
	cout << "<<Print Stack Begin>>>" << endl;

	if (stack.GetHead() == nullptr)
	{
		cout << "Stack is Empty!!!" << endl;
		return;
	}

	auto pNode = stack.GetHead();
	int size = 0;
	while (pNode)
	{
		cout << pNode->GetVal() << "-->";
		pNode = pNode->GetNextNode();
		if (++size % 10 == 0)
			cout << endl;
	}
	cout << "NULL" << endl;

	cout << "<<Print Stack End>>>" << endl;
}
