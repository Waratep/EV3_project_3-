#pragma config(Sensor, S1,     left_light,     sensorEV3_Color)
#pragma config(Sensor, S2,     ultrasonic,     sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     back_light,     sensorLightActive)
#pragma config(Sensor, S4,     right_light,    sensorEV3_Color)
#pragma config(Motor,  motorA,          motor_A,       tmotorEV3_Large, PIDControl, reversed, encoder)
#pragma config(Motor,  motorB,          motor_B,       tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          motor_C,       tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorD,          motor_D,       tmotorEV3_Large, PIDControl, reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define power_turn 40
#define power_delay 100
#define power_delay2 250
#define color_define 28
#define turn_delay 5000
#define two_turn_delay 10000
#define delay_color 3000

void beep(int i);
void forward(int bias ,float x);
void turn_left();
void two_turn_left();
void turn_right();
void stop_motor();
void checkbox();
void _init_();
void forward_until(int point);
void forward_until_noxy(int point);
void edit_map();
void blink(int i);
void findoneandkeepbox();
void keepbox();
void closearm();
int seq = 0;
int six = 0,nine = 0,color = 0,sum_error = 0,enable_delay = 0;;
float last_error=0;


//////////////////////////

void findone();
void findwall(int bx,int by);

int checkoor(int x,int y);
int checkwall(int x,int y);
void changeone(int bx,int by);
int min2(int a, int b);
int min3(int a, int b, int c);
int min4(int a, int b, int c, int d);

void _move();
void min2way(int a, int b,int checkw);
void min3way(int a, int b, int c);
float kp = 0.5,ki = 0,kd = 3.5;


//void keep_box();




//        north(0)

//	east(1)	      west(2)

//			  south(3)

int di = 0;
int x = 10 ,y = 9;
int bx=0,by=0;
int status = 0;
int ultra = 0;
void checkblock(int x,int y);
int checkx(int x,int i);
int checky(int y,int i);
void checkmap();
void printmap();
void printmapfloodfill();
void prekeep(int bx ,int by);

int checkxf(int x);
int checkyf(int y);
int checkxl(int x);
int checkyl(int y);
int checkxr(int x);
int checkyr(int y);
int checkxb(int x);
int checkyb(int y);

int checkxne(int x);
int checkyne(int y);
int checkxnw(int x);
int checkynw(int y);
int checkxse(int x);
int checkyse(int y);
int checkxsw(int x);
int checkysw(int y);

void checkleftbox1(int x, int y);
void checkrightbox1(int x, int y);


//int map[][] =
//{   //0 1 2 3 4 5 6 7 8 9
//	{1,1,1,1,1, 1,1,1,1,1},//0
//	{1,0,0,0,0, 0,0,0,0,1},//1
//	{1,0,0,0,0, 0,0,0,0,1},//2
//	{1,0,0,0,0, 0,0,0,0,1},//3
//	{1,0,0,0,0, 0,0,0,0,1},//4

//	{1,0,0,0,0, 0,0,0,0,1},//5
//	{1,0,0,0,0, 0,0,0,0,1},//6
//	{1,0,0,0,0, 0,0,0,0,1},//7
//	{1,0,0,0,0, 0,0,0,0,1},//8
//	{1,1,1,1,1, 1,1,1,1,1} //9
//};

int map[][] =
{   //0 1 2 3 4 5 6 7 8 9
	{1,1,1,1,1, 1,1,1,1,1},//0
	{1,1,1,1,1, 1,9,1,1,1},//1
	{1,1,1,6,9, 1,1,1,1,1},//2
	{1,9,1,1,1, 1,1,1,1,1},//3
	{1,1,1,1,1, 1,1,1,1,1},//4

	{1,1,1,1,1, 1,1,6,1,1},//5
	{1,1,1,1,1, 1,1,6,1,1},//6
	{1,1,1,1,1, 6,1,9,1,1},//7
	{1,1,1,1,1, 1,1,1,1,1},//8
	{1,1,1,1,1, 1,1,1,1,1} //9
};


int mapone[10][10] =  //changemap at
{   //0 1 2 3 4 5 6 7 8 9
    {81,81,81,81,81, 81,81,81,81,81},//0
    {81,81,81,81,81, 81,81,81,81,81},//1
    {81,81,81,81,81, 81,81,81,81,81},//2
    {81,81,81,81,81, 81,81,81,81,81},//3
    {81,81,81,81,81, 81,81,81,81,81},//4

    {81,81,81,81,81, 81,81,81,81,81},//5
    {81,81,81,81,81, 81,81,81,81,81},//6
    {81,81,81,81,81, 81,81,81,81,81},//7
    {81,81,81,81,81, 81,81,81,81,81},//8
    {81,81,81,81,81, 81,81,81,81,81} //9
};


task main()
{

	enable_delay = 0;
	_init_();
	enable_delay = 1;
	//while(1){
	//	forward(70,0.6);
	//}
	x = 9;
	y = 9;
	findoneandkeepbox();
	map[bx][by]=1;
	forward_until_noxy(1);
	bx=7;
  by=2;
	//bx = 1;
	//by = 7;

  for(int i=0;i<20;i++){
     changeone(bx,by);
  }
  printmapfloodfill();
  while(x!=bx || y!=by)
  {
      if(mapone[x][y]==1){
          break; //keepblock
      }else{
          _move();
      }
  }

	closearm();
	findoneandkeepbox();
	map[bx][by]=1;
	forward_until_noxy(1);
	bx = 1;
	by = 7;

	for(int i=0;i<20;i++){
     changeone(bx,by);
  }
  printmapfloodfill();
  while(x!=bx || y!=by)
  {
      if(mapone[x][y]==1){
          break; //keepblock
      }else{
          _move();
      }
  }
  closearm();


	//keepbox();
	//closearm();


}

void _init_(){

	int counter = 0 , left , right , point = 0 , angle = 0;
	float buff_bias = 0;
	while(point < 40){
		left = SensorValue[S1];
		right = SensorValue[S4];
		left = left > 40 ? 40:left;
		left = left < 5 ? 5:left;
		right = right > 40 ? 40:right;
		right = right < 5 ? 5:right;
		buff_bias = buff_bias > 70 ? 70:buff_bias;
		buff_bias += 0.05;
		forward(buff_bias,0.6);
		if(counter == 10){
			//for(int i = 0 ; i < 300 ;i++) forward(50,0.5);
			buff_bias = 0;
			turn_left();
			counter = 1;
			point++;
			angle++;
		}

		if(left < 14 && right < 14) {
			beep(0);
			switch(angle){
			case 0 : x--; break;
			case 1 : y--; break;
			case 2 : x++; break;
			case 3 : y++; break;
			}
			counter++;
			if(enable_delay == 0){
				for(int i = 0 ; i < power_delay2 ;i++) forward(50,0.5);
			}else{
				for(int i = 0 ; i < power_delay ;i++) forward(50,0.5);
			}
			if(counter != 10 && counter != 1){
				stop_motor();
				turn_left();
				checkmap();
				checkbox();
				printmap();
				stop_motor();
			}
			point++;
		}

	}
	turn_left();
	di = 0;

}

void forward_until(int point){
	int left, right ,count = 0;
	float buff_bias = 0;
	while(count < point){
		left = SensorValue[S1];
		right = SensorValue[S4];
		left = left > 40 ? 40:left;
		left = left < 5 ? 5:left;
		right = right > 40 ? 40:right;
		right = right < 5 ? 5:right;
		buff_bias = buff_bias > 70 ? 70:buff_bias;
		buff_bias += 0.1;
		forward(buff_bias,0.6);
		if(left < 14 && right < 14) {
			beep(0);
			switch(di){
				case 0 : x--; break;
				case 1 : y--; break;
				case 2 : y++; break;
				case 3 : x++; break;
			}
			count++;
		}
	}
		if(enable_delay == 0){
			for(int i = 0 ; i < power_delay2 ;i++) forward(50,0.5);
		}else{
			for(int i = 0 ; i < power_delay ;i++) forward(50,0.5);
		}

	stop_motor();
}

void forward_until_noxy(int point){
	int left, right ,count = 0;
	float buff_bias = 0;
	while(count < point){
		left = SensorValue[S1];
		right = SensorValue[S4];
		left = left > 40 ? 40:left;
		left = left < 5 ? 5:left;
		right = right > 40 ? 40:right;
		right = right < 5 ? 5:right;
		buff_bias = buff_bias > 70 ? 70:buff_bias;
		buff_bias += 0.1;
		forward(buff_bias,0.6);
		if(left < 14 && right < 14) {
			beep(0);
			//switch(di){
			//	case 0 : x--; break;
			//	case 1 : y--; break;
			//	case 2 : y++; break;
			//	case 3 : x++; break;
			//}
			count++;
		}
	}
		if(enable_delay == 0){
			for(int i = 0 ; i < power_delay2 ;i++) forward(50,0.5);
		}else{
			for(int i = 0 ; i < power_delay ;i++) forward(50,0.5);
		}
	stop_motor();
}


void checkbox(){
	int avg_color = 0;
	color = 0;
	if(seq == 1){
		stop_motor();
		for(int i = 0; i < delay_color ; i++){
			avg_color = SensorValue[S3];
			displayTextLine(11,"%d",avg_color);
		}
		if(avg_color >= color_define && SensorValue[S2] < 15){
				color = 6; // orange
				blink(0);
		}else if(avg_color < color_define && SensorValue[S2] < 15){
				color = 9; // black
				blink(0);
		}else{ color = 0;}
		switch(color){
		case 6 : map[checkx(x,1)][checky(y,1)] = 6 ; break;
		case 9 : map[checkx(x,1)][checky(y,1)] = 9; break;
		default : if(map[checkx(x,1)][checky(y,1)] == 6){map[checkx(x,1)][checky(y,1)] = 6;}
							else if(map[checkx(x,1)][checky(y,1)] == 9){map[checkx(x,1)][checky(y,1)] = 9;}
							else{map[checkx(x,1)][checky(y,1)] = 1;} break;
		}
		turn_right();
	}else if(seq == 2){
		stop_motor();
		forward_until(1);
		for(int i = 0; i < delay_color ; i++){
			avg_color = SensorValue[S3];
		}
		if(avg_color >= color_define && SensorValue[S2] < 15){
				color = 6; // orange
				blink(0);
		}else if(avg_color < color_define && SensorValue[S2] < 15){
				color = 9; // black
				blink(0);
		}else{ color = 0;}
		switch(color){
		case 6 : map[checkx(x,1)][checky(y,1)] = 6; break;
		case 9 : map[checkx(x,1)][checky(y,1)] = 9; break;
		default : if(map[checkx(x,1)][checky(y,1)] == 6){map[checkx(x,1)][checky(y,1)] = 6;}
							else if(map[checkx(x,1)][checky(y,1)] == 9){map[checkx(x,1)][checky(y,1)] = 9;}
							else{map[checkx(x,1)][checky(y,1)] = 1;} break;
		}
		two_turn_left();
		forward_until(1);
		turn_left();
	}else if(seq == 3){
		stop_motor();
		forward_until(2);
		for(int i = 0; i < delay_color ; i++){
			avg_color = SensorValue[S3];
		}
		if(avg_color >= color_define && SensorValue[S2] < 15){
				color = 6; // orange
				blink(0);
		}else if(avg_color < color_define && SensorValue[S2] < 15){
				color = 9; // black
				blink(0);
		}else{ color = 0;}
		switch(color){
		case 6 : map[checkx(x,1)][checky(y,1)] = 6; break;
		case 9 : map[checkx(x,1)][checky(y,1)] = 9; break;
		default : if(map[checkx(x,1)][checky(y,1)] == 6){map[checkx(x,1)][checky(y,1)] = 6;}
							else if(map[checkx(x,1)][checky(y,1)] == 9){map[checkx(x,1)][checky(y,1)] = 9;}
							else{map[checkx(x,1)][checky(y,1)] = 1;} break;
		}
		two_turn_left();
		forward_until(2);
		turn_left();
	}else if(seq == 4){
		stop_motor();
		forward_until(3);
		for(int i = 0; i < delay_color ; i++){
			avg_color = SensorValue[S3];
		}
		if(avg_color >= color_define && SensorValue[S2] < 15){
				color = 6; // orange
				blink(0);
		}else if(avg_color < color_define && SensorValue[S2] < 15){
				color = 9; // black
				blink(0);
		}else{ color = 0;}
		switch(color){
		case 6 : map[checkx(x,1)][checky(y,1)] = 6; break;
		case 9 : map[checkx(x,1)][checky(y,1)] = 9; break;
		default : if(map[checkx(x,1)][checky(y,1)] == 6){map[checkx(x,1)][checky(y,1)] = 6;}
							else if(map[checkx(x,1)][checky(y,1)] == 9){map[checkx(x,1)][checky(y,1)] = 9;}
							else{map[checkx(x,1)][checky(y,1)] = 1;} break;
		}
		two_turn_left();
		forward_until(3);
		turn_left();
	}else{
		turn_right();
	}
	//if(seq != 1) turn_right();
}

void findoneandkeepbox(){
	//find boxmall 1 : Round 1
  findone();
  //printxy(x,y);
  //printxy(bx,by);
  for(int i=0;i<10;i++){
      changeone(bx,by);
  }
  //printmap(mapone);

  while(x!=bx || y!=by){
      if(mapone[x][y]==1){
          break; //keepblock
      }else{
          _move();
      }
      //printxy(x,y);
  }

  prekeep(bx,by);

  //printf("keep block\n");
  keepbox();

  status = 1;

}

void keepbox(){
	int error = 0;
	resetMotorEncoder(motorA);
	resetMotorEncoder(motorD);

  for(int i = 0 ; i < 5000 ; i++){
  	ultra = SensorValue[S2];
  	error = (12 - ultra)*3;
  	setMotorSpeed(motorA, (-1)*error);
		setMotorSpeed(motorD, (-1)*error);
  }
  stop_motor();
  two_turn_left();
  stop_motor();

	for(int j = 0 ; j < 40000 ; j++){ //open arm
  	setMotorSpeed(motorB, 55);
  }
  setMotorSpeed(motorB, 0);

 	for(int i = 0 ; i < 450 ; i++){   //init turn left
		setMotorSpeed(motorA,-30);
		setMotorSpeed(motorD,30);
	}

  for(int j = 0 ; j < 9000 ; j++){ //backward
  	setMotorSpeed(motorA, -30);
		setMotorSpeed(motorD, -30);
  }
  stop_motor();
  for(int j = 0 ; j < 19000 ; j++){//close aem
  	setMotorSpeed(motorB, -60);
  }
  setMotorSpeed(motorB, 0);

  //for(int i = 0 ; i < 1000 ;i++){
  //	forward(30,0.5);
  //}
  stop_motor();
  status = 1;

  //////////////////////////////////////////////


}

void closearm(){
	for(int j = 0 ; j < 19000 ; j++){//open arm
  	setMotorSpeed(motorB, 60);
  }
  setMotorSpeed(motorB, 0);
  forward_until(1);
  stop_motor();
  setMotorSpeed(motorB, 0);
  for(int j = 0 ; j < 40000 ; j++){ //close arm
  	setMotorSpeed(motorB, -55);
  }
  setMotorSpeed(motorB, 0);
}

void prekeep(int bx ,int by){
    if(checkxf(x) == bx && checkyf(y) == by){
    }else if(checkxl(x) == bx && checkyl(y) == by){
        turn_left();
    }else if(checkxr(x) == bx && checkyr(y) == by){
        turn_right();
    }else{
        turn_left();
        turn_left();
    }
    stop_motor();
}


void checkmap(){
	//if(SensorValue[S2] < 10){
	//	counter++;
	//}
	for(int i = 0 ; i < 3000 ; i++) ultra = SensorValue[S2];
	checkblock(x,y);
}
void checkblock(int x,int y){
	if(ultra >= 4 && ultra <= 12){
		map[checkx(x,0)][checky(y,0)]=1;
		map[checkx(x,1)][checky(y,1)]=4;
		seq = 1;
		blink(0);
	}
	else if(ultra >= 32 && ultra <= 48){
		map[checkx(x,0)][checky(y,0)]=1;
		map[checkx(x,1)][checky(y,1)]=1;
		map[checkx(x,2)][checky(y,2)]=4;
		seq = 2;
		blink(0);
	}
	else if(ultra >= 64 && ultra <= 74){
		map[checkx(x,0)][checky(y,0)]=1;
		map[checkx(x,1)][checky(y,1)]=1;
		map[checkx(x,2)][checky(y,2)]=1;
		map[checkx(x,3)][checky(y,3)]=4;
		seq = 3;
		blink(0);
	}
	else if(ultra >= 90 && ultra <= 102){
		map[checkx(x,0)][checky(y,0)]=1;
		map[checkx(x,1)][checky(y,1)]=1;
		map[checkx(x,2)][checky(y,2)]=1;
		map[checkx(x,3)][checky(y,3)]=1;
		map[checkx(x,4)][checky(y,4)]=4;
		seq = 4;
		blink(0);
	}
	else{
		for(int i=0;i<=4;i++){
			if( checkx(x,i)>=0 && checkx(x,i)<=9 && checky(y,i)>=0 && checky(y,i)<=9 )
			{
				map[checkx(x,i)][checky(y,i)]=1;
			}
		}
		seq = 0;
	}
}

void stop_motor(){

	setMotorSpeed(motorA, 0);
	setMotorSpeed(motorD, 0);
}


void forward(int bias ,float x){

	float pid , error  , left , right = 0;
	left = SensorValue[S1];
	right = SensorValue[S4];
	left = left > 40 ? 40:left;
	left = left < 5 ? 5:left;
	right = right > 40 ? 40:right;
	right = right < 5 ? 5:right;
	//`if(left == 5 && right == 5) beep(1);
	error = left - right;
	sum_error += error;
	//displayTextLine(0,"%f  %f  %f",error*x,(error-last_error)*(3.5),sum_error*(0.0012));
	pid = error*(kp) + (error-last_error)*(kd) + sum_error*(ki);
	//pid = error*(x) + (error-last_error)*(3.5) + sum_error*(0.0002);
	//int buff_bias = 0;
	//while(bias > buff_bias){
	//	buff_bias++;
	//	setMotorSpeed(motorA, buff_bias+pid);
	//	setMotorSpeed(motorD, buff_bias+pid*(-1));
	//	sleep(10);
	//}
	setMotorSpeed(motorA, bias+pid);
	setMotorSpeed(motorD, bias+pid*(-1));
	last_error = error;

}

void two_turn_left(){

	for(int i = 0 ; i < two_turn_delay ; i++){
		setMotorSpeed(motorA,-power_turn);
		setMotorSpeed(motorD,power_turn);
	}
	while(SensorValue[S4] > 28){
		setMotorSpeed(motorA,-power_turn);
		setMotorSpeed(motorD,power_turn);
	}
	while(SensorValue[S1] >= 28){

		setMotorSpeed(motorA,(SensorValue[S1]-28)*(1.1));
		setMotorSpeed(motorD,(SensorValue[S1]-28)*(-1.1));
	}

	stop_motor();
	switch(di){
	case 0 : di = 3; break;
	case 1 : di = 2; break;
	case 2 : di = 1; break;
	case 3 : di = 0; break;
	}
}

void turn_left(){

	for(int i = 0 ; i < turn_delay ; i++){
		setMotorSpeed(motorA,-power_turn);
		setMotorSpeed(motorD,power_turn);
	}
	while(SensorValue[S4] > 28){
		setMotorSpeed(motorA,-power_turn);
		setMotorSpeed(motorD,power_turn);
	}
	while(SensorValue[S1] >= 28){
		setMotorSpeed(motorA,(SensorValue[S1]-28)*(1.1));
		setMotorSpeed(motorD,(SensorValue[S1]-28)*(-1.1));
	}

	stop_motor();
	switch(di){
	case 0 : di = 1; break;
	case 1 : di = 3; break;
	case 2 : di = 0; break;
	case 3 : di = 2; break;
	}
}

void turn_right(){

	for(int i = 0 ; i < turn_delay ; i++){
		setMotorSpeed(motorA,power_turn);
		setMotorSpeed(motorD,-power_turn);
	}
	while(SensorValue[S1] > 28){
		setMotorSpeed(motorA,power_turn);
		setMotorSpeed(motorD,-power_turn);
	}
	while(SensorValue[S4] >= 28){

		setMotorSpeed(motorA,(SensorValue[S1]-28)*(1.1));
		setMotorSpeed(motorD,(SensorValue[S1]-28)*(-1.1));
	}

	stop_motor();

	switch(di){
	case 0 : di = 2; break;
	case 1 : di = 0; break;
	case 2 : di = 3; break;
	case 3 : di = 1; break;
	}
}

void beep(int i) {
	for (int j = -1; j < i ; j++) {
		playTone(4000, 10);
		sleep(200);
	}
}
void blink(int i) {
	for (int j = -1; j < i ; j++) {
		setMotorSpeed(motor_C,100);
		sleep(200);
		setMotorSpeed(motor_C,0);
	}
}

int checkx(int x,int i){
	switch(di){
	case 0: return x-i;
	case 1: return x;
	case 2: return x;
	default: return x+i;
	}
}
int checky(int y,int i){
	switch(di){
	case 0: return y;
	case 1: return y-i;
	case 2: return y+i;
	default: return y;
	}
}
void printmap(){
	for(int i = 0 ; i < 10 ; i++){
		displayTextLine(i,"%d %d %d %d %d %d %d %d %d %d %d",map[i][0],map[i][1],map[i][2],map[i][3],map[i][4],map[i][5],map[i][6],map[i][7],map[i][8],map[i][9]);
	}
}

void printmapfloodfill(){
	for(int i = 0 ; i < 10 ; i++){
		displayTextLine(i,"%2d %2d %2d %2d %2d %2d %2d %2d %2d %2d %2d",mapone[i][0],mapone[i][1],mapone[i][2],mapone[i][3],mapone[i][4],mapone[i][5],mapone[i][6],mapone[i][7],mapone[i][8],mapone[i][9]);
	}
}


void edit_map(){
	for(int i = 0 ; i < 10 ; i++){
		for(int j = 0 ; j< 10 ; j++){
				if(map[i][j] == 6) six++;
				if(map[i][j] == 9) nine++;
		}
	}

	if(six == 4 && nine == 4){
		for(int i = 0 ; i < 10 ; i++){
			for(int j = 0 ; j< 10 ; j++){
				if(map[i][j] == 0)map[i][j] = 1;
			}
		}
	}
}

void findone(){
    int count = 0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(map[i][j]==6 && count ==0){
                if(map[i+1][j] != 6 && map[i][j+1] != 6 && map[i-1][j] != 6 && map[i][j-1] != 6){
                    bx = i;
                    by = j;
                    mapone[i][j]=0;
                    count++;
                }
            }
        }
    }
    findwall(bx,by);
}

void findwall(int bx,int by){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(map[i][j]>1){
                //wall[i][j]=1;
                mapone[i][j]=99;
            }
        }
    }
    //wall[bx][by]=0;
    mapone[bx][by]=0;
}
////////////////////////////// change map
int checkoor(int x,int y){
    if(x < 0 || x > 9 || y < 0 || y > 9){
        return 1;
    }else{
        return 0;
    }
}
int checkwall(int x,int y){
    int checkw=0;

    if(checkoor(x-1,y)){
        checkw += 1;//front
    }else{
        if (mapone[x-1][y] == 99) {
            checkw += 1;//front
        }
    }

    if(checkoor(x,y-1)){
        checkw += 2;//left
    }else{
        if (mapone[x][y-1] == 99) {
            checkw += 2;//left
        }
    }

    if(checkoor(x,y+1)){
        checkw += 4;//front
    }else{
        if (mapone[x][y+1] == 99) {
            checkw += 4;//right
        }
    }

    if(checkoor(x+1,y)){
        checkw += 8;//front
    }else{
        if (mapone[x+1][y] == 99) {
            checkw += 8;//back
        }
    }
    return checkw;
}
void changeone(int bx,int by)
{
	int checkw = 0;
	for (int i = 0; i < 10 ; i++){
		for (int j = 0; j < 10; j++){

            if(mapone[i][j] != 99){
                checkw = checkwall(i,j);
                switch (checkw)
                {
                case 0: //front,left,right,back
                    mapone[i][j] = min4(mapone[i - 1][j], mapone[i][j - 1],
                                        mapone[i][j + 1], mapone[i + 1][j]);
                    break;
                case 1: //left,right,back
                    mapone[i][j] = min3(mapone[i][j - 1], mapone[i][j + 1], mapone[i + 1][j]);
                    break;
                case 2: //front,right,back
                    mapone[i][j] = min3(mapone[i - 1][j], mapone[i][j + 1], mapone[i + 1][j]);
                    break;
                case 3: //back,right
                    mapone[i][j] = min2(mapone[i][j + 1], mapone[i + 1][j]);
                    break;
                case 4: //front,left,back
                    mapone[i][j] = min3(mapone[i - 1][j], mapone[i][j - 1], mapone[i + 1][j]);
                    break;
                case 5: //left,back
                    mapone[i][j] = min2(mapone[i][j - 1], mapone[i + 1][j]);
                    break;
                case 6: //front,back
                    mapone[i][j] = min2(mapone[i - 1][j], mapone[i + 1][j]);
                    break;
                case 7: //back
                    mapone[i][j] = mapone[i + 1][j] + 1;
                    break;
                case 8: //front,left,right
                    mapone[i][j] = min3(mapone[i - 1][j], mapone[i][j - 1], mapone[i][j + 1]);
                    break;
                case 9: //left,right
                    mapone[i][j] = min2(mapone[i][j - 1], mapone[i][j + 1]);
                    break;
                case 10: //front,right
                    mapone[i][j] = min2(mapone[i - 1][j], mapone[i][j + 1]);
                    break;
                case 11: //right
                    mapone[i][j] = mapone[i][j + 1] + 1;
                    break;
                case 12: //front,left
                    mapone[i][j] = min2(mapone[i - 1][j], mapone[i][j - 1]);
                    break;
                case 13: //left
                    mapone[i][j] = mapone[i][j - 1] + 1;
                    break;
                case 14: //front
                    mapone[i][j] = mapone[i - 1][j] + 1;
                    break;
                default: //no
                    mapone[i][j] = 99;
                    break;
                }
                if (i == bx && j == by)
                {
                    mapone[bx][by] = 0;
                }
            }
		}
	}
}
int min2(int a, int b)
{
	if (a < b)
	{
		return a + 1;
	}
	else
	{
		return b + 1;
	}
}
int min3(int a, int b, int c)
{
	if (((a < b) && (a < c)) || ((a == c) && (a < b)) || ((a == b) && (a < c)))
	{
		return a + 1;
	}
	else if ((b < a) && (b < c) || ((b == c) && (b < a)))
	{
		return b + 1;
	}
	else if ((c < a) && (c < b))
	{
		return c + 1;
	}
	else
	{
		return a + 1;
	}
}
int min4(int a, int b, int c, int d)
{
	if (((a < b) && (a < c) && (a < d)) || ((a == b) && (a < c) && (a < d)) || ((a == c) && (a < b) && (a < d)) || ((a == d) && (a < b) && (a < c)))
	{
		return a + 1;
	}
	else if (((b < a) && (b < c) && (b < d)) || ((b == c) && (b < a) && (b < d)) || ((b == d) && (b < a) && (b < c)))
	{
		return b + 1;
	}
	else if ((c < a) && (c < b) && (c < d) || ((c == d) && (c < a) && (c < b)))
	{
		return c + 1;
	}
	else if ((d < a) && (d < b) && (d < c))
	{
		return d + 1;
	}
	else
	{
		return a + 1;
	}
}

//////////////////////////////move to goal
void _move(){
    int checkw=0;
    if(checkoor(checkxf(x),checkyf(y))){
        //printf("fwall\n");
        checkw += 1; //front
    }else{
        if (mapone[checkxf(x)][checkyf(y)] == 99 ){
           // printf("fwall\n");
           checkw += 1; //front
        }
    }
    if(checkoor(checkxl(x),checkyl(y))){
        //printf("lwall\n");
        checkw += 2; //left
    }else{
        if (mapone[checkxl(x)][checkyl(y)] == 99){
            //printf("lwall\n");
            checkw += 2; //left
        }
    }
    if(checkoor(checkxr(x),checkyr(y))){
        //printf("rwall\n");
        checkw += 4; //right
    }else{
        if (mapone[checkxr(x)][checkyr(y)] == 99){
            //printf("rwall\n");
            checkw += 4; //right
        }
    }
    switch(checkw){
        case 0: min3way(mapone[checkxf(x)][checkyf(y)] , mapone[checkxl(x)][checkyl(y)] , mapone[checkxr(x)][checkyr(y)]);
            break;
        case 1: min2way(mapone[checkxl(x)][checkyl(y)] , mapone[checkxr(x)][checkyr(y)],1);
            break;
        case 2: min2way(mapone[checkxf(x)][checkyf(y)] , mapone[checkxr(x)][checkyr(y)],2);
            break;
        case 3:
            if(status == 0){
                turn_right();forward_until(1);
            }
            else if(status == 1){
                checkrightbox1(x,y);
            }
            // turn_right();
            break;
        case 4: min2way(mapone[checkxf(x)][checkyf(y)] , mapone[checkxl(x)][checkyl(y)],4);
            break;
        case 5:
            if(status == 0){
                turn_left();forward_until(1);
            }
            else if(status == 1){
                checkleftbox1(x,y);
            }
            // turn_left();
            break;
        case 6:forward_until(1);break;
        default:turn_left();turn_left();forward_until(1);break;
    }
}
void min2way(int a, int b,int checkw)
{
	if (a <= b)
	{
		switch (checkw)
		{
		case 1:
            if(status == 0){
                turn_left();forward_until(1);
            }
            else if(status == 1){
                checkleftbox1(x,y);
            }
            // turn_left();
            break; //left,right
		case 2: forward_until(1);break; //front,right
		default: forward_until(1);break;//front,left
		}
	}
	else
	{
		switch (checkw)
		{
		case 1:
            if(status == 0){
                turn_right();forward_until(1);
            }
            else if(status == 1){
                checkrightbox1(x,y);
            }
            // turn_right();
            break; //left,right
		case 2:
            if(status == 0){
                turn_right();forward_until(1);
            }
            else if(status == 1){
                checkrightbox1(x,y);
            }
            // turn_right();
            break; //front,right
		default:
            if(status == 0){
                turn_left();forward_until(1);
            }
            else if(status == 1){
                checkleftbox1(x,y);
            }
            // turn_left();
            break; //front,left
		}
	}
}
void min3way(int a, int b, int c)
{ //front,left,right

	if (a != b && a != c && b != c)
	{
		if (a < b && a < c)
		{ //go front
			forward_until(1);
		}
		else if (b < a && b < c)
		{ //go left
			if(status == 0){
                turn_left();forward_until(1);
            }
            else if(status == 1){
                checkleftbox1(x,y);
            }
            // turn_left();

		}
		else
		{ //go right
			if(status == 0){
                turn_right();forward_until(1);
            }
            else if(status == 1){
                checkrightbox1(x,y);
            }
            // turn_right();

		}
	}
	else
	{
		forward_until(1);
	}
}

////////////////////////////// north east west
//front
int checkxf(int x){
    switch(di){
        case 0: return x-1;
        case 1: return x;
        case 2: return x;
        default: return x+1;
    }
}
int checkyf(int y){
    switch(di){
        case 0: return y;
        case 1: return y-1;
        case 2: return y+1;
        default: return y;
    }
}
//left
int checkxl(int x){
    switch(di){
        case 0: return x;
        case 1: return x+1;
        case 2: return x-1;
        default: return x;
    }
}
int checkyl(int y){
    switch(di){
        case 0: return y-1;
        case 1: return y;
        case 2: return y;
        default: return y+1;
    }
}
//right
int checkxr(int x){
    switch(di){
        case 0: return x;
        case 1: return x-1;
        case 2: return x+1;
        default: return x;
    }
}
int checkyr(int y){
    switch(di){
        case 0: return y+1;
        case 1: return y;
        case 2: return y;
        default: return y-1;
    }
}
//back
int checkxb(int x){
    switch(di){
        case 0: return x+1;
        case 1: return x;
        case 2: return x;
        default: return x-1;
    }
}
int checkyb(int y){
    switch(di){
        case 0: return y;
        case 1: return y+1;
        case 2: return y-1;
        default: return y;
    }
}
////////////////////////////// ne nw be bw
//northeast
int checkxne(int x){
    switch(di){
        case 0: return x-1;
        case 1: return x+1;
        case 2: return x-1;
        default: return x+1;
    }
}
int checkyne(int y){
    switch(di){
        case 0: return y-1;
        case 1: return y-1;
        case 2: return y+1;
        default: return y+1;
    }
}
//northwest
int checkxnw(int x){
    switch(di){
        case 0: return x-1;
        case 1: return x-1;
        case 2: return x+1;
        default: return x+1;
    }
}
int checkynw(int y){
    switch(di){
        case 0: return y+1;
        case 1: return y-1;
        case 2: return y+1;
        default: return y-1;
    }
}

//southeast
int checkxse(int x){
    switch(di){
        case 0: return x+1;
        case 1: return x+1;
        case 2: return x-1;
        default: return x-1;
    }
}
int checkyse(int y){
    switch(di){
        case 0: return y-1;
        case 1: return y+1;
        case 2: return y-1;
        default: return y+1;
    }
}
//southwest
int checkxsw(int x){
    switch(di){
        case 0: return x+1;
        case 1: return x-1;
        case 2: return x+1;
        default: return x-1;
    }
}
int checkysw(int y){
    switch(di){
        case 0: return y+1;
        case 1: return y+1;
        case 2: return y-1;
        default: return y-1;
    }
}
//turn car to box
void prekeep(int bx ,int by){
    if(checkxf(x) == bx && checkyf(y) == by){
    }else if(checkxl(x) == bx && checkyl(y) == by){
        turn_left();
    }else if(checkxr(x) == bx && checkyr(y) == by){
        turn_right();
    }else{
        turn_left();
        turn_left();
    }
}
//turn with box1
void checkleftbox1(int x, int y){
    //printf("left\n");
    if(checkoor(checkxr(x),checkyr(y)) && checkoor(checkxsw(x),checkysw(y))){
        turn_left();
    }
    else{
        if(checkoor(checkxsw(x),checkysw(y))){ //sw oor
            if(mapone[checkxr(x)][checkyr(y)] != 99){
                turn_left();
            }
        }else {
            if(mapone[checkxr(x)][checkyr(y)] != 99 && mapone[checkxsw(x)][checkysw(y)] != 99){
                turn_left();
            }else if(mapone[checkxr(x)][checkyr(y)] != 99 &&  mapone[checkxnw(x)][checkynw(y)] != 99 &&
                        mapone[checkxf(x)][checkyf(y)] != 99 && mapone[checkxne(x)][checkyne(y)] != 99 &&
                        mapone[checkxl(x)][checkyl(y)] != 99 && mapone[checkxse(x)][checkyse(y)] != 99 ){
                turn_right();turn_right();turn_right();
            }
            /*else if((mapone[checkxne(x)][checkyne(y)] == 99 && mapone[checkxnw(x)][checkynw(y)] == 99 &&
                        mapone[checkxse(x)][checkyse(y)] == 99 && mapone[checkxsw(x)][checkysw(y)] == 99 ) &&
                        mapone[checkxf(x)][checkyf(y)] == 99 || mapone[checkxl(x)][checkyl(y)] == 99 || mapone[checkxr(x)][checkyr(y)] == 99){
                printf("Release box");
                status=0;
                turn_left();turn_left();
                forward_until(1);forward_until(1);
                printf("Keep box");
                status=1;
                turn_left();
            }*/
            else{
                forward_until(1);
            }

        }
    }
}

void checkrightbox1(int x, int y){
    //printf("right\n");
    if(checkoor(checkxl(x),checkyl(y)) && checkoor(checkxse(x),checkyse(y))){
        turn_right();
    }
    else{
        if(checkoor(checkxse(x),checkyse(y))){ //sw oor
            if(mapone[checkxl(x)][checkyl(y)] != 99){
                turn_right();
            }
        }else{
            if(mapone[checkxl(x)][checkyl(y)] != 99 && mapone[checkxse(x)][checkyse(y)] != 99){

                turn_right();
            }else if(mapone[checkxl(x)][checkyl(y)] != 99 &&  mapone[checkxnw(x)][checkynw(y)] != 99 &&
                        mapone[checkxf(x)][checkyf(y)] != 99 && mapone[checkxne(x)][checkyne(y)] != 99 &&
                        mapone[checkxr(x)][checkyr(y)] != 99 && mapone[checkxsw(x)][checkysw(y)] != 99 ){
                turn_left();turn_left();turn_left();

            }
            /*else if((mapone[checkxne(x)][checkyne(y)] == 99 && mapone[checkxnw(x)][checkynw(y)] == 99 &&
                        mapone[checkxse(x)][checkyse(y)] == 99 && mapone[checkxsw(x)][checkysw(y)] == 99 ) &&
                        mapone[checkxf(x)][checkyf(y)] == 99 || mapone[checkxl(x)][checkyl(y)] == 99 || mapone[checkxr(x)][checkyr(y)] == 99){
                printf("Release box");
                status=0;
                turn_left();turn_left();
                forward_until(1);forward_until(1);
                printf("Keep box");
                status=1;
                turn_right();
            }*/
            else{
                //printf("*\n");
                forward_until(1);
            }

        }
    }

}
