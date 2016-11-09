#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
class Neuron{
public:
	//weight of one input
	double w;
	//bias of one input ->여러개여도 하나
	double b;
	//saved for back-prop
	double input_, output_;
public://behaviors
	void print(double x){
		printf("Hypothesis is %.2lf %.2lf\n", x, w*x + b);
	}
	double Hypothesis(double &x){
		return w*x + b;
	}
	double getAct(double &s)
	{
		//for linear or identity activation functions
		return s;
	}
	double getActGrad(double &x)
	{
		//linear
		return 1.0;
	}
	void propBackward(double& target)
	{
		double alpha = 0.001; //learning rate
		double grad = (output_ - target) * getActGrad(output_);

		w -= alpha * grad * input_; //last input_
		b -= alpha * grad;
	}
	double feedForward(double &x){
		//output y = f(\sigma) = f(w_*input + b_)
		input_ = x;
		double sigma = w * input_ + b;
		output_ = getAct(sigma);
		return output_;
	}
	void feedForwardAndPrint(double& input){
		printf("%lf %lf \n", input, feedForward(input));
	}
};
int main(){
	Neuron my_neuron;
	my_neuron.w = 2.0;
	my_neuron.b = 1.0;
	int cnt = 10000;
	freopen("input2.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
	double ax, by;
	vector<double> xset;
	vector<double> yset;
	for (int i = 1; i <= 20; i++){
		scanf("%lf %lf", &ax, &by);
		xset.push_back(ax);
		yset.push_back(by);
	}
	for (int i = 0; i < 20; i++){
		printf("Rank %.2lf is point %.2lf\n", xset[i], yset[i]);
	}
	while (cnt--){
		for (int i = 0; i < 20; i++){
			//printf("Training\n");
			//my_neuron.feedForwardAndPrint(xset[i]);
			my_neuron.feedForward(xset[i]);
			my_neuron.propBackward(yset[i]);
			//printf("w = %lf b = %lf\n", my_neuron.w_, my_neuron.b_);
		}
	}
	for (int i = 1; i <= 20; i++){
		my_neuron.print((double)i);
	}

}
