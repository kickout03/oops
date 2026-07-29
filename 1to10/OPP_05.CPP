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

class A{
    private:
    int a;
    public:
    static int g;
    int x;

    A(int a,int x){
        this->x=x;
        this->a=a;
    }

    void showall();


};
void A::showall(){
    cout<<"it is a member fun so it can asses all private or public"<<endl;
    cout<<"a="<<a<<" x="<<x<<" g="<<g<<endl;
}
int A::g=4;



class complex
{
private:
    int a,b;
    public:
    static int p;
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
    friend void helloData2(complex);

    static void changeP(int x){
        cout<<"update valure of p through static func"<<endl;
        p=x;
    }
};



void func(){
    int x=6;
    static int y=6;
    cout<<x<<" "<<y<<endl;
}

int complex::p=3;//static variable has to define outside func

int main()
{
    
    cout<<"this statis variable  directly can call with out any object p = "<<complex::p<<endl;
    func();
    complex::changeP(5);
    cout<<"p = "<<complex::p<<endl;


    cout<<endl;
  

    cout<<"we can access static public member without object: g = "<<A::g<<endl;
    A a(2,3);
    cout<<a.x<<endl;
    // cout<<a.a<<endl;// private
    // cout<<a.g<<endl;// static public
    a.showall();

    return 0;
}