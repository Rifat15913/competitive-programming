#include "vector"
#include "iostream"
#include "cstdio"

using namespace std;

int calculateProfit(vector<int> &prices);

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int tc;
    int input;
    vector<int> numbers;

    scanf("%d", &tc);

    for (int i = 0; i < tc; i++) {
        scanf("%d", &input);
        numbers.push_back(input);
    }

    calculateProfit(numbers);

    return 0;
}

int calculateProfit(vector<int> &prices) {
    int finalBuyingIndex = -1, finalSellingIndex = -1, finalProfit = 0;
    int tempBuyingIndex = -1, tempSellingIndex = -1, tempProfit = 0;

    for (int i = 0; i < prices.size(); i++) {
        int currentPrice = prices[i];

        // Handle buying
        if (tempBuyingIndex == -1) {
            tempBuyingIndex = i;
        } else if (currentPrice < prices[tempBuyingIndex]) {
            tempBuyingIndex = i;
            tempSellingIndex = -1;
            tempProfit = 0;
        }

        // Handle selling
        if (tempSellingIndex == -1) {
            if(currentPrice > prices[tempBuyingIndex] && i > tempBuyingIndex) {
                tempSellingIndex = i;
                tempProfit = prices[tempSellingIndex] - prices[tempBuyingIndex];

                if(tempProfit > finalProfit) {
                    finalBuyingIndex = tempBuyingIndex;
                    finalSellingIndex = tempSellingIndex;
                    finalProfit = tempProfit;
                }
            }
        } else if (currentPrice > prices[tempSellingIndex]) {
            tempSellingIndex = i;
            tempProfit = prices[tempSellingIndex] - prices[tempBuyingIndex];

            if(tempProfit > finalProfit) {
                finalBuyingIndex = tempBuyingIndex;
                finalSellingIndex = tempSellingIndex;
                finalProfit = tempProfit;
            }
        }
    }

    return finalProfit;
}
