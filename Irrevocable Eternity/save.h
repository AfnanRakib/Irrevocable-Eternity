#ifndef HEADER_H_SAVE
#define HEADER_H_SAVE

#include "variable.h"

#include <iostream>
using namespace std;

struct GameState
{
	int levelComplete;
	int scrn;
	int hHitpoints;
	int dHitpoints;
	int scorepoint;
	int scorei;
	int scorej;
	int scorek;


	GameState()
	{
	}

	GameState(int _levelComplete, int _scrn, int _hHitpoints, int _dHitpoints, int _scorepoint, int _scorei, int _scorej, int _scorek)
	{
		levelComplete = _levelComplete;
		scrn = _scrn;
		hHitpoints = _hHitpoints;
		dHitpoints = _dHitpoints;
		scorepoint = _scorepoint;
		scorei = _scorei;
		scorej = _scorej;
		scorek = _scorek;
	}

	void setValues(int _levelComplete, int _scrn, int _hHitpoints, int _dHitpoints, int _scorepoint, int _scorei, int _scorej, int _scorek)
	{
		levelComplete = _levelComplete;
		scrn = _scrn;
		hHitpoints = _hHitpoints;
		dHitpoints = _dHitpoints;
		scorepoint = _scorepoint;
		scorei = _scorei;
		scorej = _scorej;
		scorek = _scorek;
	}
} game_state(0, 1, 10, 10, 0, 0, 0, 0), gameresume(0, 1, 10, 10, 0, 0, 0, 0), level1score(0, 1, 10, 10, 0, 0, 0, 0);



void levelscoresave(){
	level1score.setValues(levelComplete, scrn, hHitpoints, dHitpoints, scorepoint, scorei, scorej, scorek);
}

void level1scoreload(){
	levelComplete = level1score.levelComplete;
	scrn = level1score.scrn;
	hHitpoints = level1score.hHitpoints;
	dHitpoints = level1score.dHitpoints;
	scorepoint = level1score.scorepoint;
	scorei = level1score.scorei;
	scorej = level1score.scorej;
	scorek = level1score.scorek;
}

void showstandings(){
	FILE *fp = fopen("score.txt", "r");
	int x = 0;
	char s[3][100];
	while (fscanf(fp, "%s", s[x]) != EOF){
		x++;
	}
	iSetColor(0, 0, 0);
	iText(300, 300, "RAKIB", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(400, 300, s[0], GLUT_BITMAP_TIMES_ROMAN_24);
	iText(300, 200, "TAJRIN", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(400, 200, s[1], GLUT_BITMAP_TIMES_ROMAN_24);
	iText(300, 120, "DIPTO", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(400, 120, s[2], GLUT_BITMAP_TIMES_ROMAN_24);
	fclose(fp);
}

void standings(){
	FILE *fp = fopen("score.txt", "r");
	int x = 0;
	int tmp;
	while (fscanf(fp, "%d", &arr1[x]) != EOF){
		x++;
	}
	arr1[3] = scorepoint;
	for (int i = 0; i<4; i++)
	{
		for (int j = i + 1; j<4; j++)
		{
			if (arr1[j] > arr1[i])
			{
				tmp = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = tmp;
			}
		}
	}
	//printf("now:    %d\n%d\n%d\n", arr1[0], arr1[1], arr1[2]);
	fclose(fp);
	fp = fopen("score.txt", "w");	
	fprintf(fp, "%d\n%d\n%d\n", arr1[0], arr1[1], arr1[2]);
	fclose(fp);
}

void saveGame()
{
	FILE *fp = fopen("data.txt", "w");

	game_state.setValues(levelComplete, scrn, hHitpoints, dHitpoints, scorepoint, scorei, scorej, scorek);

	fprintf(fp, "%d %d %d %d %d %d %d %d", game_state.levelComplete, game_state.scrn, game_state.hHitpoints, game_state.dHitpoints, game_state.scorepoint, game_state.scorei, game_state.scorej, game_state.scorek);
	cout << "Game saved!" << endl;

	fclose(fp);
}

void newGame(){
	levelComplete = 0;
	scrn = 1;
	hHitpoints = 10;
	dHitpoints = 10;
	scorepoint = 0;
	scorei = 0;
	scorej = 0;
	scorek = 0;
	i = 0;
	natanCordinateX = 0;
	hDeath = false;
	dragondeath = false;
	bool levelone = true;
	bool leveltwo = false;

}

void pauseGame(){
	gameresume.setValues(levelComplete, scrn, hHitpoints, dHitpoints, scorepoint, scorei, scorej, scorek);
}
void stopall(){
	//levelComplete = 0;
	//scrn = 1;
	//hHitpoints = 10;
	//dHitpoints = 10;
	//scorepoint = 0;
	//scorei = 0;
	//scorej = 0;
	//scorek = 0;
	iPauseTimer(dragontimer);
	iPauseTimer(death);
	iPauseTimer(coincollectimer);
	iPauseTimer(flytimer);
	iPauseTimer(changebgtimer);
	iPauseTimer(boxtimer);
	iPauseTimer(enemytimer);
	iPauseTimer(scoretimer);
	iPauseTimer(runtimer);
}

void resumeGame(){
	levelComplete = gameresume.levelComplete;
	scrn = gameresume.scrn;
	hHitpoints = gameresume.hHitpoints;
	dHitpoints = gameresume.dHitpoints;
	scorepoint = gameresume.scorepoint;
	scorei = gameresume.scorei;
	scorej = gameresume.scorej;
	scorek = gameresume.scorek;
}

void loadGame()
{

	FILE *fp = fopen("data.txt", "r");

	if (fp == NULL)
	{
		cout << "File not found!" << endl;
		levelComplete = 0;
		scrn = 1;
		hHitpoints = 10;
		dHitpoints = 10;
		scorepoint = 0;
		scorei = 0;
		scorej = 0;
		scorek = 0;
	}
	else
	{
		int a[8];

		int i = 0;
		while (fscanf(fp, "%d", &a[i]) != EOF){
			i++;
		}

		levelComplete = a[0];
		scrn = a[1];
		hHitpoints = a[2];
		dHitpoints = a[3];
		scorepoint = a[4];
		scorei = a[5];
		scorej = a[6];
		scorek = a[7];

		cout << "Game loaded!" << endl;
		fclose(fp);
	}
}


#endif