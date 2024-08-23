//
//  try_lock.cpp
//  threads
//
//  Created by Sebastian Tleye on 23/08/2024.
//

#include "mutex_try_lock.hpp"
#include <iostream>
#include <thread>

using namespace std;

int counter = 0;
std::mutex mtx;

void increaseTheCounterFor100000Time() {
    for (int i=0; i<100000; ++i) {
        if (mtx.try_lock()) {
            ++counter;
            mtx.unlock();
        }
    }
}

int mutex_try_lock() {
    std::thread t1(increaseTheCounterFor100000Time);
    std::thread t2(increaseTheCounterFor100000Time);
    
    t1.join();
    t2.join();
    
    cout << "Counter could increase up to : " << counter << endl;
    
    return 0;
}
