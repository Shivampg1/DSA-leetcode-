class StockSpanner {
public:
stack<pair<int,int>>st;
int i=0;
    StockSpanner() {
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int prev;
        if(st.empty()){
           prev=-1;
        }
        else{
            prev=st.top().second;
        }
        int spn=i-prev;

        st.push({price,i});
        i++;
        return spn;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */