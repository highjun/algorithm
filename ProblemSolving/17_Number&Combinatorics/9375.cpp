#include<iostream>
#include<vector>

using namespace std;

//각 의상의 종류에 대해서 몇번씩 나오는지 카운팅 후 곱한다.
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<pair<string, int>> vec;
        for(int i = 0;i<N;i++){
            string name, kind;
            cin >> name >> kind;
            bool exist = false;
            for(int j = 0; j< vec.size();j++){
                if(vec[j].first == kind){
                    exist = true;
                    vec[j].second += 1;
                }
            }
            if(!exist){
                vec.emplace_back(kind, 1);
            }
        }
        int cnt = 1;
        for(int i = 0; i<vec.size();i++){
            cnt *= (vec[i].second+1);
        }
        cout << cnt-1 <<"\n";
    }
    return 0;
}