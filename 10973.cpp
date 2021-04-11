#include <bits/stdc++.h>

using namespace std;

int N;


int main(){
	cin >> N;
	vector <int> v(N);
	bool impossible = true;
 	for(int i = 0; i < N; i++) cin >> v[i];
 	for(int i = 1; i < N; i++){
 		if(v[i-1] > v[i]) {
 			impossible = false;
 			break;
		 }
	}
	if(impossible) cout << -1;
	else{
		prev_permutation(v.begin(), v.end());
	    for(auto it = v.begin(); it != v.end(); it++){
	    	cout << *it << " ";
		}
	}
}
