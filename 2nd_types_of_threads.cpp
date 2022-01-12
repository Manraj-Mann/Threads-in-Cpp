/* TOPIC: Different Types Of Thread Creation And Calling.
There are 5 different types of creating threads and calling callable in threads.

NOTES : Different types for creating threads.

1. Function Pointer-- this is the very basic form of creating threads.
2. Lambda Function
3. Functor(Function Object)
4. Non - static member function
5. Static member function

Note: if we create multiple threads at same times its not gurantee that which will start fisrt 
*/

#include <iostream>
#include <thread>
#include <pthread.h>

using namespace std;

// 1. Function Pointers
//This is very basic form of thread creation.

// void fun(int x) {

//     while (x -- > 0)
//     {
//         cout<<x<<endl;
//     }

// }
// int main(){

//     std:: thread t1(fun , 11);
//     t.join();

// return 0;
// }

// 2 . Lambda Functions

// int main()
// {
//     // We can directly inject lambda at thrad cration time
//     auto fun = [](int x)
//     {
//         while (x-- > 0)
//         {
//             cout << x << endl;
//         }
//     } std::thread t1(fun, 11);
//     t.join();

//     return 0;
// }


 // 3. Functors ( Function objects)

// class base{

//     void operator ()(int x){

//         while (x-- > 0)
//         {
//             cout<<x<<endl;
//         }
        
//     }
// };

// int main(){

//     std::thread t(base(), 10);
//     t.join();
//     return 0;
// }

// 4.  Non static member function

// class Base{

//     public:
//     void run(int x){
//          while (x-- > 0)
//         {
//             cout<<x<<endl;
//         }

//     }
// };

// int main(){

//     Base b;
//     std::thread t(&Base:: run , &b , 10); // address of func , object wrt to run , parameter
//     t.join();
//     return 0;
// }


// 5.   Static member function

   
// return 0;
// }
class Base{

    public:
    static void run(int x){
         while (x-- > 0)
        {
            cout<<x<<endl;
        }

    }
};

int main(){

    Base b;
    std::thread t(&Base:: run  , 10); // address of func  , parameter ( no object needed as function is static )
    t.join();
    return 0;
}






