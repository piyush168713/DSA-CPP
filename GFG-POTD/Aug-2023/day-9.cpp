// Largest prime factor

class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        long long int max = 0;
        for(int i = 2; i <= sqrt(N); i++){
            while(N%i == 0){
                N /= i;
                max = i;
            }
        }
        if(N != 1){
            max = N;
        }
        return max;
    }
};
