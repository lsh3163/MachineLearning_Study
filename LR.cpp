#include<stdio.h>
#include<iostream>
#include<conio.h>
using namespace std;
class LinearHypothesis{
public:
	float a, b;
	float getH(const float input){
		//linear hypothesis
		return a * input + b;
	}
	float getHa(const float input){
		return input;
	}
	float getHb(const float input){
		return 1.0f;
	}
};
class Example{
public:
	float time;
	float score;

};
#define num_exam 2
int main(){
	Example ex_list[num_exam];
	ex_list[0].time = 0.0;
	ex_list[0].score = 0.0;

	ex_list[1].time = 1.0;
	ex_list[1].score = 1.0;

	LinearHypothesis lh_;
	lh_.a = 0.0f;
	lh_.b = 0.0f;
	const float alpha = 0.001;
	//stochastic gradient descent
	for (int e = 0; e < num_exam; e++){
		//train 
		const float error = lh_.getH(ex_list[e].time) - ex_list[e].score;
		lh_.a -= error * alpha * lh_.getHa(ex_list[e].time);
		lh_.b -= error * alpha * lh_.getHb(ex_list[e].time);
		cout << "Expected = " << lh_.getH(ex_list[e].time) << "Example = " << ex_list[e].score<<endl;
	}

	_getch();
}
