#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

struct Int2{
    int idx;
    int priority;
};

bool compare(Int2 x, Int2 y){
    return (x.priority > y.priority) || (x.priority == y.priority && x.idx> y.idx);
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i< N;i++){
        queue<Int2> q;
        vector<int> v;
        int n_doc, idx;
        cin >> n_doc >> idx;
        for(int j = 0; j< n_doc;j++){
            Int2 tmp;
            tmp.idx = j;
            cin >> tmp.priority;
            q.push(tmp);
            v.push_back(tmp.priority);
        }
        sort(v.begin(), v.end(), greater<int>());
        int cnt = 1;
        for(int j = 0; j< n_doc; j++){
           while(v[j] > q.front().priority){
               Int2 tmp = q.front();
               q.pop();
               q.push(tmp);
           }
           Int2 tmp = q.front();
           if(tmp.idx ==idx){
               cout << cnt << "\n";
               break;
           }
           cnt+=1;
           q.pop();
        }
    }
    return 0;
}