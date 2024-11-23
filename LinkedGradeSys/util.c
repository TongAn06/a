#include <stdio.h>
//引入头文件
#include "util.h"
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

//全局变量 stu，用于存储学生信息
//struct Student stu;
//全局指针head头指针，用于指向链表第一个节点
Student *head=NULL;

//打印菜单
void menu() {
	printf("* * *欢迎使用学生成绩管理系统* * *\n");
	printf("*\t 1、学生成绩录入\t *\n");
	printf("*\t 2、学生成绩查询\t *\n");
	printf("*\t 3、学生成绩修改\t *\n");
	printf("*\t 4、学生成绩删除\t *\n");
	printf("*\t 5、学生成绩保存\t *\n");
	printf("*\t 6、学生成绩打印\t *\n");
	printf("*\t 0、退        出\t *\n");
	printf("* * * * * * * * ** * * * * * * * *\n");
	printf("请输入你的选择（0-6）：");
}

//录入系统
void input_score() {
//	printf("请输入学生的学号：");
//	scanf("%d",&stu.stuNum);
//	printf("请输入学生的姓名：");
//	scanf("%s",&stu.name);
//	printf("请输入学生的性别（男：M，女：F）：");
//	scanf("%s",&stu.sex);
//	printf("请输入学生的成绩：");
//	scanf("%f",&stu.score);
//	printf("录入学生成绩成功\n");
//声明一个指向student结构体的指针p，并将其初始化为链表的头节点
	Student *p=head;
//声明指针，用于记录遍历过程的前一个节点
	Student *prev=NULL;
//在内存中分配一块空间放置新节点
	Student *newNode=(Student *)malloc(sizeof(Student));
//录入学生信息
	printf("请输入学生的学号：");
	scanf("%d",&newNode->stuNum);
	printf("请输入学生的姓名：");
	scanf("%s",&newNode->name);
//清除缓冲区的换行符
	getchar();
	printf("请输入学生的性别（男：M，女：F）：");
	scanf("%s",&newNode->sex);
	printf("请输入学生的成绩：");
	scanf("%f",&newNode->score);
//初始化新节点的下一个指针为
	newNode->pNext=NULL;
//判断链表的第一个节点是否为空
	if(p==NULL) {
		printf("链表为空\n");
		//将新节点放入链表起始位置
		head =newNode;
	} else if(p!=NULL  && newNode->stuNum<p->stuNum) {

		//设置新节点的pnext为当前的头节点p
		newNode->pNext=p;
		//将新节点设置为新的头节点，从而将将它插入到链表的起始位置
		head=newNode;
	} else {
		while(p!=NULL  && newNode->stuNum>p->stuNum) {
			//更新prev为当前p，因为我们要在prev和p之间插入新节点
			prev=p;
			//移动到下一节点继续比较
			p=p->pNext;
		}
		prev->pNext=newNode;
		newNode->pNext=p;
	}
	printf("学生成绩录入成功\n");
	system("pause");
	system("cls");
}

//打印学生信息
void student_list() {
	printf("学号\t\t姓名\t性别\t成绩\n");
//	printf("%-16d%-8s%-8c%-8.2f\n",stu.stuNum,stu.name,stu.sex,stu.score);
	Student *p=head;
	while(p!=NULL) {
		printf("%-16d%-8s%-8c%-8.2f\n",p->stuNum,p->name,p->sex,p->score);
		p=p->pNext;
	}
	system("pause");
	system("cls");
}

void init_test_date() {
	//p用于遍历和更新链表
	Student *p=head;
	//创建第一个节点，分配内存空间给一个新的student结构体实例
	Student *newNode=(Student *)malloc(sizeof(Student));
	newNode->stuNum=11;
	strcpy(newNode->name,"东雪莲");
	newNode->sex='F';
	newNode->score=69;
	head=newNode;
	p=newNode;
	Student *newNode1=(Student *)malloc(sizeof(Student));
	newNode1->stuNum=12;
	strcpy(newNode1->name,"孙笑川");
	newNode1->sex='M';
	newNode1->score=258;
	p->pNext=newNode1;
	p=newNode1;
	Student *newNode2=(Student *)malloc(sizeof(Student));
	newNode2->stuNum=13;
	strcpy(newNode2->name,"侯国玉");
	newNode2->sex='M';
	newNode2->score=1;
	p->pNext=newNode2;
	p=newNode2;
	Student *newNode3=(Student *)malloc(sizeof(Student));
	newNode3->stuNum=14;
	strcpy(newNode3->name,"关瑞生");
	newNode3->sex='M';
	newNode3->score=2;
	p->pNext=newNode3;
	p=newNode3;
	Student *newNode4=(Student *)malloc(sizeof(Student));
	newNode4->stuNum=15;
	strcpy(newNode4->name,"肖欣瑶");
	newNode4->sex='F';
	newNode4->score=87;
	p->pNext=newNode4;
	p=newNode4;
	Student *newNode5=(Student *)malloc(sizeof(Student));
	newNode5->stuNum=16;
	strcpy(newNode5->name,"永雏塔菲");
	newNode5->sex='F';
	newNode5->score=69;
	p->pNext=newNode5;
	p=newNode5;
	Student *newNode6=(Student *)malloc(sizeof(Student));
	newNode6->stuNum=17;
	strcpy(newNode6->name,"2000W");
	newNode6->sex='M';
	newNode6->score=2000;
	p->pNext=newNode6;
	p=newNode6;
	Student *newNode7=(Student *)malloc(sizeof(Student));
	newNode7->stuNum=18;
	strcpy(newNode7->name,"打火机");
	newNode7->sex='M';
	newNode7->score=20;
	p->pNext=newNode7;
	p=newNode7;
	Student *newNode8=(Student *)malloc(sizeof(Student));
	newNode8->stuNum=19;
	strcpy(newNode8->name,"张京华");
	newNode8->sex='M';
	newNode8->score=0;
	p->pNext=newNode8;
	p=newNode8;
	p->pNext=NULL;
}

void search_score() {
	int num;
	printf("请输入要查询的学生学号：");
	scanf("%d",&num);
	Student *temp=head;
	while(temp!=NULL) {
		if(temp->stuNum==num) {
			break;
		}
		temp=temp->pNext;
	}
	if(temp==NULL) {
		printf("您要查询的学生不存在。");
	} else {
		printf("查询成功，查询结果如下：\n");
		printf("学号\t\t姓名\t性别\t成绩\n");
		printf("%-16d%-8s%-8c%-8.2f\n",temp->stuNum,temp->name,temp->sex,temp->score);
	}
	system("pause");
	system("cls");
}

void modify_score() {
	int num;
	printf("请输入要修改的学生学号：");
	scanf("%d",&num);
	Student *temp=head;
	while(temp!=NULL) {
		if(temp->stuNum==num) {
			break;
		}
		temp=temp->pNext;
	}
	if(temp==NULL) {
		printf("您要修改的学生不存在。");
	} else {
		printf("您要修改的学生信息如下，是否要修改记录？（y/n)\n");
		printf("学号\t\t姓名\t性别\t成绩\n");
		printf("%-16d%-8s%-8c%-8.2f\n",temp->stuNum,temp->name,temp->sex,temp->score);
		getchar();
		char choose=getchar();
		if (choose=='y'||choose=='Y') {
			printf("请输入新的成绩：\n");
			scanf("%f",&temp->score);
			printf("修改成功,");
		}
//		printf("请输入新的姓名：");
//		scanf("%s",&temp->name);
//		getchar();
//		printf("请输入新的性别（男：M，女：F）：");
//		scanf("%s",&temp->sex);
	}
	system("pause");
	system("cls");
}

void delete_score() {
	int num;

	Student *p=head;
	Student *prev=NULL;
	printf("请输入要删除的学生学号:");
	scanf("%d",&num);

	if (head==NULL) {
		printf("链表为空，删除失败\n");
		system("pause");
		return;
	}

	if (head->stuNum==num) {
		printf("找到学生信息如下：\n");
		printf("学号\t\t姓名\t性别\t成绩\n");
		printf("%-16d%-8s%-8c%-8.2f\n",p->stuNum,p->name,p->sex,p->score);
		printf("请确认是否删除（y/n）");
		getchar();
		char choose=getchar();
		if(choose=='y'||choose=='Y') {
			free(p);
			//将头指针重新指向头节点的下一个节点
			head=head->pNext;
			printf("删除学号%d的学生成功。\n",num);
		}
		system("pause");
		system("cls");
		return;
	}
	//遍历链表查找要删除的学生
	while(p!=NULL && p->stuNum!=num) {
		//记录当前节点作为前一个节点
		prev=p;
		//移动到下一个节点
		p=p->pNext;
	}
	if(p!=NULL) {
		printf("找到学生信息如下：\n");
		printf("学号\t\t姓名\t性别\t成绩\n");
		printf("%-16d%-8s%-8c%-8.2f\n",p->stuNum,p->name,p->sex,p->score);
		printf("请确认是否删除（y/n）");
		getchar();
		char choose=getchar();
		if(choose=='y'||choose=='Y') {
			//更新前一个节点的pnext指针，跳过要删除的节点
			prev->pNext=p->pNext;
			//释放要删除的节点的内存
			free(p);
			printf("删除学号%d的学生成功。\n",num);
		}
	} else {
		printf("您要删除的学生不存在");
	}
	system("pause");
	system("cls");
}

void save_file() {
	//w表示写入，如果文件不存在则创建一个文件
	FILE *fp=fopen("D:\\data.txt","w");
	if (fp==NULL) {
		printf("文件不存在或无法打开\n");
		return;
	}
	Student *p=head;
	// fwrite(数据指针，单个数据大小，数据个数，文件指针)
	while(p!=NULL) {
		fwrite(p,sizeof(Student),1,fp);
		p=p->pNext;
	}
	fclose(fp);
	printf("保存成功\n");
	system("pause");
	system("cls");

}

void load_file() {
	//r表示读取
	FILE *fp=fopen("D:\\data.txt","r");
	if (fp==NULL) {
		printf("文件不存在或无法打开\n");
		return;
	}
	Student stu;
	//p用于遍历和更新链表
	Student *p=head;
	//fread() 读取文件中的数据
	while(fread(&stu,sizeof(Student),1,fp)) {
		//动态分布内存创建新节点
		Student *newNode=(Student *)malloc(sizeof(Student));
		newNode->pNext=NULL;
		memcpy(newNode,&stu,sizeof(Student));
		//如果链表为空，设置新节点为头节点
		if(p==NULL) {
			head=newNode;
		} else {
			//如果链表非空，将新节点链接到链表末尾
			p->pNext=newNode;
		}
		p=newNode;
	}
	fclose(fp);
	printf("读取成功！\n");
}










