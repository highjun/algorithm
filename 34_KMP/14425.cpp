#include<iostream>
#include<map>

using namespace std;

struct Trie{
    map<char, Trie> children;
};

//Trie 구조를 통해서 계층화시킨다.
//이후 insert와 거의 같은 방식으로 String의 존재 여부를 판단한다.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,M;
    cin >> N >> M;
    Trie root;
    for(int i = 0;i<N;i++){
        Trie* pre= &root;
        string tmp; cin >> tmp;
        for(int j = 0;j<tmp.size();j++){
            if(!pre->children.count(tmp[j])) pre->children[tmp[j]] = Trie();
            pre = &(pre->children[tmp[j]]);
        }
        if(!pre->children.count('\n')) pre->children['\n'] = Trie();
    }
    int cnt = 0;
    for(int i = 0;i<M;i++){
        Trie* pre = &root;
        string tmp; cin >> tmp;
        int j;
        for(j = 0; j<tmp.size();j++){
            if(!pre->children.count(tmp[j])) break;
            pre = &(pre->children[tmp[j]]);
        }
        if(j == tmp.size()){
            if(!pre->children.count('\n')) j--;
        }
        if(j == tmp.size()){
            cnt++;
        }
    }
    cout << cnt <<"\n";
    return 0;
}