#include<iostream>
#include<vector>
#include<stack>
#include<tuple>

using namespace std;

//first는 index, second는 value
struct compare{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};

// 증가하는 부분수열의 각 길이 중 마지막 값이 제일 작은 경우의 값과 그 위치를 저장한다. 
// stack에 값들을 
int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> vec;
    stack<pair<int,int>> s;
    vec.push_back(0);
    for(int i = 0; i<N;i++){
        int arr;
        cin >> arr;
        //arr 이하인 값 중 가장 큰 값을 바꿔치기한다.
        int idx = lower_bound(vec.begin(), vec.end(), arr) - vec.begin();
        // cout << idx <<" ";
        if(idx == vec.size()){
            vec.push_back(arr);
            // cout << "1\n";
            s.emplace(idx,arr);
        }else{
            vec[idx] = arr;
            s.emplace(idx, arr);
        }
    }
    int len = vec.size()-1;
    vec.clear();
    while(!s.empty()){
        pair<int, int> pop = s.top();
        s.pop();
        if(pop.first == len){
            len--;
            vec.push_back(pop.second);
        }
    }
    cout << vec.size() << "\n";
    for(int i = vec.size()-1; i>=0 ; i--){
        cout << vec[i] << " ";
    }
    cout << "\n";
    return 0;
}