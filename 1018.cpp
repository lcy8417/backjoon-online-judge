#include <bits/stdc++.h>
using namespace std;

char c[51][51];

int drawChess(int h, int w){
	int res = 9999;
	int cnt = 0;
	char white_Color = 'W';
	char black_Color = 'B'; 
	// √≥¿Ω¿Ã »≠¿Ã∆Æ∑Œ Ω√¿€ 
	for(int i = h; i <= h + 7; i++){
		for(int j = w; j <= w + 7; j++){
			if(i % 2 == 1){ //  
				if(j % 2 == 1) {// »¶ºˆø° »¶ºˆ 
					if(c[i][j] != white_Color) cnt++;
				}else{ // »¶ºˆø° ¬¶ºˆ 
					if(c[i][j] != black_Color) cnt++;
				}
			}else{ // ¬¶ºˆ 
				if(j % 2 == 1) {// ¬¶ºˆø° »¶ºˆ 
					if(c[i][j] != black_Color) cnt++;
				}else{ // ¬¶ºˆø° ¬¶ºˆ 
					if(c[i][j] != white_Color) cnt++;
				}
			}
		}
	}
	res = min(cnt, res);
	cnt = 0;
	
	// √≥¿Ω¿Ã ∫Ì∑¢¿∏∑Œ Ω√¿€ 
	for(int i = h; i <= h + 7; i++){
		for(int j = w; j <= w + 7; j++){
			if(i % 2 == 1){ //  
				if(j % 2 == 1) {// »¶ºˆø° »¶ºˆ 
					if(c[i][j] != black_Color) cnt++;
				}else{ // »¶ºˆø° ¬¶ºˆ 
					if(c[i][j] != white_Color) cnt++;
				}
			}else{ // ¬¶ºˆ 
				if(j % 2 == 1) {// ¬¶ºˆø° »¶ºˆ 
					if(c[i][j] != white_Color) cnt++;
				}else{ // ¬¶ºˆø° ¬¶ºˆ 
					if(c[i][j] != black_Color) cnt++;
				}
			}
		}
	}
	res = min(res, cnt);
	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	int w, h, rep = 9999;
	char f;
	cin >> h >> w;
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= w; j++)
			cin >> c[i][j];
			
	for(int i = 1; i <= h-7; i++)
		for(int j = 1; j <= w-7; j++)
			rep = min(drawChess(i, j), rep);
			
	cout << rep;
}
