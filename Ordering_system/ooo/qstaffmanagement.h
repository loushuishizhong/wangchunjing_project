#ifndef QSTAFFMANAGEMENT_H
#define QSTAFFMANAGEMENT_H
#include "staff.h"
#include "DM1800.h"

class QStaffManagement
{
public:
    QStaffManagement();
    void initStaff();//----------用户初始化
    int deleteStaff(Staff staff);//---------删除用户信息
    int addStaff(Staff staff);//---------添加新员工
    int updateStaff(Staff staff);//---------修改员工信息
    int roleCheck(Staff staff);//---------权限检查
    int loginCheck(Staff staff);//---------用户登录验证
};

#endif // QSTAFFMANAGEMENT_H
