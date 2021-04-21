#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <vector<int> > map(6, vector<int>(6, 0));
vector<vector<string>> cubes = {
    {"0010",
     "1111",
     "0010"},
    {"0100",
     "1111",
     "1000"},
    {"0010",
     "1111",
     "0100"},
    {"0001",
     "1111",
     "1000"},
    {"0001",
     "1111",
     "0100"},
    {"11100",
     "00111"},
    {"1100",
     "0111",
     "0010"},
    {"1100",
     "0111",
     "0001"},
    {"0010",
     "1110",
     "0011"},
    {"0001",
     "1111",
     "0001"},
    {"1100",
     "0110",
     "0011"}
};

vector<string> mirror(const vector<string> &b){
	vector<string> ans(b.size());
	for(int i=0; i<b.size(); i++){
		string temp(b[i]);
		reverse(temp.begin(), temp.end());
		ans[i] = temp;
	}
	return ans;
}

vector<string> rotate(const vector<string> &b){
	vector<string> ans(b[0].size());
	for(int i = 0; i < b[0].size(); i++){
		for(int j = (int)b.size()-1; j >= 0; j--){
			ans[i] += b[j][i];
		}
	}
	return ans;
}

bool check(const vector<string> &a, int x, int y){
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < a[0].size(); j++){
			int nx = x+i;
			int ny = y+j;
			if(nx < 0 || ny < 0 || nx >= 6 || ny >= 6) return false;
			if(map[nx][ny] != a[i][j]-'0') return false;
		}
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int k = 0; k < 3; k++){
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 6; j++){
				cin >> map[i][j];
			}
		}
		bool ans = false;
		for(auto &c : cubes){
			vector<string> cube(c);
			for(int mir=0; mir<2; mir++){
				for(int rot=0; rot<4; rot++){
					for(int i = 0; i < 6; i++){
						for(int j = 0; j < 6; j++){
							ans |= check(cube, i, j);
						}
					}
					cube = rotate(cube);
				}
				cube = mirror(cube);
			}
		}
		cout << (ans?"yes":"no") << "\n";
	}
}
