#ifndef VIA_H
#define VIA_H

//本文件中是一些全局变量的声明

#include <QSize>
#include <QString>

#include "customClass/read.h"
#include "customClass/paper.h"
#include "typestruct.h"
#include "macro.h"

extern QSize *screenSize;//设备的屏幕尺寸
extern QString picRoot;//根据设备的屏幕比例选择图片
extern QSize *keyBoardMaxSize;//软键盘打开时的尺寸
extern QSize *keyBoardMinSize;//软键盘关闭时的尺寸
extern QSize *keysAreaSize;//键盘中按键区域的尺寸

extern QSize *editBoxSize;//输入框的尺寸

extern inchpa eachPageWordsNum[STUDY_PAGE_NUM];//所有学习页面的名字和其对应的单词数量的数组

extern int pageWordsNum(char *pageName);//根据页面的名字，找出并返回该页面中单词的水数量，如果不存在，则返回0

extern QString audioPath;//音频文件的存储路径
extern QString audioSuffix;//音频文件的后缀名

extern Read *reader;//对所有的音频播放操作进行处理的对象
extern Paper *paper;//对所有的输入的字母进行显示的“纸”对象
extern QString *punctuation;//在输入的时候可能遇到的标点符号。

extern short sizeOfCharPtr(char *ptr);//返回所给字符指针所指向的字符数，不包括"\0"
extern short labelNumInStudyPage;//学习页面中的label的数量


extern short phrasePanelFontSize;//短语面板单词字号
extern short paperFontSize;//“纸”对象单词字号
extern short wordsCardFontSize;//单词板的单词字号
extern short sentenceLabelFontSize;//每个学习页面左上角的句子标签中的字号
extern short keyBorderFontSize;//软键盘中的字符字号

#endif // VIA_H
