#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>



int ZeroSum(int arr[],int size){
    unordered_map<int,int>mp;
    int sum=0;

    for(int i=0;i<size;i++){
        if(mp[arr[i]]==0){
            sum=sum+arr[i];
            mp[arr[i]]++;
        }
    }
    return sum;
    
}



string FirstOcc(string str){
    unordered_map<char,int>mp;
    string ans;
    for(int i=0;i< str.length();i++){
        char ch= str[i];
        if(mp[ch]==0){
            ans=ans+ch;
            mp[ch]++;
        }
        

    }
    return ans;

}






int zeroSumOnce(vector<int> arr) {
    unordered_map<int, int> freq;

    
    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i];
        freq[num]++;
    }

    int count = 0;

    
    for (int i = 0; i < arr.size(); i++) {
        int num = arr[i];

 
       
        if (num == 0) {
            
            if (freq[0] >= 2) {
                count++;
                freq[0] -= 2; 
            }
        } else if (freq[num] > 0 && freq[-num] > 0) {
           
            count++;
            freq[num]--;    
            freq[-num]--;  
        }
    }

    return count;
}

int zeroSumReuse(vector<int> arr) {
    unordered_map<int,int> freq;
    for(int i=0;i<arr.size();i++) {
        int x=arr[i];
        freq[x]++;
    
    
    }

    int count = 0;
    for(int i=0;i<arr.size();i++) {
        
        int x=arr[i];

        if(x == 0) {
            
            count += freq[0] * (freq[0] - 1) / 2;
            freq[0] = 0; 
        }
        else if(freq[x] > 0 && freq[-x] > 0) {
            count += freq[x] * freq[-x];
            freq[x] = 0;
            freq[-x] = 0;
        }
    }
    return count;
}




int main(){
//  int arr[]={1};

// int size=1;


// string str="abracadabra";

// cout<<ZeroSum(arr,size)<<endl;
// cout<<FirstOcc(str)<<endl;


vector<int> arr = {1, 10, 8, -2, 2, 5, 7, 2, -2, -1};
cout<<zeroSumReuse(arr)<<endl;



}