#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<tuple>

using namespace std;

int MAX = 100001;

int main(){
    int N, K;
    cin >> N >> K;

    int dist[MAX];
    fill(dist, dist+MAX, INT32_MAX);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.emplace(0,N);
    dist[N] = 0;
    while(!q.empty()){
        pair<int,int> pop = q.top();
        q.pop();
        if(pop.second > 0 && dist[pop.second-1] == INT32_MAX){
            q.emplace(pop.first +1,pop.second-1);
            dist[pop.second- 1] = pop.first +1;
        }
        if(pop.second+1 <MAX && dist[pop.second+1] == INT32_MAX){
            q.emplace(pop.first +1,pop.second+1);
            dist[pop.second +1] = pop.first +1;

        }
        if(pop.second*2 < MAX && dist[pop.second*2] == INT32_MAX){
            q.emplace(pop.first +1,pop.second*2);
            dist[pop.second *2] = pop.first +1;
        }
    }
    cout << dist[K] << "\n";
    stack<int> s;
    s.push(K);
    while(s.size() < dist[K]+1){
        int h = s.top();
        if(h+1< MAX && dist[h+1]== dist[h] -1){
            s.push(h+1);
            continue;   
        }
        if(h-1>=0 && dist[h-1]== dist[h] -1){
            s.push(h-1);
            continue;   
        }
        if(h%2 ==0 && dist[h/2]== dist[h] -1){
            s.push(h/2);
            continue;   
        }
        cout << "not reached\n";
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
    return 0;
}