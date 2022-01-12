// TOPIC: Mutex In C++ Threading | Why Use Mutex | What Is Race Condition And How To Solve It? | What Is Critical Section

// Mutex: Mutual Exclusion

/*
when we cange a variable 3 actions are performed-

-> Load = Load in accumulator register 
-> Increment = increment variable changes value
-> store = store varible

*/

// RACE CONDITION:
// 0. Race condition is a situation where two or more threads/process happens to change a common data at the same time.
// 1. If there is a race condition then we have to protect it and the protected section is  called critical section/region.

// MUTEX:
// 0. Mutex is used to avoid race condition.
// 1. We use lock() , unlock() on mutex to avoid race condition.

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int amt = 0;
std::mutex m;
void addm()
{
    m.lock();
    ++amt;
    m.unlock();
}
int main()
{
    std:: thread t1(addm);
    std:: thread t2(addm);

    t1.join();
    t2.join();

    cout<<amt<<endl;


    return 0;
}
