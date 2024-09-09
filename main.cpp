#include <iostream>
#include <memory>
#include <vector>

using namespace std;
class Test
{
private:
    int data;

public:
    Test() : data{0} { std::cout << "Test Constructor(" << data << ")" << std::endl; }
    Test(int _data) : data{_data} { std::cout << "Test Constructor (" << data << ")" << std::endl; }
    int getData() const { return data; }
    ~Test() { std::cout << "Test Destructor(" << data << ")" << std::endl; }
};

auto make();
void fill(vector<shared_ptr<Test>> &vec, int num);
void display(const vector<shared_ptr<Test>> &vec);

int main()
{
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();

    cout << "How many data points do you want to enter: ";
    int num;
    cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}

// unique_ptr<vector<shared_ptr<Test>>> make()
// {
//     return make_unique<vector<shared_ptr<Test>>>();
// }
// OR
auto make()
{
    return make_unique<vector<shared_ptr<Test>>>();
}

void fill(vector<shared_ptr<Test>> &vec, int num)
{
    int data;
    for (size_t i = 0; i < num; i++)
    {
        cout << "\nEnter data for the object: ";
        cin >> data;
        // shared_ptr<Test> ptr = make_shared<Test>(data);
        // vec.push_back(ptr);
        // OR
        vec.push_back(make_shared<Test>(data));
    }
    cout << "Exiting fill" << endl;
    cout << "=====================" << endl;
}

void display(const vector<shared_ptr<Test>> &vec)
{
    for (auto const &v : vec)
    {
        cout << v->getData() << endl;
    }
    cout << "=====================" << endl;
}