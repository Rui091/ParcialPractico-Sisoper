#include "RR.h"

void RR::sortProcesses() {
    std::queue<Proceso> tempQueue;
    std::queue<Proceso> readyQueue;
    std::queue<Proceso> notReadyQueue;

    // Reorganizar la cola en dos grupos: listos y no listos.
    while (!this->getProcesses()->empty()) {
        Proceso p = this->getProcesses()->front();
        this->getProcesses()->pop();
        
        if (p.getArrivalTime() <= this->getCurrentTime()) {

            readyQueue.push(p);  // Proceso listo para ejecutarse.
        } else {
            notReadyQueue.push(p);  // Proceso no listo.
        }
    }

    // Primero agregamos los procesos listos a la cola principal.
    while (!readyQueue.empty()) {
        this->getProcesses()->push(readyQueue.front());
        readyQueue.pop();
    }

    // Después agregamos los procesos no listos.
    while (!notReadyQueue.empty()) {
        this->getProcesses()->push(notReadyQueue.front());
        notReadyQueue.pop();
    }
}

    

void RR::run(){
            int i = 0;
            if(i < this->getTotalBurstTime()) {
                Proceso p = this->getProcesses()->front();
                if (p.getArrivalTime() <= this->getCurrentTime()) {
                    if (!p.getSetTime()) {
                        p.setStartTime(this->getCurrentTime());
                        p.setSetTime(true);
                    }
                    this->increaseCurrentTime();
                    if(fictQuantum > 0 && p.getTime() > 0){
                        p.reduceTime();
                        --fictQuantum;
                    }

                    if(fictQuantum == 0 || p.getTime() == 0){  
                        fictQuantum = quantum;
                        if(p.getTime() == 0) {
                            p.setEndTime(this->getCurrentTime());
                            p.setTurnaroundTime(p.getEndTime() - p.getArrivalTime());
                            p.setWaitingTime(p.getTurnaroundTime() - p.getBurstTime());
                            this->sumTotalWaitingTime(p.getWaitingTime());
                            this->sumTotalTurnaroundTime(p.getTurnaroundTime());
                            this->getProcessesList()->push_back(p); 
                            this->getProcesses()->pop();
                            p.setState(true);
                            this->sumProcesses();
                            
                        }
                        else {
                            if(!this->getMLFQ()){
                                this->getProcesses()->pop();
                                this->getProcesses()->push(p);
                                
                    
                            }
                            else{
                                p.setBaja(true);
                                this->setProcess(p);
                            }
                        }
                    }
                    
                    this->reduceTotalBurstTime();
                    if(p.getId() == this->getProcesses()->front().getId()){
                        this->getProcesses()->front() = p;
                    }
                    
                }
                this->sortProcesses();
            }
}


