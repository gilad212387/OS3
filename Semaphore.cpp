//
// Created by Gilad on 14-Dec-18.
//
#include "Semaphore.hpp"

Semaphore::Semaphore() {
    pthread_cond_init(&cond, nullptr);
    pthread_mutex_init(&m, nullptr);
    this->val = 0;
}

Semaphore::Semaphore(unsigned val) {
    pthread_cond_init(&cond, nullptr);
    pthread_mutex_init(&m, nullptr);
    this->val = val;
}

void Semaphore::down() {
    pthread_mutex_lock(&m);
    while(val == 0) {
        pthread_cond_wait(&cond, &m);
        // cout << "Waiting" << endl;
    }
    val--;
    pthread_mutex_unlock(&m);
}

void Semaphore::up() {
    pthread_mutex_lock(&m);
    val++;
    // cout << "Up" << endl;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&m);
}

