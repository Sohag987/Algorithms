#include<iostream>
#include<vector>
#include<climits>


using namespace std; 

struct Edge{
    int source; 
    int destination; 
    int weight; 
};

int main(){
    int V ,E ; 

    cout<<"Enter the number of vertices: "; 
    cin>>V; 

    cout<<"Enter the numner of edges: ";
    cin>>E; 

    // a vrctor for storing all edges 

    vector<Edge>edges(E); 

    cout<<"Enter Source, destination and weight of each edge :  \n"; 

    for(int i=0;i<E;i++){
        cin>>edges[i].source
           >>edges[i].destination 
           >>edges[i].weight; 


    }
    
    int source ; 
    cout<<"\nEnter Source Vertex: "; 
    cin>>source; 

    vector<int>distances(V,INT_MAX); 

    distances[source] = 0 ; 

    // starting the bellmanford algorithm 

    for(int i =1 ;i<=V-1;i++){
        for(const Edge &edge:edges){
            if(distances[edge.source]!=INT_MAX){
                int newdistance = distances[edge.source] + edge.weight; 

                if (newdistance < distances[edge.destination]){
                     distances[edge.destination] = newdistance;
                }
            }
        }
    }

    // checking for negative cycle 

    bool negativecycle = false; 

    for(const Edge &edge:edges){
        if(distances[edge.source]!=INT_MAX && 
           distances[edge.source]+edge.weight<distances[edge.destination]){
            negativecycle = true; 
            break ; 
           }

    }


    //output section
    if(negativecycle){
        cout<<"\nGraph has a negative cycle\n";

    }

    else{
        cout<<"Shortest distance from vertex "<<source<<endl; 
        cout<<"Vertex\tDistance\n";

        for(int i =0 ;i<V;i++){
            cout<<i<<"\t"; 

            if (distances[i] == INT_MAX){
                cout<<"Infinite"<<endl;

            }
            else{
                cout<<distances[i]<<endl; 
            }
        }
    }


  return 0 ; 
    

}