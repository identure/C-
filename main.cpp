#include "Order.h"
#include <iostream>
#include<string>
#include<vector>

using namespace std;

int main(){

    cout << std::fixed << std::setprecision(2);
    Order a;

    // Read/write file storage location
    string fileName = "C:\\a2b\\orders.txt";
    string exefileName = "C:\\a2b\\executions.txt";

    vector<string> reread;
    a.read_txt(reread, fileName);

    a.printOrder(); // Screen print all orders
    a.matchOrder(); // Screen prints all order matching information,assume that all orders are indivisible

    vector<string> information;
    a.write_txt(information, exefileName);
    return 0;
}
