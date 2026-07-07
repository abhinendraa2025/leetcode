class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        
        int total = 10;       // count for n=1 (0 through 9)
        int uniqueDigits = 9; // choices for the 2nd digit onward
        int available = 9;    // remaining digit choices (starts at 9 for 1st digit)
        
        for (int k = 2; k <= n && k <= 10; ++k) {
            uniqueDigits *= available;
            total += uniqueDigits;
            available--;
        }
        
        return total;
    }
};