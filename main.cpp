#include "Order.h"
#include <iostream>
#include<string>
#include<vector>

using namespace std;

int main(int def, char **arg){

    cout << std::fixed << std::setprecision(2);
    Order a;
	
    // Read/write file storage location
    string fileName;
    fileName = arg[1];
    vector<string> reread;
    a.read_txt(reread, fileName);

    a.printOrder(); // Screen print all orders
    a.matchOrder(); // Screen prints all order matching information,assume that all orders are indivisible

    vector<string> information;
    string exefileName = "executions.txt";
    a.write_txt(information, exefileName);
    return 0;
}
