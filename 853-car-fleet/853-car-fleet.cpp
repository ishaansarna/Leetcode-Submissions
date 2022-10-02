class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back(make_pair(position.at(i), speed.at(i)));
        }
        sort(cars.begin(), cars.end());
        vector<float> time(n);
        int fleets = 0;
        for (int i = n-1; i >= 0; i--) {
            time.at(i) = (float)(target - cars.at(i).first) / (float)cars.at(i).second;
            fleets++;
            if (i < n-1 && time.at(i) <= time.at(i+1)){
                time.at(i) = time.at(i+1);
                fleets--;
            }
        }
        return fleets;
    }
};