// TOPIC: Thread OR Process Synchronization

// NOTE: we will use only thread examples to explain this topic.

// POINTS:
// 1.0 Thread Or Process synchronize to access critical section.
// 2.0 Critical section is one or collection of program statements which should be executed by only one thread or process at a time.

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

long long  bankbal = 0;
std:: mutex m;
void addmoney(long long val ){


    m.lock();
    bankbal += val;
    m.unlock();
    
}
int main(){

    std::thread t1(addmoney , 100);
    std::thread t2(addmoney , 200);
    t1.join();
    t2.join();
    
    cout<<"Final balance = "<<bankbal<<endl;
return 0;
}