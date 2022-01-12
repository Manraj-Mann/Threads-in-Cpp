// TOPIC: Condition Variable In C++ Threading

// IMP : CV used 
// A. Notify other threads
// B.Waiting for some condition

// NOTES:
// 1. Condition variables allow us to synchronize threads via notifications.
//    a. notify_one();
//    b. notify_all();
// 2. You need mutex to use condition variable
// 3. Condition variable is used to synchronize two or more threads.
// 4. Best use case of condition variable is Producer/Consumer problem.
// 5. Condition variables can be used for two purposes:
//     a. Notify other threads
//     b. Wait for some condition


// Notify one thread and synchronize two or more threads.
// best use of confition variable is profucer / consumer problem

#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <condition_variable>
using namespace std;

std::condition_variable cv;
std::mutex m;
long balance = 0;

void add(int money){

    std::lock_guard<mutex> lock(m);
    balance = balance + money;
    cout<<"Amount added to current balance : "<<balance<<endl;
    cv.notify_one();

}

void withd(int money){

    std:: unique_lock<mutex> ul(m);
    cv.wait(ul , [] { return (balance != 0) ? true : false;});
    if (balance >= money)
    {
        balance -= money;
        cout<<"Amount deducted : "<<money<<endl;
    }
    else{

        cout<<"Amount can't be deducted "<<endl;
    }
    cout<<"Current Amount : "<<balance<<endl;
    
}
int main(){

    std::thread t1(withd , 500);
    std::thread t2(add , 1000);
    t1.join();
    t2.join();
    

return 0;
}

