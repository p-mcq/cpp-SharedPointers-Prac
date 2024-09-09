#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"

using namespace std;
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

void myDeleter(Test *ptr)
{
    std::cout << "Using my custom function deleter" << std::endl;
    delete ptr;
}

int main()
{
    {
        // Declaring a shared pointer with a customer deleter
        std::shared_ptr<Test> ptr1{new Test{100}, myDeleter};
    } // Once the scope ends, the shared pointer will be destroyed and the custom deleter will be called

    {
        // Declaring a shared pointer with a lambda function as a deleter
        shared_ptr<Test> ptr2(new Test{100},
                              [](Test *p)
                              {
                                  cout << "Using my custom lambda deleter" << endl;
                                  delete p;
                              });
    }
}