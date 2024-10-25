// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast", "inline", "ffast-math", "unroll-loops", "no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")
// static const auto DPSolver = [](){ 
//     std::ios_base::sync_with_stdio(false); 
//     std::cin.tie(nullptr); 
//     std::cout.tie(nullptr); 
//     return 'c'; 
// }();

// class Solution {
// public:
//     static vector<string> removeSubfolders(vector<string>& vec) {
//         sort(vec.begin(),vec.end());
//         int n=vec.size();string pre=vec[0];
//         vector<string> res={vec[0]};
//         for(int i=1;i<n;i++){
//             string str=vec[i];
//             if(str.find(pre+'/')!=0){
//                 res.push_back(str);
//                 pre=str;
//             }
//         }
//         return res;
//     }
// };

class Solution {
private:
    struct TrieNode {
        bool isEndOfFolder;
        unordered_map<string, TrieNode*> children;
        TrieNode() : isEndOfFolder(false) {}
    };

    TrieNode* root;
    void deleteTrie(TrieNode* node) {
        if (node == nullptr) return;
        for (auto& pair : node->children) {
            deleteTrie(pair.second);
        }
        delete node;
    }

public:
    Solution() : root(new TrieNode()) {}
    ~Solution() { deleteTrie(root); }

    vector<string> removeSubfolders(vector<string>& folder) {
        for (string& path : folder) {
            TrieNode* currentNode = root;
            istringstream iss(path);
            string folderName;

            while (getline(iss, folderName, '/')) {
                if (folderName.empty()) continue;
                if (currentNode->children.find(folderName) ==
                    currentNode->children.end()) {
                    currentNode->children[folderName] = new TrieNode();
                }
                currentNode = currentNode->children[folderName];
            }
            currentNode->isEndOfFolder = true;
        }
        vector<string> result;
        for (string& path : folder) {
            TrieNode* currentNode = root;
            istringstream iss(path);
            string folderName;
            bool isSubFolder = false;

            while (getline(iss, folderName, '/')) {
                if (folderName.empty()) continue;
                TrieNode* nextNode = currentNode->children[folderName];
                if (nextNode->isEndOfFolder && iss.rdbuf()->in_avail() != 0) {
                    isSubFolder = true;
                    break;
                }
                currentNode = nextNode;
            }
            if (!isSubFolder) result.push_back(path);
        }

        return result;
    }
};