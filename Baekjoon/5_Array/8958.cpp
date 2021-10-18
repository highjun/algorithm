#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        int cnt = 0;
        int score = 0;
        for(int i= 0 ;i<s.length();i++){
            if(s[i]=='O'){
                score++;
                cnt += score;
            }else{
                score = 0;
            }
        }
        cout << cnt <<"\n";
    }
    return 0;
}