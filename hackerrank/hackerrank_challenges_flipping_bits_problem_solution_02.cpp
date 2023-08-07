#include "vector"
#include "iostream"
#include "cstdio"
#include "cmath"
#include <algorithm>

long flipBits(long num);

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int tc;
    long input;
    std::vector<long> numbers;

    scanf("%d", &tc);

    for (int i = 0; i < tc; i++) {
        scanf("%ld", &input);
        numbers.push_back(flipBits(input));
    }

    for (auto item: numbers) {
        std::cout << item << std::endl;
    }

    return 0;
}

long flipBits(long num) {
    std::vector<int> flippedBits;
    long flippedNumber = 0;

    while(num != 0) {
        flippedBits.push_back(num % 2);
        num = num / 2;
    }

    while(flippedBits.size() < 32) {
        flippedBits.push_back(0);
    }

    reverse(flippedBits.begin(), flippedBits.end());
    for(int & flippedBit : flippedBits) {
        flippedBit = flippedBit == 0 ? 1 : 0;
    }

    for(long i = 0; i < flippedBits.size(); i++) {
        flippedNumber = flippedNumber + (flippedBits[i] * (long) (pow(2, (32 - i - 1))));
    }

    return flippedNumber;
}
