#pragma once
#include "Imports.h"
#include "Enemy.h"
class Player
{
public:
	Player(std::string x, int y, int z, int h)
	{
		pl_name = x;
		pl_attack = y;
		pl_special_attack = z;
		pl_hp = h;
		pl_max_hp = h;
		is_dead = false;
		pl_silver = 0, pl_gold = 0;
		can_do_super_attack = true;
		cooldown_num = 2;
	}

	void AttackEnemy(Enemy *e,int attack_mode=0)
	{
		if(!is_dead)
		{
			switch (attack_mode)
			{
			default:
				break;
			case 1:
				e->TakeDamage(pl_attack);
				cooldown_num++;
				if (cooldown_num >= 2)
					can_do_super_attack = true;
				break;
			case 2:
				if (can_do_super_attack == true)
				{
					e->TakeDamage(pl_special_attack);
					can_do_super_attack = false;
					cooldown_num = 0;
					break;
				}

				else
				{
					std::cout << "Couldn't do super attack, its not charged up yet!\n\n";
				}
			}
		}
	}

	void TakeDamage(int damage)
	{
		if (!is_dead)
		{
			std::cout << "\n"+pl_name + " took " + std::to_string(damage) + " damage!\n\n";
			pl_hp -= damage;

			if (pl_hp <= 0)
			{
				std::cout << "\n"+pl_name + " died! :(\n";
				is_dead = true;
			}
		}
	}

	void GetStats()
	{
		std::cout << "\n"+pl_name << " -- Player Name\n";
		std::cout << pl_attack << " -- Attack\n";
		std::cout << pl_special_attack << " -- S Attack\n";
		std::cout << pl_hp << " -- HP\n";
		std::cout << pl_silver << " -- Silver Coins\n";
		std::cout << pl_gold << " -- Gold Coins\n\n";
	}

	int GetHP() { return pl_hp; };

	void Heal(int amount)
	{
		if (pl_hp >= pl_max_hp)
		{
			std::cout << "\nCould not heal " + pl_name + " because he is already at max hp!\n";
		}
		else
		{
			std::cout << "\nHealed " + pl_name + " " + std::to_string(amount) + "HP!\n";
			pl_hp += amount;
			if (pl_hp > 0)
			{
				std::cout << "\n"+pl_name + " is back alive!\n";
				is_dead = false;
			}
		}
	}

	void AddMoney(int silver,int gold=0)
	{
		if (pl_silver + silver < 100)
			pl_silver += silver;

		else if (pl_silver + silver == 100)
			pl_gold += 1;

		else if (pl_silver+silver>100){
			int temp = pl_silver + silver/100;
			pl_gold += temp;
		}
	}

private:
	std::string pl_name;
	int pl_attack;
	int pl_special_attack;
	int pl_hp;
	bool is_dead = false;
	int pl_max_hp;
	int pl_silver;
	int pl_gold;
	bool can_do_super_attack;
	int cooldown_num;
};