#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;
string name1, name2, name3, name4;
int score1 = 0, score2 = 0, score3 = 0, score4 = 0;
void win_function(int &n, int score)
{
	if (score == 56)
	{
		n = 1;
	}
	else
		n = 0;
}
void table(char array[][15]) {
	char n = 219;
	for (int i = 0; i < 13; i++) {
		cout << "_______";
	}
	cout << endl;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (i >= 6 && i <= 8) {
				if (j > 6 && j <= 8)
					cout << "   " << array[i][j] << "  ";
				else {
					if (i == 7) {
						if (j == 0 || j == 14 || j == 6)
							cout << "|  " << array[i][j] << "  ";
						else
							cout << "|" << n << n << array[i][j] << n << n;
					}
					else {
						if (j == 1 && i == 6 || (j == 13 && i == 8))
							cout << "|" << n << n << array[i][j] << n << n;
						else
							cout << "|  " << array[i][j] << "  ";
					}
				}
			}
			else {
				if (j == 0)
					cout << "|  " << array[i][j] << "  ";
				else {
					if (j >= 6 && j <= 9) {
						if (j == 7) {
							if (i == 0 || i == 14)
								cout << "|  " << array[i][j] << "  ";
							else
								cout << "|" << n << n << array[i][j] << n << n;
						}
						else {
							if (j == 6 && i == 13 || (j == 8 && i == 1))
								cout << "|" << n << n << array[i][j] << n << n;
							else
								cout << "|  " << array[i][j] << "  ";
						}
					}
					else
						cout << "   " << array[i][j] << "  ";
				}
			}
		}
		if (i >= 5 && i <= 8) {
			if (i == 5)
				cout << "|" << endl << "|___________________________________|_____|" << n << n << n << n << n << "|_____|___________________________________|" << endl;
			else {
				if (i >= 6 && i < 8) {
					if (i == 7)
						cout << "|" << endl << "|_____|" << n << n << n << n << n << "|" << n << n << n << n << n << "|" << n << n << n << n << n << "|" << n << n << n << n << n << "|" << n << n << n << n << n << "|                 |" << n << n << n << n << n << "|" << n << n << n << n << n << "|" << n << n << n << n << n << "|" << n << n << n << n << n << "|" << n << n << n << n << n << "|_____|" << endl;
					else {
						if (i == 6)
							cout << "|" << endl << "|_____|" << n << n << n << n << n << "|_____|_____|_____|_____|                 |_____|_____|_____|_____|_____|_____|" << endl;
						else
							cout << "|" << endl << "|_____|_____|_____|_____|_____|_____|                 |_____|_____|_____|_____|_____|_____|" << endl;
					}
				}
				else
					cout << "|" << endl << "|_____|_____|_____|_____|_____|_____|_________________|_____|_____|_____|_____|" << n << n << n << n << n << "|_____|" << endl;
			}
		}
		else {
			if (i == 14)
				cout << "|" << endl << "|___________________________________|_____|_____|_____|___________________________________|" << endl;
			else
				if (i == 0)
					cout << "|" << endl << "|                                   |_____|_____|_____|                                   |" << endl;
				else {
					if (i == 1)
						cout << "|" << endl << "|                                   |_____|" << n << n << n << n << n << "|" << n << n << n << n << n << "|                                   |" << endl;
					else {
						if (i == 13)
							cout << "|" << endl << "|                                   |" << n << n << n << n << n << "|" << n << n << n << n << n << "|_____|                                   |" << endl;
						else
							cout << "|" << endl << "|                                   |_____|" << n << n << n << n << n << "|_____|                                   |" << endl;
					}
				}
		}
	}
}
void function_red(int &Row, int &colume, int number, int &flag, char array[][15]) {
	int e, c;
	if (flag == 1) {
		Row = 13, colume = 6;
		array[Row][colume] = 177;
		flag++;
	}
}
void function_blue(int &Row, int &colume, int number, int &flag, char array[][15]) {
	int e, c;
	if (flag == 1) {
		Row = 1, colume = 8;
		array[Row][colume] = 178;
		flag++;
	}
}
void function_yellow(int &Row, int &colume, int number, int &flag, char array[][15]) {
	int e, c;
	if (flag == 1) {
		Row = 6, colume = 1;
		array[Row][colume] = 254;
		flag++;
	}
}
void function_green(int &Row, int &colume, int number, int &flag, char array[][15]) {
	if (flag == 1) {
		Row = 8, colume = 13;
		array[Row][colume] = 176;
		flag++;
	}
}
void move_token_1(int &Row, int &colume, int number, char array[][15], char image) {
	array[Row][colume] = ' ';
	Row = Row - number;
	if (Row < 9) {
		colume = Row;
		colume = colume - 3;
		Row = 8;
		array[Row][colume] = image;
	}
	else
		array[Row][colume] = image;
}
void move_token_2(int &Row, int &colume, int number, char array[][15], char image) {
	array[Row][colume] = ' ';
	colume = colume - number;
	if (colume <= 0) {
		Row = Row + colume;
		colume = 0;
		if (Row <= 6) {
			if (Row == 6) {
				Row = 2;
				Row = Row - 4;
				colume = colume + Row + 2;
				Row = 6;
				array[Row][colume] = image;
			}
			else if (Row == 5) {
				Row = 3;
				Row = Row - 4;
				colume = colume + Row + 2;
				Row = 6;
				array[Row][colume] = image;
			}
			else {
				Row = Row - 4;
				Row = abs(Row);
				colume = colume + Row + 2;
				Row = 6;
				array[Row][colume] = image;
			}
		}
		else
			array[Row][colume] = image;
	}
	else
		array[Row][colume] = image;
}
void move_token_3(int &Row, int &colume, int number, char array[][15], char image) {
	array[Row][colume] = ' ';
	colume = colume + number;
	if (colume > 5) {
		int e = colume;
		e = e - 5;
		Row = Row - e;
		colume = 6;
		array[Row][colume] = image;
	}
	else
		array[Row][colume] = image;
}
void move_token_4(int &Row, int &colume, int number, char array[][15], char image) {
	array[Row][colume] = ' ';
	Row = Row - number;
	if (Row < 0) {
		Row = abs(Row);
		colume = colume + Row;
		if (colume <= 8) {
			Row = 0;
			array[Row][colume] = image;
		}
		else {
			Row = colume - 8;
			colume = 8;
			array[Row][colume] = image;
		}
	}
	else {
		colume = 6;
		array[Row][colume] = image;
	}
}
void move_token_5(int &Row, int &colume, int number, char array[][15], char image) {
	array[Row][colume] = ' ';
	Row = Row + number;
	if (Row >= 6) {
		Row = Row - 5;
		colume = colume + Row;
		Row = 6;
		array[Row][colume] = image;
	}
	else
		array[Row][colume] = image;
}
void move_token_6(int &Row, int &colume, int number, char array[][15], char image) {
	array[Row][colume] = ' ';
	colume = colume + number;
	if (colume > 14) {
		int c = colume - 14;
		Row = Row + c;
		colume = colume - c;
		if (Row > 8) {
			c = Row - 8;
			colume = colume - c;
			Row = 8;
			array[Row][colume] = image;
		}
		else
			array[Row][colume] = image;
	}
	else
		array[Row][colume] = image;
}
void move_token_7(int &Row, int &colume, int number, char array[][15], char image) {
	array[Row][colume] = ' ';
	colume = colume - number;
	if (colume <= 8) {
		colume = 9 - colume;
		Row = Row + colume;
		colume = 8;
		array[Row][colume] = image;
	}
	else
		array[Row][colume] = image;
}
void player_1_go_home(int &Row, int &colume, int number, char array[][15], char image) {
	array[Row][colume] = ' ';
	int e = Row;
	e = e + number;
	if (Row < 14 && colume == 7)
	{
		if (Row - number > 8)
		{
			array[Row][colume] = ' ';
			Row = Row - number;
			array[Row][colume] = image;
		}
		else
		{
			if (Row - number == 8)
			{
				array[Row][colume] = ' ';
				Row = Row - number;
				array[Row][colume] = image;
			}
			else
				array[Row][colume] = image;
		}
	}
	else if (e > 14) {
		int p = e - 14;
		e = 15 - p;
		colume = 7;
		Row = e;
		array[e][colume] = image;
	}
	else
	{
		Row = e;
		array[Row][colume] = image;
	}
}
void player_2_go_home(int &Row, int &colume, int number, char array[][15], char image) {
	array[Row][colume] = ' ';
	int e = Row;
	e = e - number;
	if (Row > 0 && colume == 7)
	{
		if (Row + number < 6)
		{
			array[Row][colume] = ' ';
			Row = Row + number;
			array[Row][colume] = image;
		}
		else
		{
			if (Row + number == 6)
			{
				array[Row][colume] = ' ';
				Row = Row + number;
				array[Row][colume] = image;
			}
			else
				array[Row][colume] = image;
		}
	}
	else if (e < 0) {
		e = abs(e) - 1;
		colume = 7;
		Row = e;
		array[e][colume] = image;
	}
	else
	{
		Row = e;
		array[e][colume] = image;
	}
}
void move_token_8(int &Row, int &colume, int number, char array[][15], char image) {
	array[Row][colume] = ' ';
	Row = Row + number;
	if (Row > 14) {
		int p = Row - 14;
		colume = colume - p;
		Row = Row - p;
		if (colume < 6) {
			colume = 6 - colume;
			Row = Row - colume;
			colume = 6;
			array[Row][colume] = image;
		}
		else {
			array[Row][colume] = image;
		}
	}
	else
		array[Row][colume] = image;
}
void player_3_go_home(int &Row, int &colume, int number, char array[][15], char image) {
	array[Row][colume] = ' ';
	int e = colume;
	e = e + number;
	if (colume < 14 && Row == 7)
	{
		if (colume - number > 8)
		{
			array[Row][colume] = ' ';
			colume = colume - number;
			array[Row][colume] = image;
		}
		else
		{
			if (colume - number == 8)
			{
				array[Row][colume] = ' ';
				colume = colume - number;
				array[Row][colume] = image;
			}
			else
				array[Row][colume] = image;
		}
	}
	else if (e > 14) {
		int p = e - 14;
		e = 15 - p;
		Row = 7;
		colume = e;
		array[Row][e] = image;
	}
	else
	{
		colume = e;
		array[Row][e] = image;
	}
}
void player_4_go_home(int &Row, int &colume, int number, char array[][15], char image) {
	array[Row][colume] = ' ';
	int e = colume;
	e = e - number;
	if (colume > 0 && Row == 7)
	{
		if (colume + number < 6)
		{
			array[Row][colume] = ' ';
			colume = colume + number;
			array[Row][colume] = image;
		}
		else
		{
			if (colume + number == 6)
			{
				array[Row][colume] = ' ';
				colume = colume + number;
				array[Row][colume] = image;
			}
			else
				array[Row][colume] = image;
		}
	}
	else if (e < 0) {
		e = abs(e);
		e = e - 1;
		Row = 7;
		colume = e;
		array[Row][e] = image;
	}
	else {
		colume = e;
		array[Row][e] = image;
	}
}
void move(int &Row, int &colume, int number, int player, char array[][15], char image) {
	if (Row >= 9 && colume == 6)
		move_token_1(Row, colume, number, array, image);
	else if (Row > 6 && Row <= 8 && colume <= 6 && (player == 1 || player == 2 || player == 3))
		move_token_2(Row, colume, number, array, image);
	else if (colume < 5 && Row == 6)
		move_token_3(Row, colume, number, array, image);
	else if (colume < 8 && Row < 7 && (player == 1 || player == 3 || player == 4))
		move_token_4(Row, colume, number, array, image);
	else if (Row < 6 && colume>7)
		move_token_5(Row, colume, number, array, image);
	else if (Row < 8 && colume>8 && (player == 1 || player == 2 || player == 4))
		move_token_6(Row, colume, number, array, image);
	else if (colume > 8 && Row > 7)
		move_token_7(Row, colume, number, array, image);
	else if (Row <= 14 && player == 1)
		player_1_go_home(Row, colume, number, array, image);
	else if (Row < 6 && Row>0 && player == 2)
		player_2_go_home(Row, colume, number, array, image);
	else if (Row <= 14 && colume < 9 && colume>5)
		move_token_8(Row, colume, number, array, image);
	else if (colume < 14 && player == 3)
		player_3_go_home(Row, colume, number, array, image);
	else if (colume >= 0 && player == 4)
		player_4_go_home(Row, colume, number, array, image);
}
void playgame(int);
void file(int choice)
{
	string rule_file, play;
good:ifstream rule, menu, how_play;
	rule.open("rule.txt");
	how_play.open("how to play.txt");
	if (choice == 1)
	{
		system("cls");
		while (getline(rule, rule_file))
		{
			cout << rule_file << endl;
		}
	}
	if (choice == 4)
	{
		system("cls");
		while (getline(how_play, play))
		{
			cout << play << endl;
		}
	}
}
int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	string menu_file;
	int choice, back;
	system("cls");
back:ifstream menu;
	menu.open("menu.txt");
	while (getline(menu, menu_file))
	{
		cout << menu_file << endl;
	}
	cout << "plzz enter your choice :";
	cin >> choice;
	if (choice == 1)
	{
		file(choice);
		cout << "\n\nback 1   ";
		cin >> back;
		if (back == 1)
		{
			system("cls");
			goto back;
		}
	}
	if (choice == 4)
	{
		file(choice);
		cout << "\n\nback 1   ";
		cin >> back;
		if (back == 1)
		{
			system("cls");
			goto back;
		}
	}
	if (choice == 5)
	{
		cout << "\n\n\t\t\t\t\tgood bye  ^_^ *_*";
	}
	if (choice == 2)
	{
	good:system("cls");
		cout << "\t\t\t\t 1.how many player to play game " << endl;
		cout << "\t\t\t\t 2.go back " << endl;
		cout << "plzz enter your choice :";
		cin >> choice;
		if (choice == 2)
		{
			system("cls");
			goto back;
		}
		if (choice == 1)
		{
			system("cls");
			cout << "\t\t\t\t 1. two player " << endl;
			cout << "\t\t\t\t 2. three player " << endl;
			cout << "\t\t\t\t 3. four player " << endl;
			cout << "\t\t\t\t 4. go back " << endl;
			cout << "plzz enter your choice :";
			cin >> choice;
			if (choice == 1)
			{
				cout << "your color is red" << endl;
				cout << "enter your name ";
				cin >> name1;
				cout << "your color is blue" << endl;
				cout << "enter your name ";
				cin >> name2;
				playgame(choice);
			}
			if (choice == 2)
			{
				cout << "your color is red" << endl;
				cout << "enter your name ";
				cin >> name1;
				cout << "your color is blue" << endl;
				cout << "enter your name ";
				cin >> name2;
				cout << "your color is green" << endl;
				cout << "enter your name ";
				cin >> name3;
				playgame(choice);
			}
			if (choice == 3)
			{
				cout << "your color is red" << endl;
				cout << "enter your name ";
				cin >> name1;
				cout << "your color is blue" << endl;
				cout << "enter your name ";
				cin >> name2;
				cout << "your color is green" << endl;
				cout << "enter your name ";
				cin >> name3;
				cout << "your color is yellow" << endl;
				cout << "enter your name ";
				cin >> name4;
				playgame(choice);
			}
			if (choice == 4)
			{
				goto good;
			}
		}
	}
	if (choice == 3)
	{
		system("cls");
		cout << "\t\t\t\t\thigh score " << endl;
		cout << "\t\t\t\tplayer 1(red)    =" << score1 << endl;
		cout << "\t\t\t\tplayer 2(blue)   =" << score2 << endl;
		cout << "\t\t\t\tplayer 3(green)  =" << score3 << endl;
		cout << "\t\t\t\tplayer 4(yellow) =" << score4 << endl;
		cout << " back 1   ";
		cin >> back;
		if (back == 1)
		{
			system("cls");
			goto back;
		}
	}
	system("pause");
}
void playgame(int choice)
{
	int red, blue, green, yellow, check = 0;
	char G = 176, B = 178, R = 177, Y = 254;
	int red_r1 = 13, blue_r1 = 1, green_r1 = 11, yellow_r1 = 1;
	int red_c1 = 3, blue_c1 = 11, green_c1 = 11, yellow_c1 = 1;
	int red_r2 = 11, blue_r2 = 1, green_r2 = 11, yellow_r2 = 1;
	int red_c2 = 1, blue_c2 = 13, green_c2 = 13, yellow_c2 = 3;
	int red_r3 = 11, blue_r3 = 3, green_r3 = 13, yellow_r3 = 3;
	int red_c3 = 3, blue_c3 = 11, green_c3 = 11, yellow_c3 = 1;
	int red_r4 = 13, blue_r4 = 3, green_r4 = 13, yellow_r4 = 3;
	int red_c4 = 1, blue_c4 = 13, green_c4 = 13, yellow_c4 = 3;
	int b1 = 0, b2 = 0, b3 = 0, b4 = 0, r1 = 0, r2 = 0, r3 = 0, r4 = 0;
	int g1 = 0, g2 = 0, g3 = 0, g4 = 0, y1 = 0, y2 = 0, y3 = 0, y4 = 0;
	int a = 1, b = 1, c = 1, d = 1, e = 1, f = 1, g = 1, h = 1, i = 1, j = 1, k = 1, l = 1, m = 1, n = 1, o = 1, p = 1;
	int player = 1, number;
	int kill_1=0,kill_2=39,kill_3=26,kill_4=13;
	char array[15][15];
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			array[i][j] = ' ';
		}
	}
	for (int i = 1; i < 14; i++)
	{
		if (i > 5 && i < 9)
			array[i][7] = ' ';
		else
			array[i][7] = 219;
	}
	for (int i = 1; i < 14; i++)
	{
		if (i > 5 && i < 9)
			array[i][7] = ' ';
		else
			array[7][i] = 219;
	}
	array[6][1] = array[1][8] = array[13][6] = array[8][13] = 219;
	array[1][1] = array[1][3] = array[3][1] = array[3][3] = Y;
	array[1][11] = array[1][13] = array[3][11] = array[3][13] = B;
	array[11][1] = array[11][3] = array[13][1] = array[13][3] = R;
	array[11][11] = array[11][13] = array[13][11] = array[13][13] = G;
	choice = choice + 2;
	srand(time(0));
	do {
		system("cls");
		table(array);
		player = player % choice;

		cout << "\n\n\nPlayer " << player << endl;
		number = rand() % 6 + 1;
		cout << "\t\t\t\t\t_______" << endl;
		cout << "\t\t\t\t\t|     |" << endl;
		cout << "\t\t\t\t\t|  " << number << "  |" << endl;
		cout << "\t\t\t\t\t|_____|" << endl;
		if (player == 1)
		{
			system("color 4f");
			cout << "player 1 score =";
			cout << score1 << endl;
			cout << "player 1 name :" << name1 << endl;
			cout << "which token you move :";
			cin >> red;
			if (red == 1) {
				if (number == 6 && a == 1) {
					array[red_r1][red_c1] = ' ';
					red_r1 = 13, red_c1 = 6;
					r1++;
					a++;
				}
				if (r1 >= 1) {
					if (r1 == 1)
						function_red(red_r1, red_c1, number, r1, array);
					else {
						if (number < 7) {
							score1 = score1 + number;
							kill_1=kill_1+number;
							if (kill_1==kill_2)
							{
								blue_r1 = 1, blue_c1 = 11,  e= 1, b1 = 0;
								array[blue_r1][blue_c1]=B;
							}
							if (kill_1==kill_3)
							{
								green_r1 = 11, green_c1 = 11, i = 1, g1 = 0;
								array[green_r1][green_c1]=G;
							}
							if (kill_1==kill_4)
							{
								yellow_r1 = 1, yellow_c1 = 1, m = 1, y1 = 0;
								array[yellow_r1][yellow_c1]=Y;
							}
							else
							{
								move(red_r1, red_c1, number, player, array, R);
								win_function(check, score1);
							}
						}
					}
				}
			}
			else if (red == 2) {
				if (number == 6 && b == 1) {
					array[red_r2][red_c2] = ' ';
					red_r2 = 13, red_c2 = 6;
					r2++;
					b++;
				}
				if (r2 >= 1) {
					if (r2 == 1)
						function_red(red_r2, red_c2, number, r2, array);
					else {
						if (number < 7) {
							score1 = score1 + number;
							move(red_r2, red_c2, number, player, array, R);
							win_function(check, score1);
						}
					}
				}
			}
			else if (red == 3) {
				if (number == 6 && c == 1) {
					array[red_r3][red_c3] = ' ';
					red_r3 = 13, red_c3 = 6;
					r3++;
					c++;
				}
				if (r3 >= 1) {
					if (r3 == 1)
						function_red(red_r3, red_c3, number, r3, array);
					else {
						if (number < 7) {
							score1 = score1 + number;
							move(red_r3, red_c3, number, player, array, R);
							win_function(check, score1);
						}
					}
				}
			}
			else if (red == 4) {
				if (number == 6 && d == 1) {
					array[red_r4][red_c4] = ' ';
					red_r4 = 13, red_c4 = 6;
					r4++;
					d++;
				}
				if (r4 >= 1) {
					if (r4 == 1)
						function_red(red_r4, red_c4, number, r4, array);
					else {
						if (number < 7) {
							score1 = score1 + number;
							move(red_r4, red_c4, number, player, array, R);
							win_function(check, score1);
						}
					}
				}
			}
		}
		if (player == 2) {
			system("color 1f");
			cout << "player 2 score =";
			cout << score2 << endl;
			cout << "player 2 name :" << name2 << endl;
			cout << "which token you move :";
			cin >> blue;
			if (blue == 1) {
				if (number == 6 && e == 1) {
					array[blue_r1][blue_c1] = ' ';
					blue_r1 = 1, blue_c1 = 8;
					b1++;
					e++;
				}
				if (b1 >= 1) {
					if (b1 == 1)
						function_blue(blue_r1, blue_c1, number, b1, array);
					else {
						if (number < 7) {
							score2 = score2 + number;
							move(blue_r1, blue_c1, number, player, array, B);
							win_function(check, score2);
						}
					}
				}
			}
			if (blue == 2) {
				if (number == 6 && f == 1) {
					array[blue_r2][blue_c2] = ' ';
					blue_r2 = 1, blue_c2 = 8;
					b2++;
					f++;
				}
				if (b2 >= 1) {
					if (b2 == 1)
						function_blue(blue_r2, blue_c2, number, b2, array);
					else {
						if (number < 7) {
							score2 = score2 + number;
							move(blue_r2, blue_c2, number, player, array, B);
							win_function(check, score2);
						}
					}
				}
			}
			if (blue == 3) {
				if (number == 6 && g == 1) {
					array[blue_r3][blue_c3] = ' ';
					blue_r3 = 1, blue_c3 = 8;
					b3++;
					g++;
				}
				if (b3 >= 1) {
					if (b3 == 1)
						function_blue(blue_r3, blue_c3, number, b3, array);
					else {
						if (number < 7) {
							score2 = score2 + number;
							move(blue_r3, blue_c3, number, player, array, B);
							win_function(check, score2);
						}
					}
				}
			}
			if (blue == 4) {
				if (number == 6 && h == 1) {
					array[blue_r4][blue_c4] = ' ';
					blue_r4 = 1, blue_c4 = 8;
					b4++;
					h++;
				}
				if (b4 >= 1) {
					if (b4 == 1)
						function_blue(blue_r4, blue_c4, number, b4, array);
					else {
						if (number < 7) {
							score2 = score2 + number;
							move(blue_r4, blue_c4, number, player, array, B);
							win_function(check, score2);
						}
					}
				}
			}
		}
		if (player == 3)
		{
			system("color 2f");
			cout << "player 3 score =";
			cout << score3 << endl;
			cout << "player 3 name :" << name3 << endl;
			cout << "which token you move :";
			cin >> green;
			if (green == 1) {
				if (number == 6 && i == 1) {
					array[green_r1][green_c1] = ' ';
					green_r1 = 1, green_c1 = 8;
					g1++;
					i++;
				}
				if (g1 >= 1) {
					if (g1 == 1)
						function_green(green_r1, green_c1, number, g1, array);
					else {
						if (number < 7) {
							score3 = score3 + number;
							move(green_r1, green_c1, number, player, array, G);
							win_function(check, score3);
						}
					}
				}
			}
			if (green == 2) {
				if (number == 6 && j == 1) {
					array[green_r2][green_c2] = ' ';
					green_r2 = 1, green_c2 = 8;
					g2++;
					j++;
				}
				if (g2 >= 1) {
					if (g2 == 1)
						function_green(green_r2, green_c2, number, g2, array);
					else {
						if (number < 7) {
							score3 = score3 + number;
							move(green_r2, green_c2, number, player, array, G);
							win_function(check, score3);
						}
					}
				}
			}
			if (green == 3) {
				if (number == 6 && k == 1) {
					array[green_r3][green_c3] = ' ';
					green_r3 = 1, green_c3 = 8;
					g3++;
					k++;
				}
				if (g3 >= 1) {
					if (g3 == 1)
						function_green(green_r3, green_c3, number, g3, array);
					else {
						if (number < 7) {
							score3 = score3 + number;
							move(green_r3, green_c3, number, player, array, G);
							win_function(check, score3);
						}
					}
				}
			}
			if (green == 4) {
				if (number == 6 && l == 1) {
					array[green_r4][green_c4] = ' ';
					green_r4 = 1, green_c4 = 8;
					g4++;
					l++;
				}
				if (g4 >= 1) {
					if (g4 == 1)
						function_green(green_r4, green_c4, number, g4, array);
					else {
						if (number < 7) {
							score3 = score3 + number;
							move(green_r4, green_c4, number, player, array, G);
							win_function(check, score3);
						}
					}
				}
			}
		}
		if (player == 4)
		{
			system("color 6f");
			cout << "player 4 score =";
			cout << score4 << endl;
			cout << "player 4 name :" << name4 << endl;
			cout << "which token you move :";
			cin >> yellow;
			if (yellow == 1) {
				if (number == 6 && m == 1) {
					array[yellow_r1][yellow_c1] = ' ';
					yellow_r1 = 1, yellow_c1 = 8;
					y1++;
					m++;
				}
				if (y1 >= 1) {
					if (y1 == 1)
						function_yellow(yellow_r1, yellow_c1, number, y1, array);
					else {
						if (number < 7) {
							score4 = score4 + number;
							kill_2=kill_2+number;
							move(yellow_r1, yellow_c1, number, player, array, Y);
							win_function(check, score4);
						}
					}
				}
			}
			if (yellow == 2) {
				if (number == 6 && n == 1) {
					array[yellow_r2][yellow_c2] = ' ';
					yellow_r2 = 1, yellow_c2 = 8;
					y2++;
					n++;
				}
				if (y2 >= 1) {
					if (y2 == 1)
						function_yellow(yellow_r2, yellow_c2, number, y2, array);
					else {
						if (number < 7) {
							score4 = score4 + number;
							move(yellow_r2, yellow_c2, number, player, array, Y);
							win_function(check, score4);
						}
					}
				}
			}
			if (yellow == 3) {
				if (number == 6 && o == 1) {
					array[yellow_r3][yellow_c3] = ' ';
					yellow_r3 = 1, yellow_c3 = 8;
					y3++;
					o++;
				}
				if (y3 >= 1) {
					if (y3 == 1)
						function_yellow(yellow_r3, yellow_c3, number, y3, array);
					else {
						if (number < 7) {
							score4 = score4 + number;
							move(yellow_r3, yellow_c3, number, player, array, Y);
							win_function(check, score4);
						}
					}
				}
			}
			if (yellow == 4) {
				if (number == 6 && p == 1) {
					array[yellow_r4][yellow_c4] = ' ';
					yellow_r4 = 1, yellow_c4 = 8;
					y4++;
					p++;
				}
				if (y4 >= 1) {
					if (y4 == 1)
						function_yellow(yellow_r4, yellow_c4, number, y4, array);
					else {
						if (number < 7) {
							score4 = score4 + number;
							move(yellow_r4, yellow_c4, number, player, array, Y);
							win_function(check, score4);
						}
					}
				}
			}
		}
		player++;
	} while (check == 0);
	player--;
	cout << "\t\t\tplayer " << player << " win  *_* *_*\n";
	main();
}
