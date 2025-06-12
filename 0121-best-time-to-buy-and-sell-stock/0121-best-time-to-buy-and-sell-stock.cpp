class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], maxi = 0;
        for(int i=0; i<prices.size(); i++) {
            mini = min(mini, prices[i]);
            maxi = max(maxi, prices[i] - mini);
        }
        return maxi;
    }
};




// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int maxi = 0;
//         for(int i=0; i<prices.size()-1; i++) {
//             for(int j=i+1; j<prices.size(); j++) {
//                 if(prices[j] > prices[i])
//                     maxi = max(maxi, prices[j] - prices[i]);
//             }
//         }
//         return maxi;
//     }
// };