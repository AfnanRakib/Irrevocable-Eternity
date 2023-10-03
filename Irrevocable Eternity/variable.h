#ifndef HEADER_H_VARIABLE
#define HEADER_H_VARIABLE

#pragma warning(disable:4996)

#define SCREENWIDTH 800
#define SCREENHEIGHT 500
#define upperBgSpeed 10
//#define BgSpeed 5
#define fireSpeed 10
#define skylimit 380
#define groundlimit 30
#define JUMPLIMIT 500

int d = 0;
int standingbg;
int exitimage;
int musicimage;
int playimage;
int homeimage;
int levelcompleteimage;
int levelfailimage;
int instructions;
int aboutus;

int gameState = -1;
bool musicOn = true;
//bool levelone = false;
bool levelone = true;
//bool leveltwo = true;
bool leveltwo = false;

int levelComplete = 0;

int scrn = 1;

int ground = 50;
bool onplatform = false;

char leveloneBG[10];
//int initialBgX = 0;


int menuBG[2];
int startup = 0;
int loading = -2000;
int startupImg[6];
//:::::::::::::::::::::::::::::::::::::::::::leveltwo:::::::::::::::::::::::::::::::::::::::::::

struct Background{
	int x;
	int y;
};

Background upperBackground[16];
Background fireBackground[16];


int dragonhurtcnt = 0;
char dragonhurtimage[2];

int dragonhp = 5;
bool dragonhurt = false;

int dragonCordinateX = 50;
int dragonCordinateY = 210;

char dragon[6];
int dragonIndex = 0;
int dragoncnt = 0;

bool flyup = false;
bool flydown = false;

int firebg;
char upperBg[16];
int trap;
int scorebar;
//:::::::::::::::::::::::::::::::::::::::::::levelone:::::::::::::::::::::::::::::::::::::::::::
int natanCordinateX = 0;
int natanCordinateY = ground;

bool natanStandPos = true;
int standCnt = 0;

char natanStand[3];
int natanStandIndex = 0;

char natanRun[6];
int natanRunIndex = 0;

//char natanAtk[5];
//int natanAtkIndex = 0;

int natanJumpUpIndex;
int natanJumpDownIndex;
int natanaltJumpUpIndex;
int natanaltJumpDownIndex;

bool jump = false;//jump trigger
bool jumping = false;//jump image show
int natanJumpCordinate = 0;


char natanaltStand[3];
int natanltStandIndex = 0;

bool attack = false;//...> natan attack case

int nonatkcnt = 0;//...natan attack timer

int nonshldcnt = 0;//...natan sheild timer

int cas = 0;      //.....natan left<->right case

bool running = false;///--->natan running case

bool sheild = false;///--->natan sheild case

bool hHurt = false; ///--->natan hurt case

bool atkanimation = false;

char natanAtk[3][3];
int natanAtkIndex = 0;
int natanAtkAnimationIndex = 0;

char natanaltAtk[3][3];	//
int natanaltAtkIndex = 0;//...>flipped attack
int natanaltAtkAnimationIndex = 0;


char natanDeath[9];
int nathurt_i = 0;

char natanaltRun[6];
int natanaltRunIndex = 0;

//char natanaltAtk[4];	//
//int natanaltAtkIndex = 0;//...>flipped attack

char natanshld[1];
int natanshldIndex = 0;//---->natan sheild rendering

char natanaltshld[1];
int natanaltshldIndex = 0;//--->natan flipped sheild

//int natanjmp = natanCordinateY - 100;//----->jmp cordinate

int jumps = 0; ////------>limiting per jump
bool jumpup = false; ///----> for jumping up
bool jumpdown = false;////---->for jumping down

int hHitpoints = 10;///---->hero health
int dHitpoints = 10; 
bool dragondeath = false;

char hp[11];//--->health bar

bool hDeath = false;
int death;



int enemyatkwait = 0;
//int num = 1;
struct enemyc{
	
	//int eatkanimationCount = 0;
	
	//int eHurtanimationCount = 0;

	//int i = 0;

	int X /*= SCREENWIDTH + rand()%10 + rand()%20*/;
	int Y /*= ground*/;

	int eHitpoints ;///---->enemy health
	bool eHurtanimation;
	bool eHurt ;///--->enemy hurt case

	bool eatkanimation;
	bool eatk ;///---->enemy attack case

	bool erun ;///---->enemy run case
	bool eleft ;

	bool espawn;  ///-----> enemy spawn case
	bool edeath;
	int enemyRunIndex;//--->enemy run
	int enemyatkIndex;
	int altenemyRunIndex;
	int enemyhurtIndex;
	int enemydeathIndex;
	int enemytype ;
};
int i = 0;
struct enemyc e[10];
int eatkanimationCount = 0;
int eHurtanimationCount = 0;

//int spawntime = 0;
int eatkcnt = 0;
char enemyRun[2][4];
//--->enemy run
char altenemyRun[2][4];

char enemyatk[2][1];
//--->enemy attack

char enemyhurt[2][1];
//--->enemy hurt

char enemydeath[2][1];

//---->enemy death

int enemytype = 0;

void spawn(int);




//bool collision(int obj1_x, int obj1_y, int obj1_w, int obj1_h, int obj2_x, int obj2_y, int obj2_w, int obj2_h);
void platforming(int box_x1, int box_y1, int box_w1, int box_h1);

bool lastcoli = false;///--->last colision check
bool currentcoli = false;//--->current colision check

int box_x = 120;//	.
int box_y = 140;//	.
int box_w = 200;//  .   -->tiles coordinate.
int box_h = 40;//   .

int box_x2 = 380;//	.
int box_y2 = 140;//	.
int box_w2 = 200;//  .   -->tiles coordinate.
int box_h2 = 40;//   .

int box_x3 = 280;//	.
int box_y3 = 155;//	.
int box_w3 = 200;//  .   -->tiles coordinate.
int box_h3 = 40;//   .*/

int box_x4 = 85;//	.
int box_y4 = 140;//	.
int box_w4 = 155;//  .   -->tiles coordinate.
int box_h4 = 45;//   .*/

int box_x5 = 535;//	.
int box_y5 = 135;//	.
int box_w5 = 155;//  .   -->tiles coordinate.
int box_h5 = 50;//   .*/

int box_x6 = 110;//	.
int box_y6 = 250;//	.
int box_w6 = 200;//  .   -->tiles coordinate.
int box_h6 = 45;//   .*/

int box_x7 = 425;//	.
int box_y7 = 245;//	.
int box_w7 = 420;//  .   -->tiles coordinate.
int box_h7 = 50;//   .*/

int box_x8 = 0;
int box_y8 = 100;
int box_w8 = 144;
int box_h8 = 30;

int box_x9 = 294;
int box_y9 = 340;
int box_w9 = 140;
int box_h9 = 30;

int box_x10 = 700;
int box_y10 = 100;
int box_w10 = 140;
int box_h10 = 30;

int box_x11 = 90;
int box_y11 = 205;
int box_w11 = 140;
int box_h11 = 35;

int box_x12 = 434;
int box_y12 = 245;
int box_w12 = 140;
int box_h12 = 35;

int box_x13 = 180;
int box_y13 = 175;
int box_w13 = 366;
int box_h13 = 45;

int dx = 5;
int dx2 = 6;
int dx3 = 1;
int dx6 = 4;
int dx11 = 4;
int dx12 = 5;

int platform;

int arr1[4];

int boxdistance = 0;

int scoreimg[10];
int scorei = 0;
int scorej = 0;
int scorek = 0;
int scorepoint = 0;
int score_x = 700;
int score_y = 440;

int scoretimer;
int flytimer;
int changebgtimer;
int dragontimer;
int boxtimer;
int enemytimer;
int jumptimer;
int runtimer;
int t1sectimer;
int ehurtimer = 0;
int etimer = 0;
int espawntimer = 0;
int coincollectimer = 0;
int atkanimationtimer = 0;

struct coins
{
	int coin_x;
	int coin_y;
	int coin_h;
	int coin_w;
	int coinIndex;
	bool coinShow;
};

struct coins c[10];

bool coinc = false;
char coin[10];
bool leveldone = false;





void t1sec(){
	startup++;
	natanStandIndex++;
	if (natanStandIndex >= 3)
		natanStandIndex = 0;
	natanltStandIndex++;
	if (natanltStandIndex >= 3)
		natanltStandIndex = 0;
}
bool enemykill = false;

void scorefunc(){
	//scorei++;
	if (enemykill){
		scorei += 5;
		enemykill = false;
	}

	if(coinc){
		scorei += 5;
		coinc = false;
	}

	else if (leveltwo)
		scorei++;
	if (scorei > 9){
		int temp = scorei;
		scorei = scorei % 10;
		scorej += temp / 10;
		if (scorej > 9){
			temp = scorej;
			scorej = scorej % 10;
			scorek += temp / 10;
		}
	}

	scorepoint = scorek * 100 + scorej * 10 + scorei;
	//scorei = scorepoint % 10;
	//scorej = scorepoint % 100;
	//scorek = scorepoint % 1000;
	//cout << "score: "<<scorepoint << endl;
}


void levelChange(){
	if (levelComplete == 1){
		levelone = false;
		//leveltwo = true;
	}
	else if(levelComplete == 2){
		//levelone = true;
		leveltwo = false;
	}
}


void groundset(){
	/////------------------setting ground----------///
	for (int i = 0; i <10; i++)
		e[i].Y = ground;
	if (!jumpup && !jumpdown && !onplatform){
		if (scrn == 2){
			ground = 95;
			natanCordinateY = ground;
		}
		else if (scrn == 1){
			ground = 50;
			natanCordinateY = ground;
		}
		else if (scrn == 3){
			ground = 95;
			natanCordinateY = ground;
		}
		else if (scrn == 4){
			ground = 55;
			natanCordinateY = ground;
		}
		else if (scrn == 5){
			ground = 60;
			natanCordinateY = ground;
		}
		else if (scrn == 6){
			ground = 75;
			natanCordinateY = ground;
		}
		else if (scrn == 7){
			ground = 45;
			natanCordinateY = ground;
		}
		else if (scrn == 8){
			ground = 45;
			natanCordinateY = ground;
		}
		else if (scrn == 9){
			if (natanCordinateX < 140 || natanCordinateX >700)
				ground = 130;
			else
				ground = 50;
			natanCordinateY = ground;
		}
		else if (scrn == 10){
			ground = 150;
			natanCordinateY = ground;
		}
	}
}
#endif