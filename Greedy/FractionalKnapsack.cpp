#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Item{
    int id ; 
    double profit; 
    double weight; 
    double ratio; 
}; 

bool compare(Item a , Item b){
    return a.ratio>b.ratio ; 
}

int main(void){
    int n ; 
    double capacity; 
    cout<<"Enter number of items :" <<endl; 
    cin >>n; 
    cout<<"Enter Capacity:"<<endl; 
    cin>>capacity;

    vector<Item> items(n); 

    // Taking profit and weight  as input 
    cout<<"Enter Profits:\n";
    for(int i = 0;i<n;i++){
        cin>>items[i].profit;
        items[i].id = i+1 ;  
    }

    cout<<"Enter Weight:\n"; 
    for(int i=0;i<n;i++){
        cin>>items[i].weight; 
    }

    // calculating weight Profit ratio #pragma endregion
    for(int i =0 ;i<n;i++){
        items[i].ratio = items[i].profit/items[i].weight; 
    }

    // Sort by ratio 
    sort(items.begin(),items.end(),compare); // Sorted 

    // Selection for profit maximization 
    vector<double>selected(n,0);
    double maxProfit = 0 ; 

    for(const auto& item:items){
        if (capacity==0) return 0  ; 

        if(item.weight<capacity){
            maxProfit += item.profit;
            capacity -=item.weight; 
            
            selected[item.id-1] = 1;


        }

        else if (capacity==0 && item.weight>capacity){
             double fraction = capacity/item.weight; 

             maxProfit+= item.profit*fraction; 
             selected[item.id-1] = fraction; 
             capacity = 0 ; // For terminating the loop 
        }
    }


 cout<<"\nMaximum Profit = :"<<maxProfit<<endl; 
 cout<<"Selected Item:\n"; 
 for( int i = 0 ;i<n;i++){
    if(selected[i]>0){
        cout<<"Item "<<i+1<<"-> "<<selected[i]*100<<" % selected\n";

    }
 }
 return 0 ; 
}