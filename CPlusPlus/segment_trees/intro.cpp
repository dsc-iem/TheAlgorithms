/*This introduction is range update query where either you can update a value in the array or find the minimum of an element in the range l to r*/
#include <bits/stdc++.h>
#define int 				long long
#define ll          long long
#define pb 					push_back
#define endl 				'\n'
#define ff 					first
#define ss 					second
#define vi 					vector<int>
#define pii 				pair<int, int>
#define all(x)				(x).begin(), (x).end()
#define rep(i, x, y)		for(int i=x; i<y; i++)
#define setbits(x) 			__builtin_popcountll(x)
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 				1e19
#define mod 				1000000007 // 1e9+7
 
#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

 using namespace std;

const int N = 200005;
 
 bool myCompare(int a,int b)
{
  return a>b;
}
int arr[N],st[N];


void buildTree(int si,int ss,int se)//si-->segment index ,ss-->segment start,se-->segment index
{
    if(ss==se){
    st[si]=arr[ss];
    return;}

    int mid=(ss+se)/2;
    buildTree(2*si,ss,mid);//The left segment are stored at indices 2*i and right at 2*i+1
    buildTree(2*si+1,mid+1,se);

    st[si]=min(st[2*si],st[2*si+1]);

}

int query(int si,int ss,int se,int qs,int qe)
{
    if(qs>se || ss>qe)//if query is outside the range of segment return infinity
    return INT_MAX;

    if(qs<=ss && se<=qe)//if it totally belongs inside the range then return that vlaue  (Assume ss as 2 ,se as 4 ,qs=1 and qe=5)
    return st[si];

    int mid=(ss+se)/2;
    
	int l = query(2*si , ss , mid , qs , qe);
	int r = query(2*si+1 , mid+1 , se , qs , qe);
 
	return min(l , r);
}
void update(int si,int ss,int se,int qi,int val)
{
    if(ss==se){
    st[si]=val;
    return;}
    int mid=(ss+se)/2;
    if(qi<=mid)//goes to left side
    update(2*si,ss,mid,qi,val);
    else//goes to right side
    update(2*si+1,mid+1,se,qi,val);

    st[si]=min(st[2*si],st[2*si+1]);
}

 

void solve() {
    int n,q,l,r;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    cin>>arr[i];

    
    buildTree(1,1,n);
    while(q--)
	{
        char c;
		cin>>c>>l>>r;
        if(c=='q')
		cout<<query(1 , 1 , n , l , r)<<endl;
        else
        update(1,1,n,l,r);
	}
    


   
  
  }

signed main()
{ 
      ios;
      int test;
      test=1;
      int tc=1;
    //   factorial(N-1);
    //   InvFactorial(N-1);
    
    // SieveOfEratosthenes(N-1);
      // cin>>test;
      
      while(test--)
      {
          //cout<<"Case #"<<tc<<": ";
          //tc++;
         solve();
      }
       
    
    return 0;
	}