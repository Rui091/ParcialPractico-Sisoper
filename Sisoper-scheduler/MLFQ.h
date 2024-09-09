

#ifndef MLFQ_H
#define MLFQ_H

#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include "scheduler.h"
#include "RR.h"
#include "FCFS.h"
#include "process.h"
#include <utility>
#include <algorithm>

class MLFQ{
    private:
        vector<pair<Scheduler*,int>> queues;
        int numQueues;
        int currentTime;
        float totalWaitingTime;
        float totalTurnaroundTime;
        int totalProcesses;
        int processCount;
        int totalBurstTime;
    public:
        void addQueue(Scheduler* s, int priority); ;
        void sumTotalBurtsTime();
        void sortQueuesByPriority();
        void increaseCurrentTime(int running);
        void run();
        void printProccesses();
        Proceso* getProcess();
        void ubicate(Proceso &p,int running);
        MLFQ();


};





#endif