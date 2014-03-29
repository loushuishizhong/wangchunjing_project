#ifndef QDISHESMANAGEMENT_H
#define QDISHESMANAGEMENT_H
#include "dishes.h"
#include "staff.h"
#include "DM1800.h"

class QDishesManagement
{
public:
    QDishesManagement();
    void initDishes();//---------初始化菜单列表信息

            int addDish(Dishes);//---------添加新菜品

            int delDish(Dishes);//---------删除菜品

            int updateDish(Dishes);//---------更改菜品信息


};

#endif // QDISHESMANAGEMENT_H
