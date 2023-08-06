class Solution{
    private:
    void heapify(vector<int> &arr,int size,int index){
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;
        if(left<size && arr[left]>arr[largest]){
            largest=left;
        }
        if(right<size && arr[right]>arr[largest]){
            largest=right;
        }
        if(largest!=index){
            swap(arr[largest],arr[index]);
            heapify(arr,size,largest);
        }
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        for(auto i:a){
            ans.push_back(i);
        }
        for(auto j:b){
            ans.push_back(j);
        }
        
        //build heap
        int size=ans.size();
        for(int i=size/2-1;i>=0;i--){
            heapify(ans,size,i);
        }
        
        return ans;
    }
};