#include<iostream>
#include<assert.h>
#include<vector>
#include<queue>

using namespace std;

struct node{
    int idx;
    vector<int> adj;
    node* parent;
};

bool compare(node a, node b){
    return a.idx < b.idx;
}

int main(){
    int N;
    cin >> N;
    node x[N];
    for(int i = 0;i<N;i++){
        x[i].idx = i;
        x[i].parent = NULL;
    }
    x[0].parent = x;
    int tmp = N-1;
    while(tmp--){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        x[u].adj.push_back(v);
        x[v].adj.push_back(u);
    }
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int idx = q.front();
        q.pop();
        vector<int>* v = &(x[idx].adj);
        for(int j = 0;j<(*v).size(); j++){
            if(x[(*v)[j]].parent == NULL){
                x[(*v)[j]].parent = &x[idx];
                q.push((*v)[j]);
            }
        }
    }

    for(int i =1;i<N;i++){
        cout << x[i].parent->idx +1 << "\n";
    }
    return 0;
}