///////////////////////////
//作者：小臧同学
//文件名：猜歌.cpp
///////////////////////////
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")//音乐播放头文件

#include<cstring>
#include<iostream>
#include<stdio.h>//输入输出头文件

#include <graphics.h> //加载图像库

#include<time.h>
#include <stdlib.h>//随机数生成相关头文件

using namespace std; //所有的标准库函数都在标准命名空间std中进行了定义

#define graph_w 900
#define graph_h 750 //设置画板宽度高度 18:15
#define sum 5// 题目数

void init(); // 初始化
void Put__Music( int number ); // 播放音乐
void Put__ans( int number );//打印答案
void Close__Music();//关闭音乐
void Stop__Music();//暂停音乐
void Resume__Music();//继续音乐
int get_random_number(int l,int r); // 生成随机数
void prepare();
/////////////////////////////////////////////////声明需要使用的自定义函数

int cnt;//题目数
bool vis[100];//代表歌曲是否听过
int main( ) {  //主函数
	init(); //初始化
	prepare();//检测是否开始
	///////////////////////////////////////////////////////////////// 120 370 600 690  500 750 600 690
	while(cnt--)
	{		
	IMAGE setting_img;
	loadimage(&setting_img,_T("Img//游戏背景.png"),graph_w,graph_h);//加载背景
	putimage(0,0,&setting_img);//封面背景
/////////////////////////////////////////////////////////////////////////更换背景
	int Ran_Num=get_random_number(0,sum-1);
	Put__Music(Ran_Num);
	//Sleep(3000);
	MOUSEMSG mouse;
	int F=1;
		while(F){
		mouse=GetMouseMsg();
		switch(mouse.uMsg){
		case WM_LBUTTONDOWN:
			if(mouse.x > 120 && mouse.x < 370 && mouse.y > 600 && mouse.y <690) if(F==1) Stop__Music(),F=2; else Resume__Music(),F=1 ; 

			if(mouse.x > 500 && mouse.x < 750 && mouse.y > 600 && mouse.y <690) F=0,Put__ans(Ran_Num);
		}
		Sleep(10);
	 }
	///////////////////////////////////////////////////////////////
	Close__Music();
	}
	return 0;
}
void Put__Music( int number ){
	switch(number){
		case 0: mciSendString(TEXT("open Music\\追光者.mp3 alias Music"), NULL, NULL, NULL);break;//打开音乐文件
		case 1: mciSendString(TEXT("open Music\\起风了周深.mp3 alias Music"), NULL, NULL, NULL);break;//打开音乐文件
		case 2: mciSendString(TEXT("open Music\\孤勇者.mp3 alias Music"), NULL, NULL, NULL);break;//打开音乐文件
		case 3: mciSendString(TEXT("open Music\\一路生花.mp3 alias Music"), NULL, NULL, NULL);break;//打开音乐文件
		case 4: mciSendString(TEXT("open Music\\大鱼.mp3 alias Music"), NULL, NULL, NULL);break;//打开音乐文件
	}
	mciSendString(TEXT("play Music"), NULL, NULL, NULL);//播放音乐
}

void Put__ans( int number ) //输出答案
{
	settextstyle(150,60,_T("宋体")); // 字体设置
	settextcolor(BLUE);
	switch(number){
		case 0: outtextxy(200,350,_T("追光者" )); break;
		case 1: outtextxy(200,350,_T("起风了" )); break;
		case 2: outtextxy(200,350,_T("孤勇者" )); break;
		case 3: outtextxy(200,350,_T("一路生花" )); break;
		case 4: outtextxy(200,350,_T("大鱼" )); break;
	}
	MOUSEMSG mouse;
	int F=1;
	while(F){
		mouse=GetMouseMsg();
		switch(mouse.uMsg){
			case WM_LBUTTONDOWN:
				F=0;
			}
			Sleep(10);
		}
}

void Close__Music()
{mciSendString(TEXT("close Music"), NULL, NULL, NULL);}//关闭文件

void Stop__Music()//暂停音乐
{mciSendString(TEXT("stop Music"), NULL, NULL, NULL);}

void Resume__Music()//继续音乐
{mciSendString(TEXT("resume Music"), NULL, NULL, NULL);}

int get_random_number(int l,int r)//生成l到r随机数
{int number=rand()%(r+1)+l; if(vis[number]!=1){vis[number]=1;  return number;} for(int i=0;i<=4;i++)if(vis[i]!=1){vis[i]=1; return i;}}

void init()
{
	memset(vis,0x3f,sizeof(vis));//初始化vis数组
	srand((unsigned int)time(0));//初始化种子为随机值
	cnt = 5; //设置游戏局数

	initgraph(graph_w,graph_h,NOMINIMIZE);//绘制初始画板

	setcolor(WHITE);//设置背景色

	IMAGE setting_img;
	loadimage(&setting_img,_T("Img//开始界面.png"),graph_w,graph_h);//加载背景
	putimage(0,0,&setting_img);//封面背景
	////////////////////////////////////////////////////////////////////绘制背景
}

void prepare()
{
	MOUSEMSG mouse;
	int F=1;
		while(F){
		mouse=GetMouseMsg();
		switch(mouse.uMsg){
		case WM_LBUTTONDOWN:
			if(mouse.x > 310 && mouse.x < 590 && mouse.y > 530 && mouse.y <640) F=0;
		}
		Sleep(10);
	 }
	 ////////////////////////////////////////////////////////////////////检测是否开始

}
