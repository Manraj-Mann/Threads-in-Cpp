// DESCRIPTION :

// Here we will learn std::async and its usage like how to create task. There are three different launch policy for creating task using std::async are as follows:
// 1. std::launch::async
// 2. std::launch::deffered
// 3. std::launch::async | std::launch::deffered

// With the help of above policies std::async decides to create task as asynchronous or synchronous. Please go through video for more details.

#include <iostream>
#include <mutex>
#include <chrono>
#include <algorithm>
#include <future>
using namespace std;

typedef long int ull;
ull findodd( ull start , ull end){

    ull oddsum = 0;
    for (int  i = 0; i <= end; ++i)
    {
        if (i&1)
        {
            oddsum += i;
        }
        
    }
    return oddsum;
}
int main(){
    ull start = 0 , end = 190000000;

    cout<<"Thread called\n";
   
    std::future<ull> oddfuture = std::async(std::launch::async , findodd , start , end);
    cout<<"Waiting ..........\n";
    cout<<"odd sum : "<<oddfuture.get()<<endl;
    cout<<"Completed\n";
   

return 0;
}