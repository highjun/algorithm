#include<iostream>
#include<vector>

using namespace std;

//프렉탈
//이전 모양을 *라고 하면
// ***
// * *
// ***
vector<string> getFractal(int N){
    vector<string> result;
    if(N == 1){
        result.push_back("*");
    }else{
        vector<string> prev = getFractal(N/3);
        for(int i = 0 ; i< prev.size(); i++){
            result.push_back(prev[i] + prev[i] + prev[i]);
        }
        string space = "";
        for(int i = 0;i<N/3;i++) space += " ";
        for(int i = 0 ; i< prev.size(); i++){
            result.push_back(prev[i] + space + prev[i]);
        }
        for(int i = 0 ; i< prev.size(); i++){
            result.push_back(prev[i] + prev[i] + prev[i]);
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<string> out = getFractal(N);
    for(int i = 0; i<out.size();i++){
        cout << out[i] << "\n";
    }
    return 0;
}