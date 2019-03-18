#ifndef TYPESTRUCT
#define TYPESTRUCT

//该头文件中进行结构体等的声明

typedef unsigned short keytype_;

typedef struct CharPointerTri
{//每个页面中的单词、单词的中文解释、短语以及短语的中文解释的数据结构
    char *words;//单词
    char *wChi;//单词的中文解释
    char *phrase_1;//短语
    char *pChi_1;//短语的中文解释
    char *pic1;//第一张图片
    char *pic1Border;//第二张图片
    char *pic2;//第三张图片
    char *pic2Border;//第四张图片，同一个物品，最多只有四张图片
    char *phrasePic1;//短语图片第一张
    char *phrasePic2;//短语图片第二张，同一个物品，最多只有两张图片
    char *phrase_2;//第二条短语
    char *pChi_2;//第二条短语的中文解释
    short ax;//第一张图片显示的位置横坐标
    short ay;//第一张图片显示的位置的纵坐标
    short aw;//第一张图片显示的宽
    short ah;//第一张图片的高
}chpotr;
typedef struct IntCharPair
{//存储所有学习页面的名字和其对应的页面的单词数量的数据结构
    char *key;//页面名字
    int value;//单词数量
}inchpa;
typedef struct PtrPair
{
    void *ptr1;
    void *ptr2;
}ptrPair;

#endif // TYPESTRUCT

