// Problem Statement

// Longest-Common-Prefix - CodeStudio

// Link - https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383


    // using Trie
    // T.C - O(M*N)
    // S.C - O(M*N)
    

    class TrieNode{
        public:
        char data;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;
        
        TrieNode(char ch){
            data = ch;
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            childCount = 0;
            isTerminal = false;
        }
    };
    
    class Trie{
      public:
        TrieNode* root;
        Trie(char ch){
            root = new TrieNode(ch);
        }
        
        void insertUtil(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        // assumption, words will be in CAPS
        int index = word[0] - 'a';
        TrieNode* child;

        // Present 
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else {
            // absent
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }
        
    void lcp(string str, string &ans){
        for(int i = 0; i < str.length(); i++){
            char ch = str[i];
            if(root->childCount == 1){
                ans.push_back(ch);
                // move forward to check more
                int index = ch - 'a';
                root = root->children[index];
            } else{
                break;
            }
            if(root->isTerminal)
                break;
        }
    }
};
    
string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* t = new Trie('\0');
    for(int i = 0; i < n; i++){
        t->insertWord(arr[i]);
    }
    
    string first = arr[0];
    string ans = "";
    
    t->lcp(first, ans);
    return ans;    
}
