#include<iostream> 
#include<vector>
#include<algorithm> 


using namespace std ; 

int main(){
    string X ,Y ; 

    cout<<"Enter First string: "; 
    cin>>X; 
    cout<<"Enter Second String "; 
    cin>>Y; 

    int m = X.length(); 
    int n = Y.length(); 

    vector<vector<int>>dp(m+1,vector<int>(n+1,0)); 

    for(int i =1 ;i<m+1;i++){
        for( int j = 1 ;j<n+1;j++){
            if(X[i-1] == Y[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1 ; 

            }
            else{ 
                dp[i][j] = max (dp[i-1][j], dp[i][j-1]); 

            }

        }
    }
    cout<<"LCS length:"<<dp[m][n]<<endl;
    
    // Printing one lcs 
    string lcs = ""; 
    int i = m ; 
    int j = n ; 
    while(i>0 && j>0){
        if(X[i-1] == Y[j-1]){
            lcs += X[i-1]; 

            i--; 
            j--; 
        }

        else if (dp[i-1][j]>dp[i][j-1]){
            i--; 
        }
        else{
            j--;
        }
    }

    reverse(lcs.begin(),lcs.end());
    cout<<"One LCS "<<lcs<<endl; 
    return 0; 

}
