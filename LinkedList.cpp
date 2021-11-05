/*
 * LinkedList.h
 */
#include <iostream>
// #include "LinkedList.h";
using std::cout;
using std::endl;
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
	LinkedList(){
		head_ = nullptr;
	};

	// Destructor - make sure to clean after yourself
	~LinkedList(){
		LNode* tmp = head_;
		while (tmp!=nullptr){
			LNode* tmpa = tmp;
			tmp = tmp->next_;
			delete tmp;
		}
	};

	// print all integers in the list, in order
	void print() const{
		LNode* tmp = head_;
		while (tmp!=nullptr){
			cout << tmp->data_ << " ";
			tmp = tmp->next_;
		}
		cout << endl;
	};

	// find integer t from the list, returning a pointer to that node.
	// if not found, return nullptr
	LNode* find(int t) const{
		if(head_==nullptr) return nullptr;
		LNode* tmp = head_;
		while(tmp != nullptr) {
			if (tmp->data_ == t) return tmp;
			tmp = tmp->next_;
		}
		return tmp;
	};

	// insert integer t to the list as the new head
	void insert_head(int t){
		LNode* tmp = new LNode;
		tmp->data_ = t;
		if(head_==nullptr){
			tmp->prev_ = nullptr;
			tmp->next_ = nullptr;
		}else{
			tmp->prev_ = head_->prev_;
			tmp->next_ = head_;
			head_->next_ = tmp;
		}
		head_ = tmp;
	};

	// insert t as a new node after "location"
	// location is assumed to point to a valid position in the list
	void insert_after(LNode* location, int t){
		LNode* tmp = new LNode;
		tmp->data_ = t;
		tmp->prev_ = location;
		tmp->next_ = location->next_;
		if(location->next_!=nullptr){
			location->next_->prev_ = tmp;
		}
		location->next_ = tmp;
	};

	// remove the integer pointed to by "location"
	// location is assumed to point to a valid position in the list
	void remove(LNode* location){
		if(location==nullptr) return;
		if(location->prev_!=nullptr){
			location->prev_ = location->next_;
		}else{
			head_ = location->next_;
		}
		if(location->next_!=nullptr){
			location->prev_ = location->prev_;
		}
		delete location;
	};

private:
	LNode* head_;
};


#endif /* LINKEDLIST_H_ */