#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"

class Test
{
private:
    int data;

public:
    Test() : data{0} { std::cout << "Test Constructor (" << data << ")" << std::endl; }
    Test(int _data) : data{_data} { std::cout << "Test Constructor (" << data << ")" << std::endl; }
    int getData() const { return data; }
    ~Test() { std::cout << "Test Destructor (" << data << ")" << std::endl; }
};

int main()
{
   
}