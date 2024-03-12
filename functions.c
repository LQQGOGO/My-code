#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include"myfunctions.h"

void CleanBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}


void AccountLoad(struct accountNode **head)
{
	while(*head!=NULL)
	{
		struct accountNode *temp=*head;
		*head=(*head)->next;
		free(temp);
	}
	*head=NULL;
	struct accountNode *prev=NULL;
	struct account cur;
	FILE *fp=fopen("Account.txt","r");
	if(fp==NULL){
		printf("系统启动失败\n");
		return;
	}
	while(fscanf(fp,"%s %s %c %s\n",cur.name,cur.password,&cur.role,cur.class)!=EOF)
	{
		struct accountNode *newNode=(struct accountNode *)malloc(sizeof(struct accountNode));
		if (newNode == NULL)
		{
			fprintf(stderr, "内存分配失败\n");
			fclose(fp);
			return;
		}
		strcpy(newNode->acc.name,cur.name);
		strcpy(newNode->acc.password,cur.password);
		newNode->acc.role=cur.role;
		strcpy(newNode->acc.class,cur.class);
		newNode->next=NULL;
		if(*head==NULL)
		{
			*head= newNode;
		}else{
			prev->next=newNode;
		}
		prev=newNode;
	}
	fclose(fp);
}

int AccountLand(struct accountNode *head,char *role,char *class,char *school)
{
	char name[MAXLENGTH];
	char password[MAXLENGTH];
	struct accountNode *cur=head;
	printf("请输入你的账号:\n");
	//scanf("%s",name);
	if (scanf("%49s", name) != 1) {
		printf("无效的输入，请重新操作\n");
		CleanBuffer();
		//free(newNode);
		return 3;
	}
	printf("请输入你的密码:\n");
	//scanf("%s",password);
	if (scanf("%49s", password) != 1) {
		printf("无效的输入，请重新操作\n");
		CleanBuffer();
		//free(newNode);
		return 3;
	}
	while(cur!=NULL)
	{
		if(strcmp(cur->acc.name,name)==0)
		{
			if(strcmp(cur->acc.password,password)==0)
			{
				*role = cur->acc.role;
				strcpy(class,cur->acc.class);
				strcpy(school,cur->acc.name);
				printf("登录成功\n");
				return 1;
			}else{
				printf("密码错误\n");
				return 0;
			}
		}
		cur=cur->next;
	}
	printf("账号不存在\n");
	return 3;
	//printf("j");
}

int StudentMenu()
{
	int i=0;
	printf("请输入你想进行的操作:\n");
	printf("1.查询个人成绩\n");
	printf("2.查询本班成绩\n");
	printf("3.成绩分析\n");
	printf("4.成绩申诉\n");
	printf("5.返回上一层\n");
	printf("0.退出\n");
	//scanf("%d",&i);
	while (1) {
		if (scanf("%d", &i) != 1) {
			printf("请输入一个有效的整数\n");
			while (getchar() != '\n');
			//system("cls");
		}else{
			break;
		}
	}
	return i;
}

void StudentLoad(struct studentNode **head,int *ns)
{
	while(*head!=NULL)
	{
		struct studentNode *temp=*head;
		*head=(*head)->next;
		free(temp);
	}
	*head=NULL;
	struct studentNode *prev=NULL;
	struct student cur;
	int i=0;
	FILE *fp=fopen("Class1.txt","r");
	if(fp==NULL){
		printf("文件1启动失败\n");
		*ns=0;
		return;
	}
	while(fscanf(fp,"%s %s %s %d %d %d\n",cur.name,cur.schoolNumber,cur.classNumber,&cur.chinese,&cur.math,&cur.english)!=EOF)
	{
		struct studentNode *newNode=(struct studentNode *)malloc(sizeof(struct studentNode));
		if (newNode == NULL) {
			printf("内存分配失败\n");
			fclose(fp);
			return;
		}
		strcpy(newNode->stu.name,cur.name);
		strcpy(newNode->stu.schoolNumber,cur.schoolNumber);
		strcpy(newNode->stu.classNumber,cur.classNumber);
		newNode->stu.chinese=cur.chinese;
		newNode->stu.math=cur.math;
		newNode->stu.english=cur.english;
		newNode->next=NULL;
		i++;
		if(*head==NULL)
		{
			*head= newNode;
		}else{
			prev->next=newNode;
		}
		prev=newNode;
	}
	fclose(fp);
	fp=fopen("Class2.txt","r");
	if(fp==NULL){
		printf("文件2启动失败\n");
		*ns=0;
		return;
	}
	while(fscanf(fp,"%s %s %s %d %d %d\n",cur.name,cur.schoolNumber,cur.classNumber,&cur.chinese,&cur.math,&cur.english)!=EOF)
	{
		struct studentNode *newNode=(struct studentNode *)malloc(sizeof(struct studentNode));
		if (newNode == NULL) {
			printf("内存分配失败\n");
			fclose(fp);
			return;
		}
		strcpy(newNode->stu.name,cur.name);
		strcpy(newNode->stu.schoolNumber,cur.schoolNumber);
		strcpy(newNode->stu.classNumber,cur.classNumber);
		newNode->stu.chinese=cur.chinese;
		newNode->stu.math=cur.math;
		newNode->stu.english=cur.english;
		newNode->next=NULL;
		i++;
		if(*head==NULL)
		{
			*head= newNode;
		}else{
			prev->next=newNode;
		}
		prev=newNode;
	}
	fclose(fp);
	fp=fopen("Class3.txt","r");
	if(fp==NULL){
		printf("文件3启动失败\n");
		*ns=0;
		return;
	}
	while(fscanf(fp,"%s %s %s %d %d %d\n",cur.name,cur.schoolNumber,cur.classNumber,&cur.chinese,&cur.math,&cur.english)!=EOF)
	{
		struct studentNode *newNode=(struct studentNode *)malloc(sizeof(struct studentNode));
		if (newNode == NULL) {
			printf("内存分配失败\n");
			fclose(fp);
			return;
		}
		strcpy(newNode->stu.name,cur.name);
		strcpy(newNode->stu.schoolNumber,cur.schoolNumber);
		strcpy(newNode->stu.classNumber,cur.classNumber);
		newNode->stu.chinese=cur.chinese;
		newNode->stu.math=cur.math;
		newNode->stu.english=cur.english;
		newNode->next=NULL;
		i++;
		if(*head==NULL)
		{
			*head= newNode;
		}else{
			prev->next=newNode;
		}
		prev=newNode;
	}
	fclose(fp);
	fp=fopen("Class4.txt","r");
	if(fp==NULL){
		printf("文件4启动失败\n");
		*ns=0;
		return;
	}
	while(fscanf(fp,"%s %s %s %d %d %d\n",cur.name,cur.schoolNumber,cur.classNumber,&cur.chinese,&cur.math,&cur.english)!=EOF)
	{
		struct studentNode *newNode=(struct studentNode *)malloc(sizeof(struct studentNode));
		if (newNode == NULL) {
			printf("内存分配失败\n");
			fclose(fp);
			return;
		}
		strcpy(newNode->stu.name,cur.name);
		strcpy(newNode->stu.schoolNumber,cur.schoolNumber);
		strcpy(newNode->stu.classNumber,cur.classNumber);
		newNode->stu.chinese=cur.chinese;
		newNode->stu.math=cur.math;
		newNode->stu.english=cur.english;
		newNode->next=NULL;
		i++;
		if(*head==NULL)
		{
			*head= newNode;
		}else{
			prev->next=newNode;
		}
		prev=newNode;
	}
	fclose(fp);
	fp=fopen("Class5.txt","r");
	if(fp==NULL){
		printf("文件5启动失败\n");
		*ns=0;
		return;
	}
	while(fscanf(fp,"%s %s %s %d %d %d\n",cur.name,cur.schoolNumber,cur.classNumber,&cur.chinese,&cur.math,&cur.english)!=EOF)
	{
		struct studentNode *newNode=(struct studentNode *)malloc(sizeof(struct studentNode));
		if (newNode == NULL) {
			printf("内存分配失败\n");
			fclose(fp);
			return;
		}
		strcpy(newNode->stu.name,cur.name);
		strcpy(newNode->stu.schoolNumber,cur.schoolNumber);
		strcpy(newNode->stu.classNumber,cur.classNumber);
		newNode->stu.chinese=cur.chinese;
		newNode->stu.math=cur.math;
		newNode->stu.english=cur.english;
		newNode->next=NULL;
		i++;
		if(*head==NULL)
		{
			*head= newNode;
		}else{
			prev->next=newNode;
		}
		prev=newNode;
	}
	*ns=i;
	fclose(fp);
}

void StuGradeFind(char *school,struct studentNode *head)
{
	int flag=0;
	struct studentNode *cur=head;
	while(cur!=NULL){
		if(strcmp(cur->stu.schoolNumber,school)==0)
		{
			printf("========== 成绩单 ==========\n");
			printf("学生姓名: %s\n", cur->stu.name);
			printf("学号: %s\n", cur->stu.schoolNumber);
			printf("班级: %s\n", cur->stu.classNumber);
			printf("语文成绩: %d\n", cur->stu.chinese);
			printf("数学成绩: %d\n", cur->stu.math);
			printf("英语成绩: %d\n", cur->stu.english);
			flag=1;
			return;
		}
		cur=cur->next;
	}
//	printf("学号有误，未查询到该学生成绩......\n");
	if(flag==0){
		printf("学号有误，未查询到你的成绩......\n");
		cur=head;
		char schoolNumber[MAXLENGTH];
		printf("请尝试再次输入学号:\n");
		if (scanf("%49s", schoolNumber) != 1) {
			printf("无效的输入，请重新操作\n");
			CleanBuffer();
			//free(newNode);
			return;
		}
		//scanf("%s",schoolNumber);
		while(cur!=NULL){
			if(strcmp(cur->stu.schoolNumber,schoolNumber)==0)
			{
				printf("========== 成绩单 ==========\n");
				printf("学生姓名: %s\n", cur->stu.name);
				printf("学号: %s\n", cur->stu.schoolNumber);
				printf("班级: %s\n", cur->stu.classNumber);
				printf("语文成绩: %d\n", cur->stu.chinese);
				printf("数学成绩: %d\n", cur->stu.math);
				printf("英语成绩: %d\n", cur->stu.english);
				return;
			}
			cur=cur->next;
		}
	}
	printf("学号有误，未查询你的学生成绩......\n");
}

//void ClassGradeFind(const char *filePath)
//{
//	FILE* fp=fopen(filePath,"r");
//	if(fp==NULL)
//	{
//		printf("系统故障，查询失败......\n");
//		return;
//	}
//	struct student stu;
//	printf("=============== 成绩表 ================\n");
//	printf("姓名\t学号\t班级\t语文\t数学\t英语\n");
//	while(fscanf(fp,"%s %s %s %d %d %d\n",stu.name,stu.schoolNumber,stu.classNumber,&stu.chinese,&stu.math,&stu.english)!=EOF)
//	{
//		printf("%s\t%s\t%s\t%d\t%d\t%d\n",stu.name,stu.schoolNumber,stu.classNumber,stu.chinese,stu.math,stu.english);
//	}
//	fclose(fp);
//}

int compareTotalScore(const void *a, const void *b) {
	struct student *stuA = (struct student *)a;
	struct student *stuB = (struct student *)b;
	
	int totalScoreA = stuA->chinese + stuA->math + stuA->english;
	int totalScoreB = stuB->chinese + stuB->math + stuB->english;
	
	return totalScoreB - totalScoreA;
}

void ClassGradeFind(char *filePath) {
	FILE *fp = fopen(filePath, "r");
	if (fp == NULL) {
		printf("系统故障，查询失败......\n");
		return;
	}
	
	struct student stu;
	printf("=============== 成绩表 ================\n");
	printf("姓名\t学号\t班级\t语文\t数学\t英语\t总分\n");
	
	struct student students[100]; 
	int count = 0;
	
	while (fscanf(fp, "%s %s %s %d %d %d\n", stu.name, stu.schoolNumber, stu.classNumber, &stu.chinese, &stu.math, &stu.english) != EOF) {
		students[count++] = stu;
	}
	
	fclose(fp);
	
	qsort(students, count, sizeof(struct student), compareTotalScore);
	
	for (int i = 0; i < count; ++i) {
		int totalScore = students[i].chinese + students[i].math + students[i].english;
		printf("%s\t%s\t%s\t%d\t%d\t%d\t%d\n", students[i].name, students[i].schoolNumber, students[i].classNumber, students[i].chinese, students[i].math, students[i].english, totalScore);
	}
}

void ConvertClassName(char *class)
{
	char c = class[4];
	strcpy(class, "Class");
	class[5] = c;
	class[6] = '.'; 
	class[7] = 't';
	class[8] = 'x';
	class[9] = 't';
	class[10] = '\0';
}

void StuGradeAnalyse(struct studentNode *head,int ns,char* school)
{
	struct studentNode *cur=head;
	int to=0,ch=0,ma=0,en=0;
	int curTo=0;
	int t=1,c=1,m=1,e=1;
	int max=0,min=0;
	char sNum[MAXLENGTH],sName[MAXLENGTH];
	strcpy(sNum,school);
	
	while(cur!=NULL)
	{
		if(strcmp(sNum,cur->stu.schoolNumber)==0)
		{
			strcpy(sName,cur->stu.name);
			ch=cur->stu.chinese;
			ma=cur->stu.math;
			en=cur->stu.english;
			to=ch+ma+en;
			break;
		}
		cur=cur->next;
	}
	if (cur == NULL) {
		printf("出现故障,未找到你的成绩\n");
		return;
	}
	cur=head;
	while(cur!=NULL)
	{
		curTo=cur->stu.chinese+cur->stu.math+cur->stu.english;
		if(cur->stu.chinese>ch)
		{
			c++;
		}
		if(cur->stu.math>ma)
		{
			m++;
		}
		if(cur->stu.english>en)
		{
			e++;
		}
		if(curTo>to)
		{
			t++;
		}
		cur=cur->next;
	}
	printf("%s的成绩分析如下:\n",sName);
	printf("\t\t语文\t数学\t英语\t总分\n");
	printf("成绩\t\t%d\t%d\t%d\t%d\n",ch,ma,en,to);
	printf("全校排名\t%d\t%d\t%d\t%d\n",c,m,e,t);
	min=c>m?c:m;
	min=min>e?min:e;
	max=c<m?c:m;
	max=max<e?max:e;
	if(max>ns/2)
	{
		printf("考得不是很理想，还要继续努力!\n");
		if(min==c){
			printf("尤其是语文，要多花点时间哦!\n");
		}else if(min==m){
			printf("尤其是数学，要多花点时间哦!\n");
		}else {
			printf("尤其是英语，要多花点时间哦!\n");
		}
	}else {
		if(t>ns/2){
			printf("考得不是很理想，还要继续努力!\n");
			if(max<ns/3){
				if(max==c){
					printf("但是语文考得不错，要继续保持哦!\n");
				}else if(max==m){
					printf("但是数学考得不错，要继续保持哦!\n");
				}else {
					printf("但是英语考得不错，要继续保持哦!\n");
				}
			}
			if(min==c){
				printf("尤其是语文拖后腿了，要多花点时间在语文上\n");
			}else if(min==m){
				printf("尤其是数学拖后腿了，要多花点时间在数学上\n");
			}else {
				printf("尤其是英语拖后腿了，要多花点时间在英语上\n");
			}
		}else{
			printf("考得不错，已经超过一大部分人了!\n");
			if(max==c){
				printf("语文带来了很大帮助，要继续保持哦!\n");
			}else if(max==m){
				printf("数学带来了很大帮助，要继续保持哦!\n");
			}else {
				printf("英语带来了很大帮助，要继续保持哦!\n");
			}
			if(min>ns){
				if(min==c){
					printf("但是语文拖后腿了，要多花点时间在语文上\n");
				}else if(min==m){
					printf("但是数学拖后腿了，要多花点时间在数学上\n");
				}else {
					printf("但是英语拖后腿了，要多花点时间在英语上\n");
				}
			}
		}
	}
	
}

int TeacherMenu()
{
	int i=0;
	printf("请输入你想进行的操作:\n");
	printf("1.增加新的学生成绩\n");
	printf("2.删除学生信息\n");
	printf("3.修改学生信息\n");
	printf("4.查询学生信息\n");
	printf("5.输出本班学生成绩\n");
	printf("6.下载到文件中\n");
	printf("7.成绩分析\n");
	printf("8.提醒管理员进行成绩的更新\n");
	printf("9.返回上一层\n");
	printf("0.退出\n");
	//scanf("%d",&i);
	while (1) {
		if (scanf("%d", &i) != 1) {
			printf("请输入一个有效的整数\n");
			while (getchar() != '\n');
			//system("cls");
		}else{
			break;
		}
	}
	return i;
}

void AddStudent(struct studentNode **head) {
	struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
	
	printf("请输入学生姓名:\n");
	if (scanf("%49s", newNode->stu.name) != 1) {
		printf("输入错误！\n");
		CleanBuffer();
		free(newNode);
		return;
	}
	CleanBuffer();
	
	printf("请输入学生班级:\n");
	if (scanf("%49s", newNode->stu.classNumber) != 1) {
		printf("输入错误！\n");
		CleanBuffer();
		free(newNode);
		return;
	}
	CleanBuffer();
	
	printf("请输入学生学号:\n");
	if (scanf("%49s", newNode->stu.schoolNumber) != 1) {
		printf("输入错误！\n");
		CleanBuffer();
		free(newNode);
		return;
	}
	CleanBuffer();
	
	printf("请顺序输入学生语数英成绩:\n");
	if (scanf("%d %d %d", &newNode->stu.chinese, &newNode->stu.math, &newNode->stu.english) != 3) {
		printf("输入错误！\n");
		CleanBuffer();
		free(newNode);
		return;
	}
	CleanBuffer();
	
	struct studentNode* cur = *head;
	if (cur == NULL) {
		*head = newNode;
	} else {
		while (cur->next != NULL) {
			if (strcmp(cur->stu.schoolNumber, newNode->stu.schoolNumber) == 0) {
				printf("该学号已存在，录入失败......\n");
				free(newNode);
				return;
			}
			cur = cur->next;
		}
		cur->next = newNode;
	}
	
	char filePath[MAXLENGTH];
	convertClassName(newNode->stu.schoolNumber, filePath);
//	strcpy(filePath,newNode->stu.classNumber);
//	ConvertClassName(filePath);
	
	FILE *fp = fopen(filePath, "a");
	if (fp == NULL) {
		printf("打开文件故障,录入失败......\n");
		free(newNode);
		return;
	}
	
	fprintf(fp, "%s %s %s %d %d %d\n", newNode->stu.name, newNode->stu.schoolNumber,
		newNode->stu.classNumber, newNode->stu.chinese, newNode->stu.math, newNode->stu.english);
	printf("添加学生成绩成功!\n");
	fclose(fp);
}

void DeleteStudent(struct studentNode **head) {
	char schoolNumber[MAXLENGTH];
	printf("请输入要删除的学生学号:\n");
	//scanf("%s", schoolNumber);
	if (scanf("%49s", schoolNumber) != 1) {
		printf("输入错误！\n");
		CleanBuffer();
		//free(newNode);
		return;
	}
	
	struct studentNode *cur = *head;
	struct studentNode *prev = NULL;
	
	if (strcmp(cur->stu.schoolNumber, schoolNumber) == 0) {
		printf("该学生的成绩如下:\n");
		printf("========== 成绩单 ==========\n");
		printf("学生姓名: %s\n", cur->stu.name);
		printf("学号: %s\n", cur->stu.schoolNumber);
		printf("班级: %s\n", cur->stu.classNumber);
		printf("语文成绩: %d\n", cur->stu.chinese);
		printf("数学成绩: %d\n", cur->stu.math);
		printf("英语成绩: %d\n", cur->stu.english);
		printf("你确定要删除吗?\n1.是\n2.否\n");
		
		int c;
		while (1) {
			if (scanf("%d", &c) != 1) {
				printf("请输入一个有效的整数\n");
				while (getchar() != '\n');
				//system("cls");
			}else{
				break;
			}
		}
		if(c!=1){
			return;
		}
		*head = cur->next;
		free(cur);
	} else {
		while (cur != NULL) {
			if (strcmp(cur->stu.schoolNumber, schoolNumber) == 0) {
				printf("该学生的成绩如下:\n");
				printf("========== 成绩单 ==========\n");
				printf("学生姓名: %s\n", cur->stu.name);
				printf("学号: %s\n", cur->stu.schoolNumber);
				printf("班级: %s\n", cur->stu.classNumber);
				printf("语文成绩: %d\n", cur->stu.chinese);
				printf("数学成绩: %d\n", cur->stu.math);
				printf("英语成绩: %d\n", cur->stu.english);
				printf("你确定要删除吗?\n1.是\n2.否\n");
				
				int c;
				while (1) {
					if (scanf("%d", &c) != 1) {
						printf("请输入一个有效的整数\n");
						while (getchar() != '\n');
						//system("cls");
					}else{
						break;
					}
				}
				if(c!=1){
					return;
				}
				prev->next = cur->next;
				free(cur);
				break;
			}
			prev = cur;
			cur = cur->next;
		}
	}
	if(cur==NULL){
		printf("学生学号不存在,请重新操作\n");
		return;
	}
	
	char filePath[MAXLENGTH];
	convertClassName(schoolNumber, filePath);
	
	FILE *fp = fopen(filePath, "r");
	if (fp == NULL) {
		printf("打开文件失败\n");
		return;
	}
	
	FILE *temp = tmpfile();
	if (temp == NULL) {
		printf("无法创建临时文件\n");
		fclose(fp);
		return;
	}
	
	char buffer[MAXLENGTH];
	while (fgets(buffer, MAXLENGTH, fp) != NULL) {
		if (strstr(buffer, schoolNumber) == NULL) {
			fputs(buffer, temp);
		}
	}
	
	rewind(temp);
	fclose(fp);
	
	fp = fopen(filePath, "w");
	if (fp == NULL) {
		printf("无法打开文件\n");
		fclose(temp);
		return;
	}
	
	while (fgets(buffer, MAXLENGTH, temp) != NULL) {
		fputs(buffer, fp);
	}
	printf("学生信息删除成功!\n");
	fclose(fp);
	fclose(temp);
}

void convertClassName(const char* originalString, char* result) {
	
	strcpy(result, "class");
	result[strlen(result)] = originalString[1];
	strcat(result, ".txt");
}

void GradeFind(struct studentNode *head)
{
	struct studentNode *cur=head;
	char schoolNumber[MAXLENGTH];
	printf("请输入学号:\n");
	if (scanf("%49s", schoolNumber) != 1) {
		printf("无效的输入，请重新操作\n");
		CleanBuffer();
		//free(newNode);
		return;
	}
	//scanf("%s",schoolNumber);
	while(cur!=NULL){
		if(strcmp(cur->stu.schoolNumber,schoolNumber)==0)
		{
			printf("========== 成绩单 ==========\n");
			printf("学生姓名: %s\n", cur->stu.name);
			printf("学号: %s\n", cur->stu.schoolNumber);
			printf("班级: %s\n", cur->stu.classNumber);
			printf("语文成绩: %d\n", cur->stu.chinese);
			printf("数学成绩: %d\n", cur->stu.math);
			printf("英语成绩: %d\n", cur->stu.english);
			return;
		}
		cur=cur->next;
	}
	printf("你输入的学号有误，未查询到该学生成绩......\n");
}

void FileCopy()
{
	char s;
	char result[MAXLENGTH];
	char dest[MAXLENGTH];
	printf("请输入你想下载的班级(数字对应班级号):\n");
	//scanf(" %c",&s);
	if (scanf("%c", &s) != 1) {
		printf("输入错误！\n");
		CleanBuffer();
		//free(newNode);
		return;
	}
	
	printf("请输入你想下载到哪个文件中:\n");
	//scanf("%s",dest);
	if (scanf("%49s", dest) != 1) {
		printf("输入错误！\n");
		CleanBuffer();
		//free(newNode);
		return;
	}
	
	strcat(dest, ".txt");
	FILE* d;
	while ((d = fopen(dest, "r")) != NULL) {
		fclose(d);
		printf("该文件已经存在，请重新输入:\n");
		//scanf("%s", dest);
		if (scanf("%49s", dest) != 1) {
			printf("输入错误！\n");
			CleanBuffer();
			fclose(d);
			//free(newNode);
			return;
		}
		
		strcat(dest, ".txt");
	}
	//sprintf(result, "class%c.txt", s);
	strcpy(result, "class");
	result[strlen(result)] = s;
	strcat(result, ".txt");
	FILE* souFile=fopen(result,"r");
	if(souFile==NULL){
		printf("原文件打开失败\n");
		return;
	}
	FILE* destFile=fopen(dest,"w");
	if(destFile==NULL){
		printf("目标文件打开失败\n");
		return;
	}
	int c;
	while((c=fgetc(souFile))!=EOF){
		fputc(c,destFile);
	}
	printf("下载成功!\n");
	fclose(souFile);
	fclose(destFile);
}

void GradeAnalyse(struct studentNode *head,int ns)
{
	int to=0,ch=0,ma=0,en=0;
	int curTo=0;
	int t=1,c=1,m=1,e=1;
	int max=0,min=0;
	//int i;
	char sNum[MAXLENGTH],sName[MAXLENGTH];
	struct studentNode *cur=head;
	printf("请输入学生学号:\n");
	//scanf("%s",sNum);
	if (scanf("%49s", sNum) != 1) {
		printf("无效的输入，请重新操作\n");
		CleanBuffer();
		//free(newNode);
		return;
	}
	while(cur!=NULL)
	{
		if(strcmp(sNum,cur->stu.schoolNumber)==0)
		{
			strcpy(sName,cur->stu.name);
			ch=cur->stu.chinese;
			ma=cur->stu.math;
			en=cur->stu.english;
			to=ch+ma+en;
			break;
		}
		cur=cur->next;
	}
	if (cur == NULL) {
		printf("未找到该学生\n");
		return;
	}
	cur=head;
	while(cur!=NULL)
	{
		curTo=cur->stu.chinese+cur->stu.math+cur->stu.english;
		if(cur->stu.chinese>ch)
		{
			c++;
		}
		if(cur->stu.math>ma)
		{
			m++;
		}
		if(cur->stu.english>en)
		{
			e++;
		}
		if(curTo>to)
		{
			t++;
		}
		cur=cur->next;
	}
	printf("%s的成绩分析如下:\n",sName);
	printf("\t\t语文\t数学\t英语\t总分\n");
	printf("成绩\t\t%d\t%d\t%d\t%d\n",ch,ma,en,to);
	printf("全校排名\t%d\t%d\t%d\t%d\n",c,m,e,t);
	min=c>m?c:m;
	min=min>e?min:e;
	max=c<m?c:m;
	max=max<e?max:e;
	if(max>ns/2)
	{
		printf("考得不是很理想，还要继续努力!\n");
		if(min==c){
			printf("尤其是语文，要多花点时间哦!\n");
		}else if(min==m){
			printf("尤其是数学，要多花点时间哦!\n");
		}else {
			printf("尤其是英语，要多花点时间哦!\n");
		}
	}else {
		if(t>ns/2){
			printf("考得不是很理想，还要继续努力!\n");
			if(max<ns/3){
				if(max==c){
					printf("但是语文考得不错，要继续保持哦!\n");
				}else if(max==m){
					printf("但是数学考得不错，要继续保持哦!\n");
				}else {
					printf("但是英语考得不错，要继续保持哦!\n");
				}
			}
			if(min==c){
				printf("尤其是语文拖后腿了，要多花点时间在语文上\n");
			}else if(min==m){
				printf("尤其是数学拖后腿了，要多花点时间在数学上\n");
			}else {
				printf("尤其是英语拖后腿了，要多花点时间在英语上\n");
			}
		}else{
			printf("考得不错，已经超过一大部分人了!\n");
			if(max==c){
				printf("语文带来了很大帮助，要继续保持哦!\n");
			}else if(max==m){
				printf("数学带来了很大帮助，要继续保持哦!\n");
			}else {
				printf("英语带来了很大帮助，要继续保持哦!\n");
			}
			if(min>ns){
				if(min==c){
					printf("但是语文拖后腿了，要多花点时间在语文上\n");
				}else if(min==m){
					printf("但是数学拖后腿了，要多花点时间在数学上\n");
				}else {
					printf("但是英语拖后腿了，要多花点时间在英语上\n");
				}
			}
		}
	}
}

char ManagerMenu()
{
	char i=0;
	printf("请输入你想进行的操作:\n");
	printf("1.查看代办选项\n");
	printf("2.进入教师端进行信息修改\n");
	printf("3.增加账号及密码\n");
	printf("4.删除账号及密码\n");
	printf("5.修改账号及密码\n");
	printf("6.查找账号及密码\n");
	printf("7.录入所有账号及密码\n");
	printf("8.输出所有账号及密码\n");
	printf("9.手动重新录入学生信息\n");
	printf("a.返回上一层\n");
	printf("0.退出\n");
	//scanf(" %c",&i);
	while (1) {
		if (scanf("%c", &i) != 1) {
			printf("请输入一个有效的选择\n");
			while (getchar() != '\n');
			//system("cls");
		}else{
			break;
		}
	}
	return i;
}

void AccountRegist(struct accountNode **head)
{
	//int i=*n;
	struct accountNode* temp=*head;
	struct accountNode *cur=*head;
	struct accountNode *newNode=(struct accountNode *)malloc(sizeof(struct accountNode));\
	newNode->next = NULL;
	printf("请设置账号:\n");
	if (scanf("%49s", newNode->acc.name) != 1) {
		printf("无效的输入，请重新设置账号\n");
		CleanBuffer();
		free(newNode);
		return;
	}
	while(temp!=NULL)
	{
		if (strcmp(temp->acc.name, newNode->acc.name) == 0) {
			printf("该账号已经存在，请重新设置你的账号\n");
			return;
		}
		temp = temp->next;
	}
	printf("请设置密码:\n");
	if (scanf("%49s", newNode->acc.password) != 1) {
		printf("无效的输入，请重新设置密码\n");
		CleanBuffer();
		free(newNode);
		return;
	}
	printf("请设置身份(学生s,老师t,管理员m):\n");
	while (1) {
		if (scanf(" %c", &newNode->acc.role) != 1) {
			printf("无效的输入，请重新设置身份\n");
			while (getchar() != '\n');
		}else{
			break;
		}
	}
	if(newNode->acc.role=='s'){
		printf("请输入该学生所在班级\n");
		if (scanf("%49s", newNode->acc.class) != 1) {
			printf("无效的输入，请重新设置\n");
			CleanBuffer();
			free(newNode);
			return;
		}
	}
	if(newNode->acc.role=='t'){
		printf("请输入该老师所带的班级\n");
		if (scanf("%49s", newNode->acc.class) != 1) {
			printf("无效的输入，请重新设置\n");
			CleanBuffer();
			free(newNode);
			return;
		}
	}
	if(newNode->acc.role=='m'){
		strcpy(newNode->acc.class,"管理员");
	}
	
	//(*n)++;
	FILE *fp=fopen("Account.txt","a");
	if(fp==NULL){
		printf("注册新账号失败，请重新操作\n");
		return;
	}
	fprintf(fp,"%s %s %c %s\n",newNode->acc.name,newNode->acc.password,newNode->acc.role,newNode->acc.class);
	if (*head == NULL) 
	{
		*head = newNode;
	} else {
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = newNode;
	}
	system("cls");
	printf("注册成功，可登录该账号\n");
	fclose(fp);
	//printf("j");
}

//void DeleteAccount()
//{
//	int s,f=0;
//	char name[MAXLENGTH];
//	printf("请输入要删除的账号:\n");
//	//scanf("%s", name);
//	if (scanf("%49s", name) != 1) {
//		printf("输入错误！\n");
//		CleanBuffer();
//		//fclose(d);
//		//free(newNode);
//		return;
//	}
//	
//	FILE *fp = fopen("Account.txt", "r");
//	if (fp == NULL) {
//		printf("打开文件失败\n");
//		return;
//	}
//	
//	FILE *temp = tmpfile();
//	if (temp == NULL) {
//		printf("无法创建临时文件\n");
//		fclose(fp);
//		return;
//	}
//	
//	char buffer[MAXLENGTH];
//	while (fgets(buffer, MAXLENGTH, fp) != NULL) {
//		if (strstr(buffer, name) == NULL) {
//			fputs(buffer, temp);
//		}else{
//			f=1;
//		}
//	}
//	
//	if(f==0){
//		printf("账号不存在!\n");
//		fclose(fp);
//		fclose(temp);
//		return;
//	}
//	rewind(temp);
//	fclose(fp);
//	
//	fp = fopen("Account.txt", "w");
//	if (fp == NULL) {
//		printf("无法打开文件\n");
//		fclose(temp);
//		return;
//	}
//	
//	while (fgets(buffer, MAXLENGTH, temp) != NULL) {
//		fputs(buffer, fp);
//	}
//	printf("账号删除成功!\n");
//	fclose(fp);
//	fclose(temp);
//}

void DeleteAccount()
{
	int s, f = 0;
	char name[MAXLENGTH];
	printf("请输入要删除的账号:\n");
	//scanf("%s", name);
	if (scanf("%49s", name) != 1) {
		printf("输入错误！\n");
		CleanBuffer();
		//fclose(d);
		//free(newNode);
		return;
	}
	
	FILE* fp = fopen("Account.txt", "r");
	if (fp == NULL) {
		printf("打开文件失败\n");
		return;
	}
	
	FILE* temp = tmpfile();
	if (temp == NULL) {
		printf("无法创建临时文件\n");
		fclose(fp);
		return;
	}
	
	char buffer[MAXLENGTH];
	while (fgets(buffer, MAXLENGTH, fp) != NULL) {
		if (strstr(buffer, name) == NULL) {
			fputs(buffer, temp);
		}
		else {
			f = 1;
			struct account acc;
			sscanf(buffer, "%s %s %c %s", acc.name, acc.password, &acc.role, acc.class);
			printf("找到账号信息：\n");
			printf("账号: %s\n", acc.name);
			printf("密码: %s\n", acc.password);
			printf("身份: %c\n", acc.role);
			printf("相关班级: %s\n", acc.class);
			printf("是否删除该账号？(1: 是, 0: 否)\n");
			//scanf("%d", &s);
			while (1) {
				if (scanf("%d", &s) != 1) {
					printf("请输入一个有效的整数\n");
					while (getchar() != '\n');
					//system("cls");
				}else{
					break;
				}
			}
			if (s == 1) {
				continue;
			}else{
				return;
			}
		}
	}
	
	if (f == 0) {
		printf("账号不存在!\n");
		fclose(fp);
		fclose(temp);
		return;
	}
	rewind(temp);
	fclose(fp);
	
	fp = fopen("Account.txt", "w");
	if (fp == NULL) {
		printf("无法打开文件\n");
		fclose(temp);
		return;
	}
	
	while (fgets(buffer, MAXLENGTH, temp) != NULL) {
		fputs(buffer, fp);
	}
	printf("账号删除成功!\n");
	fclose(fp);
	fclose(temp);
}


void ReviseAccount() {
	int found = 0;
	char name[MAXLENGTH];
	char password[MAXLENGTH];
	printf("请输入账号:\n");
	if (scanf("%49s", name) != 1) {
		printf("输入错误！\n");
		CleanBuffer();
		return;
	}
	
	FILE *fp = fopen("Account.txt", "r");
	if (fp == NULL) {
		printf("打开文件失败\n");
		return;
	}
	
	struct account buffer;
	while (fscanf(fp, "%s %s %c %s\n", buffer.name, buffer.password, &buffer.role, buffer.class) != EOF) {
		if (strcmp(buffer.name, name) == 0) {
			found = 1;
			printf("原账号信息：\n");
			printf("账号: %s\n", buffer.name);
			printf("密码: %s\n", buffer.password);
			printf("请输入修改之后的密码:\n");
			if (scanf("%49s", password) != 1) {
				printf("输入错误！\n");
				CleanBuffer();
				fclose(fp);
				return;
			}
			break;
		}
	}
	fclose(fp);
	
	if (!found) {
		printf("账号不存在!\n");
		return;
	}
	
	FILE *temp = tmpfile();
	if (temp == NULL) {
		printf("无法创建临时文件\n");
		return;
	}
	
	fp = fopen("Account.txt", "r");
	if (fp == NULL) {
		printf("打开文件失败\n");
		fclose(temp);
		return;
	}
	
	while (fscanf(fp, "%s %s %c %s\n", buffer.name, buffer.password, &buffer.role, buffer.class) != EOF) {
		if (strcmp(buffer.name, name) == 0) {
			fprintf(temp, "%s %s %c %s\n", name, password, buffer.role, buffer.class);
		} else {
			fprintf(temp, "%s %s %c %s\n", buffer.name, buffer.password, buffer.role, buffer.class);
		}
	}
	
	fclose(fp);
	rewind(temp);
	
	fp = fopen("Account.txt", "w");
	if (fp == NULL) {
		printf("无法打开文件\n");
		fclose(temp);
		return;
	}
	
	while (fscanf(temp, "%s %s %c %s\n", buffer.name, buffer.password, &buffer.role, buffer.class) != EOF) {
		fprintf(fp, "%s %s %c %s\n", buffer.name, buffer.password, buffer.role, buffer.class);
	}
	printf("修改成功!\n");
	fclose(fp);
	fclose(temp);
}

void FindAccount()
{
	int s;
	char name[MAXLENGTH];
	printf("请输入账号:\n");
	//scanf("%s", name);
	if (scanf("%49s", name) != 1) {
		printf("输入错误！\n");
		CleanBuffer();
		//fclose(d);
		//free(newNode);
		return;
	}
	
	FILE *fp = fopen("Account.txt", "r");
	if (fp == NULL) {
		printf("打开文件失败\n");
		return;
	}
	char buffer[MAXLENGTH];
	while (fgets(buffer, MAXLENGTH, fp) != NULL) {
		if (strstr(buffer, name) != NULL) {
			printf("账号\t密码\t身份\t相关班级\n");
			printf("%s\n",buffer);
			return;
		}
	}
	printf("你输入的账号不存在......\n");
}

void OutputAccount(char *filename) {
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		printf("无法打开文件 %s\n", filename);
		return;
	}
	
	struct account acc;
	char line[MAXLENGTH];
	
	printf("学生的账户：\n");
	printf("==============\n");
	while (fscanf(file, "%s %s %c %s", acc.name, acc.password, &acc.role, acc.class) == 4) {
		if (acc.role == 's') {
			printf("账号：%s\n", acc.name);
			printf("密码：%s\n", acc.password);
			printf("--------------\n");
		}
	}
	
	rewind(file);
	
	printf("\n老师的账户：\n");
	printf("==============\n");
	while (fscanf(file, "%s %s %c %s", acc.name, acc.password, &acc.role, acc.class) == 4) {
		if (acc.role == 't') {
			printf("账号：%s\n", acc.name);
			printf("密码：%s\n", acc.password);
			printf("--------------\n");
		}
	}
	
	rewind(file);
	
	printf("\n管理员的账户：\n");
	printf("==============\n");
	while (fscanf(file, "%s %s %c %s", acc.name, acc.password, &acc.role, acc.class) == 4) {
		if (acc.role == 'm') {
			printf("账号：%s\n", acc.name);
			printf("密码：%s\n", acc.password);
			printf("--------------\n");
		}
	}
	
	fclose(file);
}

void GradeAppeal(struct studentNode* head, char* schoolNumber) {
	struct studentNode* current = head;
	while (current != NULL) {
		if (strcmp(current->stu.schoolNumber, schoolNumber) == 0) {
			printf("你的各科成绩如下:\n");
			printf("语文成绩：%d\n", current->stu.chinese);
			printf("数学成绩：%d\n", current->stu.math);
			printf("英语成绩：%d\n", current->stu.english);
			break;
		}
		current = current->next;
	}
	
	current = head;
	FILE *file = fopen("Appeal.txt", "a");
	if (file == NULL) {
		printf("无法打开申诉文件\n");
		return;
	}
	
	while (current != NULL) {
		if (strcmp(current->stu.schoolNumber, schoolNumber) == 0) {
			printf("请输入您的语文期望分数：");
			scanf("%d", &current->stu.chinese);
			printf("请输入您的数学期望分数：");
			scanf("%d", &current->stu.math);
			printf("请输入您的英语期望分数：");
			scanf("%d", &current->stu.english);
			
			fprintf(file, "%s %s %s %d %d %d\n", current->stu.name, current->stu.schoolNumber, current->stu.classNumber,
				current->stu.chinese, current->stu.math, current->stu.english);
			
			printf("申诉信息已保存\n");
			break;
		}
		current = current->next;
	}
	fclose(file);
}

void ReviseGrades(struct studentNode** head) {
	char line[MAXLENGTH];
	FILE* fp = fopen("Appeal.txt", "r");
	if (fp == NULL) {
		printf("无法打开文件\n");
		return;
	}
	while (fgets(line, MAXLENGTH, fp) != NULL) {
		char name[MAXLENGTH];
		char schoolNumber[MAXLENGTH];
		char classNumber[MAXLENGTH];
		int chinese, math, english;
		sscanf(line, "%s %s %s %d %d %d", name, schoolNumber, classNumber, &chinese, &math, &english);
		printf("学生姓名：%s\n", name);
		printf("学号：%s\n", schoolNumber);
		printf("班级：%s\n", classNumber);
		printf("语文期望成绩：%d\n", chinese);
		printf("数学期望成绩：%d\n", math);
		printf("英语期望成绩：%d\n", english);
		DisplayStudentInfo(*head, schoolNumber);
		printf("--------------------------\n");
	}
	fclose(fp);
	
	fp = fopen("Appeal.txt", "r");
	if (fp == NULL) {
		printf("无法打开文件\n");
		return;
	}
	
	int choice;
	do {
		printf("请输入你确定要改成绩的学生的学号 (输入0退出)：\n");
		char school[MAXLENGTH];
		if (scanf("%49s", school) != 1) {
			printf("输入错误！\n");
			CleanBuffer();
			continue;
		}
		if (strcmp(school, "0") == 0) {
			break;
		}
		
		int found = 0; 
		fseek(fp, 0, SEEK_SET);
		while (fgets(line, MAXLENGTH, fp) != NULL) {
			char name[MAXLENGTH];
			char schoolNumber[MAXLENGTH];
			char classNumber[MAXLENGTH];
			int chinese, math, english;
			sscanf(line, "%s %s %s %d %d %d", name, schoolNumber, classNumber, &chinese, &math, &english);
			if (strcmp(schoolNumber, school) == 0) {
				found = 1;
				DeleteAppeal(schoolNumber);
				ReviseStudent(head, schoolNumber, chinese, math, english);
				break;
			}
		}
		
		if (!found) {
			printf("该学生不存在\n");
		}
	} while (1);
	
	fclose(fp);
}




void DisplayStudentInfo(struct studentNode* head, char* schoolNumber) {
	struct studentNode* current = head;
	while (current != NULL) {
		if (strcmp(current->stu.schoolNumber, schoolNumber) == 0) {
			printf("语文原成绩：%d\n", current->stu.chinese);
			printf("数学原成绩：%d\n", current->stu.math);
			printf("英语原成绩：%d\n", current->stu.english);
			break;
		}
		current = current->next;
	}
}

void DeleteAppeal(char *school)
{
	int f=0;
	FILE *fp = fopen("Appeal.txt", "r");
	if (fp == NULL) {
		printf("打开文件失败\n");
		return;
	}
	
	FILE *temp = tmpfile();
	if (temp == NULL) {
		printf("无法创建临时文件\n");
		fclose(fp);
		return;
	}
	
	char buffer[MAXLENGTH];
	while (fgets(buffer, MAXLENGTH, fp) != NULL) {
		if (strstr(buffer, school) == NULL) {
			fputs(buffer, temp);
		}else{
			f=1;
		}
	}
	
	if(f==0){
		printf("账号不存在!\n");
		fclose(fp);
		fclose(temp);
		return;
	}
	rewind(temp);
	fclose(fp);
	
	fp = fopen("Appeal.txt", "w");
	if (fp == NULL) {
		printf("无法打开文件\n");
		fclose(temp);
		return;
	}
	
	while (fgets(buffer, MAXLENGTH, temp) != NULL) {
		fputs(buffer, fp);
	}
	//printf("账号删除成功!\n");
	fclose(fp);
	fclose(temp);
}

void ReviseStudent(struct studentNode **head,char *schoolNumber,int chinese,int math,int english)
{
	struct studentNode *cur = *head;
	while (cur != NULL) {
		if (strcmp(cur->stu.schoolNumber, schoolNumber) == 0) {
//			printf("该学生的语文成绩是:%d\n该学生的数学成绩是:%d\n该学生的英语成绩是:%d\n",
//				cur->stu.chinese, cur->stu.math, cur->stu.english);
//			int newChinese, newMath, newEnglish;
//			printf("请输入修改后的语文成绩:\n");
//			if (scanf("%d", &newChinese) != 1) {
//				printf("输入错误！\n");
//				CleanBuffer();
//				return;
//			}
//			printf("请输入修改后的数学成绩:\n");
//			if (scanf("%d", &newMath) != 1) {
//				printf("输入错误！\n");
//				CleanBuffer();
//				return;
//			}
//			printf("请输入修改后的英语成绩:\n");
//			if (scanf("%d", &newEnglish) != 1) {
//				printf("输入错误！\n");
//				CleanBuffer();
//				return;
//			}
			cur->stu.chinese = chinese;
			cur->stu.math = math;
			cur->stu.english = english;
			char filePath[MAXLENGTH];
			convertClassName(schoolNumber, filePath);
			
			int f = SearchStudentNumber(filePath, schoolNumber);
			if (f == 0) {
				return;
			}
			
			FILE *fp = fopen(filePath, "r");
			if (fp == NULL) {
				printf("打开文件失败\n");
				return;
			}
			
			FILE *temp = tmpfile();
			if (temp == NULL) {
				printf("无法创建临时文件\n");
				fclose(fp);
				return;
			}
			
			char buffer[MAXLENGTH];
			while (fgets(buffer, MAXLENGTH, fp) != NULL) {
				if (strstr(buffer, schoolNumber) == NULL) {
					fputs(buffer, temp);
				} else {
					fprintf(temp, "%s %s %s %d %d %d\n", cur->stu.name, cur->stu.schoolNumber,
						cur->stu.classNumber, cur->stu.chinese, cur->stu.math, cur->stu.english);
				}
			}
			
			rewind(temp);
			fclose(fp);
			
			fp = fopen(filePath, "w");
			if (fp == NULL) {
				printf("无法打开文件\n");
				fclose(temp);
				return;
			}
			
			while (fgets(buffer, MAXLENGTH, temp) != NULL) {
				fputs(buffer, fp);
			}
			printf("修改成功!\n");
			fclose(fp);
			fclose(temp);
			
			return;
		}
		cur = cur->next;
	}
	printf("未找到该学生学号，无法修改成绩。\n");
}

int SearchStudentNumber(char *filePath,char *schoolNumber) 
{
	FILE *fp = fopen(filePath, "r");
	if (fp == NULL) {
		printf("学号 %s 不存在\n", schoolNumber);
		return 0;
	}
	
	char buffer[MAXLENGTH];
	int found = 0;
	while (fgets(buffer, MAXLENGTH, fp) != NULL) {
		if (strstr(buffer, schoolNumber) != NULL) {
			found = 1;
			break;
		}
	}
	
	fclose(fp);
	
	if (!found) {
		printf("学号 %s 不存在\n", schoolNumber);
	}
	return found;
}

//void AverageScores(struct student* head) {
//	if (head == NULL) {
//		printf("链表为空\n");
//		return;
//	}
//	
//	double totalChinese = 0, totalMath = 0, totalEnglish = 0;
//	int studentCount = 0;
//	
//	// 遍历链表计算总分
//	struct student* current = head;
//	while (current != NULL) {
//		// 计算各科总分
//		totalChinese += current->chinese;
//		totalMath += current->math;
//		totalEnglish += current->english;
//		
//		studentCount++;
//		
//		current = current->next;
//	}
//	
//	double averageChinese = totalChinese / studentCount;
//	double averageMath = totalMath / studentCount;
//	double averageEnglish = totalEnglish / studentCount;
//	
//	system("cls");
//	printf("\033[32m\033[1m成绩分析：\033[0m\n\n");
//	
//	printf("\033[32m\033[1m语文平均分：%.2lf\033[0m\n", averageChinese);
//	if (averageChinese >= 80) {
//		printf("\033[32m\033[1m本班语文表现较好，继续保持！\n\033[0m\n");
//	} else {
//		printf("\033[32m\033[1m本班语文有待提高，建议加强相关练习。\n\033[0m\n");
//	}
//	
//	printf("\033[32m\033[1m数学平均分：%.2lf\033[0m\n", averageMath);
//	if (averageMath >= 80) {
//		printf("\033[32m\033[1m本班数学表现较好，继续保持！\033[0m\n\n");
//	} else {
//		printf("\033[32m\033[1m本班数学有待提高，建议加强相关练习。\033[0m\n\n");
//	}
//	
//	printf("\033[32m\033[1m英语平均分：%.2lf\033[0m\n", averageEnglish);
//	if (averageEnglish >= 80) {
//		printf("\033[32m\033[1m本班英语表现较好，继续保持！\033[0m\n");
//	} else {
//		printf("\033[32m\033[1m本班英语有待提高，建议加强相关练习。\033[0m\n");
//	}
//}
//
//void TeacherScoreAnaly(struct student* head) {
//	system("clear");
//	
//	SelectionSort(head->next, 1, 1);
//	printf("\033[32m\033[1m语文成绩排名前十的学生：\033[0m\n");
//	PrintTopStudents(head, 1, 10);
//	printf("\n");
//	Wait();
//	
//	system("clear");
//	SelectionSort(head->next, 2, 1);
//	printf("\033[32m\033[1m数学成绩排名前十的学生：\033[0m\n");
//	PrintTopStudents(head, 2, 10);
//	printf("\n");
//	Wait();
//	
//	system("clear");
//	SelectionSort(head->next, 3, 1);
//	printf("\033[32m\033[1m英语成绩排名前十的学生：\033[0m\n");
//	PrintTopStudents(head, 3, 10);
//	printf("\n");
//	Wait();
//	
//	system("clear");
//	SelectionSort(head->next, 4, 1);
//	printf("\033[32m\033[1m总成绩排名前十的学生：\033[0m\n");
//	PrintTopStudents(head, 4, 10);
//	printf("\n");
//	Wait();
//	
//	AverageScores(head);
//	printf("\n");
//	Wait();
//}
//
//void PrintTopStudents(struct student* head, int subject, int count) {
//	int rank = 1;
//	
//	struct student* cur = head;
//	while (cur != NULL && rank <= count) {
//		if (subject == 1) {
//			printf("\033[33m\033[1m第 %-2d 名: %-8s    语文成绩: %d\033[0m\n", rank, cur->name, cur->chinese);
//		}
//		else if (subject == 2) {
//			printf("\033[33m\033[1m第 %-2d 名: %-8s    数学成绩: %d\033[0m\n", rank, cur->name, cur->math);
//		}
//		else if (subject == 3) {
//			printf("\033[33m\033[1m第 %-2d 名: %-8s    英语成绩: %d\033[0m\n", rank, cur->name, cur->english);
//		}
//		else if (subject == 4) {
//			printf("\033[33m\033[1m第 %-2d 名: %-8s    总成绩: %d\033[0m\n", rank, cur->name, cur->chinese + cur->math + cur->english);
//		}
//		cur = cur->next;
//		rank++;
//	}
//}
//
//
//void SelectionSort(struct student* head, int subjectChoice, int orderChoice) {
//	if (head == NULL || head->next == NULL) {
//		return;
//	}
//	for (struct student* p = head->next; p != NULL; p = p->next) {
//		for (struct student* q = p; q != NULL; q = q->next) {
//			if ((!CompareStudents(p, q, subjectChoice) && orderChoice == 1) || (CompareStudents(p, q, subjectChoice) && orderChoice == 2)) {
//				SwapStudents(p, q);
//			}
//		}
//	}
//}

void Regist(struct accountNode *head) {
	struct accountNode* temp = head;
	struct accountNode* newNode = (struct accountNode*)malloc(sizeof(struct accountNode));
	newNode->next = NULL;
	
	printf("请设置你的账号:\n");
	if (scanf("%49s", newNode->acc.name) != 1) {
		printf("无效的输入，请重新设置你的账号\n");
		CleanBuffer();
		free(newNode);
		return;
	}
	
	while (temp != NULL) {
		if (strcmp(temp->acc.name, newNode->acc.name) == 0) {
			printf("该账号已经存在，请重新设置你的账号\n");
			return;
		}
		temp = temp->next;
	}
	
	printf("请设置你的密码:\n");
	if (scanf("%49s", newNode->acc.password) != 1) {
		printf("无效的输入，请重新设置你的密码\n");
		CleanBuffer();
		free(newNode);
		return;
	}
	
	printf("请设置你的身份:\n");
	if (scanf(" %c", &newNode->acc.role) != 1) {
		printf("无效的输入，请重新设置你的身份\n");
		CleanBuffer();
		free(newNode);
		return;
	} else if (newNode->acc.role != 's' && newNode->acc.role != 't' && newNode->acc.role != 'm') {
		printf("无效的输入，请重新设置你的身份\n");
		return;
	}
	
	printf("请设置你的相关班级（若是管理员则输入管理员）:\n");
	if (scanf("%49s", newNode->acc.class) != 1) {
		printf("无效的输入，请重新设置你的相关班级\n");
		CleanBuffer();
		free(newNode);
		return;
	}
	
	FILE* fp = fopen("Regist.txt", "a");
	if (fp == NULL) {
		printf("注册新账号失败，请重新操作\n");
		return;
	}
	
	fprintf(fp, "%s %s %c %s\n", newNode->acc.name, newNode->acc.password,newNode->acc.role,newNode->acc.class);
	fclose(fp);
	
	system("cls");
	printf("信息读入成功，待管理员确认\n");
	
	free(newNode);
}

void displayAccountsFromFile() {
	FILE* file = fopen("Regist.txt", "r");
	if (file == NULL) {
		printf("打开文件失败\n");
		return;
	}
	
	struct account acc;
	while (fscanf(file, "%s %s %c %s", acc.name, acc.password, &acc.role, acc.class) != EOF) {
		printf("账号: %s, 密码: %s, 身份: %c, 相关班级: %s\n", acc.name, acc.password, acc.role, acc.class);
	}
	
	fclose(file);
}

void insertAccountToList(struct accountNode** head, struct account acc) {
	struct accountNode* newNode = (struct accountNode*)malloc(sizeof(struct accountNode));
	if (newNode == NULL) {
		printf("内存分配失败\n");
		return;
	}
	
	newNode->acc = acc;
	newNode->next = *head;
	*head = newNode;
}

void deleteAccountFromFile(const char* username) {
	FILE* inputFile = fopen("Regist.txt", "r");
	FILE* tempFile = fopen("temp.txt", "w");
	
	if (inputFile == NULL || tempFile == NULL) {
		printf("打开文件失败\n");
		return;
	}
	
	struct account acc;
	while (fscanf(inputFile, "%s %s %c %s", acc.name, acc.password, &acc.role, acc.class) != EOF) {
		if (strcmp(acc.name, username) != 0) {
			fprintf(tempFile, "%s %s %c %s\n", acc.name, acc.password, acc.role, acc.class);
		}
	}
	
	fclose(inputFile);
	fclose(tempFile);
	
	remove("Regist.txt");
	rename("temp.txt", "Regist.txt");
}

void RegistConfirm(struct accountNode** head) {
	printf("下面是申请注册的帐号信息:\n");
	displayAccountsFromFile();
	
	char username[MAXLENGTH];
	printf("请输入你确认要注册的帐号\n");
	scanf("%s", username);
	
	// Check if the username exists in the file
	FILE* file = fopen("Regist.txt", "r");
	if (file == NULL) {
		printf("打开文件失败\n");
		return;
	}
	
	struct account acc;
	int accountExists = 0;
	while (fscanf(file, "%s %s %c %s", acc.name, acc.password, &acc.role, acc.class) != EOF) {
		if (strcmp(acc.name, username) == 0) {
			accountExists = 1;
			break;
		}
	}
	
	fclose(file);
	
	if (!accountExists) {
		printf("该账号不存在\n");
		return;
	}
	
	// Confirm registration
	char response[MAXLENGTH];
	printf("你是想注册这个账号吗? '%s'? (yes/no): ", username);
	scanf("%s", response);
	
	if (strcmp(response, "yes") == 0) {
		// Insert the account into the linked list
		insertAccountToList(head, acc);
		// Remove the account from the file
		deleteAccountFromFile(username);
		FILE* fp = fopen("Account.txt", "a");
		if (fp == NULL) {
			printf("打开文件失败\n");
			return;
		}
		
		fprintf(fp, "%s %s %c %s\n", acc.name, acc.password, acc.role, acc.class);
		fclose(fp);
		printf("注册成功\n", username);
	} else {
		printf("已取消注册\n");
	}
}

int ManagerWorkMenu()
{
	int i;
	printf("请输入你想进行的操作:\n");
	printf("1.密码注册\n");
	printf("2.密码修改\n");
	printf("3.密码找回\n");
	//scanf("%d",&i);
	while (1) {
		if (scanf("%d", &i) != 1) {
			printf("请输入一个有效的整数\n");
			while (getchar() != '\n');
			//system("cls");
		}else{
			break;
		}
	}
	return i;
}


