#ifndef QSTAFFMANAGEMENT_H
#define QSTAFFMANAGEMENT_H
#include "staff.h"
#include "DM1800.h"

class QStaffManagement
{
public:
    QStaffManagement();
    void initStaff();//----------�û���ʼ��
    int deleteStaff(Staff staff);//---------ɾ���û���Ϣ
    int addStaff(Staff staff);//---------�����Ա��
    int updateStaff(Staff staff);//---------�޸�Ա����Ϣ
    int roleCheck(Staff staff);//---------Ȩ�޼��
    int loginCheck(Staff staff);//---------�û���¼��֤
};

#endif // QSTAFFMANAGEMENT_H
