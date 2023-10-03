
#ifndef HEADER_H_LEVEL1
#define HEADER_H_LEVEL1

#include "variable.h"

void levelonefunc(){
	//scrn = 10;
	/////----------------------------------------------Bg showing----------------------------------------------///
	if (!hDeath){
		if (scrn == 1){
			
			if (i < 3){
				spawn(i++);
			}
			iShowImage(0, 0, 800, 500, leveloneBG[0]);
			//iRotate(box_x, box_y, 15);
			//iShowImage(box_x, box_y, box_w, box_h, platform);
			//iUnRotate();
			//iShowImage(box_x2, box_y2, box_w2, box_h2, platform);
		}
		else if (scrn == 2){
			iShowImage(0, 0, 800, 500, leveloneBG[1]);
			iShowImage(box_x6, box_y6, box_w6, box_h6, platform);
			iShowImage(255, 0, 295, 95, trap);
			for (int i = 0; i < 10; i++){
				e[i].espawn = false;
			}
		}
		else if (scrn == 3){
			iShowImage(0, 0, 800, 500, leveloneBG[2]);
			iShowImage(box_x3, box_y3, box_w3, box_h3, platform);
			iShowImage(405, 0, 400, 120, trap);
			for (int i = 0; i < 10; i++){
				e[i].espawn = false;
			}
		}
		else if (scrn == 4){
			iShowImage(0, 0, 800, 500, leveloneBG[3]);
			if (i < 3){
				spawn(i++);
			}
		}
		else if (scrn == 5){
			iShowImage(0, 0, 800, 500, leveloneBG[4]);
			if (i < 2){
				spawn(i++);
			}
		}
		else if (scrn == 6){
			iShowImage(0, 0, 800, 500, leveloneBG[5]);
			if (i < 3){
				spawn(i++);
			}
		}
		else if (scrn == 7){
			iShowImage(0, 0, 800, 500, leveloneBG[6]);
			if (i < 4){
				spawn(i++);
			}
		}
		else if (scrn == 8){
			iShowImage(0, 0, 800, 500, leveloneBG[7]);
			if (i < 6){
				spawn(i++);
			}
		}
		else if (scrn == 9){
			iShowImage(0, 0, 800, 500, leveloneBG[8]);
			iShowImage(box_x8, box_y8, box_w8, box_h8, platform);
			iShowImage(box_x9, box_y9, box_w9, box_h9, platform);
			iShowImage(box_x10, box_y10, box_w10, box_h10, platform);
			iShowImage(box_x11, box_y11, box_w11, box_h11, platform);
			iShowImage(box_x12, box_y12, box_w12, box_h12, platform);
			for (int i = 0; i < 10; i++){
				e[i].espawn = false;
			}
			iRotate(420,420, 90);
			for (int i = 0; i < 16; i++){
				iShowImage(fireBackground[i].x, fireBackground[i].y, 90, 100, firebg);
			}
			iUnRotate();
			
		}
		else if (scrn == 10){
			iShowImage(0, 0, 800, 500, leveloneBG[9]);
			iShowImage(0, box_y8 + 20, box_w8, box_h8, platform);
			for (int i = 0; i < 10; i++){
				e[i].espawn = false;
			}
		}
	}
	else{
		
		iShowImage(0, 0, 800, 500, levelfailimage);
	}

	/////--------------------------------------------enemy codes-------------------------------------------------------///
	for (int i = 0; i < 10; i++){

		if (e[i].espawn){

			if (e[i].eatkanimation && !e[i].eHurtanimation){
				iShowImage(e[i].X, e[i].Y, 120, 100, enemyatk[e[i].enemytype][e[i].enemyatkIndex]);
				eatkanimationCount++;
				if (eatkanimationCount > 300){
					eatkanimationCount = 0;
					e[i].eatkanimation = false;
				}
			}
			if (e[i].eHurtanimation){
				iShowImage(e[i].X, e[i].Y, 120, 100, enemyhurt[e[i].enemytype][e[i].enemyhurtIndex]);
				eHurtanimationCount++;
				if (eHurtanimationCount > 500){
					eHurtanimationCount = 0;
					e[i].eHurtanimation = false;
				}
			}

			if (e[i].erun && !e[i].eHurt && !e[i].edeath && !e[i].eHurtanimation &&e[i].eleft || !e[i].eatk && !e[i].eHurt && !e[i].edeath && !e[i].eatkanimation && !e[i].eHurtanimation &&e[i].eleft)
				iShowImage(e[i].X, e[i].Y, 120, 100, altenemyRun[e[i].enemytype][e[i].altenemyRunIndex]);
			else if (e[i].erun && !e[i].eHurt && !e[i].edeath && !e[i].eHurtanimation && !e[i].eleft || !e[i].eatk && !e[i].eHurt && !e[i].edeath && !e[i].eatkanimation && !e[i].eHurtanimation && !e[i].eleft)
				iShowImage(e[i].X, e[i].Y, 120, 100, enemyRun[e[i].enemytype][e[i].enemyRunIndex]);
			else  if (e[i].eatk && !e[i].eHurt &&!e[i].erun)
			{
				e[i].eatkanimation = true;
				eatkcnt++;
				if (eatkcnt >= 45)
				{
					e[i].eatk = false;
					eatkcnt = 0;
				}

			}
			else if (e[i].eHurt){
				e[i].eHurtanimation = true;
				ehurtimer++;
				if (ehurtimer >= 55)
				{
					e[i].eHurt = false;
					ehurtimer = 0;
				}
			}

			else if (e[i].edeath && e[i].enemytype == 0){
				iShowImage(e[i].X, e[i].Y, 80, 100, enemydeath[e[i].enemytype][e[i].enemydeathIndex]);
				espawntimer++;
				if (espawntimer > 550){
					e[i].espawn = false;
					enemykill = true;
					espawntimer = 0;
				}

			}
			if (hDeath){
				e[i].espawn = false;
			}

		}
	}
	
	/////---------------------------------------------climbing platform--------------------------------------------------------///


	if (jumps > 0){
		/*if (scrn == 1 && natanCordinateX > box_x - (box_w) && natanCordinateX < box_x + (box_w) && natanCordinateY == box_y + box_h){
			platforming(box_x, box_y, box_w, box_h);
		}
		else if (scrn == 1 && natanCordinateX > box_x2 - (box_w2) && natanCordinateX < box_x2 + (box_w2) && natanCordinateY == box_y2 + box_h2){
			platforming(box_x2, box_y2, box_w2, box_h2);
		}
		else */if (scrn == 2 && natanCordinateX > box_x4 - (box_w4) && natanCordinateX < box_x4 + (box_w4) && natanCordinateY == box_y4 + box_h4){
			platforming(box_x4, box_y4, box_w4, box_h4);
		}
		else if (scrn == 2 && natanCordinateX > box_x5 - (box_w5) && natanCordinateX < box_x5 + (box_w5) && natanCordinateY == box_y5 + box_h5){
			platforming(box_x5, box_y5, box_w5, box_h5);
		}
		else if (scrn == 2 && natanCordinateX > box_x6 - (box_w6) && natanCordinateX < box_x6 + (box_w6) && natanCordinateY == box_y6 + box_h6){
			platforming(box_x6, box_y6, box_w6, box_h6);
		}
		else if (scrn == 3 && natanCordinateX > box_x3 - (box_w3) && natanCordinateX < box_x3 + (box_w3) && natanCordinateY == box_y3 + box_h3){
			platforming(box_x3, box_y3, box_w3, box_h3);
		}
		else if (scrn == 3 && natanCordinateX > box_x7 - (box_w7) && natanCordinateX < box_x7 + (box_w7) && natanCordinateY == box_y7 + box_h7){
			platforming(box_x7, box_y7, box_w7, box_h7);
		}
		else if (scrn == 9 && natanCordinateX > box_x8 - (box_w8) && natanCordinateX < box_x8 + (box_w8) && natanCordinateY == box_y8 + box_h8){
			platforming(box_x8, box_y8, box_w8, box_h8);
		}
		else if (scrn == 9 && natanCordinateX > box_x9 - (box_w9) && natanCordinateX < box_x9 + (box_w9) && natanCordinateY == box_y9 + box_h9){
			platforming(box_x9, box_y9, box_w9, box_h9);
		}
		else if (scrn == 9 && natanCordinateX > box_x10 - (box_w10) && natanCordinateX < box_x10 + (box_w10) && natanCordinateY == box_y10 + box_h10){
			platforming(box_x10, box_y10, box_w10, box_h10);
		}
		else if (scrn == 9 && natanCordinateX > box_x11 - (box_w11) && natanCordinateX < box_x11 + (box_w11) && natanCordinateY == box_y11 + box_h11){
			platforming(box_x11, box_y11, box_w11, box_h11);
		}
		else if (scrn == 9 && natanCordinateX > box_x12 - (box_w12) && natanCordinateX < box_x12 + (box_w12) && natanCordinateY == box_y12 + box_h12){
			platforming(box_x12, box_y12, box_w12, box_h12);
		}
		else if (scrn == 10 && natanCordinateX > box_x13 - (box_w13) && natanCordinateX < box_x13 + (box_w13) && natanCordinateY == box_y13 + box_h13){
			platforming(box_x13, box_y13, box_w13, box_h13);
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
		else if (atkanimationtimer)																		///--->attack condition
		{
			
			if (cas == 0 && !running)
				iShowImage(natanCordinateX, natanCordinateY, 120, 150, natanAtk[natanAtkIndex][natanAtkAnimationIndex]);
			else if (cas == 1 && !running)
				iShowImage(natanCordinateX, natanCordinateY, 120, 150, natanaltAtk[natanaltAtkIndex][natanaltAtkAnimationIndex]);

			else if (cas == 0 && running)														//--->attack condition while running
				iShowImage(natanCordinateX, natanCordinateY, 120, 150, natanAtk[2][natanAtkAnimationIndex]);
			else if (cas == 1 && running)
				iShowImage(natanCordinateX, natanCordinateY, 120, 150, natanaltAtk[2][natanaltAtkAnimationIndex]);


			nonatkcnt++;
			if (nonatkcnt >= 100 && !running)				///----> non-attack timer while not running																	
			{
				nonatkcnt = 0;
				attack = false;
			}

			else if (nonatkcnt >= 100 && running)			///---->non-attack timer while  running
			{
				nonatkcnt = 0;

				attack = false;
			}

		}

		/////--------------------------------------------------shield-------------------------------------------------------///

		else if (sheild){

			if (cas == 0 && !running)
				iShowImage(natanCordinateX, natanCordinateY, 120,150, natanshld[natanshldIndex]);     ///--->sheild condition
			else if (cas == 1 && !running)
				iShowImage(natanCordinateX, natanCordinateY, 120, 150, natanaltshld[natanaltshldIndex]);

			nonshldcnt++;
			if (nonshldcnt >= 1000)																	///----> non-sheild timer 																	
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
					running = false;
				}
			}

			/////--------------------------------------------------stand position-------------------------------------------------------///

			else if (cas == 0)
			{
				iShowImage(natanCordinateX, natanCordinateY, 80, 110, natanStand[0]);
			}
			else if (cas == 1)
			{
				iShowImage(natanCordinateX, natanCordinateY, 80, 110, natanaltStand[0]);
			}
		}
	}
	else if (hDeath){
		iShowImage(natanCordinateX, natanCordinateY, 150, 200, natanDeath[nathurt_i]);

		if (nathurt_i<8)
			iResumeTimer(death);
	}
	//////-------------traps -------------//////////////
	if ((natanCordinateX >= 403 && natanCordinateX <= 798) && (natanCordinateY >= 0 && natanCordinateY <= 130) && scrn == 3){

		hDeath = true;
	}
	else if ((natanCordinateX >= 220 && natanCordinateX <= 545) && (natanCordinateY >= 0 && natanCordinateY <= 130) && scrn == 2){

		hDeath = true;
	}
	else if ((natanCordinateX >= 145 && natanCordinateX <= 695) && (natanCordinateY >= 0 && natanCordinateY <= 50) && scrn == 9){

		hDeath = true;
	}

	////---------------------------------------------------------Score----------------------------------------------------------////

	if (!hDeath){
		iShowImage(score_x - 220, score_y, 250, 40, scorebar);
		iShowImage(score_x - 5, score_y + 5, 20, 30, scoreimg[scorei]);
		iShowImage(score_x - 30, score_y + 5, 20, 30, scoreimg[scorej]);
		iShowImage(score_x - 55, score_y + 5, 20, 30, scoreimg[scorek]);

		iShowImage(10, 400, 280, 120, hp[hHitpoints]);
	}


}




/////--------box change---------////
void boxchange(){

	//--------------------fire show-------------//

	for (int i = 0; i < 16; i++){
		fireBackground[i].y -= fireSpeed-2;

		if (fireBackground[i].y <= 0){
			fireBackground[i].y = SCREENWIDTH;
		}
	}
	for (int i = 0; i < 16; i++){
		fireBackground[i].x += fireSpeed - 9;

		if (fireBackground[i].x >= 10){
			fireBackground[i].x = -25;
		}
	}





	boxdistance++;

	box_x += dx;
	box_x2 += (dx2);
	box_x3 += (dx3);
	box_x6 += (dx6);
	box_x11 += (dx11);
	box_x12 += (dx12);

	if (boxdistance > 30){
		dx = -dx;
		dx2 = -dx2;
		dx3 = -dx3;
		dx6 = -dx6;
		dx11 = -dx11;
		dx12 = -dx12;
		boxdistance = 0;
	}
	if (natanCordinateX > box_x - (box_w) && natanCordinateX < box_x + (box_w) && natanCordinateY == box_y + box_h){
		natanCordinateX += dx;
	}
	else if (natanCordinateX > box_x2 - (box_w2) && natanCordinateX < box_x2 + (box_w2) && natanCordinateY == box_y2 + box_h2){
		natanCordinateX += dx2;
	}
	else if (natanCordinateX > box_x3 - (box_w3) && natanCordinateX < box_x3 + (box_w3) && natanCordinateY == box_y3 + box_h3){
		natanCordinateX += dx3;
	}
	else if (natanCordinateX > box_x6 - (box_w6) && natanCordinateX < box_x6 + (box_w6) && natanCordinateY == box_y6 + box_h6){
		natanCordinateX += dx6;
	}
	else if (natanCordinateX > box_x11 - (box_w11) && natanCordinateX < box_x11 + (box_w11) && natanCordinateY == box_y11 + box_h11){
		natanCordinateX += dx11;
	}
	else if (natanCordinateX > box_x12 - (box_w12) && natanCordinateX < box_x12 + (box_w12) && natanCordinateY == box_y12 + box_h12){
		natanCordinateX += dx12;
	}



	////--------jump animation---------////

	if (jumpup)
	{
		natanCordinateY += 10;
		jumps++;
		if (natanCordinateY >= JUMPLIMIT || jumps >= 14)
		{
			jumpup = false;
			jumpdown = true;

		}
	}

	if (jumpdown)
	{
		natanCordinateY -= 10;
	}
	if (natanCordinateY < ground)
	{
		jumpdown = false;
		natanCordinateY = ground;
	}

}

void platforming(int box_x1, int box_y1, int box_w1, int box_h1){
	if ((natanCordinateY == box_y1 + box_h1 && (natanCordinateX >= box_x1 - (box_w1 / 3.75) && natanCordinateX <= box_x1 + (box_w1 / 1.25))))
	{
		jumpdown = false;
		onplatform = true;
	}
	else
	{
		jumpdown = true;
		onplatform = false;
	}
}



////--------run animation---------////
void runAnimation(){
	natanRunIndex++;
	if (natanRunIndex >= 6)
		natanRunIndex = 0;

	natanaltRunIndex++;
	if (natanaltRunIndex >= 6)
		natanaltRunIndex = 0;



	//-------atkanimation----///
	if (atkanimation && cas == 0){
		natanAtkAnimationIndex++;
		if (natanAtkAnimationIndex > 2){
			natanAtkAnimationIndex = 0;
		}
	}
	else if (atkanimation && cas == 1){
		natanaltAtkAnimationIndex++;
		if (natanaltAtkAnimationIndex > 2){
			natanaltAtkAnimationIndex = 0;
		}
	}
	if (atkanimation)
		atkanimationtimer++;
	if (atkanimationtimer > 2 && !running)				///----> non-attack timer while not running																	
	{
		atkanimationtimer = 0;
		atkanimation = false;
	}

	else if (atkanimationtimer > 2 && running)			///---->non-attack timer while  running
	{
		atkanimationtimer = 0;
		natanAtkIndex = 0;
		atkanimation = false;
	}
}


void setVariable(){
	//int i = 0;
	for (int i = 0; i <10; i++){
		e[i].eleft = true;
		e[i].edeath = false;
		e[i].eatkanimation;

		e[i].eHurtanimation;




		e[i].X = SCREENWIDTH + 100;
		e[i].Y = ground;
		e[i].eHitpoints = 3;///---->enemy health

		e[i].eHurt = false;///--->enemy hurt case

		e[i].eatk = false;///---->enemy attack case

		e[i].erun = false;///---->enemy run case

		e[i].espawn = false; ///-----> enemy spawn case*/
		e[i].enemyRunIndex = 0;
		e[i].enemyatkIndex = 0;
		e[i].altenemyRunIndex = 0;
		e[i].enemyhurtIndex = 0;
		e[i].enemydeathIndex = 0;
		e[i].enemytype = rand() % 2;
	}

}

////------------------------------enemy animation--------------------------------////

void enemy(){
	
	for (int i = 0; i < 10; i++){
		
		if (e[i].espawn){

			///------enemy run-----///
			if (e[i].X > natanCordinateX + 55 && !e[i].edeath)
			{
				e[i].erun = true;
				if (e[i].enemytype == 0){
					e[i].altenemyRunIndex++;
					if (e[i].altenemyRunIndex > 3){
						e[i].altenemyRunIndex = 0;
					}
				}
					
				e[i].eleft = true;
				if (e[i].enemytype == 0)
					e[i].X = e[i].X - 4;
				else if (e[i].enemytype == 1)
					e[i].X = e[i].X - 6;
			}
			else if (e[i].X < natanCordinateX - 55 && !e[i].edeath){
				e[i].erun = true;
				if (e[i].enemytype == 0){
					e[i].enemyRunIndex++;
					if (e[i].enemyRunIndex > 3){
						e[i].enemyRunIndex = 0;
					}
				}
				
				e[i].eleft = false;
				if (e[i].enemytype == 0)
					e[i].X = e[i].X + 4;
				else if (e[i].enemytype == 1)
					e[i].X = e[i].X + 6;
			}
			else
				e[i].erun = false;
			///----enemy run end----///
			etimer++;
			///----enemy attack----////		
			if ((e[i].X <= natanCordinateX + 55 || e[i].X >= natanCordinateX - 55) && e[i].Y == natanCordinateY && !e[i].erun && !e[i].edeath && etimer > 50 && !hDeath){
				e[i].eatk = true;
				etimer = 0;
			}
			if (e[i].eatk && (e[i].X <= natanCordinateX + 55 || e[i].X >= natanCordinateX - 55) && e[i].Y == natanCordinateY && !e[i].edeath)
			{
				if (!sheild)
				{
					hHurt = true;
					if (hHurt){
						//iShowImage(natanCordinateX, natanCordinateY, 80, 100,natanhurt[0]);
						hHitpoints--;
						printf("hit points = %d", hHitpoints);
						hHurt = false;
					}
				}

			}
			if (hHitpoints == 0){

				hDeath = true;


			}

			///----enemy attack end----////


			////---enemy hit recieve----///
			if (attack && (e[i].X <= natanCordinateX + 55 && e[i].X >= natanCordinateX - 55) && e[i].Y == natanCordinateY  && !e[i].edeath &&!e[i].eHurt)
			{
				//printf("enemy hitpoint %d", eHitpoints);
				e[i].eatk = false;

				e[i].eHurt = true;

				if (cas == 0 && e[i].eHurt /*&& attack*/)
				{
					e[i].X += 30;
					e[i].eHitpoints--;

					etimer = 0;
				}
				else if (cas == 1 && e[i].eHurt /*&& attack*/)
				{
					e[i].X -= 30;
					e[i].eHitpoints--;

					etimer = 0;
				}
			}

			if (e[i].eHitpoints == 0){
				e[i].edeath = true;
				e[i].eatk = false;
				e[i].erun = false;
				e[i].eHurt = false;
				if (e[i].enemytype == 1){

					e[i].espawn = false;
				}
				
				enemykill = true;
			}

			////---enemy hit recieve end----///
		}

	}
	
}

void natdeath(){

	if (nathurt_i < 8){
		iPauseTimer(death);
	}
	nathurt_i++;
}

void spawn(int i){
	e[i].espawn = true;
	e[i].edeath = false;
	e[i].eHitpoints = 3;
	if (e[i].espawn)
	{
		//i++;

		e[i].X = rand() % 1000 + 200+ rand() % 100;
		e[i].Y = ground;

	}
}

#endif