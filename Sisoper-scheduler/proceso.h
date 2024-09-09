#include <iostream>
#include <string>
#include <queue>

using namespace std;

#ifndef PROCESO_H
#define PROCESO_H

class Proceso{
    private:
        int state;
        int priority;
        int burstTime;
        int arrivalTime;
        int id;
        int waitingTime;
        int turnaroundTime;
        int startTime;
        int endTime;
        int time;
        bool baja=false;
        bool setTime=false;
    public:
        void setState(int s);
        void setPriority(int p);
        void setBurstTime(int b);
        void setArrivalTime(int a);
        void setId(int i);
        void setWaitingTime(int w);
        void setTurnaroundTime(int t);
        void setStartTime(int s);
        void setEndTime(int e);
        int getPriority();
        int getBurstTime();
        int getArrivalTime();
        int getId();
        int getWaitingTime();
        int getTurnaroundTime();
        int getStartTime();
        int getEndTime();
        int getTime();
        void reduceTime();
        bool getSetTime();
        void setSetTime(bool s);
        Proceso(int s, int p, int b, int a, int i);
        Proceso();
        void setBaja(bool b);
        bool getBaja();
};




#endif