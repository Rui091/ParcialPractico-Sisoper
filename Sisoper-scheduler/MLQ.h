#ifndef MLQ_H
#define MLQ_H


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

using namespace std;

class MLQ{
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
        void addQueue(Scheduler* s, int priority); 
        void sumTotalBurtsTime();
        void sortQueuesByPriority();
        void increaseCurrentTime(int running);
        void run();
        void printProccesses();
        MLQ();

};



#endif