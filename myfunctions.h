#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H
#define MAXLENGTH 50

struct account
{
	char name[MAXLENGTH];
	char password[MAXLENGTH];
	char role;
	char class[MAXLENGTH];
};

struct accountNode
{
	struct account acc;
	struct accountNode* next;
};

struct student
{
	char name[MAXLENGTH];
	char schoolNumber[MAXLENGTH];
	char classNumber[MAXLENGTH];
	int chinese;
	int math;
	int english;
};

struct studentNode
{
	struct student stu;
	struct studentNode* next;
};

void AccountLoad(struct accountNode **head);

int AccountLand(struct accountNode *head,char *role,char *class,char *school);

void CleanBuffer();

int StudentMenu();

void StuGradeFind(char *school,struct studentNode *head);

void StudentLoad(struct studentNode **head,int *ns);

void ClassGradeFind(char *filePath);

int compareTotalScore(const void *a, const void *b);

void ConvertClassName(char *class);

void StuGradeAnalyse(struct studentNode *head,int ns,char *school);

int TeacherMenu();

void AddStudent(struct studentNode **head);

void DeleteStudent(struct studentNode **head);

void convertClassName(const char* originalString, char* result);

void GradeFind(struct studentNode *head);

void FileCopy();

void GradeAnalyse(struct studentNode *head,int ns);

char ManagerMenu();

void AccountRegist(struct accountNode **head);

void DeleteAccount();

void ReviseAccount();

void FindAccount();

void OutputAccount(char *filename);

void GradeAppeal(struct studentNode* head, char* schoolNumber);

void ReviseGrades(struct studentNode** head);

void DisplayStudentInfo(struct studentNode* head, char* schoolNumber);

void DeleteAppeal(char *school);

int SearchStudentNumber(char *filePath,char *schoolNumber);

void ReviseStudent(struct studentNode **head,char *schoolNumber,int chinese,int math,int english);

//void AverageScores(struct student* head);
//
//void TeacherScoreAnaly(struct student* head);
//
//void PrintTopStudents(struct student* head, int subject, int count);
//
//void SelectionSort(struct student* head, int subjectChoice, int orderChoice);

void Regist(struct accountNode *head);

void displayAccountsFromFile();

void insertAccountToList(struct accountNode** head, struct account acc);

void deleteAccountFromFile(const char* username);

void RegistConfirm(struct accountNode** head);

int ManagerWorkMenu();

#endif
