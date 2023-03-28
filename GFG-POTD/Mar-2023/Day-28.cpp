// Shy Geek

// Link - https://practice.geeksforgeeks.org/problems/59dfb26eb6c659e6e5f60869ac335f450f97165a/1

/*
Instructions - 

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in increasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/
class Solution{
    public:
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k){
        // Return the number of chocolates Geek had
        // enjoyed out of 'n' chocolates availabe in the
        // 'shop'.
        long long ans = 0, l = 0, r = n-1;
        while(r >= 0 && k > 0){
            l = 0;
            int index = -1, index_val;
            while(l <= r){
                long long mid = (l+r)/2;
                long long mid_price = shop.get(mid);
                if(mid_price <= k){
                    index = mid;
                    index_val = mid_price;
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            ans += k/index_val;
            k = k%index_val;
            r = index-1;
        }
        return ans;
    }
};
