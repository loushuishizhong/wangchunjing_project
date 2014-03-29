#ifndef DISHES_H
#define DISHES_H
#include<QString>
class Dishes
{
public:
    Dishes();
    QString dish_number;        //菜品编号
    QString dish_name;          //菜品名称
    QString dish_short_name;    //菜品简称(拼音)
    QString dish_category;      //菜品分类
    QString dish_price;         //菜品价格
    QString dish_icon_filepath;//图片路径

};

#endif // DISHES_H
