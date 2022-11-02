#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;
enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
    DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void SetColor(ConsoleColor text, ConsoleColor background)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((background << 4) | text));
}
//��������, ���� �� ������
bool check(const string& inp) {
	for (int i = 0; i < inp.size(); ++i) {
		if (inp[i] != ' ') {
			return inp[i] == '-';
		}
	}
	return false;
}

int main() {
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	setlocale(LC_ALL, "");
	ifstream in("in.txt");
	int c;
	string line;//�����������
	stringstream ss;//��������� �����
	while (true) {
		cout << "�������� ��������:" << endl;
		cout << "1 - ��������������� ���������� �����" << endl;
		cout << "2 - ���������� ����� ��� ���������" << endl;
		cout << "0 - �����" << endl;
		cin >> c;
		if (c == 1) {
			try
			{

				if (in.is_open())
				{
					while (getline(in, line)) {//��������� �� �����������
											   //���� ������ ���������� � ����
						if (check(line)) {
							//SetConsoleTextAttribute(hConsole, 12);
							SetColor(Red, White);
							ss << line << '\n';
						}

					}
				}
				else throw exception("�� ������� ������� ����!");

				cout << ss.str();//����� ���� ������
			}

			catch (const exception& err)
			{
				cerr << err.what() << endl;
			}
		}
		if(c==2){
			try
			{

				if (in.is_open())
				{
					while (getline(in, line)) {//��������� �� �����������
											   //���� ������ ���������� � ����

						ss << line << '\n';
					}
				}
				else throw exception("�� ������� ������� ����!");

				cout << ss.str();//����� ���� ������
			}

			catch (const exception& err)
			{
				cerr << err.what() << endl;
			}
		}
		if (c == 0) {
			return 0;
			break;
		}
	}
	in.close();//��������� ����			

	system("pause>>void");

}
