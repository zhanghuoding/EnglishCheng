#ifndef TOOL_H
#define TOOL_H

#include <QSize>
#include <QString>
#include <QRect>

#include "via.h"


class Tool
{
public:
    Tool();
    static char * const prompter;//提示信息对话框的标题
    static char *const barrNotOpen;//关卡暂时未开启的提示
    static char *const functionNotDeveloped;//该功能尚未开发出来的提示
    static void *creatClassByStringWithSingleton(QString className=QString(""));//本函数根据传入的类名，创建单例模式的类
    static void initNullArray(void* pointer,int size);//将数组成员全部初始化为空
    static QSize size(int width,int height);//计算并返回一个与计算机屏幕成一定比例的尺寸
    static QRect rect(int ax=0, int ay=0, int aw=0, int ah=0);//返回一个与16:9屏幕成比例的图形的位置和尺寸
    static int width(int width);//根据计算机屏幕的水平宽度，返回一个成比例的整型值
    static int height(int height);//根据计算机屏幕的竖直高度，返回一个成比例的整型值
    static char *styleSheetNormalAndPressed(int leftUponRadius = -1, int rightUponRadius = -1, int leftBottomRadius = -1, int rightBottomRadius = -1,
                                            char *rgb1=BUTTON_BACKCOL_NORMAL,char *rgb2=BUTTON_BACKCOL_ENTER,
                                            char *rgb3=BUTTON_BACKCOL_PRESSED,char *rgb=BUTTON_FONT_COLOR,int fontSi=24);//设置按钮各角的样式以及按钮三态的颜色
    static char *styleSheetPressed(int leftUponRadius = -1, int rightUponRadius = -1, int leftBottomRadius = -1, int rightBottomRadius = -1,
                                            char *rgb2=BUTTON_BACKCOL_ENTER,char *rgb3=BUTTON_BACKCOL_PRESSED,
                                            char *rgb=BUTTON_FONT_COLOR,int fontSi=30);//设置按钮各角的样式以及按钮三态的颜色
    static char *rateWidthToChar(int x);//将传入的x按屏幕的宽比例换算后，转换成字符串返回
    static char *rateHeightToChar(int y);//将传入的y按屏幕的高比例换算后，转换成字符串返回
    static void showDialog(char *text = Tool::functionNotDeveloped,char *title = Tool::prompter);//弹出对话框显示提示信息
    static int fontSize(int size);//按照屏幕的宽来按比例计算字体的大小
};

#endif // TOOL_H
