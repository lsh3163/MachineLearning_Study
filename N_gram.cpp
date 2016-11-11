#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define N 32
#pragma warning(disable:4996)
using namespace std;
void setlastch(int n, char chr, char lastch[]);
void printngram(int n, char lastch[]);
int main(){
	freopen("alice.txt", "r", stdin);
	int n = 5;
	char lastch[N] = { ' ' };
	char chr;
	while ((chr = getchar())!=EOF){
		if (chr != '\n'){
			setlastch(n, chr, lastch);
			printngram(n, lastch);
		}
	}
	_getch();
}
void setlastch(int n, char chr, char lastch[]){
	int i;
	for (i = n - 2; i >= 0; i--){
		lastch[i + 1] = lastch[i];
	}
	lastch[0] = chr;
}
void printngram(int n, char lastch[]){
	int i;
	for (i = n - 1; i >= 0; i--){
		printf("%c", lastch[i]);
	}
	printf("\n");
}
