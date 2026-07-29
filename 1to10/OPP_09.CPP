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
    static int p;
    complex(int x,int y){// parameterize const
        cout<<"built it"<<endl;
        a=x;
        b=y;
    }
  
    

    ~complex(){// after program complete , it auto matically call destrut , ad object destroyed
        cout<<"destroy it"<<endl;
    }
   
    void showData(){
        cout<<"a="<<a<<" b="<<b<<endl;
    }
    

    complex operator+(complex c){// when you call it called prints as vale of c1 copes;
        complex temp(0,0);
        temp.a=a+c.a;
        temp.b=b+c.b;
        return temp;
    }
    complex operator-(complex c){// when you call it called prints as vale of c1 copes;
        complex temp(0,0);
        temp.a=a-c.a;
        temp.b=b-c.b;
        return temp;
    }
    complex operator-(){// when you call it called prints as vale of c1 copes;
        complex temp(0,0);
        temp.a=-a;
        temp.b=-b;
        return temp;
    }

    
};

int main()
{
 
    complex c1(2,4);
    complex c2(2,9);
    c1.showData();
    c2.showData();
    complex c3 = c1+c2;// operator overloading;
    complex c4 = c1-c2;// operator overloading;
    complex c5 = -c1;// operator overloading;
    c3.showData();  
    c4.showData();
    c5.showData();
    cout<<"programs end"<<endl;

    return 0;
}