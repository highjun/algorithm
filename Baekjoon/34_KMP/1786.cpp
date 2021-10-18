#include<iostream>
#include<vector>

using namespace std;

//ps: 첫 문자열 [0,i]에서 prefix == suffix인 최대 길이 
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string text;
    getline(cin, text);
    string pattern;
    getline(cin, pattern);
    int ps[pattern.size()];
    int prev = 0;
    ps[0] = 0;
    for(int i = 1; i< pattern.size(); i++){
        // cout << prev << ", " << i <<"\n";
        if(pattern[prev]== pattern[i]){
            prev++;
            ps[i] = prev;
            // cout << ps[i] << "\n";
        }else{
            if(prev > 0){
                prev = ps[prev-1];
                i--;
            }else{
                ps[i] = 0;
            }
        }
    }
    // cout << "\n";
    prev = 0;
    vector<int> result;
    for(int idx  = 0; idx < text.size();idx++){
        // cout << idx+1 << " " << prev << "\n";
        if(prev == pattern.size()){
            result.push_back(idx + 1 - prev);
            prev = ps[prev-1];
            idx--;
            continue;
        }
        if(pattern[prev] == text[idx]){
            prev++;
        }else{
            if(prev> 0){
                idx--;
                prev = ps[prev-1];
            }
        }
    }
    if(prev == pattern.size()){
        result.push_back(text.size() - prev+1);
    }
    cout << result.size() << "\n";
    for(int i = 0 ;i < result.size();i++){
        cout << result[i] << " ";
    }
    if(result.size() != 0) cout <<"\n";
    return 0;
}