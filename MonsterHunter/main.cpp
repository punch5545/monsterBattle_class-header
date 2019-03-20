#include <iostream>
#include "Character.h"
#include <Windows.h>
#include <conio.h>
#include <time.h>

Character player;
Character monster[3];

bool colCheck(int i);
int mobCount = 2;

void main() {
	srand((unsigned int)time(0));

	player.initCharacter(50,20,10,10,(char*)"¡Ú",(char*)"PLAYER", 9, 9);
	for (int i = 0; i < 3; i++) {
		int hp = rand() % 30 + 1;
		int atk = rand() % 20 + 1;
		int def = rand() % 20 + 1;
		int luk = rand() % 20 + 1;
		int x = rand() % 108 + 5;
		int y = rand() % 18 + 3;
		monster[i].initCharacter(hp, luk, atk, def, (char*)"¢Á", (char*)"Monster" + (i + 1),x ,y);
	}
	while (player.getHP()) {
		player.drawBox();
		system("cls");
		player.drawBox();
		player.drawCharacter();
		for (int i = 0; i < 3; i++) { monster[i].drawCharacter(); }
		for (int i = 0; i < 3; i++) {
			if (colCheck(i)) {
				if (player.battle(monster[i])) {
					monster[i].initCharacter(0, 0, 0, 0, (char*)"", 0, 0, 0);
					if (mobCount == 0)
					{
						for (int i = 60; i > 25; i--) {
							system("cls");
							player.drawObject(i, 7, "      ::::::::   :::        ::::::::::      :::      ::::::::: \n");
							player.drawObject(i, 8, "    :+:    :+:  :+:        :+:           :+: :+:    :+:    :+: \n");
							player.drawObject(i, 9, "   +:+         +:+        +:+          +:+   +:+   +:+    +:+  \n");
							player.drawObject(i, 10, "  +#+         +#+        +#++:++#    +#++:++#++:  +#++:++#:    \n");
							player.drawObject(i, 11, " +#+         +#+        +#+         +#+     +#+  +#+    +#+    \n");
							player.drawObject(i, 12, "#+#    #+#  #+#        #+#         #+#     #+#  #+#    #+#     \n");
							player.drawObject(i, 13, "########   ########## ##########  ###     ###  ###    ###      \n");
							//Sleep(500);
						}
					}
					else {
						mobCount--;
					}
				}
			}
		}
		char key = getch();
		//_getch();
		if (key == 'q')
			break;
		player.moveCharacter(key);
	}
}

bool colCheck(int i) {
	if (monster[i].getHP()) {
		if (player.x == monster[i].x) {
			if (player.y == monster[i].y - 1)
				return true;
			else if (player.y == monster[i].y + 1)
				return true;
		}
		else if (player.y == monster[i].y) {
			if (player.x == monster[i].x + 2)
				return true;
			else if (player.x == monster[i].x - 2)
				return true;
		}
	}
	return false;
}