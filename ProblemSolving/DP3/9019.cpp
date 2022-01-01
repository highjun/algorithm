#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<tuple>

using namespace std;


int main(){
    int MAX = 10000;
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n_case;
    cin >> n_case;
    while(n_case--){
        int src, dest;
        cin >> src >> dest;
        bool visited[MAX];
        fill(visited, visited+MAX, false);
        queue<tuple<int,string>> q;
        visited[src] = true;
        q.emplace(src, "");
        while(!q.empty()){
            int distance, node;
            string cur;
            tie(node, cur) = q.front();
            q.pop();
            if(node == dest){
                cout << cur << "\n";
                break;
            }
            //D
            int D = (node * 2)%MAX;
            if(!visited[D]){
                visited[D] = true;
                q.emplace(D, cur + "D");
            }
            //S
            int S = (node + 9999)%MAX;
            if(!visited[S]){
                visited[S] = true;
                q.emplace( S,cur+"S");
            }
            //L
            int L = (node*10 + (node/1000))%MAX;
            if(!visited[L]){
                visited[L] = true;
                q.emplace( L, cur+"L");
            }
            //R
            int R = ((node/10) +  1000*(node%10))%MAX;
            if(!visited[R]){
                visited[R] = true;
                q.emplace( R, cur+"R");
            }
        }
    }
    return 0;
}