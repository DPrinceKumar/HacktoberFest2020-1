 #include <bits/stdc++.h>
using namespace std;
 

class Trie {
public:
     
    class node{
     public:   bool end;
       unordered_map<char, node*> mp;
    };
    
    node* trie;
    Trie(){
        trie = new node();
    }
    
     
    void insert(string word) {
        
        int i=0;
        node* it = trie;
        
        while(i<word.size()){
            if(it->mp[word[i]-'a']==NULL){
                it->mp[word[i]-'a'] = new node();
            }
            it = it->mp[word[i]-'a'];
            i++;
        }
        it->end = true;
    }
    
     
    bool search(string word) {
         
        node*it = trie;
        for(auto x: word){
            if(it->mp[x-'a']==NULL) return false;
            it=it->mp[x-'a'];
        }
        return it->end;
         
    }
    
    
    bool startsWith(string prefix) {
      
        node* it=trie;
        for(char c:prefix){
            c-='a';
            if(it->mp[c]==NULL) return false;
            it=it->mp[c];
        }
        return true;
    }
};

// Driver
int main()
{
 
 Trie* obj = new Trie();
 
int n;
cout<< "Number of Words to be Inserted"<<endl;
cin>>n;
 
for (int i = 0; i < n; i++)

    { cout<<"Enter the Word: ";
      string keys;
      cin>>keys;
	    obj->insert(keys);
      cout<<keys<<" is inserted in the Trie"<<endl;
}

int x;
cout<<endl;
cout<< "Number of Words to be Searched"<<endl;
cin>>x;

 for (int i = 0; i < x; i++)

 {
   string word;
  cout<<"Enter Word to be searched: "<<endl;
  cin>>word; 
   bool search = obj->search(word);
  if(search) cout<< word<<" is present"<<endl;
  else cout<< word<<" is not present"<<endl;
  
  cout<<endl;
 }

int p;
cout<<endl;
cout<< "Number of prefixes to be Searched"<<endl;
cin>>p;


 for (int i = 0; i < p; i++)

 {
  string pre;
  cout<<"Enter Prefix: "<<endl;
  cin>>pre; 
  bool prefix = obj->startsWith(pre);
  if(prefix) cout<< "Word with prefix : "<<pre<<" is present"<<endl;
  else cout<<"Word with prefix : "<<pre<<" is not present"<<endl;
  cout<<endl;
 }
  
	return 0;
}
