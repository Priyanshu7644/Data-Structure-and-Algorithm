class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        // Use long long for values to prevent overflow during summation
        vector<long long> values(nums.begin(), nums.end());
        
        // Doubly linked list simulation
        vector<int> prev(n), next(n);
        iota(prev.begin(), prev.end(), -1); // -1, 0, 1, ...
        iota(next.begin(), next.end(), 1);  // 1, 2, 3, ...

        // Min-heap to store pairs: {sum, index}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        int badPairs = 0; 

        // Initialize structures
        for (int i = 0; i < n - 1; ++i) {
            pq.push({values[i] + values[i + 1], i});
            if (values[i] > values[i + 1]) {
                badPairs++;
            }
        }

        int ops = 0;
        
        while (badPairs > 0) {
            auto [sum, i] = pq.top();
            pq.pop();

            int j = next[i];

            // FIX: Check if j is -1 (which implies i was removed)
            if (j == -1 || j == n || values[i] + values[j] != sum) {
                continue;
            }

            ops++;

            // 1. Remove bad pair contribution between i and j
            if (values[i] > values[j]) badPairs--;
            
            // 2. Remove bad pair contribution between prev[i] and i
            int p = prev[i];
            if (p != -1 && values[p] > values[i]) badPairs--;

            // 3. Remove bad pair contribution between j and next[j]
            int k = next[j];
            if (k != n && values[j] > values[k]) badPairs--;

            // MERGE: Merge j into i
            values[i] += values[j]; 
            
            // Update pointers to remove j
            next[i] = k;
            if (k != n) prev[k] = i;
            
            // Mark j as removed
            next[j] = -1; 

            // Update inversion count after merge
            if (p != -1 && values[p] > values[i]) badPairs++;
            if (k != n && values[i] > values[k]) badPairs++;

            // Push new potential pairs
            if (p != -1) pq.push({values[p] + values[i], p});
            if (k != n) pq.push({values[i] + values[k], i});
        }

        return ops;
    }
};