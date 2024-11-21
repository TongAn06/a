#ifndef UTIL_H
#define UTIL_H

void menu();

void init_test_date();

//定义结构体类型，用于存放学生的信息
typedef struct Student{
	//学号
	int stuNum;
	//姓名
	char name[10];
	//性别
	char sex;
	//成绩
	float score;
	//pnext指向下一个student类型的结构体,可以链接多个student结构体，形成一个链式存储结构
	struct Student *pNext;
}Student;

//录入成绩
void input_score();

//打印学生成绩
void student_list();

//查询
void search_score();

//修改
void modify_score();

//删除
void delete_score();

//保存
void save_file();
#endif