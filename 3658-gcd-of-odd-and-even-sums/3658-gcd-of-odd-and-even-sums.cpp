class Solution {
public:
    int gcdOfOddEvenSums(int n) {

        
        int EvenSum = n*(n+1);

        int OddSum = n*n;

        return gcd(EvenSum,OddSum);
    }
};