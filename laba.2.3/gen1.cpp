#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string>
#include<ctime>
#include<fstream>
#include<algorithm>
using namespace std;



int transform(FILE* file) {
	char ch[10];
	string ch1;
	int i = 0;
	while (!(feof(file))) {
		/*Пока с файла считывается*/
			if ((ch[i] = fgetc(file)) == ' ') { ch[i + 1] = '\0'; break; }//Если равно пробелу я их убираю	
		i++;//Каждый проход по циклу считаю  
	}
	//Сколько срочек он сосчитал столько раз и прохожу, чтобы записать все что было в CHAR в STRING  
	//Также что бы все числа в строчке в доке записать.
	for (int j = 0; j < i; j++) {
		ch1 += ch[j];
	}
	//stoi - вроде как преобразовывает из string в int
	return stoi(ch1);
}



int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//1 Задание

	FILE* file = nullptr; //Объявляю переменную файла
	fopen_s(&file, "test.txt", "r");//Открываю файл, таким способом он считывает посимвольно
	int N = transform(file); //Считываю первое число
	int* mas = new int[N], i = 0, sort;

	for (int i = 0; i < N; i++) {//В этом цикле преобразовываю все числа в int
		mas[i] = transform(file);
		cout << mas[i] << " - Element" << endl;
	}

	cout << "------------------------------------------" << endl;

	for (int i = 0; i < N; i++) {//Цикл сортировки пузырьком, если интересно почитай, тут трудно объяснить будет)
		for (int j = N; j >= i + 1; j--) {
			if (mas[i] < mas[i - 1]) {
				sort = mas[i];
				mas[i] = mas[i - 1];
				mas[i - 1] = sort;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << mas[i] << " - sorted" << endl;
	}
	fclose(file);//Обяз надо файл закрыть

	FILE* file1 = nullptr;
	fopen_s(&file1, "test1.txt", "w");
	for (int i = 0; i < N; i++) {//Записываю в новый файл
		fprintf(file, "%d", mas[i]);
	}
	fclose(file1);
}