#include <iostream>
#include <string>
using namespace std;

class Game {
	public:
		char board[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
		bool player1turn = true;
		bool complete = false;
		string victor;
		void start() {
			while (!complete) {
				renderBoard();
				move();
				checkVictory();
			}
			cout << victor << " wins!";
		}
		void renderBoard() {
			cout << board[0] << "|" << board[1] << "|" << board[2] << "\n" << board[3] << "|" << board[4] << "|" << board[5] << "\n" << board[6] << "|" << board[7] << "|" << board[8] << "\n"; 
		}
		void move() {
			string x;
			cin >> x;
			if (player1turn) {
				board[stoi(x)] = 'X';
			}
			else {
				board[stoi(x)] = 'O';
			}
			player1turn = !player1turn;
		}
		void checkVictory() {
			if (board[0] == board[1] && board[0] == board[2]) {
				victor = board[0];
				complete = true;
			} else if (board[3] == board[4] && board[3] == board[5]) {
				victor = board[3];
				complete = true;
			} else if (board[6] == board[7] && board[6] == board[8]) {
				victor = board[6];
				complete = true;
			} else if (board[0] == board[3] && board[0] == board[6]) {
				victor = board[0];
				complete = true;
			} else if (board[1] == board[4] && board[1] == board[7]) {
				victor = board[1];
				complete = true;
			} else if (board[2] == board[5] && board[2] == board[8]) {
				victor = board[2];
				complete = true;
			} else if (board[0] == board[4] && board[0] == board[8]) {
				victor = board[0];
				complete = true;
			} else if (board[2] == board[4] && board[2] == board[6]) {
				victor = board[2];
				complete = true;
			} else {
				complete = false;
			}
		}
};

int main()
{
	Game game;
	game.start();
}
