#include "MLQ.h"

MLQ::MLQ() : currentTime(0), totalWaitingTime(0), totalTurnaroundTime(0), totalProcesses(0),
       processCount(0), totalBurstTime(0) {}

void MLQ::addQueue(Scheduler* s, int priority) {
    pair<Scheduler*, int> p;
    p.first = s;
    p.second = priority;
    queues.push_back(p);
    sortQueuesByPriority();

}
void MLQ::sumTotalBurtsTime() {
    for (int i = 0; i < queues.size(); ++i) {
        totalBurstTime += queues[i].first->getTotalBurstTime();
    }
}
void MLQ::sortQueuesByPriority() {
    sort(queues.begin(), queues.end(), [](const pair<Scheduler*, int>& a, const pair<Scheduler*, int>& b) {
        return a.second < b.second;
    });
}
void MLQ::increaseCurrentTime(int running) {
    for (int i = 0; i < queues.size(); ++i) {
        if (i != running) {
            queues[i].first->increaseCurrentTime();
        }
    }
}
void MLQ::run() {
    int i = 0;
    sumTotalBurtsTime();
    int x = totalBurstTime;
    while (i < x) {
        int firstToRun = -1;
        for (int j = 0; j < queues.size(); ++j){
            if(!queues[j].first->getProcesses()->empty()){  
                if (queues[j].first->getTotalBurstTime() > 0 && queues[j].first->getProcesses()->front().getArrivalTime() <= currentTime) {
                    firstToRun = j;
                    break;
                }
            }
        }
        if (firstToRun != -1) {
            queues[firstToRun].first->run();
            --x;
        }
        increaseCurrentTime(firstToRun);
        ++currentTime;
    }
}

        
void MLQ::printProccesses() {
    for (int i = 0; i < queues.size(); ++i) {
        queues[i].first->printProccesses();
        totalWaitingTime+=queues[i].first->getTotalWaitingTime();
        totalTurnaroundTime+=queues[i].first->getTotalTurnaroundTime();
        totalProcesses += queues[i].first->getTotalProcesses();
    }
    cout << "Total waiting time: " << totalWaitingTime << endl;
    cout << "Total turnaround time: " << totalTurnaroundTime << endl;
    cout << "Total WT per process: " << totalWaitingTime/totalProcesses << endl;
    cout << "Total TAT per process: " << totalTurnaroundTime/totalProcesses << endl;
}