#include <stdio.h>
#include "util.h"

int main(int argc, char** argv) {
    //定义初始化选择项
	int choose=-1;
	while(1) {
        //调用打印菜单函数
		menu();
		scanf("%d",&choose);
		switch(choose) {
            //用户输入选项菜单项
			case 1:
				input_score();
				break;
			case 2:
				printf("查询成绩\n");
				break;
			case 3:
				printf("修改成绩\n");
				break;
			case 4:
				printf("删除成绩\n");
				break;
			case 5:
				printf("保存成绩\n");
				break;
			case 6:
				student_list();
				break;
			case 0:
				printf("谢谢使用，再见！\n");
				return 0;
		}
	}
	return 0;
}