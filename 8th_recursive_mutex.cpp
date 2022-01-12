// Topic Recursuve mutex in c++ ( std:: recursive_mutex )

/*

Notes:

0. It is same as mutex but , Same thread can lock one mutex mutiple times using recursive_mutex.
1. If thread T1 is running first calll lock/try lock on recursive_mutex m1 then m1 is locked by T1 , now as T1 is running in recursuion T1 can call lock/try_lock on any number of times there is no issue.
2. But id T1 have acquired 10 times lock/try_lock on mutex m1 then thread T1 will have to unlock
it 1- times otherwise no other thread will be able to lock mutex m1.
3.How many time we can lock recursive_mutex is not defined but when that number reaches and if we were calling lock() it will return std::system_error OR if we were calling try_lock() then it will return false.

Bottom line : 

0. It is similar to mutex but have extra facility that it can be locked mutiple times by same threa.
1. If we can avoid recursive_mutex then we should because it brings overhead to the system .
2. It can be used in loops also.

*/

// 1.With recursion

// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <chrono>
// using namespace std;
// int buffer = 0;
// std::recursive_mutex m1;

// void recur(char c , int forlop)
// {
//     if (forlop < 0) 
//     {
//         return;
//     }
//     m1.lock();

//     cout<<c<<" "<<buffer++<<endl;
//     recur( c , --forlop);
//     m1.unlock();
  
// }
// int main()
// {
//     std::thread t1(recur , '0' , 2);
//     std::thread t2(recur , '1' , 2);

//     t1.join();
//     t2.join();
  

//     return 0;
// }

// 2. With loops 

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;
int buffer = 0;
std::recursive_mutex m1;

int main()
{
   for (int i = 0; i < 5; i++)
   {
     m1.lock();
     std::cout<<" Locked "<<i<<endl;
   }
   for (int i = 0; i < 5; i++)
   {
     m1.unlock();
     std::cout<<" Unlocked "<<i<<endl;
   }
   

    return 0;
}

