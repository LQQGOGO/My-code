#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include"myfunctions.h"

int main()
{
	int c1,c2,c3,c4,flag;
	char role;
	char m;
	char school[MAXLENGTH];
	char class[MAXLENGTH];
	struct accountNode *acchead=NULL;
	AccountLoad(&acchead);
	
	while(1)
	{
		start:
		printf("请选择你要进行的操作:\n1.注册\n2.登录\n");
		//scanf("%d",&c1);
		while (1) {
			if (scanf("%d", &c1) != 1) {
				printf("请输入一个有效的整数\n");
				while (getchar() != '\n');
				//system("cls");
			}else{
				break;
			}
		}
		system("cls");
		switch (c1)
		{
		case 1:
			Regist(acchead);
			continue;
		case 2:
			flag = AccountLand(acchead,&role,class,school);
			switch (flag)
			{
			case 0:
				printf("是否要找回密码:\n1.是\n2.否\n");
				//scanf("%d",&c2);
				while (1) {
					if (scanf("%d", &c2) != 1) {
						printf("请输入一个有效的整数\n");
						while (getchar() != '\n');
						//system("cls");
					}else{
						break;
					}
				}
				system("cls");
				switch (c2)
				{
				case 1:
					printf("还没写\n");
					//************PasswordFind(acchead);
					continue;
				case 2:
					system("cls");
					continue;
				default:
					printf("无效请求，请重新输入:\n");
					continue;
				}
				break;
			case 1:
				break;
			default:
				printf("请注册账号后再进行操作......\n");
				Sleep(1000);
				system("cls");
				continue;
			}
			break;
		default:
			system("cls");
			printf("无效请求，请重新输入:\n");
			continue;
		}
		break;
	}
//	printf("%c",role);
//	printf("%s",class);
//	printf("%s",school);
	ConvertClassName(class);
	struct studentNode *stuhead=NULL;
	int ns;
	switch (role) {
	case 's':
		StudentLoad(&stuhead,&ns);
		while(1){
			c3 = StudentMenu();
			system("cls");
			switch (c3) {
			case 1:
				StuGradeFind(school,stuhead);
				system("pause");
				system("cls");
				continue;
			case 2:
				ClassGradeFind(class);
				system("pause");
				system("cls");
				continue;
			case 3:
				StuGradeAnalyse(stuhead,ns,school);
				system("pause");
				system("cls");
				continue;
			case 4:
				GradeAppeal(stuhead,school);
				system("pause");
				system("cls");
				continue;
			case 5:
				goto start;
				break;
			case 0:
				break;
			default:
				system("cls");
				printf("无效请求，请重新输入:\n");
				continue;
			}
			break;
		}
		
		break;
	case 't':
		teacher:
		StudentLoad(&stuhead,&ns);
		while(1){
			c3 = TeacherMenu();
			system("cls");
			switch (c3) {
			case 1:
				AddStudent(&stuhead);
				system("pause");
				system("cls");
				continue;
			case 2:
				DeleteStudent(&stuhead);
				system("pause");
				system("cls");
				continue;
			case 3:
				ReviseGrades(&stuhead);
				system("pause");
				system("cls");
				continue;
			case 4:
				GradeFind(stuhead);
				system("pause");
				system("cls");
				continue;
			case 5:
				ClassGradeFind(class);
				system("pause");
				system("cls");
				continue;
			case 6:
				FileCopy();
				system("pause");
				system("cls");
				continue;
			case 7:
				GradeAnalyse(stuhead,ns);
				system("pause");
				system("cls");
				continue;
			case 8:
				//TODO
				system("pause");
				system("cls");
				continue;
			case 9:
				goto start;
				break;
			case 0:
				break;
			default:
				system("cls");
				printf("无效请求，请重新输入:\n");
				continue;
			}
			break;
		}
		break;
	case 'm':
		StudentLoad(&stuhead,&ns);
		while(1){
			system("cls");
			m = ManagerMenu();
			system("cls");
			switch (m) {
			case '1':
				while(1){
					c4= ManagerWorkMenu();
					system("cls");
					switch (c4) {
					case 1:
						RegistConfirm(&acchead);
						system("pause");
						break;
					case 2:
						ReviseAccount();
						system("pause");
						break;
					case 3:
						FindAccount();
						system("pause");
						break;
						break;
					default:
						system("cls");
						printf("无效请求，请重新输入:\n");
						continue;
					}
					break;
				}
				continue;
			case '2':
				goto teacher;
				break;
			case '3':
				AccountRegist(&acchead);
				system("pause");
				system("cls");
				continue;
			case '4':
				DeleteAccount();
				system("pause");
				system("cls");
				continue;
			case '5':
				ReviseAccount();
				system("pause");
				system("cls");
				continue;
			case '6':
				FindAccount();
				system("pause");
				system("cls");
				continue;
			case '7':
				AccountLoad(&acchead);
				printf("录入所有账号密码成功\n");
				system("pause");
				system("cls");
				continue;
			case '8':
				OutputAccount("Account.txt");
				system("pause");
				system("cls");
				continue;
			case '9':
				AddStudent(&stuhead);
				system("pause");
				system("cls");
				continue;
			case 'a':
				goto start;
				break;
			case '0':
				break;	
			default:
				system("cls");
				printf("无效请求，请重新输入:\n");
				continue;
			}
			break;
		}
		break;
	default:
		break;
	}
	
	while(acchead!=NULL)
	{
		struct accountNode *ta=acchead;
		acchead=acchead->next;
		free(ta);
	}
	while(stuhead!=NULL)
	{
		struct studentNode *ts=stuhead;
		stuhead=stuhead->next;
		free(ts);
	}
	
	return 0;
}
