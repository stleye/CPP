//
//  condition_variable.cpp
//  threads
//
//  Created by Sebastian Tleye on 24/08/2024.
//

#include "condition_variable.hpp"
#include <thread>
#include <condition_variable>
#include <iostream>

using namespace std;

std::condition_variable cv;
std::mutex cvm;
long balance = 0;

void cvAddMoney(int money) {
    std::lock_guard<mutex> lg(cvm);
    balance+=money;
    cout << "Amount Added Current Balance: " << balance << endl;
    cv.notify_one();
}

void withdrawMoney(int money) {
    std::unique_lock<mutex> ul(cvm);
    cv.wait(ul, [] { return (balance != 0) ? true : false; });
    if (balance>=money) {
        balance -= money;
        cout << "Amount Deducted: " << money << endl;
    } else {
        cout << "Amount Can't Be Deducted, Current Balance is less Than " << money << endl;
    }
    cout << "Current Balance Is: " << balance << endl;
}

int conditional_variable() {
    std::thread t1(withdrawMoney, 500);
    std::thread t2(cvAddMoney, 500);
    t1.join();
    t2.join();
    return 0;
}
