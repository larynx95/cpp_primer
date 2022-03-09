#include <conio.h>
#include <windows.h>

#include <iostream>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

using namespace std;

void gotoxy(int x, int y);
void cursor(int n);

int main() {
  int key = 0, y = 0, x = 0;
  while (1) {
    cursor(0);
    system("cls");
    gotoxy(x, y);
    cout << "▶";
    gotoxy(0, 12);
    cout << "key 값 : " << key << ", 좌표 : (" << x << "," << y << ")";

    key = getch();
    if (key == 224) {
      key = getch();
    }
    if (key == UP) {
      y--;
      if (y < 0) {
        y = 0;
      }
    } else if (key == DOWN) {
      y++;
      if (y > 10) {
        y = 10;
      }
    } else if (key == LEFT) {
      x--;
      if (x < 0) {
        x = 0;
      }
    } else if (key == RIGHT) {
      x++;
      if (x > 10) {
        x = 10;
      }
    }
  }
}
void gotoxy(int x, int y) {
  COORD Pos;
  Pos.X = x;
  Pos.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void cursor(int n) {  // 커서 보이기 & 숨기기
  HANDLE hConsole;
  CONSOLE_CURSOR_INFO ConsoleCursor;  //구조체 선언
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  ConsoleCursor.bVisible = n;  //커서 노출여부 1:보임, 0:안보임
  ConsoleCursor.dwSize = 1;    //커서 사이즈
  SetConsoleCursorInfo(hConsole, &ConsoleCursor);
  //지정된 콘솔 스크린 버퍼에 대하여 커서의 형태 (두께 or 노출여부) 를 설정하는
  //역할을 합니다. 매개변수로 콘솔 스크린 버퍼에 대한 핸들과 CONSOLE_CURSUR_INFO
  //구조체를 넘겨줍니다.
}
