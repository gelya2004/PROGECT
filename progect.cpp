#include <iostream>
#include "math.hpp"
using namespace std;
void Output()
{
	cout << "Press 0 to exit the programm" << endl;
	cout << "Press 1 for matrix addition" << endl;
	cout << "Press 2 for matrix subtraction" << endl;
	cout << "Press 3 for matrix multiplication" << endl;
	cout << "Press 4 for using the Gauss method" << endl;
	cout << "Press 5 for checking the dependence of vectors" << endl;
	cout << "Press 6 for finding the reverse matrix" << endl;
	cout << "Press 7 for finding the transposition matrix" << endl;
	cout << "Press 8 for findint the determinant for 2x2 or 3x3 type matrix" << endl;
	cout << "Press 9 for findint the determinant for 2x2 or 3x3 type matrix" << endl;

}

int main()
{
	int p = 0;
	int n, m;
	Output();
	cin >> p;

	while (p != 0)
	{
		if ((p > 8) && (p < 0))
		{
			Output();
		}

		if (p == 1)
		{
			cout << "The number of lines and columns of matrix A: " << endl;
			cin >> n >> m;

			Matrix A(n, m);
			cout << "Type A matrix: " << endl;
			cin >> A;

			cout << "The number of lines and columns of matrix B: " << endl;
			cin >> n >> m;

			Matrix B(n, m);
			cout << "Type B matrix: " << endl;
			cin >> B;

			cout << '\n';
			cout << A + B << endl;
			cout << '\n';

			Output();
			cin >> p;

		}

		if (p == 2)
		{
			cout << "The number of lines and columns of matrix A: " << endl;
			cin >> n >> m;

			Matrix A(n, m);
			cout << "Type A matrix: " << endl;
			cin >> A;

			cout << "The number of lines and columns of matrix B: " << endl;
			cin >> n >> m;

			Matrix B(n, m);
			cout << "Type B matrix: " << endl;
			cin >> B;

			cout << '\n';
			cout << A - B << endl;
			cout << '\n';

			Output();
			cin >> p;
		}

		if (p == 3)
		{
			cout << "The number of lines and columns of matrix A: " << endl;
			cin >> n >> m;

			Matrix A(n, m);
			cout << "Type A matrix: " << endl;
			cin >> A;

			cout << "The number of lines and columns of matrix B: " << endl;
			cin >> n >> m;

			Matrix B(n, m);
			cout << "Type B matrix: " << endl;
			cin >> B;

			cout << '\n';
			cout << A * B << endl;
			cout << '\n';

			Output();
			cin >> p;
		}

		if (p == 4)
		{
			cout << "The number of equations: " << endl;
			cin >> n;

			Matrix A(n, n);
			Matrix B(n, 1);

			cout << "Type the coefficients: " << endl;
			cin >> A;

			cout << "Type the free terms: " << endl;
			cin >> B;

			cout << '\n';
			A% B;
			cout << '\n';

			Output();
			cin >> p;
		}

		if (p == 5)
		{
			cout << "Type three vectors: " << endl;

			Matrix A(3, 3);
			cin >> A;

			cout << '\n';
			A.linear_dependence();
			cout << '\n';

			Output();
			cin >> p;
		}

		if (p == 6)
		{
			cout << "The number of lines and columns of matrix A: " << endl;
			cin >> n >> m;

			Matrix A(n, m);
			cout << "Type A matrix: " << endl;
			cin >> A;

			cout << '\n';
			cout << A.reverse();
			cout << '\n';

			Output();
			cin >> p;
		}

		if (p == 7)
		{
			cout << "The number of lines and columns of matrix A: " << endl;
			cin >> n >> m;

			Matrix A(n, m);
			cout << "Type A matrix: " << endl;
			cin >> A;

			cout << '\n';
			cout << A.transposition();
			cout << '\n';

			Output();
			cin >> p;
		}


		if (p == 9)
		{
			cout << "The number of lines and columns of matrix A up to matrix 3x3: " << endl;
			cin >> n >> m;

			Matrix A(n, m);
			cout << "Type A matrix: " << endl;
			cin >> A;

			cout << '\n';
			cout << A.Rang();
			cout << '\n';

			Output();
			cin >> p;
		}
	}
	return 0;
}