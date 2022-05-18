//
//#include<iostream>
//#include<cstring>
//#include <Windows.h>
//#include <fstream>
//using namespace std;
//
//struct kino {
//	kino* next;
//	kino* prev;
//	string name;
//	string time;
//	int price;
//	int people;
//};
//
//void addInEnd(kino*& begin, string name, string time, int price, int people) {
//	kino* temp = new kino;
//	temp->name = name;
//	temp->time = time;
//	temp->price = price;
//	temp->people = people;
//	temp->next = NULL;
//	temp->prev = NULL;
//
//	if (begin) { // если список не пустой
//		kino* ptr = begin;
//		// ищем конец списка
//		while (ptr->next != NULL) {
//			ptr = ptr->next;
//		}
//		ptr->next = temp; // новый элемент в конец
//		temp->prev = ptr;
//	}
//	else // если список пустой
//		begin = temp; // новый первый элемент
//}
//void output(kino* ptr) {
//	cout << "-------------------------------------------------" << endl;
//	cout << "|";
//
//	cout.width(19);
//	cout << "Фильм";
//
//	cout << "|";
//	cout.width(5);
//	cout << "Время";
//
//	cout << "|";
//	cout.width(5);
//	cout << "Цена";
//
//	cout << "|";
//	cout.width(5);
//	cout << "Зрители";
//
//	cout << "|";
//
//	cout << endl;
//	cout << "-------------------------------------------------" << endl;
//	while (ptr != NULL) {
//
//		cout << "|";
//		cout.width(19);
//		cout << ptr->name;
//
//		cout << "|";
//
//		cout.width(10);
//		cout << ptr->time;
//
//		cout << "|";
//
//		cout.width(16);
//		cout << ptr->price;
//
//		cout << "|";
//
//		cout.width(7);
//		cout << ptr->people;
//		cout << "|";
//
//		cout << endl;
//		cout << "-------------------------------------------------" << endl;
//		ptr = ptr->next;
//	}
//}
//void edit(kino*& ptr, string N, string new_name, string new_time, int new_price, int new_people) {
//
//	while (ptr != NULL) {
//		if (ptr->name == N) {
//			ptr->name = new_name;
//			ptr->time = new_time;
//			ptr->price = new_price;
//			ptr->people = new_people;
//			break;
//		}
//		ptr = ptr->next;
//	}
//	cout << "Информация изменена" << endl;
//}
//void del(kino*& begin, string N) {
//	kino* ptr = begin; // текущий элемент
//	kino* prev = NULL; // предыдущий элемент
//	while (ptr != NULL) {//Тоже условие поиска
//		if (ptr->name == N) { // найден элемент, который нужно удалить
//			if (prev) { // есть предыдущий элемент
//				kino* temp = ptr;
//				prev->next = ptr->next;
//			}
//			else { // нет предыдущего элемента
//				begin = ptr->next;
//				delete ptr;
//			}
//		}
//		prev = ptr;//Инфа о предыдущем элементе 
//		ptr = ptr->next;
//	}
//	cout << "Фильм удален" << endl;
//}
//void find(kino*& ptr, string N)
//{
//	kino* next = new kino;
//	int k = 0;
//	while (ptr != NULL) {
//		if (ptr->name == N) {
//			k++;
//			cout << "movie " << ptr->name << " is found" << endl;
//			cout << "Время:" << ptr->time << "\n" << "Цена:" << ptr->price << endl;
//			break;
//		}
//		else
//			ptr = ptr->next;
//	}
//	if (k == 0)
//		cout << "this movie is not found" << endl;
//}
//
//int main() {
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	kino* head = NULL;
//	kino* end = head;
//	kino* ptr = head;
//
//	string file, file_name;
//	ifstream in; ofstream save;
//
//	string name;
//	string time;
//	int price;
//	int people;
//
//	for (;;) {
//		int a;
//
//		cout << "1: Добавить новую строку." "\n"
//			"2: Изменить данные." "\n"
//			"3: Вывести все данные и среднее количество зрителей" "\n"
//			"4: Удалить выбранный элемент." "\n"
//			"5: Поиск фильма" "\n"
//			"6: Сохранить в файл" "\n"
//			"7: Вывести из файла" "\n"
//		    "8: Выход ""\n";
//		
//		cin >> a;
//		system("cls");
//		if (a == 1) {
//			cout << "Введите название фильма" << endl;
//			cin >> name;
//			cout << "Введите время сеанса" << endl;
//			cin >> time;
//			cout << "Введите цену за билет" << endl;
//			cin >> price;
//			cout << "Введите количество зрителей" << endl;
//			cin >> people;
//			addInEnd(head, name, time, price, people);
//		}
//
//		else if (a == 2) {
//			string N;
//
//			cout << "Введите название фильма, который нужно изменить" << endl;
//			cin >> N;
//			cout << "Введите название фильма" << endl;
//			cin >> name;
//			cout << "Введите время сеанса" << endl;
//			cin >> time;
//			cout << "Введите цену за билет" << endl;
//			cin >> price;
//			cout << "Введите количество зрителей" << endl;
//			cin >> people;
//			edit(head, N, name, time, price, people);
//		}
//		else if (a == 3) {
//			output(head);
//		}
//		else if (a == 4) {
//			string N;
//			cout << "Введите название фильма, который нужно удалить" << endl;
//			cin >> N;
//			del(head, N);
//		}
//		else if (a == 5) {
//			cout << "Введите название фильма, который нужно найти" << endl;
//			cin >> name;
//			find(head, name);
//		}
//		
//		//Сохраняю в файл
//		else if (a == 6) {
//			
//			cout << "введите 1, если хотите записать в файл по умолчанию, введите 2, если хотите дать имя файлу";
//				int x;
//				cin >> x;
//				ptr = head;
//				if (x == 1) {
//					save.open("default.txt");
//					if (!save.is_open()) {
//						cout << "Error1\n";
//					}
//					else {
//						SetConsoleCP(1251);
//						while (ptr != nullptr) {
//							cout << ptr->name << endl;;
//							cout << ptr->time << endl;
//							cout << ptr->price<<endl;
//							cout << ptr->people<<endl;
//							save << "\n" << ptr->name << "\t" << ptr->time << "\t" << ptr->price << "\t" << ptr -> people;
//							ptr = ptr->next;
//						}
//						SetConsoleCP(866);
//					}
//					save.close();
//				}
//
//				else if (x == 2) {
//					cin >> file;
//					save.open(file + ".txt");
//					if (!save.is_open()) {
//						cout << "Error2\n";
//					}
//					else
//					{
//						while (ptr != NULL) {
//							save << "\n" << ptr->name << "\t" << ptr->time << "\t" << ptr->price << "\t" << ptr->people;
//							ptr = ptr->next;
//						}
//					}
//					save.close();
//				}
//				
//		}
//
//		else if (a == 7) {
//			cout << "введите 1, если хотите вывести из  файла по умолчанию, введите 2, если хотите вывести из определенного файла ";
//			int x;
//			cin >> x;
//			if (x == 2) {
//				cin >> file;
//				in.open(file+".txt");
//
//				if (!in.is_open()) {
//					cout << "aaaaaaaaaaaa\n";
//				}
//				else {
//					string str;
//					while (!in.eof()) {
//						in >> str;
//						cout << str << endl;
//					}
//				}
//				in.close();
//				
//			}
//			if (x == 1)
//			{
//				
//				in.open("default.txt");
//
//				if (!in.is_open()) {
//					cout << "aaaaaaaaaaaa\n";
//				}
//				else {
//					string str;
//					while (!in.eof()) {
//						in >> str;
//						cout << str << endl;
//					}
//				}
//				in.close();
//
//			}
//		}
//
//		else if (a == 10) {
//			return 0;
//		}
//	}
//};



