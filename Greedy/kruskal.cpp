#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 


struct edge{
    int u;
    int v ; 
    int weight;
}; 

bool compare(edge a ,edge b){
    return a.weight<b.weight; 

}; 

class DSU{
    private: 
    vector<int>parent; 
    vector<int>rank; 

    public: 
    DSU(int n){
        parent.resize(n); 
        rank.resize(n,0); 

        // initially every vertex it it's own parent .. 
        for(int i = 0 ; i<n;i++){
            parent[i] = i ; 

        }; 
        // Find representative of a set 
        

    }

    int find(int x){
            if(parent[x]==x){
                return x ;
            }

        return  parent[x] = find(parent[x]); 
               
            
            
        }; 
};

