//
//  std_lock.cpp
//  threads
//
//  Created by Sebastian Tleye on 29/08/2024.
//

#include "std_lock.hpp"
#include <iostream>
#include <thread>

using namespace std;

// syntax----> std::lock(m1, m2, m3, m4)
// 1. All arguments are locked via a sequence of calls to lock(), try_lock(), or unlock() on each argument
// 2. Order of locking is not defined (it will try to lock provided mutex in any order and ensure that there is no dead lock)
// 3. It is a blocking call

std::mutex slm1, slm2;

void task_a() {
    while (1) {
        std::lock(slm1, slm2);
        cout << "task_a\n";
        slm1.unlock();
        slm2.unlock();
    }
}

void task_b() {
    while (1) {
        std::lock(slm2, slm1);
        cout << "task_b\n";
        slm2.unlock();
        slm1.unlock();
    }
}

void std_lock() {
    std::thread th1(task_a);
    std::thread th2(task_b);
    
    th1.join();
    th2.join();
}
