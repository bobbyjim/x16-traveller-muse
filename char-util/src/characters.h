#ifndef _CHARACTERS_H_
#define _CHARACTERS_H_

typedef struct  {
	unsigned id;
	unsigned playerId; // if 0 then not assigned
	char name[16];     // null terminated
	char upp[7];       // null terminated
	char sophont;      // sophont type (A=Aslan, M=Amindii, B=Bwap, D=Droyne, H=Human, V=Vargr, L=Llellewyloly,S=Shrieker)
	char st;           // 'O'=OK 'W'=wounded 'S'=severely wounded 'C'=critical 'X'=dead 
	char career;       // M=Merchant, S=Scout, A=Army, G=Agent, N=Navy, R=Rogue, I=Marines
	char terms;        // number of terms served
	char skillLevel[16];
	int bestSkill; 	   // highest value skill
} CharacterStruct;

void characters_generateRegistry();
void characters_showRegistry();
void characters_saveRegistry();
void characters_loadRegistry();

#endif // _CHARACTERS_H_
