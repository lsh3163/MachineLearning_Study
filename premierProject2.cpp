#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<conio.h>
#pragma warning(disable:4996)
using namespace std;
class Neuron{
public:
	//weight of one input
	double w_;
	//bias of one input ->여러개여도 하나
	double b_;
	//saved for back-prop
	double input_, output_;
public://behaviors
	void print(const double &x){
		printf("Hypothesis is %lf %lf\n", x, w_*x + b_);
	}
	double getAct(const double &s)
	{
		//for linear or identity activation functions
		return s;
		//for ReLU
		//return max(s, 0.0);
	}
	double getActGrad(const double &x)
	{
		//linear
		return 1.0;
		//ReLU if(x<0.0) return 0.0
	}
	void propBackward(const double& target)
	{
		const double alpha = 0.1; //learning rate
		const double grad = (output_ - target) * getActGrad(output_);

		w_ -= alpha * grad * input_; //last input_
		b_ -= alpha * grad * 1.0;
	}
	double feedForward(const double &_input){
		//output y = f(\sigma) = f(w_*input + b_)
		//for mutliple inputs;
		//\sigma = w0_ * x0 + w1_ * x1 + ... + b
		input_ = _input;
		const double sigma = w_ * input_ + b_;
		output_ = getAct(sigma);
		return output_;
	}
	void feedForwardAndPrint(const double& input){
		printf("%lf %lf \n", input, feedForward(input));
	}
};
int main(){
	Neuron my_neuron;
	my_neuron.w_ = 2.0;
	my_neuron.b_ = 1.0;
	int cnt = 10000;
	freopen("input.txt", "r", stdin);
	double ax, by;
	vector<double> xset;
	vector<double> yset;
	for (int i = 1; i <= 20; i++){
		cin >> ax >> by;
		xset.push_back(ax);
		yset.push_back(by);
	}
	for (int i = 0; i < 20; i++){
		printf("%.2lf %.2lf\n", xset[i], yset[i]);
	}
	while (cnt--){
		for (int i = 0; i < 5; i++){
			printf("Training\n");
			my_neuron.feedForwardAndPrint(xset[i]);
			my_neuron.propBackward(yset[i]);
			printf("w = %lf b = %lf\n", my_neuron.w_, my_neuron.b_);
		}
	}
	my_neuron.print(1.0);
	my_neuron.print(10.0);
	_getch();
}
