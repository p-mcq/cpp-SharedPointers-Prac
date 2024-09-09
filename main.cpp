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
    // Test t1 = Test(1000);
    // Test *pa = new Test(100);
    // delete pa;

    // std::unique_ptr<Test> t1{new Test(100)};
    // std::unique_ptr<Test> t2 = std::make_unique<Test>(80);

    // std::unique_ptr<Test> t3;
    // t3 = std::move(t1);

    std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Moe", 5000);
    std::cout << *a1 << std::endl;
    a1->deposit(5000);
    std::cout << *a1 << std::endl;

    std::vector<std::unique_ptr<Account>> accounts;
    accounts.push_back(std::make_unique<Checking_Account>("James", 1000));
    accounts.push_back(std::make_unique<Savings_Account>("Billy", 4000, 5.2));
    accounts.push_back(std::make_unique<Trust_Account>("Bobby", 5000, 4.5));

    // for (auto i = 0; i < accounts.size(); i++)
    // {
    //     std::cout << *accounts[i] << std::endl;
    // }

    for (const auto &acc : accounts)
    {
        std::cout << *acc << std::endl;
    }

    return 0;
}