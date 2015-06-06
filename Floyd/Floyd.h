#pragma once

#include <stdlib.h>
#include <time.h>
#include <ostream>
#include <iomanip>



/*
in W , -1 means unlimit
*/

class Floyd
{
public:

	Floyd(int ** wIn , int len)
	{
		Len = len;
		
		//mikhahim andis ha az 1 shoroo beshe , pas dar sakhte araye 1 vahed be har taraf ezafe midim
		w = new int *[len+1];
		p = new int *[len + 1];
		d = new int *[len + 1];

		for (int i = 1; i < len + 1; i++)
		{
			w[i] = new int[len + 1];
			d[i] = new int[len + 1];
			p[i] = new int[len + 1];
		}
			

		for (int i = 1; i <= len; i++)
			for (int j = 1; j <= len; j++)
				w[i][j] = wIn[i-1][j-1];//-1 ha vase ine ke araye birooni az 0 index hash shoroo mishe
		
	}
	Floyd(int len , int maxRandom)
	{
		Len = len;

		//mikhahim andis ha az 1 shoroo beshe , pas dar sakhte araye 1 vahed be har taraf ezafe midim
		w = new int *[len + 1];
		p = new int *[len + 1];
		d = new int *[len + 1];

		for (int i = 1; i < len + 1; i++)
		{
			w[i] = new int[len + 1];
			d[i] = new int[len + 1];
			p[i] = new int[len + 1];
		}

		for (int i = 1; i <= len; i++)
			for (int j = 1; j <= len; j++)
			{
				if (i == j)
					w[i][j] = 0;
				else
				{
					srand(time(0) + (i + j * 15) + rand() % 50);
					//vazn nabayad 0 beshe , age random 0 shod taghiresh midim be -1 ke bi nahayat bashe
					w[i][j] = rand() % maxRandom;
					if (w[i][j] == 0)
						w[i][j] = -1;
				}
			}
	}


	~Floyd()
	{
		delete[] w;
		delete[] p;
		delete[] d;
	}

	void calculate()
	{
		for (int i = 1; i <= Len; i++)
			for (int j = 1; j <= Len; j++)
			{
				p[i][j] = 0;
				d[i][j] = w[i][j]; /// D0 = W
			}
		for (int k = 1 ; k<=Len ; k++)
			for (int i = 1; i <= Len; i++)
				for (int j = 1; j <= Len; j++)
				{
					int sum = add(d[i][k] , d[k][j]);
					if (isSmaller(sum, d[i][j]))
					{
						p[i][j] = k;
						d[i][j] = sum;
					}
				}
	}

	std::ostream & wPrinter(std::ostream& os)
	{
		os << "W:\n    ";

		for (int i = 1; i <= Len; i++)
			os << std::left << std::setw(5) << i;
		

		os << "\n   " << (char)218 << (char)196 << (char)196 << (char)196;
		for (int i = 1; i < Len; i++)
			os << (char)196 << (char)196 << (char)196 << (char)196 << (char)196;
		
		os << "\n";

		for (int i = 1; i <= Len; i++)
		{
			os << std::right << std::setw(3) << i<<(char)179;
			for (int j = 1; j <= Len; j++)
			{
				if (w[i][j] != -1)
					os << std::left << std::setw(5) << w[i][j];
				else
					os << std::left << std::setw(5) << (char)236;
			}
				

				os << std::endl;
		}
		return os;
			
	}

	std::ostream & dPrinter(std::ostream& os)
	{
		os << "D:\n    ";

		for (int i = 1; i <= Len; i++)
			os << std::left << std::setw(5) << i;


		os << "\n   " << (char)218 << (char)196 << (char)196 << (char)196;
		for (int i = 1; i < Len; i++)
			os << (char)196 << (char)196 << (char)196 << (char)196 << (char)196;

		os << "\n";

		for (int i = 1; i <= Len; i++)
		{
			os << std::right << std::setw(3) << i << (char)179;
			for (int j = 1; j <= Len; j++)
			{
				if (d[i][j] != -1)
					os << std::left << std::setw(5) << d[i][j];
				else
					os << std::left << std::setw(5) << (char)236;
			}

			os << std::endl;
		}
		return os;

	}

	std::ostream & pPrinter(std::ostream& os)
	{
		os << "P:\n    ";

		for (int i = 1; i <= Len; i++)
			os << std::left << std::setw(5) << i;


		os << "\n   " << (char)218 << (char)196 << (char)196 << (char)196;
		for (int i = 1; i < Len; i++)
			os << (char)196 << (char)196 << (char)196 << (char)196 << (char)196;

		os << "\n";

		for (int i = 1; i <= Len; i++)
		{
			os << std::right << std::setw(3) << i << (char)179;
			for (int j = 1; j <= Len; j++)
				os << std::left << std::setw(5) << p[i][j];

			os << std::endl;
		}
		return os;

	}

	std::ostream & path(std::ostream& os, int q, int r)
	{
		if (p[q][r] != 0)
		{
			path(os, q, p[q][r]);
			os << "V" << p[q][r];
			path(os, p[q][r], r);
		}
		return os;
	}

private:
	int ** w;
	int ** d;
	int ** p;
	int Len;


	bool isSmaller(int a, int b)
	{
		if (a == -1)
			return false;
		if (b == -1)
			return true;
		return (a<b);
	}
	int add(int a, int b)
	{
		if (a == -1 || b == -1)
			return -1;
		return a + b;
	}
};