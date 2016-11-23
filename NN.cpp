#include <iostream>

// linear regression < deep learning < machine learning
class Neuron
{
public:
	// linear hypothesis : y = a * x + b
	float a_ = 0.0f;
	float b_ = 0.0f;

	float dy_dx_temp_, dy_da_temp_;

	float getY(const float& x_input)
	{
		// gradients for back-prop
		dy_dx_temp_ = a_;
		dy_da_temp_ = x_input;

		return a_ * x_input + b_; // returns y = a*x+b
	}

	void backprop(const float& error, const float& lr = 0.1)
	{
		const float dse_over_da = error * dy_da_temp_;
		const float dse_over_db = error * 1.0f;

		a_ -= dse_over_da * lr;
		b_ -= dse_over_db * lr;
	}
};

const int num_data = 5;

int main()
{
	const float x_input_data[num_data] = { 0.1, 0.2, 0.3, 0.4, 0.5 };
	const float y_target_data[num_data] = { 4, 5, 6, 7, 8 };

	Neuron neu0, neu1;

	for (int tr = 0; tr < 100000; tr++)
	for (int i = 0; i < num_data; i++)
	{
		const float x_input = x_input_data[i];
		const float y_output = neu1.getY(neu0.getY(x_input));
		const float y_target = y_target_data[i];
		const float error = y_output - y_target;
		const float sqr_error = 0.5 * error * error;

		neu1.backprop(error, 0.01);
		neu0.backprop(error, 0.01);
	}

	std::cout << "From trained NN " << std::endl;

	for (int i = 0; i < num_data; i++)
		std::cout << neu1.getY(neu0.getY(x_input_data[i])) << std::endl;

	return 0;
}
