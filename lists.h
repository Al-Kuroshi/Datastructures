#pragma once
#include <iostream>
#define and &&
#define or ||
#define equalto ==
#define not !=
#define greaterthan >
#define lessthan <





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                          NODES
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
template <typename T>
class Node {
public:
	Node() {
		//data = 0;
		next = NULL;
	}
	Node(T d, Node<T>* n) {
		data = d;
		next = n;
	}
	Node(T d) {
		data = d;
		next = NULL;
	}
	void setData(T d) {
		data = d;
	}
	void setNext(Node<T>* n) {
		next = n;
	}
	T getData() {
		return data;
	}
	Node<T>* getNext() {
		return next;
	}
	T data; // data
	Node<T>* next; // pointer to next
};

template<typename T>
class lrNode
{
public:
	T data;
	lrNode<T>* left;
	lrNode<T>* right;
	lrNode()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	lrNode(T data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
};


template <typename T>
class SLinkedList {
public:
	SLinkedList(void) { head = NULL; tail = NULL; }          // constructor
	~SLinkedList(void);                         // destructor
	bool IsEmpty() { return head == NULL; }     // check if list is empty
	Node<T>* InsertatHead(T x);                 // insert x at head
	Node<T>* InsertatTail(T x);                 // insert x at tail
	int search(T x);                            // return index to a node with value x
	int DeleteNode(T x);                        //  delete node with value x
	void print(void);                           //  display list values 
	Node<T>* getHead() { return head; }
	void setHead(Node<T>* ptr) { head = ptr; }
	Node<T>* getTail() { return tail; }
	void setTail(Node<T>* ptr) { tail = ptr; }
private:
	Node<T>* head;
	Node<T>* tail;
};



template <typename T>
class Queue {
public:
	Queue(void) { head = NULL; tail = NULL; }          // constructor
	Queue(Queue<T>& copy);
	~Queue(void);                         // destructor
	bool IsEmpty() { return head equalto NULL; }     // check if list is empty
	Node<T>* InsertatHead(T x);                 // insert x at head
	Node<T>* enqueue(T x);
	Node<T>* dequeue();
	T& front() { if (head != NULL)return head->data;}
	int search(T x);                            // return index to a node with value x
	int DeleteNode(T x);                        //  delete node with value x
	void print(void);                           //  display list values 
	Node<T>* getHead() { return head; }
	void setHead(Node<T>* ptr) { head = ptr; }
	Node<T>* getTail() { return tail; }
	void setTail(Node<T>* ptr) { tail = ptr; }
	Queue<T>*& operator+ (Queue& addto);
	Node<T>* head;
	Node<T>* tail;
};

template <typename T>
class stack {
public:
	stack(void) { head = NULL; tail = NULL; size = 0; }          // constructor
	stack(stack<T>& copy);
	~stack(void);                         // destructor
	bool IsEmpty() { return head equalto NULL; }     // check if list is empty
	int sizeofstack() { return size; }
	Node<T>* InsertatTail(T x);          // insert x at tail
	Node<T>* push(T x);                 // insert x at head
	Node<T>* pop();
	T& front() { if (head != NULL)return head->val; }
	int search(T x);                            // return index to a node with value x
	int DeleteNode(T x);                        //  delete node with value x
	void print(void);//  display list values 
	Node<T>* Peek() { return head; }
	void clear();
	Node<T>* getHead() { return head; }
	void setHead(Node<T>* ptr) { head = ptr; }
	Node<T>* getTail() { return tail; }
	void setTail(Node<T>* ptr) { tail = ptr; }
	Node<T>* head;
	Node<T>* tail;
	int size;
};

template<typename T>
class BST
{
public:
	lrNode<T>* root;
	BST()
	{
		root = NULL;
	}
	BST(T data)
	{
		root = new lrNode<T>(data);
	}
	void Pre_Trav(lrNode<T>* check);
	void Pos_Trav(lrNode<T>* check);
	void In_Trav(lrNode<T>* check);
	void Lvl_Trav(lrNode<T>*& check);
	void insert(T data);
	void sert(T data, lrNode<T>*& check);
	lrNode<T>* retreve(T data, lrNode<T>* check);
	bool search(T data, lrNode<T>* check);
	lrNode<T>* getMin(lrNode<T>* root);
	lrNode<T>* getparent(lrNode<T>* key, lrNode<T>* root);
	void deleteNode(T key, lrNode<T>* root);

};


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                 Singly linked List
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<typename T>
inline SLinkedList<T>::~SLinkedList(void)
{
	Node<T>* current = head;
	Node<T>* next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	head = NULL;
}

template<typename T>
inline Node<T>* SLinkedList<T>::InsertatHead(T x)
{
	Node<T>* insert = new Node<T>();
	insert->setData(x);
	insert->setNext(head);
	head = insert;
	if (tail == NULL)
		tail = head;
	else if (head == tail)
		tail = head->next;
	return head;
}

template<typename T>
inline Node<T>* SLinkedList<T>::InsertatTail(T x)
{
	if (tail == NULL && head == NULL)
	{
		InsertatHead(x);
		return head;
	}
	Node<T>* insert = new Node<T>();
	insert->setData(x);
	tail->next = insert;
	tail = tail->next;
	return tail;
}

template<typename T>
inline int SLinkedList<T>::search(T x)
{
	int count = 0;
	Node<T>* checknode = new Node<T>();
	while (checknode->next != NULL)
	{
		if (checknode->getData() == x)
			break;
		count++;
	}
	return count;
}

template<typename T>
inline int SLinkedList<T>::DeleteNode(T x)
{
	bool found = false;
	int count = 0;
	Node<T>* checknode = head;
	Node<T>* previous = NULL;
	while (checknode->next != NULL)
	{
		if (checknode->getData() == x)
		{
			found = true;
			break;
		}
		previous = checknode;
		checknode = checknode->next;
		count++;
	}
	if (checknode == head)
	{
		head = head->next;
		checknode->next = NULL;
		delete checknode;
	}
	else if (checknode == tail)
	{
		previous->next = NULL;
		tail = previous;
		delete checknode;
	}
	else if (found)
	{
		previous->next = checknode->next;
		checknode->next = NULL;
		delete checknode;
	}
	return count;
}

template<typename T>
inline void SLinkedList<T>::print(void)
{
	cout << "\n";
	if (head == NULL)
	{
		cout << "List is empty\n"; return;
	}
	Node<T>* print = head;
	while (print != NULL)
	{
		cout << print->data << " ";
		print = print->next;
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                            Queue
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




template<typename T>
Queue<T>::Queue(Queue<T>& copy)
{
	if (!IsEmpty())
	{
		while (head != NULL)
		{
			dequeue();
		}
	}
	Node<T>* from = copy.head;
	while (from != NULL)
	{
		enqueue(from->data);
		from = from->next;
	}
}

template<typename T>
inline Queue<T>::~Queue(void)
{
	Node<T>* current = head;
	Node<T>* next;
	while (current not NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	head = NULL;
}

template<typename T>
inline Node<T>* Queue<T>::InsertatHead(T x)
{
	Node<T>* insert = new Node<T>();
	insert->setData(x);
	insert->setNext(head);
	head = insert;
	if (tail equalto NULL)
		tail = head;
	else if (head equalto tail)
		tail = head->next;
	return head;
}

template<typename T>
inline Node<T>* Queue<T>::enqueue(T x)
{
	if (tail equalto NULL and head equalto NULL)
	{
		InsertatHead(x);
		return head;
	}
	Node<T>* insert = new Node<T>();
	insert->setData(x);
	tail->next = insert;
	tail = tail->next;
	return tail;
}

template<typename T>
Node<T>* Queue<T>::dequeue()
{

	if (head equalto NULL)//is empty
		return nullptr;
	else if (head not NULL and head equalto tail)
	{
		Node<T>* DQ = head;
		Node<T>* ret = DQ;
		head = NULL;
		tail = NULL;
		delete DQ;
		return ret;
	}
	else
	{
		Node<T>* DQ = head;
		Node<T>* ret = DQ;
		head = head->next;
		delete DQ;
		return ret;
	}
}

template<typename T>
inline int Queue<T>::search(T x)
{
	int count = 0;
	Node<T>* checknode = new Node<T>();
	while (checknode->next != NULL)
	{
		if (checknode->getData() equalto x)
			break;
		count++;
	}
	return count;
}

template<typename T>
inline int Queue<T>::DeleteNode(T x)
{
	bool found = false;
	int count = 0;
	Node<T>* checknode = head;
	Node<T>* previous = NULL;
	while (checknode->next not NULL)
	{
		if (checknode->getData() equalto x)
		{
			found = true;
			break;
		}
		previous = checknode;
		checknode = checknode->next;
		count++;
	}
	if (checknode equalto head)
	{
		head = head->next;
		checknode->next = NULL;
		delete checknode;
	}
	else if (checknode equalto tail)
	{
		previous->next = NULL;
		tail = previous;
		delete checknode;
	}
	else if (found)
	{
		previous->next = checknode->next;
		checknode->next = NULL;
		delete checknode;
	}
	return count;
}

template<typename T>
inline void Queue<T>::print(void)
{
	cout << "\n";
	if (head equalto NULL)
	{
		cout << "Queue is empty\n"; return;
	}
	Node<T>* print = head;
	while (print not NULL)
	{
		cout << print->data << " ";
		print = print->next;
	}
}

template<typename T>
inline Queue<T>*& Queue<T>::operator+(Queue& addto)
{
	Queue<T>* con = new Queue(*this);
	Queue<T> con2 = addto;
	while (addto.head != NULL)
	{
		con->enqueue(addto.front());
		addto.dequeue();
	}
	return con;
}


void roundrobin(Queue<int>& q, int timequant)
{
	int counter = 0;
	while (!q.IsEmpty())
	{
		cout << "\n" << counter << ": Exceution Time: " << q.front() << " seconds\n";
		q.front() -= timequant;
		if (q.getHead() != NULL)
		{
			if (q.front() <= 0)
			{
				cout << "Remaining Time: " << q.front() << " seconds\n";
				cout << "Process Complete\n\t\t\t\tLoading next Process\n";
				q.dequeue();
			}
			if (q.front() greaterthan 0)
			{
				cout << "Remaining Time: " << q.front() << " seconds\n";
				cout << "Task Not Complete ,\n\t\t\t\t Reschedualing Task\n";
				q.enqueue(q.front());
				q.dequeue();
			}
		}
		counter++;
	}
	q.print();
	cout << "All Processes Complete";
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                        STACK
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
stack<T>::stack(stack<T>& copy)
{
	if (!IsEmpty())
	{
		while (head != NULL)
		{
			pop();
		}
	}
	Node<T>* from = copy.head;
	while (from != NULL)
	{
		InsertatTail(from->val);
		from = from->next;
	}
	this->size = copy.size;
}

template<typename T>
inline Node<T>* stack<T>::InsertatTail(T x)
{
	if (tail == NULL && head == NULL)
	{
		InsertatHead(x);
		return head;
	}
	Node<T>* insert = new Node<T>();
	insert->setData(x);
	tail->next = insert;
	tail = tail->next;
	return tail;
}

template<typename T>
inline stack<T>::~stack(void)
{
	Node<T>* current = head;
	Node<T>* next;
	while (current not NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	head = NULL;
	size = 0;
}

template<typename T>
inline Node<T>* stack<T>::push(T x)
{
	Node<T>* insert = new Node<T>();
	insert->setData(x);
	insert->setNext(head);
	head = insert;
	if (tail equalto NULL)
		tail = head;
	else if (head equalto tail)
		tail = head->next;
	size++;
	return head;
}

template<typename T>
Node<T>* stack<T>::pop()
{

	if (head equalto NULL)//is empty
		return nullptr;
	else if (head not NULL and head equalto tail)
	{
		Node<T>* DQ = head;
		head = NULL;
		tail = NULL;
		delete DQ;
		size--;
	}
	else
	{
		Node<T>* DQ = head;
		head = head->next;
		delete DQ;
		size--;
	}
}

template<typename T>
inline int stack<T>::search(T x)
{
	int count = 0;
	Node<T>* checknode = new Node<T>();
	while (checknode->next != NULL)
	{
		if (checknode->getData() equalto x)
			break;
		count++;
	}
	return count;
}

template<typename T>
inline int stack<T>::DeleteNode(T x)
{
	bool found = false;
	int count = 0;
	Node<T>* checknode = head;
	Node<T>* previous = NULL;
	while (checknode->next not NULL)
	{
		if (checknode->getData() equalto x)
		{
			found = true;
			break;
		}
		previous = checknode;
		checknode = checknode->next;
		count++;
	}
	if (checknode equalto head)
	{
		head = head->next;
		checknode->next = NULL;
		delete checknode;
		size--;
	}
	else if (checknode equalto tail)
	{
		previous->next = NULL;
		tail = previous;
		delete checknode;
		size--;
	}
	else if (found)
	{
		previous->next = checknode->next;
		checknode->next = NULL;
		delete checknode;
		size--;
	}
	return count;
}

template<typename T>
inline void stack<T>::print(void)
{
	cout << "\n";
	if (head equalto NULL)
	{
		cout << "Queue is empty\n"; return;
	}
	Node<T>* print = head;
	while (print not NULL)
	{
		cout << print->val << " ";
		print = print->next;
	}
}

template<typename T>
inline void stack<T>::clear()
{
	Node<T>* current = head;
	Node<T>* next;
	while (size != 0) {
		this->pop();
	}
	head = NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                        Binary Search Tree
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
inline void BST<T>::Pre_Trav(lrNode<T>* check)
{
	if (check == NULL)
		return;
	std::cout << check->data << " , ";
	Pre_Trav(check->left);
	Pre_Trav(check->right);
}

template<typename T>
inline void BST<T>::Pos_Trav(lrNode<T>* check)
{
	if (check == NULL)
		return;
	Pos_Trav(check->left);
	Pos_Trav(check->right);
	std::cout << check->data << " , ";
}

template<typename T>
inline void BST<T>::In_Trav(lrNode<T>* check)
{
	if (check == NULL)
		return;
	In_Trav(check->left);
	std::cout << check->data << " , ";
	In_Trav(check->right);
}

template<typename T>
inline void BST<T>::Lvl_Trav(lrNode<T>*& root)
{
	Queue<lrNode<int>*>outq;
	outq.enqueue(root);       // first enqueue the root
	while (!outq.IsEmpty())     // while queue is not empty (no more nodes left in tree)
	{
		if (outq.front()->left != NULL)          // if roots left is not null enqueue it
			outq.enqueue(outq.front()->left);    
		if (outq.front()->right != NULL)         // if roots left is not null enqueue it
			outq.enqueue(outq.front()->right);
		cout << outq.front()->data << ", ";      // output the front 
		outq.dequeue();                          // dequeue
	}
}

template<typename T>
inline void BST<T>::insert(T data)
{
	if (root == NULL)
		root = new lrNode<int>(data);
	else if (!search(data, root))
		sert(data, root);
}

template<typename T>
inline void BST<T>::sert(T data, lrNode<T>*& check)
{
	if (check == NULL)
	{
		check = new lrNode<T>(data);
	}
	else if (data < check->data)
		sert(data, check->left);
	else if (data > check->data)
		sert(data, check->right);
}

template<typename T>
inline lrNode<T>* BST<T>::retreve(T data, lrNode<T>* check)
{
	if (check == NULL)
		return NULL;
	else if (data == check->data)
		return check;
	else if (data < check->data)
		retreve(data, check->left);
	else if (data > check->data)
		retreve(data, check->right);
}

template<typename T>

inline bool BST<T>::search(T data, lrNode<T>* check)
{
	if (check == NULL)
		return false;
	else if (data == check->data)
		return true;
	else if (data < check->data)
		search(data, check->left);
	else if (data > check->data)
		search(data, check->right);
}

template<typename T>
inline lrNode<T>* BST<T>::getMin(lrNode<T>* root)
{
	if (root->left == NULL)
		return root;
	getMin(root->left);
}

template<typename T>
inline lrNode<T>* BST<T>::getparent(lrNode<T>* data, lrNode<T>* root)
{
	if (root == NULL)
		return NULL;
	if (data == root->left || data == root->right)
		return root;
	if (data->data < root->data)
		getparent(data, root->left);
	if (data->data > root->data)
		getparent(data, root->right);
}

template<typename T>
inline void BST<T>::deleteNode(T key, lrNode<T>* root)
{
	root = retreve(key, root);
	if (root != 0)
	{
		if (root->left == 0 && root->right == 0)
		{
			lrNode<T>* temp = root;
			lrNode<T>* parent = getparent(root, this->root);
			if (parent->left == temp)
				parent->left = NULL;
			if (parent->right == temp)
				parent->right = NULL;
			delete temp;
		}
		else if (root->left == 0)
		{
			lrNode<T>* temp = root;
			lrNode<T>* parent = getparent(temp, this->root);
			root = root->right;
			delete temp;
			if (parent->left == 0)
				parent->left = root;
			else
				parent->right = root;


		}
		else if (root->right == 0)
		{
			lrNode<T>* temp = root;
			lrNode<T>* parent = getparent(temp, this->root);
			root = root->left;
			delete temp;
			if (parent->left == 0)
				parent->left = root;
			else
				parent->right = root;
		}
		else
		{
			lrNode<T>* temp = root;
			lrNode<T>* parent = getparent(temp, this->root);
			lrNode<T>* left = root->left;
			lrNode<T>* right = root->right;
			if (parent != root)
			{
				delete temp;

				if (parent->left == 0)
				{
					parent->left = right;
					right->left = left;
				}
				else
				{
					parent->right = right;
					right->left = left;
				}
			}
		}

	}
}
