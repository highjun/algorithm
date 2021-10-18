#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> vec;
    int tmp;
    while(cin >> tmp){
        vec.push_back(tmp);
    }
    int idx = max_element(vec.begin(), vec.end())- vec.begin();
    cout<< vec[idx] <<"\n" << idx+1 <<"\n";
    return 0;
}