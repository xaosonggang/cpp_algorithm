#pragma once
#include "../../Utility/utility.h"

#undef __Debug_Memory__
//#define __Debug_Memory__

//TODO: 双向链表
//TODO: 循环链表

template <typename T> class LinkNode
{
public:
	LinkNode(const T& val, LinkNode* pNextNode = nullptr) : m_Val(val), m_NextNode(pNextNode)
	{

	}

	~LinkNode()
	{
#ifdef __Debug_Memory__
		cout << "LinkNode destructor run:" << m_Val << endl;
#endif // __Debug_Memory__

	}

public:
	T GetVal() const { return m_Val; }
	void SetVal(const T& val) { m_Val = val; }

	LinkNode* GetNextNode() const { return m_NextNode; }
	void SetNextNode(LinkNode* pNode) { m_NextNode = pNode; }

private:
	T m_Val;
	LinkNode* m_NextNode = nullptr;
};

template <typename T> class LinkList
{
public:
	LinkList() = default;
	LinkList(LinkNode<T>* pHead, int nSize) : m_pHead(pHead), m_nSize(nSize)
	{

	}

	~LinkList()
	{
#ifdef __Debug_Memory__
		cout << "LinkList destructor" << endl;
#endif // __Debug_Memory__

		auto pNode = m_pHead;
		while (pNode != nullptr)
		{
			auto pTemp = pNode;
			pNode = pNode->GetNextNode();
			delete pTemp;
		}
	}

public:
	void Insert(int pos, const T& val);

	void Delete(const T& val);
	void DeleteIndex(int index);

	int Search(const T& val);
	T SearchIndex(int index);

	int Update(const T& oldVal, const T& newVal);
	int UpdateIndex(int index, const T& val);

public:
	LinkNode<T>* GetHead()const { return m_pHead; }
	void SetHead(LinkNode<T>* node) { m_pHead = node; }

	int GetSize() const { return m_nSize; }

private:
	LinkNode<T>* m_pHead = nullptr;
	int m_nSize = 0;
};

template <typename T> void LinkList<T>::Insert(int pos, const T& val)
{
	if (pos > m_nSize)
	{
		pos = m_nSize;
	}

	LinkNode<T>* newNode = new LinkNode<T>(val);
	if (newNode == nullptr) {
		return;
	}

	if (m_pHead == nullptr)
	{
		m_pHead = newNode;
		newNode->SetNextNode(nullptr);
		m_nSize = 1;
		return;
	}
	else
	{
		LinkNode<T>* pNode = m_pHead;
		if (pos == 0)
		{
			newNode->SetNextNode(m_pHead);
			m_pHead = newNode;
			++m_nSize;
			return;
		}

		for (int i = 0; i < m_nSize; ++i)
		{
			if (i == pos)
			{
				LinkNode<T>* pNextNode = pNode->GetNextNode();
				pNode->SetNextNode(newNode);
				newNode->SetNextNode(pNextNode);
				++m_nSize;
				return;
			}
			else if ((i == m_nSize - 1) && (i + 1 == pos))
			{
				pNode->SetNextNode(newNode);
				newNode->SetNextNode(nullptr);
				++m_nSize;
				return;
			}
			else
			{
				pNode = pNode->GetNextNode();
			}
		}

		//error handler
		std::cout << "!!!!ERROR" << endl
			<< "!!!!ERROR" << endl
			<< "!!!!ERROR" << endl
			<< "Insert Link List, targPos " << pos << ", now size " << m_nSize << endl;
	}
}

template <typename T> void LinkList<T>::Delete(const T& val)
{
	if (m_pHead == nullptr) return;

	auto pNode = m_pHead;
	LinkNode<T>* pPreNode = nullptr;
	for (int i = 0; i < m_nSize; ++i)
	{
		if (pNode->GetVal() == val)
		{
			if (i == 0)
			{
				auto temp = m_pHead;
				m_pHead = m_pHead->GetNextNode();
				delete temp;
				--m_nSize;
				return;
			}
			else
			{
				pPreNode->SetNextNode(pNode->GetNextNode());
				delete pNode;
				--m_nSize;
				return;
			}
		}
		else
		{
			pPreNode = pNode;
			pNode = pNode->GetNextNode();
		}
	}

	cout << "Delete LinkList failed! value:" << val << endl;
}

template <typename T> void LinkList<T>::DeleteIndex(int index)
{
	if (m_pHead == nullptr) return;
	if (index < 0 || m_nSize <= index) return;

	if (index == 0)
	{
		auto temp = m_pHead;
		m_pHead = m_pHead->GetNextNode();
		delete temp;
		--m_nSize;
		return;
	}

	auto pNode = m_pHead;
	decltype(m_pHead) pPreNode = nullptr;
	for (int i = 0; i < m_nSize; ++i)
	{
		if (i == index)
		{
			pPreNode->SetNextNode(pNode->GetNextNode());
			delete pNode;
			--m_nSize;
			return;
		}
		else
		{
			pPreNode = pNode;
			pNode = pNode->GetNextNode();
		}
	}
}

template <typename T> int LinkList<T>::Search(const T& val)
{
	if (m_pHead == nullptr) return -1;

	auto pNode = m_pHead;
	for (int i = 0; i < m_nSize; ++i)
	{
		if (pNode->GetVal() == val)
		{
			return i;
		}
		else
		{
			pNode = pNode->GetNextNode();
		}
	}
	return -1;
}

template <typename T> T LinkList<T>::SearchIndex(int index)
{
	if (m_pHead == nullptr) return -1;

	auto pNode = m_pHead;
	for (int i = 0; i < m_nSize; ++i)
	{
		if (i == index)
		{
			return pNode->GetVal();
		}
		else
		{
			pNode = pNode->GetNextNode();
		}
	}
	return -1;

}

template <typename T> int LinkList<T>::Update(const T& oldVal, const T& newVal)
{
	if (m_pHead == nullptr) return -1;

	auto pNode = m_pHead;
	for (int i = 0; i < m_nSize; ++i)
	{
		if (pNode->GetVal() == oldVal)
		{
			pNode->SetVal(newVal);
			return -1;
		}
		else
		{
			pNode = pNode->GetNextNode();
		}
	}
	return -1;
}

template <typename T> int LinkList<T>::UpdateIndex(int index, const T& val)
{
	if (m_pHead == nullptr) return -1;

	auto pNode = m_pHead;
	for (int i = 0; i < m_nSize; ++i)
	{
		if (i == index)
		{
			pNode->SetVal(val);
			return i;
		}
		else
		{
			pNode = pNode->GetNextNode();
		}
	}
	return -1;
}

//外部辅助函数
template<typename T> void PrintLinkList(const LinkList<T>& lList)
{
	cout << "<<<Begin Print LinkList>>>" << endl;

	LinkNode<T>* pNode = lList.GetHead();
	if (pNode == nullptr)
	{
		cout << "Link List is empty!!" << endl;
	}
	else
	{
		for (int i = 0; i < lList.GetSize(); ++i)
		{
			cout << pNode->GetVal() << "-->";
			pNode = pNode->GetNextNode();
			if ((i + 1) % 10 == 0) cout << endl;
		}
		cout << "NULL" << endl;
	}

	cout << endl
		<< "<<End Print LinkList>>>" << endl;
	return;
}
