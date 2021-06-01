#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//vector로 받아서 sort후 더한 후 10씩 곱함
int main(){
    int N;
    cin >> N;
    vector<int> v;
    while(N!= 0){
        v.push_back(N%10);
        N /= 10;
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0;i<v.size();i++){
        N += v[i];
        if(i != v.size()-1) N *= 10;
    }
    cout << N <<"\n";
    return 0;
}