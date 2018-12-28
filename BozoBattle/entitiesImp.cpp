#include<iostream>
#include<string>
#include<vector>
#include<time.h>
#include"entities.h"
#include<stdlib.h>

using namespace std;

playerStats::playerStats()
{
	playerName = "";
	playerHealth = 50;
	playerDamage = 0;
	maxHit = 10;
	bossesDefeated = 0;
};

void playerStats::playerInfo()
{
	cout << "\nName: " << playerName << endl;
	cout << "Health: " << playerHealth << endl;
	cout << "Max Hit: " << maxHit << endl;
	cout << "Monsters defeated: " << bossesDefeated << endl;
}

void playerStats::randPlayerDamage()
{
	playerDamage = rand() % (maxHit + 1); //+1 bc if maxHit is the highest, modulus will only have 1 less than maxHit

}

void playerStats::addItem(string item)
{
	bool duplicate = false;

	for (int pos = 0; pos < inventory.size(); pos++) {
		if (item == inventory[pos]) {
			duplicate = true;
		}

	}

	if (duplicate == false) {
		inventory.push_back(item);
	}
	else {
		cout << "You already have this item.\n";
	}

}

void playerStats::showInventory()
{
	cout << "\nInventory:\n";

	for (int pos = 0; pos < inventory.size(); pos++) {
		cout << "\t-" << inventory[pos] << "\n";
	}
}

bool playerStats::applyConsumables()
{
	

	for (int pos = 0; pos < inventory.size(); pos++) {

		if (inventory[pos] == "Phoenix Necklace") {

			if (playerHealth <= 12) {
				playerHealth = playerHealth + 10;

				cout << "You used your Phoenix Necklace to restore 10 health.\n";

				inventory[pos] = "";

				return false;
			}
			
		}

		if (inventory[pos] == "Ring of Life") {

			if (playerHealth <= 0) {

				cout << "\nYou used your Ring of Life to come back from the grave baabyyy.\n";

				inventory[pos] = "";

				return true;
			}
			
		}

	}
	return false;
}

void playerStats::applyItems()
{
	for (int pos = 0; pos < inventory.size(); pos++) {

		if (inventory[pos] == "Dragon Scimitar") {

			maxHit += 3;

			inventory[pos] = "";
		}
		if (inventory[pos] == "Rune Scimitar") {

			maxHit += 1;

			inventory[pos] = "";
		}
		if (inventory[pos] == "Regen Bracelet") {

			playerHealth += 15;

			inventory[pos] = "";
		}
		if (inventory[pos] == "Tanglebug Meat") {

			playerHealth += 10;

			inventory[pos] = "";
		}
		if (inventory[pos] == "Amulet of Strength") {

			maxHit += 1;

			inventory[pos] = "";
		}
	}

}

int playerStats::playerAttack() {
	randPlayerDamage();


	return playerDamage;
}

void playerStats::playerDefence(int damage)
{
	for (int pos = 0; pos < inventory.size(); pos++) {

		if (inventory[pos] == "Rune SQ Shield") {

			if (damage > 0) {
				damage -= 1;
			}

		}
		else if (inventory[pos] == "Rune Defender") {


		}
	}

	playerHealth -= damage;

}



//###################################################################################

bossGrimcrackle::bossGrimcrackle()
{
	bossName = "Grimcrackle";
	bossHealth = 50;
	bossDamage = 0;
	drops[0] = "Rune SQ Shield";
	drops[1] = "Phoenix Necklace";
	drops[2] = "Dragon Scimitar";
	maxHit = 10;
	bossLives = 3;
};

void bossGrimcrackle::bossInfo()
{
	cout << "\n" << bossName << "'s Stats:\n";
	cout << "Health: " << bossHealth << "\n";
	cout << "Max Hit: " << maxHit << "\n";
	cout << "Lives Left: " << bossLives << "\n";
}

void bossGrimcrackle::randBossDamage()
{
	bossDamage = rand() % (maxHit + 1);
}

void bossGrimcrackle::rollDropTable(playerStats &player)
{
	int dropIndex;

	dropIndex = rand() % dropTableSize;

	cout << "You got the drop '" << drops[dropIndex] << "'!\n";

	player.addItem(drops[dropIndex]);
	
	player.applyItems();

}

void bossGrimcrackle::showDropTable()
{
	cout << "\n" << getName() << "'s Drop Table:\n";
	for (int pos = 0; pos < dropTableSize; pos++) {
		cout << "\t-" << drops[pos] << "\n";
	}
}

int bossGrimcrackle::attack()
{
	randBossDamage();
	return bossDamage;
}

void bossGrimcrackle::defence(int damage)
{
	bossHealth -= damage;
}

void bossGrimcrackle::bossBuff()
{
	if (bossLives == 2) {
		bossHealth = 55;
		maxHit = 12;
	}
	else if (bossLives == 1) {
		bossHealth = 65;
		maxHit = 14;
	}

}

//###################################################################

bossRazorwing::bossRazorwing()
{
	bossGrimcrackle();
	setName("Razorwing");
	setHealth(35);
	setDamage(0);
	setMaxHit(6);
	drops[0] = "Ring of Life";
	drops[1] = "Regen Bracelet";
	drops[2] = "Rune Scimitar"; //
}

void bossRazorwing::bossInfo()
{
	cout << "\n" << getName() << "'s Stats:\n";
	cout << "Health: " << getHealth() << "\n";
	cout << "Max Hit: " << getMaxHit() << "\n";
	cout << getName() << "has a 25% chance to evade your attack\n";
	cout << "Lives Left: " << getBossLives() << "\n";
}

void bossRazorwing::randBossDamage()
{
	setDamage( (rand() % (getMaxHit() - 2) ) + 2 );
}

int bossRazorwing::attack() {
	randBossDamage();
	return getDamage();
}

void bossRazorwing::defence(int damage)
{
	int evade;
	evade = rand() % 100;

	if (evade >= 0 && evade <= 24) {
		cout << "\nRazorwing evaded the attack!\n";
	}

	else {
		setHealth(getHealth() - damage);
	}
}

void bossRazorwing::rollDropTable(playerStats &player)
{
	int dropIndex;

	dropIndex = rand() % dropTableSize;

	cout << "You got the drop '" << drops[dropIndex] << "'!\n";

	player.addItem(drops[dropIndex]);

	player.applyItems();

}

void bossRazorwing::showDropTable()
{
	cout << "\n" << getName() << "'s Drop Table:\n";
	for (int pos = 0; pos < dropTableSize; pos++) {
		cout << "\t-" << drops[pos] << "\n";
	}
}

void bossRazorwing::bossBuff()
{
	if (getBossLives() == 2) {
		setHealth(40);
		setMaxHit(7);
	}
	else if (getBossLives() == 1) {
		setHealth(50);
		setMaxHit(8);
	}


}

//###################################################################

bossTanglebug::bossTanglebug()
{
	bossGrimcrackle();
	setName("Tanglebug");
	setHealth(40);
	setDamage(0);
	setMaxHit(7);
	drops[0] = "Amulet of Strength"; //add 1 to max hit
	drops[1] = "Rune Defender"; //constant block 1 damage, add 1 to max hit
	drops[2] = "Tanglebug Meat"; //adds 10 health one time
}