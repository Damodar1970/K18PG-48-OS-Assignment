#include<iostream>
#include<conio.h>
using namespace std; 
  
// creating a structure of a process 
struct process { 
    int processno; 
    int AT; 
    int BT; 
  
    // for backup purpose to print in last 
    int BTbackup; 
    int WT; 
    int TAT; 
    int CT; 
}; 
  
// creating a structe of 3  students
struct process p[3]; 
  
// variable to find the total time 
int totaltime = 0; 
int prefinaltotal = 0; 
// comparator function for sort() 
bool compare(process p1, process p2) 
{ 
    // compare the processno of two processes 
    return p1.processno < p2.processno; 
} 

int findlargest(int at) 
{ 
    int max = 0, i; 
    for (i = 0; i <=2; i++) { 
        if (p[i].AT <= at) { 
            if (p[i].BT > p[max].BT) 
                max = i; 
        } 
    } 
  
    // returning the index of the process having the largest BT 
    return max; 
} 
  
// function to find the completion time of each process 
int findCT() 
{ 
  
    int index; 
    int flag = 0; 
    int i = p[0].AT; 
    while (1) { 
        if (i <= 2) { 
            index = findlargest(i); 
        } 
  
        else
            index = findlargest(2); 
        cout << "Process executing at time " << totaltime 
             << " is: P" << index + 1 << "\t"; 
  
        p[index].BT -= 1; 
        totaltime += 1; 
        i++; 
  
        if (p[index].BT == 0) { 
            p[index].CT = totaltime; 
            cout << " Process P" << p[index].processno  
                 << " is completed at " << totaltime; 
        } 
        cout << endl; 
  
        // loop termination condition 
        if (totaltime == prefinaltotal) 
            break; 
    } 

int main() 
{ 
  
    int i; 
  
    // initializing the process number 
     
        p[0].processno =2132 ; 
        
        p[1].processno =2102 ; 
         
        p[0].processno =2453 ; 
    } 
  
    // cout<<"arrival time of 3 processes: "; 
    for (i = 0; i <=2; i++) // taking AT 
    { 
        p[i].AT =0; 
    } 
  
    // cout<<" Burst time of 4 processes/students : "; 
    for (i = 0; i <2; i++) { 
  
        // assigning {2, 4,  8} as Burst Time to the processes/students 
        // backup for displaying the output in last 
        // calculating total required time for terminating  
        // the function(). 
       p[0].BT=2
        p[i+1].BT = 2 * p[i]; 
        p[i+1].BTbackup = p[i+1].BT; 
        prefinaltotal += p[i+1].BT; 
    } 

 // displaying the process before executing 
    cout << "PNo\tAT\tBT\n"; 
  
    for (i = 0; i <=2; i++) { 
        cout << p[i].processno << "\t"; 
        cout << p[i].AT << "\t"; 
        cout << p[i].BT << "\t"; 
        cout << endl; 
    } 
    cout << endl; 
  
    // soritng process according to processno; 
    sort(p, p + 2, compare); 
  
    // calculating initial time when execution starts 
    totaltime += p[0].AT; 
  
    // calculating to terminate loop 
    prefinaltotal += p[0].AT; 
    findCT(); 
    int totalWT = 0; 
    int totalTAT = 0; 
    for (i = 0; i <=2; i++) { 
        // since, TAT = CT - AT 
        p[i].TAT = p[i].CT - p[i].AT; 
        p[i].WT = p[i].TAT - p[i].BTbackup; 
  
        // finding total waiting time 
        totalWT += p[i].WT; 
  
        // finding total turn around time 
        totalTAT += p[i].TAT; 
    } 
  
    cout << "After execution of all processes ... \n"; 
  
    // after all process executes 
    cout << "PNo\tAT\tBT\tCT\tTAT\tWT\n"; 
  
    for (i = 0; i <=2; i++) { 
        cout << p[i].processno << "\t"; 
        cout << p[i].AT << "\t"; 
        cout << p[i].BTbackup << "\t"; 
        cout << p[i].CT << "\t"; 
        cout << p[i].TAT << "\t"; 
        cout << p[i].WT << "\t"; 
        cout << endl; 
    } 
  
    cout << endl; 
    cout << "Total TAT = " << totalTAT << endl; 
    cout << "Average TAT = " << totalTAT / 4.0 << endl; 
    cout << "Total WT = " << totalWT << endl; 
    cout << "Average WT = " << totalWT / 4.0 << endl; 
    return 0; 
  
}

