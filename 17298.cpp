#include <bits/stdc++.h>

using namespace std;

bool compare(int a, int b){
	return a > b;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	stack <int> s;
	cin >> n;
	vector <int> arr(n+1, 0);
	vector <int> ref(n+1, -1);
	
	for(int i = 1; i <= n; i++) cin >> arr[i];
	
	for(int i = 1; i <= n; i++){
		while(!s.empty() && arr[s.top()] < arr[i]){
			ref[s.top()] = arr[i];
			s.pop();
		}
		s.push(i);
	}
	for(int i = 1; i <= n; i++) cout << ref[i] << " ";
	
}
