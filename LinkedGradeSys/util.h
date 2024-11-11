#ifndef UTIL_H
#define UTIL_H

void menu();

//定义结构体，用于存放学生的信息
struct Student{
	//学号
	int stuNum;
	//姓名
	char name[10];
	//性别
	char sex;
	//成绩
	float score;
};

//录入成绩
void input_score();

//打印学生成绩
void student_list();

#endif