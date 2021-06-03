#include<iostream>
#include<vector>

using namespace std;

bool isValid(int x[][9], vector<pair<int,int>>* vec, int idx){
    pair<int,int> loc = (*vec)[idx];
    int tmp[9];
    fill(tmp, tmp+9,0);
    for(int  i = 0; i<9;i++){
        if(x[i][loc.second]!=0){
            tmp[x[i][loc.second]-1]++;
        }
    }
    for(int i=0;i<9;i++){
        if(tmp[i] > 1) return false;
    }
    fill(tmp, tmp+9,0);
    for(int  i = 0; i<9;i++){
        if(x[loc.first][i]!=0){
            tmp[x[loc.first][i]-1]++;
        }
    }
    for(int i=0;i<9;i++){
        if(tmp[i] > 1) return false;
    }
    fill(tmp, tmp+9,0);
    int r = loc.first/3, c= loc.second/3;
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(x[3*r+i][3*c+j]!=0)
                tmp[x[3*r+i][3*c+j]-1]++;
        }
    }
    for(int i=0;i<9;i++){
        if(tmp[i] > 1) return false;
    }
    return true;
}

int backtracking(int x[][9], vector<pair<int,int>>* vec, int N, int idx){
    // cout << idx << ": ";
    // for(int i = 0; i<idx;i++){
    //     cout << x[(*vec)[i].first][(*vec)[i].second] << " ";
    // }
    // cout <<"\n";
    if(idx == N){
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                cout << x[i][j] << " ";
            }
            cout << "\n";
        }
        return 1;
    }
    int cnt = 0;
    for(int i = 1; i<10;i++){
        x[(*vec)[idx].first][(*vec)[idx].second] = i;
        if(isValid(x,vec, idx)){
            if(backtracking(x,vec, N,idx+1) == 1){
                return 1;
            }
        }
        x[(*vec)[idx].first][(*vec)[idx].second] = 0;
    }
    return 0;
}
//DFS를 이용한 BackTracking
int main(){
    int x[9][9];
    vector<pair<int,int>> vec;
    for(int i = 0;i<9;i++){
        for(int j = 0; j<9;j++){
            cin >> x[i][j];
            if(x[i][j] == 0){
                vec.emplace_back(i,j);
            }
        }
    }
    int N = vec.size();
    backtracking(x, &vec, N, 0);
    return 0;
}