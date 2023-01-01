class Solution {
    bool CANBUY, BOUGHT;
    int dp(vector<int>& prices, int i, bool state, map<pair<int, bool>, int>& cache) {
        if (i >= prices.size()) return 0;
        if (cache.find({i, state}) != cache.end())
            return cache[{i, state}];
        int rest = dp(prices, i+1, state, cache);
        if (state == CANBUY) {
            int buy = dp(prices, i+1, BOUGHT, cache) - prices[i];
            cache[{i, state}] = max(buy, rest);
        }
        else {
            int sell = dp(prices, i+2, CANBUY, cache) + prices[i];
            cache[{i, state}] = max(sell, rest);
        }
        return cache[{i, state}];
    }
public:
    int maxProfit(vector<int>& prices) {
        map<pair<int, bool>, int> cache;
        CANBUY = false;
        BOUGHT = true;
        return dp(prices, 0, CANBUY, cache);
    }
};