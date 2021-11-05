/*
 * LinkedList.h
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct LNode {
	int data_;
	LNode* next_;
	LNode* prev_;
};

/*
 * Create a container using a doubly linked list
 */
class LinkedList {
public:
	// Constructor, Initialize the linkedlist to empty
	LinkedList();

	// Destructor - make sure to clean after yourself
	~LinkedList();

	// print all integers in the list, in order
	//按顺序输出列表中的所有整数
	void print() const;

	// find integer t from the list, returning a pointer to that node.
	// if not found, return nullptr
	//从列表中查找整型t，返回指向该节点的指针。  
	//如果没有找到，返回nullptr  
	LNode* find(int t) const;

	// insert integer t to the list as the new head
	//将整数t插入列表作为新的头  
	void insert_head(int t);

	// insert t as a new node after "location"
	// location is assumed to point to a valid position in the list
	//将t作为一个新节点插入到location后面  
	//假设location指向列表中的一个有效位置  
	void insert_after(LNode* location, int t);

	// remove the integer pointed to by "location"
	// location is assumed to point to a valid position in the list
	//删除由location指向的整数  
	void remove(LNode* location);

private:
	LNode* head_;
};

#endif /* LINKEDLIST_H_ */