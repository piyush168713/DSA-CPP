// Minimum Steps Required

// Link - https://practice.geeksforgeeks.org/problems/6a1b365b520f10c8a29b533eb72951b4b4237b57/1

int minSteps(string str) {
    // Write your code here.
    int a = 0;
    int b = 0;
    
    if(str[0] == 'a'){
        a++;
    }
    if(str[0] == 'b'){
        b++;
    }
    
    for(int i = 1; i < str.size(); i++){
        if(str[i-1] == 'a' && str[i] == 'b'){
            b++;
        }
        if(str[i-1] == 'b' && str[i] == 'a'){
            a++;
        }
    }
    
    return min(a,b)+1;
}
