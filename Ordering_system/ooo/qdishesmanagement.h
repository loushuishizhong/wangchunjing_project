#ifndef QDISHESMANAGEMENT_H
#define QDISHESMANAGEMENT_H
#include "dishes.h"
#include "staff.h"
#include "DM1800.h"

class QDishesManagement
{
public:
    QDishesManagement();
    void initDishes();//---------��ʼ���˵��б���Ϣ

            int addDish(Dishes);//---------����²�Ʒ

            int delDish(Dishes);//---------ɾ����Ʒ

            int updateDish(Dishes);//---------���Ĳ�Ʒ��Ϣ


};

#endif // QDISHESMANAGEMENT_H
