#include <bits/stdc++.h> 

void minHeapify(vector<int> &myHeap,int i){
    int left=2*i+1;
    int right=2*i+2;
    int smallest=i;
    if(myHeap[left]<myHeap[i] && left<myHeap.size()){
        smallest=left;
    }
    if(myHeap[right]<myHeap[i]  && right<myHeap.size()){
        smallest=right;
    }
    
    if(smallest!=i){
        swap(myHeap[smallest],myHeap[i]);
        minHeapify(myHeap,smallest);
    }
    else{
        return;
    }
}

void insert(vector<int> &myHeap,int x){
    myHeap.push_back(x);
    int index=myHeap.size()-1;
    int parent=(index-1)/2;
    while(myHeap[parent]>myHeap[index]){
        minHeapify(myHeap,parent);
        index=parent;
        parent=(parent-1)/2;
    }
}

int remove(vector<int> &myHeap){
    int ans=myHeap[0];
    swap(myHeap[0],myHeap[myHeap.size()-1]);
    myHeap.pop_back();
    minHeapify(myHeap,0);
    return ans;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> ans;
    vector<int> myHeap;
    for(int i=0;i<q.size();i++){
        if(q[i][0]==0){
            insert(myHeap,q[i][1]);
        }
        else{
            ans.push_back(remove(myHeap));
        }
    }

    return ans;
}
