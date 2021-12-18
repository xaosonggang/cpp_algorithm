#pragma once

template<typename T> class QueueNode
{
public:
	QueueNode(const T& val) : m_Val(val)
	{
	}
	~QueueNode()
	{
		cout << "QueueNode Destructor:" << m_Val << endl;
	}

public:
	T GetVal() const { return m_Val; }
	void SetVal(const T& val) { m_Val = val; }

	QueueNode<T>* GetNextNode() const { return m_NextNode; }
	void SetNextNode(QueueNode<T>* pNextNode) { m_NextNode = pNextNode; }

private:
	T m_Val;
	QueueNode<T>* m_NextNode = nullptr;
};

template<typename T> class QueueData
{
public:
	QueueData() = default;

	~QueueData()
	{
		auto pNode = m_pHead;
		while (pNode != nullptr)
		{
			auto pTemp = pNode;
			pNode = pNode->GetNextNode();
			delete pTemp;
		}
		m_pHead = nullptr;
		m_pTail = nullptr;
	}

public:
	void EnQueue(const T& val);
	T DeQueue();
	T Peek();

	bool IsFull();
	bool IsEmpty();

public:
	QueueNode<T>* GetHead()const { return m_pHead; }
	void SetHead(QueueNode<T>* pHead) { m_pHead = pHead; }

	QueueNode<T>* GetTail() const { return m_pTail; }
	void SetTail(QueueNode<T>* pTail) { m_pTail = pTail; }

private:
	QueueNode<T>* m_pHead = nullptr;
	QueueNode<T>* m_pTail = nullptr;
};

template<typename T> void QueueData<T>::EnQueue(const T& val)
{
	QueueNode<T>* pNode = new QueueNode<T>(val);
	if (m_pHead == nullptr)
	{
		m_pHead = pNode;
		m_pTail = pNode;
		return;
	}

	m_pTail->SetNextNode(pNode);
	m_pTail = pNode;
	return;
}

template<typename T> T QueueData<T>::DeQueue()
{
	static T defaultVal;
	if (m_pTail == nullptr)
	{
		return defaultVal;
	}
	if (m_pHead == m_pTail)
	{
		T val = m_pHead->GetVal();
		delete m_pHead;
		m_pHead = nullptr;
		m_pTail = nullptr;
		return val;
	}

	auto pNode = m_pHead;
	m_pHead = m_pHead->GetNextNode();
	T val = pNode->GetVal();
	delete pNode;
	return val;
}

template<typename T> T QueueData<T>::Peek()
{
	static T defaultVal;
	if (m_pHead == nullptr)
	{
		return defaultVal;
	}
	return m_pHead->GetVal();
}

template<typename T> bool QueueData<T>::IsFull()
{
	return false;
}

template<typename T> bool QueueData<T>::IsEmpty()
{
	return m_pHead == nullptr;
}

template<typename T> void PrintQueue(const QueueData<T>& qData)
{
	cout << "<<<Print Queue Data Begin!>>>" << endl;
	auto pNode = qData.GetHead();
	if (pNode == nullptr)
	{
		cout << "Empty Queue Data!" << endl;
	}
	int index = 0;
	while (pNode != nullptr)
	{
		cout << pNode->GetVal() << "-->";
		pNode = pNode->GetNextNode();
		if (++index % 10 == 0) cout << endl;
	}
	cout << endl;

	cout << "<<<Print Queue Data End!>>>" << endl;
}
