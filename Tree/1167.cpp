#include<iostream>
#include<vector>
#include<assert.h>
#include<tuple>
#include<stack>
using namespace std;

//dfs지만 지름을 return하도록 한다.
//start를 루트로 하여 아래의 child에 대한 지름을 반환한다.
//이 때, pop에 해당 노드쪽으로의 가장 긴 거리를 저장한다.
int dfs(vector<pair<int,int>>* adj, bool *visit, int* pop, int start, int w){
    visit[start] = true;
    int max_ = 0;
    int first_dist = 0;
    int second_dist = 0;
    for(int i = 0; i<adj[start].size();i++){
        int dest,weight;
        tie(dest, weight)  =adj[start][i];
        if(!visit[dest]){
            int tmp = dfs(adj, visit, pop, dest, weight);
            max_ = max(tmp,  max_);
            if(pop[dest] > first_dist){
                second_dist = first_dist;
                first_dist = pop[dest];
            }else if(pop[dest]> second_dist){
                second_dist = pop[dest];
            }
        }
    }
    pop[start] = first_dist+w;
    max_ = max(first_dist+ second_dist , max_);
    return max_;
}


int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int V;
    cin >> V;
    vector<pair<int,int>> adj[V];
    for(int i = 0; i< V;i++){
        int src;
        cin >> src;
        int dest,weight;
        cin >> dest;
        while(dest!=-1){
            cin >>weight;
            adj[src-1].emplace_back(dest-1, weight);
            cin >> dest;
        }
    }
    bool visit[V];
    fill(visit, visit+V, false);
    int pop[V];//가장 긴 거리를 저장
    fill(pop, pop+V, 0);
    int max_= dfs(adj, visit, pop, 0,0);
    cout << max_ << "\n";

    return 0;
}