#include "FCFS.h"
#include "proceso.h"
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include "RR.h"
#include "scheduler.h"
#include "MLQ.h"
#include "MLFQ.h"
using namespace std;


int main(){
    Proceso p1(0, 1, 2, 0, 1);
    Proceso p2(0, 2, 3, 0, 2);
    Proceso p3(0, 3, 8, 10, 3);
    Proceso p4(0, 4, 6, 10, 4);
    Proceso p5(0, 5, 4, 10, 5);
    Proceso p6(0, 6, 2, 10, 6);
    Proceso p7(0, 7, 7, 10, 7);
    Proceso p8(0, 8, 1, 10, 8);
    Proceso p9(0, 9, 9, 10, 9);
    Proceso p10(0, 10, 5, 10, 10);
    Proceso p11(0, 11, 3, 10, 11);
    Proceso p12(0, 12, 8, 10, 12);
    Proceso p13(0, 13, 6, 10, 13);
    Proceso p14(0, 14, 4, 10, 14);
    Proceso p15(0, 15, 2, 10, 15);
    RR* r = new RR(2);
    FCFS* f = new FCFS();
    MLQ m;
    r->addProcess(p1);
    r->addProcess(p2);
    r->addProcess(p3);
    f->addProcess(p9);
    f->addProcess(p10);
    m.addQueue(r, 1);
    m.addQueue(f, 2);
    m.run();
    m.printProccesses();

    return 0;
    
    

}