#include<bits/stdc++.h> 
#include "Trie.cpp"
#include<windows.h>
using namespace std;                          
#pragma GCC optimize("O3")
typedef long long ll;
#define rep(i, n)    for(ll i = 0; i < (n); ++i)
#define repA(i, a, n)  for(ll i = a; i <= (n); ++i)
#define repD(i, a, n)  for(ll i = a; i >= (n); --i)
#define vec(i, a)  for( auto i=a.begin();i != a.end(); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define mp make_pair
#define pb push_back
#define fast  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define sixfive in out 
typedef long double ld;
typedef std::pair<ll, ll> pii;
typedef std::vector<ll> vi;
const ll MOD = 1e9 + 7;
ll n_bits(ll n ) { ll x= __builtin_popcount(n) ;return x ;}
ll binpow(ll a, ll b, ll m=MOD) 
{
    a%=m;
    ll res=1;
    while (b>0) 
    {
        if (b&1)    res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}
    int menuu()
{
    cout<<"\n";
    cout<<"\t\t\t\t\t--------------------------------------------\n";
    cout<<"\t\t\t\t\t--------------------------------------------\n";
    cout<<"\t\t\t\t\t|          PHONE BOOK APPLICATION          |\n";
    cout<<"\t\t\t\t\t--------------------------------------------\n";
    cout<<"\t\t\t\t\t|                                          |\n";
    cout<<"\t\t\t\t\t|       [1]  Add Contacts                  |\n";
    cout<<"\t\t\t\t\t|       [2]  Search by Name                |\n";
    cout<<"\t\t\t\t\t|       [3]  delete                        |\n";
    cout<<"\t\t\t\t\t|       [4]  Show_Recommendations          |\n";
    cout<<"\t\t\t\t\t|                                          |\n";
    cout<<"\t\t\t\t\t--------------------------------------------\n";
    cout<<"\t\t\t\t\t|            [5]    Exite                  |\n";
    cout<<"\t\t\t\t\t--------------------------------------------\n";
    cout<<"\t\t\t\tEnter your choice";
    int a;
    cin>>a;
    
    return a;
}
    
int main()
{    
   Trie *t = new Trie();
    
       
       
        int ch = menuu();
        do{

            if(ch==1)
        {
            
            cout<<"\t\t\t\t\t\t Please enter Name :";
            string s,num;
            cin>>s;
            cout<<"\t\t\t\t\t\t Please enter Phone no :";
            cin>>num;
            if(t->search(s))
               { cout<<"\t\t\t\t\t!!!!!!Name already exists!!!!!!\n\n";}


            
            t->insert(s, num);
            
        }
        else if(ch==2)
        {
            
            cout<<"\t\t\t\t\tPlease enter name to check: ";
            string s;
            cin>>s;
            bool ok = t->search(s);
             if(ok)
                cout<<"\t\t\t\t\t\t Contact exists!! :";
            else
                cout<<"\t\t\t\t\t\t Contact does not exists:";
            
        }
        
        else if(ch==3)
        {
            
            cout<<"\t\t\t\t\tFor Delete Enter Name : ";
            string n;
            cin>>n;
            t->remove(n);
            
        }
        else if(ch==4)
        {

            cout<<"\t\t\t\t\tPlease enter the prefix: ";
            string na;
            cin>>na;
            
            t->show_recommendations(na);
        }
        
        ch=menuu();
    }while(ch!=5);
        


        
        
       	
        
    
    return 0;
}