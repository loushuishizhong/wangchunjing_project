#include "fooddetail.h"

FoodDetail::FoodDetail()
{}

FoodDetail::FoodDetail(QString food_ID, QString food_name, QString food_category, QString food_price, QString food_icon_ID)
    :m_food_ID(food_ID),
    m_food_name(food_name),
    m_food_category(food_category),
    m_food_price(food_price),
    m_food_icon_ID(food_icon_ID)
{}


QString FoodDetail::getFoodCategory()
{
    return m_food_category;

}
void FoodDetail::setFoodCategory(QString food_category)
{
    m_food_category  = food_category;

}


QString FoodDetail::getFoodID()
{
    return m_food_ID;

}
void FoodDetail::setFoodID(QString food_ID)
{
    m_food_ID = food_ID;
}



QString FoodDetail::getFoodName()
{
    return m_food_name;

}
void FoodDetail::setFoodName(QString food_name)
{
    m_food_name = food_name;
}


QString FoodDetail::getFoodPrice()
{
    return m_food_price;

}
void FoodDetail::setFoodPrice(QString food_price)
{
    m_food_price = food_price;
}


QString FoodDetail::getFoodIconID()
{
    return m_food_icon_ID;

}
void FoodDetail::setFoodIconID(QString food_icon_ID)
{
    m_food_icon_ID = food_icon_ID;
}


QString FoodDetail::getFoodCount()
{
    return m_food_count;

}
void FoodDetail::setFoodCount(QString food_count)
{
    m_food_count = food_count;
}





