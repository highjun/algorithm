#include<iostream>

using namespace std;

//Group 단어를 찾기 위해서 각각의 단어에서 바로전 알파벳과
//이미 나온 알파벳을 저장해서 비교한다.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    int cnt = 0;
    while(T--){
        string x;
        cin >> x;
        int n_alphabet = 'z'-'a'+1;
        bool appear[n_alphabet];
        fill(appear, appear+n_alphabet, false);
        char prev;
        bool isGroup = true;
        for(int i = 0; i<x.size();i++){
            if(i == 0){
                appear[x[i]-'a'] = true;
                prev = x[i];
            }else{
                if(prev!=x[i]&& appear[x[i]-'a']){ 
                    isGroup = false;
                    break;
                }
                prev= x[i];
                appear[x[i]-'a'] = true;
            }
        }
        if(isGroup) cnt++;
    }
    cout << cnt <<"\n";
    return 0;
}