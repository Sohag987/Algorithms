#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 

struct Job{
    int id;
    int deadline; 
    int profit; 
}; 

// for soring job according to the Profit 
bool compare(Job a , Job b){
    return a.profit>b.profit ; 
}


int main(){

    int n ;
    cout<<"Enter  the numbers of jobs:\n";
    cin>>n; 

    // creating a vector as the size of number of jobs 
    vector<Job>jobs(n);

    cout<<"Enter the Profit of the job:"<<endl; 
    for(int i =0 ; i<n;i++){
        cin>>jobs[i].profit;
        jobs[i].id = i+1; 

    }

    cout<<"Enter the Deadline of jobs:\n"; 
    for(int i=0;i<n;i++){
        cin>>jobs[i].deadline; 

    }

    // the algorithm is greedy to profit 
    // need to sort according to profit 
    sort(jobs.begin(),jobs.end(),compare); 

    // m -> for number of slots 

    int m ; 
    cout<<"Enter the Nuber of slot:"<<endl;
    cin>>m ; 

    vector<int>slecetedJobs(m,-1);

    int totalProfit = 0 ; 
    
    // process Strat --> 
    for(const auto& job:jobs){
         
        for(int t = job.deadline-1;t>=0;t--){
            if(slecetedJobs[t]==-1){
                slecetedJobs[t] = job.id;
                totalProfit += job.profit; 
                break ; 

            }

        }
    }

    cout<<"Selected Jobs:\n";
    
    for(int id:slecetedJobs){
        cout<<"Job -> "<<id<<" "<<endl;
         

    }
    cout<<"\n Maximum Profit: "<<totalProfit<<endl; 
    cout<<"Final Schedule: "<<endl ;
    cout<<"Slot -> JOB\n";
    for(int i=0;i<m;i++){
        cout<<i+1<< " -->"<<slecetedJobs[i]<<endl;
    }


    return 0 ; 




}