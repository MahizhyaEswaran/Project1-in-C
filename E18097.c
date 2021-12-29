#include <stdio.h>                     // include standard input output header file
#include <stdlib.h>                    
#include <string.h>
#include <time.h>
#include <unistd.h>
#define Reset		0
#define Bright		1 
#define Black 		0
#define Red	    	1
#define Green		2
#define Yellow		3
#define Blue		4
#define Magenta		5
#define Cyan		6
#define	White		7
#define DC	        8
void BackColor(int,int,int);
int ColorPointOut(char *);
int DegitPointOut(char);
int place(int );
void Noarr(char get, int X, int color);
void colon(int, int);
void putDigit(int (*array)[6], int X, int color);


//main function//

int main(int argc, char **argv){
	int X;
	int i;
	int colorvalue;

	if(argc==1){
		colorvalue = 7;	// set color white//
	}
	else if(argc==3){
		char *colour=(argv[2]);
		colorvalue =  ColorPointOut(colour);  	// get color value
			if(colorvalue==100){
				printf("%s :This is not a valid color, Please enter one of these colours: black, red, green, yellow, blue, magenta, cyan, white\n",colour);    // print error mdg for invalid input color
				return 0;
			}
	}

	else{
			
//declare error messages////
	  char em1[50]="Invalid use of arguments.\n";
	  char em2[50]="Invalid argument for color.\n";
	  char cm4[100]="usage : clock -h                quick help on cmd\n";
    char cm5[100]="usage : clock -c <color>        print clock with a color\n"; 
	  char cm6[100]="<color-black|red|green|yellow|blue|magenta|cyan|white>  supported colors\n";
	  
	
	
 
 int a=1;
 	
	if((argc==3)&&(strcmp(argv[1],"-c")==0)){
		printf("%s",em2);						//print the specific error message
    a=0;
	}else{
	     if((argc!=2)||(strcmp(argv[1],"-h")!=0)){
			printf("%s",em1);					//print the specific error message
      a=0;
			}
	}
	printf("%s%s",cm4,cm5);	//print the common message
  if(a==1){
  printf("%s",cm6);}
	 
 
 
 
 
 
 
 
 
 
 
 
 
 
		return 0;
	}
	
	printf("\033[?25l");	// Hiding the cursor
	printf("\033[2J");		// Clear console
 	

	while(1){
		char time_value[20];
  		char date[20];
  		time_t current_time;  		       // time_t: a data type used to store system time values
  		current_time = time(NULL);         // time elapsed (in seconds) since Epoch
  
  		struct tm* brokentime = localtime(&current_time);   // Converts to broken down time 
  
  		strftime(time_value,20,"%X", brokentime);	//current time
  		strftime(date,20,"%Y-%m-%d", brokentime);	// current Date
	
  	//update hour, minute and second
  	for(X=0;X<2;X++)	// print Hour
  		Noarr(time_value[X],X,colorvalue);

  	colon(15,colorvalue);		// print colon

  	for(X=3;X<5;X++)	// print minute
  		Noarr(time_value[X],X,colorvalue);

  	colon(34,colorvalue);            //print colon

  	for(X=6;X<8;X++)		// print second
  		Noarr(time_value[X],X,colorvalue);

  	
  	printf("\033[8;23H");
	BackColor(Bright, colorvalue, DC);
  	
  	for(i=0;i<12;i++){
  		printf("%c",date[i]);                //print date
  	}
  	
  	putchar('\n');
  	BackColor(Reset, White, Black);
  	sleep(1);                                 ////wait till 1 second
  	}
	
	return 0;
}




//print in black backround
void BackColor(int attr, int fg, int bg){
	char command[13];                    
	printf("\033[0m");

	if (attr == Bright){
		if (fg == DC){
			printf("\033[%dm", bg +40);
		}else{
			printf("\033[%dm", fg +30);
		}
	}

}



// funtion for pointOut input color//
int  ColorPointOut(char *Y){    			
	char *Ary[]={"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};					
	int R,len= sizeof(Ary) / sizeof( Ary[0] );

	for(R=0;R<len;R++){
 		if(strcmp(Y,Ary[R])==0){
 			return R;		
 		}
 	}
 	return 100;
}




// funtion for digit pointout//
int DegitPointOut(char Y){    			
	char Arr[]={'0','1','2','3','4','5','6','7','8','9'};					
	int R,len = sizeof(Arr)/sizeof( Arr[0] );

	for(R=0;R<len;R++){
 		if(Y==Arr[R]){
 			return R;		
 		}
 	} 
	 	
}



		
int place(int h){
 int _Space;
  if (h==0){
		_Space=2;}
  else if(h==1){
		_Space=9;}
  else if(h==3){
		_Space=21;}
  else if(h==4){
		_Space=28;}
  else if(h==6){
		_Space=40;} 
  else if(h==7){
		_Space=47;}

	return _Space;
}










// function for set  array for every digit//
void Noarr(char get,int X,int color){	
	int Digitarr[5][6];
	int No=DegitPointOut(get);
	int j=0;
	
	//array for No 0
	if(No==0){                   
		int Digitarr[5][6]={			  
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,0,0,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1}
	};}
   //array for No 1
	else if(No==1){
		int Digitarr[5][6]={		    	
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1}
	};}
    //array for No 2
	else if(No==2){
		int Digitarr[5][6]={		     	
		{1,1,1,1,1,1}, 
		{0,0,0,0,1,1},
		{1,1,1,1,1,1},
		{1,1,0,0,0,0},
		{1,1,1,1,1,1}
	};}
    //array for No 3
	else if(No==3){
		int Digitarr[5][6]={		    
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1}
	};}
    //array for No 4
	else if(No==4){
		int Digitarr[5][6]={			
		{1,1,0,0,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1}
	};}
    //array for No 5
	else if(No==5){
		int Digitarr[5][6]={		
		{1,1,1,1,1,1},
		{1,1,0,0,0,0},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1}
	};}
    //array for No 6
	else if(No==6){
		int Digitarr[5][6]={			
		{1,1,1,1,1,1},
		{1,1,0,0,0,0},
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1}
	};}
    //array for No 7
	else if(No==7){
		int Digitarr[5][6]={			
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1},
		{0,0,0,0,1,1}
	};}
    //array for No 8
	else if(No==8){
		int Digitarr[5][6]={		
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1}
	};}
    //array for No 9
	else if(No==9){
		int Digitarr[5][6]={			
		{1,1,1,1,1,1},
		{1,1,0,0,1,1},
		{1,1,1,1,1,1},
		{0,0,0,0,1,1},
		{1,1,1,1,1,1}
	};}
putDigit(Digitarr,X,color);
}


// functioin for print  colon//
void colon(int X, int color){		
	
	int row,column;

	int array[5][6]={			
		{0,0,0,0,0,0},
		{0,0,1,1,0,0},
		{0,0,0,0,0,0},
		{0,0,1,1,0,0},
		{0,0,0,0,0,0}
	};

	for(int row=0;row<=5;row++){		
		for(int column=0;column<=6;column++){
			printf("\033[%d;%dH",row+2,column+X);
			if(array[row][column]==0){
				BackColor(Reset, White, Black);
				printf(" ");
			}
			else if(array[row][column]==1){
				BackColor(Bright, DC, color);
				printf(" ");
			}

		}
	BackColor(Reset, White, Black);
	}		
}




// function for print the digits//
void putDigit(int (*array)[6],int X, int color){

	int row,column;

	for(int row=0;row<5;row++){
		for(column=0;column<6;column++){
			printf("\033[%d;%dH",row+2,column+place(X));
			int value = array[row][column];
			if(value==0){
				BackColor(Reset, White, Black);
				printf(" ");
			}
			else if(value==1){
				BackColor(Bright, DC, color);
				printf(" ");
			}
		}
		BackColor(Reset, White, Black);	
	}
}



