#include<iostream>
#include<vector>

using namespace std;

//전위 순회
void frontDFS(vector<int>* result, int adj[][2], int root){
    result->push_back(root);
    for(int i = 0; i<2;i++){
        if(adj[root][i]!=-1)
            frontDFS(result, adj, adj[root][i]);
    }
}
//중위 순회
void centerDFS(vector<int>* result,int adj[][2], int root){
    if(adj[root][0]!=-1)
        centerDFS(result, adj, adj[root][0]);    
    result->push_back(root);
    if(adj[root][1]!=-1)
        centerDFS(result, adj, adj[root][1]);
}
//후위 순회
void backDFS(vector<int>* result, int adj[][2], int root){
    for(int i = 0; i<2;i++){
        if(adj[root][i]!=-1)
            backDFS(result, adj, adj[root][i]);
    }
    result->push_back(root);
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin >> N;
    int adj[N][2];
    for(int i = 0; i<N; i++){
        char x,y,z;
        cin >> x>> y>> z;
        adj[x-'A'][0] = y == '.'? -1: y-'A';
        adj[x-'A'][1] = z == '.'? -1: z-'A';
    }
    vector<int> result;
    frontDFS(&result, adj, 0);
    for(int i = 0;i<result.size();i++){
        cout<< (char)(result[i]+'A');
    }
    cout<< "\n";
    result.clear();
    centerDFS(&result, adj, 0);
    for(int i = 0;i<result.size();i++){
        cout<< (char) (result[i]+'A');
    }
    cout<< "\n";
    result.clear();
    backDFS(&result, adj, 0);
    for(int i = 0;i<result.size();i++){
        cout<< (char) (result[i]+'A');
    }
    cout<< "\n";
    return 0; 
}