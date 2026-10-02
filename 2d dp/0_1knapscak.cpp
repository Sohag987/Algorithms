#include<iostream>
#include<vector> 
#include<algorithm> 


using namespace std; 

int main(){
    int n ,W ; 
    cout<<"Enter number of items : "; 
    cin>>n ; 
    vector<int>weight(n); 
    vector<int>profit(n);
    
    cout<<"Enter  weight and Profit for each item: \n"; 

    for(int i = 0;i<n;i++){
        cin>>weight[i]; 
        cin>>profit[i]; 
 
    }

    cout<<"Enter Kanpscak capacity: ";

    cin>>W; 

    // DP table
    
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));

    for(int i =1 ;i<=n;i++){
        for(int w =1;w<=W;w++){
            if(weight[i-1]>w)
            {
                dp[i][w] = dp[i-1][w]; 
            }
            else{
                dp[i][w] = max(dp[i-1][w],profit[i-1]+dp[i-1][w-weight[i-1]]) ;
            }
        }
    }


cout<<"\nMaximum Profit = "<< dp[n][W]<<endl;

cout<<"Selected Items: "<<endl; 
int w = W ; 

for(int i=n;i>=1;i--){
    if(dp[i][w]!=dp[i-1][w]){
        cout<<i<<"  "; 
        w  -= weight[i-1]; 
    }
}

cout<<endl; 




    return 0 ; 
}