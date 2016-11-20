#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<conio.h>
#define N 32
#pragma warning(disable:4996)
using namespace std;
void setlastch(int n, char chr);

map<string, int> mp;
map<int, string> mp2;
string s;
int main(){
	freopen("alice.txt", "r", stdin);
	int n = 5;
	char lastch[N] = { ' ' };
	char chr;
	s = "aaaaa";
	while ((chr = getchar()) != EOF){
		if (chr != '\n'){
			setlastch(n, chr);
		}
	}
	priority_queue<int, string> mq;
	for (map<string, int>::iterator iter = mp.begin(); iter != mp.end(); iter++){
		//cout << "first (" << (*iter).first << ")" << endl;
		//cout<< "second (" << (*iter).second << ")" << endl;
		mp2[(*iter).second] = (*iter).first;
	}
	for (map<int, string>::iterator iter = mp2.begin(); iter != mp2.end(); iter++){
		cout << "Frequence " << (*iter).first <<endl;
		string str = (*iter).second;
		bool check = true;
		for (int i = n - 1; i >= 0; i--){
			if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] == ' '))){
				check = false;
			}
			if (str[i] == '\n'){
				check = false;
			}
		}
		if (!check) continue;
		
		for (int i = n - 1; i >= 0; i--){
			printf("%c", str[i]);
		}
		printf("\n");
	}
	_getch();
}
void setlastch(int n, char chr){
	int i;
	s.pop_back();
	s = chr + s;
	if (mp.count(s) == 0){
		mp[s] = 1;
	}
	else{
		mp[s]++;
	}
}
