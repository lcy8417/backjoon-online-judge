#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	long long unsigned int K, N, lt, rt;
	long long unsigned int res = 0;
	cin >> K >> N;
	vector <int> ran(K+1, 0);
	for(int i = 1; i <= K; i++) cin >> ran[i];
	sort(ran.begin()+1, ran.begin()+1+K);
	lt = 1;
	rt = ran[K];
	while(lt<=rt){
		long long unsigned int mid = (lt+rt)/2;
		long long unsigned int cnt = 0;
		if(mid > 0) for(int i = 1; i <= K; i++) cnt += ran[i] / mid;
		if(cnt >= N){
			res = max(res, mid);
			lt = mid+1;
		}else rt = mid-1;
	}
	cout << res;
}
