#include<iostream>
using namespace std;
#define MAX 20
int main(){
    int n, start;
    int adj[MAX][MAX];
    int visited[MAX];
    int q[MAX];
    int front=-1, rear=-1;

    cout<<"Enter no of nodes : ";
    cin>>n;

    cout<<"Enter adjacency matrix :  ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }

    cout<<"Enter starting node : ";
    char s;
    cin>>s;
    start=s-'A';

    for(int i=0;i<n;i++)
        visited[i]=0;

    if(front==-1)
        front=0;
    q[++rear]=start;
    visited[start]=1;

    cout<<"BFS Traversal : ";

    while(front!=-1 && front<=rear){
        int node=q[front++];
        if(front>rear)
            front=rear=-1;

        cout<<char(node+'A')<<" ";

        for(int j=0;j<n;j++){
            if(adj[node][j]==1 && !visited[j]){
                if(front==-1)
                    front=0;
                q[++rear]=j;
                visited[j]=1;
            }
        }
    }

    return 0;
}