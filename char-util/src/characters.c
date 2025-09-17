
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <cx16.h>

#include "name.h"
#include "characters.h"

CharacterStruct character_registry[20];
#define MAX_CHARACTERS 20

char* sophonts[] = { "", "aslan", "amindii", "bwap", "droyne", "human", "vargr", "llellewyloly", "shrieker" };
char* getSophontType(char c) {
    int index = 0;
	switch(c) {
		case 'a': index = 1; break;
		case 'm': index = 2; break;
		case 'b': index = 3; break;
		case 'd': index = 4; break;
		case 'h': index = 5; break;
		case 'v': index = 6; break;
		case 'l': index = 7; break;
		case 's': index = 8; break;
	}
	return sophonts[index];
}

char* careers[] = { "unknown", "merchant", "scout", "scholar", "army", "agent", "navy", "rogue", "marine" };
char* getCareerType(char c) {
	int index = 0;
	switch(c) {
		case 'm': index = 1; break;
		case 's': index = 2; break;
		case 'c': index = 3; break;
		case 'a': index = 4; break;
		case 'g': index = 5; break;
		case 'n': index = 6; break;
		case 'r': index = 7; break;
		case 'i': index = 8; break;
	}
	return careers[index];
}

char* status[] = { "unknown", "ok", "wounded", "serious", "critical", "dead" };
char* getStatusType(char c) {
	int index = 0;
	switch(c) {
		case 'o': index = 1; break;
		case 'w': index = 2; break;
		case 's': index = 3; break;
		case 'c': index = 4; break;
		case 'x': index = 5; break;
	}
	return status[index];
}

char* skills[] = { "astrogator", "bureaucrat", "diplomat", "engineer",
                   "fighter", "gunner", "hostile env", "medic", 
				   "pilot", "sensop", "steward", "streetwise", 
				   "survey", "survival", "trader", "vacc suit" };

void upp_generate(char *upp) {
	int i;
	const char *attributes = "23456789abc";
	for (i = 0; i < 6; i++) {
		upp[i] = attributes[rand() % 6 + rand() % 6];
	}
	upp[6] = '\0'; // Null-terminate the string
}

void characters_generateOneCharacterAt(int i) {
	int skillCount;
	int bestSkill = 0;
	character_registry[i].id = rand();
	name_generate(character_registry[i].name);
	upp_generate(character_registry[i].upp);
	character_registry[i].sophont = "ambdhhhhvls"[rand() % 6 + rand() % 6];
	character_registry[i].st = 'o'; // OK
	character_registry[i].career = "mscagnri"[rand() % 8];
	character_registry[i].terms = 1 + rand() % 4 + rand() % 4; // 1 to 7 terms
	skillCount = character_registry[i].terms * 2 + rand() % 3; // number of skills
	while(--skillCount) {
		int j = rand() % 16;
		if (character_registry[i].skillLevel[j] > 5) { // ceiling
			continue; // skip it, since this character has a huge skill asset already
		}
		character_registry[i].skillLevel[j] += 1 + rand() % 3; // increment random skill
		if (character_registry[i].skillLevel[j] > character_registry[i].skillLevel[bestSkill]) {
			bestSkill = j;
		}
	}
	character_registry[i].bestSkill = bestSkill;
}

void characters_generateRegistry()
{
	int i;

    for(i = 0; i < 20; i++) {
		characters_generateOneCharacterAt(i);
	}
}

void showCharacterDetails(int index) {
	int j;
	int salary = 0;

	if (index < 0 || index >= MAX_CHARACTERS) {
		printf("invalid character index\n");
		return;
	}
	clrscr();
	textcolor(COLOR_CYAN);
	bgcolor(COLOR_BLACK);
	printf("\n                      character details\n\n");
	textcolor(COLOR_GREEN);
	printf("   name:         %-12s   (%s %s)\n", character_registry[index].name, getStatusType(character_registry[index].st), getSophontType(character_registry[index].sophont));
	printf("   upp:          %s\n", character_registry[index].upp);
	printf("   career:       %s, %d terms\n", getCareerType(character_registry[index].career), character_registry[index].terms);
	printf("   salary:    cr %d\n", salary);
	
	//printf("Best Skill:   %s (%d)\n", skills[character_registry[index].bestSkill], character_registry[index].skillLevel[character_registry[index].bestSkill]);
	printf("\n   skills:\n");
	for(j = 0; j < 16; j++) {
		if (character_registry[index].skillLevel[j] > 0) {
			printf("      %-12s : %d\n", skills[j], character_registry[index].skillLevel[j]);
			salary += character_registry[index].skillLevel[j] * 100;
		}
	}
	gotoxy(17,6);
	printf("%d", salary);
	gotoxy(0,23);
	textcolor(COLOR_YELLOW);
	printf("\n   (d)elete   (f)ire   (h)ire   (r)eturn? ");
	for(;;) {
		int c = cgetc();
		if (c == 'r') return;
	}
}

void characters_showRegistry() {
	int i;
	char v;

	for(;;) {
		videomode(VIDEOMODE_80x30);
		textcolor(COLOR_CYAN);
		bgcolor(COLOR_BLACK);
		printf("                      character register\n\n");
		printf("         name         #   upp    st    sophont        best skill\n");
		printf("         ----         -   ------ ---   --------       -----------\n");
		for(i=0; i<MAX_CHARACTERS; i++) {
			textcolor(COLOR_CYAN);
			if (character_registry[i].playerId) {
				textcolor(COLOR_GRAY2); // gray out assigned characters
			}
			printf("         %-12s %c   %s %-3s   %-12s   %s\n", 
				character_registry[i].name, 
			    'a' + i,
				character_registry[i].upp, 
				getStatusType(character_registry[i].st),
				getSophontType(character_registry[i].sophont),
				skills[character_registry[i].bestSkill]
				//character_registry[i].skillLevel[character_registry[i].bestSkill]
			);
		}
		printf("\n   view (a-t; z quits)? ");
		v = cgetc();
		if (v == 'z') {
			return;
		}
		showCharacterDetails(v - 'a');
	}
}

void characters_loadRegistry() {
	characters_generateRegistry();
}

void characters_saveRegistry()
{
	// code to generate character registry goes here
	// FILE *fp = fopen("charreg.txt", "w");
	// if (fp == NULL) {
	// 	// handle error
	// 	printf("error opening character registry for writing\n");
	// 	return;
	// }
	// for (i = 0; i < 256; i++) {
	// 	if (fprintf(fp, "%d - character description\n", i) < 0) {
	// 		// handle error
	// 		printf("error writing to character registry\n");
	// 		fclose(fp);
	// 		return;
	// 	}
	// }
	// fclose(fp);
	// printf("character registry generated successfully!\n");
}
