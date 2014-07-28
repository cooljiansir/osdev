#include "include/monitor.h"

static u16int cursor_x=0,cursor_y=0;
static char *video_memory = 0xb8000;

static void move_cursor()
{
	u16int loc = cursor_y * 80 + cursor_x;
	outb(0x3D4,14);
	outb(0x3D5,loc>>8);
	outb(0x3D4,15);
	outb(0x3D5,loc);
}

static void scroll_screen()
{
	int i;
	u8int attributeByte = (0<<4)|(15&0x0F);
	if(cursor_y==25){
		for(i = 0;i<24*80;i++)
		{
			video_memory[i*2] = video_memory[(i+80)*2];
			video_memory[i*2+1] = video_memory[(i+80)*2+1];
		}
		for(i = 24*80;i<25*80;i++)
		{
			video_memory[i*2] = ' ';
			video_memory[i*2+1] = attributeByte;
		}
		cursor_y = 24;
	}
}

void monitor_put(char c)
{
	u8int backColour = 0;
	u8int foreColour = 15;
	u8int attributeByte = (backColour<<4)|(foreColour & 0x0F);
	char *loc = (video_memory+2*80*cursor_y+2*cursor_x);
	
	if(c=='\b')
	{
		if(cursor_x>0)
			cursor_x--;
	}else if(c=='\r')
	{
		cursor_x = 0;
	}else if(c=='\n')
	{
		cursor_x = 0;
		cursor_y ++;
	}else if(c=='\t')
	{
		cursor_x = (cursor_x+8) & ~(7);
	}
	else{
		cursor_x ++;
	}
	if(c>=' '){
		loc[0] = c;
		loc[1] = attributeByte;
	}
	if(cursor_x>=80)
	{
		cursor_x = 0;
		cursor_y ++;
	}
	scroll_screen();
	move_cursor();
}

void monitor_write(char *str)
{
	int i = 0;
	while(str[i])
	{
		monitor_put(str[i++]);
	}
}

void monitor_clear()
{
	int i;
	u8int attributeByte = (0<<4)|(15 & 0x0F);
	for(i = 0;i<25*80;i++)
	{
		video_memory[i*2] = ' ';
		video_memory[i*2+1] = attributeByte;
	}
	cursor_x = cursor_y = 0;
}

static char *itoa(char *str,int a)
{
	char *strc = str;
	int len=0,i,j;
	char temp;
	if(a<0){
		(*str++) = '-';
		a*=-1;
		len++;
	}
	while(a){
		(*str++) = a%10+'0';
		a/=10;
		len++;
	}
	(*str) = '\0';
	i=0,j=len-1;
	for(;i<j;i++,j--){
		temp = strc[i];
		strc[i] = strc[j];
		strc[j] = temp;
	}
	return strc;
}

void printf(const char *str, ...)
{
	char **params = (char **)(&str);
	char ch;
	char buff[40];
	params++;
	while((ch=*str++)!=0)
	{	
		if(ch!='%')
			monitor_put(ch);
		else{
			ch=*str++;
			if(ch==0)
			{
				monitor_put('%');
				break;
			}
			if(ch=='%')
				monitor_put('%');
			else if(ch=='d')
			{
				monitor_write(itoa(buff,*((int *)params++)));
			}
			else if(ch=='s')
			{	
				monitor_write(*params++);
			}
		}
	}
}
