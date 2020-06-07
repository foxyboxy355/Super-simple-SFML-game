#pragma once
#include "Player.h"
#include "Enemy.h"
#include <time.h>

namespace GameFunctions
{
	template <class T, class A >
	void EnemyAttack(T* p, A* e)
	{
		p->TakeDamage(e->GetDamage());
	}
	void AttackEnemy(Enemy* e,Player* p,int mode=1)
	{
		switch (mode)
		{
		default:
			break;
		case 1:
			p->AttackEnemy(e,1);
			break;
		case 2:
			p->AttackEnemy(e, 2);
			break;
		}
	}

	void HealPlayer(Player* p,int amount)
	{
		p->Heal(amount);
	}
}