//Electronic voting machine code 
// Shakir Ahmad Hurrah, Basit Mushatq, Mohsin Farooq.
// Roll No : CSE-16-66, CSE-16-122  , CSE-16-126.
//Semister : 6th (CSE).
//Section   : B.
//Subject : Embedded Systems.
//Submitted to : MR RAYEES AHMAD DAR.
// Date Of Submission : 21/07/2019.

#include<stdio.h>
#include<reg51.h>

sfr input=0x90;
sfr ldata=0xa0;
sbit rs=P0^7;
sbit rw=P0^6;
sbit en=P0^5;
sbit m=P3^0;
sbit n=P3^1;
sbit buzz=P3^2;
sbit on=P3^3;

void delay(int );
void lcdcmd(char ); void lcddata1(char *); void lcddata(char); //void lcd();
int a,i11,i12,i2,i21,i22,i3,i31,i32,i4,i41,i42=0;
void main() { on=0; P1=0;P3=0; 

while(1)
{ lcdcmd(0x38); delay(10); lcdcmd(0x0e) ; delay(10); lcdcmd(0x01); lcdcmd(0x06) ; delay(20) ;


if(n==1)
on=1; if(m==1&on==1) {
if (input==0x01) {

buzz=1;
while (input == 0x01); a=a + 1;
if(a>=10)
i11=a/10; i12=a%10;
on=0;
buzz=0;
//ready=0;
}
if (input==0x02) {buzz=1;
while (input == 0x02); {
i2=i2 + 1;
if(i2>=10)
i21=i2/10; i22=i2%10;
on=0;

buzz=0;
}
}
if (input==0x04) {
buzz=1;
while (input ==0x04); {
i3=i3 + 1;
if(i3>=10)
i31=i3/10; i32=i3%10;
on=0;
buzz=0;
}
}
if (input==0x08)
{
buzz=1;

while (input == 0x08); {
i4=i4 + 1;
if(i4>=10)
i41=i4/10; i42=i4%10; on=0; buzz=0;
}
}
if (input==0x10)
{
buzz=1;
while (input == 0x10); {
i5=i5 + 1;
if(i5>=10)
i51=i5/10; i52=i5%10;

i5=0; on=0; buzz=0; }
}
}}
if(m==0)//else {
if (input==0x01)
{
lcddata1(" Peoples Democratic Party="); lcddata(i11+0x30); lcddata(i12+0x30); delay(100);   
}
if (input==0x02)
{
lcdcmd(0x01); lcddata1(" National confrence=");

lcddata(i21+0x30); lcddata(i22+0x30); delay(100);
}
if (input==0x04)
{
lcdcmd(0x01); lcddata1(" Indian National Congress="); lcddata(i31+0x30); lcddata(i32+0x30); delay(100);
}
if (input==0x08)
{
lcdcmd(0x01); lcddata1(" shah Faisal"); lcddata(i41+0x30); lcddata(i42+0x30); delay(100);

}
else{
lcdcmd(0x01);
lcddata1("press key "); delay(100) ;
}
void delay(int time)
{
int i,j;
for(i=0;i<time;i++) for(j=0;j<900;j++);
}
void lcdcmd(char value)
{
ldata=value;
rs=0;
rw=0;
en=1;
delay(2);
en=0;
}
void lcddata1(char *value) { int i; for(i=0;value[i]!='\0';i++)

{
ldata=value[i];
rs=1;
rw=0;
en=1;
delay(1);
en=0;
}
}
void lcddata(char value) {
ldata=value;
rs=1;
rw=0;
en=1;
delay(1);
en=0;
}