
#ifndef FCFS_H
#define FCFS_H

#include "proceso.h"
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include "scheduler.h"
using namespace std;

class FCFS : public Scheduler {
    public:
        void run();
        FCFS();
};

#endif