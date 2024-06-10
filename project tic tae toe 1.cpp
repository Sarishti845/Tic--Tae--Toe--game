#include <iostream>
using namespace std;

char ch[9] = { '1','2','3','4','5','6','7','8','9' };
int num;
char player1 = 'X';
char player2 = 'O';

void Draw();
void player_1();
void player_2();
bool X_Wins();
bool O_Wins();
bool isDraw();

int main() {
    do {
        Draw();
        player_1();
        Draw();

        if (X_Wins()) {
            cout << "\t\t\t\tPlayer<1> Wins!" << endl;
            break;
        }
        if (isDraw()) {
            cout << "\t\t\t\tThe game is a draw!" << endl;
            break;
        }

        player_2();
        Draw();

        if (O_Wins()) {
            cout << "\t\t\t\tPlayer<2> Wins!" << endl;
            break;
        }
        if (isDraw()) {
            cout << "\t\t\t\tThe game is a draw!" << endl;
            break;
        }

    } while (true);

    return 0;
}

void Draw() {
    system("cls"); 
    cout << "\t\t\t\tTic Toc Toe Game\n" << endl;
    cout << "\t\t\t\tplayer<1>: X\n";
    cout << "\t\t\t\tplayer<2>: O\n";
    cout << endl << endl;

    cout << "\t\t\t\t" << ch[0] << "  |  " << ch[1] << "  |  " << ch[2] << "\n";
    cout << "\t\t\t\t-------------" << endl;

    cout << "\t\t\t\t" << ch[3] << "  |  " << ch[4] << "  |  " << ch[5] << "\n";
    cout << "\t\t\t\t-------------" << endl;

    cout << "\t\t\t\t" << ch[6] << "  |  " << ch[7] << "  |  " << ch[8] << "\n\n";
}

void player_1() {
    cout << "\t\t\t\tPlayer<1> Enter number: ";
    cin >> num;

    if (num < 1 || num > 9 || ch[num - 1] == 'X' || ch[num - 1] == 'O') {
        cout << "\t\t\t\tInvalid move! Please try again.\n";
        player_1();
    } else {
        ch[num - 1] = player1;
    }
}

void player_2() {
    cout << "\t\t\t\tPlayer<2> Enter number: ";
    cin >> num;

    if (num < 1 || num > 9 || ch[num - 1] == 'X' || ch[num - 1] == 'O') {
        cout << "\t\t\t\tInvalid move! Please try again.\n";
        player_2();
    } else {
        ch[num - 1] = player2;
    }
}

bool X_Wins() {
    return (ch[0] == 'X' && ch[1] == 'X' && ch[2] == 'X') ||
           (ch[3] == 'X' && ch[4] == 'X' && ch[5] == 'X') ||
           (ch[6] == 'X' && ch[7] == 'X' && ch[8] == 'X') ||
           (ch[0] == 'X' && ch[3] == 'X' && ch[6] == 'X') ||
           (ch[1] == 'X' && ch[4] == 'X' && ch[7] == 'X') ||
           (ch[2] == 'X' && ch[5] == 'X' && ch[8] == 'X') ||
           (ch[0] == 'X' && ch[4] == 'X' && ch[8] == 'X') ||
           (ch[2] == 'X' && ch[4] == 'X' && ch[6] == 'X');
}

bool O_Wins() {
    return (ch[0] == 'O' && ch[1] == 'O' && ch[2] == 'O') ||
           (ch[3] == 'O' && ch[4] == 'O' && ch[5] == 'O') ||
           (ch[6] == 'O' && ch[7] == 'O' && ch[8] == 'O') ||
           (ch[0] == 'O' && ch[3] == 'O' && ch[6] == 'O') ||
           (ch[1] == 'O' && ch[4] == 'O' && ch[7] == 'O') ||
           (ch[2] == 'O' && ch[5] == 'O' && ch[8] == 'O') ||
           (ch[0] == 'O' && ch[4] == 'O' && ch[8] == 'O') ||
           (ch[2] == 'O' && ch[4] == 'O' && ch[6] == 'O');
}

bool isDraw() {
    for (int i = 0; i < 9; ++i) {
        if (ch[i] != 'X' && ch[i] != 'O') {
            return false;
        }
    }
    return true;
}

