/*
 * LinkedList.h
 */
#include <iostream>
#include "LinkedList.h"
using std::cout;
using std::endl;
//#ifndef LINKEDLIST_H_
//#define LINKEDLIST_H_


/*
 * Create a container using a doubly linked list
 */
//class LinkedList {
//public:
//class LinkedList{}
	// Constructor, Initialize the linkedlist to empty
	LinkedList::LinkedList(){
		head_ = nullptr;
	};

	// Destructor - make sure to clean after yourself
	LinkedList::~LinkedList(){
		LNode* tmp = head_;
		while (tmp!=nullptr){
			LNode* tmpa = tmp;
			tmp = tmp->next_;
			delete tmpa;
		}
	};

	// print all integers in the list, in order
	void LinkedList::print() const{
		LNode* tmp = head_;
		while (tmp!=nullptr){
			cout << tmp->data_ << " ";
			tmp = tmp->next_;
		}
		cout << endl;
	};

	// find integer t from the list, returning a pointer to that node.
	// if not found, return nullptr
	LNode* LinkedList::find(int t) const{
		if(head_==nullptr) return nullptr;
		LNode* tmp = head_;
		while(tmp != nullptr) {
			if (tmp->data_ == t) return tmp;
			tmp = tmp->next_;
		}
		return tmp;
	};

	// insert integer t to the list as the new head
	void LinkedList::insert_head(int t){
		LNode* tmp = new LNode;
		tmp->data_ = t;
		if(head_==nullptr){
			tmp->prev_ = nullptr;
			tmp->next_ = nullptr;
		}else{
			tmp->prev_ = head_->prev_;
			tmp->next_ = head_;
			head_->prev_ = tmp;
		}
		head_ = tmp;
	};

	// insert t as a new node after "location"
	// location is assumed to point to a valid position in the list
	void LinkedList::insert_after(LNode* location, int t){
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
	void LinkedList::remove(LNode* location){
		if(location==nullptr) return;
		if(location->prev_!=nullptr){
			location->prev_->next_ = location->next_;
		}else{
			head_ = location->next_;
		}
		if(location->next_!=nullptr){
			location->next_->prev_ = location->prev_;
		}
		delete location;
	};



//#endif /* LINKEDLIST_H_ */
