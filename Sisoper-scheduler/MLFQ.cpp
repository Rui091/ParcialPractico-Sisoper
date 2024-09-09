#include "MLFQ.h"



MLFQ::MLFQ() : currentTime(0), totalWaitingTime(0), totalTurnaroundTime(0), totalProcesses(0),
       processCount(0), totalBurstTime(0) {}

void MLFQ::addQueue(Scheduler* s, int priority) {
    pair<Scheduler*, int> p;
    p.first = s;
    p.second = priority;
    s->setMLFQ(true);
    queues.push_back(p);
    sortQueuesByPriority();
}

void MLFQ::sumTotalBurtsTime() {
    for (int i = 0; i < queues.size(); ++i) {
        totalBurstTime += queues[i].first->getTotalBurstTime();
    }
}

void MLFQ::sortQueuesByPriority() {
    sort(queues.begin(), queues.end(), [](const pair<Scheduler*, int>& a, const pair<Scheduler*, int>& b) {
        return a.second < b.second;
    });
}

void MLFQ::increaseCurrentTime(int running) {
    for (int i = 0; i < queues.size(); ++i) {
        if (i != running) {
            queues[i].first->increaseCurrentTime();

        }
    
    }
}
void MLFQ::ubicate(Proceso &p,int running){
    queues[running+1].first->addProcess(p);
}

void MLFQ::run() {
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
            if (firstToRun < queues.size()-1){
                if(queues[firstToRun].first->getProcesses()->front().getBaja()){
                    Proceso p = queues[firstToRun].first->getProcesses()->front();
                    queues[firstToRun].first->getProcesses()->pop();
                    ubicate(p,firstToRun);
                }
            }
        }
        increaseCurrentTime(firstToRun);
        ++currentTime;
        }
    
    }
void MLFQ::printProccesses() {
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



