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
		/*���� � ����� �����������*/
			if ((ch[i] = fgetc(file)) == ' ') { ch[i + 1] = '\0'; break; }//���� ����� ������� � �� ������	
		i++;//������ ������ �� ����� ������  
	}
	//������� ������ �� �������� ������� ��� � �������, ����� �������� ��� ��� ���� � CHAR � STRING  
	//����� ��� �� ��� ����� � ������� � ���� ��������.
	for (int j = 0; j < i; j++) {
		ch1 += ch[j];
	}
	//stoi - ����� ��� ��������������� �� string � int
	return stoi(ch1);
}



int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//1 �������

	FILE* file = nullptr; //�������� ���������� �����
	fopen_s(&file, "test.txt", "r");//�������� ����, ����� �������� �� ��������� �����������
	int N = transform(file); //�������� ������ �����
	int* mas = new int[N], i = 0, sort;

	for (int i = 0; i < N; i++) {//� ���� ����� �������������� ��� ����� � int
		mas[i] = transform(file);
		cout << mas[i] << " - Element" << endl;
	}

	cout << "------------------------------------------" << endl;

	for (int i = 0; i < N; i++) {//���� ���������� ���������, ���� ��������� �������, ��� ������ ��������� �����)
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
	fclose(file);//���� ���� ���� �������

	FILE* file1 = nullptr;
	fopen_s(&file1, "test1.txt", "w");
	for (int i = 0; i < N; i++) {//��������� � ����� ����
		fprintf(file, "%d", mas[i]);
	}
	fclose(file1);
}