#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include <vector>


using namespace std;
string repeat;

double check_input(char in)															
{
	double in_value;
	cin >> in_value;
	if (in == 'x')
	{
		while ((cin.fail()) || (cin.peek() != '\n'))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Wrong type of input data, try again: "; cin >> in_value;
			cout << endl;
		}
	}
	if (in == 'a')
	{
		while ((cin.fail()) || (cin.peek() != '\n') || in_value < 0)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Wrong type of input data, try again: "; cin >> in_value;
			cout << endl;
		}
	}
	return in_value;
}

long long fact(int i) 
{
	if (i <= 1) return 1;
	else return i * fact(i - 1);
}

long double a_n(double N_to_function,double x_to_function)
{
	long double to_out;
	to_out = (pow(2, N_to_function / 2) * sin((M_PI * N_to_function) / 4) * pow(x_to_function, N_to_function)) / fact(N_to_function);
	return to_out;
}

string repeat_check()
{
	cout << "\nRepeat? (Y/N) " << endl;
	cin >> repeat;
	while (((repeat == "Y") || (repeat == "y") || (repeat == "N") || (repeat == "n")) != 1 || (cin.peek() != '\n'))
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Unidentified operator, try again" << endl;
		cout << "Repeat? (Y/N) " << endl;
		cin >> repeat;
		cout << endl;
	}
	return repeat;
}

int main()
{
	
	double x_prev = NAN;
	double a_prev = NAN;
	vector<long double> elements;
	vector<long double> S_elements;
	vector<long double> accs;
	long double an;
	double x, a;
	bool try_repeat;


	while(repeat != "N" && repeat != "n")
	{
		int n = 0;
		
		long double acc;


		cout << "Enter parameter x: "; x = check_input('x');
		if(x != x_prev)
		{
			try_repeat = false;
			x_prev = x;
			elements.clear();
			S_elements.clear();
			accs.clear();
		}
		
		cout << "Enter parameter alpha: "; a = check_input('a');
		if (a != a_prev)
		{
			a_prev = a;
			try_repeat = false;
		}
		else
		{
			try_repeat = true;
		}
		cout << endl;
		

		if (a - int(a) == 0.0) 
		{
			long double S=0;
			long double an;
	

			a = int(a);

			if (elements.size() == 0)
			{
				for (n = 0; n <= a-1; n++)
				{
					an = a_n(n, x);
					elements.push_back(an);
					S = S + an;
					S_elements.push_back(S);
					acc = abs(a_n(x, n + 1) / S);
					accs.push_back(acc);
					if (acc == INFINITY) {cout << "Iteration number :" << n << endl << "Last a: " << an << endl << "Current amount: " << S << endl << "Current accuraton: " << "Undefined" << endl;}
					else {cout << "Iteration number :" << n << endl << "Last a: " << an << endl << "Current amount: " << S << endl << "Current accuraton: " << acc << endl;}
					cout << endl;
				}
				repeat = repeat_check();
			}
			else
			{	
				if (a <= S_elements.size())
				{
					for (n = 0; n <= a-1; n++)
					{
						cout << "Iteration number :" << n << endl << "Last a: " << elements[n] << endl << "Current amount: " << S_elements[n] << accs[n] << endl;
						cout << endl;
						
					}
					repeat = repeat_check();
				}
				else
				{
					n = 0;
					for (n = 0; n <= elements.size()-1; n++)
					{
						cout << "Iteration number :" << n << endl << "Last a: " << elements[n] << endl << "Current amount: " << S_elements[n] << endl << "Current accuraton: " <<  accs[n] << endl;
						cout << endl;
					}
					for (n; n <= a-1; n++)
					{
						an = a_n(n, x);
						elements.push_back(an);
						S = S + an;
						S_elements.push_back(S);
						acc = abs(a_n(x, n + 1) / S);
						accs.push_back(acc);
						cout << "Iteration number :" << n << endl << "Last a: " << an << endl << "Current amount: " << S << endl << "Current accuraton: " << acc << endl;
						cout << endl;
						
					}
					repeat = repeat_check();
				}
			}
		}
		else
		{
			if(elements.size() == 0)
			{
				do
				{
					long double an;
					long double S = 0;
					an = a_n(n, x);
					S = S + an;
					acc = abs(a_n(n + 1, x) / S);
					elements.push_back(an);
					S_elements.push_back(S);
					if (acc != INFINITY) 
					{
						accs.push_back(acc);
					}
					cout << "Iteration number :" << n << endl << "Last a: " << an << endl << "Current amount: " << S << endl << "Current accuraton: " << acc << endl;
					cout << endl;

					n += 1;
				} while (a <= acc);

				repeat = repeat_check();
			}
			else
			{
				elements.clear();
				S_elements.clear();
				accs.clear();
				do
				{
					long double an;
					long double S = 0;
					an = a_n(n, x);
					S = S + an;
					acc = abs(a_n(n + 1, x) / S);
					elements.push_back(an);
					S_elements.push_back(S);
					if (acc != INFINITY)
					{
						accs.push_back(acc);
					}
					cout << "Iteration number :" << n << endl << "Last a: " << an << endl << "Current amount: " << S << endl << "Current accuraton: " << acc << endl;
					cout << endl;

					n += 1;
				} while (a <= acc);

				repeat = repeat_check();
			}
		}
	}
}
