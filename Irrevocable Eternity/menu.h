#ifndef HEADER_H_MENU
#define HEADER_H_MENU

#include "variable.h"
#include "save.h"


void menuscreen(){
	iShowImage(0, 0, 800, 500, menuBG[0]);
	iShowImage(190, 10, 420, 480, menuBG[1]);
}

void loadingfunc(){
	loading++;
	iShowImage(0, 0, 800, 500, startupImg[startup]);
	if (loading >= 7000){
		gameState = -1;
	}
}


void menuoption(int mx, int my){

		//play
	if (mx >= SCREENWIDTH*0.46 && mx <= SCREENWIDTH*0.545 && my >= SCREENHEIGHT*0.52 && my <= SCREENHEIGHT*0.66 && gameState == -1){
			gameState = 0;
		}
		//sound
	else if (mx >= SCREENWIDTH*0.563 && mx <= SCREENWIDTH*0.613 && my >= SCREENHEIGHT*0.44 && my <= SCREENHEIGHT*0.54 && gameState == -1)
		{
			gameState = 2;
		}
		//standing
	else if (mx >= SCREENWIDTH*0.4 && mx <= SCREENWIDTH*0.45 && my >= SCREENHEIGHT*0.44 && my <= SCREENHEIGHT*0.54 && gameState == -1){
		standings();
		gameState = 3;
	}		
		//exit
	else if (mx >= SCREENWIDTH*0.4 && mx <= SCREENWIDTH*0.45 && my >= SCREENHEIGHT*0.31 && my <= SCREENHEIGHT*0.39 && gameState == -1)
			gameState = 4;
		//about us
	else if (mx >= SCREENWIDTH*0.482 && mx <= SCREENWIDTH*0.525 && my >= SCREENHEIGHT*0.31 && my <= SCREENHEIGHT*0.39 && gameState == -1)
			gameState = 5;
		//instruction
	else if (mx >= SCREENWIDTH*0.563 && mx <= SCREENWIDTH*0.613 && my >= SCREENHEIGHT*0.31 && my <= SCREENHEIGHT*0.39 && gameState == -1)
			gameState = 6;



	//---------------------------------------------inside exit menu
	else if (mx >= 323 && mx <= 370 && my >= 189 && my <= 250 && gameState == 4)
	{
		//no
		gameState = -1;
	}
	else if (mx >= 430 && mx <= 479 && my >= 192 && my <= 248 && gameState == 4)
	{
		//yes
		exit(0);
	}





	//--------------------------------------------inside play menu
	else if (mx >= 298 && mx <= 497 && my >= 332 && my <= 383 && gameState == 0)
	{
		//resume Game
		if (dragondeath){
			level1scoreload();
			dragondeath = false;
		}
		else{
			resumeGame();
		}
		gameState = 1;
	}
	else if (mx >= 274 && mx <= 523 && my >= 258 && my <= 309 && gameState == 0)
	{
		//new Game
		newGame();
		gameState = 1;
	}
	else if (mx >= 264 && mx <= 530 && my >= 179 && my <= 232 && gameState == 0)
	{
		//load game
		loadGame();
		gameState = 1;
	}
	else if (mx >= 264 && mx <= 529 && my >= 105 && my <= 156 && gameState == 0)
	{
		// save game
		saveGame();
	}




	//---------------------------------------------inside sound menu
	else if (mx >= 428 && mx <= 475 && my >= 174 && my <= 232 && gameState == 2)
	{
		if (musicOn){
			musicOn = false;
			PlaySound(0, 0, 0);
		}
	}
	else if (mx >= 323 && mx <= 367 && my >= 176 && my <= 233 && gameState == 2)
	{
		if (!musicOn){
			musicOn = true;
			PlaySound("sound\\menumusic.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}




}

#endif