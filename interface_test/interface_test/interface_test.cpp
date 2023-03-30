#include <iostream>
#include <memory>
#include <vector>
//сделал чат гпт
class AbstractBase {
public:
    virtual void foo() = 0;
    virtual ~AbstractBase() {}
};

class Derived1 : public AbstractBase {
public:
    void foo() { std::cout << "Derived1\n"; }
};

class Derived2 : public AbstractBase {
public:
    void foo() { std::cout << "Derived2\n"; }
};

template<typename T>
void registerDerived(std::vector<std::shared_ptr<AbstractBase>>& vec) {
    vec.emplace_back(std::make_shared<T>());
}

int main() {
    std::vector<std::shared_ptr<AbstractBase>> vec;
    registerDerived<Derived1>(vec);
    registerDerived<Derived2>(vec);
    for (const auto& ptr : vec) {
        ptr->foo();
    }
    return 0;
}