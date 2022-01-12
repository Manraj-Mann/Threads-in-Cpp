// TOPIC: unique_lock In C++

// NOTES:
// 1. The class unique_lock is a mutex ownership wrapper.
// 2. It Allows:
//     a. Can Have Different Locking Strategies
//     b. time-constrained attempts at locking (try_lock_for, try_lock_until)
//     c. recursive locking
//     d. transfer of lock ownership (move not copy)
//     e. condition variables. (See this in coming videos)

// Locking Strategies
//    TYPE           EFFECTS(S)
// 1. defer_lock  do not acquire ownership of the mutex.
// 2. try_to_lock  try to acquire ownership of the mutex without blocking.
// 3. adopt_lock  assume the calling thread already has ownership of the mutex.

// Example 1

// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <chrono>
// using namespace std;
// int buffer = 0;
// std:: mutex m1;

// void task( const char * threadnumber , int loopfor){

//     std::unique_lock<mutex> lock(m1);
//     for (int i = 0; i < loopfor; ++i)
//     {
//         buffer++;
//         cout<<threadnumber<<" "<<buffer<<endl;
//     }
    
// }
// int main()
// {
//     std::thread t1(task , 'T0' , 10);
//     std::thread t2(task , 'T1' , 10);

//     t1.join();
//     t2.join();
  

//     return 0;
// }

// Example 2


#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;
int buffer = 0;
std:: mutex m1;

void task( const char * threadnumber , int loopfor){

    std::unique_lock<mutex> lock(m1 , std::defer_lock);// doesnot call lock on mutex m1 bcz used deferlock 
    lock.lock();// But then will have to explicittely tell to lock when eve we want to lock mutex m1
    for (int i = 0; i < loopfor; ++i)
    {
        buffer++;
        cout<<threadnumber<<" "<<buffer<<endl;
    }

    // no unlock needed 
    
}
int main()
{
    std::thread t1(task , 'T0' , 10);
    std::thread t2(task , 'T1' , 10);

    t1.join();
    t2.join();
  

    return 0;
}