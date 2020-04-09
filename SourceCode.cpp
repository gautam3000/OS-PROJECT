#include<iostream> 
using namespace std; 
void WaitingTime(int processes[], int store, int Burst_Time[], int WaitingTime[], int TimeSlack) 
{ 
	int REM_BT[store]; 
	for (int i = 0 ; i < store ; i++) 
		REM_BT[i] = Burst_Time[i]; 

	int t = 0;   
	while (1) 
	{ 
		bool done = true; 
		for (int i = 0 ; i < store; i++) 
		{  
			if (REM_BT[i] > 0) 
			{ 
				done = false;

				if (REM_BT[i] > TimeSlack) 
				{  
					t += TimeSlack; 
					REM_BT[i] -= TimeSlack; 
				} 
                else
				{ 
					t = t + REM_BT[i]; 
					WaitingTime[i] = t - Burst_Time[i]; 
					REM_BT[i] = 0; 
				} 
			} 
		} 
		if (done == true) 
		break; 
	} 
} 
void TurnAroundTime(int processes[], int NumberS,int BurstTime[], int WaitingTime[], int TurnTime[]) 
{ 
	for (int i = 0; i < NumberS ; i++) 
		TurnTime[i] = BurstTime[i] + WaitingTime[i]; 
} 
void avgTime(int processes[], int NUMBER, int BURSTTIME[], int TIMEQUANTUM) 
{ 
	int WaitingTime2[NUMBER], TurnTime[NUMBER], TOTALWAITINGTIME = 0, TOTALTURNTIME = 0; 
	WaitingTime(processes, NUMBER, BURSTTIME, WaitingTime2, TIMEQUANTUM);  
	TurnAroundTime(processes, NUMBER, BURSTTIME, WaitingTime2, TurnTime); 
	cout << "Processes "<< " Burst time "<< " Waiting time " << " Turn around time\n"; 
	for (int i=0; i< NUMBER; i++) 
	{ 
		TOTALWAITINGTIME = TOTALWAITINGTIME + WaitingTime2[i]; 
		TOTALTURNTIME = TOTALTURNTIME + TurnTime[i]; 
		cout << " " << i+1 << "\t\t" << BURSTTIME[i] <<"\t "<< WaitingTime2[i] <<"\t\t " << TurnTime[i] <<endl; 
	} 

	cout << "Average waiting time = "<< (float)TOTALWAITINGTIME / (float)NUMBER; 
	cout << "\nAverage turn around time = "<< (float)TOTALTURNTIME / (float)NUMBER; 
}  
int main() 
{
    int numberOfProcess ;
    cin >> numberOfProcess ;
    int processes[numberOfProcess];
    for(int i = 0 ; i < numberOfProcess ; i++)
    {
        processes[i] = i + 1 ;
    }   
    int BurstTime[numberOfProcess];
    for(int i = 0 ; i < numberOfProcess; i++)
    {
        cout << "Enter burst time for " << i+1 << " process :- ";
        cin >> BurstTime[i];
    }
    cout << "Enter the time slace for each process:- ";
    int Time ;
    cin >> Time ;
	avgTime(processes, numberOfProcess, BurstTime, Time); 
	return 0; 
} 
