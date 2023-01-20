//CHARACTER ARRAY AND STRINGS

#include<iostream>
using namespace std;


/*
//FOR REMOVE CASE SENSITIVITY
char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
//CHECK THE STRING IS PALINDROME
bool checkPalindrome(char a[] , int n){
    int s = 0;
    int e = n-1;
    while(s <= e){
        //for case sensitive
        // 
        // if(a[s] != a[e]){
        //     return 0;
        // }
        // 
        //for case insensitive
        if(toLowerCase(a[s]) != toLowerCase(a[e])){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

//REVERSE
void reverse(char name[] , int n){
    int s = 0 ; 
    int e = n-1;
    while(s < e){
        swap(name[s++] , name[e--]);
    }
}

//LENGTH
int getLength(char name[]) {
    int count = 0;
    for(int i = 0 ; name[i] != '\0' ; i++){
        count++;
        // cout<<name[i]<<" ";
    }
    return count;
}
int main(){
    char name[20];
    cout<<"Enter the name : "<<endl;
    cin>>name;

    // name[2] = '\0';
    cout<<"The name is : "<<endl;
    cout<<name<<endl;

    int len = getLength(name);
    cout<<"The length of string is : "<<len<<endl;  

    cout<<"The name after reverse : "<<endl;
    reverse(name , len);
    cout<<name<<endl;

    cout<<"Palindrome or not : "<<checkPalindrome(name , len)<<endl;


    return 0;
}
*/
/*OUTPUT
Enter the name : 
Nitin       //nitin
The name is : 
Nitin       //nitin
The length of string is : 5
The name after reverse :
nitiN
Palindrome or not : 1
*/
 

 //VALID PALINDROME (ONLY MAIN FUNCTION)
/*
bool valid(char ch){
    if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch<= 'Z' || ch >= '0' && ch<= '9'){
        return 1;
    }
    return 0;
}
char toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z'||  ch >= '0' && ch<= '9'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
bool checkPalindrome(string a){
    int s = 0;
    int e = a.size() - 1;
    while(s <= e){
        if(a[s] != a[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

bool isPalindrome(string s){
    //1st case remove irrelevent char
    string temp = "";
    for(int i = 0 ; i < s.size() ; i++){
        if(valid(s[i])){
            temp.push_back(s[i]);
        }
    }

    //2nd case convert to lowercase
    for(int i = 0 ; i < temp.length() ; i++){
        temp[i] = toLowerCase(temp[j]);
    }

    //3rd case check palindrome
    return checkPalindrome(temp);
}
*/


// REVERSE WORD IN A STRING 

// RETURN MAXIMUM OCCURING CHARACTER IN AN INPUT STRING
/*
char getMaxOccChar(string s){

    //create an array of count of char
    int a[26]= {0};
    for(int i = 0 ; i < s.length() ; i++){
        char ch = s[i];
        int num = 0;
        num = ch - 'a';
        a[num]++;
    }

    //find maximum occurance character
    int max= -1 , ans = 0;
    for(int i = 0 ; i < 26; i++){
        if(max < a[i]){
            ans = i;
            max = a[i];
        }
    }
    return 'a'+ans;
}
int main(){
    string s;
    cout<<"Enter the string : "<<endl;
    cin>>s;

    cout<<"Maximum occuring character is : "<<endl;
    cout<<getMaxOccChar(s);

    return 0;
}
*/
/*OUTPUT
Enter the string : 
test
Maximum occuring character is : 
t
*/
 

//INT THE STRING REPLACE " " -> @40
/*
string replaceSpace(string s){
    string temp = "";
    for (int i = 0 ; i < s.length() ; i++){
        if(s[i] == ' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else{
            temp.push_back(s[i]);
        }
    }
    return temp;
}
int main(){
    string s;
    cout<<"Enter the string : "<<endl;
    getline(cin,s);

    cout<<"After replacing spaces : "<<endl;
    cout<<replaceSpace(s);

    return 0;
}
*/
/*OUTPUT
Enter the string :
my name is shivam
After replacing spaces :
my@40name@40is@40shivam
*/


//REMOVE ALL OCCURANCE OF A SUBSTRING
/*
string removeOccurance(string s , string part){
    while(s.length() != 0 && s.find(part) < s.length()){
        s.erase(s.find(part) , part.length());
    }
    return s;
}
int main(){

    string s;
    cout<<"Enter the string : "<<endl;
    getline(cin,s);

    string part;
    cout<<"Enter the part to remove : "<<endl;
    getline(cin,part);

    string x = removeOccurance(s , part);
    cout<<"The required string is : "<<x<<endl;
}
*/
/*OUTPUT
Enter the string : 
d a a b c b a a b c b c 
Enter the part to remove : 
a b c 
The required string is : d a b 
*/


//PERMUTATION IN STRING

//REMOVE ALL ADJACENTS  DUPLICATES IN STRING

//STRING COMPRESSION (only function)
/*
#include<vector>

int compress(vector<char> c){
    int i = 0 ;
    int ansIndex = 0;
    int n = c.size();
    while(i < n){
        int j = i + 1;
        while(j < n && c[i] == c[j]){
            j++;
        }

        //old store
        c[ansIndex++] = c[i];
        int count = j-i;
        if(count > 1){
            
            //converting count into single digit
            string cnt = to_string(count);
            for(char ch : cnt){
                c[ansIndex++] = ch;
            }
        }
        //moving to new character
        i = j;
    }
    return ansIndex;
}
*/