#include "FCFS.h"

FCFS::FCFS() : Scheduler() {}

void FCFS::run() {
        int i = 0;
        if (i < this->getTotalBurstTime()) {
            Proceso p = this->getProcesses()->front();
            p.setBaja(false);
            if (p.getArrivalTime() <= this->getCurrentTime()) {
                p.reduceTime();
                if (!p.getSetTime()) {
                    p.setStartTime(this->getCurrentTime());
                    p.setSetTime(true);
                }
                this->increaseCurrentTime();
                if (p.getTime() == 0) {
                    p.setEndTime(this->getCurrentTime());
                    p.setTurnaroundTime(p.getEndTime() - p.getArrivalTime());
                    p.setWaitingTime(p.getTurnaroundTime() - p.getBurstTime());
                    this->sumTotalWaitingTime(p.getWaitingTime());
                    this->sumTotalTurnaroundTime(p.getTurnaroundTime());
                    this->getProcessesList()->push_back(p); 
                    this->getProcesses()->pop();
                    this->sumProcesses();

                } else {
                    this->getProcesses()->front() = p; 
                }
                this->reduceTotalBurstTime(); 
            }
        }
    } 
    




       