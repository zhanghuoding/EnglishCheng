#ifndef MACRO
#define MACRO

//该头文件用来声明所有的宏定义

//#define _PICROOT4_3_ /image4.3/image/screenRate4.3     //4:3屏幕比例对应的图片根目录
//#define _PICROOT16_9_ /image16.9/image/screenRate16.9  //16:9屏幕比例对应的图片根目录

#define KEY_FONT_COLOR ("#000000")//软键盘中的按键的字体的颜色
#define KEY_BACKCOL_NORMAL ("#ffffff")//软件盘中的按键在正常情况下的颜色
#define KEY_BACKCOL_ENTER ("#acdcf7")//软键盘中的按键在鼠标进入但没有按下时的颜色
#define KEY_BACKCOL_PRESSED ("#33cef5")//软件盘中的按键在鼠标按下时的颜色
#define KEY_BACKCOL_NORMAL_AFTCLI ("#ff0000")//软件盘中的按键在经历一次点击以后的改变的颜色，正常情况下就是这个颜色
#define KEY_BACKCOL_ENTER_AFTCLI ("#ff0072")//软键盘中的按键在经历一次点击以后，鼠标再次进入该按键，但是没有按下时的颜色
#define KEY_BACKCOL_PRESSED_AFTCLI ("#fc00ff")//软键盘中的按键在经历一次点击以后，鼠标再次按下时的颜色
#define KEY_BACKCOL_NORMAL_REMIND ("#f8fb16")//软件盘中的按键在进行输入提示时的颜色，正常情况下就是这个颜色
#define KEY_BACKCOL_ENTER_REMIND ("#f8fb0d")//软键盘中的按键在进行输入提示时，鼠标再次进入该按键，但是没有按下时的颜色
#define KEY_BACKCOL_PRESSED_REMIND ("#f7fa05")//软键盘中的按键在进行输入提示时，鼠标再次按下时的颜色

#define BUTTON_FONT_COLOR ("#000000")//整个软件中的按钮中的文本的颜色，即前景色
#define BUTTON_BACKCOL_NORMAL ("#f4f4f4")//整个软件中的所有按钮在正常情况下的背景颜色
#define BUTTON_BACKCOL_ENTER ("#edecec")//整个软件中的按钮在鼠标进入，但是没有按下时的背景色
#define BUTTON_BACKCOL_PRESSED ("#dddcdc")//整个软件中的按钮在鼠标按下时的背景色

#define STUDY_PAGE_NUM (25)//整个软件中的页学习页面的计数器

#endif // MACRO

