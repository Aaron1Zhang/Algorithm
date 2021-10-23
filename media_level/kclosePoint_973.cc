class Solution {
public:
    //构建一个大堆
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [this] (vector<int>& p1, vector<int>& p2) {
            return calcDistance(p1) < calcDistance(p2);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pqueue(comp);
        for (int i = 0; i < points.size(); ++i) {
            pqueue.push(points[i]);
            if (pqueue.size() > k) {
                pqueue.pop();
            }
            
        }
        vector<vector<int>> res;
        while (!pqueue.empty()) {
            res.push_back(pqueue.top());
            pqueue.pop();
        }
        return res;

    }
    int calcDistance(vector<int>& point) {
        return pow(point[0], 2) + pow(point[1], 2);
    }

    //方法二，快速选择
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        quick_select(points, 0, points.size() - 1, k);
        res.insert(res.end(), points.begin(), points.begin() + k);
        return res;
    }
    //返回第K小的数
    void quick_select(vector<vector<int>>& vec, int start, int end, int k) {
        if (start == end) return ;

        int mid = start + (end - start) / 2;
        auto pivot = calcDistance(vec[mid]);
        int i = start;
        int j = end;
        while (i <= j) {
            while (i <= j && calcDistance(vec[i]) < pivot) {
                ++i;
            }
            while (i <= j && calcDistance(vec[j]) > pivot) {
                --j;
            }
            if (i <= j) {
                std::swap(vec[i], vec[j]);
                ++i;
                --j;
            }
        }
        if (k - 1 + start < j) {
            return quick_select(vec, start, j, k);

        } else if (k - 1 + start >= i) {
            return quick_select(vec, i, end, k - (i - start));
        } 
        return;
    }
};