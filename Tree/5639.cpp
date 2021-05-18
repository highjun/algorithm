#include<iostream>
#include<vector>

using namespace std;

void recursive(vector<int>* result, vector<int>* pre,int start, int end){
    if(end <= start) return;
    int node_ = (*pre)[start];
    if(start +1 == end||(*pre)[end-1] < node_ || (*pre)[start+1] > node_){
        recursive(result, pre, start+1, end);
        result->push_back(node_);
        return;
    }
    int ss = start+1, ee = end;
    while(ee-ss > 1){//주어진 값 이상인 가장 작은 idx를 찾는다.
        int tmp = (ee+ss)/2;
        if(node_ >= (*pre)[tmp-1]){//[(ee+ss)/2, ee)
            ss = tmp;
        }else{// [ss, (ee+ss)/2)에 들어가는 경우
            ee = tmp;
        }
    }
    int idx = (node_ < (*pre)[ss])? ss : ss+1;
    // cout << node_ <<", " <<start <<", " << end << "\n";
    // cout << idx << ":" << (*pre)[idx] <<"\n";
    recursive(result, pre, start+1, idx);
    recursive(result, pre, idx, end);
    result->push_back(node_);
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector<int> pre;
    int tmp;
    while(cin >>tmp){
        pre.push_back(tmp);
    }
    vector<int> result;
    recursive(&result, &pre, 0, pre.size());
    for(int i = 0;i<pre.size();i++){
        cout << result[i] << "\n";
    }

    return 0;
}