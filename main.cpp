#include "header_main.h"
#include "MatPart\functions.h"
#include <boost/program_options.hpp>

using namespace boost::program_options;
void on_array_size_1(int number)
{
	std::cout << "On array_size_1: " << number << '\n';
}
void on_array_size_2(int number)
{
	std::cout << "On array_size_2: " << number << '\n';
}
void on_matrix_size(int number)
{
	std::cout << "On matrix_size: " << number << '\n';
}

void main(int argc, const char* argv[]) {
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int default_size = 4;
	int array_size_1 = 10, array_size_2 = 15;
	int matrix_size = 7;

	try//работа через командную строку
	{
		options_description desc{ "Options" };
		desc.add_options()
			("help,h", "Help screen")
			("array_size_1", value<int>()->notifier(on_array_size_1), "on_array_size_1")//размер векторов
			("array_size_2", value<int>()->notifier(on_array_size_2), "on_array_size_2")//размер векторов
			("matrix_size", value<int>()->notifier(on_matrix_size), "Matrix_size");//размер матриц

		variables_map vm;
		//ASPM181 --array_size_1 7 --array_size_2 3
		store(parse_command_line(argc, argv, desc), vm);
		notify(vm);
		if (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("array_size_1")) {
			std::cout << "Array_size_1: " << vm["array_size_1"].as<int>() << '\n';
			array_size_1 = vm["array_size_1"].as<int>();//записываем в наш размер значение из командной строки
		}

		if (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("array_size_2")) {
			std::cout << "Array_size_2: " << vm["array_size_2"].as<int>() << '\n';
			array_size_2 = vm["array_size_2"].as<int>();//записываем в наш размер значение из командной строки
		}

		if (vm.count("help"))
			std::cout << desc << '\n';
		else if (vm.count("matrix_size")) {
			std::cout << "Matrix_size: " << vm["matrix_size"].as<int>() << '\n';
			matrix_size = vm["matrix_size"].as<int>();//записываем в наш размер значение из командной строки
		}

	}
	catch (const error& ex)
	{
		std::cerr << ex.what() << '\n';
	}

	//сама работа с векторами и матрицами
	double* array_one = new double[array_size_1];
	double* array_second = new double[array_size_2];
	double** matrix_A = new double* [matrix_size];
	double** matrix_B = new double* [matrix_size];
	for (int i = 0; i < matrix_size; i++) {
		matrix_A[i] = new double[matrix_size];
		matrix_B[i] = new double[matrix_size];
	}

	initialization(array_one, array_second, array_size_1, array_size_2, matrix_A, matrix_B, matrix_size);
	printf("Ќачальный ¬ектор time: \n");
	output_array(array_one, array_size_1);
	printf("Ќачальный ¬ектор data: \n");
	output_array(array_second, array_size_2);
	printf("Ќачальна€ матрица time: \n");
	output_matrix(matrix_A, matrix_size);


	double* B = Vstavka(array_one, array_size_1);
	printf("¬ектор после удвоени€ числа: \n");
	output_array(B, array_size_1);

	int array_size_3 = array_size_1;
	double* B2 = Vstavka(B, array_size_1);
	printf("¬ектор после удвоени€ числа: \n");
	output_array(B2, array_size_3);
	

	B = DOB_r_t(B, array_size_1,2,32);
	printf("\n¬ектор после вставки нового элемента: \n");
	output_array(B, array_size_1);

	double O;
	Otnoshenie(B2, array_size_3, O);
	cout << "\noтношение = " << O;
	cout << endl;

	cout << endl;
	system("pause");
}


