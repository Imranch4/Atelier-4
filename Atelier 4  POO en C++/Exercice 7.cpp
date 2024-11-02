#include <iostream>
#include <vector>

class Pile {
private:
    std::vector<int> elements;

public:
    Pile() {}

    void push(int element) {
        elements.push_back(element);
    }

    int pop() {
        if (elements.empty()) {
            throw std::out_of_range("La Pile et vide");
        }
        int topElement = elements.back();
        elements.pop_back();
        return topElement;
    }

    bool isEmpty() const {
        return elements.empty();
    }
};

int main() {
    Pile p1, p2;

    p1.push(0);
    p1.push(20);
    p1.push(40);

    std::cout << "Dépiler de p1: " << p1.pop() << std::endl;
    std::cout << "Dépiler de p1: " << p1.pop() << std::endl;
    std::cout << "Dépiler de p1: " << p1.pop() << std::endl;

    p2.push(100);
    p2.push(150);
    p2.push(200);

    std::cout << "Dépiler de p2: " << p2.pop() << std::endl;
    std::cout << "Dépiler de p2: " << p2.pop() << std::endl;
    std::cout << "Dépiler de p2: " << p2.pop() << std::endl;

    return 0;
}
