#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

// Observer Design Pattern
class Observer {
public:
    virtual void update() = 0;
};

class Subject {
private:
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void notify() {
        for (auto observer : observers) {
            observer->update();
        }
    }
};

// Singleton Design Pattern
class Singleton {
private:
    static Singleton* instance;
    Singleton() {}
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void printMessage() {
        std::cout << "This is a Singleton instance" << std::endl;
    }
};
Singleton* Singleton::instance = nullptr;

// Factory Design Pattern
class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() {
        std::cout << "Circle::draw()" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        std::cout << "Square::draw()" << std::endl;
    }
};

class ShapeFactory {
public:
    static Shape* createShape(int type) {
        switch(type) {
            case 0:
                return new Circle();
            case 1:
                return new Square();
            default:
                return nullptr;
        }
    }
};

// OOP Concepts and Constructors
class Animal {
protected:
    std::string name;
public:
    Animal(std::string name) : name(name) {
        std::cout << "Animal constructor called" << std::endl;
    }
    virtual ~Animal() {
        std::cout << "Animal destructor called" << std::endl;
    }
    virtual void makeSound() = 0;
};

class Cat : public Animal {
public:
    Cat(std::string name) : Animal(name) {
        std::cout << "Cat constructor called" << std::endl;
    }
    ~Cat() {
        std::cout << "Cat destructor called" << std::endl;
    }
    void makeSound() {
        std::cout << name << " says meow" << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog(std::string name) : Animal(name) {
        std::cout << "Dog constructor called" << std::endl;
    }
    ~Dog() {
        std::cout << "Dog destructor called" << std::endl;
    }
    void makeSound() {
        std::cout << name << " says woof" << std::endl;
    }
};

// Templates
template<typename T>
class Stack {
private:
    std::vector<T> data;
public:
    void push(T element) {
        data.push_back(element);
    }
    T pop() {
        if (data.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        T element = data.back();
        data.pop_back();
        return element;
    }
};

// STL Containers and Algorithms
void stlDemo() {
    std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    std::sort(vec.begin(), vec.end());
    std::unique(vec.begin(), vec.end());

    for (auto num : vec) {
        std::cout << num << " ";
    }
    
    std::cout << std::endl;
}

// Smart Pointers
void smartPointerDemo() {
    std::shared_ptr<int> ptr1(new int(42));
    std::shared_ptr<int> ptr2 = ptr1;
    std::weak_ptr<int> weakPtr = ptr1;
    std::cout << *ptr1 << " " << *ptr2 << " " << *weakPtr.lock() << std::endl;
}

// Lambda Functions
void lambdaDemo() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int sum = 0;
    std::for_each(vec.begin(), vec.end(), [&](int num) {
        sum += num;
    });
    std::cout << "Sum of vector: " << sum << std::endl;
}

// Observer Design Pattern
class ConcreteObserver : public Observer {
public:
    void update() {
        std::cout << "Observer notified" << std::endl;
    }
};

int main() {
    Subject subject;
    ConcreteObserver observer;
    subject.addObserver(&observer);
    subject.notify();

    // Singleton Design Pattern
    Singleton* singleton1 = Singleton::getInstance();
    Singleton* singleton2 = Singleton::getInstance();
    singleton1->printMessage();
    singleton2->printMessage();

    // Factory Design Pattern
    Shape* circle = ShapeFactory::createShape(0);
    Shape* square = ShapeFactory::createShape(1);
    circle->draw();
    square->draw();

    // OOP Concepts and Constructors
    Animal* cat = new Cat("Fluffy");
    Animal* dog = new Dog("Rufus");
    cat->makeSound();
    dog->makeSound();
    delete cat;
    delete dog;

    // Templates
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;

    // STL Containers and Algorithms
    stlDemo();

    // Smart Pointers
    smartPointerDemo();

    // Lambda Functions
    lambdaDemo();

    return 0;
}
