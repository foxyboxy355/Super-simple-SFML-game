#pragma once
#include "Imports.h"

class Enemy
{
public:
	virtual void TakeDamage(int damage)
	{
		if (!is_dead) 
		{
			if (e_hp <= 0) 
			{
				is_dead = true;
				std::cout << e_type + " died :)\n\n";
			}
			else
			{
				e_hp -= damage;
			}
		}
			
	}
	virtual void GetStats()
	{
		std::cout << e_type << " -- Type\n";
		std::cout << e_damage << " -- Damage\n";
		std::cout << e_hp << " -- Enemy HP\n\n";
	}

	int GetDamage() { return e_damage; };
	int GetHP() { return e_hp; };
	std::string e_type = "Default enemy";
	int GetReward() { return e_reward; };
protected:
	
	int e_damage=10;
	int e_hp=50;
	int e_reward = 10;
	bool is_dead = false;
};

class Ninja : public Enemy
{
public:
	void TakeDamage(int damage)
	{
		if (!is_dead)
		{
			if (e_hp <= 0)
			{
				is_dead = true;
				std::cout << e_type + " died :)\n\n";
			}
			else
			{
				e_hp -= damage;
			}
		}
	}
	void GetStats()
	{
		std::cout << e_type << " -- Enemy Type\n";
		std::cout << e_damage << " -- Damage\n";
		std::cout << e_hp << " -- Enemy HP\n\n";
	}
	
	int GetDamage() { return e_damage; };
	int GetHP() { return e_hp; };
	std::string e_type = "Ninja";
	int GetReward() { return e_reward; };
protected:
	
	int e_damage=50;
	int e_hp=60;
	int e_reward = 50;
};

class Reaper : public Enemy
{
public:
	void TakeDamage(int damage)
	{
		if (!is_dead)
		{
			if (e_hp <= 0)
			{
				is_dead = true;
				std::cout << e_type + " died :)\n\n";
			}
			else
			{
				e_hp -= damage;
			}
		}
	}
	void GetStats()
	{
		std::cout << e_type << " -- Enemy Type\n";
		std::cout << e_damage << " -- Damage\n";
		std::cout << e_hp << " -- Enemy HP\n\n";
	}

	int GetDamage() { return e_damage; };
	int GetHP() { return e_hp; };
	int GetReward() { return e_reward; };
	std::string e_type = "Reaper";
protected:
	
	int e_damage = 30;
	int e_hp = 120;
	int e_reward = 60;
};
