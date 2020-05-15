/*Написать программу вычисления стоимости поездки на автомобиле на дачу (туда и обратно). Исходными данными являются:
   расстояние до дачи (км);
   количество бензина, которое потребляет автомобиль на 100 км пробега;
   цена одного литра бензина. */

#include <iostream>
#include <Windows.h> // для кириллицы
#include <string>    // для std::string

using std::cout; using std::cin; using std::endl; using std::string;

// получаем от пользователя дробное число, выводя соответствующий текст в качестве запроса
double get_number(const char* text_for_user)
{
	cout << text_for_user;
	double answer;
	cin >> answer;
	while (cin.fail() || (answer < 0))  // если вводит буквы или отрицательное число
	{
		cin.clear();
		cin.ignore(1000, '\n'); //очищаем cin
		cout << "Вы ввели нечто некорректное, введите положительное число: ";
		cin >> answer;      //снова вводит число
		continue;
	}
	return answer;
}

// считаем затраты на всю поездку:
double total_cost(const double& s, const double& petrol_consumption, const double& petrol_cost)
{
	/*	расстояние * расход бензина * цену бензина
		   расстояние умножаем на 2 т.к. смотрим поездку туда и обратно
		   чтобы получить расход бензина на 1 км, делим введённое значение на 100, так как пользователь вводил значение расхода на 100 км */
	return (2 * s * (petrol_consumption / 100) * petrol_cost);
}

// возвращает истину, если игрок хочет рассчитать затраты ещё раз и ложь, если не хочет
bool wantsContinue()
{
	cout << endl;
	cout << "Хотите рассчитать ещё раз? Нажмите 'y', если да или 'n', если нет ";
	string answer;
	cin.ignore(1000, '\n');   // очищаем cin
	std::getline(cin, answer);
	while ((answer != "y") && (answer != "n"))
	{
		cout << "Ваш ответ не понятен! Хотите рассчитать ещё раз? Нажмите 'y', если да или 'n', если нет ";
		std::getline(cin, answer);
	}
	cout << endl;
	if (answer == "y") return true;
	else return false;
}

int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251); // для ввода-вывода на кириллице

	do
	{
		// запрашиваем у пользователя данные по поездке
		double s =                                        // переменная для обозначения расстояния, как в физике
			      get_number("Расстояние до дачи (км): ");  
		double petrol_consumption =                       // переменная для обозначения расхода бензина
			      get_number("Расход бензина (литров на 100 км пробега): "); 
		double petrol_cost =                              // переменная для обозначения цены бензина
			      get_number("Цена литра бензина (руб.): "); 

		cout << "Поездка на дачу и обратно обойдётся в " << total_cost(s, petrol_consumption, petrol_cost) << " руб. " << endl;

	}
	while (wantsContinue());

	cout << "Желаем Вам приятной поездки! " << endl;
	return 0;
}