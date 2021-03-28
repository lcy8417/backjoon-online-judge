#include <bits/stdc++.h>
using namespace std;

int arr[101];
vector <int> v;
int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, maxi = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr+1, arr+1+n);
	for(int i = 1; i <= n; i++) {
		for(int j = i+1; j <= n; j++) 
			arr[j] -= arr[i];
	}
	maxi = arr[2];
	for(int i = 3; i <= n; i++) maxi = gcd(maxi, arr[i]);
	
	for(int i = 1; i <= maxi/2 + 1; i++) {
		if(maxi % i == 0) {
			v.push_back(i);
			v.push_back(maxi/i);
		}
	}
	sort(v.begin(), v.end());
	for(int i = 1; i < v.size(); i++){
		if(v[i-1] == v[i]) continue;
		else cout << v[i] << " ";
	}
}
