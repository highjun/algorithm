#include<iostream>
#include<vector>

using namespace std;


//재귀적으로 in은 L NODE R , post는 LR NODE임을 이용
void recursive(vector<int>* result,
    int* in, int in_start, int in_end, 
    int*post, int post_start, int post_end){
        if(post_start == post_end) return;
        int root = post[post_end-1];
        result->push_back(post[post_end-1]);
        int idx = in_start;
        while(idx < in_end){
            if(in[idx] == root){
                break;
            }
            idx++;
        }
        idx-= in_start;
        recursive(result,
            in, in_start, in_start+idx,
            post, post_start, post_start+idx);
        recursive(result,
            in, in_start+idx+1, in_end,
            post, post_start+idx, post_end-1);
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int V;
    cin >> V;
    int in[V];
    int post[V];
    for(int i =0; i<V;i++){
        cin >> in[i];
    }
    for(int i =0; i<V;i++){
        cin >> post[i];
    }
    vector<int> result;
    recursive(&result, in, 0, V,post, 0, V);
    for(int i = 0; i<result.size();i++){
        cout << result[i] << " ";
    }
    cout <<"\n";
    return 0; 
}