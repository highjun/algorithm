#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>

using namespace std;

struct Point {
    int x,y;
};
vector<Point> points;
int N;
int MAX = 1000000000;
int cnt = 0;

bool compareX(Point point1, Point point2){
    return (point1.x< point2.x); 
}
bool compareY(Point point1, Point point2){
    return (point1.y< point2.y); 
}

int getDist(Point point1, Point point2){
    return pow(point1.x-point2.x,2)+ pow(point1.y-point2.y,2); 
}

int getMinDist(int left, int right){
    if(right==left) return MAX;
    int center = (left+right)/2;
    int x_div= points[center].x;
    int dist = min(getMinDist(left, center), getMinDist(center+1, right));

    int l= center, r = center+1;
    vector<Point> strip;
    strip.reserve(right-left);
    //O(n)
    while(l>= left && pow(points[l].x-x_div,2) < dist){
        strip.push_back(points[l]);
        --l;
    }
    //O(n)
    while(r<= right && pow(points[r].x- x_div,2) < dist){ 
        strip.push_back(points[r]);
        ++r;
    }
    //O(nlogn)
    sort(strip.begin(), strip.end(), compareY);
    //O(n)
    for(int i=0;i<strip.size();i ++){
        for(int j = i+1 ; j<strip.size();j++){
            if(pow(strip[j].y-strip[i].y,2) >= dist) break;
            cnt++;
            dist = min(dist, getDist(strip[j], strip[i]));
        }
    }
    return dist;
}

int main()
{
    int N;
    cin >> N;
    for(int i =0; i<N; i++){
        Point point;
        cin >> point.x;
        cin >> point.y;
        points.push_back(point);
    }
    sort(points.begin(), points.end(), compareX);
    // for(int i = 0; i<points.size();i++){
    //     cout << "("<< points[i][0] << ", " << points[i][1] << ") ";
    // }
    cout << getMinDist(0, N-1) << endl;
    // cout << cnt<< "\n";

	return 0;
}