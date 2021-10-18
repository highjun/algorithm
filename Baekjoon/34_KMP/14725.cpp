#include<iostream>
#include<map>

using namespace std;

struct Trie{
    map<string, Trie> children;
};

void dfs(Trie &root, int depth){
    for(auto node: root.children){
        for(int i = 0; i < depth;i++) cout << "--";
        cout << node.first << "\n";
        dfs(node.second, depth+1); 
    }
}

//Trie 구조를 통해서 계층화시킨다.
//이후 DFS를 통해서 안에 있는 것들을 출력한다.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    Trie root;
    for(int i = 0;i<N;i++){
        int M;
        cin >> M;
        Trie* pre= &root;
        for(int j = 0;j<M;j++){
            string tmp; cin >> tmp;
            if(!pre->children.count(tmp)) pre->children[tmp] = Trie();
            pre = &(pre->children[tmp]);
        }
    }
    dfs(root, 0);
    return 0;
}