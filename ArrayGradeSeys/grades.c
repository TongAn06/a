#include <stdio.h>
#include <stdlib.h>
#define MaxNum 100
//int stu[3][2];
int actnum=6;
int stu[MaxNum][2]= {{1,8},{2,20},{3,99},{4,77},{5,89},{6,90}};
void print_score();
void input_score();
void search_score();
void modify_score();
void remove_score();
void save_score();
void load_score();
void bubble_sort_by_score();
void insertion_sort_by_score();

int main(int argc, char** argv) {
	while(1) {
		int choose=-1;
		printf("1、准备成绩录入\n");
		printf("2、学生成绩修改\n");
		printf("3、学生成绩删除\n");
		printf("4、学生成绩查询\n");
		printf("5、学生成绩打印\n");
		printf("6、学生成绩保存\n");
		printf("7、学生成绩读取\n");
		printf("8、按成绩升序（冒泡排序）\n");
		printf("9、按成绩升序（插入排序）\n");
		printf("0、退        出\n");
		printf("请输入你的选择(0~5):");
		scanf("%d",&choose);
		printf("你的选择是：%d\n",choose);
		switch(choose) {
			case 1:
				printf("正在使用：学生成绩录入\n");
				input_score();
				break;
			case 2:
				printf("正在使用：学生成绩修改\n");
				modify_score();
				break;
			case 3:
				printf("正在使用：学生成绩删除\n");
				remove_score();
				break;
			case 4:
				printf("正在使用：学生成绩查询\n");
				search_score();
				break;
			case 5:
				printf("正在使用：学生成绩打印\n");
				print_score();
				break;
			case 6:
				printf("正在使用：学生成绩保存\n");
				save_score();
				break;
			case 7:
				printf("正在使用：学生成绩读取\n");
				load_score();
				break;
			case 8:
				printf("正在使用：成绩排序（冒泡排序）");
				bubble_sort_by_score();
				break;
			case 9:
				printf("正在使用：成绩排序（插入排序）");
				insertion_sort_by_score();
				break;
			case 0:
				printf("谢谢使用：再见\n");
				return 0;
			default:
				printf("对不起，没有这个菜单选项\n");
				break;
		}
	}
	return 0;
}
void print_score() {
	printf("成绩打印中......\n");
	printf("学号\t-\t成绩\n");
	for(int i=0; i<actnum; i++) {
		printf("%d\t-\t%d\n",stu[i][0],stu[i][1]);

	}
}
void input_score() {

//	printf("请输入第1个学生的学号:");
//	scanf("%d",&stu[0][0]);
//	printf("请输入第1个学生的成绩:");
//	scanf("%d",&stu[0][1]);
//	printf("请输入第2个学生的学号:");
//	scanf("%d",&stu[1][0]);
//	printf("请输入第2个学生的成绩:");
//	scanf("%d",&stu[1][1]);
//	printf("请输入第3个学生的学号:");
//	scanf("%d",&stu[2][0]);
//	printf("请输入第3个学生的成绩:");
//	scanf("%d",&stu[2][1]);
	for(int i=actnum; i<MaxNum; i++) {
		printf("请输入第%d个学生的学号:",i+1);
		scanf("%d",&stu[i][0]);
		printf("请输入第%d个学生的成绩:",i+1);
		scanf("%d",&stu[i][1]);
		actnum++;

		getchar();
		printf("是否继续[y/n]\n");
		char flag=getchar();
		if(flag=='n'||flag=='N') {
			break;
		}
	}
	for(int i=0; i<actnum; i++) {
		printf("第%d个学生的成绩-学号%d-%d\n",i+1,stu[i][0],stu[i][1]);
	}
}
//学生成绩查询
void search_score() {
	printf("准备成绩查询......\n");
	//定义学号变量
	int number;
	printf("请输入要查询的学生学号:");
	//获取用户在键盘上输入的学号
	scanf("%d",&number);
	//定义数组下标，并赋值为0
	int i=0;
	//循环判断当前下标所指的学生学号，是否与所要查询的学生学号相等
	while(stu[i][0] !=number  && i<actnum) {//不相等，则继续循环，下标自增一个
		i++;
	}
	if(stu[i][0]==number) {
		printf("学号为%d的成绩是%d\n",stu[i][0],stu[i][1]);
	}

	else {
		printf("学号为%d的未找到",number);
	}
}
void modify_score() {
	printf("准备成绩修改......\n");
	//定义学号变量
	int num;
	printf("请输入要修改的学生学号：");
	//获取用户在键盘上输入的学号
	scanf("%d",&num);
	//定义数组下标，并赋值为0
	int i=0;
	//循环判断当前下标所指的学生学号，是否与所要修改的学生学号相等
	for(i=0; i<actnum; i++) {
		// 判断当前下标的学号是否与查询学号一致
		if(stu[i][0]==num) {
			// 打印学号和成绩
			printf("学号为%d的学生成绩是%d\n",stu[i][0],stu[i][1]);
			// 提示用户输入新的成绩
			printf("请输入学号为%d的的新成绩：",stu[i][0]);
			// 将成绩赋值给对应下标的数组
			scanf("%d",&stu[i][1]);
			return;
		}
	}
	// 不一致，说明没找到，打印提示信息
	//if(i==6) {printf("学号为%d的学生没找到！\n",num);}
	printf("学号为%d的学生没找到！\n",num);
}
void remove_score() {
	printf("准备成绩删除......\n");
	int num;
	printf("请输入需要删除的学号：");
	scanf("%d",&num);
	int i=0;
	while(stu[i][0]!=num  &&i<actnum) {
		i++;
	}
	if(stu[i][0]==num) {
		printf("学号为%d的学生的成绩是%d\n",stu[i][0],stu[i][1]);
		for(; i<actnum; i++) {
			stu[i][0]=stu[i+1][0];
			stu[i][1]=stu[i+1][1];
		}
		printf("删除成功\n");
		actnum--;
	} else {
		printf("学号为%d的学生未找到\n",num);
	}
}
void save_score() {
	printf("准备保存数据到文件......\n");
	FILE *fp;
	fp=fopen("d:\\score.txt","a+");
	if(fp==NULL) {
		printf("文件打开失败");
		system("pause");
	} else {
		int i=0;
		while(stu[i][0]!=0) {
			fprintf(fp,"%d,%d\n",stu[i][0],stu[i][1]);
			i++;
		}
		fclose(fp);
	}
}
void load_score() {
	printf("准备读取数据到文件......\n");
	FILE *fp;
	fp=fopen("d:\\score.txt","a+");
	if(fp=NULL) {
		printf("文件打开失败");
		system("pause");
	} else {
		int i=0;
		actnum=0;
		while(fscanf(fp,"%d,%d\n",&stu[i][0],&stu[i][1])!=EOF) {
			i++;
			actnum++;
		}
		printf("%d条数据\n",i+1);
		fclose(fp);
	}
}
void bubble_sort_by_score() {
	printf("准备成绩排序，基于冒泡排序......\n");
//	for(int j=0; j<actnum-1; j++) {
//		if(stu[j][1]>stu[j+1][1]) {
//			int tempID=stu[j][0];
//			int tempScore=stu[j][1];
//			stu[j][0]=stu[j+1][0];
//			stu[j][1]=stu[j+1][1];
//			stu[j+1][0]=tempID;
//			stu[j+1][1]=tempScore;
//		}
for (int i=0;i<actnum-1;i++){
	for(int j=0;j<actnum-1-i;j++){
		if(stu[j][1]>stu[j+1][1]){
			int tempID=stu[j][0];
			int tempScore=stu[j][1];
			stu[j][0]=stu[j+1][0];
			stu[j][1]=stu[j+1][1];
			stu[j+1][0]=tempID;
			stu[j+1][1]=tempScore;
		}
	}
}

		printf("排序完毕，建议进行查看以避免程序存在错误。");
	}
void insertion_sort_by_score() {
}


