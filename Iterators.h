#pragma once
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                         Nodes
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// <summary>
/// node for singly linked list
/// </summary>
/// <typeparam name="T"></typeparam>
template <class T>
struct SL_Node {
	T data;
	SL_Node<T>* next;

	SL_Node() :data(T()), next(nullptr)					{	}
	SL_Node(T data) :data(data), next(nullptr)				{	}
};

/// <summary>
/// node for doubly linked list
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
struct DL_Node {
	T data;
	DL_Node<T>* next;
	DL_Node<T>* prev;

	DL_Node() :data(T()), next(nullptr), prev(nullptr)			{	}
	DL_Node(T data) : data(data), next(nullptr), prev(nullptr)		{	}
};




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                           Iterators
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace sl{

template <class DataT>
using NodePtr = SL_Node<DataT>*;

template <class DataT>
struct SL_Iterator
{
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = DataT;
	using reference = DataT&;
	using pointer = DataT*;


	explicit SL_Iterator(NodePtr<DataT> start = nullptr) : current(start)	{	}
	SL_Iterator(const SL_Iterator& src) : current(src.current)		{	}

	reference operator*()  const						{ return current->data; }
	pointer operator->() const						{ return &(operator*()); }

	bool operator==(SL_Iterator const& rhs) const				{ return current == rhs.current; }
	bool operator!=(SL_Iterator const& rhs) const				{ return current != rhs.current; }

	SL_Iterator& operator=(SL_Iterator const& src)				{ if (this == &src) { return *this; } current = src; return *this; }

	SL_Iterator& operator++()						{ current = current->next; return *this; }

	SL_Iterator operator++(int)						{ SL_Iterator preincremented = *this; current = current->next; return preincremented; }

	private:
		NodePtr<DataT> current;
	};


template <class DataT>
struct const_SL_Iterator
{
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = DataT;
	using reference = DataT&;
	using pointer = DataT*;



	explicit const_SL_Iterator(NodePtr<DataT> start = nullptr):current_node_ptr(start)	{	}
	const_SL_Iterator(const const_SL_Iterator& src):current_node_ptr(src.current_node_ptr)	{	}

	const reference operator*()  const							{ return current_node_ptr->data; }
	const pointer operator->() const							{ return &(operator*()); }

	bool operator==(const const_SL_Iterator const& rhs) const				{ return current_node_ptr == rhs.current_node_ptr; }
	bool operator!=(const const_SL_Iterator const& rhs) const				{ return current_node_ptr != rhs.current_node_ptr; }


	const_SL_Iterator& operator++()								{ current_node_ptr = current_node_ptr->next; return *this; }

	const_SL_Iterator operator++(int)							{ const_SL_Iterator preincremented = *this; current_node_ptr = current_node_ptr->next; return preincremented; }

private:
	NodePtr<DataT> current_node_ptr;
};




}

namespace dl{
template<class DataT>
using NodePtr = DL_Node<DataT>*;


template <class DataT>
struct DLL_Iterator
{
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = DataT;
	using reference = DataT&;
	using pointer = DataT*;
	
	explicit DLL_Iterator(NodePtr<DataT> start = nullptr) : current_node(start)		{	}
	DLL_Iterator(const DLL_Iterator& src) : current_node(src.current_node)			{	}

	reference operator*()  const								{ return current_node->data; }
	pointer operator->() const																	{ return &(operator*()); }

	bool operator==(DLL_Iterator const& rhs) const						{ return current_node == rhs.current_node; }
	bool operator!=(DLL_Iterator const& rhs) const						{ return current_node != rhs.current_node; }


	DLL_Iterator operator+(int rhs) { for (int i = 0; i < rhs; i++)				{ current_node = current_node->next; } return *this; }

	DLL_Iterator& operator=(DLL_Iterator const& src)					{ if (this == &src) { return *this; }	current_node = src.current_node;	return *this; }

	DLL_Iterator& operator+=(int rhs)							{ for (int i = 0; i < rhs; i++) { current_node = current_node->next; } return *this; }

	DLL_Iterator& operator++()																	{ current_node = current_node->next; return *this; }

	DLL_Iterator operator++(int)								{ DLL_Iterator predecremented = *this; current_node = current_node->next; return predecremented; }
		 
	DLL_Iterator& operator--()																	{ current_node = current_node->prev; return *this; }

	DLL_Iterator operator--(int)								{ DLL_Iterator predecremented = *this; current_node = current_node->prev; return predecremented; }

private:
	NodePtr<DataT> current_node;
};


template <class DataT>
struct const_DLL_Iterator
{
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = DataT;
	using reference = DataT&;
	using pointer = DataT*;

	explicit const_DLL_Iterator(NodePtr<DataT> start = nullptr) : current_node(start)	{	}
	const_DLL_Iterator(const const_DLL_Iterator& src) : current_node(src.current_node)	{	}

	const reference operator*()  const							{ return current_node->data; }
	const pointer operator->() const							{ return &(operator*()); }

	bool operator==(const_DLL_Iterator const& rhs) const					{ return current_node == rhs.current_node; }
	bool operator!=(const_DLL_Iterator const& rhs) const					{ return current_node != rhs.current_node; }


	const_DLL_Iterator operator+(int rhs)							{ for (int i = 0; i < rhs; i++) { current_node = current_node->next; } return *this; }

	const_DLL_Iterator& operator+=(int rhs)							{ for (int i = 0; i < rhs; i++){ current_node = current_node->next; } return *this; }

	const_DLL_Iterator& operator++()							{ current_node = current_node->next; return *this; }

	const_DLL_Iterator operator++(int)							{ const_DLL_Iterator predecremented = *this; current_node = current_node->next; return predecremented; }

	const_DLL_Iterator& operator--()							{ current_node = current_node->prev; return *this; }

	const_DLL_Iterator operator--(int)							{ const_DLL_Iterator predecremented = *this; current_node = current_node->prev; return predecremented; }

private:
	NodePtr<DataT> current_node;
};

}

