#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include"entities.h"

void mainMenu(playerStats &player);



bool bossFightGrimcrackle(playerStats &player, bossGrimcrackle &Grimcrackle);
bool bossGrimcrackleOutcome(playerStats &player, bossGrimcrackle &boss);


bool bossFightRazorwing(playerStats &player, bossRazorwing &Razorwing);
bool bossRazorwingOutcome(playerStats &player, bossRazorwing &boss);


void endGameStats(playerStats &player);

void itemInfo();
#endif // !FUNCTIONS_H

