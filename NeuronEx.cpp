#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<conio.h>
using namespace std;
class Neuron{
public:
	//weight of one input
	double w_;
	//bias of one input ->여러개여도 하나
	double b_;
	double act(const double &s){
		//for linear or identity activation functions
		return s;
		//for ReLU
		//return max(s, 0.0);
	}
	double feedForward(const double &input){
		//output y = f(\sigma) = f(w_*input + b_)
		//for mutliple inputs;
		//\sigma = w0_ * x0 + w1_ * x1 + ... + b

		const double sigma = w_ * input + b_;
		return act(sigma);
	}
};
int main(){
	Neuron my_neuron;
	my_neuron.w_ = 2.0;
	my_neuron.b_ = 1.0;
	printf("INput 1.0");
	printf("%lf\n",my_neuron.feedForward(1.0));
	printf("INput 2.0");
	printf("%lf\n", my_neuron.feedForward(2.0));
	printf("INput 3.0");
	printf("%lf\n", my_neuron.feedForward(3.0));
	_getch();
}
