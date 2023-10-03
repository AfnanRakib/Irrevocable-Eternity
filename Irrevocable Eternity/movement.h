
#ifndef HEADER_H_MOVEMENT
#define HEADER_H_MOVEMENT

#include "variable.h"

void natanMove(unsigned char key){

	if (key == 'd')
	{
		if (jumpup || jumpdown)
			natanCordinateX += 1;

		if (levelone){
			cas = 0;
			//running = true;
			if (((natanCordinateX >= 40 && natanCordinateX <= 250) && (natanCordinateY >= 0 && natanCordinateY <= 160) && scrn == 2) || ((natanCordinateX >= 93 && natanCordinateX <= 250) && (natanCordinateY >= 0 && natanCordinateY <= 210) && scrn == 10)){
				running = false;
			}
			else{
				running = true;
			}
			if (scrn != 10 && running){
				natanCordinateX += 6;
			}
			else if (natanCordinateX < 350 && scrn == 10 && running){
				natanCordinateX += 6;
			}
			else if (natanCordinateX > 350 && scrn == 10){
				levelComplete = 1;
				leveldone = true;
			}
			if (natanCordinateX >= 800){
				if (scrn < 10){
					scrn++;
					i = 0;
					natanCordinateX = 0;
				}
			}

			natanStandPos = false;
		}




	}

	if (key == 'a')
	{
		if (jumpup || jumpdown)
			natanCordinateX -= 1;

		if (levelone){
			cas = 1;
			//running = true;
			if ( ((natanCordinateX >= 560 && natanCordinateX <= 690) && (natanCordinateY >= 0 && natanCordinateY <= 160) && scrn == 2)){
				running = false;
			}
			else{
				running = true;
			}
			if (natanCordinateX > 0 && scrn == 1 && running){
				natanCordinateX -= 6;
			}
			else if (scrn != 1 && running){
				natanCordinateX -= 6;
			}

			if (natanCordinateX < 0 ){
				if (scrn > 1){
					scrn--;
					natanCordinateX = 750;
				}
			}
			natanStandPos = false;
		}
	}

	if (key == 'w')
	{
		if (leveltwo)
			flyup = true;

		if (!jumpup && !jumpdown)
		{
			jumps = 0;

			jumpup = true;
		}
	}


}




#endif