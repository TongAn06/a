#include <stdio.h>
//引入头文件
#include "util.h"
//全局变量 stu，用于存储学生信息
struct Student stu;

//打印菜单
void menu(){
	printf("* * *欢迎使用学生成绩管理系统* * *\n");
	printf("*\t 1、学生成绩录入\t *\n");
	printf("*\t 2、学生成绩查询\t *\n");
	printf("*\t 3、学生成绩修改\t *\n");
	printf("*\t 4、学生成绩删除\t *\n");
	printf("*\t 5、学生成绩保存\t *\n");
	printf("*\t 6、学生成绩打印\t *\n");
	printf("*\t 0、退        出\t *\n");
	printf("* * * * * * * * ** * * * * * * * *\n");
	printf("请输入你的选择（0-5）：");
}

//录入系统
void input_score(){
	printf("请输入学生的学号：");
	scanf("%d",&stu.stuNum);
	printf("请输入学生的姓名：");
	scanf("%s",&stu.name);
	printf("请输入学生的性别（男：M，女：F）：");
	scanf("%s",&stu.sex);
	printf("请输入学生的成绩：");
	scanf("%f",&stu.score);
	printf("录入学生成绩成功\n");
}

//打印学生信息
void student_list(){
	printf("学号\t\t姓名\t性别\t成绩\n");
	printf("%-16d%-8s%-8c%-8.2f\n",stu.stuNum,stu.name,stu.sex,stu.score);
}