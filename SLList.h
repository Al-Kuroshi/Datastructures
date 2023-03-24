#pragma once
#include<iostream>
#include<functional>
#include"Iterators.h"

namespace sl
{

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//                                                         Class Defs
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	template <class T>
	using Node = SL_Node<T>;
	template<class T>
	using NodePtr = SL_Node<T>*;

	/// <summary>
	/// singly linked list
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template <class T>
	class list {
	public:

		using iterator			=	SL_List_Iterator<T>;
		using const_iterator	=	const_SL_List_Iterator<T>;

		list(void) :head(nullptr), tail(nullptr), m_size(0)					{	}

		list(std::initializer_list<T> list);
		~list();

		size_t size()														{ return m_size; }
		bool empty()														{ return head == nullptr; }

		//void push_at(const_iterator where,T data);
		void push_front(T data);
		void push_back(T data);
		void pop_front();
		void pop_back();



		/*template<class... Args>
		void emplace_front(const_iterator where,Args&&... args);*/
		template<class... Args>
		void emplace_front(Args&&... args);
		template<class... Args>
		void emplace_back(Args&& ...args);

		int search(T data);
		int delete_node(T data);

		iterator begin() 													{ return iterator(head); }
		iterator end() 														{ return iterator(tail->next); }

		const_iterator begin() const										{ return const_iterator(head); }
		const_iterator end() const											{ return const_iterator(tail->next); }

	protected:
		NodePtr<T> get_headptr()											{ return head; }
		void set_headptr(NodePtr<T> ptr)									{ head = ptr; }
		NodePtr<T> get_tailptr()											{ return tail; }
		void set_tailptr(NodePtr<T> ptr)									{ tail = ptr; }
	
		NodePtr<T>	head;
		NodePtr<T>	tail;
		size_t		m_size;
	};


	/// <summary>
	/// queue based on singly linked list
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<class T >
	class queue : protected list<T>
	{
		using list<T>::head;
		using list<T>::tail;
		using list<T>::push_back;
		using list<T>::pop_front;
	public:
		using list<T>::empty;
		using list<T>::size;
		using iterator			=	SL_List_Iterator<T>;
		using const_iterator	=	const_SL_List_Iterator<T>;
		

		queue() :list<T>()													{	};
		void enqueue(T data)												{ push_back(data); }
		void dequeue()														{ pop_front();}
		T front()															{ return *head; }

		iterator begin()													{ return iterator(head); }
		iterator end()														{ return iterator(tail->next); }

		const_iterator begin() const										{ return const_iterator(head); }
		const_iterator end() const											{ return const_iterator(tail->next); }

	};

	/// <summary>
	/// stack based on singly linked list
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template<class T >
	class stack : protected list<T>
	{
		using list<T>::head;
		using list<T>::tail;
		using list<T>::push_front;
		using list<T>::pop_front;
	public:
		using list<T>::empty;
		using list<T>::size;
		using iterator = SL_List_Iterator<T>;
		using const_iterator = const_SL_List_Iterator<T>;


		stack() :list<T>() {	};
		void push(T data) { push_front(data); }
		void dequeue() { pop_front(); }
		T front() { return *head; }

		iterator begin() { return iterator(head); }
		iterator end() { return iterator(tail->next); }

		const_iterator begin() const { return const_iterator(head); }
		const_iterator end() const { return const_iterator(tail->next); }

	};


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//                                                          Methods For List Queue and Stack
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	template<class T>
	inline list<T>::list(std::initializer_list<T> list)
	{
		for (auto& i : list)
		{
			this->push_back(i);
		}
	}

	template<class T>
	inline list<T>::~list(void)
	{
		NodePtr<T> current = head;
		while (current != 0) {
			NodePtr<T> next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
	}

	template<class T>
	inline void list<T>::push_front(T data)
	{

		NodePtr<T> insert = new Node<T>;
		insert->data = data;
		insert->next = head;
		head = insert;
		if (tail == nullptr)
			tail = head;
		else if (head == tail)
			tail = head->next;
		m_size++;
	}

	template<class T>
	inline void list<T>::push_back(T data)
	{
		if (tail == NULL || head == NULL)
		{
			push_front(data);
			return;
		}
		NodePtr<T> insert = new Node<T>();
		insert->data = data;
		tail->next = insert;
		tail = tail->next;
		m_size++;
	}

	template<class T>
	inline void list<T>::pop_front()
	{
		NodePtr<T> temp = head;
		head = head->next;
		delete temp;
		m_size--;
	}

	template<class T>
	inline void list<T>::pop_back()
	{
		NodePtr<T> temp = head;
		while (temp->next != tail)
		{
			temp = temp->next;
		}
		delete tail;
		tail = temp;
		m_size--;
	}

	template<class T>
	inline int list<T>::search(T data)
	{
		int count = 0;
		NodePtr<T> checknode = new Node<T>();
		while (checknode->next != NULL)
		{
			if (checknode->data == data)
				break;
			count++;
		}
		return count;
	}

	template<class T>
	inline int list<T>::delete_node(T data)
	{
		bool found = false;
		int count = 0;
		NodePtr<T> checknode = head;
		NodePtr<T> previous = nullptr;
		while (checknode->next != nullptr)
		{
			if (checknode->data == data)
			{
				found = true;
				break;
			}
			previous = checknode;
			checknode = checknode->next;
			//checknode++;
			count++;
		}
		if (checknode == head)
		{
			head = head->next;
			checknode->next = nullptr;
			delete checknode;
		}
		else if (checknode == tail)
		{
			previous->next = nullptr;
			tail = previous;
			delete checknode;
		}
		else if (found)
		{
			previous->next = checknode->next;
			checknode->next = nullptr;
			delete checknode;
		}
		return count;
	}

	template<class T>
	template<class ...Args>
	inline void list<T>::emplace_front(Args && ...args)
	{
		push_front(T(std::forward<Args>(args)...));
	}

	template<class T>
	template<class ...Args>
	inline void list<T>::emplace_back(Args && ...args)
	{
		push_back(T(std::forward<Args>(args)...));
	}

}


