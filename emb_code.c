#include<reg51.h>
sbit s1=P1^0;
sbit rs=P1^1; 
sbit rw=P1^2; 
sbit en=P1^3;
sbit buz=P3^0;
sbit led=P1^4;



void delay(unsigned int);
void lcdinit();
void lcddat(unsigned char);
void lcdcommand(unsigned char);
void lcddisp(unsigned char *);



void main()
{
buz=0;
led=0;
s1=0;
back:lcdinit();
lcddisp("Alert System");
buz=0;
led=0;
while(1)
{
if(s1==1){
lcdcommand(0x01);
delay(10000);
lcddisp("Red Alert Zone");
buz=1;
led=1;
delay(10000);
}
goto back;
}
}



void lcdinit(){
lcdcommand(0x38); 
lcdcommand(0x10);
lcdcommand(0x10);
lcdcommand(0x0c);
lcdcommand(0x80);
}



void lcdcommand(unsigned char val){
P2=val;
rs=0;
rw=0;
en=1;
delay(100);
en=0;
}



void lcddat(unsigned char dat){ 
P2=dat;
rs=1;
rw=0;
en=1;
delay(100);
en=0;
}



void lcddisp(unsigned char *s){
unsigned char j;
for(j=0;s[j]!='\0';j++){
lcddat(s[j]);
}
}



void delay(unsigned int n){
unsigned int i;
for(i=0;i<n;i++);
}