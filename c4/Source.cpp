#include<iostream>
#include<string>
using namespace std;

void display();
void check(int a, int b);
int fall(int b, char player);
char board[6][7];
int main()
{
	for (int a = 0; a <= 5; a++){
		for (int b = 0; b <= 6; b++)
			board[a][b] = ' ';
}

display();

int hold;
int hold2 = 0;
int charsplaced = 0;
bool gamewon = false;
char player = 15;
while (!gamewon){
	if (hold2 != -1){
		if (player == 15){
			cout << "Player 1 drop where?";
			player = 254;
		}
		else
		{
			cout << "Player 1 drop where?";
			player = 15;
		}
	}
	while (true)
	{
		if (charsplaced == 42)
			break;
		cin >> hold;
		hold--;
		if (hold <= 6 && hold >= 0)
			break;
		else
		{
			cout << "Please enter a value between 1 and 7";
		}
		if (cin.fail())
		{
			cin.clear();
			char c;
			cin >> c;
		}
	}
	if (charsplaced == 42)
	{
		break;


		hold2 = fall(hold, player);
	}	if (hold2 == -1)
	{
		cout << "Column is full please enter another value between 1 and 7";
	}
	else
	{
		gamewon = check(hold2, hold);
		charsplaced++;
		system("cls");
		display();
	}
}
system("cls");
if (charsplaced == 42){
	cout << "Game draw";
	system("Pause");
	return 0;
}
if (player == 15)
cout << "Palyer 2 won the game";
else
cout << "Player 1 won the game";
system("pause");
return 0;
}
void display(){
	cout << " 1   2   3   4   5   6   7\n";
	for (int a = 0; a <= 5; a++)
	{
		for (int b = 0; b <= 6; b++) cout << char(218) << char(196) << char(191) << " ";
		cout << '\n';
		for (int b = 0; b <= 6; b++) cout << char(179) <<board[a][b] << char(179) << " ";
		cout << '\n';
		for (int b = 0; b <= 6; b++) cout << char(192) << char(196) << char(217) << " ";
		cout << '\n';
	}
}
bool check(int a, int b){
	int vertical = 1;//(|)
	int horizontal = 1;//(-)
	int diagonal1 = 1;//(\)
	int diagonal2 = 1;//(/)
	char player = board[a][b];
	int i;//vertical
	int ii;//horizontal
	//check for vertical(|)
	for (i = a + 1; board[i][b] == player && i <= 5; i++, vertical++);//Check down
	for (i = a - 1; board[i][b] == player && i >= 0; i--, vertical++);//Check up
	if (vertical >= 4)return true;
	//check for horizontal(-)
	for (ii = b - 1; board[a][ii] == player && ii >= 0; ii--, horizontal++);//Check left
	for (ii = b + 1; board[a][ii] == player && ii <= 6; ii++, horizontal++);//Check right
	if (horizontal >= 4) return true;
	//check for diagonal 1 (\)
	for (i = a - 1, ii = b - 1; board[i][ii] == player && i >= 0 && ii >= 0; diagonal1++, i--, ii--);//up and left
	for (i = a + 1, ii = b + 1; board[i][ii] == player && i <= 5 && ii <= 6; diagonal1++, i++, ii++);//down and right
	if (diagonal1 >= 4) return true;
	//check for diagonal 2(/)
	for (i = a - 1, ii = b + 1; board[i][ii] == player && i >= 0 && ii <= 6; diagonal2++, i--, ii++);//up and right
	for (i = a + 1, ii = b - 1; board[i][ii] == player && i <= 5 && ii >= 0; diagonal2++, i++, ii--);//up and left
	if (diagonal2 >= 4) return true;
	return false;
}
int drop(int b, char player){
	if (b >= 0 && b <= 6)
	{
		if (board[0][b] == ' '){
			int i;
			for (i = 0; board[i][b] == ' '; i++)
				if (i == 5){
					board[i][b] = player;
					return i;
				}
			i--;
			board[i][b] = player;
			return i;

		}
		else{
			return -1;
		}

	}
	else{
		return -1;
	}

}