class Solution {
public:
    long long countCommas(long long n) {
        long long start = 1000;
        int commas = 1;
        long long count = 0;

        while(start <= n){
            long long end = start * 1000 - 1;
            count += (min(n, end) - start + 1) * commas;

            start *= 1000;
            commas += 1;
        }

        return count;
    }
};