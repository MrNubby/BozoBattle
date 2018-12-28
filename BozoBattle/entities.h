#ifndef ENTITIES_H
#define ENTITIES_H

#include<vector>
#include<string>

using namespace std;

class bossGrimcrackle;

class playerStats
{
public:

	void playerInfo();

	playerStats();

	void setName(string newPlayerName) { playerName = newPlayerName; }
	string getName() { return playerName; }

	void setHealth(int newPlayerHealth) { playerHealth = newPlayerHealth; }
	int getHealth() { return playerHealth; }

	void randPlayerDamage();
	int getDamage() { return playerDamage; }

	void addItem(string item);
	void showInventory();

	int getMaxHit() { return maxHit; }

	void bossDefeatCounter() { bossesDefeated++; }
	int getBossesDefeated() { return bossesDefeated++; }

	bool applyConsumables();
	void applyItems();

	int playerAttack();
	void playerDefence(int damage);

private:

	string playerName;
	int playerHealth;
	int playerDamage;
	int maxHit;
	vector<string>inventory;
	int bossesDefeated;
};

//#####################################################################################

class bossGrimcrackle
{
public:

	void bossInfo();

	bossGrimcrackle();

	void setHealth(int _bossHealth) { bossHealth = _bossHealth; }
	int getHealth() { return bossHealth; }

	void setName(string _bossName) { bossName = _bossName; }
	string getName() { return bossName; }

	void randBossDamage();
	void setDamage(int _bossDamage) { bossDamage = _bossDamage; }
	int getDamage() { return bossDamage; }

	void rollDropTable(playerStats &player);
	void showDropTable();

	void setMaxHit(int _maxHit) { maxHit = _maxHit; }
	int getMaxHit() { return maxHit; }

	int attack();
	void defence(int damage);

	void bossBuff();

	void setBossLives(int _bossLives) { bossLives = _bossLives; }
	int getBossLives() { return bossLives; }


private:

	string bossName;
	int bossHealth;
	int bossDamage;
	const static int dropTableSize = 3;
	string drops[dropTableSize];
	int maxHit;
	int bossLives = 3;
};

//#####################################################################################

class bossRazorwing : public bossGrimcrackle
{
public:

	bossRazorwing();
	void bossInfo();
	void randBossDamage();
	int attack();
	void defence(int damage);
	void rollDropTable(playerStats &player);
	void showDropTable();
	void bossBuff();


private:
	const static int dropTableSize = 3;
	string drops[dropTableSize];
};

//#########################################################################################

class bossTanglebug : public bossGrimcrackle
{
public:
	
	bossTanglebug();
	void bossInfo();
	void randBossDamage();
	int attack();
	void defence(int damage);
	void rollDropTable(playerStats &player);
	void showDropTable();
	void bossBuff();
private:
	const static int dropTableSize = 3;
	string drops[dropTableSize];
};
//WISE OLD MAN FINAL BOSS NAME

#endif // ENTITIES_H