
#ifndef HEADER_H_IMAGE
#define HEADER_H_IMAGE

#include "variable.h"

void images(){

	coin[0] = iLoadImage("coins\\coin1.png");

	scoreimg[0] = iLoadImage("Score\\0.png");
	scoreimg[1] = iLoadImage("Score\\1.png");
	scoreimg[2] = iLoadImage("Score\\2.png");
	scoreimg[3] = iLoadImage("Score\\3.png");
	scoreimg[4] = iLoadImage("Score\\4.png");
	scoreimg[5] = iLoadImage("Score\\5.png");
	scoreimg[6] = iLoadImage("Score\\6.png");
	scoreimg[7] = iLoadImage("Score\\7.png");
	scoreimg[8] = iLoadImage("Score\\8.png");
	scoreimg[9] = iLoadImage("Score\\9.png");


	natanshld[0] = iLoadImage("sheild\\sheild.png");
	natanaltshld[0] = iLoadImage("sheild\\altsheild.png");///------>natan sheild rendering

	altenemyRun[1][0] = iLoadImage("enemy\\alte2.png");////---->enemy run
	enemyRun[1][0] = iLoadImage("enemy\\alte2.png");
	enemyatk[1][0] = iLoadImage("enemy\\alte3.png");///--->enemy atk
	enemyhurt[1][0] = iLoadImage("enemy\\alte1.png");///--->enemy hurt*/
	

	enemyRun[0][0] = iLoadImage("enemy\\w1.png");////---->enemy run
	enemyRun[0][1] = iLoadImage("enemy\\w2.png");////---->enemy run
	enemyRun[0][2] = iLoadImage("enemy\\w3.png");////---->enemy run
	enemyRun[0][3] = iLoadImage("enemy\\w4.png");////---->enemy run

	altenemyRun[0][0] = iLoadImage("enemy\\altw1.png");////---->enemy run
	altenemyRun[0][1] = iLoadImage("enemy\\altw2.png");////---->enemy run
	altenemyRun[0][2] = iLoadImage("enemy\\altw3.png");////---->enemy run
	altenemyRun[0][3] = iLoadImage("enemy\\altw4.png");////---->enemy run


	enemyatk[0][0] = iLoadImage("enemy\\demonatk.png");///--->enemy atk
	enemyhurt[0][0] = iLoadImage("enemy\\demonhurt.png");///--->enemy hurt
	enemydeath[0][0] = iLoadImage("enemy\\demondeath.png");///--->enemy death

	natanaltRun[0] = iLoadImage("run\\flippedrun2.png");
	natanaltRun[1] = iLoadImage("run\\flippedrun3.png");
	natanaltRun[2] = iLoadImage("run\\flippedrun4.png");
	natanaltRun[3] = iLoadImage("run\\flippedrun6.png");
	natanaltRun[4] = iLoadImage("run\\flippedrun7.png");
	natanaltRun[5] = iLoadImage("run\\flippedrun8.png");


	natanRun[0] = iLoadImage("run\\2.png");
	natanRun[1] = iLoadImage("run\\3.png");
	natanRun[2] = iLoadImage("run\\4.png");
	natanRun[3] = iLoadImage("run\\6.png");
	natanRun[4] = iLoadImage("run\\7.png");
	natanRun[5] = iLoadImage("run\\8.png");

	natanJumpUpIndex = iLoadImage("Jump\\jump3.png");
	natanJumpDownIndex = iLoadImage("Jump\\jump5.png");

	natanaltJumpUpIndex = iLoadImage("Jump\\flipjump3.png");
	natanaltJumpDownIndex = iLoadImage("Jump\\flipjump5.png");

	natanStand[0] = iLoadImage("idle\\idle1.png");
	

	menuBG[0] = iLoadImage("menu\\menuBG.jpg");
	menuBG[1] = iLoadImage("menu\\menuwindow.png");

	leveloneBG[0] = iLoadImage("background\\levelonebg\\1.jpg");
	leveloneBG[1] = iLoadImage("background\\levelonebg\\2.jpg");
	leveloneBG[2] = iLoadImage("background\\levelonebg\\3.jpg");
	leveloneBG[3] = iLoadImage("background\\levelonebg\\4.jpg");
	leveloneBG[4] = iLoadImage("background\\levelonebg\\5.jpg");
	leveloneBG[5] = iLoadImage("background\\levelonebg\\6.jpg");
	leveloneBG[6] = iLoadImage("background\\levelonebg\\7.jpg");
	leveloneBG[7] = iLoadImage("background\\levelonebg\\8.jpg");
	leveloneBG[8] = iLoadImage("background\\levelonebg\\9.jpg");
	leveloneBG[9] = iLoadImage("background\\levelonebg\\10.jpg");


	firebg = iLoadImage("background\\fire.PNG");

	dragon[0] = iLoadImage("dragon\\1.png");
	dragon[1] = iLoadImage("dragon\\2.png");
	dragon[2] = iLoadImage("dragon\\3.png");
	dragon[3] = iLoadImage("dragon\\4.png");
	dragon[4] = iLoadImage("dragon\\5.png");
	dragon[5] = iLoadImage("dragon\\6.png");

	upperBg[0] = iLoadImage("background\\upperbg\\row-1-column-1.png");
	upperBg[1] = iLoadImage("background\\upperbg\\row-1-column-2.png");
	upperBg[2] = iLoadImage("background\\upperbg\\row-1-column-3.png");
	upperBg[3] = iLoadImage("background\\upperbg\\row-1-column-4.png");
	upperBg[4] = iLoadImage("background\\upperbg\\row-1-column-5.png");
	upperBg[5] = iLoadImage("background\\upperbg\\row-1-column-6.png");
	upperBg[6] = iLoadImage("background\\upperbg\\row-1-column-7.png");
	upperBg[7] = iLoadImage("background\\upperbg\\row-1-column-8.png");
	upperBg[8] = iLoadImage("background\\upperbg\\row-1-column-9.png");
	upperBg[9] = iLoadImage("background\\upperbg\\row-1-column-10.png");
	upperBg[10] = iLoadImage("background\\upperbg\\row-1-column-11.png");
	upperBg[11] = iLoadImage("background\\upperbg\\row-1-column-12.png");
	upperBg[12] = iLoadImage("background\\upperbg\\row-1-column-13.png");
	upperBg[13] = iLoadImage("background\\upperbg\\row-1-column-14.png");
	upperBg[14] = iLoadImage("background\\upperbg\\row-1-column-15.png");
	upperBg[15] = iLoadImage("background\\upperbg\\row-1-column-16.png");


	natanaltStand[0] = iLoadImage("idle\\flippedstand1.png");
	


	natanDeath[0] = iLoadImage("Death\\1.png");
	natanDeath[1] = iLoadImage("Death\\2.png");
	natanDeath[2] = iLoadImage("Death\\3.png");
	natanDeath[3] = iLoadImage("Death\\4.png");
	natanDeath[4] = iLoadImage("Death\\5.png");
	natanDeath[5] = iLoadImage("Death\\6.png");
	natanDeath[6] = iLoadImage("Death\\7.png");
	natanDeath[7] = iLoadImage("Death\\8.png");
	natanDeath[8] = iLoadImage("Death\\9.png");


	hp[0] = iLoadImage("Hp\\0.png");
	hp[1] = iLoadImage("Hp\\1.png");
	hp[2] = iLoadImage("Hp\\2.png");
	hp[3] = iLoadImage("Hp\\3.png");
	hp[4] = iLoadImage("Hp\\4.png");
	hp[5] = iLoadImage("Hp\\5.png");
	hp[6] = iLoadImage("Hp\\6.png");
	hp[7] = iLoadImage("Hp\\7.png");
	hp[8] = iLoadImage("Hp\\8.png");
	hp[9] = iLoadImage("Hp\\9.png");
	hp[10] = iLoadImage("Hp\\10.png");

	platform = iLoadImage("background\\platform.png");


	exitimage=iLoadImage("menu\\exit.jpg");
	musicimage = iLoadImage("menu\\music.jpg");
	playimage = iLoadImage("menu\\play.jpg");
	homeimage = iLoadImage("menu\\home.png");
	levelcompleteimage = iLoadImage("menu\\levelcomplete.jpg");
	levelfailimage = iLoadImage("menu\\youdied.jpg");


	
	natanAtk[0][0] = iLoadImage("Attack1\\atk02.png");
	natanAtk[0][1] = iLoadImage("Attack1\\atk03.png");
	natanAtk[0][2] = iLoadImage("Attack1\\atk04.png");							//.......>natan attack rendering

	natanAtk[1][0] = iLoadImage("Attack1\\atk12.png");
	natanAtk[1][1] = iLoadImage("Attack1\\atk13.png");
	natanAtk[1][2] = iLoadImage("Attack1\\atk14.png");							//.......>natan attack rendering

	natanAtk[2][0] = iLoadImage("Attack1\\atk22.png");
	natanAtk[2][1] = iLoadImage("Attack1\\atk23.png");
	natanAtk[2][2] = iLoadImage("Attack1\\atk24.png");							//.......>natan attack rendering

	natanaltAtk[0][0] = iLoadImage("Attack1\\altatk02.png");
	natanaltAtk[0][1] = iLoadImage("Attack1\\altatk03.png");
	natanaltAtk[0][2] = iLoadImage("Attack1\\altatk04.png");  //

	natanaltAtk[1][0] = iLoadImage("Attack1\\altatk12.png");
	natanaltAtk[1][1] = iLoadImage("Attack1\\altatk13.png");
	natanaltAtk[1][2] = iLoadImage("Attack1\\altatk14.png");  //

	natanaltAtk[2][0] = iLoadImage("Attack1\\altatk22.png");
	natanaltAtk[2][1] = iLoadImage("Attack1\\altatk23.png");
	natanaltAtk[2][2] = iLoadImage("Attack1\\altatk24.png");  //


	trap = iLoadImage("background\\trap.png");
	scorebar = iLoadImage("Score\\bar.jpg");

	standingbg = iLoadImage("menu\\scorerbg.jpg");
	aboutus = iLoadImage("menu\\aboutus.jpg");
	instructions = iLoadImage("menu\\instructions.jpg");

	
	/*
	startupImg[0] = iLoadImage("menu\\startup1.png");
	startupImg[1] = iLoadImage("menu\\startup10.png");
	startupImg[2] = iLoadImage("menu\\startup2.png");
	startupImg[3] = iLoadImage("menu\\startup3.png");
	startupImg[4] = iLoadImage("menu\\startup4.png");
	startupImg[5] = iLoadImage("menu\\startup5.png");


	dragonhurtimage[0] = iLoadImage("dragon\\dragonhurt.png");
	dragonhurtimage[1] = iLoadImage("dragon\\dragonimmune.png");
	*/

}



#endif