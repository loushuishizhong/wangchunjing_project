#ifndef FOODDETAIL_H
#define FOODDETAIL_H
#include <QString>
#include <QIcon>
class FoodDetail
{
public:
    FoodDetail();
    FoodDetail(QString food_ID,QString food_name,QString food_category,QString food_price,QString food_icon_ID);

    void setFoodID(QString food_ID);
    QString getFoodID();

    void setFoodName(QString food_name);
    QString getFoodName();

    void setFoodCategory(QString food_category);
    QString getFoodCategory();

    void setFoodPrice(QString food_price);
    QString getFoodPrice();

    void setFoodIconID(QString food_icon_ID);
    QString getFoodIconID();

    void setFoodCount(QString food_count);
    QString getFoodCount();

private:
    QString m_food_name;
    QString m_food_ID;
    QString m_food_category;
    QString m_food_price;
    QString m_food_icon_ID;
    QString m_food_count;

};

#endif // FOODDETAIL_H
