class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> lmaxh;
    priority_queue<int, vector<int>, greater<int>> rminh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int lsize = lmaxh.size();
        int rsize = rminh.size();
        int med = findMedian();
        
        if(lsize == rsize){
            if(num < med){
                lmaxh.push(num);
            }
            else
                rminh.push(num);
        }
        //lsize > rsize
        else if(lsize > rsize){
            if(num < med){
                rminh.push(lmaxh.top());
                lmaxh.pop();
                lmaxh.push(num);
            }
            else{
                rminh.push(num);
            }
        }
        //rsize > lsize
        else{
            if(num < med){
                lmaxh.push(num);
            }
            else{
                lmaxh.push(rminh.top());
                rminh.pop();
                rminh.push(num);
            }
        }
    }
    
    double findMedian() {
        int rsize = rminh.size();
        int lsize = lmaxh.size();
        if(lsize == 0 && rsize == 0)
            return 0;
        else if(lsize == rsize){
            return (double)(lmaxh.top()+rminh.top())/2;
        }
        else if(lsize > rsize)
            return lmaxh.top();
        else
            return rminh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */