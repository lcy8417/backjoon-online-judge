#include <iostream>

using namespace std;

int s;
int res[1000][1000];

void Func(char c, int idx){
	switch(c){
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;			
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	string n;
	cin >> s >> n;
	
	for(int k = 0; k < s*2+3; k++){
		for(int i = 0; i < n.length(); i++){
			int c = n[i] - '0';
			if(k == 0){ // 처음일 떄 
				 switch(c){
					case 0:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 1:
						for(int i = 0; i < s+2; i++) cout << " ";
						break;
					case 2:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 3:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 4:
						for(int i = 0; i < s+2; i++) cout << " ";
						break;
					case 5:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 6:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 7:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 8:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 9:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;			
				}
			}
			if(k > 0 && k < s+1){ // 처음과 중간 사이 
				switch(c){
					case 0:
						cout << "|";
						for(int i = 0; i < s; i++) cout << " ";
						cout << "|";
						break;
					case 1:
						for(int i = 0; i < s+1; i++) cout << " ";
						cout << "|";
						break;
					case 2:
						for(int i = 0; i < s+1; i++) cout << " ";
						cout << "|";
						break;
					case 3:
						for(int i = 0; i < s+1; i++) cout << " ";
						cout << "|";
						break;
					case 4:
						cout << "|";
						for(int i = 0; i < s; i++) cout << " ";
						cout << "|";
						break;
					case 5:
						cout << "|";
						for(int i = 0; i < s+1; i++) cout << " ";
						break;
					case 6:
						cout << "|";
						for(int i = 0; i < s+1; i++) cout << " ";
						break;
					case 7:
						for(int i = 0; i < s+1; i++) cout << " ";
						cout << "|";
						break;
					case 8:
						cout << "|";
						for(int i = 0; i < s; i++) cout << " ";
						cout << "|";
						break;
					case 9:
						cout << "|";
						for(int i = 0; i < s; i++) cout << " ";
						cout << "|";
						break;			
				}
			}
			if(k == s+1){ //중간일 때 
				switch(c){
					case 0:
						for(int i = 0; i < s+2; i++) cout << " ";
						break;
					case 1:
						for(int i = 0; i < s+2; i++) cout << " ";
						break;
					case 2:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 3:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 4:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 5:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 6:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 7:
						for(int i = 0; i < s+2; i++) cout << " ";
						break;
					case 8:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 9:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;			
				}
			}
			if(k > s+1 && k < s*2+2){
				switch(c){
					case 0:
						cout << "|";
						for(int i = 0; i < s; i++) cout << " ";
						cout << "|";
						break;
					case 1:
						for(int i = 0; i < s+1; i++) cout << " ";
						cout << "|";
						break;
					case 2:
						cout << "|";
						for(int i = 0; i < s+1; i++) cout << " ";
						break;
					case 3:
						for(int i = 0; i < s+1; i++) cout << " ";
						cout << "|";
						break;
					case 4:
						for(int i = 0; i < s+1; i++) cout << " ";
						cout << "|";
						break;
					case 5:
						for(int i = 0; i < s+1; i++) cout << " ";
						cout << "|";
						break;
					case 6:
						cout << "|";
						for(int i = 0; i < s; i++) cout << " ";
						cout << "|";
						break;
					case 7:
						for(int i = 0; i < s+1; i++) cout << " ";
						cout << "|";
						break;
					case 8:
						cout << "|";
						for(int i = 0; i < s; i++) cout << " ";
						cout << "|";
						break;
					case 9:
						for(int i = 0; i < s+1; i++) cout << " ";
						cout << "|";
						break;			
				}
			}
			if(k == s*2 + 2){ // 마지막 일 때 
				switch(c){
					case 0:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 1:
						for(int i = 0; i < s+2; i++) cout << " ";
						break;
					case 2:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 3:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 4:
						for(int i = 0; i < s+2; i++) cout << " ";
						break;
					case 5:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 6:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 7:
						for(int i = 0; i < s+2; i++) cout << " ";
						break;
					case 8:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;
					case 9:
						cout << " ";
						for(int i = 0; i < s; i++) cout << "-";
						cout << " ";
						break;			
				}
			}
			cout << " ";
		}
		cout << "\n";
	}
	
}
