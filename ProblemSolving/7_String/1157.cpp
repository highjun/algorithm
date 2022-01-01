#include<iostream>

using namespace std;

//문자열을 입력받아 각각의 문자를 counting
//대소문자 구분이 없으므로 대문자인지 아닌지를 판단하여
//counting한다.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string x;
    cin >> x;
    int n_alphabet = 'z'-'a'+1;
    int cnt[n_alphabet];
    fill(cnt, cnt+n_alphabet, 0);
    for(int i = 0;i<x.size();i++){
        if(x[i]>= 'A' && x[i]<='Z'){
            cnt[x[i]-'A']++;
        }else if(x[i]>='a'&& x[i]<='z'){
            cnt[x[i]-'a']++;
        }
    }
    //n_max를 통해서 max가 몇 번 나오는지 Counting
    int max_ = -1, n_max = 0;
    int max_idx = 0;
    for(int i = 0;i<n_alphabet;i++){
        if(max_ < cnt[i]){
            max_ = cnt[i];
            max_idx = i;
            n_max = 1;
        }else if(max_ == cnt[i]){
            n_max++;
        } 
    }
    cout << (n_max>1? '?': (char) (max_idx + 'A')) <<"\n";
    return 0;
}