class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t start1 = 0, end1 = version1.find('.'), start2 = 0,
               end2 = version2.find('.');
        bool version1End = false, version2End = false;
        while (!version1End || !version2End) {
            int revision1 = 0;
            int revision2 = 0;
            if (!version1End) {
                revision1 = stoi(version1.substr(start1, end1 - start1));
            }
            if (!version2End) {
                revision2 = stoi(version2.substr(start2, end2 - start2));
            }
            if (revision1 < revision2) {
                return -1;
            } else if (revision1 > revision2) {
                return 1;
            }
            if (end1 == string::npos) {
                version1End = true;
            }
            if (end2 == string::npos) {
                version2End = true;
            }
            start1 = end1 + 1;
            start2 = end2 + 1;
            end1 = version1.find('.', start1);
            end2 = version2.find('.', start2);
        }

        return 0;
    }
};