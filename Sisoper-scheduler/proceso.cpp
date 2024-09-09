#include "proceso.h"


void Proceso::setState(int s){
    state = s;
}
void Proceso::setPriority(int p){
    priority = p;
}
void Proceso::setBurstTime(int b){
    burstTime = b;
}
void Proceso::setArrivalTime(int a){
    arrivalTime = a;
}
void Proceso::setId(int i){
    id = i;
}
void Proceso::setWaitingTime(int w){
    waitingTime = w;
}
void Proceso::setTurnaroundTime(int t){
    turnaroundTime = t;
}
void Proceso::setStartTime(int s){
    startTime = s;
}
void Proceso::setEndTime(int e){
    endTime = e;
}
int Proceso::getPriority(){
    return priority;
}
int Proceso::getBurstTime(){
    return burstTime;
}
int Proceso::getArrivalTime(){
    return arrivalTime;
}
int Proceso::getId(){
    return id;
}
int Proceso::getWaitingTime(){
    return waitingTime;
}
int Proceso::getTurnaroundTime(){
    return turnaroundTime;
}
int Proceso::getStartTime(){
    return startTime;
}
int Proceso::getEndTime(){
    return endTime;
}
int Proceso::getTime(){
    return time;
}
void Proceso::reduceTime(){
    time -= 1;
}
bool Proceso::getSetTime(){
    return setTime;
}
void Proceso::setSetTime(bool s){
    setTime = s;
}
Proceso::Proceso(int s, int p, int b, int a, int i){
    state = s;
    priority = p;
    burstTime = b;
    arrivalTime = a;
    id = i;
    time = b;
    waitingTime = 0;
    turnaroundTime = 0;
    startTime = 0;
    endTime = 0;
    
}
Proceso::Proceso(){
    state = 0;
    priority = 0;
    burstTime = 0;
    arrivalTime = 0;
    id = 0;
}
void Proceso::setBaja(bool b){
    baja = b;
}
bool Proceso::getBaja(){
    return baja;
}

