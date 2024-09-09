#include <iostream>
#include <memory>
#include <vector>

#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"

// So I don't have to write std:: everywhere
using namespace std;

class B; // Forward declaration

class A
{
    shared_ptr<B> b_ptr; // Shared Pointer to B class
public:
    void setB(shared_ptr<B> &b)
    {
        b_ptr = b;
    }
    A() { cout << "A Constructor" << endl; }
    ~A() { cout << "A Destructor" << endl; }
};

class B
{
    // shared_ptr<A> a_ptr; // Shared Pointer to A class - Should be weak_ptr
    weak_ptr<A> a_ptr; // Weak Pointer to A class
public:
    void setA(shared_ptr<A> &a)
    {
        a_ptr = a;
    }
    B() { cout << "B Constructor" << endl; }
    ~B() { cout << "B Destructor" << endl; }
};

int main()
{
    // If kept the same as before, neither A nor B will be destructed since they are pointing to each other
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->setB(b);
    b->setA(a);
}