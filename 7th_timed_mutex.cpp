/*

TOPIC : timed mutex in c++ threading ( std:: timed_mutex)

We have learned mutex , race condiiton , critical section in previous video

Notes :
0. std::timed_mutex is blocked till timeout_time or the lock is aquired and returns true if success otherwise false.
1. Member Function :
    a. lock
    b. try_lock
    c. try_lock_for  --\ These 2 functions makes it diffrtrnt from mutex
    d. try_lock_until
    e. unlock 

// Ex - try_lock_until();

Waits until specified timeout_duration has elapsed or thr lock is acquied , whichever comes first.
On succssfull lock acquisition return true , otherwise false 

*/

// 1. try_lock_for

// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <chrono>
// using namespace std;
// int amt = 0;
// std::timed_mutex m;
// void incre(int i)
// {

//     if (m.try_lock_for(std::chrono::seconds(1)))
//     {
//         ++amt;
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         cout << "Thread " << i << " Entered " << endl;
//         m.unlock();
//     }
//     else
//     {
//         cout << "Thread " << i << " couldn't enter" << endl;
//     }
// }
// int main()
// {
//     std::thread t1(incre , 1);
//     std::thread t2(incre , 2);

//     t1.join();
//     t2.join();

//     cout<<amt<<endl;

//     return 0;
// }

// 2. try_lock_until

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;
int amt = 0;
std::timed_mutex m;
void incre(int i)
{
    auto now = std::chrono::steady_clock::now();
    if (m.try_lock_until(now + std::chrono::seconds(1)))
    {
        ++amt;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "Thread " << i << " Entered " << endl;
        m.unlock();
    }
    else
    {
        cout << "Thread " << i << " couldn't enter" << endl;
    }
}
int main()
{
    std::thread t1(incre , 1);
    std::thread t2(incre , 2);

    t1.join();
    t2.join();

    cout<<amt<<endl;

    return 0;
}
