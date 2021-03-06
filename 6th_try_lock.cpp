// TOPIC: std::try_lock() On Mutex In C++11 Threading

// 0. std::try_lock() tries to lock all the mutexes passed in it one by one in given order.
// 1. On success this function returns -1 otherwise it will return 0-based mutex index number which it could not lock.
// 2. If it fails to lock any of the mutex then it will release all the mutex it locked before.
// 3. If a call to try_lock results in an exception, unlock is called for any locked objects before re-throwing

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

int X = 0, Y = 0;
std::mutex m1, m2;

void dowork(int seconds)
{

    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void incrementXY(int &XorY, std::mutex &m, const char *desc)
{

    for (int i = 0; i < 5; i++)
    {
        m.lock();
        ++XorY;
        cout << desc << XorY << endl;
        m.unlock();
        dowork(1);
    }
}

void consumeXY()
{

    int usecount = 5;
    int XplusY = 0;
    while (1)
    {
        int lockresult = std::try_lock(m1, m2);
        if (lockresult == -1)
        {
            if (X != 0 && Y != 0)
            {
                --usecount;
                XplusY += X+Y;
                X = 0;
                Y = 0;
                cout<<"XpluseY = "<<XplusY<<endl;
            }
            m1.unlock();
            m2.unlock();
            if (usecount == 0)
            {
                break;
            }
            
            
        }
        
    }
    
}

int main()
{

    std::thread t1(incrementXY, std::ref(X), std::ref(m1), "X ");
    std::thread t2(incrementXY, std::ref(Y), std::ref(m2), "Y ");
    std::thread t3(consumeXY);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}