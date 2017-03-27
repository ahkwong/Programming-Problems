#include <iostream>
#include <string>

using namespace std;

enum class MonsterType
{
	OGRE,
	DRAGON,
	ORC,
	GIANT_SPIDER,
	SLIME
};

struct Monster
{
	MonsterType type;
	string name;
	int health;
};

string getMonsterTypeName(Monster monster)
{
	switch (monster.type)
	{
	case MonsterType::OGRE:
		return "Ogre";
	case MonsterType::DRAGON:
		return "Dragon";
	case MonsterType::ORC:
		return "Orc";
	case MonsterType::GIANT_SPIDER:
		return "Giant Spider";
	case MonsterType::SLIME:
		return "Slime";
	default:
		return "Unknown";
	}
}

void printMonster(Monster monster)
{
	cout << "This " << getMonsterTypeName(monster) << " is named ";
	cout << monster.name << " and has " << monster.health << "health." << endl;
}

int main()
{
	Monster ogre = { MonsterType::OGRE, "Torg", 100 };
	Monster slime = { MonsterType::SLIME, "Pouring", 10 };

	printMonster(ogre);
	printMonster(slime);

	system("pause");
	return 0;
}