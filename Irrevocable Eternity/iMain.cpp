#include<iostream>
using namespace std;
#include "iGraphics.h"
#include "variable.h"
#include "images.h"
#include "menu.h"
#include "movement.h"
#include "level1.h"
#include "level2.h"
#include "save.h"


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://


void iDraw()
{
	levelChange();
	if (!leveltwo)
		iClear();
	
	if (gameState == -2){
		//load screen
		loadingfunc();
	}

	else if (gameState == -1){
		//menu
		menuscreen();
		stopall();
	}

	else if (gameState == 0 && !leveldone){
		//play
		menuscreen();
		iShowImage(150, 75, 500, 350, playimage);
		stopall();

	}

	else if (gameState == 1){
		if (levelone){
			iResumeTimer(boxtimer);
			iResumeTimer(enemytimer);
			///iResumeTimer(jumptimer);
			iResumeTimer(runtimer);
			iResumeTimer(scoretimer);

			iPauseTimer(coincollectimer);
			iPauseTimer(dragontimer);
			iPauseTimer(flytimer);
			iPauseTimer(changebgtimer);

			groundset();
			levelonefunc();
		
		}
		else if (leveltwo){
			iResumeTimer(scoretimer);
			iResumeTimer(dragontimer);
			iResumeTimer(flytimer);
			iResumeTimer(changebgtimer);
			iResumeTimer(coincollectimer);
			
			iPauseTimer(boxtimer);
			iPauseTimer(enemytimer);
		//	iPauseTimer(jumptimer);
			iPauseTimer(runtimer);

			leveltwofunc();
		}

	}
	else if (gameState == 2){
		//music
		menuscreen();
		iShowImage(270, 100, 260, 240, musicimage);
		stopall();
	}
	else if (gameState == 3){
		//standing
		iShowImage(0, 0, 800, 500, standingbg);
		showstandings();
		stopall();
	}
	else if (gameState == 4){
		//exit
		menuscreen();
		iShowImage(270, 100, 260, 240, exitimage);
		stopall();
	}
	else if (gameState == 5){
		//about us
		iShowImage(0, 0, 800, 500, aboutus);
		stopall();
	}
	else if (gameState == 6){
		//instructuion
		iShowImage(0, 0, 800, 500, instructions);
		stopall();
	}
	if (leveldone){
		iShowImage(0, 0, 800, 500, levelcompleteimage);
		if (levelComplete == 1){
			levelscoresave();
		}
	}

	if (gameState != -1){
		iShowImage(740, 440, 50, 50, homeimage);
	}

}

void iMouseMove(int mx, int my)
{
	//printf("x = %d y =%d\n", mx, my);

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	printf("x = %d y =%d\n", mx, my);
}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)///{---->attack trigger 
	{

		//main menu
		if (gameState !=1){
			menuoption(mx, my);
		}


		//home button
		if (mx >= 740 && mx <= 790 && my >= 440 && my <= 490 && gameState != -1)
		{
			pauseGame();
			if (leveldone){
				leveldone = false;
				if (levelComplete == 1){
					levelone = false;
					leveltwo = true;
					gameState = 0;
				}
				if (levelComplete == 2){
					standings();
					gameState = 3;
				}
			}
			gameState = -1;
		}


		//attack

		attack = true;
		atkanimation = true;

		if (cas == 0 && natanAtkIndex < 2 && attack)
			natanAtkIndex++;
		else if (natanAtkIndex > 1)
			natanAtkIndex = 0;

		if (cas == 1 && natanaltAtkIndex < 2 && attack)
			natanaltAtkIndex++;
		else if (natanaltAtkIndex > 1)
			natanaltAtkIndex = 0;
	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		if (!running)
		{
			sheild = true;
			
		}									////---->sheilding trigger button
	}
}

void iKeyboard(unsigned char key)
{
	if (key == 'l'){
		scrn++;
	}
	natanMove(key);

}

void iSpecialKeyboard(unsigned char key)
{

}



int main()
{
	iInitialize(SCREENWIDTH, SCREENHEIGHT, "Irrevocable Eternity");
	//if (levelone)
		setVariable();
		boxtimer=iSetTimer(35, boxchange);//jump animation also
		enemytimer=iSetTimer(35, enemy);
		//jumptimer=iSetTimer(35, jumpAnimation);
		runtimer=iSetTimer(120, runAnimation);
		death = iSetTimer(150, natdeath);
	
		
	//else if (leveltwo)
		setBg();
		setCoinVariable();
		dragontimer=iSetTimer(50, dragonAnimation);//coinn change animation also
		scoretimer=iSetTimer(1000, scorefunc);
		flytimer=iSetTimer(400, dragonfly);
		changebgtimer=iSetTimer(100, changeBg);
		coincollectimer = iSetTimer(50, Coincollect);
		//iSetTimer(100, changeCoin);
	
	//if (levelone || gameState==-2)
		t1sectimer=iSetTimer(1000, t1sec);

	if (musicOn){
		PlaySound("sound\\menumusic.wav", NULL, SND_LOOP | SND_ASYNC);
	}

	images();

	iStart();
	return 0;
}