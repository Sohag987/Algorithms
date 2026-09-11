#include <iostream>
#include <vector>

using namespace std;

class DisjointSetUnion
{
public:
    int n;
    vector<int> parent, rank;

    DisjointSetUnion(int n)
    {
        this->n = n;

        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    void union_by_rank(int a, int b)
    {
        int parent_a = find(a); 
        int parent_b = find(b); 

        if (parent_a ==parent_b){
            return ; 
        }

        if(rank[parent_a] == rank[parent_b]){
            parent[parent_b] = parent_a;
            rank[parent_a]++;  

        }

        else if(rank[parent_a]>rank[parent_b]){
            parent[parent_b] = parent_a; 
            // rank[parent_a]++;

        }
        else{
            parent[parent_b] = parent_a; 
        }
    };

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }

        return parent[x]=find(parent[x]); // saving value for path compression 
    }; 

};

// this the whole code for Disjoint Set Union data structure .. 