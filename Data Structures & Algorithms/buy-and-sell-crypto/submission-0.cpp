class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> minUpTo(prices.size());
        vector<int> maxAfter(prices.size());

        minUpTo[0] = prices[0];
        for (int i = 1; i < prices.size(); i++){
            minUpTo[i] = minUpTo[i-1];
            if (prices[i] < minUpTo[i-1]){
            minUpTo[i] = prices[i];
            }
        }
        maxAfter[prices.size() - 1] = prices[prices.size() - 1];
        for (int i = prices.size()-2; i > -1; i--){
            maxAfter[i] = maxAfter[i+1];
            if (prices[i] > maxAfter[i+1]){
            maxAfter[i] = prices[i];
            }
        }

        int maxDifference = maxAfter[0] - minUpTo[0];
        int difference;
        for (int i = 0; i < prices.size(); i++){
            difference = maxAfter[i] - minUpTo[i];
            if (difference > maxDifference){
            maxDifference = difference;
            }
        }
        return maxDifference;
            
    }
};
