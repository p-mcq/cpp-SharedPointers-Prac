#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"

template <typename T>
void printUseCount(const std::shared_ptr<T> &p)
{
    std::cout << "Use Count: " << p.use_count() << std::endl;
}

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
#pragma region Introduction to Shared Pointers
    // std::shared_ptr<int> p1{new int{100}};
    // std::shared_ptr<Test> p3{new Test{1000}};
    // printUseCount(p1);
    // printUseCount(p3);

    // // Initalise another shared pointer using the existing shared pointer
    // std::shared_ptr<int> p2{p1};
    // printUseCount(p1);

    // p1.reset();
    // printUseCount(p1);
    // printUseCount(p2);
#pragma endregion

#pragma region Scope affects
    // // Create a shared pointer on the heap to a Test object
    // std::shared_ptr<Test> ptr = std::make_shared<Test>(100);
    // // Print the use count of the shared pointer
    // printUseCount(ptr); // 1
    // {
    //     // Create a new shared pointer to the same object
    //     std::shared_ptr<Test> ptr1 = ptr;
    //     // Print the use count of the shared pointer
    //     printUseCount(ptr); // 2
    //     {
    //         // Create a new shared pointer to the same object
    //         std::shared_ptr<Test> ptr2 = ptr;
    //         // Print the use count of the shared pointer
    //         printUseCount(ptr); // 3
    //         // Reset the shared pointer
    //         ptr.reset();
    //     }
    //     // Print the use count of the shared pointer. It will now be less since ptr has been reset and ptr2 is no longer in scope
    //     printUseCount(ptr); // 1
    // }
    // printUseCount(ptr); // 0
#pragma endregion

#pragma region Vectors and Shared Pointers
    std::shared_ptr<Account> checkingAccount = std::make_shared<Checking_Account>("Moe", 5000);
    std::shared_ptr<Account> savingsAccount = std::make_shared<Savings_Account>("Larry", 6000, 0.03);
    std::shared_ptr<Account> trustAccount = std::make_shared<Trust_Account>("Curly", 7000, 0.04);

    printUseCount(checkingAccount);
    printUseCount(savingsAccount);
    printUseCount(trustAccount);

    std::vector<std::shared_ptr<Account>> accounts;
    accounts.push_back(checkingAccount);
    accounts.push_back(savingsAccount);
    accounts.push_back(trustAccount);

    for (const auto &account : accounts)
    {
        std::cout << *account << std::endl;
        printUseCount(account);
    }

#pragma endregion
}