#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//만약 2개로 나누지 않는다면 최대 2^30 *8 = 8GB ...
vector<long long> comb1;//최대 2^15* 8 = 2^18 = 256KB
vector<long long> comb2;

void getComb(int select, int start, int end, long long curr_comb_w, long long*  weight, long long C){
    if(start > end){
        if(select == 1) comb1.push_back(curr_comb_w);
        else comb2.push_back(curr_comb_w);
        return;
    } 
    if(curr_comb_w + weight[start] <= C){
        // cout << start << " " << end << "\n";
        getComb(select, start+1, end, curr_comb_w+ weight[start],weight, C);   
    }
    getComb(select, start+1, end, curr_comb_w, weight, C);
}

int main(){
    int N;
    long long C;
    cin >> N >> C;
    long long weight[N];
    for(int  i = 0; i<N;i++) cin >> weight[i];
    getComb(1, 0, N/2, 0, weight, C);//0에서 N/2
    getComb(2, N/2+1, N-1, 0, weight, C);
    sort(comb1.begin(),comb1.end());
    sort(comb2.begin(),comb2.end());
    int start = 0, end = comb2.size()-1;
    int cnt = 0;
    while(start != comb1.size()){
        if(comb1[start] + comb2[end] > C){
            end--;
        }else{
            cnt += end+1;
            start++;
        }
    }
    cout << cnt << "\n";
    return 0;
}