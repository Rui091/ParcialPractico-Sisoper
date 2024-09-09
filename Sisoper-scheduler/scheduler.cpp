#include "scheduler.h"
#include <iostream>

Scheduler::Scheduler()
    : currentTime(0), totalWaitingTime(0), totalTurnaroundTime(0), totalProcesses(0),
      processCount(0), totalBurstTime(0), paused(false) {}

void Scheduler::addProcess(Proceso p) {
    totalBurstTime += p.getBurstTime();
    if (processes.empty()) {
        processes.push(p);
         
    } else {
        if (p.getArrivalTime() < processes.front().getArrivalTime()) {
            std::queue<Proceso> temp;
            temp.push(p);
            while (!processes.empty()) {
                temp.push(processes.front());
                processes.pop();
            }
            processes = temp;
        } else {
            processes.push(p);
        }
    }
}

std::queue<Proceso>* Scheduler::getProcesses() {
    return &processes;
}

void Scheduler::sumWaitingTime() {
    std::queue<Proceso> temp;
    Proceso p1 = processes.front();
    temp.push(p1);
    processes.pop();
    while (!processes.empty()) {
        Proceso p = processes.front();
        int counter = p.getWaitingTime();
        if(p.getArrivalTime() <= currentTime){
            p.setWaitingTime(counter + 1);
        }
        processes.pop();
        temp.push(p);
        totalWaitingTime += 1;
    }
    processes = temp;
}
void Scheduler::sumTotalWaitingTime2(){
    std::queue<Proceso> temp;
    while (!processes.empty()) {
        Proceso p = processes.front();
        int counter = p.getWaitingTime();
        if(p.getArrivalTime() <= currentTime){
            p.setWaitingTime(counter + 1);
        }
        processes.pop();
        temp.push(p);
    }
    totalWaitingTime += 1;
    processes = temp;
}

void Scheduler::printProccesses() {
    for(int i=0;i<this->getProcessesList()->size();i++){
        cout << "Proceso " << this->getProcessesList()->at(i).getId() << " | Tiempo de llegada: " << this->getProcessesList()->at(i).getArrivalTime()
        << " | Tiempo de inicio: " << this->getProcessesList()->at(i).getStartTime() << " | Tiempo de fin: " << this->getProcessesList()->at(i).getEndTime()
        << " | Tiempo de espera: " << this->getProcessesList()->at(i).getWaitingTime() << " | Tiempo de retorno: " << this->getProcessesList()->at(i).getTurnaroundTime()
        << endl;    

    }
}

int Scheduler::getTotalBurstTime() const {
    return totalBurstTime;
}

void Scheduler::setTotalBurstTime(int t) {
    totalBurstTime = t;
}

void Scheduler::setPaused(bool p) {
    paused = p;
}

bool Scheduler::getPaused() const {
    return paused;
}

void Scheduler::setCurrentTime(int c) {
    currentTime = c;
}

int Scheduler::getCurrentTime() const {
    return currentTime;
}

void Scheduler::reduceTotalBurstTime() {
    --totalBurstTime;
}

void Scheduler::increaseCurrentTime() {
    ++currentTime;
}

void Scheduler::sumTotalWaitingTime(int t) {
    totalWaitingTime += t;
}

void Scheduler::sumTotalTurnaroundTime(int t) {
    totalTurnaroundTime += t;
}


void Scheduler:: run() {
    
}

int Scheduler::getTotalWaitingTime() {
    return totalWaitingTime;
}

int Scheduler::getTotalTurnaroundTime() {
    return totalTurnaroundTime;
}

int Scheduler::getTotalProcesses() {
    return totalProcesses;
}

vector<Proceso>* Scheduler::getProcessesList() {
    return &processList;
}

bool Scheduler::getMLFQ() {
    return MLFQ;
}

void Scheduler::setMLFQ(bool m) {
    MLFQ = m;
}

void Scheduler::setProcess(Proceso p) {
    currentProcess = p;
}

Proceso Scheduler::getCurrentProcess() {
    return currentProcess;
}
void Scheduler::setProcesses(std::queue<Proceso> p){
    processes = p;
}

void Scheduler::sumProcesses(){
    totalProcesses += 1;
}