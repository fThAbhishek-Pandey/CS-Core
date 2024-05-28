#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
// /#include<paser.h>
using namespace std;
string operation;
int last_instant, process_count;
// vector<pair<char, int>> algorithms;
vector<tuple<string,int,int>> processes;
vector<vector<char>>timeline;
// unordered_map<string,int>processToIndex;


//Results

vector<int>finishTime;
vector<int>turnAroundTime;
vector<float>normTurn;

int getArrivalTime(tuple<string, int, int> &a)
{
    return get<1>(a);
}
int getServiceTime(tuple<string, int, int> &a)
{
    return get<2>(a);
}

void fillInWaitTime(){
    for (int i = 0; i < process_count; i++)
    {
        int arrivalTime = getArrivalTime(processes[i]);
        for (int k = arrivalTime; k < finishTime[i]; k++)
        {
            if (timeline[k][i] != '*')
                timeline[k][i] = '.';

        }
    }
}
 void shortestRemainingTime()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int j = 0;
    for (int i = 0; i < last_instant; i++)
    {
        while(j<process_count &&getArrivalTime(processes[j]) == i){
            pq.push(make_pair(getServiceTime(processes[j]), j));
            j++;
        }
        if (!pq.empty())
        {
            int processIndex = pq.top().second;
            int remainingTime = pq.top().first;
            pq.pop();
            int serviceTime = getServiceTime(processes[processIndex]);
            int arrivalTime = getArrivalTime(processes[processIndex]);
            timeline[i][processIndex] = '*';

            if (remainingTime == 1) // process finished
            {
                finishTime[processIndex] = i + 1;
                turnAroundTime[processIndex] = (finishTime[processIndex] - arrivalTime);
                normTurn[processIndex] = (turnAroundTime[processIndex] * 1.0 / serviceTime);
            }
            else
            {
                pq.push(make_pair(remainingTime - 1, processIndex));
            }
        }
    }
    fillInWaitTime();
}
void printProcesses()
{
    cout << "Process    ";
    for (int i = 0; i < process_count; i++)
        cout << "|  " << getProcessName(processes[i]) << "  ";
    cout << "|\n";
}
void printArrivalTime()
{
    cout << "Arrival    ";
    for (int i = 0; i < process_count; i++)
        printf("|%3d  ",getArrivalTime(processes[i]));
    cout<<"|\n";
}
void printServiceTime()
{
    cout << "Service    |";
    for (int i = 0; i < process_count; i++)
        printf("%3d  |",getServiceTime(processes[i]));
    cout << " Mean|\n";
}
void printFinishTime()
{
    cout << "Finish     ";
    for (int i = 0; i < process_count; i++)
        printf("|%3d  ",finishTime[i]);
    cout << "|-----|\n";
}
void printTurnAroundTime()
{
    cout << "Turnaround |";
    int sum = 0;
    for (int i = 0; i < process_count; i++)
    {
        printf("%3d  |",turnAroundTime[i]);
        sum += turnAroundTime[i];
    }
    if((1.0 * sum / turnAroundTime.size())>=10)
		printf("%2.2f|\n",(1.0 * sum / turnAroundTime.size()));
    else
	 	printf(" %2.2f|\n",(1.0 * sum / turnAroundTime.size()));
}

void printNormTurn()
{
    cout << "NormTurn   |";
    float sum = 0;
    for (int i = 0; i < process_count; i++)
    {
        if( normTurn[i]>=10 )
            printf("%2.2f|",normTurn[i]);
        else
            printf(" %2.2f|",normTurn[i]);
        sum += normTurn[i];
    }

    if( (1.0 * sum / normTurn.size()) >=10 )
        printf("%2.2f|\n",(1.0 * sum / normTurn.size()));
	else
        printf(" %2.2f|\n",(1.0 * sum / normTurn.size()));
}
void printStats(int algorithm_index)
{
    printProcesses();
    printArrivalTime();
    printServiceTime();
    printFinishTime();
    printTurnAroundTime();
    printNormTurn();
}

int main(){
    //    parse();
       shortestRemainingTime();
       return 0;
}
