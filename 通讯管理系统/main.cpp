#include <iostream>
using namespace std;
#include <string>
#define max 1000
struct person
{
	string name;
	string sex;
	short age;
	string telephone;
	string address;
};
struct contacts
{
	struct person persoArray[max];
	int size;
};

//添加联系人
void addPerson(contacts* abs)
{
	if (abs->size == max)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else
	{
		cout << "请输入联系人的姓名：" << endl;
		cin >> abs->persoArray[abs->size].name;
		cout << "请输入联系人的性别：" << endl;
		cin >> abs->persoArray[abs->size].sex;
		cout << "请输入联系人的年龄：" << endl;
		cin >> abs->persoArray[abs->size].age;
		cout << "请输入联系人的家庭地址：" << endl;
		cin >> abs->persoArray[abs->size].address;
		cout << "请输入联系人的电话号码：" << endl;
		cin >> abs->persoArray[abs->size].telephone;
		abs->size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}


//显示联系人
void showPerson(contacts* abs)
{
	if (abs->size == 0)
	{
		cout << "通讯录为空！" << endl;
	}
	else
	{
		for (short i = 0; i < abs->size; i++)
		{
			cout << abs->persoArray[i].name << "\t" << abs->persoArray[i].age << "\t" << abs->persoArray[i].sex << "\t" <<
				abs->persoArray[i].address << "\t" << abs->persoArray[i].telephone << "\t" << endl;
		}
	}
	system("pause");
	system("cls");
}


//判断联系人是否存在
int isExist(contacts* abs, string name)
{
	for (short i = 0; i < abs->size; i++)
	{
		if (abs->persoArray[i].name == name)
		{
			return i;
		}
	}
	return -1;
}


//删除联系人
void deletePerson(contacts* abs)
{
	string name;
	cout << "请输入联系人姓名：";
	cin >> name;
	short rea = isExist(abs, name);
	cout << ((rea != -1) ? "联系人存在！" : "联系人不存在！") << endl;
	if (rea != -1)
	{
		for (short i = rea; i < abs->size; i++)
		{
			if (abs->persoArray[i].name == name)
			{
				abs->persoArray[i] = abs->persoArray[i + 1];
			}
		}
		abs->size--;
		cout << "删除成功！" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(contacts* abs)
{
	string name;
	cout << "请输入联系人姓名：";
	cin >> name;
	short rea = isExist(abs, name);
	cout << ((rea != -1) ? "联系人存在！" : "联系人不存在！") << endl;
	if (rea != -1)
	{
		for (short i = 0; i < abs->size; i++)
		{
			if (abs->persoArray[i].name == name)
			{
				cout << abs->persoArray[i].name << "\t" << abs->persoArray[i].age << "\t" << abs->persoArray[i].sex << "\t" <<
					abs->persoArray[i].address << "\t" << abs->persoArray[i].telephone << "\t" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

//修改联系人
void revisePerson(contacts* abs)
{
	string name;
	string rename;
	string address;
	string telephone;
	short  age = 0;
	string sex;
	cout << "请输入联系人姓名：";
	cin >> name;
	short rea = isExist(abs, name);
	cout << ((rea != -1) ? "联系人存在！" : "联系人不存在！") << endl;
	if (rea != -1)
	{
		for (short i = 0; i < abs->size; i++)
		{
			if (abs->persoArray[i].name == name)
			{
				cout << "请输入修改后的联系人姓名：";
				cin >> rename;
				abs->persoArray[i].name = rename;
				cout << "请输入修改后的联系人年龄：";
				cin >> age;
				abs->persoArray[i].age = age;
				cout << "请输入修改后的联系人性别：";
				cin >> sex;
				abs->persoArray[i].sex = sex;
				cout << "请输入修改后的联系人地址：";
				cin >> address;
				abs->persoArray[i].address = address;
				cout << "请输入修改后的联系人电话号码：";
				cin >> telephone;
				abs->persoArray[i].telephone = telephone;
				cout<<"修改后的联系人信息为：\n" << abs->persoArray[i].name << "\t" << abs->persoArray[i].age 
					<< "\t" << abs->persoArray[i].sex << "\t" <<abs->persoArray[i].address << "\t" <<abs->persoArray[i].telephone << "\t" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

//清空联系人
void emptyPerson(contacts* abs)
{
	cout << "确定的要清空吗？确定清空请按1，取消请按2" << endl;
	short i = 0;
	cin >> i;
	if (i == 1)
	{
		abs->size = 0;
		cout << "清空完成！" << endl;
	}
	else
	{
		cout << "取消成功！" << endl;
	}
	system("pause");
	system("cls");
}

/*主界面*/
void showMenu()
{
	cout << "*****通讯管理系统*****" << endl;
	cout << "***  1.添加联系人  ***" << endl;
	cout << "***  2.显示联系人  ***"<< endl;
	cout << "***  3.删除联系人  ***" << endl;
	cout << "***  4.查找联系人  ***" << endl;
	cout << "***  5.修改联系人  ***" << endl;
	cout << "***  6.清空联系人  ***" << endl;
	cout << "***  0.返回主菜单  ***" << endl;
	cout << "**********************" << endl;
}
/*主函数*/
int main()
{
	contacts abs;
	abs.size = 0;
	while (true)
	{
	    short select = 0;	
		showMenu();
		cin >>select;
		switch (select)
		{
		case 1:addPerson(&abs);//1.添加联系人
			break;
		case 2:showPerson(&abs);//2.显示联系人
			break;
		case 3:deletePerson(&abs);//3.删除联系人
			break;
		case 4:findPerson(&abs);//4.查找联系人
			break;
		case 5:revisePerson(&abs);//5.修改联系人
			break;
		case 6:emptyPerson(&abs);//6.清空联系人
			break;
		case 0:cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;//0.返回主菜单
			break;
		default:
			break;
		}
	}
}