#include <bits/stdc++.h>

using namespace std;

int N, S, res;
int a[21];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S;
	for(int i = 0; i < N; i++) cin >> a[i];
	for(int i = 1; i < (1 << N); i++){
		int sum = 0;
		for(int j = 0; j < N; j++){
			if(i & (1 << j)){
				sum += a[j];
			}
		}
		if(sum == S) res++;
	}
	cout << res;
}
