//INTRO TO C++
#include <bits/stdc++.h>
using namespace std;

//FIND AREA OF RECTANGLE
int main() {
    int L;
    cin>>L;
    int B;
    cin>>B;

    cout<<L*B;

    return 0;
}
/*
Sample Input 1:
4 20
Sample Output 1:
80
*/


//PRINT NAME AND AGE
int main() {
    string name;
    cin>>name;
    int age;
    cin>>age;
    cout <<"The name of the person is "<<name<<" and the age is " <<age<<".";

    return 0;
}
/*
Sample Input 1:
Ali
30
Sample Output 1:
The name of the person is Ali and the age is 30.
*/


//SWAP TWO NUMBERS
pair < int, int > swap(pair < int, int > swapValues) {
    int temp = swapValues.first;
    swapValues.first = swapValues.second;
    swapValues.second = temp;

    return swapValues;
}
/*
Sample Input 1:
2
1 2 
3 4
Sample Output 1:
2 1
4 3
*/


//CALCULATE SIMPLE INTEREST
int main() {
    int p; 
    cin>>p;
    float r;
    cin>>r;
    int t;
    cin>>t;

    cout<<int((p*r*t)/100);

    return 0;
}
/*
Sample Input 1:
2000
2.2
4
Sample Output 1:
176
*/


//FIND CHARACTER CASE
int main() {
    char ch;
    cin>>ch;

    if(ch >= 'A' && ch <= 'Z'){
        cout<<"1";
    }
    else if(ch >= 'a' && ch <= 'z'){
        cout<<"0";
    }
    else{
        cout<< "-1";
    }
}
/*
Sample Input 1 :
v
Sample Output 1 :
0
*/


//TOTAL SALARY
int main() {
    int basic;
    cin>> basic;

    char grade;
    cin>> grade;

    float hra = 0.2*basic;
    float da = 0.5*basic;
    float allow;

    if(grade == 'A'){
        allow = 1700;
    } 
    else if(grade == 'B'){
        allow = 1500;
    }
    else{
        allow = 1300;
    }

    float pf = 0.11*basic;

    int ans = round(basic + hra + da + allow - pf);

    cout << ans;

    return 0;
}
/*
Sample Input 1 :
10000 A
Sample Output 1 :
17600
*/


//LARGEST OF THREE NUMBERS
int main() {
    int a, b, c;
    cin>>a>>b>>c;

    if(a > b && a > c){
        cout<<a;
    }    
    else if(b > a && b > c){
        cout<<b;
    }
    else{
        cout<<c;
    }

    return 0;
}
/*
Sample Input 1 :
4 6 1
Sample Output 1 :
6
*/


//FIND QUARDANT OF COORDINATE POINT
int main() {
    int x,y;
    cin>>x>>y;
    if(x != 0 && y == 0){
        cout<<"x axis";
    }
    else if( x == 0 && y != 0){
        cout<<"y axis";
    }
    else if( x == 0 && y == 0){
        cout<<"Origin";
    }
    else if(x > 0 && y > 0){
        cout<<"1st Quadrant";
    }
    else if(x < 0 && y > 0){
        cout<<"2nd Quadrant";
    }
    else if(x < 0 && y < 0){
        cout<<"3rd Quadrant";
    }
    else {
        cout<<"4th Quadrant";
    }

    return 0;
}
/*
Sample Input 1 :
5 100
Sample Output 1 :
1st Quadrant
*/


//SUM OF EVEN NUMBERS TILL N
int main() {
    int n;
    cin>>n;

    int sum = 0;
    for(int i = 0 ; i <= n ; i += 2){
        sum = sum + i;
    }
    cout<<sum;
}
/*
Sample Input 1 :
 6
Sample Output 1 :
12
*/


//FAHRENHEIT TO CELSIUS
void print(int start ,int end, int gap){
    int celcius;
    while (start <= end){
        celcius = ((start-32)*5)/9;
        cout<<start<<" "<<celcius<<endl;
        start = start + gap;
    }
}
int main() {
    int start, end,gap;
    cin>>start>>end>>gap;
    print(start, end, gap);

    return 0;
}
/*
Sample Input 1:
0 
100 
20
Sample Output 1:
0   -17
20  -6
40  4
60  15
80  26
100 37
*/


//SUM OF EVEN AND ODD
int main() {
    string n;
    cin>>n;
    int evenSum = 0;
    int oddSum = 0;
    for(char i : n){
        if(i % 2 == 0 ){
            evenSum += i -'0';
        }
        else{
            oddSum += i - '0';
        }
    }
    cout<<evenSum<<" "<<oddSum;

    return 0;
}
/*
Sample Input 1:
1234
Sample Output 1:
6 4
*/


//FIND POWER OF A NUMBER
void pow(int x, int n){
    int ans = 1;
    for(int i = 0 ; i < n ; i++){
        ans = ans*x;
    }
    cout<<ans;
}
int main() {
    int x, n;
    cin>>x>>n;
    pow(x, n);

    return 0;
}
/*
Sample Input 1 :
 3 4
Sample Output 1 :
81
*/


//FACTORIAL OF NUMBER
int main(){
    int n;
    cin>>n;
    int fact = 1;
    if(n < 0){
        cout<<"Error";
        return 0;
    }
    else{
        for(int i = 1; i <= n ; i++){
            fact = fact*i;
        }
        cout<<fact;
    }

    return 0;
}
/*
Sample Input 1 :
5
Sample Output 1 :
120
*/


//FIBONACCI NUMBER                                                  {T.C = O(N), S.C = O(1)}
#define mod 1000000007
int fibonacciNumber(int n){
    if(n <= 1){
        return n;
    }
    int prev = 0;
    int curr = 1;
    for(int i = 2 ; i <= n ; i++){
        int temp = curr;
        curr = (prev + curr) % mod;
        prev = temp;
    }
    return curr;
}
//using matrixexponential
int* arr = (int*)calloc(100002, sizeof(int));

int fibonacciNumber(int n){
    //base case
    if(n == 0 || n == 1){ 
        arr[n] = n;
        return n;
    }
    if(arr[n] > 0) return arr[n];
    int ans = (1ll)*(fibonacciNumber(n - 1) + fibonacciNumber(n - 2))%mod;
    arr[n] = ans;
    return ans;
}
/*
Sample Input 1:
2
10
7
Sample Output 1:
55
13
*/


//PRINT ALL DIVISORS OF A NUMBER
vector<int> printDivisors(int n) {
    vector<int>divisors;
    for(int i = 1 ; i <= n ; i++){
        if(n % i == 0){
            divisors.push_back(i);
        }
    }
    return divisors;
}
/*
Sample Input 1 :
10
Sample Output 1 :
1 2 5 10
*/


//BINARY TO DECIMAL
int main(){
    int n;
    cin>>n;

    int ans = 0;
    int power = 1;
    while(n > 0){
        int lastDigit = n % 10;
        ans += lastDigit*power;
        power *= 2;
        n /= 10;
    }
    cout<<ans;
}
/*
intput
111
output
7
*/


//DECIMAL TO BINARY
int main(){
    int n;
    cin>>n;
    int ans = 0;
    int power = 1;
    while(n > 0){
        int parityDigit = n % 2;
        ans += parityDigit*power;
        power *= 10;
        n /= 2;
    }
    cout<<ans;
}


//SET BITS
int countBits(int n){
    int count = 0;
    while(n >0){
        if(n % 2 == 1){
            count++;
        }
        n /= 2;
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    cout<<countBits(n);
    return 0;
}
/*
Sample Input 2:
13                        //1101
Sample Output 2:
3
*/


//TOTAL PRIME
bool isPrime(int n){
    if(n <= 1){
        return false;
    }
    for(int i = 2 ; i*i <= n ; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
int totalPrime(int S, int E){
    int count = 0;
    for(int i = S ; i <= E ; i++){
        if(isPrime(i)){
            // cout<<i<<" ";
            count++;
        }
    }
    return count;
}

int main() {
    int S, E;
    cin >> S >> E;
    cout << totalPrime(S, E);
    return 0;
}
/*
Sample Input 1 :
2 10
Sample Output 1 :
4
*/

//-----------------------------------------------------    ARRAY      ------------------------------------------------------------------


//FIRST INDEX OF ELEMENT
int main() {
    int n;
    cin>>n;
    // vector<int>arr(n);            //it can also be use
    int *arr = new int[n];

    //taking input
    for(int i = 0 ; i  < n ; i++){
        cin>>arr[i];
    }
    int x;
    cin>>x;

    //searching index
    for(int i = 0 ; i < n; i++){
        if(arr[i] == x){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
/*
Sample Input 1 :
8
7 5 2 11 2 43 1 1
2
Sample Output 1 :
2
*/


//LAST INDEX OF ELEMENT
int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    
    //taking input of array
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }

    int x;
    cin>>x;
    //searching from last
    for(int i = n-1 ; i >= 0 ; i--){
        if(arr[i] == x){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
/*
Sample Input 1 :
8
7 5 2 11 2 43 1 1
2
Sample Output 1 :
4
*/


//REVERSE THE ARRAY
int main() {
    int n;
    cin>>n;
    int *arr = new int[n];

    //taking input array element
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }

    //reverse array
    for(int i = n-1 ; i >= 0 ; i--){
        cout<<arr[i]<<" ";
    }

    return 0;
}
/*
Sample Input:
8
7 5 2 11 2 43 1 10
Sample Output:
10 1 43 2 11 2 5 7
*/


//ROTATE ARRAY
int main() {
    int n;
    cin>>n;
    int *arr = new int[n];

    //taking input
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;

    //create temporary array to store k elements
    int *temp= new int[k];
    //copy k elements to temp array
    for(int i = 0 ; i < k ;i++){
        temp[i] = arr[i];
    }
    //shifting array element to left for filling index
    for(int i = k ; i < n; i++){
        arr[i-k] = arr[i];
    }
    //copy k element to end of original array
    for(int i = 0 ; i < k ; i++){
        arr[n-k+i] = temp[i];
    }

    //print rotated array
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }

    delete[] arr;
    delete[] temp;

    return 0;
}
/*
Sample Input 1:
8
7 5 2 11 2 43 1 1
2
Sample Output 1:
2 11 2 43 1 1 7 5
*/


//SORT 012
//dutch national flag algo
void sort012(int arr[], int n) {
    int ptr1 = 0, ptr2 = n-1, i=0;
    while(i <= ptr2){
        if(arr[i] == 0){
            swap(arr[i],arr[ptr1]);
            i++;
            ptr1++;
        }
        else if(arr[i] == 2){
            swap(arr[i], arr[ptr2]);
            ptr2--;
        }
        else{                            //arr[i] == 1
            i++;
        }
    }
}
/*
Sample Input 1:
1
7
0 1 2 0 2 0 1
Sample Output 1:
0 0 0 1 1 2 2 
*/


//KTH LARGEST/SMALLEST ELEMENT IN AN ARRAY
//last test case not passed
vector<int> kthSmallestLargest(vector<int>&arr, int n, int k) {
    vector<int>result(2);

    //finding kth largest element
    //create max heap
    priority_queue<int>maxHeap(arr.begin(), arr.end());
    //pop from max heap exactly k-1 times
    for(int i = 1; i < k ; i++){
        maxHeap.pop();
    }
    //store ans
    result[0] = maxHeap.top();

    //finding kth smallest element
    //create min heap
    priority_queue<int,vector<int>,greater<int>>minHeap(arr.begin(), arr.end());
    //pop from min heap exactly k-1 times
    for(int i = 1; i < k ; i++){
        minHeap.pop();
    }
    //store ans
    result[1] = minHeap.top();

    return result;
}
//copied solution
int duplicates(int arr[], int n) {    
    if (n==0 || n==1){
        return n;
    }

    int j = 0;

    for (int i=0; i < n-1; i++){
        if (arr[i] != arr[i+1]){
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n-1];

    return j; 
}
void kthSmallestLargest(int arr[], int n, int k) {    //Write your code here
    sort(arr, arr + n);
    n = duplicates(arr, n);
    int start=0, end=n-1;    
    if(k<=n){    
        cout << arr[n-k] <<" "<< arr[k-1] << endl;    
    }else{        
        cout << -1 <<" "<< -1 << endl;    
    } 
}
int main() {
    int t;
    cin >> t;

    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        kthSmallestLargest(arr, n, k);
        t--;
    }
    return 0;
}
/*
input
1
6 3
1 2 3 4 5 6
output
4 3*/


//-------------------------------------------------     STRINGS      -----------------------------------------------------------------


//COUNT WORDS
int countWords(string input) {
    int count = 1;
    for(int i = 0 ; i < input.length() ; i++){
        if(input[i] == ' '){
            count++;
        }
    }
    return count;
}
int main() {
    string input;
    getline(cin, input);
    int output = countWords(input);
    cout << output << endl;
    return 0;
}
/*
Sample Input 2:
this is a sample string
Sample Output 2:
5
*/


//ALL SUBSTRINGS
void printSubstrings(string input) {
    for(int i = 0 ; i < input.length(); i++){
        string str = "";
        for(int j = i ; j < input.length() ; j++){
            str.push_back(input[j]);
            cout<<str<<endl;
        }
    }
}
int main() {
    string input;
    getline(cin, input);
    printSubstrings(input);
    return 0;
}
/*
Sample Input 1:
abc
Sample Output 1:
a 
ab 
abc 
b 
bc 
c 
*/


//REVERSE STRING WORDWISE
//using another temp string                                               {T.C = O(N), S.C = O(N)}
string reverseStringWordWise(string input){
    string s = input;
    reverse(s.begin(), s.end());

    //reverse individual word
    int start= 0;
    int end = 0;
    while(end < s.length()){
        if(s[end] == ' '){
            reverse(s.begin()+start, s.begin()+end);
            start = end+1;                                             //for next word
        }
        end++;
    }

    //revers the last word (or only 1 word)
    reverse(s.begin()+start, s.begin()+end);

    return s;
}

int main(){
    string s;
    getline(cin, s);
    string ans = reverseStringWordWise(s);
    cout << ans << endl;
}

//NOT USING EXTRA TEMP STRING                                               {T.C = O(N), S.C = O(1)}
void reverseWords(string &str, int s, int e) {
    while (s <= e) {
        swap(str[s], str[e]);
        s++;
        e--;
    }
}
string reverseStringWordWise(string input){
    int i = 0, j = 0;
    reverse(input.begin(), input.end());
    while (input[i] != '\0') {
        while (input[j] != ' ' && input[j] != '\0') {
            j++;
        }
        reverseWords(input, i, j - 1);
        i = j;
        i++;
        if (input[j] == '\0')
            break;
        j = i;
    }
    return input;
}
/*
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome
*/


//CHECK PERMUTATION
//inbuild sort function                                                {T.C = O(N*LOGN), S.C = O(1)}
bool isPermutation(char input1[], char input2[]) {
    int n = sizeof(input1);
    sort(input1, input1+n);
    sort(input2, input2+n);
    for(int i = 0 ; i < n ; i++){
        if(input1[i] != input2[i]){
            return false;
        }
    }
    return true;
} 
//using unordered map                                                  {T.C = O(N), S.C = O(N)}
bool isPermutation(char input1[], char input2[]) {
    unordered_map<char, int>mp1;
    unordered_map<char, int>mp2;
    
    int n = sizeof(input1);
    //put element into map
    for(int i = 0 ; i < n ;i++){
        mp1[input1[i]]++;
        mp2[input2[i]]++;
    }
    if(mp1 != mp2){
        return false;
    }
    return true;
}
/*
Sample Input 1:
abcde
baedc
Sample Output 1:
true
*/


//REMOVE CONSECUTIVE DUPLICATES                                                       {T.C = O(N), S.C = O(N)}
string removeConsecutiveDuplicates(string input)
{
    string str = "";
    for(int i = 0 ; i < input.length(); i++){
        if(input[i] != input[i+1]){
            str.push_back(input[i]);
        }
    }
    return str;
}
int main()
{
    string str;
    cin >> str;
    string ans = removeConsecutiveDuplicates(str);
    cout << ans << endl;
}
/*
Sample Input 1:
aabccbaa
Sample Output 1:
abcba
*/


//REVERSE EACH WORD
string reverseEachWord(string input)
{
    string s = input;
    int start = 0;
    int end = 0;
    while(end < s.length()){
        if(s[end] == ' '){
            reverse(s.begin()+ start, s.begin()+end);
            start = end+1;                                     //for next word
        }
        end++;
    }
    //for last word
    reverse(s.begin() + start, s.begin()+end);
    return s;
}
int main()
{

    string str;
    getline(cin, str);
    string ans = reverseEachWord(str);
    cout << ans << endl;
}
/*
Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
emocleW ot gnidoC sajniN
*/


//REMOVE CHARACTERS                                                                     
string removeAllOccurrencesOfChar(string input, char c) {
    string s = "";
    for(int i = 0 ; i < input.length() ; i++){
        if(input[i] != c){
            s.push_back(input[i]);
        }
    }
    return s;
}
int main() {
    string input;
    char c;
    cin >> input >> c;
    string output = removeAllOccurrencesOfChar(input, c);
    cout << output << endl;
    return 0;
}
/*
Sample Input 1:
aabccbaa
a
Sample Output 1:
bccb
*/


//----------------------------------------------      OOPS        -------------------------------------------------------------------------------------


//COMPLEX NUMBER CLASS
class ComplexNumbers {
private:
    int real;
    int img;
public:
    //constructor
    ComplexNumbers(int x, int y){
        real = x;
        img = y;
    }
    void plus(ComplexNumbers c){
        this->real = this->real+c.real;
        this->img = this->img+c.img;
    }
    void multiply(ComplexNumbers d){
        int a = (this->real)*(d.real) - (this->img)*(d.img);
        int b = (this->real)*(d.img) + (this->img)*(d.real);
        this->real = a;
        this->img = b;
    }
    void print(){
        cout<<real<<" + i"<<img<<endl;
    }

};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    } else {
        return 0;
    }
}
/*
Sample Input 1 :
4 5
6 7
1
Sample Output 1 :
10 + i12
*/


//POLYNOMIAL CLASS
class Polynomial {
    public:
    int *degCoeff;
    int capacity;
    Polynomial(){
        degCoeff = new int[5];
        for(int i = 0;i<5;i++){
            degCoeff[i]=0;
        }
        capacity = 5;
    }
    Polynomial(Polynomial const &p2){
        degCoeff = new int[p2.capacity];
        for(int i = 0;i<p2.capacity;i++){
            degCoeff[i]=p2.degCoeff[i];
        }
        capacity = p2.capacity;
    }
    void operator=(Polynomial const &p2){
        this -> degCoeff = new int[p2.capacity];
        for(int i = 0;i<p2.capacity;i++){
            this -> degCoeff[i]=p2.degCoeff[i];
        }
        this -> capacity = p2.capacity;
    }
    void setCoefficient(int degree, int coeff){
        if(degree >= capacity){
            int *newdegCoeff = new int[degree +1];
            for(int i= 0;i<capacity;i++){
                newdegCoeff[i]=degCoeff[i];
            }
            for(int i = capacity;i<degree+1;i++){
                newdegCoeff[i]=0;
            }
            delete [] degCoeff;
            degCoeff = newdegCoeff;
            capacity = degree+1;
        }
        degCoeff[degree]= coeff;
    }
    void print(){
        for(int i = 0;i<capacity;i++){
            if(this -> degCoeff[i]!=0){
                cout<<this -> degCoeff[i]<<"x"<<i<<" ";
            }
        }cout<<endl;
    }
    Polynomial operator+(Polynomial const &p2){
        Polynomial result;
        result.capacity = max(capacity,p2.capacity);
        result.degCoeff = new int[result.capacity];
        if(capacity<p2.capacity){
            int i = 0;
            for(;i<capacity;i++){
                result.degCoeff[i]=degCoeff[i]+p2.degCoeff[i];
            }for(;i<p2.capacity;i++){
                result.degCoeff[i]=p2.degCoeff[i];
            }
        }else{
            int i= 0;
            for(;i<p2.capacity;i++){
                result.degCoeff[i]=degCoeff[i]+p2.degCoeff[i];
            }for(;i<capacity;i++){
                result.degCoeff[i]=degCoeff[i];
            }
        }
        return result;
    }
    Polynomial operator-(Polynomial const &p2){
        Polynomial result;
        result.capacity = max(capacity,p2.capacity);
        result.degCoeff = new int[result.capacity];
        if(capacity<p2.capacity){
            int i = 0;
            for(;i<capacity;i++){
                result.degCoeff[i]=degCoeff[i]-p2.degCoeff[i];
            }for(;i<p2.capacity;i++){
                result.degCoeff[i]=-p2.degCoeff[i];
            }
        }else{
            int i= 0;
            for(;i<p2.capacity;i++){
                result.degCoeff[i]=degCoeff[i]-p2.degCoeff[i];
            }for(;i<capacity;i++){
                result.degCoeff[i]=degCoeff[i];
            }
        }
        return result;
    }
    Polynomial operator*(Polynomial const &p2){
        Polynomial result;
        result.capacity = capacity + p2.capacity;
        result.degCoeff = new int[result.capacity];
        for(int i = 0;i<result.capacity;i++){
            result.degCoeff[i]=0;
        }
        for(int i = 0;i<capacity;i++){
            for(int j = 0;j<p2.capacity;j++){
                result.degCoeff[j+i]+=degCoeff[i]*p2.degCoeff[j];
            }
        }
        return result;
    }
};

int main() {
    int count1, count2, choice;
    cin >> count1;

    int * degree1 = new int[count1];
    int * coeff1 = new int[count1];

    for (int i = 0; i < count1; i++) {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++) {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int * degree2 = new int[count2];
    int * coeff2 = new int[count2];

    for (int i = 0; i < count2; i++) {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++) {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch (choice) {
        // Add
    case 1:
        result = first + second;
        result.print();
        break;
        // Subtract
    case 2:
        result = first - second;
        result.print();
        break;
        // Multiply
    case 3:
        result = first * second;
        result.print();
        break;

    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
        break;
    }

    }

    return 0;
}
/*
Sample Input 1 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
1
Sample Output 1 :
4x0 3x1 -3x2 3x3 -4x5
*/


//FRACTION CLASS
class Fraction {
private:
    long long int num;
    long long int den;

public:
    Fraction(int n, int d){
        num = n;
        den = d;
    }
    void add(int n1, int d1){
        if(den == d1){
            num += n1;
        }
        else{
            num = (num*d1) + (n1*den);            //numerator = (a*d) + (c*d)
            den = (den*d1);                     //denominator = b*d
        }
    }
    void multiply(int n1, int d1){
        num *= n1;
        den *= d1;
    }
    void print(){
        int div = __gcd(num, den);              //getting already simplfied answer
        cout<<num/div<<"/"<<den/div<<endl;
    }

};

int main() {
    int n, d;                     //n = numerator, d = denominator
    cin>>n>>d;

    Fraction f1(n, d);
    int q;                        //query no. = 1 == add , 2 == multiply
    cin>>q;

    for(int i = 0 ; i < q ; i++){
        int op, n1, d1;
        cin>>op>>n1>>d1;
        if(op == 1){
            f1.add(n1, d1);
            f1.print();
        }
        else{
            f1.multiply(n1, d1);
            f1.print();
        }
    }

    return 0;
}
/*
Sample Input 1:
67 14
1
2 7 78
Sample Output 1:
67/156
Explanation Of Sample Input 1:
Fist fraction is 67/14 and no. of queries is 1. So now 
in the next line 2 7 8 means type=2 which defines 
multiplication and second fraction is 7/78 so 67/74 * 7/78=67/156.
*/


//PRINT NAME AND AGE (USING GETTER AND SETTER)
class Person {
private:
    string name;
    int age;

public:
    void setName(string newName){
        name = newName;
    }
    string getName(){
        return name;
    }
    void setAge(int newAge){
        age = newAge;
    }
    int getAge(){
        return age;
    }
};

int main() {
    Person p;

    string name;
    cin>>name;
    int age;
    cin>>age;

    p.setName(name);
    p.setAge(age);

    cout<<"The name of the person is "<<p.getName()<<" and the age is "<<p.getAge()<<"."<<endl;

    return 0;
}
/*
Sample Input 1:
Afzal
67
Sample Output 1:
The name of the person is Afzal and the age is 67.
*/


//AREA OF RECTANGLE
class Rectangle {
public:
    int length;
    int breadth;
    int getArea(){
        return length * breadth;
    }
};
/*
Sample Input 1:
4 20
Sample Output 1:
80
*/


//CAR CLASS
class Car {
    // Write your constructor and printCarInfo method here.
public:
    int n;
    string c;
    Car(int n, string c ){
        this->n = n;
        this->c = c;
    }
    void printCarInfo(){
        cout<<"noOfGear: "<< n <<endl;
        cout<<"color: "<< c<<endl;
    }
};


class RaceCar: public Car {
    // Write your constructor and printRaceCarInfo method here.
public:
    int s;
    RaceCar(int n, string c, int s):Car(n,c){
        this->s = s;
    }
    void printInfo(){
        printCarInfo();
        cout<<"maxSpeed: "<< s <<endl;
    }
};
int main() {
    int noOfGear, maxSpeed;
    string color;
    cin >> noOfGear >> color >> maxSpeed;
    RaceCar raceCar(noOfGear, color, maxSpeed);
    raceCar.printInfo();
    return 0;
}
/*
Sample Input 1:
5
red
1000
Sample Output 1:
noOfGear: 5
color: red
maxSpeed: 1000
Explanation Of Sample Output 1:
When we call the printInfo function, all the info related to the car will be printed the same as the above format.
*/


//SHAPE AND OVERRIDING
class Shape{
public:
    int l;
    int b;
};
class Square : public Shape{
public:
    Square(int l){
        this->l = l;
    }
    void area(){
        cout<<"square"<<endl;
        cout<< l * l<<endl;
    }

};
class Rectangle : public Shape{
public:
    Rectangle(int l, int b){
        this->l = l;
        this->b = b;
    }
    void area(){
        cout<<"rectangle"<<endl;
        cout<< l * b;
    }
};
int main() {

    Square s(5);
    s.area();

    Rectangle r(5, 4);
    r.area();

    return 0;
}
/*
Sample Output 1 :
square
25
rectangle
20
Explanation Of Sample Output 1:
Firstly we are creating the object of class Square with mentioned length 5 and calling the functions printMyType which output square and then calculateArea which returns 25 and hence printed. Similarly, it is done for the Rectangle class.
*/