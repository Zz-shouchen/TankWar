代码说明：
暂无详细完整的注释。
需要一定的环境。
需要ncurses库。
改变文件后请重新make clean,make,或执行abuild.sh。
执行abuild.sh前请执行 chmod 777 abuild.sh

游戏说明：
游戏地图为30x80（可在gui.h中修改,5~6行）
坦克属性，子弹属性在ahealth_power.txt，在Game.h中修改。
游戏中有三种敌方坦克，分别为：普通坦克、超级坦克和激光坦克。
输入seed，当seed为0或1时map为提前准备好的地图，为其他数时map根据seed产生。
初始血量为300，显示百分数，

作弊键：
'u'：子弹数加1000
'i'：分数加1000
'o'：血量加1000000（+333334%）
'p'：血量减10（-3%）
'j'：发射激光

——by Zz-shouchen
