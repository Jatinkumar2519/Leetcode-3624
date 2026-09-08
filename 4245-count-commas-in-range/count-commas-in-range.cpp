class Solution {
public:
    int countCommas(int n) {
        long long start = 1000;
        int commas = 1;
        long long count = 0;

        while(start <= n){
            long long end = start * 1000 - 1;
            count += (min((long long)n, end) - start + 1) * commas;

            start *= 1000;
            commas++;
        }

        return count;
    }
};