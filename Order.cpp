#include "Order.h"

Order::Order() {
    // IMPLEMENT ME
    marketPrice_ = 0.0;
    buyONum = 0;
    sellONum = 0;
}

Order::~Order() {
    // IMPLEMENT ME

}

// Read the .txt file
void Order::read_txt(vector<string>& info, string in_file)
{
    char buf[1024];
    ifstream file(in_file.c_str());
    //ifstream infile;
    //infile.open(in_file.c_str());
    if (!file.is_open()) {
        cout << "open file :" << in_file << "has failed!!" << endl;
        return;
    }

    // Read the file and split the order
    string resl;
    int resnum = 0;
    for (int i = 0; file.good() && !file.eof(); i++) {
        memset(buf, 0, 1024);
        file.getline(buf, 1024);
        string message(buf);
        if (i == 0) {
            marketPrice_ = atof(message.c_str());
        }
        else { // Get the contents of a single order
           //cout << message;
            allorders.push_back(message);
            string str[6];
            istringstream is(message);
            is >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5];
            if (strcmp(str[1].c_str(), "B") == 0) {
                buyONum++;
                buyorders.push_back(message);
                leftbuyorders.push_back(message);
                sellorders.push_back("empty");
            }
            else {
                sellONum++;
                buyorders.push_back("empty");
                sellorders.push_back(message);
                leftsellorders.push_back(message);
            }
        }
        info.push_back(message);
    }
    file.close();
    return;
}



// Output the .txt file
void Order::write_txt(vector<string> info, string out_file, int Mode)
{
    /*int num = info.size();
    if (num <= 0) {
        cout << "write information is empty!!!please check input " << endl;
        return;
    }*/
    ofstream outfile;
    switch (Mode)
    {
    case 1:outfile.open(out_file.c_str());
        break;
    case 2:outfile.open(out_file.c_str(), ios::app);
        break;
    default:outfile.open(out_file.c_str());
        break;
    }

    if (!outfile.is_open()) {
        cout << "open file :" << out_file << "has failed!!!!" << endl;
        return;
    }

    info.push_back(output);
    for (auto i : info)
        outfile << i << "\r";
    outfile.close();
    return;
}


string Order::getWay() const {
    // IMPLEMENT ME
    return way;
}

string Order::getType() const {
    // IMPLEMENT ME
    return type;
}

string Order::getDivide() const {
    // IMPLEMENT ME
    return divide;
}

void Order::printOrder() {
    string resr = "";
    cout << "Last trading price: " << marketPrice_ << endl;
    cout << "Buy" << "                   \t" << "Sell" << endl;
    cout << "--------------------------------------------" << endl;
    int m = 0;
    int n = 0;
    int totalnum = 0;
    totalnum = buyONum >= sellONum ? buyONum * 2 : sellONum * 2;
    for (int i = 0; i < totalnum; i++) {
        if (i % 2 == 0) {
            //cout << i << buyorders[i] << endl;
            for (int y = m; y < buyorders.size(); y++) {
                if (m == buyorders.size() - 1) {
                    resr = "                \t";
                    cout << resr;
                    break;
                }
                if (strcmp(buyorders[m].c_str(), "empty") != 0 && m < buyorders.size()) {
                    string str[6];
                    istringstream is(buyorders[m]);
                    is >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5];
                    resr = str[0] + " " + str[4] + " " + str[5] + "      \t";
                    cout << resr;
                    m++;
                    break;
                }
                else if (strcmp(buyorders[m].c_str(), "empty") == 0 && (m == buyorders.size() - 1)) {
                    resr = "                \t";
                    cout << resr;
                    m++;
                    break;
                }
                else {
                    m++;
                }
            }
        }
        else {
            //cout << i << sellorders[i] << endl;
            for (int y = n; y < sellorders.size(); y++) {
                if (n == sellorders.size()) {
                    resr = "\n";
                    cout << resr;
                    break;
                }
                if (strcmp(sellorders[n].c_str(), "empty") != 0 && n < sellorders.size()) {
                    string str[6];
                    istringstream is(sellorders[n]);
                    is >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5];
                    resr = str[0] + " " + str[4] + " " + str[5] + "\n";
                    cout << resr;
                    n++;
                    break;
                }
                else if (strcmp(sellorders[n].c_str(), "empty") == 0 && (n == sellorders.size() - 1)) {
                    resr = "\n";
                    cout << resr;
                    n++;
                    break;
                }
                else {
                    n++;
                }
            }
        }


    }

    //for (auto i : buyorders)
    //    cout << i << endl;
    //for (auto i : sellorders)
    //    cout << i << endl;
}

void Order::matchOrder() {
    output = "";
    double price = 0.00;
    string lastprice;
    int buynum = 0;
    int sellnum = 0;
    string buyname;
    string sellname;
    for (int i = 0; i < allorders.size(); i++) {
        //cout << i << allorders[i] << endl;
        string str[6];
        istringstream is(allorders[i]);
        is >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5];
        if (strcmp(str[1].c_str(), "B") == 0) {
            buyname = str[0];
            buynum = atoi(str[5].c_str());
            price = atof(str[4].c_str());
            lastprice = str[4];
            if (leftsellorders.size() == 0) { // No sale order, no execution 
                output = output + "order " + str[0] + " shares unexecuted";
            }
            else {
                for (int y = 0; y < leftsellorders.size(); y++) { // If the order quantity and bill are not correct, it will not be executed     
                    string str[6];
                    istringstream is(leftsellorders[y]);
                    is >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5];
                    if (atoi(str[5].c_str()) != buynum) {
                        output = output + "order " + buyname + " shares unexecuted";
                        break;
                    }
                    else {
                        output = output + "order " + buyname + " " + str[5] + " shares purchased at price " + lastprice + "\n";
                        leftsellorders.erase(leftsellorders.begin() + y);
                        break;
                    }
                }
            }
        }
        else {
            //if (stod(str[4]) > price) { // update the highest price
                //price = stod(str[4]);
            //}
            sellname = str[0];
            sellnum = atoi(str[5].c_str());
            lastprice = str[4];
            if (leftbuyorders.size() == 0) { // No payment, no execution
                output = output + "order " + str[0] + " shares unexecuted";
            }
            else {
                for (int y = 0; y < leftbuyorders.size(); y++) { // If the order quantity and bill are not correct, it will not be executed
                    string str[6];
                    istringstream is(leftbuyorders[y]);
                    is >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5];
                    if (atoi(str[5].c_str()) != sellnum) {
                        output = output + "order " + sellname + " shares unexecuted";
                        break;
                    }
                    else {
                        output = output + "order " + sellname + " " + str[5] + " shares sold at price " + lastprice + "\n";
                        leftbuyorders.erase(leftbuyorders.begin() + y);
                        break;
                    }
                }
            }
        }
    }
    cout << output << endl;
    return;
}
