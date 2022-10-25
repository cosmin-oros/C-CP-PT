#include <iostream>
#include <mutex>
#include <thread>

class Singleton{
    // the constructor and destructor should always be private
private:
    static Singleton* pinstance_;
    static std::mutex mutex_;

protected:
    Singleton(const std::string value): value_(value){
    }
    ~Singleton(){
    }
    std::string value_;

public:
    Singleton(Singleton &other) = delete;
    void operator = (const Singleton&) = delete;
    static Singleton* getInstance(const std::string &value);
    void someOperation(){
        //
    }
    std::string value() const{
        return value_;
    }
};

Singleton *Singleton::getInstance(const std::string& value)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Singleton(value);
    }
    return pinstance_;
}

void ThreadBar(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getInstance("BAR");
    std::cout << singleton->value() << "\n";
}

void ThreadFoo(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getInstance("FOO");
    std::cout << singleton->value() << "\n";
}



Singleton* Singleton::pinstance_{nullptr};
std::mutex Singleton::mutex_;

int main(){
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}