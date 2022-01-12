
// In this video we will learn about how std::promise and std::future and how they work together to synchronize threads.
// Basically std::promise is sent to the called thread and once the value is ready we set that value in promise object, now at calling thread side we get that value using 
//std::future object which was created using std::promise object before sending it to the called thread. And this is how we receive value from one thread to another in synchronization.

#include <iostream>
#include <mutex>
#include <chrono>
#include <algorithm>
#include <future>
using namespace std;

typedef long int ull;
void findodd(std::promise<ull> && Oddsumpromise , ull start , ull end){

    ull oddsum = 0;
    for (int  i = 0; i <= end; ++i)
    {
        if (i&1)
        {
            oddsum += i;
        }
        
    }
    Oddsumpromise.set_value(oddsum);
    
}
int main(){
    ull start = 0 , end = 190000000;

    std::promise<ull> oddsum;
    std::future<ull> oddfuture = oddsum.get_future();
    cout<<"Thread called\n";

    std::thread t1(findodd , std::move(oddsum) , start , end);

    cout<<"Waiting ..........\n";
    cout<<"odd sum : "<<oddfuture.get()<<endl;
    cout<<"Completed\n";
    t1.join();

return 0;
}