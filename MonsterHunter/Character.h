#pragma once
class Character {
public:
	void drawObject(int x, int y, const char * str);
	bool battle(Character mob);
	void drawBox();
	void initCharacter(int hp, int luk, int atk, int def, char* symbol, char*name, short x, short y);
	void drawCharacter();
	void moveCharacter(char key);
	bool getHP();

	short x;
	short y;
	short mobCount = 3;
private:
	char* name;
	int hp;
	int luk;
	int atk;
	int def;
	char* Symbol;
};