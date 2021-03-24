#include <bits/stdc++.h>

using namespace std;

struct Tri{
	int area;
	bool left;
	bool right;
	bool top_bottom;
	Tri(int num, bool a, bool b, bool c){
		area = num;
		left = a;
		right = b;
		top_bottom = c;
	}
};

vector <Tri> tri;
int dy[1001];
int ch[1001];
bool pos[1001];

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n;
	for(int i = 1; i <= n; i++){
		tri.push_back(Tri(1, true, true, true));
		int cnt = 1;
		cin >> m;
		while(cnt != m){
			int left_sum = 0;
			int right_sum = 0;
			int tb_sum = 0;
			int maxi = 0;
			if(cnt % 2 == 1){ // 이전 삼각형이 세워져있을때 각변들의 합중에 max 값을 찾으면 됨 
				for(int i = 0; i < tri.size(); i++){
					if(i % 2 == 0) { 
						if(tri[i].left){
							left_sum = tri[i].area;
						}if(tri[i].right){
							right_sum = tri[i].area;
						}if(tri[i].top_bottom){
							tb_sum = tri[i].area;
						}
					}
				}
				if(left_sum > right_sum) {
					maxi = 1;
					tri.push_back(Tri(maxi, true, false, true));
				}
				else {
					maxi = 2;
					tri.push_back(Tri(maxi, false, true, true));
				}
				if(maxi < tb_sum) {
					maxi = 3;
					tri.push_back(Tri(maxi, true, true, false));
				}
				for(int i = 0; i < tri.size(); i++){
					if(i % 2 == 0) { 
						if(maxi == 1){
							tri[i].left = false;
						}if(maxi == 2){
							tri[i].right = false;
						}if(maxi == 3){
							tri[i].top_bottom = false;
						}
					}
				}  
			}else{ // 이전 삼각형이 뒤집어져있을때 
				for(int i = 0; i < tri.size(); i++){
					if(i % 2 == 0) { 
						if(tri[i].left){
							left_sum = tri[i].area;
						}if(tri[i].right){
							right_sum = tri[i].area;
						}if(tri[i].top_bottom){
							tb_sum = tri[i].area;
						}
					}
				}
				if(left_sum > right_sum) {
					maxi = 1;
					tri.push_back(Tri(maxi, true, false, true));
				}
				else {
					maxi = 2;
					tri.push_back(Tri(maxi, false, true, true));
				}
				if(maxi < tb_sum) {
					maxi = 3;
					tri.push_back(Tri(maxi, true, true, false));
				}
				for(int i = 0; i < tri.size(); i++){
					if(i % 2 == 0) { 
						if(maxi == 1){
							tri[i].left = false;
						}if(maxi == 2){
							tri[i].right = false;
						}if(maxi == 3){
							tri[i].top_bottom = false;
						}
					}
				}  
			}
			cnt++;
		}
		cout << tri[tri.size()-1].area << "\n";
		tri.clear();
	}
}


