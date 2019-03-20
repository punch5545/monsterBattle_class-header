#include <iostream>
#include "Character.h"
#include <Windows.h>
#include <time.h>
using namespace std;



void Character::drawObject(int x, int y, const char * str)
{
	COORD coord = { x,y }; //Coordnation: 좌표
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	printf("%s", str);
}

bool Character::battle(Character mob)
{
	srand(time(0));
	int turn = 2;
	while (mob.hp > 0 && this->hp > 0) {
		system("cls");
		if (turn % 2 == 0) { // player turn
			drawObject(2, 27, "Player Turn");
			if (mob.luk >= rand() % 200 + 1) {
				drawObject(2, 25, "Miss!                                                                                              ");
			}
			else {
				if (this->luk >= rand() % 50 + 1) { // 치명타, 방어력 무시
					mob.hp -= this->atk;
					drawObject(2, 25, "");
					printf("치명타! %d만큼의 대미지를 입혔습니다.   남은 체력: %d                                                  ", this->atk, mob.hp);
				}
				else {
					mob.hp -= this->atk - (this->atk * mob.def / 100); // 방어력% 만큼 공격 대미지 감쇠
					drawObject(2, 25, "");
					printf("유효타! %d만큼의 대미지를 입혔습니다.   남은 체력: %d                                               ", this->atk - (this->atk * mob.def / 100), mob.hp);
				}
			}
		}
		else { //mob turn
			drawObject(2, 27, "Enemy Turn  ");
			if (this->luk >= rand() % 50 + 1) {
				drawObject(2, 25, "Miss!                                    ");
			}
			else {
				if (this->luk >= rand() % 50 + 1) { // 치명타, 방어력 무시
					this->hp -= mob.atk;
					drawObject(2, 25, "");
					printf("치명타! %d만큼의 대미지를 입었습니다.  남은 체력: %d                                                 ", mob.atk, this->hp);
				}
				else {
					this->hp -= mob.atk - (mob.atk * this->def / 100); // 방어력% 만큼 공격 대미지 감쇠
					drawObject(2, 25, "");
					printf("유효타! %d만큼의 대미지를 입었습니다.  남은 체력: %d                                                 ", mob.atk - (mob.atk * this->def / 100), this->hp);
				}
			}
		}
		drawObject(0, 20, "Cur HP");
		for (int i = 0; i < this->hp; i++) {
			drawObject(i + 8, 20, "");
			printf("|           ");
		}
		drawObject(0, 23, "Mob HP");
		for (int i = 0; i < mob.hp; i++) {
			drawObject(i + 8, 23, "");
			printf("|           ");
		}
		Sleep(1500);
		turn++;
	}
	if (mob.hp < 1) {
		mob.initCharacter(0, 0, 0, 0, 0, 0, 0, 0);
		drawObject(2, 25, "Enemy Slayered!                                                                                     ");
	}
	else if (this->hp <= 0) {
		return false;
	}
	return true;
}


void Character::drawBox()
{
	int i;

	drawObject(2, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	for (i = 1; i < 24; i++) {
		drawObject(2, i, "┃");
		drawObject(116, i, "┃");
	}
	drawObject(2, 24, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}

void Character::initCharacter(int hp, int luk, int atk, int def, char * symbol, char * name, short x, short y)
{
	this->hp = hp;
	this->atk = atk;
	this->luk = luk;
	this->def = def;
	this->Symbol = symbol;
	this->name = name;
	this->x = x;
	this->y = y;
}

void Character::drawCharacter()
{
	drawObject(this->x, this->y, this->Symbol);
}

void Character::moveCharacter(char key)
{
	switch (key) {
	case 'w': this->y--; break;
	case 'a': this->x--; break;
	case 's': this->y++; break;
	case 'd': this->x++; break;
	default:break;
	}
}

bool Character::getHP()
{
	if (this->hp <= 0)
		return false;
	else
		return true;
}

