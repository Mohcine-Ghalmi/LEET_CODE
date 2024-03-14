class Solution {
public:
    void bubbleSort(std::vector<int>& vec, std::vector<int>& vec2) {
        int n = vec.size();
        bool swapped;
        do {
            swapped = false;
            for (int i = 1; i < n; ++i) {
                if (vec[i - 1] > vec[i]) {
                    std::swap(vec[i - 1], vec[i]);
                    std::swap(vec2[i - 1], vec2[i]);
                    swapped = true;
                }
            }
            n--;
        } while (swapped);
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> vectRowsCount;
         for (int i = 0; i < mat.size(); ++i) {
            std::vector<int> innerVec = mat[i];
            int count = 0;
            for (int j = 0; j < innerVec.size(); ++j)
                if (innerVec[j] == 1)
                    count++;
            vectRowsCount.push_back(count);
        }
        vector<int> lastVect;
        for (vector<int>::iterator it = vectRowsCount.begin(); it < vectRowsCount.end(); it++)
            lastVect.push_back(*it);
        vector<int> vectIndex;
        for (size_t i = 0; i < lastVect.size(); ++i)
            vectIndex.push_back(i);
        bubbleSort(lastVect, vectIndex);
        vector<int> vectToReturn;
        for (vector<int>::iterator it = vectIndex.begin(); it < vectIndex.end(); it++) {
            if (*it == k) {
                vectToReturn.push_back(*it);
                break;
            }
            vectToReturn.push_back(*it);
        }
        return (vectToReturn);
    }
};
