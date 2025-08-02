#include <iostream>
#include <vector>
#include<map>
using namespace std;

// Function to add an edge between two vertices
void addEdge(vector<vector<int>>& adj, int i, int j){
   //write your code here
   adj[i].push_back(j);adj[j].push_back(i);
}

// Function to display the adjacency list
void displayAdjList(const vector<vector<int>>& adj,vector<string> n){
    //write your code here
    for(int i=0;i<adj.size();i++){
        cout<<n[i]<<": ";
        for(int j=0;j<adj[i].size();j++){
            cout<<n[adj[i][j]]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> adj(3); 
    map<string,int> m={{"Hardik",0},{"Rohit",1},{"Surya",2}};
    vector<string> n={"Hardik","Rohit","Surya"};
    addEdge(adj, m["Hardik"],m["Rohit"]);
    addEdge(adj, m["Hardik"],m["Surya"]);
    addEdge(adj, m["Rohit"],m["Surya"]);

    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj,n);
    return 0;
}