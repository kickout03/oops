#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <unordered_set>
#define ll long long
#define vll vector<long long>
#define pll pair<ll, ll>
#define omp map<ll, ll>
#define ump unordered_map<ll, ll>
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rep0(i, n) for (ll i = 0; i < n; i++)
#define print(arr) \
    for (int i = 0; i < arr.size(); i++) \
        cout << arr[i] << ' ';
#define input(arr, n) \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
using namespace std;





class complex
{
private:
    int a,b;
    public:

    complex(int x,int y){// parameterize const
        cout<<"built it"<<endl;
        a=x;
        b=y;
    }
   
    void showData(){
        cout<<"a="<<a<<" b="<<b<<endl;
    }
    
    friend void func(complex);
};

void func(complex c){
    cout<<"a="<<c.a<<" b="<<c.b;
}

int main()
{
 
    complex c1(2,4);
    complex c2(2,9);
    
    c1.showData();
    c2.showData();
    func(c1);

    return 0;
}