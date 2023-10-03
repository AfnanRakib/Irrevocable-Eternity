#ifndef HEADER_H_LEVEL2
#define HEADER_H_LEVEL2

#include "variable.h"


void leveltwofunc(){

	for (int i = 0; i < 16; i++){
		iShowImage(upperBackground[i].x, upperBackground[i].y, 50, 500, upperBg[i]);
		iShowImage(fireBackground[i].x, fireBackground[i].y, 40, 100, firebg);
	}

	if (dragonhurt)
	{

		dHitpoints--;
		dragonhurt = false;
		if (dHitpoints == 0){
			dragondeath = true;
			dragonhurt = false;
			flydown = false;
		}
		dragonhurtcnt++;
		if (dragonhurtcnt >= 3000)
		{
			dragonhurtcnt = 0;
			dragonhurt = false;
			flydown = true;
		}
	}
	else
		iShowImage(dragonCordinateX, dragonCordinateY, 100, 100, dragon[dragonIndex]);

	for (int j = 0; j < 10; j++){
		if (c[j].coinShow)
		{
			iShowImage(c[j].coin_x, c[j].coin_y, c[j].coin_w, c[j].coin_h, coin[0]);
		}
	}



		iShowImage(score_x - 220, score_y, 250, 40, scorebar);
		iShowImage(score_x - 5, score_y + 5, 20, 30, scoreimg[scorei]);
		iShowImage(score_x - 30, score_y + 5, 20, 30, scoreimg[scorej]);
		iShowImage(score_x - 55, score_y + 5, 20, 30, scoreimg[scorek]);

		iShowImage(10, 400, 280, 120, hp[dHitpoints]);

		if (dHitpoints<=0){
			dragondeath = true;
			iShowImage(0, 0, 800, 500, levelfailimage);
		}
		d++;
		if (d > 40000){
			leveldone = true;
			d = 0;
		}
}


void setBg(){
		int sum = 0;
		for (int i = 0; i < 16; i++){
			upperBackground[i].y = 0;
			fireBackground[i].y = sum;
			upperBackground[i].x = sum;
			fireBackground[i].x = 0;
			sum += 50;
		}
}

void changeBg(){

	for (int i = 0; i < 16; i++){
		upperBackground[i].x -= upperBgSpeed;
		fireBackground[i].y -= fireSpeed;

		if (upperBackground[i].x <= 0){
			upperBackground[i].x = SCREENWIDTH;
		}
		if (fireBackground[i].y <= 0){
			fireBackground[i].y = SCREENHEIGHT;
		}

	
	}
}


void dragonfly(){
	dragonIndex++;
	if (dragonIndex >= 6)  ////------------> for dragon
		dragonIndex = 0;
}

void dragonAnimation(){

	if (dragonCordinateY > skylimit)
	{
		dragonCordinateY = 210;
		dragonhp--;
		dragonhurt = true;
		//flyup = false;
	}
	if (flyup)
	{
		dragonCordinateY += 20;
		flyup = false;
		flydown = true;
		
	}
	if (flydown)
	{
		dragonCordinateY -= 5;
	}
	if (dragonCordinateY < groundlimit)
	{
		dragonCordinateY = 210;
		dragonhp--;
		dragonhurt = true;
		//flydown = false;
		//flyup = true;
	}


	//------------------------coin change animation---------------------//
	for (int j = 0; j < 10; j++)
	{
		c[j].coin_x -= 5;
		if (c[j].coin_x <= 0)
		{
			c[j].coin_x = SCREENWIDTH;
			if (!c[j].coinShow){
				c[j].coinShow = true;
			}
		}
	}


}

void Coincollect()
{
	for (int j = 0; j < 10; j++){
		if ((dragonCordinateY >= (c[j].coin_y - c[j].coin_h) && dragonCordinateY <= (c[j].coin_y + c[j].coin_h)) && ((dragonCordinateX + 80) >= (c[j].coin_x - (c[j].coin_w /*/ 3.75*/)) && ((dragonCordinateX - 80) <= (c[j].coin_x + (c[j].coin_w /*/ 1.25*/)))))
		{
			c[j].coinShow = false;
			coinc = true;
		}

	}

}



void setCoinVariable()
{
	for (int j = 0; j < 10; j++)
	{
		c[j].coin_x = SCREENWIDTH + rand() % 1000;
		c[j].coin_y = rand() % 400 + 150;
		c[j].coin_h = 40;
		c[j].coin_w = 30;
		c[j].coinIndex = rand() % 10;
		c[j].coinShow = true;

	}
}

#endif