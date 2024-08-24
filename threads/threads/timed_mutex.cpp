//
//  timed_mutex.cpp
//  threads
//
//  Created by Sebastian Tleye on 23/08/2024.
//

#include "timed_mutex.hpp"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int myAmountTimedMutex = 0;
std::timed_mutex timed_m;

void increment(int i) {
    if (timed_m.try_lock_for(std::chrono::seconds(1))) {
        ++myAmountTimedMutex;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "Thread " << i << " Entered" << endl;
        timed_m.unlock();
    } else {
        cout << "Thread " << i << " Couldn't enter" << endl;
    }
}

int timed_mutex() {
    std::thread t1(increment, 1);
    std::thread t2(increment, 2);
    
    t1.join();
    t2.join();
    
    cout << myAmountTimedMutex << endl;
    
    return 0;
}
