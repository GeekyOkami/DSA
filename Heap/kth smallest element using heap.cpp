 int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;
        
        //step1 build pq for k elements
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        
        //step 2 if element less than heap top insert
        for(int i=k;i<=r;i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        //return ans
        int ans=pq.top();
        return ans;
    }