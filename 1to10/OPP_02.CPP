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
    complex(/* args */){
        cout<<"built it"<<endl;;
    }
    ~complex(){}
    void setdata(int x,int y){
        a=x;
        b=y;
    }
    void showData(){
        cout<<"a="<<a<<" b="<<b<<endl;
    }

    complex add(complex c){
        complex temp;
        temp.a=a+c.a;
        temp.b=b+c.b;
        return temp;
    }

    void helloData();
};
//class member function
// complex:: --> this is called scope resolution operator
void complex::helloData(){
    cout<<a<<" "<<b<<endl;//here it got acces of member variable of object
}



int main()
{
    complex c1,c2;
    complex c3 = complex();
    c1.setdata(3,4);
    c1.showData();
    c3.setdata(1,2);
    c3.showData();
    c1.helloData();
    c2=c1.add(c3);
    c2.showData();
    return 0;
}