#include "bits/stdc++.h"

using namespace std;


int main(){
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int N, M; //num_speedzones, num_journeyzones
    cin >> N >> M;
    vector<int> SZL; //speedzones length
    vector<int> SZM; //speedzones MPH
    vector<int> JZL; //journeyzones length
    vector<int> JZM; //journeyzones MPH
    int x; //placeholder for len zones
    int y; //placeholder for MPH of zones
   
    for (int i = 1; i <= N; i++){
        cin >> x;
        cin >> y;
        SZL.push_back(x);
        SZM.push_back(y);
    }

    for (int i = N ; i < N + M; i++){
        cin >> x;
        cin >> y;
        JZL.push_back(x);
        JZM.push_back(y);
    }

    SZL.pop_back();
    SZM.pop_back();
    JZL.pop_back();
    JZM.pop_back();

    int max_above = 0;
    int SZL_idx = 0;
    int JZL_idx = 0;

    int ST = 0; //speed_zones traveled
    int JT = 0; //journey_zones traveled

    while (ST < 100 && JT < 100){
        if (ST + SZL[SZL_idx] > JT + JZL[JZL_idx]){
            max_above = max(max_above, JZM[JZL_idx] - SZM[SZL_idx]);
            JT += JZL[JZL_idx];
            JZL_idx += 1;
        }
        else if (ST + SZL[SZL_idx] < JT + JZL[JZL_idx]){
            max_above = max(max_above, JZM[JZL_idx] - SZM[SZL_idx]);
            ST += SZL[SZL_idx];
            SZL_idx += 1;
        }
        else {
            max_above = max(max_above, JZM[JZL_idx] - SZM[SZL_idx]);
            JT += JZL[JZL_idx];
            ST += SZL[SZL_idx];
            JZL_idx += 1;
            SZL_idx += 1;
        }
    }
    cout << max_above;
    return 0;
}