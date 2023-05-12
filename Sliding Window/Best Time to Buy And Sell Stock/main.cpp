class Solution {
public:
int maxProfit(vector<int>& prices) {
int minPrice = INT_MAX; // initialize minimum price to maximum possible value
int maxProfit = 0;

    for (int price : prices) {
        if (price < minPrice) {
            minPrice = price; // update minimum price if current price is lower
        } else if (price - minPrice > maxProfit) {
            maxProfit = price - minPrice; // update maximum profit if current profit is higher
        }
    }
    
    return maxProfit;
}
};
