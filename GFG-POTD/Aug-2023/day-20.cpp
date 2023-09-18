// Number of occurrence

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int cnt = 0;
	    for(int i = 0; i < n; i++){
	        if(arr[i] == x){
	            cnt++;
	        }
	        else if(arr[i] < x){
	            continue;
	        }
	        else if(arr[i] > x){
	            break;
	        }
	    }
	    return cnt;
	}
};
