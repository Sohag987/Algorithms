

#include<bits/stdc++.h>

using namespace std ; 

struct Node{
    char ch;
    int freq; 
    Node *left , *right;

    Node(char c , int f ){
        ch = c ; 
        freq= f; 
        left = right = nullptr; 
    }
}; 


   

struct Compare{

    bool operator()(Node *a, Node *b){
        return a->freq>b->freq ; 
    }

};  



void generateCodes(Node* root,string code,unordered_map<char,string>& huffmanCode){

    if(root==nullptr){ 
        return ; 
    }

        

    if(root->left == nullptr && root->right == nullptr){
        huffmanCode[root->ch] = code;
    } 

     

    generateCodes(root->left,code+'0',huffmanCode); 
    generateCodes(root->right,code+'1',huffmanCode); 

 }




string decode(Node *root,string encoded){ 
    string result; 
    Node *current = root ; 


    for(char bit: encoded){
        
        if(bit=='0'){
            current= current->left;
        }
        else{
            current = current->right; 
        }

       

        if(current->left==nullptr && current->right == nullptr){
            result += current->ch; 
            current = root ; 
        } 
    }

    return result; 



}

int main(){

     
    string msg ;
    cout<<"Enter your message"<<endl; 

    getline(cin,msg); 
    
   
    unordered_map<char,int>frequency; 

    for(char ch: msg){
        frequency[ch]++; 

    }

    priority_queue<Node*,vector<Node*>,Compare>min_heap; 

    for (auto& pair:frequency){
        min_heap.push(new Node(pair.first,pair.second)); 
    }

    // Frequency building associated with chharacter is done ... it is time to build the huuffman tree #pragma endregion

    while(min_heap.size()>1){
        Node* left = min_heap.top(); 
        min_heap.pop();
        
        Node* right = min_heap.top();
        min_heap.pop(); 

        Node* parent = new Node('\0',left->freq+right->freq); 

        parent->left = left ; 
        parent->right = right; 

        min_heap.push(parent);
    }

    Node *root = min_heap.top() ; 

    // Generating huffman coding 
    unordered_map<char,string>huffman_code; 

    generateCodes(root,"",huffman_code); 


    cout<<"Original Message:"<<msg<<endl;

    cout<<"\nHuffman code:\n";

    for(const auto& pair:huffman_code){
        if(pair.first == ' '){
            cout<<"[space]"; 
        }
        else{
            cout<<pair.first<<" ->"<<pair.second<<endl; 
        }
    }
     

    // encoded msg 
    string encodedmsg = "" ;
    
    for (char ch :msg){
        encodedmsg += huffman_code[ch]; 

    }

    cout<<"Encoded Msg"<<encodedmsg<<endl; 
    string decoded  = decode(root,encodedmsg); 
    cout<<"Decoded msg : "<<decoded<<endl; 


    return 0 ; 
}


