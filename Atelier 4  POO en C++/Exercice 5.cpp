#include <iostream>

class Test {
public:
    void call() {
        ++call_count;
    }

    static int getCallCount() {
        return call_count;
    }

private:
    static int call_count;
};

int Test::call_count = 0;

int main() {
    Test t1, t2;

    t1.call();
    t1.call();
    t2.call();

    std::cout << "La fonction a ete appelle " << Test::getCallCount() << " fois." << std::endl;

    return 0;
}
