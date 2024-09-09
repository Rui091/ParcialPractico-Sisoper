#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "proceso.h"
#include <vector>
#include <queue>

using namespace std;
class Scheduler {
private:
    std::queue<Proceso> processes;
    int currentTime;
    int totalWaitingTime;
    int totalTurnaroundTime;
    int totalProcesses;
    int processCount;
    int totalBurstTime;
    bool paused;
    bool MLFQ = false;
    Proceso currentProcess;
    vector<Proceso> processList;

public:
    Scheduler();
    void addProcess(Proceso p);
    std::queue<Proceso>* getProcesses(); // Returns a pointer to the queue
    void sumWaitingTime();
    void printProccesses() ;
    int getTotalBurstTime() const;
    void setTotalBurstTime(int t);
    void setPaused(bool p);
    bool getPaused() const;
    void setCurrentTime(int c);
    int getCurrentTime() const;
    void reduceTotalBurstTime();
    void increaseCurrentTime();
    void sumTotalWaitingTime(int t);
    void sumTotalTurnaroundTime(int t);
    vector<Proceso>* getProcessesList(); // Returns a pointer to the vector
    void decreaseBurtsTime();
    virtual void run();
    int getTotalWaitingTime();
    int getTotalTurnaroundTime();
    int getTotalProcesses();
    void sumTotalWaitingTime2();
    bool getMLFQ();
    void setMLFQ(bool m);
    void setProcess(Proceso p);
    Proceso getCurrentProcess();
    void setProcesses(std::queue<Proceso> p);
    void sumProcesses();
};

#endif
