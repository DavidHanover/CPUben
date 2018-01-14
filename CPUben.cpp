#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;

/**
* Find and return the index of pivot element.
* @param a - The array.
* @param first - The start of the sequence.
* @param last - The end of the sequence.
* @return - the pivot element
*/
int pivot(int a[], int first, int last)
{
	int  p = first;
	int pivotElement = a[first];

	for (int i = first + 1; i <= last; i++)
	{
		/* If you want to sort the list in the other order, change "<=" to ">" */
		if (a[i] <= pivotElement)
		{
			p++;
			swap(a[i], a[p]);
		}
	}

	swap(a[p], a[first]);

	return p;
}

void quicksort(int a[], int first, int last)
{
	int pivotElement;

	if (first < last)
	{
		pivotElement = pivot(a, first, last);
		quicksort(a, first, pivotElement - 1);
		quicksort(a, pivotElement + 1, last);
	}
}

double DOUBLE( double t) {
	int Nfloat = 0;
	int const n = 468;
	clock_t start = clock();
	double rt = 0.0;
	{
		while (rt < t) {

			int i, j;
			bool s = true;
			float mat[n][n];
			float cop[n][n];

			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (i == j) {
						mat[i][j] = 2.00010;
						cop[i][j] = 2.00010;

					}
					else {
						mat[i][j] = 1.00010;
						cop[i][j] = 1.00010;
					}
				}
			}

			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					mat[i][j] = pow(mat[i][j], -1.0);
					//cout << "";
				}
			}

			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					mat[i][j] = pow(mat[i][j], -1.0);
					//cout << "";
				}
			}

			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (s == false) { break; }
					if (mat[i][j] != cop[i][j]) {
						s = false;
						break;
					}
				}
				if (s == false) {
					break;
				}
			}

			if (s == true) { Nfloat++; }


			rt = (std::clock() - start) / CLOCKS_PER_SEC;

		}
	}
	return ((double)Nfloat / rt)*60.0;
}


double INTEGER(double t) {
	clock_t start = clock();
	double rt = 0.0;
	const int n = 3460;
	const int n1 = n / 10;
	int Nint = 0;
	{
		int sor[n];
		int i, j;


		// Pre-Sorted Array to compare to
		// NOTE: you can put this before the time loop to save cpu
		int num = 1; j = 0;
		for (i = 0; i < n; i++) {
			sor[i] = num;
			j++; if (j == n1) { j = 0; num++; }
		}

		while (rt < t) {
			bool s = true;
			int arr[n];


			// Evenly distributed Array to sort
			j = 1;
			for (i = 0; i <= n - 1; i++) {
				arr[i] = j;
				j++;
				if (j == 11) { j = 1; }
			}

			//cout << endl << endl;
			//cout << "arr is: " << endl;
			//for (i = 0; i < n; i++) { cout << arr[i] << ' '; }
			//cout << endl << endl;;
			//cout << "sor is: " << endl;
			//for (i = 0; i < n; i++) { cout << sor[i] << ' '; }
			//cout << endl << endl;;
			//quicksort(arr, 0, n - 1);
			//cout << "sorted arr is :" << endl;
			//for (i = 0; i < n; i++) { cout << arr[i] << ' '; }



			quicksort(arr, 0, n - 1);


			for (i = 0; i < n; i++) {
				if (arr[i] != sor[i]) { s = false; break; }
			}

			if (s == true) { Nint++; }


			rt = (std::clock() - start) / CLOCKS_PER_SEC;
		}
	}
	return ((double)Nint / rt) * 60.0;
}

int main()
{	double tim = 10.0;

	clock_t t;
	t = clock();
	double poo = 0;
	double pee = 0;
	double puk = 0;
	poo = DOUBLE(tim);
	cout << "NFLOAT is: " << poo << endl;
	pee = INTEGER(tim);

	puk = 2 / ((1 /poo) + (1 /pee));

	cout << "NINT is: " << pee << endl; 
	cout << "NPROC is: " << puk << endl;

	t = clock() - t;
	cout << "this took " << (float)t/CLOCKS_PER_SEC << " seconds"<<endl;
	getchar();
    return 0;
}

