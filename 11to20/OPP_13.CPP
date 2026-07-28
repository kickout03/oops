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




class B;
class A{
    int a;
    public:
     A(int x){ a=x;}
    friend int operator+(A,B);

};
class B{
    int b;
    public:
    B(int x){ b=x;}
    friend int operator+(A,B);
};

int operator+(A x,B y){
    cout<<"sum "<<x.a + y.b<<endl;
    return x.a+y.b;
}


int main()
{

    A a(50);
    B b(5);

    int x = a+b;
    cout<< x;
    return 0;
}