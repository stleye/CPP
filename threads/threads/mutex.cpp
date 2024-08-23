//
//  mutex.cpp
//  threads
//
//  Created by Sebastian Tleye on 22/08/2024.
//

#include "mutex.h"
#include <iostream>
#include <thread>

int myAmount = 0;

std::mutex m;

void addMoney() {
    for (int i = 0; i < 100; i++) {
        m.lock();
        ++myAmount;
        m.unlock();
    }
}


void mutex() {
    std::thread t1(addMoney);
    std::thread t2(addMoney);
    
    t1.join();
    t2.join();
    
    std::cout << myAmount << std::endl;
}
