#include <iostream>
#include <cstdlib>
#include <ctime>

void arr_add(int*& arr, int length, int num) {
	if (num <= 0)
		return;
	int* tmp = new int[length + num]{};
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;


	//Динамическа память 
	int* pointer = new int; // Направление указателя на произвольный участок динамической памяти размеров в 4 байта ( т.к. int).
	*pointer = 15; // Запись в динамическую память числа 15.
	std::cout << "pointer = " << pointer << std::endl;
	std::cout << "*pointer = " << *pointer << std::endl;

	delete pointer; // Освобождение ( очистка) области динамической памяи на которую направлен указатель. Необходитмо во избежание утечки памяти.

	pointer = new int; // Выделение нового участка динамической памяти.
	std::cout << "pointer = " << pointer << std::endl;
	*pointer = 7;
	std::cout << "*pointer = " << *pointer << std::endl;

	//Утечка памяти - явление в ходе которого программа не может освободить выделенные ранее участки динамической памяти. Возникает из-за неправильного использования указателей.
	
	delete pointer;

	//Динамические массивы 

	std::cout << "Введите размер массива -> ";
	int size;
	std::cin >> size;

	int* d_arr = new int[size]; // Выделние динамической памяти под массив 

	std::cout << "Ввод массива:\n";
	for (int i = 0; i < size; i++) {
		std::cout << "Введите " << i + 1 << " -й элемент -> ";
		std::cin >> d_arr[i];

	}
	std::cout << "Итоговый массив:\n";
	for (int i = 0; i < size; i++)
		std::cout << d_arr[i] << ' ';
	std::cout << std::endl;

	delete[] d_arr;// освобождение памяти под массив 

	// Отличия Статических  от Динамических 
	// 1. Размер динамического массива может быть определён на этапе выполнения программы;
	// 2. С помощью спец. конструкций размер динамичского массива может быть изменён;
	// 3. При работе с динамическим массивом необходимо следить за освобождением памяти;
	// 4. Работа со статическим массивом происходит гораздо быстрей; 
	// 5. Выделение памяти для хранения массивов с большим кол-ом изменений, чем 1, является сложным и долгим процссом с точки зрения написания кода.

	// Двухмерный динамичесикй массив.

	int rows, cols;
	std::cout << "Введите размер двухмерного массива -> ";
	std::cin >> rows;
	std::cin >> cols;
	//int* mx = new int[rows][cols]; // не работает 
	int** mx = new int* [rows];
	for (int i = 0; i < rows; i++)
		mx[i] = new int[cols];

	// Использование массива точно такое же, как и у статического.


	//Освобождение памяти. 
	for (int i = 0; i < rows; i++)
		delete[] mx[i];
	delete[] mx;

	// Задача 1. Увелечение массива. 
	std::cout << "Задача 1.\nВведите значение массива -> ";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	srand(time(NULL));
	std::cout << "Изначальный массив:\n[";
	for (int i = 0; i < size1; i++) {
		arr1[i] = rand() % 11 + 10; //[10..20]
		std::cout << arr1[i] << ", ";
	}
	std::cout << "\b\b]\nВведите кол-во новых элементов -> ";
	std::cin >> n;

	arr_add(arr1, size1, n);
	size1 += n;
	
	std::cout << "Итоговый массив:\n[";
	for (int i = 0; i < size1; i++)
		std::cout << arr1[i] << ", ";
	std::cout << "\b\b]\n";



	return 0;
}