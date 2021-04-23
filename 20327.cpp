#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int n, r, k, l;

vector<vector<int> > Func(vector<vector<int> > v, int e, int key){ 
	vector<vector<int> > temp(n, vector<int>(n, 0));
	int len = pow(2, e); 
	queue <int> q;
	// x 시작점 len 길이 
	switch(key){
		case 1: // 배열 상하 반전 
		for(int rx = 0; rx < n; rx+=len){
				for(int ry = 0; ry < n; ry+=len){
					for(int i = rx+len-1; i >= rx; i--)
						for(int j = ry; j < ry + len; j++)
							q.push(v[i][j]);
							
					for(int i = rx; i < rx + len; i++){
						for(int j = ry; j < ry + len; j++){
							temp[i][j] = q.front();
							q.pop();
						}
					}
				}
			}
			while(!q.empty()) q.pop();
			return temp;
		case 2:
			for(int rx = 0; rx < n; rx+=len){
				for(int ry = 0; ry < n; ry+=len){
					for(int i = rx; i < rx + len; i++) // 배열의 좌우 반전 
						for(int j = ry+len-1; j >= ry; j--)
							q.push(v[i][j]);
							
					for(int i = rx; i < rx + len; i++){
						for(int j = ry; j < ry + len; j++){
							temp[i][j] = q.front();
							q.pop();
						}
					}
				}
			}
			return temp;
		case 3: // 오른쪽 회전 
			for(int rx = 0; rx < n; rx+=len){
					for(int ry = 0; ry < n; ry+=len){
						for(int i = ry; i < ry + len; i++)
							for(int j = rx+len-1; j >= rx; j--)
								q.push(v[j][i]);
				
						for(int i = rx; i < rx + len; i++){
							for(int j = ry; j < ry + len; j++){
								temp[i][j] = q.front();
								q.pop();
							}
						}
					}
				}
			while(!q.empty()) q.pop();
			return temp;
		case 4: // 왼쪽으로 회전 
			for(int rx = 0; rx < n; rx+=len){
					for(int ry = 0; ry < n; ry+=len){
						for(int i = ry+len-1; i >= ry; i--){
							for(int j = rx; j < rx + len; j++){
								q.push(v[j][i]);
							}
						}
						for(int i = rx; i < rx + len; i++){
							for(int j = ry; j < ry + len; j++){
								temp[i][j] = q.front();
								q.pop();
							}
						}
					}
				}
			while(!q.empty()) q.pop();
			return temp;
		case 5: // 부분배열 상하 반전 0 1 2 
			for(int rx = n-len; rx >= 0; rx-=len){
				for(int i = rx; i < rx+len; i++)
					for(int j = 0; j < n; j++)
						q.push(v[i][j]);		
				}
				for(int i = 0; i < n; i++){
					for(int j = 0; j < n; j++){
						temp[i][j] = q.front();
						q.pop();
					}
				}
			while(!q.empty()) q.pop();
			return temp;
		case 6: // 부분배열 좌우 반전 
			for(int i = 0; i < n; i++){
					for(int ry = n-len; ry >= 0; ry-=len){
						//for(int i = rx; i < rx + len; i++) // 배열의 좌우 반전 
							for(int j = ry; j < ry+len; j++)
								q.push(v[i][j]);
					}
				}for(int i = 0; i < n; i++){
					for(int j = 0; j < n; j++){
						temp[i][j] = q.front();
						q.pop();
					}
				}
				
			return temp;
		case 7: // 부분배열 오른쪽 회전 	
			for(int ry = 0; ry < n; ry+=len){
				for(int rx = n-len; rx >= 0; rx-=len){
					for(int i = rx; i < rx+len; i++){
						for(int j = ry; j < ry+len; j++){
							q.push(v[i][j]);
						}
					}
				}
			}
			for(int rx = 0; rx < n; rx += len){
				for(int ry = 0; ry < n; ry += len){
					for(int i = rx; i < rx+len; i++){
						for(int j = ry; j < ry+len; j++){
							temp[i][j] = q.front();
							q.pop();
						}
					}
				}
			}
			return temp;
		case 8: // 부분배열 왼쪽 회전 
			for(int ry = n-len; ry >= 0; ry-=len){
				for(int rx = 0; rx < n; rx+=len){
					for(int i = rx; i < rx+len; i++){
						for(int j = ry; j < ry+len; j++){
							q.push(v[i][j]);
						}
					}
				}
			}
			for(int rx = 0; rx < n; rx += len){
				for(int ry = 0; ry < n; ry += len){
					for(int i = rx; i < rx+len; i++){
						for(int j = ry; j < ry+len; j++){
							temp[i][j] = q.front();
							q.pop();
						}
					}
				}
			}
		return temp;	
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> r;
	n = pow(2, n);
	vector<vector<int> > a(n,vector<int>(n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	while(r--){
		cin >> k >> l;
		a = Func(a, l, k);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j] << ' ';
		}
		cout << "\n";
	}	
}
