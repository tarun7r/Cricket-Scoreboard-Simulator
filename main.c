#include <at89c5131.h>
#include "lcd.h"		//Header file with LCD interfacing functions
#include "serial.c"	//C file with UART interfacing functions


//Main function
void inning(void)
{ 
	unsigned int score = 0;
	unsigned int reg= 0xC0;
	unsigned int wickets = 0;
	unsigned int balls = 0;              // used for increasing the balls in the over 0.x
	unsigned int overs = 0;              // used for increasing the overs x.0 accprding to my code 1.6 = 2.0
	unsigned int overallballs = 0;  
	unsigned int ch=0;
  unsigned char currentscore[20];
	unsigned char currentballs[10];
	unsigned char currentovers[10];
	unsigned char currentevent[10];
	unsigned char currentwickets[10];
	//Call initialization functions
	lcd_init();
	uart_init();
	lcd_cmd(0x83);
	lcd_write_string(" 0/0  (0.0)");
	
	
	while(1)
	{
			//Receive a character
			ch = receive_char();
		  
		  if (balls>5){
				overs=overs+1;
				int_to_string1(overs,currentovers);
				lcd_cmd(0x8A);
				lcd_write_string(currentovers);
				lcd_cmd(0xC0);
				lcd_write_string("            ");
				reg=0xC0;
				if (overs>9){
				overs=overs-10;
			  int_to_string1(overs,currentovers);
				lcd_cmd(0x8A);
				lcd_write_string(currentovers);
				lcd_cmd(0x88);
				lcd_write_string("(1");
				
				}	
				balls=0;
			 }
			
			
       
				
				
			//Decide which test function to run based on character sent
      //Displays the string on the terminal software
			switch(ch)
			{				
				case '1': 
					       score++;
				         balls++;
				         int_to_string3(score,currentscore);
				         lcd_cmd(0x82);
								 lcd_write_string(currentscore);
		             int_to_string1(balls,currentballs);
				         lcd_cmd(0x8C);
								 lcd_write_string(currentballs);
				         
								 break;
				case '2': 
					       score=score+2;
				         balls++;
				         int_to_string3(score,currentscore);
				         lcd_cmd(0x82);
								 lcd_write_string(currentscore);
		             int_to_string1(balls,currentballs);
				         lcd_cmd(0x8C);
								 lcd_write_string(currentballs);
				
								 break;
				case '3': 
					       score=score+3;
				         balls++;
				         int_to_string3(score,currentscore);
				         lcd_cmd(0x82);
								 lcd_write_string(currentscore);
		             int_to_string1(balls,currentballs);
				         lcd_cmd(0x8C);
								 lcd_write_string(currentballs);
				
								 break;
				case '4': 
					       score=score+4;
				         balls++;
				         int_to_string3(score,currentscore);
				         lcd_cmd(0x82);
								 lcd_write_string(currentscore);
		             int_to_string1(balls,currentballs);
				         lcd_cmd(0x8C);
								 lcd_write_string(currentballs);
				
								 break;
				case '5': 
					       score=score+5;
				         balls++;
				         int_to_string3(score,currentscore);
				         lcd_cmd(0x82);
								 lcd_write_string(currentscore);
		             int_to_string1(balls,currentballs);
				         lcd_cmd(0x8C);
								 lcd_write_string(currentballs);
				
								 break;
				case '6': 
					       score=score+6;
				         balls++;
				         int_to_string3(score,currentscore);
				         lcd_cmd(0x82);
								 lcd_write_string(currentscore);
		             int_to_string1(balls,currentballs);
				         lcd_cmd(0x8C);
								 lcd_write_string(currentballs);
				
								 break;
				case 'E': 
					       score=score+1;
				         int_to_string3(score,currentscore);
				         lcd_cmd(0x82);
								 lcd_write_string(currentscore);
				         overallballs=overallballs-1;
								 break;
			 	case 'W': 
					       wickets=wickets+1;
				         balls++;
				         int_to_string1(wickets,currentwickets);
				         lcd_cmd(0x86);
								 lcd_write_string(currentwickets);
				         int_to_string1(balls,currentballs);
				         lcd_cmd(0x8C);
								 lcd_write_string(currentballs);
				         if(wickets>9){
				         lcd_cmd(0x86);
								 lcd_write_string("10");
								 }
				
								 break;
				case 'N': 
					       score=score+1;
				         int_to_string3(score,currentscore);
				         lcd_cmd(0x82);
								 lcd_write_string(currentscore);
				         overallballs=overallballs-1;
								 break;
				case '.': 
					       balls=balls+1;
				         int_to_string1(balls,currentballs);
				         lcd_cmd(0x8C);
								 lcd_write_string(currentballs);
								 break;
				
				
				
				
							
				default:transmit_string("Incorrect test. Pass correct number\r\n");
								 break;
				
			}
			
		
		  overallballs=overallballs+1;
			if(overallballs>119) {
				transmit_string("Innings is completed");
				lcd_cmd(0xC0);
	      lcd_write_string("Innings Ends");
				msdelay(5000);
				overs=0;
				wickets=0;
				balls=0;
				score=0;
				lcd_cmd(0x83);
	      lcd_write_string(" 000/0 (0.0)");
				return;
				}
			else if(wickets>9) {
				transmit_string("Innings is completed");
				lcd_cmd(0xC0);
	      lcd_write_string("Innings Ends");
				msdelay(5000);
				overs=0;
				wickets=0;
				balls=0;
				score=0;
				lcd_cmd(0x83);
	      lcd_write_string(" 000/0 (0.0)");
				return;
				}
			reg = reg+1;
		  lcd_cmd(reg);
		  int_to_string2(ch,currentevent);
	    lcd_write_string(currentevent);
			msdelay(100);
	}

}
void main(void){
	inning();
	inning();
}
