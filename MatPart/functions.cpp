#include "functions.h"

//добавлениe элемента с индексом r и значеним t
double* DOB_r_t(double* a, int& n, int r, double t)
{
	double* b;
	n++;
	b = new double[n];
	int i = 0;
	if (r > 0) {
		for (; i < r; i++)
			b[i] = a[i];
	}
	b[r] = t;	
	for (i = r + 1; i < n; i++)
		b[i] = a[i - 1];
	//delete[] a;
	a = new double[n];
	for (i = 0; i < n; i++) {
		a[i] = b[i];
		cout << a[i] <<"   ";
	}
	delete[] b;
	return a;
}
//За каждым элементом с заданным значением вставить его дубликат.
double* Vstavka(double* a, int& n)
{
	double z;
	int m = 0;
	cout << "\nВведите значение:";
	cin >> z;
	double* b;
	b = new double[n + 1];
	if (b == NULL)
	{
		cout << "\nНе хватило ОП";
		exit(1);
	}
	for (int i = 0; i < n+m; i++)
	{
		if (a[i] == z)
		{
			int j = 0;
			for (j = 0; j <= i; j++)
				b[j] = a[j];
			b[j] = z;
			for (int j = i + 2; j < n + 1; j++)
				b[j] = a[j - 1];
			n++;
			delete[] a;
			a = new double[n + 1];
			for (int i = 0; i < n; i++)
				a[i] = b[i];
			i+=1;
			m++;
		}
	}
	delete[] b;
	return(a);
}
//За каждым элементом с заданным значением вставить его дубликат (ввод не с клавиатуры)
double* Vstavka(double* a, int& n, double z)
{
	int m = 0;	
	for (int i = 0; i < n + m; i++)
	{
		double* b;
		b = new double[n + m + 1];
		if (a[i] == z)
		{
			int j = 0;
			for (j = 0; j <= i; j++)
				b[j] = a[j];
			b[j] = z;
			for (int j = i + 2; j < n + 1; j++)
				b[j] = a[j - 1];
			n++;
			//delete[] a;
			m++;
			a = new double[n + m];
			for (int i = 0; i < n; i++)
				a[i] = b[i];
			i += 1;			
		}
		delete[] b;
	}	
	return(a);
}

//определить отношение суммы элементов массива, расположенных до последнего 
// из максимальных элементов в массиве , если он не единственный, к произведению элементов,
// расположенных после максимального.
void Otnoshenie(double* a, int n, double& O) {
	double max = a[0], k;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == max)
			k = i;
	}
	double s1 = 0, s2 = 0;
	for (int i = 0; i < k; i++) {
		s1 = s1 + a[i];
	}
	for (int i = k + 1; i < n; i++) {
		s2 = s2 + a[i];
	}
	O = s1 / s2;
}