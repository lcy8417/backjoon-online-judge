#include <bits/stdc++.h>
using namespace std;

int res[10001];
int arr1[10001], arr2[10002];
int main() {
	ios_base::sync_with_stdio(false);
	string n1, n2;
	int p1, p2, p3 = 0, upper = 0, x = 0, y = 0, maxi = 0;
	vector <int> res;
	cin >> n1 >> n2;
	p1 = n1.length()-1;
	p2 = n2.length()-1;
	string temp = "";
	if(p1 > p2){
		for(int i = 0; i < p1 - p2; i++) temp += "0";
		n2 = temp + n2;
	}else if(p1 < p2){
		for(int i = 0; i < p2 - p1; i++) temp += "0";
		n1 = temp + n1;
	}
	
	maxi = max(p1, p2);
	for(int i = maxi; i >= 0; i--) arr1[i] = n1[i] - '0';
	for(int i = maxi; i >= 0; i--) arr2[i] = n2[i] - '0';
	
	//cout << n1 << " " << n2 << endl;
	while(1){
		x = arr1[maxi];
		y = arr2[maxi];
		if(maxi < 0){
			if(upper == 1) res.push_back(1);
			break;
		}else if(x + y + upper >= 10){
			res.push_back((x + y + upper) % 10);
			upper = 1;
			maxi--;
		}else{
			res.push_back(x + y + upper);
			upper = 0;
			maxi--;
		}
	}
	for(int i = res.size()-1; i >= 0; i--) cout << res[i];
}
