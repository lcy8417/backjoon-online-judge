#include <iostream>
#include <vector>
using namespace std;

int n, k;

vector<int> Rotate(const vector <int> &v){
	vector <int> ans(2*n+1, 0);
	for(int i = 2; i <= 2*n; i++) ans[i] = v[i-1];
	ans[1] = v[2*n];
	return ans;
}

vector<bool> Rotate(const vector <bool> &v){
	vector <bool> ans(2*n+1, false);
	for(int i = 2; i <= 2*n; i++) ans[i] = v[i-1];
	ans[1] = v[2*n];
	return ans;
}

int main(){
	cin >> n >> k;
	vector <int> a(2*n+1, 0); 
	vector <bool> check(2*n+1, false); // ·Îº¿ÀÇ À§Ä¡ 

	for(int i = 1; i <= 2*n; i++) cin >> a[i];
	for(int cnt = 1;;cnt++){
		// step : 1
		a = Rotate(a);
		check = Rotate(check);
	
		if(check[n] == true) check[n] = false;
		
		for(int i = n-1; i >= 1; i--){ // step : 2
			if(check[i]){
				if(!check[i+1] && a[i+1] > 0){
					check[i] = false;
					check[i+1] = true;
					a[i+1] -= 1;
					if(a[i+1] == 0) k--;
				}
			}
		}
		if(check[n] == true) check[n] = false;
		if(a[1] > 0){
			check[1] = true;
			a[1] -= 1;
			if(a[1] == 0) k--;
		}
		if(k <= 0) {
			cout << cnt;
			break;
		}
	}
}
