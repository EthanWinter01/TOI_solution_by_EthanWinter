/*
CONTEST: 15th Triam Udom Mathematics and Science Olympiad, 2018
HOST: Triam Udom Suksa School
TASK: AouheiMaimuenteekuiganwainiwa (tumso15_am)
SOURCE:
    https://beta.programming.in.th/tasks/tumso15_am
LANG: C++
AUTHOR: EthanWinter (Thanpisit Naowapradit)
SCHOOL: Phimanpittayasan School
WRITTEN ON: 20/05/2023
*/

#include <bits/stdc++.h>
using namespace std;
void solve(){
	int N,M;
	cin >> N;
	for(int i=0;i<N;i++){
        cin >> M;
		int top = M-1;
		for(int j=0; j<M; j++){
			if(j==0){
				for(int a=1;a<=top;a++)
                    cout << " ";
				cout << "^\n";
			} else if(j>0 && j<(M-4)){
                for(int a=1; a<=top-j; a++)
                    cout << " ";
                cout << "/";
                for(int a=1; a<=2*j-1; a++)
                    cout << " ";
                cout << "\\\n";
			} else if(j>=(M-4)&&j<(M-1)){
				for(int a=1; a<=top-j; a++)
                    cout << " ";
				cout << "/";
				if(j==(M-4)||j==(M-2)){
					for(int a=1; a<=(2*j-2)/2; a++)
                        cout << " ";
					cout << "-";
					for(int a=1; a<=(2*j-2)/2; a++)
                        cout << " ";
					cout << "\\";
				}
				if(j==(M-3)){
					for(int a=1; a<=((2*j-2)/2)-2; a++)
                        cout << " ";
					cout << "<( )>";
					for(int a=1; a<=((2*j-2)/2)-2; a++)
                        cout << " ";
					cout << "\\";
				}
				cout << "\n";
			}
			else if(j==(M-1)){
				cout << " ";
                for(int a=1; a<=2*top-1; a++)
                    cout << "-";
                cout << "\n";
			}
		}
	}
}
int main(void){
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}