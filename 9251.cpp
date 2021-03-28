#include <bits/stdc++.h>
using namespace std;

vector <int> dy(1001, 0);
int res;

int main(){
	ios::sync_with_stdio(false);
	string a, b, temp = "";
	cin >> a >> b;	
	if(a.length() > b.length()){ 
		temp = a;
		a = b;
		b = temp;
	}
	for(int i = 0; i < a.length(); i++){
		for(int j = b.length()-1; j >= 0; j--){
			if(a[i] == b[j]){
				dy[j] = max(dy[j], 1);
				for(int k = 0; k < j; k++){
					dy[j] = max(dy[j], dy[k]+1);
				}
				res = max(dy[j], res);
			}
		} 
	}
	cout << res;
}
