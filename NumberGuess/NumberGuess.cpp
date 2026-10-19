#include <iostream>
#include <random>
#include <windows.h>
#include <iomanip>

using namespace std;

random_device rd;
mt19937_64 gen(rd());

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << "The computer will choose a random number from 1 to 10000 (inclusive).\n";
	cout << "Your job is to guess the number.\n";
	cout << "The computer will tell you each time if your guess is too high or too low.\n";
	cout << "Now, please begin guessing: ";

	uniform_int_distribution<int> dist(1, 10000);
	int target = dist(gen);

	int guess, tries = 0, ub = 10000, lb = 1;
	while (true) {
		cin >> guess;
		tries++;

		if (guess > target) {
			cout << "Too high.\n";

			if (guess < ub) {
				ub = guess;
			}
		}
		else if (guess < target) {
			cout << "Too low.\n";

			if (guess > lb) {
				lb = guess;
			}
		}
		else {
			cout << "You guess it! You guess the number " << target << " in " << tries << (tries == 1 ? " try!" : " tries!");
			break;
		}

		cout << "Tries: " << tries << "\n";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

		cout << "Your current best guess of where the number is between " << lb << " and " << ub << '\n';

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}

	return 0;
}