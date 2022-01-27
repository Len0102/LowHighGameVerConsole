#include "head.h"
/*
* Low High 게임 만들기
*
*
* Ver 1.0
* 1. Server(임의)는 srand() 함수를 사용하여 1부터 100 사이의 임의의 값을 선정한다.
* 2. Client(임의)는 특정 수를 입력한다.
* 3-1. 만약 그 수가 임의의 값 보다 낮다면 Low를 콘솔에 출력한다.
* 3-2. 만약 그 수가 임의의 값 보다 높다면 High를 콘솔에 출력한다.
* 4. 만약 그 수가 임의의 수와 같다면, 게임은 종료된다.
*/

int main() {
	int Server;
	int Client;
	int Count = 0;
	srand(time(NULL));
	Server = rand() % 100 + 1;
	ConsoleSet();
	char Menu = 's' || 'q';
	while (true) {
		FirScreen();
		cout << "작업을 입력하세요 : " << endl;
		cin >> Menu;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		switch (Menu) {
		case 's':
			while (true) {
				system("cls");
				cout << "도전 횟수 : " << Count << '\n' << endl;
				Stage();
				cin >> Client;
				if (Client > Server) {
					cout << "High!" << endl;
					system("pause");
					Count++;
					continue;
				}

				else if (Client < Server) {
					cout << "Low!" << endl;
					system("pause");
					Count++;
					continue;
				}

				else if (Client == Server) {
					cout << "맞추셨습니다!" << endl;
					system("pause");
					system("cls");
					cout << "다시 하시겠습니까?" << endl;
					cout << "예(1)    아니오(2)" << endl;
					int A;
					cin >> A;

					if (cin.fail()) {
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}

					if (A == 1) {
						break;
					}

					else if (A == 2) {
						return 0;
					}
				}

				if (Count > 10) {
					cout << "도전 횟수가 10회가 넘어 정답을 공개하겠습니다." << endl;
					cout << "정답은" << Server << "입니다." << endl;
					system("pause");
					return 0;
				}
			}
			break;
		case 'q':
			system("cls");
			return 0;
			break;
		}
	}
	return 0;
}

//functions
void GotoXY(int x, int y) {
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = 2 * y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void ConsoleSet() {
	system("mode con:cols=50 lines=20");
	system("title [HangManGame] by.BlockDMask");
}

void FirScreen() {
	system("cls");
	GotoXY(5, 2);
	cout << "==============================";
	GotoXY(5, 3);
	cout << "======= Low HIGH GAME ========";
	GotoXY(5, 4);
	cout << "==============================";
	GotoXY(6, 6);
	cout << "시작하려면 's'를 눌러주세요";
	GotoXY(6, 7);
	cout << "종료하려면 'q'를 눌러주세요\n";
	GotoXY(9, 14);
	cout << "by. Len" << endl;
}

void Stage() {
	cout << "*** 제시한 숫자를 맞춰보세요! ***" << endl;
	GotoXY(5, 40);
	cout << "*********************************\n" << endl;
	GotoXY(5, 40);

	cout << "숫자를 입력하세요 : " << endl;
}