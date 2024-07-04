#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <cmath>
using namespace std;

struct user_type
{
	string username;
	string password;
	bool isAdmin;
	bool authorized = 1;
};
user_type user[10000];

struct report_type {
	string location;
	string type;
	string health_situation;
	string description;
	bool  isAdopted;
	int report_user_idx, adoption_user_idx, isConfirmed;
} report[10000];

fstream Users;
fstream reportsFile;
fstream reportsNumberFile;
int idxOfUser = 0;
int MaxUsersIdx = -1;
int reportsNum = 0;
int animalsNum = 0;
int totalDonations = 0;
int adminsNum = 1;
long long donation[10000];
bool isUserMenuReq = 0;
bool isAdminMenuReq = 0;
string weakPasswords_arr[10000];
string tempUsername;
bool removeSelf = 0;

void adoption();
void editReport();
void user_history();
void userMenu();
void change();
void checklists();
void newAnimal();
void addRevAdmin();
void banuser();
void Confirm();
void AdminMenu();
bool isNewUsername(string& Newusername);
bool isCorrectSize(string& password);
bool UsernameSignInCheck();
bool CurrentPasswordCheck();
bool NewPasswordCheck(bool isSignUp);
bool NewUsernameCheck();
bool UsernameSignUpCheck();
void signUp();
void logIn();
void changeUsername();
void changePassword();
void FilestoArray_users();
void ArraytoFiles_users();
void FilestoArray_weakPasswords();
bool isWeak(string& password);
void hashing(string& password);
void toFile_reports();
void fromFile_reports();
void store_num_of_reports();
void how_many_reports();
void addToFile_donation();
void addToArray_donation();
void exitFun();

int main()
{/*
	how_many_reports();
	fromFile_reports();
	addToArray_donation();
	FilestoArray_users();
	FilestoArray_weakPasswords();*/

	char choice;

	do
	{
		system("cls");
		isAdminMenuReq = 0;
		isUserMenuReq = 0;
		removeSelf = 0;

		cout << "WELCOME !!\n";

		do
		{
			cout << "press 1 -> logIn \n press 2 -> signUp \n press 3 -> exit \n";
			cin >> choice;
			cin.ignore();

			if (choice == '1')
				logIn();
			else if (choice == '2')
				signUp();
			else if (choice == '3')
				exitFun();
			else
			{
				system("cls");
				cout << "INVALID CHOICE\n";
			}


		} while (choice != '1' && choice != '2' && choice != '3');

		if (isAdminMenuReq)
		{
			AdminMenu();
			isAdminMenuReq = 0;
		}
		else if (isUserMenuReq)
		{
			userMenu();
			isUserMenuReq = 0;
		}


	} while (!isAdminMenuReq && !isUserMenuReq);

	return 0;




}

void adoption()
{
	system("cls");
	int choice_;
	cout << "WHAT DO YOU WANT EXACTLT___";
	cout << "1- JUST TAKE A LOOK AT ANIMALS ";
	cout << "2- TAKE A LOOK AND ADOPT ONE";
	cin >> choice_;
	if (choice_ == 1)
	{
		for (int i = 0; i < reportsNum; i++)
		{
			if (report[i].isConfirmed == 1 && report[i].isAdopted == false)

				cout << i + 1 << "- " << report[i].type + "\t\t" << report[i].location + "\t\t" << report[i].health_situation + "\t\t" << report[i].description << "\n";
		}
	}
	else if (choice_ == 2)
	{
		for (int i = 0; i <= reportsNum; i++)
		{
			if (report[reportsNum].isConfirmed == 1 && report[i].isAdopted == false)
				cout << i + 1 << "- " << report[i].type << report[i].location << report[i].health_situation << report[i].description << "\n";
		}
		cout << "PLEASE,TELL US WHICH ONE YOU HAVE DECIDED TO ADOPT ";
		int adopteton_choice;
		cin >> adopteton_choice;
		for (int i = 0; i <= reportsNum; i++)
		{

			if (i == adopteton_choice - 1) {

				report[i].isAdopted = true;
				report[i].adoption_user_idx = idxOfUser;
			}
		}

	}
}

void editReport() {
	char ch;
	do
	{
		int num = 1;
		int save_rpt[100];

		int count = 0;
		for (int i = 0; i <= reportsNum; i++)
		{
			if (report[i].report_user_idx == idxOfUser) {
				cout << num << "- " << report[i].type + "\t\t" << report[i].location + "\t\t" << report[i].health_situation + "\t\t" << report[i].description << endl;
				num++;
				save_rpt[count] = i;
				count++;
			}
		}
		if (count == 0) {
			cout << "SORRY! YOU HAVE NOT ADD ANY REPORT BEFORE";
			break;
		}
		cout << "which one do u want to change ";
		int re_choice;
		cin >> re_choice;
		if (re_choice <= count) {
			//re_choice = idxOfUser;
			cout << "which part do u want to change--\n 1- type\n 2- location\n 3- health situation\n 4- description\n ";
			int edit_choice;
			cin >> edit_choice;
			if (edit_choice == 1)
			{
				cout << "What is the type of the animal?\n";
				cin >> report[save_rpt[re_choice - 1]].type;
				//report[save_rpt[count]].type = report[save_rpt[re_choice - 1]].type;
			}
			else if (edit_choice == 2)
			{
				cout << "What is the location of the animal?\n";
				cin >> report[save_rpt[re_choice - 1]].location;
				//report[save_rpt[count]].location = report[save_rpt[re_choice - 1]].location;
			}
			else if (edit_choice == 3)
			{
				cout << "What is the health situation of the animal?\n";
				cin >> report[save_rpt[re_choice - 1]].health_situation;
				//report[save_rpt[count]].health_situation = report[save_rpt[re_choice - 1]].health_situation;
			}
			else if (edit_choice == 4)
			{
				cout << "What is the descrption of the animal?\n";
				cin >> report[save_rpt[re_choice - 1]].health_situation;
				//report[save_rpt[count]].description = report[save_rpt[re_choice - 1]].description;
			}
		}

		cout << "\nDo you want to edit another report (enter y/Y) ? ";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	cout << "---------------------------\n";
	system("pause");
}

void user_history()
{
	int n, c = 0;
	char ch;
	do
	{
		int n, c = 0;
		cout.width(78);
		cout << "C H E C K I N G  L I S T S!\n\n";
		cout << "1-All the animal I have adopted\n\n";
		cout << "2- My reports I have made.\n\n";
		cout << "3-All Donations.\n\n";
		cout << "------------------------\n";
		cout << "Which list do you want to view (1-3) ? \n"; cin >> n;
		switch (n)
		{
		case 1:
			system("cls");
			for (int i = 0; i <= reportsNum; i++)
			{
				if (report[i].adoption_user_idx == idxOfUser)
				{
					c++;
					cout << c << " and your report is num:" << i + 1 << "in our system" << report[i].type + "\t\t" << report[i].location + "\t\t" << report[i].health_situation + "\t\t" << report[i].description << endl;
				}
			}
			if (c == 0)
				cout << "you have not adopted before";
			break;
		case 2:
			system("cls");
			for (int i = 0; i <= reportsNum; i++)
			{
				if (report[i].report_user_idx == idxOfUser)
				{
					c++;
					cout << c << report[i].type + "\t\t" << report[i].location + "\t\t" << report[i].health_situation + "\t\t" << report[i].description << endl;
				}
			}
			if (c == 0)
				cout << "you have not added report before";
			break;
		case 3:
			system("cls");
			//donation
		default:
			break;
		}

		cout << "\n IF YOU WANT TO SEE ANYTHING ELSE IN YOUR HISTORY (enter y/Y) ? ";
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	cout << "---------------------------\n";


}

void userMenu()
{
	////Testing
	//reportsNum = 3;
	//report[0].type = "Cat";
	//report[0].location = "Cairo";
	//report[0].health_situation = "Broken leg";
	//report[0].description = "White with brown spots";
	//report[0].report_user_idx = 1;
	//report[0].report_user_idx = 1;
	//report[0].isAdopted = 0;
	//report[0].isConfirmed = 1;
	//user[0].isAdmin = 0;
	//report[1].type = "dog";
	//report[1].location = "alex";
	//report[1].health_situation = "great";
	//report[1].description = "black";
	//report[1].report_user_idx = 2;
	//report[1].report_user_idx = 2;
	//report[1].isAdopted = 0;
	//report[1].isConfirmed = 1;
	//user[1].isAdmin = 0;
	///////////////
	//report[2].type = "bird";
	//report[2].location = "giza";
	//report[2].health_situation = "Healthy";
	//report[2].description = "yellow";
	//report[2].report_user_idx = 13;
	////idxOfUser = 13;
	//report[2].isConfirmed = -1;
	//report[2].isAdopted = 0;
	//report[2].adoption_user_idx = 4;
	//user[2].isAdmin = 1;



	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);


	cout << "-------------------------------------------------------------------\n Welcome  to your menue\n------------------------------------------------------------------- ";
	short int i;

	string menuList[7] = { "See  all the animals in the shelter and you can adopt any one if you want","If you want to donate","If you see an animal that needs help, send us a report report,please or if you want to edit an earlier one ","change passord/usernmae","see my history","chat","Exit" };
	int menuNum;
	do {
		system("cls");
		for (int i = 1; i <= 7; i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << "\n\n" << "\t\t" << i << "- " << menuList[i - 1] << "\n";
		}

		cout << "\n\n\t How Can we Help You ?  ";
		cin >> menuNum;
		switch (menuNum)
		{
		case 1:
			//see animals and adopt
			system("cls");
			adoption();
			system("pause");
			break;

		case 2:

			//donation
		case 3:
			system("cls");
			cout << "WHAT DO YOU WANT EXACTLT___";
			cout << "1- ADD ONE";
			cout << "2- EDIT ONE";
			int choice_;
			cin >> choice_;
			if (choice_ == 1)
			{
				// add 
				newAnimal();
				cout << "\nAnimals added! :) \nThank you for your help <3\n";
			}
			else if (choice_ == 2)
			{
				//edit
				editReport();
			}
			system("pause");
			break;
		case 4:
			change();
			break;
		case 5:
			//see history
			user_history();
			break;
		case 6:
			//chat
		case 7:
			system("cls");
			return;
		default:
			break;
		}
	} while (menuNum != 9);
}

void change()
{
	system("cls");
	int no;
	bool changed = false;
	while (changed == false)
	{
		cout << endl;
		cout.width(91);
		cout << "C H A N G E  U S E R N A M E  A N D  P A S S W O R D :\n";
		cout.width(92);
		cout << "~~~~~~~~~~~~~~~~~~~\n\n";
		cout << "1-Change username\n\n2-Change password\n\n";
		cout << "Which one do you want to Change(1/2)? "; cin >> no;
		cout << "~~~~~~~~~~~~~~\n\n";
		if (no == 1)
		{
			changeUsername();
			changed = true;
		}
		else if (no == 2)
		{
			changePassword();
			changed = true;
		}
		else
		{
			cout << "Invalid choice";
			changed = false;
		}

	}
	system("pause");
}

void checklists()
{
	system("cls");
	int x;
	bool rightchoice = false;
	cout << endl;
	cout.width(78);
	cout << "C H E C K I N G  L I S T S!\n\n";
	cout << "1-Reports (Confirmed,Denied and Pending)\n\n";
	cout << "2-Adopted animals and whom they were adopted by.\n\n";
	cout << "3-All Donations made by users.\n\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Which list do you want to view (1-3) ? \n"; cin >> x;
	switch (x)
	{
	case 1:
		system("cls");
		cout << "\nLists of confirmed, denied and pending reports: \n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout << "CONFIRMED REPORTS: \n\n";
		cout << "Type:\tLocation:\tHealth situation:\tDescription:\n";
		for (int i = 0; i <= reportsNum; i++)
		{
			if (report[i].isConfirmed == 1)
				cout << report[i].type << "\t" << report[i].location << "\t\t" << report[i].health_situation << "\t\t" << report[i].description << "\n";
		}
		cout << endl << "--------------------\n";
		cout << "DENIED REPORTS: \n\n";
		cout << "Type:\tLocation:\tHealth situation:\tDescription:\n";
		for (int i = 0; i <= reportsNum; i++)
		{
			if (report[i].isConfirmed == 0)
				cout << report[i].type << "\t" << report[i].location << "\t\t" << report[i].health_situation << "\t\t" << report[i].description << "\n";
		}
		cout << endl << "--------------------\n";
		cout << "PENDING REPORTS: \n\n";
		cout << "Type:\tLocation:\tHealth situation:\tDescription:\n";
		for (int i = 0; i <= reportsNum; i++)
		{
			if (report[i].isConfirmed == -1)
				cout << report[i].type << "\t" << report[i].location << "\t\t" << report[i].health_situation << "\t\t" << report[i].description << "\n";
		}
		cout << endl << "--------------------\n";
		rightchoice = true;
		system("pause");
		break;
	case 2:
		system("cls");
		cout << "\n";
		cout.width(78);
		cout << "A D O P T E D  A N I M A L S <3\n";
		cout.width(79);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
		cout << "ADOPTED ANIMAL:\t\tADOPTED BY USER:\t\tLOCATION:\t\tHealth situation:\t\tDescription\n";
		cout << "------------------------------------------------------------------------------------------------------------------------------------------\n";
		for (int i = 0; i <= reportsNum; i++)
		{
			if (report[i].isAdopted == 1)
			{
				cout << report[i].type; cout << "\t\t\t" << report[i].adoption_user_idx << "\t\t\t    " << report[i].location; cout << "\t\t\t"
					<< report[i].health_situation << "    \t\t" << report[i].description; cout << "\n";
				cout << "------------------------------------------------------------------------------------------------------------------------------------------\n";

			}
		}

		//cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		rightchoice = true;
		system("pause");
		break;
	case 3:
		system("cls");
		cout << "Donations made by users:\n";
		//Donation function 
		rightchoice = true;
		break;
	default:
		cout << "Please enter a valid choice!";

	}

}

void newAnimal()
{
	char choice;
	do
	{
		system("cls");
		cout << "\n";
		cout.width(80);
		cout << "A D D  N E W  A N I M A L S  T O  A D O P T !\n";
		cout.width(80);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		reportsNum++;
		int type, location;
		bool typeAdded = false, locationAdded = false;
		while (typeAdded == false)
		{
			cout << "Animal type:\n 1-Dog\n 2-Cat\n 3-Bird\n 4-Hamster\n 5-Monkey\n 6-Other\n Animal type no: "; cin >> type;
			switch (type)
			{
			case 1:
				report[reportsNum].type = "Dog";
				typeAdded = true;
				break;
			case 2:
				report[reportsNum].type = "Cat";
				typeAdded = true;
				break;
			case 3:
				report[reportsNum].type = "Bird";
				typeAdded = true;
				break;
			case 4:
				report[reportsNum].type = "Hamster";
				typeAdded = true;
				break;
			case 5:
				report[reportsNum].type = "Monkey";
				typeAdded = true;
				break;
			case 6:
				cout << "What is the type of the animal?\n";
				cin >> report[reportsNum].type;
				typeAdded = true;
				break;
			default:
				cout << "Please enter a valid choice!\n";
			}
		}

		while (locationAdded == false)
		{
			system("cls");
			cout << "\n";
			cout.width(80);
			cout << "A D D  N E W  A N I M A L S  T O  A D O P T !\n";
			cout.width(80);
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

			cout << "Locations:\n 1-Cairo\n 2-Giza\n 3-Alexandria\n 4-Hurghada\n 5-Aswan\n 6-Port Said\n 7-Other\n Location number: "; cin >> type;
			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			switch (type)
			{
			case 1:
				report[reportsNum].location = "Cairo";
				locationAdded = true;
				break;
			case 2:
				report[reportsNum].location = "Giza";
				locationAdded = true;
				break;
			case 3:
				report[reportsNum].location = "Alexandria";
				locationAdded = true;
				break;
			case 4:
				report[reportsNum].location = "Hurghada";
				locationAdded = true;
				break;
			case 5:
				report[reportsNum].location = "Aswan";
				locationAdded = true;
				break;
			case 6:
				report[reportsNum].location = "Port Said";
				locationAdded = true;
				break;
			case 7:
				cout << "What is the location of the animal?\n";
				cin >> report[reportsNum].location;
				locationAdded = true;
				break;
			default:
				cout << "\nPlease enter a valid choice!\n\n";
				locationAdded = false;
				system("pause");
			}
		}
		system("cls");
		cout << "\n";
		cout.width(80);
		cout << "A D D  N E W  A N I M A L S  T O  A D O P T !\n";
		cout.width(80);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

		cout << "Health situation: "; cin >> report[reportsNum].health_situation;
		cout << "Description: "; cin >> report[reportsNum].description;
		/*report[reportsNum].isConfirmed = 1;
		report[reportsNum].isAdopted = 0; */
		if (user[idxOfUser].isAdmin == true)
		{
			report[reportsNum].isConfirmed = 1;
			report[reportsNum].report_user_idx = idxOfUser;
		}
		else
		{
			report[reportsNum].isConfirmed = -1;
			report[reportsNum].report_user_idx = idxOfUser;
		}
		cout << "\nDo you want to add another animal (enter y/Y) ? ";
		cin >> choice;

	} while (choice == 'Y' || choice == 'y');
	cout << "~~~~~~~~~~~~~~~~~~~~\n";
	system("pause");
}

void addRevAdmin()
{
	system("cls");
	int y, count = 0;
	bool choice = false;
	string adminName;
	cout << "\n";
	while (choice == false)
	{
		system("cls");
		cout.width(91);
		cout << "A D D I N G  O R  R E M O V I N G  A N  A D M I N !\n";
		cout.width(92);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout << "1- ADD admin\n\n2-REMOVE admin\n\nChoice number: "; cin >> y; cout << "\n";
		string name;
		bool Userfound = 0;
		switch (y)
		{
		case 1:
			cout << "Adding an admin...\n\n";
			cout << "Enter the username: "; cin >> name;
			for (int i = 0; i <= MaxUsersIdx; i++)
			{
				if (user[i].username == name)
				{
					user[i].isAdmin = 1;
					Userfound = 1;
					adminsNum++;
					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
					cout << "\nAdmin added successfully :) !\n";
					choice = true;
					break;
				}
			}
			if (Userfound == 0)
			{
				cout << "No user exists with this name!\n";
				system("pause");
			}
			break;

		case 2:
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "Removing an admin...\n\n";
			cout << "Enter the username of the admin you want to remove: "; cin >> adminName;
			for (int i = 0; i <= MaxUsersIdx; i++)
			{
				if (user[i].username == adminName)
				{
					if (adminsNum > 1)
					{
						user[i].isAdmin = 0;
						cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
						cout << "\nAdmin removed successfully!\n";
						if (user[idxOfUser].username == adminName)
						{
							removeSelf = 1;
						}
						count++;
						adminsNum--;
					}
					else
					{
						cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
						cout << "\nCan't remove admin! Atleast one admin should exist!\n";
						count++;
					}
				}
			}
			if (count == 0)
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "\nNo admin exists with this name!\n";
			choice = true;
			break;
		default:
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "\nPlease enter a valid choice :/\n\n";

		}
	}
	system("pause");
}

void banuser()
{
	system("cls");
	int count = 0;
	string username;
	cout << "\n";
	cout.width(75);
	cout << "B A N N I N G  A  U S E R !\n";
	cout.width(75);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Banning user...\n\n";
	cout << "Enter the username of the user you want to ban: "; cin >> username;
	for (int i = 0; i <= MaxUsersIdx; i++)
	{
		if (user[i].username == username)
		{
			if (user[i].isAdmin == 0)
			{
				count++;
				user[i].authorized = 0;
				cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
				cout << "User has been banned!\n";
			}
		}
	}
	if (count == 0)
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "No user exists with this name!\n";
	}
	system("pause");
}

void Confirm()
{
	int n, c, d;
	int count = 0;
	int idx[10000];

	for (int i = 0; i <= reportsNum; i++)
	{
		if (report[i].isConfirmed == -1)
		{
			cout << count + 1 << "-" << report[i].type << "\t\t\t\t" << report[i].report_user_idx << "\t\t\t\t" << report[i].location << "\t\t\tHealth situation: "
				<< report[i].health_situation << "\n\t\t\t\t\t\t\t\t\t\t\tDescription: " << report[i].description << "\n\n";

			idx[count] = i;
			count++;
		}
	}

	do {
		cout << "what do you want 1- confirm 2 -Deny ";
		cin >> n;
		if (n == 1)
		{
			cout << "Enter the number of the report you want to confirm: \n ";
			cin >> c;
			report[idx[c - 1]].isConfirmed = 1;

			////if (c >= 1 && c <= 10000)
			//{
			//	report[idx[c - 1]].isConfirmed = 1;
			//}
			//else
			//{
			//	cout << "EE";
			//	continue;
			//}


		}
		else if (n == 2)
		{
			cout << "Enter the number of the report you want to deny: \n ";
			cin >> d;
			report[idx[d - 1]].isConfirmed = 0;

		}
		else
			cout << "Enter a valid option\n";
	} while (n != 1 && n != 2);
}

void AdminMenu()
{

	////Testing
	//report[10].type = "Cat";
	//report[10].location = "Cairo";
	//report[10].health_situation = "Broken leg";
	//report[10].description = "White with brown spots";
	//report[10].report_user_idx = 12;
	//report[10].isConfirmed = -1;
	//report[10].isAdopted = 1;
	//report[10].adoption_user_idx = 13;

	////Testing
	//user[0].username = "Jana";
	//user[0].password = "1233";
	//user[0].isAdmin = 1;

	////Testing
	//report[1].type = "Dog";
	//report[1].location = "Alexandria";
	//report[1].health_situation = "Healthy";
	//report[1].description = "Black";
	//report[1].report_user_idx = 13;
	//report[1].isConfirmed = -1;
	//report[1].isAdopted = 1;
	//report[1].adoption_user_idx = 4;

	////Testing
	//user[1].username = "Ja";
	//user[1].isAdmin = 1;

	system("cls");
	int choice;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	bool option = false;
	while (option == false)
	{
		do
		{
			system("cls");
			cout << "\n";
			cout << "                                               WELCOME TO PAWS 'N' CLAWS <3                     \n";
			cout << "                                                    Happy to see you :)                       \n\n";
			cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << " |                    MENU                      |\n";
			cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "  1- CHECK the lists of reports, adopted animals and donations.\n";
			cout << "  2- CHECK the reports to be Accepted/Denied.\n";
			cout << "  3- ADD new animals to adopt.\n";
			cout << "  4- CHANGE username/password.\n";
			cout << "  5- MAKE/REMOVE an admin.\n";
			cout << "  6- BAN users.                \n";
			cout << "  7- CHAT.\n";
			cout << "  8- LOG OUT. \n";
			cout << " How can we help (1-8) ? "; cin >> choice;


			switch (choice)
			{
			case 1:
				checklists();
				break;
			case 2:
				system("cls");
				cout << "\n";
				cout.width(90);
				cout << "A C C E P T  O R  D E N Y  A N  A N I M A L!\n";
				cout.width(92);
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
				cout << "Reported animal:\t\tReported by user:\t\tLocation:\t\tDetials:\n";
				Confirm();
				system("pause");
				break;
			case 3:
				newAnimal();
				cout << "\nAnimals added! :) \nThank you for your help <3\n";
				break;
			case 4:
				change();
				system("cls");
				break;
			case 5:
				addRevAdmin();
				if (removeSelf)
					return;
				break;
			case 6:
				banuser();
				break;
			case 7:
				//Chat function
				// Testing function: editReport();
				break;
			case 8:
				system("cls");
				cout << "\n\n";
				cout.width(75);
				cout << "Logged out successfully!\n\n";
				cout.width(81);
				cout << "Thank you for using Paws 'N' Claws!\n\n";
				cout.width(79);
				cout << "Hope you have a great day < 3\n\n";
				system("pause");
				return;
			case 9:
				//exit function
				exit(0);
			default:
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cout << "Please enter a valid choice :/\n";
				system("pause");


			}

		} while (true);
	}




}

bool isNewUsername(string& Newusername)
{
	for (int i = 0; i <= MaxUsersIdx; i++)
	{
		if (Newusername == user[i].username)
			return 0;
	}

	return 1;
}

bool isCorrectSize(string& password)
{
	if (password.size() < 8 || password.size() > 20)
		return 0;

	return 1;
}

bool UsernameSignInCheck()
{
	string login_Username, ErrorType;
	bool UsernameisCorrect = 0, isBanned = 0, returnTomain = 0;
	char choice;

	do
	{
		system("cls");
		cout << "Enter Username : ";
		getline(cin, login_Username);

		for (int j = 0; j <= MaxUsersIdx; j++)
		{
			if (login_Username == user[j].username)
			{
				if (user[j].authorized == 0)
				{
					isBanned = 1;
					break;
				}

				idxOfUser = j;
				UsernameisCorrect = 1;
				break;
			}

		}

		if (isBanned)
			ErrorType = "User is not authorized";
		else if (!UsernameisCorrect)
			ErrorType = "Username is incorrect";

		if (!UsernameisCorrect || isBanned)
		{
			system("cls");
			cout << ErrorType << "\n\n";
			cout << "Choose operation:-\n";
			cout << "1-Reenter username\n";
			cout << "2-Return to previous menu\n\n";
			cout << "Your choice : ";
			do
			{
				cin >> choice;
				if (choice == '1')
				{
					cin.ignore();
					login_Username.clear();
				}
				else if (choice == '2')
					returnTomain = 1;
				else
				{
					system("cls");
					cout << "Invalid Choice\n\n";
					cout << "Choose operation:-\n";
					cout << "1-Reenter username\n";
					cout << "2-Return to previous menu\n\n";
					cout << "Your choice : ";
				}
			} while (choice != '1' && choice != '2');

		}

	} while (!UsernameisCorrect && (!returnTomain || isBanned));

	if (returnTomain)
		return 1;
	else
		return 0;

}

bool CurrentPasswordCheck()
{
	string inPassword = "";
	char inChar;
	bool isCorrectPassword = 0, returnTomain = 0;
	char choice;

	do
	{
		system("cls");
		cout << "Enter password : ";
		inChar = _getch();
		inPassword += inChar;

		while (inChar != '\r')
		{
			cout << "*";
			inChar = _getch();

			if (inChar != '\r')
				inPassword += inChar;
		}

		if (isCorrectSize(inPassword))
			hashing(inPassword);

		if (user[idxOfUser].password != inPassword)
		{
			system("cls");
			cout << "Password in incorrect\n\n";
			cout << "Choose operation:-\n";
			cout << "1-Reenter password\n";
			cout << "2-Return to previous menu\n\n";
			cout << "Your choice : ";
			do
			{
				cin >> choice;
				if (choice == '1')
					inPassword.clear();
				else if (choice == '2')
					returnTomain = 1;
				else
				{
					system("cls");
					cout << "Invalid Choice\n\n";
					cout << "Choose operation:-\n";
					cout << "1-Reenter password\n";
					cout << "2-Return to previous menu\n\n";
					cout << "Your choice : ";
				}
			} while (choice != '1' && choice != '2');
		}
		else
		{
			isCorrectPassword = 1;
			break;
		}

	} while (!isCorrectPassword && !returnTomain);

	if (returnTomain)
		return 1;
	else
		return 0;
}

bool NewPasswordCheck(bool isSignUp)
{

	string newPassword = "", ErrorType;
	char inChar;
	bool isValidNewPassword = 0, returnToMenu = 0, containSpaces = 0;
	char choice;

	do
	{
		system("cls");
		cout << "Enter New Password : ";
		inChar = _getch();
		newPassword += inChar;

		while (inChar != '\r')
		{
			cout << "*";
			inChar = _getch();

			if (inChar != '\r')
				newPassword += inChar;
		}

		for (int i = 0; i < newPassword.size(); i++)
		{
			if (newPassword[i] == ' ')
			{
				containSpaces = 1;
				break;
			}
		}

		if (!isCorrectSize(newPassword) || containSpaces)
			ErrorType = "Password must me between 8 and 20 charcters and it can not contain spaces.";
		else if (isWeak(newPassword) || (newPassword == user[idxOfUser].username && isSignUp == 0) || (newPassword == tempUsername && isSignUp == 1))
			ErrorType = "Password is too weak or common.";
		else
			isValidNewPassword = 1;

		if (!isValidNewPassword)
		{
			system("cls");
			cout << ErrorType << " Choose Another Password\n\n";
			cout << "Choose operation:-\n";
			cout << "1-Reenter password\n";
			cout << "2-Return to previous menu\n\n";
			cout << "Your choice : ";
			do
			{
				cin >> choice;
				if (choice == '1')
					newPassword.clear();
				else if (choice == '2')
					returnToMenu = 1;
				else
				{
					system("cls");
					cout << "Invalid Choice\n\n";
					cout << "Choose operation:-\n";
					cout << "1-Reenter password\n";
					cout << "2-Return to previous menu\n\n";
					cout << "Your choice : ";
				}
			} while (choice != '1' && choice != '2');

		}
		else
		{
			isValidNewPassword = 1;
			break;
		}

	} while (!isValidNewPassword && !returnToMenu);

	if (returnToMenu)
		return 1;
	else
	{
		if (isSignUp)
		{
			++MaxUsersIdx;
			idxOfUser = MaxUsersIdx;
			user[idxOfUser].username = tempUsername;
		}

		hashing(newPassword);
		user[idxOfUser].password = newPassword;
		return 0;
	}
}

bool NewUsernameCheck()
{
	cin.ignore();

	string newUsername, TempNewUsername, ErrorType;
	char inChar;
	char choice;
	bool returnToMenu = 0, isValidNewUsername = 0;

	do
	{
		system("cls");
		cout << "Enter New Username : ";
		getline(cin, newUsername);

		int specialChar = newUsername.find_first_of("!@#?><}{:+-/&$%×÷؛");

		if (newUsername.size() < 8 || newUsername.size() > 16)
			ErrorType = "Username must be between 8 and 16 characters.";
		else if (specialChar > 0 || newUsername.find(' ') != string::npos)
			ErrorType = "Username can not contain spaces or special characters.";
		else if (newUsername == user[idxOfUser].username)
			ErrorType = "New username is the same as your current one.";
		else if (!isNewUsername(newUsername))
			ErrorType = "Username is already taken.";
		else if (isCorrectSize(newUsername))
		{
			TempNewUsername = newUsername;
			hashing(TempNewUsername);
			if (TempNewUsername == user[idxOfUser].password)
				ErrorType = "New username can not be the same as your password.";
			else
				isValidNewUsername = 1;
		}
		else
			isValidNewUsername = 1;

		if (!isValidNewUsername)
		{
			system("cls");
			cout << ErrorType << " Choose Another Username\n\n";
			cout << "Choose operation:-\n";
			cout << "1-Reenter username\n";
			cout << "2-Return to previous menu\n\n";
			cout << "Your choice : ";
			do
			{
				cin >> choice;
				if (choice == '1')
				{
					newUsername.clear();
					cin.ignore();
				}
				else if (choice == '2')
					returnToMenu = 1;
				else
				{
					system("cls");
					cout << "Invalid Choice\n\n";
					cout << "Choose operation:-\n";
					cout << "1-Reenter password\n";
					cout << "2-Return to previous menu\n\n";
					cout << "Your choice : ";
				}
			} while (choice != '1' && choice != '2');
		}
		else
		{
			isValidNewUsername = 1;
			break;
		}

	} while (!isValidNewUsername && !returnToMenu);

	if (returnToMenu)
		return 1;
	else
	{
		user[idxOfUser].username = newUsername;
		return 0;
	}

}

bool UsernameSignUpCheck()
{
	string choiceMessage = "Press 1 to try entering your username again OR Press any other number to Exit sign up menu";
	char tryAgain = 0;
	bool usernameCorrect = false;

	while (true)
	{
		system("cls");
		cout << "Enter username" << " : ";

		if (tryAgain == '1')
			cin.ignore();

		getline(cin, tempUsername);

		int specialChar = tempUsername.find_first_of("!@#?><}{:+-/&$%×÷؛");

		if (specialChar > 0)
		{
			cout << "Sorry! username cannot have any special charachters" << endl;
			cout << choiceMessage << endl;
			cin >> tryAgain;
			if (tryAgain == '1')
				continue;
			else
				break;
		}
		else if (tempUsername.find(' ') != string::npos)
		{
			cout << "Sorry! username cannot have any spaces between charachters" << endl;
			cout << choiceMessage << endl;
			cin >> tryAgain;
			if (tryAgain == '1')
				continue;
			else
				break;
		}
		else if (tempUsername.size() < 8 || tempUsername.size() > 16)
		{
			cout << "Sorry! username must be between 8 and 16 charachters" << endl;
			cout << choiceMessage << endl;
			cin >> tryAgain;
			if (tryAgain == '1')
				continue;
			else
				break;
		}
		else if (!isNewUsername(tempUsername))
		{
			cout << "Sorry! the username you entered is already taken" << endl;
			cout << choiceMessage << endl;
			cin >> tryAgain;
			if (tryAgain == '1')
				continue;
			else
				break;
		}
		else
		{
			usernameCorrect = true;
			break;
		}
	}

	if (usernameCorrect)
		return 0;
	else
		return 1;
}

void signUp()
{
	if (UsernameSignUpCheck() || NewPasswordCheck(1))
	{
		return;
	}
	else
	{
		isUserMenuReq = 1;
		return;
	}
}

void logIn()
{

	if (UsernameSignInCheck() || CurrentPasswordCheck())
	{
		return;
	}
	else if (user[idxOfUser].isAdmin == 1)
	{
		isAdminMenuReq = 1;
		return;
	}
	else
	{
		isUserMenuReq = 1;
		return;
	}

}

void changeUsername()
{
	if (CurrentPasswordCheck() || NewUsernameCheck())
		return;
	else
	{
		system("cls");
		cout << "Username has been changed successfully\n";
		system("pause");
	}
}

void changePassword()
{


	if (CurrentPasswordCheck() || NewPasswordCheck(0))
	{
		return;
	}
	else
	{
		system("cls");
		cout << "Password has been changed successfully\n";
		system("pause");
	}


}

void FilestoArray_users()
{
	string Transformer;

	int i = 0, Trio_Counter = 1;

	Users.open("users.txt", ios::in);

	while (getline(Users, Transformer))

	{
		if (Trio_Counter == 1)
		{
			user[i].username = Transformer;
			++Trio_Counter;
		}

		else if (Trio_Counter == 2)
		{
			user[i].password = Transformer;
			++Trio_Counter;
		}

		else if (Trio_Counter == 3)
		{
			if (Transformer == "1")
				user[i].isAdmin = true;

			else if (Transformer == "0")
				user[i].isAdmin = false;

			++Trio_Counter;
		}

		else
		{
			if (Transformer == "1")
				user[i].authorized = true;

			else if (Transformer == "0")
				user[i].authorized = false;
			Trio_Counter = 1;
			++i;
		}



	}
	MaxUsersIdx = i - 1;
}

void ArraytoFiles_users()
{

	Users.open("users.txt", std::ofstream::out | std::ofstream::trunc);
	Users.close();

	Users.open("users.txt", ios::out);
	if (Users.is_open())
	{
		for (int i = 0; i <= MaxUsersIdx; i++)
		{
			Users << user[i].username + "\n";

			Users << user[i].password + "\n";

			if (user[i].isAdmin)
				Users << "1\n";
			else
				Users << "0\n";

			if (user[i].authorized)
				Users << "1\n";
			else
				Users << "0\n";
		}
	}
	Users.close();
}

void FilestoArray_weakPasswords()
{
	fstream weakPasswordsFile;
	weakPasswordsFile.open("weakPasswords.txt", ios::in);

	if (weakPasswordsFile.is_open())
	{
		int i = 0;
		string line;
		while (getline(weakPasswordsFile, line))
		{
			weakPasswords_arr[i] = line;
			i++;
			if (i >= 10000)
				return;
		}
		weakPasswordsFile.close();
	}
}

bool isWeak(string& password)
{
	int start = 0, end = 9999, mid;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (weakPasswords_arr[mid] == password)
			return 1;
		else if (weakPasswords_arr[mid] < password)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return 0;
}

void hashing(string& password)
{
	long long hashedPassword1 = 0, hashedPassword2 = 0, hashedPasswordFinal;
	long long mod1 = 999999733, mod2 = 999985379, mod3 = 1000000007, PrimePowI;

	for (int i = 0; i < 5; i++)
	{
		PrimePowI = ((long long int)pow(3, i)) % mod1;
		hashedPassword1 = ((hashedPassword1 % mod1) + ((password[i] % mod1) * (PrimePowI % mod1)) % mod1) % mod1;
	}

	for (int i = 0; i < password.size(); i++)
	{
		PrimePowI = ((long long int)pow(5, i)) % mod2;
		hashedPassword2 = ((hashedPassword2 % mod2) + ((password[i] % mod2) * (PrimePowI % mod2)) % mod2) % mod2;
	}

	hashedPasswordFinal = ((hashedPassword1 % mod3) * (hashedPassword2 % mod3)) % mod3;
	password = to_string(hashedPasswordFinal);
}

void toFile_reports() {
	reportsFile.open("reports.txt", ios::out);
	for (int i = 0; i <= reportsNum; i++)

	{
		reportsFile << report[i].description << endl;
		reportsFile << report[i].location << endl;
		reportsFile << report[i].type << endl;
		reportsFile << report[i].health_situation << endl;
		if (report[i].isAdopted)
		{
			reportsFile << '1' << endl;
			reportsFile << to_string(report[i].adoption_user_idx) << endl;
		}
		else
		{
			reportsFile << '0' << endl;
			reportsFile << "-1" << endl;//this means : no one has adopted this animal (-1 is basically a garbage data in this situation)

		}

		if (report[i].isConfirmed == 1)
			reportsFile << '1' << endl;
		else if (report[i].isConfirmed == 0)
			reportsFile << '0' << endl;
		else
			reportsFile << "-1" << endl;


		reportsFile << to_string(report[i].report_user_idx) << endl;

	}


	reportsFile.close();



}

void fromFile_reports() {
	reportsFile.open("reports.txt", ios::in);//read from file
	for (int i = 0; i <= reportsNum; i++)

	{
		string isConfirmed_str = "is", isAdopted_str = "is", user_idx_str = "100", adopted_user_str;

		getline(reportsFile, report[i].description);
		getline(reportsFile, report[i].location);
		getline(reportsFile, report[i].type);
		getline(reportsFile, report[i].health_situation);
		getline(reportsFile, isAdopted_str);
		if (isAdopted_str == "1")
			report[i].isAdopted = true;
		else
			report[i].isAdopted = false;
		getline(reportsFile, adopted_user_str);
		report[i].adoption_user_idx = stoi(adopted_user_str);
		getline(reportsFile, isConfirmed_str);
		report[i].isConfirmed = stoi(isConfirmed_str);
		getline(reportsFile, user_idx_str);
		report[i].report_user_idx = stoi(user_idx_str);

	}
	reportsFile.close();




}

void store_num_of_reports() {
	reportsNumberFile.open("reportsNum.txt", ios::out);
	reportsNumberFile << to_string(reportsNum);
	reportsNumberFile.close();
}

void how_many_reports() {
	string report;
	reportsNumberFile.open("reportsNum.txt", ios::in);
	getline(reportsNumberFile, report);
	reportsNum = stoi(report);
	reportsNumberFile.close();
}

void addToFile_donation() {
	ofstream myfile;
	myfile.open("donate.txt", ios::out);

	for (int i = 0; i <= MaxUsersIdx; i++) {

		myfile << i << endl;
		myfile << donation[i] << endl;

	}
	myfile.close();

}

void addToArray_donation() {

	int j = 1, emp_idx, emp;
	ifstream myfile("donate.txt", ios::in);
	while (myfile >> emp) {
		if (j == 1) {
			j++;
			emp_idx = emp;
		}
		else if (j == 2) {
			donation[emp_idx] = emp;
			totalDonations += donation[emp_idx];
			j = 1;
		}
	}myfile.close();
}

void exitFun()
{
	addToFile_donation();
	store_num_of_reports();
	toFile_reports();
	ArraytoFiles_users();
	exit(0);
}
