//
// Created by Gilad on 15-Dec-18.
//

#ifndef OS3_JOB_HPP
#define OS3_JOB_HPP

#include "Headers.hpp"
#include "Lock.hpp"

class Job {
public:
    Job (uint lower, uint upper, bool_mat* current, bool_mat* next);
    virtual void run();

private:
    uint lower_row;
    uint upper_row;
    bool_mat* current;
    bool_mat* next;

    /**
     * Count the number of live neighbors of a given cell for the current state of the job's board
     * @param i Cell's x coordinate
     * @param j Cell's y coordinate
     * @return Number of live cells which are neighbors to (i,j).
     * Cells out of bound of the given board are considered dead
     */
    int countNeighbors(int i, int j);
};


#endif //OS3_JOB_HPP
