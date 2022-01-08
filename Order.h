#ifndef ORDER_H_
#define ORDER_H_

#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;


struct Node {
	string data;
	Node* next;
};

class Order {
	public:
		// Default constructor
		Order();

		// Destructor
		~Order();
	
		// Read the .txt file
		void read_txt(vector<string>& info, string in_file);

		//Output the .txt file
		void write_txt(vector<string> info, string out_file, int Mode = 1);

		string getWay() const;
		string getType() const;
		string getDivide() const;

		void printOrder(); // Print all orders according to buy and sell
		void matchOrder(); // Match all orders

		float marketPrice_; // market price
		float limitPrice_; // limit price
		string orderNum;
		string way; // buy or sell
		string type; // limit or market price
		string divide; // separable or indivisible
		double price; // final price
		int num; // number of shares
		int buyONum;
		int sellONum;

		vector<string> buyorders; // all purchase orders
		vector<string> sellorders; // all orders to sell
		vector<string> leftbuyorders; // all purchase orders left after matching
		vector<string> leftsellorders; // all remaining sales orders after matching
		vector<string> allorders; // all orders
		string output; // the final order matches the output information

	protected:

	private:

};

#endif /* ORDER_H_ */