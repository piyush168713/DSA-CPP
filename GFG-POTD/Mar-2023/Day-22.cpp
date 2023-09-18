// String rp or pr

// Link - https://practice.geeksforgeeks.org/problems/d25f415de2ff3e02134de03e17ad019d723ab2e9/1

class Solution{   
public:
    long long evaluate(char ch1,char ch2,string &s,int X,int Y){
        stack<char>st;
        long long ans = 0;
        //First we use stack to eliminate all the occurrence of ch1 ch2
        for(int i = 0;i<s.size();i++){
            if(st.size() && st.top()==ch1 && s[i]==ch2){
                st.pop();
                ans += X;
            }
            else
            st.push(s[i]);
        }
        //Than for the remaining characters, we need to check for the occurrence of ch2 ch1
        if(st.size()<2) return ans;
        s = "";
        while(st.size()){
            s.push_back(st.top());
            st.pop();
        }
        for(auto it = s.rbegin();it!=s.rend();it++){
            if(st.size() && st.top()==ch2 && *it==ch1){
                ans += Y;
                st.pop();
            }
            else
            st.push(*it);
        }
        return ans;
    }

    long long solve(int X,int Y,string S){
      //code here
      bool greater = X>Y;
      return evaluate(greater?'p':'r',greater?'r':'p',S,
                    greater?X:Y,greater?Y:X);
    }
};
