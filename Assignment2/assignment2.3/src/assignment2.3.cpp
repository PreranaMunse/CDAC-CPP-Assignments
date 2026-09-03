//============================================================================
// Name        : 3.cpp
// Author      : prer
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;

class Entity{

private :

	string name;
	int health;
	int level;
	string type;


public :

 Entity& setName(const string& name)
{
	this->name = name;
	return *this;
}

Entity& setHealth(int health)
{
	this->health = health;
	return *this;
}
Entity& setLevel(int level)
{
	this->level = level;
	return *this;
}
Entity& setType(const string& type)
{
	this->type = type;
	return *this;

}

string getName()  const
{
	return name;
}
int getHealth() const
{
	return health;
}
int getLevel()  const
{
	return level;
}
string getType()  const
{
	return type;
}

void displayInfo() const
{
	cout << "Name : " << name << endl;
    cout << "Health : " << health << endl;
    cout <<"Level : " << level << endl;
    cout << "Type : " << type << endl;
}

};

//-----------Part B

namespace Physics {

double clamp(double val, double min, double max)
{
	if (val < min) return min;
	        if (val > max) return max;
	        return val;
}
double lerp(double a, double b, double t)
{
	return a + t * (b - a);
}
}

namespace GameMath {


int clamp(int val, int min, int max)
	{
		if (val < min)
			return min;
		if (val > max) return max;
		    return val;
	}


double lerp(double a, double b, double t)
{
	return a + t * (b - a);
}
}

int main() {

	Entity player, enemy, item;

	player.setName("Aragorn").setHealth(100).setLevel(10).setType("Player");

	enemy.setName("Orc").setHealth(60).setLevel(5).setType("Enemy");

	item.setName("HealthPotion").setHealth(0).setLevel(1).setType("Item");

	player.displayInfo();
	enemy.displayInfo();
	item.displayInfo();

	//------------Part B


	    double velocity = 150.5;
	    double clampedVelocity = Physics::clamp(velocity, -100.0, 100.0);
	    cout << "Physics::clamp -> clamped velocity = " << clampedVelocity << endl;

	    double physLerp = Physics::lerp(0.0, 10.0, 0.5);
	    cout << "Physics::lerp  -> interpolated value = " << physLerp << endl;

	    int health = 120;
	    int clampedHealth = GameMath::clamp(health, 0, 100);
	    cout << "GameMath::clamp -> clamped health = " << clampedHealth << endl;

	    double uiLerp = GameMath::lerp(0.0, 1.0, 0.25);
	    cout << "GameMath::lerp  -> UI animation value = " << uiLerp << endl;

	    {

	        using namespace GameMath;

	        int level = 25;
	        int clampedLevel = clamp(level, 1, 20);
	        cout << "\n[Block scope] using namespace GameMath;" << endl;
	        cout << "GameMath clamp (unqualified) -> clamped level = " << clampedLevel << endl;

	        double animVal = GameMath::lerp(0.0, 5.0, 0.6);
	        cout << "GameMath lerp (unqualified) -> animation value = " << animVal << endl;
	    }
	    cout << "\n[Outside block] back to needing full qualification:" << endl;
	    cout << "Physics::clamp(200.0, 0.0, 50.0) = "
	         << Physics::clamp(200.0, 0.0, 50.0) << endl;



	return 0;
}
