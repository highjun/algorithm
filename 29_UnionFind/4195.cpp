#include<iostream>
#include<vector>
#include<map>

using namespace std;

//find root
int find(int x, vector<int>* parent){
    if((*parent)[x] == x){
        return x;
    }else{
        //path compression
        //root로 가는 길에 있는 노드를 root의 child로 올려버린다.
        (*parent)[x] = find((*parent)[x], parent);
        return (*parent)[x];
    }
}
int union_(int x, int y, vector<int>* parent, vector<int>* rank, vector<int>* n_node){
    x = find(x, parent);
    y = find(y, parent);
    if(x == y) return (*n_node)[x];
    // union-by-rank 알고리즘
    // rank는 root Node에서만 업데이트된다. 
    if((*rank)[x] < (*rank)[y]){
        (*parent)[x] = y;
        (*n_node)[y] += (*n_node)[x];
        return (*n_node)[y];
    }else{
        (*parent)[y] = x;
        (*n_node)[x] += (*n_node)[y];
        if((*rank)[x] == (*rank)[y]){
            (*rank)[x]++;
        }
        return (*n_node)[x];
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int n_case;
    cin >> n_case;
    while(n_case--){
        int F;
        cin >> F;
        map<string, int> m;
        //(parent, rank, n_node) 저장
        //rank, n_node의 경우, 루트 노드만 올바르게 저장됨
        vector<int> parent;
        vector<int> rank;
        vector<int> n_node;
        while(F--){
            string u,v;
            cin >> u >> v;
            if(m.find(u) == m.end()){
                m.insert(make_pair(u,parent.size()));
                parent.push_back(parent.size());
                rank.push_back(0);
                n_node.push_back(1);
            }
            if(m.find(v) == m.end()){
                m.insert(make_pair(v,parent.size()));
                parent.push_back(parent.size());
                rank.push_back(0);
                n_node.push_back(1);
            }
            cout << union_(m[u], m[v], &parent, &rank, &n_node) <<"\n";
            // for(int i = 0;i<parent.size() ; i++){
            //     cout << parent[i] << " ";
            // }
            // cout <<"\n";
        }        
    }
    return 0;
}