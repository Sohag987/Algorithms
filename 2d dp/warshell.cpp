#include<iostream>
#include<vector>
#include<iomanip>
#include<climits>


using namespace std; 

int main(){
    int V;
    cout<<"Enter The number of vertices :"; 

    cin>>V;
    const int INF = 999999;  
    
    vector<vector<int>>dist(V,vector<int>(V,INF)); 
    
    cout<<"Enter the adjacency Matrix: \n";
    for(int i =0 ;i<V;i++){
        for(int j = 0; j<V;j++){
            cin>>dist[i][j]; 
        }
        cout<<endl; 

    }

    //Floyd warshell algorithm 
    for(int k =0 ; k<V;k++){
        for(int i = 0 ; i<V;i++){
            for(int j = 0 ;j<V;j++){
                if (dist[i][k] !=INF && dist[k][j]!=INF){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]); 
                }
            }
        }
    }

    // Checking for negative cycle .. if any diagonal element is negative then the grag has negative eweeighted cycle 

    bool isnegativecycle = false; 

    for(int i = 0 ; i<V;i++){
        if(dist[i][i] <0){
            isnegativecycle = true; 
            break;

        }


    }
    
    if(isnegativecycle){
        cout<<"\nThe Graph contains a negative weighted cycle\n";
    }else{ 

        cout<<"Shortest path matrix:\n\n ";
       
        for(int i =0 ;i<V;i++){
          for(int j = 0; j<V;j++){
            
              cout<<dist[i][j]<<"\t"; 
        }
        cout<<endl; 

    }



    }

    

  return 0 ; 

}
