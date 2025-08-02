#include <iostream>
#include <vector>
#include<map>
using namespace std;

class City{
    public:
        string name;float area;int pop;
        City(string n,float a,int p):name(n),area(a),pop(p){}
        friend ostream &operator <<(ostream &os,const City &p);
        ~City(){}
};

ostream &operator <<(ostream &os,const City &p){
    os<<p.name;
    return os;
}

// Function to add an edge between two vertices
void addEdge(vector<vector<int>>& adj, int i, int j){
   //write your code here
   adj[i].push_back(j);adj[j].push_back(i);
}

// Function to display the adjacency list
void displayAdjList(const vector<vector<int>>& adj,vector<City> n){
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
    vector<vector<int>> adj(6); 
    City p1("Hyderabad",55000.50,2000000),p2("Delhi",45000.56,3500000);
    City p3("Mumbai",50000.35,5000000),p4("Bangalore",60000.46,7500000);
    City p1("Hyderabad",55000.50,2000000),p2("Delhi",45000.56,3500000);
    City p3("Mumbai",50000.35,5000000),p4("Bangalore",60000.46,7500000);
    map<City*,int> m={{&p1,0},{&p2,1},{&p3,2},{&p4,3}};
    vector<City> n={p1,p2,p3,p4};
    addEdge(adj, m[&p1],m[&p2]);
    addEdge(adj, m[&p1],m[&p3]);
    addEdge(adj, m[&p1],m[&p4]);
    addEdge(adj, m[&p2],m[&p3]);
    addEdge(adj, m[&p3],m[&p4]);
    //addEdge(adj, 2, 3);

    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj,n);
    
    /*int V = 4;
    vector<vector<int>> adj(V); 
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj);
    
    int V = 4;
    vector<vector<int>> adj(V); 

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj);*/

    return 0;
}