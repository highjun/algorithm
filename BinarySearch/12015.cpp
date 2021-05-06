#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// LIS가 될 수 있는 가능성이 있는 부분수열을 길이별로 저장한다.
// 그러나, 부분수열의 마지막 원소만이 중요하므로 마지막 원소만 저장해도 된다.
int main(){
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> lis;
    lis.push_back(0);
    for(int i =0 ;i<N;i++){
        int tmp;
        cin >> tmp;
        int idx = lower_bound(lis.begin(), lis.end(), tmp) -lis.begin();
        if(idx == lis.size()){
            lis.push_back(tmp);
        }else{
            lis[idx] = tmp;
        }
    }
    cout << lis.size()-1 << "\n";
    return 0;
}