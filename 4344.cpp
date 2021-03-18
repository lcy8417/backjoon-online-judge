#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cout << fixed;
	cout.precision(3);
	int n, m, v;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> m;
		int sum = 0;
		double avg = 0;
		int cnt = 0;
		for(int j = 1; j <= m; j++){
			cin >> v;
			arr[j] = v;
			sum += v;
		}
		avg = (double)sum / m;
		for(int j = 1; j <= m; j++)
			if(arr[j] > avg) cnt++;
		cout << round((double)cnt / m * 100000) / 1000<< "%" << "\n";
	}
}
