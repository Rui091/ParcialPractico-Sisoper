#include "proceso.h"
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include "scheduler.h"
#include <algorithm>
using namespace std;


#ifndef RR_H
#define RR_H

class RR: public Scheduler{
    private:
        int quantum;
        int fictQuantum;
    public:
        RR(int q) : Scheduler(), quantum(q),fictQuantum(q) {}
        void run() override;
        void sortProcesses();   
};


#endif
