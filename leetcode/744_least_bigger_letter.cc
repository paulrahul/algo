class Solution {
public:
    
    char findNext(vector<char>& letters, int idx, char target) {
        char ch = letters[idx];
        int n = letters.size();
        for (int i = idx + 1; i < n; i++) {
            if (letters[i] != ch) {
                return letters[i];
            }
        }
        
        return letters[0];
    }
    
    char binSearch(vector<char>& letters, int start, int end, char target) {
        if (start >= end) {
            char ch = letters[start];
            if (ch > target) {
                return ch;
            }
            
            return findNext(letters, start, target);
        }
        
        int mid = (start + end) / 2;
        
        if (letters[mid] > target) {
            return binSearch(letters, start, mid - 1, target);
        } else {
            return binSearch(letters, mid + 1, end, target);
        }
    }
    
    
    char nextGreatestLetter(vector<char>& letters, char target) {
        return binSearch(letters, 0, letters.size() - 1, target);
    }
};