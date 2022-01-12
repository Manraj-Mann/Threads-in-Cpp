#include <iostream>
#include <mutex>
#include <chrono>
#include <time.h>
#include <thread>
using namespace std;
using namespace std::chrono;
int main(){
    auto stime = high_resolution_clock::now();
    for (long long i = 0; i < 100000000; i++)
    {
      //  cout<<i<<endl;
    }
    

    auto sttime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(sttime - stime);
    std::cout<<" time = "<<duration.count()<<endl;
return 0;
}