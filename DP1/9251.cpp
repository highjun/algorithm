#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//쌓을 수 있는 개수
int cache[1001][1001];


int main(){
    string A,B;
    cin >>A >>B;
    // cout <<A <<endl << B;

    for(int i=0;i<A.size(); i++){
        for(int j = 0; j<B.size(); j++){
            if(A.at(i) == B.at(j)){
                cache[i+1][j+1] = cache[i][j]+1;
            }else{
                cache[i+1][j+1] = max(cache[i][j+1], cache[i+1][j]);
            }
        }
    }
    
    cout << cache[A.size()][B.size()] <<endl;
    return 0;
}