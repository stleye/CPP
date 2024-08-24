//
//  recursive_mutex.cpp
//  threads
//
//  Created by Sebastian Tleye on 23/08/2024.
//

#include "recursive_mutex.hpp"
#include <iostream>
#include <thread>

using namespace std;

std::recursive_mutex rm1;
int buffer = 0;

void recursion(char c, int loopFor) {
    if(loopFor<0)
        return;
    
    rm1.lock();
    cout << c << " " << buffer++ << endl;
    recursion(c, --loopFor);
    rm1.unlock();
}

int recursive_mutex() {
    thread t1(recursion, '0', 10);
    thread t2(recursion, '1', 10);
    t1.join();
    t2.join();
    
    return 0;
}
