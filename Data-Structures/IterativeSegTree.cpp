#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 100007;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
	  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
	  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
	  int res = 1;
	  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		    if (l&1) res += t[l++];
		    if (r&1) res += t[--r];
	  }
     return res;
}

int posneg(int a){
    if(a>0) return 1;
	  if(a<0) return -1;
	  else return 0;
}

int main() {
    int k, a;
    while(cin >> n){
        cin >> k;
        for (int i = 0; i < n; ++i){
            cin >> a;
            t[n+i] = posneg(a);
        }
        build();
        
		    while(k--){
  		      string command;
	  		    cin >> command;

      			int a,b;		
      			cin >> a >> b;
  		    	if(command == "C"){
  				      modify(a-1, posneg(b));
  			    }
  			    if(command == "P"){
  				      int answ = query(a-1, b); //ignore \/
  				      if(answ == 1)
  					        cout << "+";
  				      else if(answ == -1)
  					        cout << "-";
	  			      else if(answ == 0)
		  			        cout << 0;
			      }
		    }
		    cout << endl;
	  }
	  return 0;
}
