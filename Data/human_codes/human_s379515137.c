#include <bits/stdc++.h>

#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define rep(i,n) reps(i,0,n)
#define rrep(i,n) for(int i=n-1; i>=0: i--)
#define X first
#define Y second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll INF = 1e9;



bool B[3][2][2][2];
int H, N;




int solve(int n, bool q[][4][4]){
	bool p[20][4][4];


	if(n==N){
		return 0;

		rep(i,20){
			bool f=false;
			rep(j,4)rep(k,4) f |= q[i][j][k];
			if(f) continue;
			return i;
		}
	}

	int ret = -INF;
	rep(x,3) rep(y,3){
		rep(i,20)rep(j,4)rep(k,4) p[i][j][k] = q[i][j][k];

		int a=17;
		for(;a>=0; --a){
			bool f=false;
			rep(i,2) rep(j,2)rep(k,2){
				if(B[n][i][j][k] && p[a+i][x+j][y+k]) f=true;
			}
			if(f)break;
		}
		a++;
		
		rep(i,2)rep(j,2)rep(k,2) p[a+i][x+j][y+k] |= B[n][i][j][k];
		
		bool f=false;
		rep(i,20)rep(j,4)rep(k,4){
			if(j==1 && k==1)continue;
			if(j==2 && k==1)continue;
			if(j==1 && k==2)continue;
			if(j==2 && k==2)continue;
			if(p[i][j][k]) f=true;
		}
		if(f)continue;
		
		int b=0;
		int rr=0;
		rep(i, 20){
			bool f=true;

			reps(j,1,3) reps(k,1,3){
				f &= p[i][j][k];
			}
			if(f){
				rr++;
				continue;
			}

			rep(j,4)rep(k,4){
				p[b][j][k] = p[i][j][k];
			}
			b++;
		}
	
	/*
		printf("a%d %d %d:%d %d\n", n, x, y, rr,a);
		rep(i, 20){
			rep(j,4){
				rep(k,4) cerr << (p[i][j][k]?'$':'.') << ' ';
				cerr << endl;
			}
			cerr << endl;
		}
		cerr << endl;
*/
		
		for(;b<20;++b){
			rep(j,4)rep(k,4) p[b][j][k] = false;
		}
			
		int r = solve(n+1, p)+rr;
		ret = max(ret, r);
	}
	return ret;
}


int main(){

	for(;;){
		bool p[20][4][4];
		rep(i,20)rep(j,4)rep(k,4) p[i][j][k] = false;

		cin >> H >> N;
		if(H+N==0)break;

		rep(i,H)rep(j,2){
			string s;
			cin >> s;

			p[i][j+1][1] = s[0] =='#';
			p[i][j+1][2] = s[1] =='#';
		}
		
		int bn = 0;
		rep(a,N){
			bool g=false;
			rep(i,2){
				bool f=false;
				rep(j,2){
					string s;
					cin >> s;
					B[a][i][j][0] = s[0] == '#';
					B[a][i][j][1] = s[1] == '#';
					f |= s[0] == '#'; 
					f |= s[1] == '#'; 
				}
				if(f) bn++;
				if(i==0) g=!f;
			}
			if(g){
				rep(i,2) rep(j,2){
					B[a][0][i][j] = B[a][1][i][j];
					B[a][1][i][j] = false;
				}
			}
		}
		/*
		rep(i, 20){
			rep(j,4){
				rep(k,4) cerr << (p[i][j][k]?'$':'.') << ' ';
				cerr << endl;
			}
			cerr << endl;
		}
		cerr << endl;
		*/
		/*	
		rep(a, N){
			rep(i, 2){
				rep(j,2){
					rep(k,2) cerr << (B[a][i][j][k]?'$':'.') << ' ';
				cerr << endl;
				}
				cerr << endl;
			}
			cerr << endl;
		}
		cerr << endl;
		*/


		int r = solve(0, p);
		cerr << r << endl;
		cout << r << endl;

		//cout << H+2*N-bn-r << endl;
	}
}