class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int sizeOfwords = words.size(), answer = 0;

        for(int i = 0; i < sizeOfwords; i++) {
            int sizeOfWordToCheck = words[i].size();
            for(int j = i + 1, k; j < sizeOfwords; j++) {
                int sizeOfCurrentWord = words[j].size();
                if(sizeOfWordToCheck > sizeOfCurrentWord) {
                    continue;
                }
                for(k = 0; k < sizeOfWordToCheck; k++) {
                    if(words[j][k] != words[i][k] || words[j][sizeOfCurrentWord - 1 - k] != words[i][sizeOfWordToCheck - 1 - k]) {
                        break;
                    }
                }
                if(k == sizeOfWordToCheck) {
                    answer++;
                }
            }
        }
        return answer;
    }
};