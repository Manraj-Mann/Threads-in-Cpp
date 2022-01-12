#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <algorithm>
#include <future>
#include <condition_variable>
#include <queue>
using namespace std;
std::mutex mu;
deque<int> buffer;
std::condition_variable cond;
const unsigned int max_buffer = 50;

void producer(int val)
{

    while (val)
    {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, []()
                  { return buffer.size() < max_buffer; });
        buffer.push_back(val);
        cout << "Produced : " << val << endl;
        val--;
        locker.unlock();
        cond.notify_one();
    }
}

void consumer()
{

    while (true)
    {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, [](){ return buffer.size() > 0; });
        int val = buffer.back();
        buffer.pop_back();
        cout << "Counsumed : " << val << endl;
        locker.unlock();
        cond.notify_one();
    }
}

int main()
{

    std::thread t1(producer, 100);
    std::thread t2(consumer);

    t1.join();
    t2.join();


    return 0;
}