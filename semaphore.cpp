#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class Semaphore{
    int count;
    mutex m;
    condition_variable cv;

public:
   Semaphore(int n){
    count = n;
   }

   void wait(){
    unique_lock<mutex> lock(m);

    while(count <= 0){
        cv.wait(lock);
    }
    count--;
   }

   void signal(){
    unique_lock<mutex> lock(m);

    count++;
    cv.notify_one();
   }
};

Semaphore sem(1);

void fun(int id){
    sem.wait();

    cout<<"Thread number entered in critical section: "<<id<<"\n";
    cout<<"Thread number leaving critical section: "<<id<<"\n";

    sem.signal();
}

int main(){
    thread t1(fun, 1);
    thread t2(fun, 2);

    t1.join();
    t2.join();

    return 0;
}