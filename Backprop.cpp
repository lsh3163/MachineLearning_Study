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
	//saved for back-prop
	double input_, output_;
public://behaviors
	
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
	int cnt = 100;
	while (cnt--){
		printf("Training\n");
		my_neuron.feedForwardAndPrint(1.0);
		my_neuron.propBackward(4.0);
		printf("w = %lf b = %lf\n", my_neuron.w_, my_neuron.b_);
	}
	_getch();
}
