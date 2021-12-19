#pragma once
#include "../../Utility/utility.h"

using std::shared_ptr;
using std::make_shared;

template<typename T, typename K> class HashNodeData
{
public:
	HashNodeData() = default;
	HashNodeData(const T& val, const K& key, shared_ptr<HashNodeData<T, K>> pNode = nullptr) :
		m_Val(val), m_Key(key), m_NextNode(pNode)
	{

	}

	~HashNodeData()
	{
		cout << "HashNodeData destructor val:" << m_Val << ", key:" << m_Key <<endl;
	}

public:
	T GetVal()const { return m_Val; }
	void SetVal(const T& val) { m_Val = val; }
	K GetKey() const { return m_Key; }
	void SetKey(const K& key) { m_Key = key; }

	shared_ptr<HashNodeData<T, K>> GetNextNode()const { return m_NextNode; }
	void SetNextNode(shared_ptr<HashNodeData<T, K>> pNode) { m_NextNode = pNode; }

private:
	T m_Val;
	K m_Key;
	shared_ptr<HashNodeData<T, K>> m_NextNode;
};


template<typename T, typename K> class HashListMap
{
public:
	HashListMap() = delete;
	HashListMap(int nIndex, shared_ptr<HashNodeData<T, K>> pNode = nullptr) :
		m_Index(nIndex), m_Head(pNode)
	{

	}

	~HashListMap()
	{
		cout << "HashListMap destructor!" << endl;
		//auto pNode = m_Head;
		//while (pNode != nullptr)
		//{
		//	auto temp = pNode;
		//	pNode = pNode->GetNextNode();
		//}
	}

public:
	void Add(const T& val, const K& key);


public:
	int GetIndex() const { return m_Index; }
	void SetIndex(int val) { m_Index = val; }

	shared_ptr<HashNodeData<T, K>> GetHead()const { return m_Head; }
	void SetHead(shared_ptr<HashNodeData<T, K>> val) { m_Head = val; }

private:
	int m_Index;
	shared_ptr<HashNodeData<T, K>> m_Head;
};

template<typename T, typename K> class HashMap
{
public:
	HashMap() = delete;
	HashMap(const unsigned nKeyCount)
	{
		for (int i = 0; i < nKeyCount; ++i)
		{
			//m_KeyVec.push_back();

		}
	}


public:


private:
	vector<K> m_KeyVec;
	vector<HashListMap<T, K>> m_HLMap;

};

template<typename T, typename K> void HashListMap<T, K>::Add(const T& val, const K& key)
{
	shared_ptr<HashNodeData<T, K>> pNode = make_shared<HashNodeData<T, K>>(val, key);
	if (pNode == nullptr) return;

	if (m_Head == nullptr)
	{
		m_Head = pNode;
		return;
	}

	pNode->SetNextNode(m_Head);
	m_Head = pNode;
	return;
}

template<typename T, typename K> void PrintHashListMap(const HashListMap<T, K>& hMap)
{
	cout << "<<<Print HashListMap Begin>>>" << endl;
	cout << "HashListMap index:" << hMap.GetIndex() << endl;

	if (hMap.GetHead() == nullptr)
	{
		cout << "Empty HashList!!" << endl;
	}

	auto pNode = hMap.GetHead();
	int index = 0;
	while (pNode != nullptr)
	{
		cout << "[" << pNode->GetKey() << "," << pNode->GetVal() << "]-->";
		pNode = pNode->GetNextNode();
		if (++index % 10 == 0) cout << endl;
	}
	cout << endl;

	cout << "<<<Print HashListMap End>>>" << endl;
}
