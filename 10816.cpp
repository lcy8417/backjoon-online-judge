#include <bits/stdc++.h>
using namespace std;

int a[500001];
int pl[10000001];
int	mi[10000001]; 
int res[500001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, M, key, lt, rt;
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
		if(a[i] < 0) mi[-a[i]]++;
		else pl[a[i]]++;
	}
	cin >> M;
	sort(a+1, a+1+N);
	for(int i = 1; i <= M; i++){
		lt = 1; rt = N;
		int cnt = 0;
		cin >> key;
		if(key < a[1] || key > a[N]) continue;
		while(lt<=rt){
			int mid = (lt+rt)/2;
			if(a[mid] == key) {
				if(key < 0) res[i]+=mi[-key];
				else res[i] += pl[key];
				break;
			}else if(a[mid] > key) rt = mid-1;
			else lt = mid + 1;
		}
	}
	for(int i = 1; i <= M; i++) cout << res[i] << " ";
	
}
