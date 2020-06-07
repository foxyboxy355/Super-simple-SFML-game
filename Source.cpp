#include "Imports.h"
using namespace GameFunctions;
using namespace oth;

//define variables
std::string name = "Mr POOPY Pants jr.";

std::shared_ptr<Player> player{ new Player(name, 30, 60, 300) };
std::shared_ptr<Reaper> reaper1{ new Reaper() };

void ChooseAttack()
{
	SlowLog("What do you want to do?\n");
	Log("1. Basic attack\n2. S Attack\n");
	char temp;
	std::cin >> temp;
	switch (temp)
	{
	default:
		break;
	case '1':
		AttackEnemy(reaper1.get(), player.get(), 1);
		break;
	case '2':
		AttackEnemy(reaper1.get(), player.get(), 2);
		break;
	}
}

void Tutorial()
{
	SlowLog("Welcome to Legend of The Reaper! This is the tutorial, for the most elite game in history!\nJust kidding it's terrible :P\n\n");
	
	//make the game work
	SlowLog("These are your player stats:");
	player->GetStats();
	Sleep(1000);
	SlowLog("OH NO! Look, a reaper has appeared! Unfortunately it dealt some damage to you, lets get revenge on it!\nHere are its stats:\n\n");
	EnemyAttack(player.get(), reaper1.get());
	reaper1->GetStats();
	Sleep(1000);

	while (reaper1->GetHP() > 0)
	{
		ChooseAttack();

		if (reaper1->GetHP() > 0)
		{
			SlowLog("\nLooks like the reaper is not dead yet, hit more!\nREAPER HP:" + std::to_string(reaper1->GetHP())+"\n");
		}
		else 
		{
			SlowLog("\nYou killed the reaper! Well done, hopefully it wont be the last one you have killed!\n");
			break;
		}
	}

	//introduction to the economy system

	SlowLog("\nAs a reward for killing the reaper, you have gained: "+std::to_string(reaper1->GetReward())+" silver!\n");
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //checks memory leaks
	Tutorial();
}