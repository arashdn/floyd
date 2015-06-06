#include <iostream>
#include "Floyd.h"
using namespace std;



int main()
{
	cout << "Do you want to Enter numbers manullay or random?\n1.Manuall\n2.Random\n";
	int c;
	cin >> c;

	Floyd * f;
	if (c == 1)
	{
		int n;
		int ** a;
		cout << "Matrix len?";
		cin >> n;
		a = new int*[n];
		for (int i = 0; i < n; i++)
			a[i] = new int[n];

		cout << "Enter -1 for " << (char)236 << endl;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cout << "Enter W[" << i + 1 << "][" << j + 1 << "]: ";
				cin >> a[i][j];
			}

		f = new Floyd(a, n);
	}
	else
	{
		int a , n;
		cout << "Matrix len?";
		cin >> n;
		cout << "Max Value for random numbers?";
		cin >> a;
		f = new Floyd(n, a);
	}

	
	f->wPrinter(cout);
	cout << "\nCalculate...\n";
	f->calculate();
	f->dPrinter(cout);
	cout << "\n";
	f->pPrinter(cout);

	cout << "\n--------------------------------\n";

	int q, r = 1;
	while (r > 0)
	{
		cout << "\nEnter two node number to find path:(Enter r as 0 to exit)\nVq:";
		cin >> q;
		cout << "Vr:";
		cin >> r;
		if (r > 0)
		{
			f->path(cout, q, r);
		}
	}

	/*cin.ignore();
	cin.get();*/
	return 0;
}