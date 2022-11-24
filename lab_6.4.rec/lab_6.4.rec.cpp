#include <iostream>
#include <time.h>

using namespace std;

void Create(double*& a,  int n, int i)
{
	a[i] = -100. + rand() * (100. + 100.) / RAND_MAX;
	if (i < n - 1)
		Create(a, n, i + 1);

}

void Print(double*& a, int n, int i)
{
	cout << a[i] << " , ";
	if (i < n - 1)

		Print(a, n, i + 1);
	else

		return;
}

double Product(double*& a, int n, double p, int i)
{
	if (a[i] < 0)
	{
		p *= a[i];
	}
	if (i < n - 1)
		return Product(a, n, p, i + 1);
	else
		return p;

}

void Inverse(double*& a, int n, int i)
{
	double tmp = a[i];
	a[i] = a[n - 1 - i];
	a[n - 1 - i] = tmp;
	if (i < n / 2 - 1)
		Inverse(a, n, i + 1);
}

void Print_Inverse(double*& a, int n, int i)
{
	cout << a[i] << " , ";
	if (i < n - 1)

		Print(a, n, i + 1);
	else

		return;
}

int main()
{
	srand((unsigned)time(NULL));
    int n;
	cout << "n = "; cin >> n;
	double* a = new double[n];
	Create(a, n, 0);
	cout << "a {"; Print(a, n, 0); cout << "}" << endl;
	cout << "1.1) P = " << Product(a, n, 1., 0) << endl;
	Inverse(a, n, 0);
	cout << "2) Inverse a{"; Print_Inverse(a, n, 0); cout << "}" << endl;

	delete[]a;
}
