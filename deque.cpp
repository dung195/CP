#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define bs binary_search
const ll sized = 1e6;
const ll N = 1e7;
const ll inf = 1e18;
const ll MOD = 123456789;
const ll LOG = 20;
deque<int>a;
vector<int>x;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("main.inp","r",stdin);
	// freopen("main.out","w",stdout);
    int n,r;
    cin>>n>>r;
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        x.push_back(b);
    }
    for(int i=0;i<n;i++){
        while (!a.empty() && a.back()<x[i])
        {
            a.pop_back();
        }
        a.push_back(x[i]);
        if(a.size()>r) a.pop_front();
        if(i+1>=r) cout<<a.front()<<endl;
    }
    return 0;
}
