#include<iostream>
#include<vector>

using namespace std;

//src dest이 바뀌면서 재귀가 성립한다.
//위의 N-1개 원판을 1->2, 그리고 N을 1->3, 그리고 다시 N-1개 원판을 2->3이다.
vector<pair<int,int>> getHanoi(int N, int src, int  dest, int middle){
    vector<pair<int,int>> result;
    if(N == 1) result.emplace_back(src, dest);
    else{
        auto prev = getHanoi(N-1, src, middle, dest);
        result.insert(result.end(), prev.begin(), prev.end());
        result.emplace_back(src, dest);
        prev = getHanoi(N-1, middle, dest, src);
        result.insert(result.end(), prev.begin(), prev.end());
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    auto out= getHanoi(N, 1, 3, 2);
    cout << out.size() << "\n";
    for(int i = 0; i< out.size();i++){
        cout << out[i].first << " " << out[i].second << "\n";
    }
    return 0;
}