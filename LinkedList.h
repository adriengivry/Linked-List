#ifndef __LINKED_LIST__
#define __LINKED_LIST__

template<class T>
struct LinkedListNode
{
	T m_value;
	LinkedListNode<T>* m_next;
};

template<class T>
class LinkedList
{
public:
	LinkedList() : __size(0) {}
	~LinkedList() { clear(); }

	void add(T p_toAdd);
	void remove(unsigned int p_index);
	void clear();
	const unsigned int& size() const;

	const T& operator[](unsigned int p_index);

private:
	LinkedListNode<T>* __head;
	LinkedListNode<T>* __tail;
	unsigned int __size;
};

template <class T>
void LinkedList<T>::add(T p_toAdd)
{
	LinkedListNode<T>* node = new LinkedListNode<T>;
	node->m_value = p_toAdd;
	node->m_next = nullptr;

	if (!__head)
	{
		__head = node;
		__tail = node;
	}
	else
	{
		__tail->m_next = node;
		__tail = node;
	}

	++__size;
}

template <class T>
void LinkedList<T>::remove(unsigned int p_index)
{
	LinkedListNode<T>* toRemove = __head;
	LinkedListNode<T>* previous = nullptr;

	while (p_index--)
	{
		previous = toRemove;
		toRemove = toRemove->m_next;
	}

	if (toRemove == __head)
	{
		__head = __head->m_next;
		if (!__head)
			__tail = nullptr;
	}
	else
	{
		previous->m_next = toRemove->m_next;
	}

	--__size;

	if (toRemove)
		delete toRemove;
}

template <class T>
void LinkedList<T>::clear()
{
	LinkedListNode<T>* current = __head;
	LinkedListNode<T>* toDelete = current;

	while (current)
	{
		toDelete = current;
		current = current->m_next;
		delete toDelete;
	}

	__head = nullptr;
	__tail = nullptr;
	__size = 0;
}

template <class T>
const unsigned int& LinkedList<T>::size() const
{
	return __size;
}

template <class T>
const T& LinkedList<T>::operator[](unsigned int p_index)
{
	LinkedListNode<T>* current = __head;

	while (p_index--)
		current = current->m_next;

	return current->m_value;
}

#endif // !__LINKED_LIST__