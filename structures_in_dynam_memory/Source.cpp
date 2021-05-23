#include <string>
#include <memory>
#include <iostream>

using namespace std;

class Essence
{
private:
    string name;

public:
    const string& getName() const { return name; }
    string& getName() { return name; }

    Essence(const string& name) : name(name)
    {
        cout << "Essence " << name << " created!" << endl;
    };

    Essence() : name("Unknown")
    {
        cout << "Essence " << name << " created!" << endl;
    };

    ~Essence()
    {
        cout << "Essence " << name << " deleted!" << endl;
    };
};

int main(int argc, char* argv[])
{
    void* p1 = nullptr;

    cout << "Null pointer = " << p1 << endl;

    int a = 234;
    int* a_ptr = &a;
    cout << "a = " << a << endl;

    cout << "Pointer a_ptr (" << a_ptr << ") with value " << *a_ptr << endl;

    int* b = new int[8];
    for (int i = 0; i < 8; i++)
        b[i] = i;
    cout << "Pointer to array (" << b << ") with value " << *b << endl;

    int* b_init = b;
    cout << "Incremented pointer to array (" << ++b << ") with value " << *b << endl;
    cout << "Difference = " << (b - b_init) * sizeof(int) << "bytes" << endl;

    b = b_init;
    cout << "Proof that a[i] = i[a] = *(a+i)" << endl;
    cout << "b[2] = " << b[2] << endl;
    cout << "2[b] = " << 2[b] << endl;

    delete[] b;

    cout << "Raw pointer" << endl;
    Essence* e0 = new Essence("E0");
    delete e0;

    cout << "Raw pointer to object in stack in scoupe" << endl;
    Essence* e1;

    cout << "Raw pointer in scoupe" << endl;
    {
        Essence* e3 = new Essence("E3");
    }

    {
        Essence e2 = Essence("E2");
        e1 = &e2;
        cout << e1->getName() << endl;
    }
    cout << e1->getName() << endl;

    cout << "E3 still isn't deleted" << endl;

    cout << "Smart unique_ptr" << endl;
    {
        unique_ptr<Essence> e4 = make_unique<Essence>("E4");
    }

    cout << "Smart shared_ptr, E6 refrences E5" << endl;
    shared_ptr<Essence> e6;
    {
        auto e5 = make_shared<Essence>("E5");
        e6 = e5;
    }
    cout << "E5 still exists at e6 variable" << endl;
    e6.reset();

    cout << "Smart weak_ptr" << endl;
    weak_ptr<Essence> e7;
    {
        auto e8 = make_shared<Essence>("E8");
        e7 = e8;
    }
    cout << (e7.expired() ? "e7 expired" : "e7 still exists") << endl;
}