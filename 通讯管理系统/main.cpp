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

//�����ϵ��
void addPerson(contacts* abs)
{
	if (abs->size == max)
	{
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else
	{
		cout << "��������ϵ�˵�������" << endl;
		cin >> abs->persoArray[abs->size].name;
		cout << "��������ϵ�˵��Ա�" << endl;
		cin >> abs->persoArray[abs->size].sex;
		cout << "��������ϵ�˵����䣺" << endl;
		cin >> abs->persoArray[abs->size].age;
		cout << "��������ϵ�˵ļ�ͥ��ַ��" << endl;
		cin >> abs->persoArray[abs->size].address;
		cout << "��������ϵ�˵ĵ绰���룺" << endl;
		cin >> abs->persoArray[abs->size].telephone;
		abs->size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}


//��ʾ��ϵ��
void showPerson(contacts* abs)
{
	if (abs->size == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
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


//�ж���ϵ���Ƿ����
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


//ɾ����ϵ��
void deletePerson(contacts* abs)
{
	string name;
	cout << "��������ϵ��������";
	cin >> name;
	short rea = isExist(abs, name);
	cout << ((rea != -1) ? "��ϵ�˴��ڣ�" : "��ϵ�˲����ڣ�") << endl;
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
		cout << "ɾ���ɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(contacts* abs)
{
	string name;
	cout << "��������ϵ��������";
	cin >> name;
	short rea = isExist(abs, name);
	cout << ((rea != -1) ? "��ϵ�˴��ڣ�" : "��ϵ�˲����ڣ�") << endl;
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

//�޸���ϵ��
void revisePerson(contacts* abs)
{
	string name;
	string rename;
	string address;
	string telephone;
	short  age = 0;
	string sex;
	cout << "��������ϵ��������";
	cin >> name;
	short rea = isExist(abs, name);
	cout << ((rea != -1) ? "��ϵ�˴��ڣ�" : "��ϵ�˲����ڣ�") << endl;
	if (rea != -1)
	{
		for (short i = 0; i < abs->size; i++)
		{
			if (abs->persoArray[i].name == name)
			{
				cout << "�������޸ĺ����ϵ��������";
				cin >> rename;
				abs->persoArray[i].name = rename;
				cout << "�������޸ĺ����ϵ�����䣺";
				cin >> age;
				abs->persoArray[i].age = age;
				cout << "�������޸ĺ����ϵ���Ա�";
				cin >> sex;
				abs->persoArray[i].sex = sex;
				cout << "�������޸ĺ����ϵ�˵�ַ��";
				cin >> address;
				abs->persoArray[i].address = address;
				cout << "�������޸ĺ����ϵ�˵绰���룺";
				cin >> telephone;
				abs->persoArray[i].telephone = telephone;
				cout<<"�޸ĺ����ϵ����ϢΪ��\n" << abs->persoArray[i].name << "\t" << abs->persoArray[i].age 
					<< "\t" << abs->persoArray[i].sex << "\t" <<abs->persoArray[i].address << "\t" <<abs->persoArray[i].telephone << "\t" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ��
void emptyPerson(contacts* abs)
{
	cout << "ȷ����Ҫ�����ȷ������밴1��ȡ���밴2" << endl;
	short i = 0;
	cin >> i;
	if (i == 1)
	{
		abs->size = 0;
		cout << "�����ɣ�" << endl;
	}
	else
	{
		cout << "ȡ���ɹ���" << endl;
	}
	system("pause");
	system("cls");
}

/*������*/
void showMenu()
{
	cout << "*****ͨѶ����ϵͳ*****" << endl;
	cout << "***  1.�����ϵ��  ***" << endl;
	cout << "***  2.��ʾ��ϵ��  ***"<< endl;
	cout << "***  3.ɾ����ϵ��  ***" << endl;
	cout << "***  4.������ϵ��  ***" << endl;
	cout << "***  5.�޸���ϵ��  ***" << endl;
	cout << "***  6.�����ϵ��  ***" << endl;
	cout << "***  0.�������˵�  ***" << endl;
	cout << "**********************" << endl;
}
/*������*/
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
		case 1:addPerson(&abs);//1.�����ϵ��
			break;
		case 2:showPerson(&abs);//2.��ʾ��ϵ��
			break;
		case 3:deletePerson(&abs);//3.ɾ����ϵ��
			break;
		case 4:findPerson(&abs);//4.������ϵ��
			break;
		case 5:revisePerson(&abs);//5.�޸���ϵ��
			break;
		case 6:emptyPerson(&abs);//6.�����ϵ��
			break;
		case 0:cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;//0.�������˵�
			break;
		default:
			break;
		}
	}
}