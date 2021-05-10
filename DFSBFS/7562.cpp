#include<iostream>
#include<memory.h>
#include<queue>

using namespace std;

int check[300][300];
int l;

struct compare{
    bool operator()(int a, int b){
        int a1 = a/l,a2 = a%l;
        int b1 = b/l,b2 = b%l;

        return check[a1][a2] > check[b1][b2];
    }
};

bool isNotVisit(int x, int y){
    return x>=0 && x<l && y<l && y>=0 && check[x][y] == -1;
}

priority_queue<int, vector<int> ,compare> bfs;

void pushNotVisit(int x, int y, int tmp){
    if(isNotVisit(x,y)){
        check[x][y] = tmp+1;
        bfs.push(x*l+y);
    }
}

int main(){
    int n_case;
    cin >> n_case;
    for(int i=0;i<n_case; i++){
        // cout << "start" <<"\n";
        cin >> l;
        int start_x, start_y;
        cin >> start_x >> start_y;
        int end_x, end_y;
        cin >> end_x >> end_y;
        memset(check,  -1, 300*300*sizeof(int));
        while(!bfs.empty()){
            bfs.pop();
        }
        // cout << start_x*l + start_y <<"\n";
        bfs.push(start_x * l + start_y);
        check[start_x][start_y] = 0;
        while(!bfs.empty()){
            int node = bfs.top();
            bfs.pop();
            int x= node/l, y= node%l;
            int tmp = check[x][y];
            pushNotVisit(x+2, y+1,tmp);
            pushNotVisit(x-2, y+1,tmp);
            pushNotVisit(x+2, y-1, tmp);
            pushNotVisit(x-2, y-1, tmp);
            pushNotVisit(x+1, y+2, tmp);
            pushNotVisit(x-1, y+2, tmp);
            pushNotVisit(x+1, y-2, tmp);
            pushNotVisit(x-1, y-2, tmp);
        }
        cout << check[end_x][end_y] <<"\n";
    }
    return 0;
}