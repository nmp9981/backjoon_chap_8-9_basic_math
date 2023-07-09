#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
const int inf = 1 << 30;
vector<pair<int,int>> pos;
set<pair<int, int>> s;//y좌표 기준

//두 점사이 거리
int Dist(pair<int, int> a, pair<int, int> b) {
    int distX = (a.first - b.first) * (a.first - b.first);
    int distY = (a.second - b.second) * (a.second - b.second);
    return distX + distY;
}

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int xi, yi;
        cin >> xi >> yi;
        pos.push_back({ xi,yi });
    }
    sort(pos.begin(), pos.end());//x좌표 순으로 정렬
    s.insert({ pos[0].second,pos[0].first });
    s.insert({ pos[1].second,pos[1].first });
}
//최소 거리 찾기
void MinDist() {
    int minDist = Dist(pos[0], pos[1]);
    int idx = 0;

    for (int i = 2; i < n; i++) {
        while (idx < i) {
            //x축거리가 기존 최소보다 크면 안된다.
            int xDist = pos[i].first - pos[idx].first;
            if (xDist * xDist <= minDist) break;
            else {
                s.erase({pos[idx].second,pos[idx].first});
                idx++;
            }
        }
        //후보군들중 가장 가까운 거리로 갱신
        auto st = s.lower_bound({ pos[i].second - sqrt(minDist),-inf});
        auto ed = s.lower_bound({ pos[i].second + sqrt(minDist), inf });
        for (auto k = st; k != ed; k++) minDist = min(minDist, Dist({ k->second,k->first }, pos[i]));

        s.insert({pos[i].second,pos[i].first});
    }
    cout << minDist;//출력
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    MinDist();//최소거리 찾기
    return 0;
}
