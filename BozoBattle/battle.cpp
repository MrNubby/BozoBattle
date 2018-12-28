#include<iostream>
#include<string>
#include<vector>
#include<time.h>
#include"entities.h"
#include"functions.h"
#include<stdlib.h>
#include<thread> //<thread> and <chrono> included to slow down program
#include<chrono>

using namespace std;

int main()
{
	srand(time(NULL));

	playerStats player;

	string newPlayerName;
	string beginFight;

	cout << "What is the name of your player?\n";
	getline(cin, newPlayerName);
	player.setName(newPlayerName);

	if (newPlayerName == "deulin") { //easter egg for player named 'deulin'
		cout << "\nAs you step into the arena, you find your left arm suddenly broken.\n";
		cout << "A dull, aching pain fills your body until you slowly sink to the ground.\n";
	}
	else if (newPlayerName == "nubby") { //easter egg for player named 'nubby'
		cout << "\nAs you step into the arena, you notice that all children in the stands are gruesomely murdered.\n";
		cout << "A pang of guilt takes over your body before you take your own life.\n";
	}
	else if (newPlayerName == "frenchy") { //easter egg for player named 'frenchy'
		cout << "\nAs you step into the arena, you remember that you're wasting your time.\n";
		cout << "You NEED to get back to maxing in OSRS.\n";
	}
	if (newPlayerName == "adri") { //easter egg for player named 'adri'
		cout << "\nAs you step into the arena, you remember that you have yet to call Jonny tonight.\n";
		cout << "What's he doing? Who's he talking to? Where is he?\n";
		cout << "You NEED to call him.\n";
	}
	else {
		mainMenu(player);
	}
	

	endGameStats(player);
	/*cout << "\nAbout your opponent:\n";
	boss.bossInfo();*/

	return 0;

}