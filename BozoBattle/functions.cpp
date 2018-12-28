#include<iostream>
#include<thread>
#include<chrono>
#include"functions.h"
#include"entities.h"

using namespace std;

void mainMenu(playerStats &player)
{
	bossGrimcrackle Grimcrackle;
	bossRazorwing Razorwing;
	int choice;
	bool loop = true;
	int fightTurns = 0;

	while (loop == true) {

		cout << "\nMain Menu\n";
		cout << "\nSelect an Option:\n";
		cout << "\t1. Fight\n";
		cout << "\t2. View Inventory\n";
		cout << "\t3. View Drop Tables\n";
		cout << "\t4. Player Stats\n";
		cout << "\t5. Boss Stats\n";
		cout << "\t6. Item Info\n";
		cout << "\t7. Exit Game\n";

		cin >> choice;

		if (choice == 1) {
			
			cout << "\nSelect a Boss to Fight:\n";
			cout << "\t1. Grimcrackle\n";
			cout << "\t2. Razorwing\n";
			cout << "\t3. Return to Main Menu\n";

			cin >> choice;

			switch (choice)
			{
			case 1:
				
				if (Grimcrackle.getBossLives() > 0) {
					if (bossFightGrimcrackle(player, Grimcrackle) == false) { //ends game if player dies
						loop = false;
					}
				}
				else {
					cout << "\nYou've already defeated all of this boss' forms\n";
				}

				break;
			case 2:

				if (Razorwing.getBossLives() > 0) {
					if (bossFightRazorwing(player, Razorwing) == false) { //ends game if player dies
						loop = false;
					}
				}
				else {
					cout << "\nYou've already defeated all of this boss' forms\n";
				}

				break;
			case 3:

				break;
			default:
				cout << "Invalid Choice\n";
				break;
			}

		}//main menu choice == 1

		else if (choice == 2) { //inventory

		player.showInventory();


		}//main menu choice == 2

		else if (choice == 3) { //drop tables
		cout << "\nSelect a Boss to View Its Drop Table:\n";
		cout << "\t1. Grimcrackle\n";
		cout << "\t2. Razorwing\n";
		cout << "\t3. Return to Main Menu\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			Grimcrackle.showDropTable();
			break;
		case 2:
			Razorwing.showDropTable();
			break;
		case 3:

			break;
		default:
			cout << "Invalid Choice\n";
			break;
		}
		}//main menu choice == 3

		else if (choice == 4) { //player stats

		player.playerInfo();
		}//main menu choice == 4

		else if (choice == 5) { //boss stats
		cout << "\nSelect a Boss:\n";
		cout << "\t1. Grimcrackle\n";
		cout << "\t2. Razorwing\n";
		cout << "\t3. Return to Main Menu\n";

		cin >> choice;

		switch (choice)
		{
		case 1:
			Grimcrackle.bossInfo();
			break;
		case 2:
			Razorwing.bossInfo();
			break;
		case 3:

			break;
		default:
			cout << "Invalid Choice\n";
			break;
		}
		}//main menu choice == 5

		else if (choice == 6) { //show item info
			itemInfo();
		}//main menu choice 6

		else if (choice == 7) { //exit
		loop = false;
		}//main menu choice == 7
		else {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(255, '\n');
		}
		printf("\033c");
		cout << "Invalid Choice, Try Again.\n";
		}//main menu choice error

	}//while loop

}//entire function

bool bossFightGrimcrackle(playerStats &player, bossGrimcrackle &Grimcrackle)
{
	int turnCount = 0;
	int skipChoice;

	if (player.getHealth() != 65) {
		player.setHealth(50);
	}

	/*Grimcrackle.setHealth(50);*/

	cout << "Would you like to skip the fight sequence?\n";
	cout << "\t1. Yes\n";
	cout << "\t2. No\n";
	cin >> skipChoice;

	printf("\033c");

	/*cout << "Added (ITEM) to TEST\n";
	player.addItem("Ring of Life");
	player.addItem("Phoenix Necklace");*/

	

	while (player.getHealth() > 0 && Grimcrackle.getHealth() > 0) {



		if (player.applyConsumables() == true) { //Checks to see if the user uses Ring of Life
			if (Grimcrackle.getBossLives() == 3) {
				Grimcrackle.setHealth(50);
			}
			else if (Grimcrackle.getBossLives() == 2) {
				Grimcrackle.setHealth(55);
			}
			else if (Grimcrackle.getBossLives() == 1) {
				Grimcrackle.setHealth(65);
			}
			return true;
		}

		cout << "Player HP: " << player.getHealth() << "\t\t\t" << "Boss HP: " << Grimcrackle.getHealth();
		

		Grimcrackle.defence(player.playerAttack());
		cout << "\n" << player.getName() << " dealt " << player.getDamage() << " points of damage.\n";
		
		if (skipChoice == 2) {
			this_thread::sleep_for(chrono::seconds(2));
		}

		printf("\033c");
		cout << "Player HP: " << player.getHealth() << "\t\t\t" << "Boss HP: " << Grimcrackle.getHealth();
		

		player.playerDefence(Grimcrackle.attack());
		cout << "\n" << Grimcrackle.getName() << " dealt " << Grimcrackle.getDamage() << " points of damage.\n";
		
		if (skipChoice == 2) {
			this_thread::sleep_for(chrono::seconds(2));
		}
		
		printf("\033c");
		cout << "Player HP: " << player.getHealth() << "\t\t\t" << "Boss HP: " << Grimcrackle.getHealth();
		
		turnCount++;

		if (player.applyConsumables() == true) { //Checks to see if the user uses Ring of Life
			if (Grimcrackle.getBossLives() == 3) {
				Grimcrackle.setHealth(50);
			}
			else if (Grimcrackle.getBossLives() == 2) {
				Grimcrackle.setHealth(55);
			}
			else if (Grimcrackle.getBossLives() == 1) {
				Grimcrackle.setHealth(65);
			}
			return true;
		}

		printf("\033c");
		
		
	}
	cout << "Player HP: " << player.getHealth() << "\t\t\t" << "Boss HP: " << Grimcrackle.getHealth() << "\n";
	cout << "\nThis battle lasted " << turnCount << " turns\n";
	return bossGrimcrackleOutcome(player, Grimcrackle);
}

bool bossGrimcrackleOutcome(playerStats &player, bossGrimcrackle &boss)
{
	cout << "\n";
	if (player.getHealth() <= 0 && boss.getHealth() <= 0) {
		cout << "It's a tie\n";
		/*cout << "Player health: " << player.getHealth() << endl;
		cout << "Boss health: " << boss.getHealth() << endl;*/
		player.bossDefeatCounter();

		
		return false;

	}
	else if (player.getHealth() <= 0) {
		cout << "You lose\n";
		cout << boss.getName() << " had " << boss.getHealth() << " health left.\n";
		
		return false;

	}
	else if (boss.getHealth() <= 0) {
		cout << "You win\n";
		cout << player.getName() << " had " << player.getHealth() << " health left.\n";
		boss.rollDropTable(player);
					
		player.bossDefeatCounter();
		
		boss.setBossLives(boss.getBossLives() - 1);
		boss.bossBuff();
		return true;

	}
	else {
		cout << "Wtf happened";
		return false;
	}

}

bool bossFightRazorwing(playerStats &player, bossRazorwing &Razorwing)
{
	
	int turnCount = 0;
	int skipChoice;
	if (player.getHealth() != 65) {
		player.setHealth(50);
	}
	//Razorwing.setHealth(35);


	cout << "Would you like to skip the fight sequence?\n";
	cout << "\t1. Yes\n";
	cout << "\t2. No\n";
	cin >> skipChoice;

	printf("\033c");

	//player.addItem("TEST ITEM");

	while (player.getHealth() > 0 && Razorwing.getHealth() > 0) {

		if (player.applyConsumables() == true) { //Checks to see if the user uses Ring of Life
			return true;
		}

		cout << "Player HP: " << player.getHealth() << "\t\t\t" << "Boss HP: " << Razorwing.getHealth();


		Razorwing.defence(player.playerAttack());
		cout << "\n" << player.getName() << " dealt " << player.getDamage() << " points of damage.\n";
		if (skipChoice == 2) {
			this_thread::sleep_for(chrono::seconds(2));
		}
		printf("\033c");
		cout << "Player HP: " << player.getHealth() << "\t\t\t" << "Boss HP: " << Razorwing.getHealth();


		player.playerDefence(Razorwing.attack());
		cout << "\n" << Razorwing.getName() << " dealt " << Razorwing.getDamage() << " points of damage.\n";
		if (skipChoice == 2) {
			this_thread::sleep_for(chrono::seconds(2));
		}
		printf("\033c");
		cout << "Player HP: " << player.getHealth() << "\t\t\t" << "Boss HP: " << Razorwing.getHealth();

		if (player.applyConsumables() == true) { //Checks to see if the user uses Ring of Life
			
			
			return true;

		}

		turnCount++;
		printf("\033c");

	}
	cout << "Player HP: " << player.getHealth() << "\t\t\t" << "Boss HP: " << Razorwing.getHealth() << "\n";
	cout << "\nThis battle lasted " << turnCount << " turns\n";
	return bossRazorwingOutcome(player, Razorwing);
}

bool bossRazorwingOutcome(playerStats &player, bossRazorwing &boss)
{
	cout << "\n";
	if (player.getHealth() <= 0 && boss.getHealth() <= 0) {
		cout << "It's a tie\n";
		/*cout << "Player health: " << player.getHealth() << endl;
		cout << "Boss health: " << boss.getHealth() << endl;*/
		player.bossDefeatCounter();

		return false;

	}
	else if (player.getHealth() <= 0) {
		cout << "You lose\n";
		cout << boss.getName() << " had " << boss.getHealth() << " health left.\n";

		return false;

	}
	else if (boss.getHealth() <= 0) {
		cout << "You win\n";
		cout << player.getName() << " had " << player.getHealth() << " health left.\n";
		boss.rollDropTable(player);

		player.bossDefeatCounter();

		boss.setBossLives(boss.getBossLives() - 1);
		boss.bossBuff();
		return true;

	}
	else {
		cout << "Wtf happened";
		return false;
	}

}

void endGameStats(playerStats &player) {
	
	cout << "\n" << player.getName() << "'s journey has come to an end.\n";
	cout << "\nBosses defeated: " << player.getBossesDefeated() << "\n";
	cout << "\nFinal Max Hit: " << player.getMaxHit() << "\n";
	player.showInventory();

}

void itemInfo()
{
	cout << "\nItem Info:\n";
	cout << "\nRune SQ Shield - Lowers all damage recieved by 1\n";
	cout << "Phoenix Necklace(C) - Raises life by 10 when dropped to kill shot range\n";
	cout << "Dragon Scimitar - Permanently raises max hit to 13\n";
	cout << "Ring of Life(C) - Resurrects the player if health drops to 0\n";
	cout << "Regen Bracelet - Permanently raises player health from 50 to 65\n";
	cout << "Rune Scimitar - Permanently raises max hit to 11\n";
	cout << "\n(C) represents 'Consumable', AKA a one time use item\n";

}