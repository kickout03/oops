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
    static int g;
    public:
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
    complex(int x,int y){// parameterize const
        cout<<"built it"<<endl;
        a=x;
        b=y;
    }
    complex(){//deafualt constructor
        cout<<"built it"<<endl;
    }

    // there is bydeafult ccopy const
    // we can also make it
    complex(complex &c){
        cout<<"called"<<endl;
        a=c.a;
        b=c.b;
    }

    ~complex(){// after program complete , it auto matically call destrut , ad object destroyed
        cout<<"destroy it"<<endl;
    }
   
    void showData(){
        cout<<"a="<<a<<" b="<<b<<endl;
    }
    

    complex add(complex c){// when you call it called prints as vale of c1 copes;
        complex temp(0,0);
        temp.a=a+c.a;
        temp.b=b+c.b;
        return temp;
    }

    
};
void func(){
    complex c1(2,3);
    c1.showData();
}

int main()
{
    int t;
    complex c1(2,4);
    c1.showData();
    func();
    cin>>t;
    cout<<t<<endl;

    return 0;
}