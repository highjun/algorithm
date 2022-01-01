#include<iostream>
#include<iomanip>
#include<memory.h>

using namespace std;

struct Trie{
    Trie* children[27];
    int n_children = 0;
    // map<char, Trie> children;
    int pass = 0; 
    Trie(): n_children(0), pass(0){
        memset(children, 0, sizeof(children));
    }
};

int dfs(Trie* root){
    int cnt = 0;
    if(root->n_children > 1) cnt+= root->pass;
    // if(root.children.size() > 1) cnt+= root.pass;
    for(auto node: root->children){
        if(node!= NULL)
            cnt+= dfs(node);
    }
    delete root;
    return cnt;
}

//Trie에 각 Node를 지나치는 단어의 개수를 센 후, DFS를 통해서 
//분기점이 되는 경우 지나치는 단어의 개수를 더한다.
//new는 동적할당으로 delete로 지워주기는 해야함
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cout << fixed << setprecision(2);
    int T;
    while(cin >> T){
        Trie* root = new Trie();
        int n_word = T;
        while(T--){
            string tmp; cin >> tmp;
            Trie* pre= root;
            for(int j = 0;j<tmp.size();j++){
                int idx = tmp[j] - 'a';
                if(pre->children[idx] == NULL){
                    pre->children[idx] = new Trie();
                    pre->n_children++;
                }
                pre->pass++;
                pre = pre->children[idx];
            }
            if(pre->children[26]==NULL){
                pre->n_children++;
            }
        }
        int cnt = 0;
        if(root->n_children==1) cnt+= n_word;
        cnt += dfs(root);
        double result = ((double)cnt) / n_word; 
        cout << result << "\n";
    }
    return 0;
}