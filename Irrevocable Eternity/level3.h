#ifndef HEADER_H_LEVEL3
#define HEADER_H_LEVEL3

#include "variable.h"
#include "movement.h"

void levelthreefunc(){
	//////////----------------bg---------------------////
	if (!hDeath){
		scrn = 9;
		 if (scrn == 9){
			iShowImage(0, 0, 800, 500, leveloneBG[8]);
		}
		else if (scrn == 10){
			iShowImage(0, 0, 800, 500, leveloneBG[9]);
		}
	}
	else{
		iSetColor(255, 0, 0);
		iText(400, 250, "YOU DIED", GLUT_BITMAP_TIMES_ROMAN_24);
		}
	////-------------------bane animation show-------------////
	for (int i = 0; i < 10; i++){

		if (bane.espawn){

			if (bane.eatkanimation && !bane.eHurtanimation){
				iShowImage(bane.X, bane.Y, 80, 100, enemyatk[bane.enemyatkIndex]);
				eatkanimationCount++;
				if (eatkanimationCount > 300){
					eatkanimationCount = 0;
					bane.eatkanimation = false;
				}
			}
			if (bane.eHurtanimation){
				iShowImage(bane.X, bane.Y, 80, 100, enemyhurt[bane.enemyhurtIndex]);
				eHurtanimationCount++;
				if (eHurtanimationCount > 500){
					eHurtanimationCount = 0;
					bane.eHurtanimation = false;
				}
			}

			if (bane.erun && !bane.eHurt && !bane.edeath && !bane.eHurtanimation || !bane.eatk && !bane.eHurt && !bane.edeath && !bane.eatkanimation && !bane.eHurtanimation)
				iShowImage(bane.X, bane.Y, 80, 100, enemyRun[bane.enemyRunIndex]);
			else  if (bane.eatk && !bane.eHurt &&!bane.erun)
			{
				bane.eatkanimation = true;
				eatkcnt++;
				if (eatkcnt >= 45)
				{
					bane.eatk = false;
					eatkcnt = 0;
				}

			}
			else if (bane.eHurt){
				bane.eHurtanimation = true;
				ehurtimer++;
				if (ehurtimer >= 55)
				{
					bane.eHurt = false;
					ehurtimer = 0;

				}
			}

			else if (bane.edeath){
				iShowImage(bane.X, bane.Y, 80, 100, enemydeath[bane.enemydeathIndex]);
				espawntimer++;
				if (espawntimer > 2000){

					bane.espawn = false;

					espawntimer = 0;
				}

			}
			if (hDeath){
				bane.espawn = false;
			}

		}
	}
	///--------------------platforming-------------------//
	if (jumps > 0){
		if (scrn == 1 && natanCordinateX > box_x - (box_w) && natanCordinateX < box_x + (box_w) && natanCordinateY == box_y + box_h){
			platforming(box_x, box_y, box_w, box_h);
		}
		else if (scrn == 1 && natanCordinateX > box_x2 - (box_w2) && natanCordinateX < box_x2 + (box_w2) && natanCordinateY == box_y2 + box_h2){
			platforming(box_x2, box_y2, box_w2, box_h2);
		}
		else if (scrn == 3 && natanCordinateX > box_x3 - (box_w3) && natanCordinateX < box_x3 + (box_w3) && natanCordinateY == box_y3 + box_h3){
			platforming(box_x3, box_y3, box_w3, box_h3);
		}
	}


	/////-------------------------------------------------- jumping -------------------------------------------------------///
	if (!hDeath){
		if (jumpup)
		{																						///--->jumpup image
			if (cas == 0)
				iShowImage(natanCordinateX, natanCordinateY, 95, 120, natanJumpUpIndex);
			else if (cas == 1)
				iShowImage(natanCordinateX, natanCordinateY, 95, 120, natanaltJumpUpIndex);
		}
		else if (jumpdown)																		///--->jumpdown image
		{
			if (cas == 0)
				iShowImage(natanCordinateX, natanCordinateY, 95, 120, natanJumpDownIndex);
			else if (cas == 1)
				iShowImage(natanCordinateX, natanCordinateY, 95, 120, natanaltJumpDownIndex);
		}

		/////--------------------------------------------------attacking-------------------------------------------------------///

		else if (attack)																		///--->attack condition
		{
			if (cas == 0 && !running)
				iShowImage(natanCordinateX, natanCordinateY, 120, 150, natanAtk[natanAtkIndex]);
			else if (cas == 1 && !running)
				iShowImage(natanCordinateX, natanCordinateY, 120, 150, natanaltAtk[natanaltAtkIndex]);

			else if (cas == 0 && running)														//--->attack condition while running
				iShowImage(natanCordinateX, natanCordinateY, 120, 150, natanAtk[1]);
			else if (cas == 1 && running)
				iShowImage(natanCordinateX, natanCordinateY, 120, 150, natanaltAtk[1]);


			nonatkcnt++;
			if (nonatkcnt >= 300 && !running)				///----> non-attack timer while not running																	
			{
				nonatkcnt = 0;
				natanAtkIndex = 0;
				attack = false;
			}
			else if (nonatkcnt >= 100 && running)			///---->non-attack timer while  running
			{
				nonatkcnt = 0;
				natanAtkIndex = 0;
				attack = false;
			}

		}

		/////--------------------------------------------------shield-------------------------------------------------------///

		else if (sheild){

			if (cas == 0 && !running)
				iShowImage(natanCordinateX, natanCordinateY, 75, 90, natanshld[natanshldIndex]);     ///--->sheild condition
			else if (cas == 1 && !running)
				iShowImage(natanCordinateX, natanCordinateY, 75, 90, natanaltshld[natanaltshldIndex]);

			nonshldcnt++;
			if (nonshldcnt >= 500)																	///----> non-sheild timer 																	
			{
				nonshldcnt = 0;
				natanshldIndex = 0;
				sheild = false;
			}
		}

		/////--------------------------------------------------running-------------------------------------------------------///

		else
		{
			if (!natanStandPos)
			{

				if (cas == 0)
					iShowImage(natanCordinateX, natanCordinateY - 5, 80, 110, natanRun[natanRunIndex]);
				else if (cas == 1)
					iShowImage(natanCordinateX, natanCordinateY - 5, 80, 110, natanaltRun[natanaltRunIndex]);

				standCnt++;
				if (standCnt >= 1500)
				{
					standCnt = 0;
					natanRunIndex = 0;
					natanStandPos = true;
				}
			}

			/////--------------------------------------------------stand position-------------------------------------------------------///

			else if (cas == 0)
			{
				iShowImage(natanCordinateX, natanCordinateY, 80, 110, natanStand[natanStandIndex]);
			}
			else if (cas == 1)
			{
				iShowImage(natanCordinateX, natanCordinateY, 80, 110, natanaltStand[natanltStandIndex]);
			}
		}
	}
	else if (hDeath){
		iShowImage(natanCordinateX, natanCordinateY, 150, 200, natanDeath[nathurt_i]);

		if (nathurt_i<8)
			iResumeTimer(death);
	}


	iShowImage(score_x, score_y, 20, 30, scoreimg[scorei]);
	iShowImage(score_x - 30, score_y, 20, 30, scoreimg[scorej]);
	iShowImage(score_x - 60, score_y, 20, 30, scoreimg[scorek]);


	iSetColor(24, 67, 233);
	iText(10, 450, "Score: ", GLUT_BITMAP_TIMES_ROMAN_24);
	//iShowBMP2(200,200, img[0], 0);

}


void setbaneVariable(){
	
	
		bane.eleft = true;
		bane.edeath = false;
		bane.eatkanimation;

		bane.eHurtanimation;




		bane.X = SCREENWIDTH + rand() % 200 + rand() % 100;
		bane.Y = ground;
		bane.eHitpoints = 3;///---->enemy health

		bane.eHurt = false;///--->enemy hurt case

		bane.eatk = false;///---->enemy attack case

		bane.erun = false;///---->enemy run case

		bane.espawn = false; ///-----> enemy spawn case*/
		bane.enemyRunIndex = 0;
		bane.enemyatkIndex = 0;
		bane.enemyhurtIndex = 0;
		bane.enemydeathIndex = 0;
	

}

////------------------------------enemy animation--------------------------------////

void banefunc(){
	
		if (bane.espawn){

			///------enemy run-----///
			if (bane.X > natanCordinateX + 55 && !bane.edeath)
			{
				bane.erun = true;
				bane.eleft = true;
				bane.X = bane.X - 6;
			}
			else if (bane.X < natanCordinateX - 55 && !bane.edeath){
				bane.erun = true;
				bane.eleft = false;
				bane.X = bane.X + 6;
			}
			else
				bane.erun = false;
			///----enemy run end----///
			etimer++;
			///----enemy attack----////		
			if ((bane.X <= natanCordinateX + 55 || bane.X >= natanCordinateX - 55) && bane.Y == natanCordinateY && !bane.erun && !bane.edeath && etimer > 24 && !hDeath){

				bane.eatk = true;
				etimer = 0;
			}
			if (bane.eatk && (bane.X <= natanCordinateX + 55 || bane.X >= natanCordinateX - 55) && bane.Y == natanCordinateY && !bane.edeath)
			{
				if (!sheild)
				{
					hHurt = true;
					if (hHurt){
						//iShowImage(natanCordinateX, natanCordinateY, 80, 100,natanhurt[0]);
						hHitpoints--;
						//printf("hit points = %d", hHitpoints);
						hHurt = false;
					}

				}

			}
			if (hHitpoints == 0){

				hDeath = true;


			}

			///----enemy attack end----////


			////---enemy hit recieve----///
			if (attack && (bane.X <= natanCordinateX + 55 && bane.X >= natanCordinateX - 55) && bane.Y == natanCordinateY  && !bane.edeath &&!bane.eHurt)
			{
				//printf("enemy hitpoint %d", eHitpoints);
				bane.eatk = false;

				bane.eHurt = true;

				if (cas == 0 && bane.eHurt /*&& attack*/)
				{
					bane.X += 30;
					bane.eHitpoints--;

					etimer = 0;
				}
				else if (cas == 1 && bane.eHurt /*&& attack*/)
				{
					bane.X -= 30;

					bane.eHitpoints--;


					etimer = 0;
				}
			}
			if (bane.eHitpoints == 0){
				bane.edeath = true;
				bane.eatk = false;
				bane.erun = false;
				bane.eHurt = false;
				enemykill = true;;
			}



			////---enemy hit recieve end----///
		

	}

}


void banespawn(int i){
	bane.espawn = true;
	bane.edeath = false;
	bane.eHitpoints = 3;
	if (bane.espawn)
	{
		

		bane.X = SCREENWIDTH + rand() % 1000 + 200;
		bane.Y = ground;
	}
}

#endif