/*
Huffman coding is a technique for loss less data compression  

the core idea : 
=> to assign variable length code to input character. 
=> length of teh code is base on the frequencies of the characters 
=> The grredy(optimization) idea is that assign the less length code to the to the most freequent charater  

=> The variable length code is assigned to the characters is called prefic codes .. 
=>means the codes are assigned sucah a way that the code assigned to one character is not the prefix of code 
assigned to any other character. 

So , No ambiguity when  decoding the generated bitstream.  
*/

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


// min-heap comparator    

struct Compare{

    bool operator()(Node *a, Node *b){
        return a->freq>b->freq ; 
    }

};  

// generate huffman code -> 
// This function is for generating huffman code for every character of the message as key-value pair  

void generateCodes(Node* root,string code,unordered_map<char,string>& huffmanCode){

    if(root==nullptr){  // if the huffman man tree is empty .. just return  
        return ; 
    }

    // if there is no left and right node then just set the consisted code  as the value of 
    // the character key -> it is teh base case  for the recursive call    

    if(root->left == nullptr && root->right == nullptr){
        huffmanCode[root->ch] = code;
    } 

    //  recursive calls 

    generateCodes(root->left,code+'0',huffmanCode); 
    generateCodes(root->right,code+'1',huffmanCode); 

 }


//String decode-> compressed to original one  

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

        // if  there is no left or right node for the current node then it is a leaf node and .... this node 
        // char is a  letter for the meessage #pragma endregion

        if(current->left==nullptr && current->right == nullptr){
            result += current->ch; 
            current = root ; 
        } 
    }

    return result; 



}

int main(){

    // At first  i need to build a huffman tree 
    // -> taking input  for string --> using get line 
    string msg ;
    cout<<"Enter your message"<<endl; 

    getline(cin,msg); 
    
    // creating a for calculating frequency
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


