//
//  promise_and_future.cpp
//  threads
//
//  Created by Sebastian Tleye on 29/08/2024.
//

#include "promise_and_future.hpp"
#include <iostream>
#include <chrono>
#include <future>

using namespace std;
using namespace std::chrono;

typedef long int ull;

void findOdd(std::promise<ull>&& OddSumPromise, ull start, ull end) {
    ull OddSum = 0;
    for (ull i = start; i <= end; ++i) {
        if (i & 1) {
            OddSum += i;
        }
    }
    OddSumPromise.set_value(OddSum);
}

void promise_and_future() {
    
    ull start = 0;
    ull end = 1900000000;
    
    std::promise<ull> OddSum;
    std::future<ull> OddFuture = OddSum.get_future();
    
    cout << "Thread Created!!" << endl;
    std::thread t1(findOdd, std::move(OddSum), start, end);
    
    cout << "Waiting For Result!!" << endl;
    
    cout << "OddSum : " << OddFuture.get() << endl;
    
    cout << "Completed!!" << endl;
    t1.join();
    
}
