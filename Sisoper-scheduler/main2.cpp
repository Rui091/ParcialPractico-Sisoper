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
    int numProcesos;
    int numColas;
    string algoritmo;
    string algoritmoColas;
    int priority;
    int i = 0;
    int j = 0;

    cin >> algoritmo >> numColas;

    // Crear el objeto adecuado basado en el algoritmo
    if (algoritmo == "MLFQ"){
        MLFQ mlfq;
        while (i < numColas) {
            cin >> algoritmoColas >>numProcesos;
            ++i;
            Scheduler* q;

            if (algoritmoColas == "RR") {
                int quantum;
                cin >> quantum;
                q = new RR(quantum);
            }
            else if (algoritmoColas == "FCFS") {
                q = new FCFS();
            }
            else {
                cerr << "Algoritmo de cola no soportado" << endl;
                return 1;
            }
            while(j<numProcesos && i == 0){
                int id;
                int arrivalTime;
                int burstTime;
                cin >> id >> arrivalTime >> burstTime ;
                Proceso p(0, 0, burstTime, arrivalTime, id);
                q->addProcess(p);
                j++;
            }
            mlfq.addQueue(q, i+1);
        }

        mlfq.run();
        mlfq.printProccesses();

    } else if (algoritmo == "MLQ") {
        MLQ mlq;
        while (i < numColas) {
            cin >> priority >> algoritmoColas >> numProcesos;
            ++i;
            Scheduler* q;

            if (algoritmoColas == "RR") {
                int quantum;
                cin >> quantum;
                q = new RR(quantum);
            }
            else if (algoritmoColas == "FCFS") {
                q = new FCFS();
            }
            else {
                cerr << "Algoritmo de cola no soportado" << endl;
                return 1;
            }
            while(j<numProcesos){
                int id;
                int arrivalTime;
                int burstTime;
                cin >> id >> arrivalTime >> burstTime ;
                Proceso p(0, 0, burstTime, arrivalTime, id);
                q->addProcess(p);
                j++;
            }
            mlq.addQueue(q, priority);
        }
    }
    return 0;
}


