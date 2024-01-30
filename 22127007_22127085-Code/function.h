#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class Process
{
public:
    // Variables for scheduling
    int index;
    int arrivalTime;
    int Task[6];
    int turnAroundTime;
    int waitingTime;
    int curTaskPos;

    Process();
    Process(int at, int tt, int wt);
    Process(const Process &other);
    ~Process(){};

    int getArrivalTime() const;
    int getCurTask();
    void decreaseCurTask();
    Process &operator=(const Process &other);
};

class Scheduler
{
private:
    vector<Process> processes;
    int schedulingAlgorithm;
    int numProcesses;
    int timeQuantum;

    int numCompleted;
    int curTime;
    // Member variables for Gantt charts
    queue<int> cpuQueue;
    queue<int> resourceQueue;
    // Member variables for output
    vector<char> cpuSchedule;
    vector<char> resourceSchedule;

public:
    Scheduler(const string &inputFile, const string &outputFile);
    Scheduler();
    ~Scheduler(){};
    int getProcessByIndex(int index);
    void readInput(const string &inputFile);
    void executeScheduling();
    void fcfsConcrete(vector<char> &Schedule, queue<int> &Queue, queue<int> &otherQueue);
    void fcfsScheduling();

    void sjfConcrete(vector<char> &Schedule, queue<int> &Queue, queue<int> &otherQueue);
    void sjfScheduling();
    void srtnScheduling();

    void rrConcrete(vector<char> &Schedule, queue<int> &Queue, queue<int> &otherQueue);
    void roundRobinScheduling();

    void writeOutput(const string &outputFile);
};
