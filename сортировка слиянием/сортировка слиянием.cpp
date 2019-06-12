
#include <iostream>
#include <vector>

using namespace std;

void  mergeSort(vector<int>& a, size_t start, size_t end)//функция сортировки слиянием
{
	if (end - start < 2)//проверка, если элементов меньше 2 в массиве, выводим тот элемент, который есть.
		return;
	if (end - start == 2)//проверка, если элементов 2 в массиве, то меняем в нужном порядке и выводим
	{
		if (a[start] > a[start + 1])
			swap(a[start], a[start + 1]);
		return;
	}
	mergeSort(a, start, start + (end - start) / 2);//делим массив на 2 части
	mergeSort(a, start + (end - start) / 2, end);

	vector<int> b;
	size_t b1 = start;
	size_t e1 = start + (end - start) / 2;
	size_t b2 = e1;
	while (b.size() < end - start)//условие, проверка размерности
	{
		if (b1 >= e1 || (b2 < end && a[b2] <= a[b1]))//сравнение элементов
		{
			b.push_back(a[b2]);//вставка в массив
			++b2;
		}
		else
		{
			b.push_back(a[b1]);
			++b1;
		}
	}
	for (size_t i = start; i < end; ++i)
		a[i] = b[i - start];//вывод на экран
}



int main()
{
	setlocale(LC_ALL, "RUS");//подключение русского языка
	int size;
	cout << "Размерность" << endl;
	cin >> size;
	vector<int> v;//наш вектор, который является массивом
	for (int i = 0; i < size; ++i)//вставляем элементы
		v.push_back(i);//вставляем числа от 0 до 20
	for (size_t i = 0; i < v.size(); ++i)
		swap(v[i], v[rand() % (v.size() - i) + i]);//перемешиваем
	for (auto i : v)
		cout << i << " ";//выводим на экран все элементы
	cout << endl;
	cout << " Если нужно от min до max, то h=1. Если нужно от max до min, то h=0." << endl;
	int h;
	cout << "Введите h." << endl;
	cin >> h;
	if (h == 1) {
		mergeSort(v, 0, v.size());
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}
	if (h == 0) {
		mergeSort(v, 0, v.size());
		reverse(v.begin(), v.end());//переворот
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}
}

