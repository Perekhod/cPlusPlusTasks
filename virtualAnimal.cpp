#include <iostream>
#include <memory>
#include <string>
#include <vector>

class AnimalActionObserver {
public:
    virtual void onAnimalAction(const std::string& action) = 0;
};

class Animal {
public:
    virtual     ~Animal () = default;
    virtual void speak  () = 0;
    void addObserver(std::shared_ptr<AnimalActionObserver> observer) {
        observers.push_back(observer);
    }
protected:
    void notifyObservers(const std::string& action) {
        for (auto& observer : observers) {
            observer->onAnimalAction(action);
        }
    }
private:
    std::vector<std::shared_ptr<AnimalActionObserver>> observers;
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Dog says: Woof!" << std::endl;
        notifyObservers("Dog barked");
    }
};

class Cat : public Animal {
public:
    void speak() override {
        std::cout << "Cat says: Meow!" << std::endl;
        notifyObservers("Cat meowed");
    }
};

class AnimalActionLogger : public AnimalActionObserver {
public:
    void onAnimalAction(const std::string& action) override {
        std::cout << "Logger: " << action << std::endl;
    }
};

int main() {
    auto dog = std::make_shared<Dog>();
    auto cat = std::make_shared<Cat>();
    auto logger = std::make_shared<AnimalActionLogger>();

    dog->addObserver(logger);
    cat->addObserver(logger);

    dog->speak();
    cat->speak();

    return 0;
}
