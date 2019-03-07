#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include <dos.h>
#include <dir.h>
union REGS i,o;
int button,p,q;
main()
{
int gd = DETECT,gm;
int maxx,maxy,x,y,button,i,j,x2,x1,y2,y1;
int cor[60][2],f=1,hour,min,sec,l,dat,mont,yea;
struct arccoordstype arcinfo;
struct  time t;
struct date d;
char mm[80],mf[80],m[50],n[5];
char
mon[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
initmouse();
showmouseptr();
initgraph(&gd,&gm,"c:\\tc\\bgi");
maxx=getmaxx();
maxy=getmaxy();
//textcolor(0);
setviewport(1,1,getmaxx()-2,getmaxy()-2,1);
showmouseptr();
restrictmouseptr(350,20,600,70);
circle(maxx/2,maxy/2,100);
putpixel(maxx/2,maxy/2,3);
setfillstyle(0,0);
j=90;
setcolor(0);
cleardevice();
setfillstyle(1,14);
bar(390,55,440,70);
setfillstyle(1,14);
bar(460,55,500,70);
setfillstyle(1,14);
bar(390,30,460,45);
setfillstyle(1,14);
bar(466,30,540,45);
j=30;
setfillstyle(1,12);
bar(180,100,465,387);
setfillstyle(1,0);
bar(185,104,460,383);
while(f<13)
{
if (i<=90) {i=90-j;} else { i=360-(j-90);}
setcolor(0);
arc(maxx/2,maxy/2,90,i,125);
getarccoords(&arcinfo);
setcolor(14);
settextstyle(DEFAULT_FONT, HORIZ_DIR,2);
if (f<=5) {sprintf(n,"%d",f);outtextxy(arcinfo.xend+2,arcinfo.yend,n);}
else if ((f>=7)&&(f<12))
{sprintf(n,"%d",f);outtextxy(arcinfo.xend-7,arcinfo.yend,n);}
else if
(f==12){sprintf(n,"%d",f);outtextxy(arcinfo.xstart-10,arcinfo.ystart,n);}
else if (f==6) {sprintf(n,"%d",f);outtextxy(arcinfo.x-17,arcinfo.y+120,n);}
j+=30;
f++;
}
setcolor(13);
sprintf(mm,"Exit");
outtextxy(550,35,mm);
settextstyle(DEFAULT_FONT,0,1);
sprintf(mm,"Program by:");
outtextxy(400,435,mm);
settextstyle(TRIPLEX_FONT, HORIZ_DIR,2);
sprintf(mm,"VRUSHANK PATEL");
outtextxy(410,445,mm);

settextstyle(DEFAULT_FONT, HORIZ_DIR,0);
outtextxy(400,60,"Time    Date");

sprintf(mm,"SET-TIME");
outtextxy(395,35,mm);
sprintf(mm,"SET-DATE");
outtextxy(470,35,mm);
f=0;
while(1)
{
getmousepos(&button,&p,&q);
getdate(&d);
gettime(&t);
//outer
setfillstyle(1,15);
pieslice(maxx/2,maxy/2,0,360,5);
setfillstyle(1,12);
bar(180,100,184,387);
bar(461,100,465,387);
bar(180,100,465,105);
bar(180,385,465,387);
bar(200,390,445,400);
bar(180,400,465,405);
//hour
if (t.ti_hour>13) {t.ti_hour = t.ti_hour - 12;}
if (t.ti_min==0) {i=(t.ti_hour*30);}  else
{i=((t.ti_hour*30)+((t.ti_min/12)*6));}
if (i>=90) {j=360-(i-90);}
else {j=90-i;}
textcolor(0);
setcolor(0);
arc(maxx/2,maxy/2,j,90,50);
getarccoords(&arcinfo);
if (((t.ti_hour==0)||(t.ti_hour==12))&&(t.ti_min<=11))
{
setcolor(0);
line(maxx/2,maxy/2,x1,y1);
setcolor(3);
line(maxx/2,maxy/2,maxx/2,maxy/2-50);
x1=0;y1=0;
x1=maxx/2;
y1=maxy/2-50;
}
else
{
setcolor(0);
line(maxx/2,maxy/2,x1,y1);
setcolor(3);
line(maxx/2,maxy/2,arcinfo.xstart,arcinfo.ystart);
x1=arcinfo.xstart;
y1=arcinfo.ystart;
}
//hour
//minutr
i=(t.ti_min*6);
if (i>=90) {j=360-(i-90);}
else {j=90-i;}
textcolor(0);
setcolor(0);
arc(maxx/2,maxy/2,j,90,90);
getarccoords(&arcinfo);
if (t.ti_min==0)
{
setcolor(0);
line(maxx/2,maxy/2,x2,y2);
setcolor(2);
line(maxx/2,maxy/2,maxx/2,maxy/2-80);
x2=0;y2=0;
x2=maxx/2;
y2=maxy/2-80;
}
else
{
setcolor(0);
line(maxx/2,maxy/2,x2,y2);
setcolor(2);
line(maxx/2,maxy/2,arcinfo.xstart,arcinfo.ystart);
x2=arcinfo.xstart;
y2=arcinfo.ystart;
}
//minute
//seconds
i=(t.ti_sec*6);
if (i>=90) {j=360-(i-90);}
else {j=90-i;}
textcolor(0);
setcolor(0);
arc(maxx/2,maxy/2,j,90,100);
getarccoords(&arcinfo);
setcolor(5);
rectangle(185,104,460,383);
setcolor(15);
//setcolor(4);
if (t.ti_sec==0)
{
setcolor(0);
line(maxx/2,maxy/2,x,y);
setcolor(15);
//setcolor(4);
line(maxx/2,maxy/2,maxx/2,maxy/2-100);
x=0;y=0;
x=maxx/2;
y=maxy/2-100;
}
else
{
setcolor(0);
line(maxx/2,maxy/2,x,y);
setcolor(15);
//setcolor(4);
line(maxx/2,maxy/2,arcinfo.xstart,arcinfo.ystart);
x=arcinfo.xstart;
y=arcinfo.ystart;
}
press();
getmousepos(&button,&p,&q);
if ((p>=390)&&(p<=440)&&(q>=55)&&(q<=70)&&((button & 1)==1))
{
f=f^1;
if (f==1)
{
l=3;
}
else
{
l=0;
gotoxy(38,20);
printf("                ");
}
}

if (l==3)
{
gotoxy(38,20);
printf("%d:%d:%d",t.ti_hour,t.ti_min,t.ti_sec);
}


press();
getmousepos(&button,&p,&q);
if ((p>=460)&&(p<=500)&&(q>=55)&&(q<=70)&&((button & 1)==1))
{
f=f^1;
if (f==1)
{
l=5;
}
else
{
l=0;
gotoxy(36,12);
printf("                ");
}
}

if (l==5)
{
gotoxy(36,12);
printf("%d,%s %d ",d.da_day,mon[d.da_mon-1],d.da_year);
}


if (t.ti_min==0)
{
sound(2000);
}
if (t.ti_sec>=2)
{nosound();}
press();
getmousepos(&button,&p,&q);
if ((p>=550)&&(p<=650)&&(q>=33)&&(q<=50)&&((button & 1)==1)) {goto 
end;}
//set time
if ((p>=390)&&(p<=460)&&(q>=30)&&(q<=45)&&((button & 1)==1))
{
gotoxy(1,22);
printf("Enter :");
gotoxy(1,23);
printf("Hour[24]:");scanf("%d",&hour);
gotoxy(1,24);
printf("Minute  :");scanf("%d",&min);
gotoxy(1,25);
printf("Second  :");scanf("%d",&sec);
if (hour!=24)
{t.ti_hour = hour;} else {t.ti_hour = 0;}
t.ti_min =  min;
t.ti_sec = sec;
settime(&t);
gotoxy(1,22);
printf("          ");
gotoxy(1,23);
printf("                         ");
gotoxy(1,24);
printf("                          ");
gotoxy(1,25);
printf("                         ");
}
//set date
if ((p>=350)&&(p<=510)&&(q>=35)&&(q<=45)&&((button & 1)==1))
{
gotoxy(1,22);
printf("Enter :");
gotoxy(1,23);
printf("date   :");scanf("%d",&dat);
gotoxy(1,24);
printf("Month  :");scanf("%d",&mont);
gotoxy(1,25);
printf("Year   :");scanf("%d",&yea);
d.da_day=dat;
d.da_mon=mont;
d.da_year=yea;
setdate(&d);
gotoxy(1,22);
printf("          ");
gotoxy(1,23);
printf("                         ");
gotoxy(1,24);
printf("                          ");
gotoxy(1,25);
printf("                         ");
}
//while end
}
end:
closegraph();
restorecrtmode();
//program end
return 0;
}



initmouse()
{
i.x.ax = 0;
int86(0x33,&i,&o);
return (o.x.ax);
}

showmouseptr()
{
i.x.ax = 1;
int86(0x33,&i,&o);
return 0;
}
hidemouseptr()
{
i.x.ax = 2;
int86(0x33,&i,&o);
return 0;
}

restrictmouseptr(int x1,int y1,int x2,int y2)
{
i.x.ax = 7;
i.x.cx = x1;
i.x.dx = x2;
int86 (0x33,&i,&o);
i.x.ax = 8;
i.x.cx = y1;
i.x.dx = y2;
int86 (0x33,&i,&o);
return 0;
}

getmousepos(int *button,int *x,int *y)
{
i.x.ax = 3;
int86 (0x33,&i,&o);
*button = o.x.bx;
*x=o.x.cx;
*y=o.x.dx;
return 0;
}

press()
{
while ((button & 1)==1)
{
getmousepos(&button,&p,&q);}
return 0;
}       
