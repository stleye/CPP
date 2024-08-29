//
//  thread_synchronization.cpp
//  threads
//
//  Created by Sebastian Tleye on 27/08/2024.
//

#include "thread_synchronization.hpp"
#include <iostream>
#include <thread>

using namespace std;

long long bankBalance = 0;
std::mutex tsm;

void addMoney(long long val) {
    
    if (val <= 0)
        return;
 
    tsm.lock();
    bankBalance+=val;
    tsm.unlock();
}

int thread_synchronization() {
    std::thread t1(addMoney,100);
    std::thread t2(addMoney,100);
    std::thread t3(addMoney,100);
    std::thread t4(addMoney,0);
    std::thread t5(addMoney,0);
    std::thread t6(addMoney,0);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    
    cout << "Final BankBalance : " << bankBalance << endl;
    
    return 0;
}
