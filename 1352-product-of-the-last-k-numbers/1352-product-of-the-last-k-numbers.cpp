class ProductOfNumbers {
public:
    vector<int> arr;
    int firstZero = -1;
    
    void add(int num) {
        if (arr.empty()) {
            if (num == 0) {
                firstZero = 0;
            }
            arr.push_back(num);
        }
        else if (num == 0) {
            arr.push_back(num);
            firstZero = arr.size() - 1;
        }
        else {
            if (arr.back() == 0) {
                arr.push_back(num);
            }
            else {
                arr.push_back(num * arr.back());
            }
        }
    }
    
    int getProduct(int k) {
        int n = arr.size();
        if (firstZero != -1) {
            if (n - k <= firstZero) {
                return 0;
            }
            else {
                if (arr[n - k - 1] == 0) {
                    return (arr.back());
                }
                else {
                    return (arr.back() / arr[n - k - 1]);
                }
            }
        }
        else {
            if (n - k == 0) {
                return arr.back();
            }
            else {
                return (arr.back() / arr[n - k - 1]);
            }
        }
    }
};