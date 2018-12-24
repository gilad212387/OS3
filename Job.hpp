//
// Created by Gilad on 15-Dec-18.
//

#ifndef OS3_JOB_HPP
#define OS3_JOB_HPP

#include "Headers.hpp"
#include "GameField.hpp"
#include "Lock.hpp"

class Job {
public:
    Job (uint lower, uint upper, GameField* current, GameField* next,
         vector<Lock*>& lower_s, vector<Lock*>& upper_s) {
        lower_row = lower;
        upper_row = upper;
        this->current = current;
        this->next = next;
        this->lower_locks = lower_s;
        this->upper_locks = upper_s;
    }
    void run();

private:
    uint lower_row;
    uint upper_row;
    GameField* current;
    GameField* next;
    vector<Lock*> lower_locks;
    vector<Lock*> upper_locks;
};


#endif //OS3_JOB_HPP