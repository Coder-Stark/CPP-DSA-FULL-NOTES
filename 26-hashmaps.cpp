//HASHMAPS

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    //creation of unordered map               {T.C = O(1)}
    unordered_map<string,int>m;

    //creation of ordered map                 {T.C = O(LOGN)}
    // map<string,int>m;

    //insertion 1
    pair<string,int>p = make_pair("shivam",3);
    m.insert(p);

    //insertion 2
    pair<string,int>p2("kumar",2);
    m.insert(p2);

    //insertion 3
    m["Rajbhar"] = 1;


    //Replace insertion with updation    
    m["Rajbhar"] = 2;


    //Search
    cout<<m["Rajbhar"]<<endl;

    cout<<m.at("kumar")<<endl;

    //error
    // cout<<m.at("unknownkey")<<endl;


    //no error create entry with value 0
    cout<<m["unknown"]<<endl;


    //now its fine
    cout<<m["unknown"]<<endl;

    cout<<m.size()<<endl;

    //to chech present
    cout<<m.count("bro")<<endl;
    cout<<m.count("shivam")<<endl;

    //erase
    m.erase("kumar");
    cout<<m.size()<<endl;

    //iteration 1
    for(auto i : m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    //iteration 2 using iterator in stl
    unordered_map<string,int>::iterator it = m.begin();
    // map<string,int>::iterator it = m.begin();

    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    return 0;
}

/*
output
2
2
0
0
4
0
1
3
unknown 0
Rajbhar 2
shivam 3
unknown 0
Rajbhar 2
shivam 3
*/


//MAXIMUM FREQUENCY NUMBER                                            {T.C = O(N)}
#include<vector>
int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int>count;
    int maxFreq = 0;
    int maxAns = 0;

    for(int i = 0 ; i < arr.size() ; i++){
        count[arr[i]]++;
        maxFreq = max(maxFreq,count[arr[i]]);
    }
    for(int i= 0 ; i < arr.size() ; i++){
        if(maxFreq == count[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}
/*
Sample Input 1:
1 
13
2 12 2 11 -12 2 -1 2 2 11 12 2 -6 
Sample Output 1:
2
*/