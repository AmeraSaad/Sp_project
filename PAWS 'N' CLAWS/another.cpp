//#include <iostream>
//#include <fstream>
//#include <string>
//#include <windows.h>
//#include <iomanip>
//#include <conio.h>
//#include <cmath>
//using namespace std;
//
//struct user_type
//{
//	string username;
//	string password;
//	bool isAdmin;
//	bool authorized = 1;
//	string messages[1000];
//	int totalMessages;
//};
//user_type user[10000];
//
//struct report_type {
//	string location;
//	string type;
//	string health_situation;
//	string description;
//	bool  isAdopted;
//	int report_user_idx, adoption_user_idx, isConfirmed;
//} report[10000];
//
//fstream Users;
//fstream Communication;
//fstream reportsFile;
//fstream reportsNumberFile;
//int idxOfUser = 0;
//int MaxUsersIdx = -1;
//int foundUseridx;
//int reportsNum = 0;
//int animalsNum = 0;
//int totalDonations = 0;
//int adminsNum = 0;
//int numOfMessages = 0;
//long long donation[10000];
//bool isUserMenuReq = 0;
//bool isAdminMenuReq = 0;
//bool removeSelf = 0;
//bool isActivecc;
//string weakPasswords_arr[10000];
//string tempUsername;
//
//
//void adoption();
//void editReport();
//void user_history();
//void userMenu();
//void change();
//void checklists();
//void newAnimal();
//void addRevAdmin();
//void banuser();
//void Confirm();
//void AdminMenu();
//bool isNewUsername(string& Newusername);
//bool isCorrectSize(string& password);
//bool UsernameSignInCheck();
//bool CurrentPasswordCheck();
//bool NewPasswordCheck(bool isSignUp);
//bool NewUsernameCheck();
//bool UsernameSignUpCheck();
//void signUp();
//void logIn();
//void changeUsername();
//void changePassword();
//void FilestoArray_users();
//void ArraytoFiles_users();
//void FilestoArray_weakPasswords();
//void getPasswordWithAsterisks(string& password, bool isSignUp);
//bool isWeak(string& password);
//void hashing(string& password);
//void toFile_reports();
//void fromFile_reports();
//void store_num_of_reports();
//void how_many_reports();
//void addToFile_donation();
//void addToArray_donation();
//bool sendingMessages(long long targetedUser);
//bool viewingMessages();
//void fileToMessages();
//void messagesToFile();
//void moneyValidation();
//void creditValidation();
//void displayDonations_admin();
//void displayDonations_user();
//void exitFun();
//
//int main()
//{
//	/*how_many_reports();
//	fromFile_reports();
//	addToArray_donation();
//	FilestoArray_users();
//	FilestoArray_weakPasswords();
//	fileToMessages();*/
//
//	char choice;
//	bool isValidChoice_menu = 1;
//
//	while (true)
//	{
//		system("cls");
//		isAdminMenuReq = 0;
//		isUserMenuReq = 0;
//		removeSelf = 0;
//
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//		system("cls");
//		cout << "\n                                               WELCOME TO PAWS 'N' CLAWS                        ";
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//
//		if (!isValidChoice_menu)
//		{
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << "\n\n INVALID CHOICE!!";
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			isValidChoice_menu = 1;
//		}
//
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//		cout << "\n\n 1) Log In \n 2) Sign Up \n 3) Exit \n\n";
//		cout << "____________________________";
//		cout << "\n\n Choose an operation : ";
//		cin >> choice;
//		cin.ignore(); //because we use getline in logIn & signUp 
//
//		if (choice == '1')
//			logIn();
//		else if (choice == '2')
//			signUp();
//		else if (choice == '3')
//			exitFun();
//		else
//			isValidChoice_menu = 0;
//
//		if (isAdminMenuReq)
//			AdminMenu();
//		else if (isUserMenuReq)
//			userMenu();
//
//	}
//
//	return 0;
//
//}
//
//void userMenu()
//{
//	system("cls");
//	short int i;
//	string menuList[8] = { "See  all the animals in the shelter and you can adopt any one if you want","If you want to donate","If you see an animal that needs help, send us a report report,please or if you want to edit an earlier one ","change passord/usernmae","see my history","chat","Log out","Exit" };
//	int menuNum;
//	do
//	{
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//		system("cls");
//		cout << "\n";
//		cout << "                                               W E L C O M E  T O  P A W S  'N'  C L A W S <3                     \n";
//		cout << "                                                       H A P P Y  T O  SEE  YOU :)                       \n\n";
//		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//		cout << "|                    MENU                      |\n";
//		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//
//		for (int i = 1; i <= 8; i++)
//		{
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			cout << "\n\n" << " " << i << "- " << menuList[i - 1] << "\n";
//		}
//		cout << "\n\n\t How Can we Help You ?  ";
//		cin >> menuNum;
//		switch (menuNum)
//		{
//		case 1:
//			//see animals and adopt
//			system("cls");
//			adoption();
//			system("pause");
//			break;
//
//		case 2:
//			isActivecc = 0;
//			creditValidation();
//			if (isActivecc)
//				moneyValidation();
//			break;
//		case 3:
//			system("cls");
//			cout << "WHAT DO YOU WANT EXACTLT___";
//			cout << "1- ADD ONE  \t";
//			cout << "2- EDIT ONE \t(1-2)?  ";
//			int choice_;
//			while (true)
//			{
//				cin >> choice_;
//				if (choice_ == 1)
//				{
//					newAnimal();
//					break;
//				}
//				else if (choice_ == 2)
//				{
//					editReport();
//					break;
//				}
//				else {
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//					cout << "Please enter a valid choice!";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//					continue;
//				}
//			}
//			break;
//		case 4:
//			change();
//			break;
//		case 5:
//			system("cls");
//			//see history
//			user_history();
//			break;
//		case 6:
//			system("cls");
//			cin.ignore();
//			viewingMessages();
//			break;
//		case 7:
//			system("cls");
//			cout << "\n\n";
//			cout.width(75);
//			cout << "Logged out successfully!\n\n";
//			cout.width(81);
//			cout << "Thank you for using Paws 'N' Claws!\n\n";
//			cout.width(79);
//			cout << "Hope you have a great day < 3\n\n";
//			system("pause");
//			return;
//			break;
//		case 8:
//			exitFun();
//			break;
//		default:
//			cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//			cout << "Invalid choice,please try again\n";
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			system("pause");
//		}
//	} while (menuNum != 8);
//}
//
//void adoption()
//{
//	system("cls");
//	int choice_, n = 0, ad[1000], count = 0;
//	char ch;
//	bool rightchoice = false;
//	cout << "WHAT DO YOU WANT EXACTLT___";
//	cout << "1- JUST TAKE A LOOK AT ANIMALS  \t ";
//	cout << "2- TAKE A LOOK AND ADOPT ONE    (1-2)? ";
//	while (rightchoice == false)
//	{
//		cin >> choice_;
//		switch (choice_)
//		{
//		case 1:
//			system("cls");
//			cout << "\nLIST OF ANIMALS IN OUR SHELTER <3 \n";
//			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
//			cout << "  Type:\t\t    Location:\t\tHealth situation:\t\t\t   Description:\n\n";
//			cout << "---------------------------------------------------------------------------------------------------------------------\n";
//			for (int i = 0; i <= reportsNum; i++)
//			{
//				if (report[i].isConfirmed == 1 && report[i].isAdopted == false) {
//					cout << n + 1 << "- " << left << setw(16) << report[i].type + "\t" << setw(16) << "| " + report[i].location + "\t" << setw(20) << "| " + report[i].health_situation << left << setw(20) << "\t" << "| " + report[i].description << "\n";
//					n++;
//					count++;
//				}
//				if (count != 0)
//					cout << endl << "---------------------------------------------------------------------------------------------------------------------\n";
//			}
//			if (count == 0)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//				cout << "SORRY FOR THAT BUT THERE IS NO ANIMLEs IN THE SHELTER RIGHT NOW ,PLEAE CHECK LATER\n";
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			}
//			rightchoice = true;
//			break;
//		case 2:
//			do
//			{
//				system("cls");
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//				n = 0, count = 1;
//				bool checkchoice2 = false;
//				cout << "\nLIST OF ANIMALS IN OUR SHELTER THAT YOU CAN ADOPTE ANYONE YOU WANT <3 \n";
//				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
//				cout << "  Type:\t\t    Location:\t\tHealth situation:\t\t\t   Description:\n\n";
//				cout << "---------------------------------------------------------------------------------------------------------------------\n";
//				if (count != 0) {
//					count = 0;
//					for (int i = 0; i <= reportsNum; i++)
//					{
//						if (report[i].isConfirmed == 1 && report[i].isAdopted == false) {
//							cout << n + 1 << "- " << left << setw(16) << report[i].type + "\t" << setw(16) << "| " + report[i].location + "\t" << setw(20) << "| " + report[i].health_situation << left << setw(20) << "\t" << "| " + report[i].description << "\n";
//							n++;
//							ad[count] = i;
//							count++;
//						}
//						if (count != 0)
//							cout << endl << "---------------------------------------------------------------------------------------------------------------------\n";
//					}
//				}
//				if (count == 0) {
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//					cout << "SORRY FOR THAT BUT THERE IS NO ANIMLEs IN THE SHELTER RIGHT NOW ,PLEAE CHECK LATER\n";
//					break;
//				}
//				else {
//					int adopteton_choice, checkCad = 0;
//					cout << "PLEASE,TELL US WHICH ONE YOU HAVE DECIDED TO ADOPT\t ";
//					while (checkchoice2 == false) {
//						cin >> adopteton_choice;
//						for (int i = 1; i <= count; i++)
//						{
//							if (i == adopteton_choice) {
//								checkCad++;
//							}
//						}
//						if (checkCad == 0) {
//							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//							cout << "INVALID CHOICE,PLEASE ENTER A CHOICE AGAIN : ";
//							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//						}
//
//						else {
//							--count;
//							checkchoice2 = true;
//							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//							cout << "\nAnimal adopted! :) \nThank you for your kindness <3\n";
//							report[ad[adopteton_choice - 1]].isAdopted = true;
//							report[ad[adopteton_choice - 1]].adoption_user_idx = idxOfUser;
//							///////////////
//							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//							cout << "\nDo you want to adopte another animal (enter y/Y) ? ";
//							cin >> ch;
//							if (count == 0 && (ch == 'Y' || ch == 'y')) {
//								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//								cout << "SORRY FOR THAT BUT THERE IS NO MORE ANIMLES IN THE SHELTER RIGHT NOW ,PLEAE CHECK LATER\n";
//								break;
//							}
//						}
//					}
//
//				}
//			} while (ch == 'Y' || ch == 'y');
//			cout << "~~~~~~~~~~~~~~~~~~~~\n";
//			rightchoice = true;
//			break;
//		default:
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//			cout << "INVALID CHOICE,PLEASE ENTER A RIGHT CHOICE: ";
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//		}
//	}
//}
//
//void editReport() {
//	char ch;
//	do
//	{
//		system("cls");
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//		cout << "\n YOUR EDIT LIST<3 \n";
//		cout << "~~~~~~~~~~~~~~~~~~~~~\n\n";
//		cout << "  Type:\t\t    Location:\t\tHealth situation:\t\t\t   Description:\n\n";
//		cout << "----------------------------------------------------------------------------------\n";
//		int count = 0;
//		int save_rpt[100];
//		for (int i = 0; i <= reportsNum; i++)
//		{
//			if (report[i].report_user_idx == idxOfUser) {
//				cout << count + 1 << "- " << left << setw(16) << report[i].type + "\t" << setw(16) << "| " + report[i].location + "\t" << setw(20) << "| " + report[i].health_situation << left << setw(20) << "\t" << "| " + report[i].description << "\n";
//				save_rpt[count] = i;
//				count++;
//			}
//		}
//		if (count == 0) {
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//			cout << "SORRY! YOU HAVE NOT ADD ANY REPORT BEFORE";
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			break;
//		}
//		bool rightCedit = false;
//		cout << "Which one do u want to change ? ";
//		int re_choice, check = 0;
//		while (rightCedit == false)
//		{
//			cin >> re_choice;
//			for (int i = 1; i <= count; i++)
//			{
//				if (i == re_choice) {
//					check++;
//				}
//			}
//			if (check == 0)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//				cout << "INVALID CHOICE,PLEASE ENTER A CHOICE AGAIN : ";
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			}
//			else {
//				rightCedit = true;
//				cout << "\n 1 - type\n 2 - location\n 3 - health situation\n 4 - description\n which part do u want to change(1-4)";
//				int edit_choice;
//				bool checkchoice;
//				do {
//					checkchoice = true;
//					cin >> edit_choice;
//					if (edit_choice == 1)
//					{
//						cout << "What is the type of the animal?\n";
//						cin.ignore(); getline(cin, report[save_rpt[re_choice - 1]].type);
//					}
//					else if (edit_choice == 2)
//					{
//						cout << "What is the location of the animal?\n";
//						cin.ignore(); getline(cin, report[save_rpt[re_choice - 1]].location);
//					}
//					else if (edit_choice == 3)
//					{
//						cout << "What is the health situation of the animal?\n";
//						cin.ignore(); getline(cin, report[save_rpt[re_choice - 1]].health_situation);
//					}
//					else if (edit_choice == 4)
//					{
//						cout << "What is the descrption of the animal?\n";
//						cin.ignore(); getline(cin, report[save_rpt[re_choice - 1]].health_situation);
//					}
//					else {
//						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//						cout << "INVALID CHOICE,PLEASE ENTER A RIGHT CHOICE: ";
//						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//						checkchoice = false;
//					}
//				} while (checkchoice == false);
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//				cout << "\nReport dited! :)";
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//				cout << "\nDo you want to edit again or edit another report (enter y/Y) ? ";
//				cin >> ch;
//			}
//		}
//
//	} while (ch == 'Y' || ch == 'y');
//	cout << "---------------------------\n";
//	system("pause");
//}
//
//void user_history()
//{
//	int n, c = 0;
//	char ch;
//	do
//	{
//		system("cls");
//		cout.width(78);
//		cout << "\nC H E C K I N G  L I S T S!\n\n";
//		cout << "1-All the animal I have adopted\n\n";
//		cout << "2- My reports I have made.\n\n";
//		cout << "3-All Donations.\n\n";
//		cout << "------------------------\n";
//		cout << "Which list do you want to view (1-3) ? \n";
//		bool rightchoice = false;
//		while (rightchoice == false)
//		{
//			cin >> n;
//			switch (n)
//			{
//			case 1:
//				system("cls");
//				cout << "\n ALL THE ANIMALS YOU HAVE ADOPTED BEFORE<3\n\n";
//				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
//				cout << "  Type:\t\t    Location:\t\tHealth situation:\t\t\t   Description:\n\n";
//				cout << "----------------------------------------------------------------------------------------------\n";
//				for (int i = 0; i <= reportsNum; i++)
//				{
//					if (report[i].adoption_user_idx == idxOfUser)
//					{
//						c++;
//						cout << c << "- " << left << setw(16) << report[i].type + "\t" << setw(16) << "| " + report[i].location + "\t" << setw(20) << "| " + report[i].health_situation << left << setw(20) << "\t" << "| " + report[i].description << "\n";
//					}
//				}
//				if (c == 0) {
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//					cout << "YOU  HAVE NOT ADOPTED BRFORE:)";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//				}
//				rightchoice = true;
//				break;
//			case 2:
//				system("cls");
//				cout << "\n ALL THE REPORTS YOU HAVE MADE<3\n\n";
//				cout << "\nLIST OF ANIMALS IN OUR SHELTER <3 \n";
//				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"; "  Type:\t\t    Location:\t\tHealth situation:\t\t\t   Description:\n\n";
//				cout << "----------------------------------------------------------------------------------------------------------------------------------------------";
//				for (int i = 0; i <= reportsNum; i++)
//				{
//					if (report[i].report_user_idx == idxOfUser)
//					{
//						cout << c + 1 << "- " << left << setw(16) << report[i].type + "\t" << setw(16) << "| " + report[i].location + "\t" << setw(20) << "| " + report[i].health_situation << left << setw(20) << "\t" << "| " + report[i].description << "\n";
//						c++;
//					}
//				}
//				if (c == 0) {
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//					cout << "YOU  HAVE NOT REPORTED BRFORE:)";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//				}
//				rightchoice = true;
//				break;
//			case 3:
//				system("cls");
//				rightchoice = true;
//				displayDonations_user();
//				break;
//			default:
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//				cout << "INVALID CHOICE,PLEASE ENTER A RIGHT CHOICE: ";
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			}
//		}
//		cout << "\n IF YOU WANT TO SEE ANYTHING ELSE IN YOUR HISTORY (enter y/Y) ? ";
//		cin >> ch;
//	} while (ch == 'Y' || ch == 'y');
//	cout << "---------------------------\n";
//
//
//}
//
//void change()
//{
//	system("cls");
//	string no;
//	bool changed = false;
//	while (changed == false)
//	{
//		cout << endl;
//		cout.width(91);
//		cout << "C H A N G E  U S E R N A M E  A N D  P A S S W O R D :\n";
//		cout.width(92);
//		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
//		cout << "1-Change username\n\n2-Change password\n\n";
//		cout << "Which one do you want to Change(1/2)? ";
//		cin >> no;
//
//		cout << "~~~~~~~~~~~~~~\n\n";
//		if (no == "1")
//		{
//			changeUsername();
//			changed = true;
//		}
//		else if (no == "2")
//		{
//			changePassword();
//			changed = true;
//		}
//		else
//		{
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << "Invalid choice";
//			changed = false;
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//
//		}
//
//	}
//	system("pause");
//}
//
//void checklists()
//{
//	system("cls");
//	char x;
//	bool rightchoice = false;
//	cout << endl;
//	cout.width(78);
//	cout << "C H E C K I N G  L I S T S!\n\n";
//	cout << "1-Reports (Confirmed,Denied and Pending)\n\n";
//	cout << "2-Adopted animals and whom they were adopted by.\n\n";
//	cout << "3-All Donations made by users.\n\n";
//	cout << "4-List of all users in the system.\n\n";
//	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//	do {
//		cout << "Which list do you want to view (1-4) ? \n"; cin.ignore(); cin >> x;
//		switch (x)
//		{
//		case '1':
//			system("cls");
//			cout << "\nLists of confirmed, denied and pending reports: \n";
//			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
//			cout << "CONFIRMED REPORTS: \n\n";
//			cout << "Type:\tLocation:\t\tHealth situation:\t\tDescription:\n";
//			for (int i = 0; i <= reportsNum; i++)
//			{
//				if (report[i].isConfirmed == 1)
//					cout << report[i].type << "\t" << report[i].location << "\t\t\t" << report[i].health_situation << "\t\t\t    " << report[i].description << "\n";
//			}
//			cout << endl << "--------------------\n";
//			cout << "DENIED REPORTS: \n\n";
//			cout << "Type:\tLocation:\t\tHealth situation:\t\tDescription:\n";
//			for (int i = 0; i <= reportsNum; i++)
//			{
//				if (report[i].isConfirmed == 0)
//					cout << report[i].type << "\t" << report[i].location << "\t\t\t" << report[i].health_situation << "\t\t\t    " << report[i].description << "\n";
//			}
//			cout << endl << "--------------------\n";
//			cout << "PENDING REPORTS: \n\n";
//			cout << "Type:\tLocation:\t\tHealth situation:\t\tDescription:\n";
//			for (int i = 0; i <= reportsNum; i++)
//			{
//				if (report[i].isConfirmed == -1)
//					cout << report[i].type << "\t" << report[i].location << "\t\t\t" << report[i].health_situation << "\t\t\t    " << report[i].description << "\n";
//			}
//			cout << endl << "--------------------\n";
//			rightchoice = true;
//			system("pause");
//			break;
//		case '2':
//			system("cls");
//			cout << "\n";
//			cout.width(78);
//			cout << "A D O P T E D  A N I M A L S <3\n";
//			cout.width(79);
//			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
//			cout << "ADOPTED ANIMAL:\t\tADOPTED BY USER:\t\tLOCATION:\t\tHealth situation:\t\tDescription\n";
//			cout << "------------------------------------------------------------------------------------------------------------------------------------------\n";
//			for (int i = 0; i <= reportsNum; i++)
//			{
//				if (report[i].isAdopted == 1)
//				{
//					cout << report[i].type; cout << "\t\t\t" << user[report[i].adoption_user_idx].username << "\t\t\t    " << report[i].location; cout << "\t\t\t"
//						<< report[i].health_situation << "    \t\t" << report[i].description; cout << "\n";
//					cout << "------------------------------------------------------------------------------------------------------------------------------------------\n";
//
//				}
//			}
//
//			//cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//			rightchoice = true;
//			system("pause");
//			break;
//		case '3':
//			system("cls");
//			cout << "Donations made by users:\n";
//			displayDonations_admin();
//			rightchoice = true;
//			break;
//		case '4':
//			system("cls");
//			cout << "\n";
//			cout.width(78);
//			cout << "L I S T  O F  A L L  U S E R S!\n";
//			cout.width(79);
//			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
//			cout << "Username:\t\tAdmin:\t\tAuthorized:\n";
//			cout << "-------------------------------------------------------------\n";
//			for (int i = 0; i <= MaxUsersIdx; i++)
//			{
//				cout << i + 1 << "- " << user[i].username << "\t\t\t" << user[i].isAdmin << "\t\t" << user[i].authorized << "\n";
//				cout << "-------------------------------------------------------------\n";
//			}
//			rightchoice = true;
//			system("pause");
//			break;
//
//		default:
//
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << "Please enter a valid choice!\n";
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			system("pause");
//		}
//	} while (rightchoice == false);
//}
//
//void newAnimal()
//{
//	char choice;
//	do
//	{
//		system("cls");
//		cout << "\n";
//		cout.width(80);
//		cout << "A D D  N E W  A N I M A L S  T O  A D O P T !\n";
//		cout.width(80);
//		cout << "~~~~~~~~~~~~~~~~\n";
//		reportsNum++;
//		char type, location;
//		bool typeAdded = false, locationAdded = false, otherUsed = 0;
//		while (typeAdded == false)
//		{
//			cout << "Animal type:\n 1-Dog\n 2-Cat\n 3-Bird\n 4-Hamster\n 5-Monkey\n 6-Other\n Animal type no: "; cin >> type;
//			switch (type)
//			{
//			case '1':
//				report[reportsNum].type = "Dog";
//				typeAdded = true;
//				break;
//			case '2':
//				report[reportsNum].type = "Cat";
//				typeAdded = true;
//				break;
//			case '3':
//				report[reportsNum].type = "Bird";
//				typeAdded = true;
//				break;
//			case '4':
//				report[reportsNum].type = "Hamster";
//				typeAdded = true;
//				break;
//			case '5':
//				report[reportsNum].type = "Monkey";
//				typeAdded = true;
//				break;
//			case '6':
//				cout << "What is the type of the animal?\n";
//				cin >> report[reportsNum].type;
//				typeAdded = true;
//				otherUsed = 1;
//				break;
//			default:
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//				cout << "Please enter a valid choice!\n";
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			}
//		}
//
//		while (locationAdded == false)
//		{
//			system("cls");
//			cout << "\n";
//			cout.width(80);
//			cout << "A D D  N E W  A N I M A L S  T O  A D O P T !\n";
//			cout.width(80);
//			cout << "~~~~~~~~~~~~~~~~\n";
//
//			cout << "Locations:\n 1-Cairo\n 2-Giza\n 3-Alexandria\n 4-Hurghada\n 5-Aswan\n 6-Port Said\n 7-Other\n Location number: "; cin >> location;
//			switch (location)
//			{
//			case '1':
//				report[reportsNum].location = "Cairo";
//				locationAdded = true;
//				break;
//			case '2':
//				report[reportsNum].location = "Giza";
//				locationAdded = true;
//				break;
//			case '3':
//				report[reportsNum].location = "Alexandria";
//				locationAdded = true;
//				break;
//			case '4':
//				report[reportsNum].location = "Hurghada";
//				locationAdded = true;
//				break;
//			case '5':
//				report[reportsNum].location = "Aswan";
//				locationAdded = true;
//				break;
//			case '6':
//				report[reportsNum].location = "Port Said";
//				locationAdded = true;
//				break;
//			case '7':
//				cout << "What is the location of the animal?\n";
//				cin.ignore(); getline(cin, report[reportsNum].location);
//				locationAdded = true;
//				otherUsed = 1;
//				break;
//			default:
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//				cout << "\nPlease enter a valid choice!\n\n";
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//				locationAdded = false;
//				system("pause");
//			}
//		}
//		system("cls");
//		cout << "\n";
//		cout.width(80);
//		cout << "A D D  N E W  A N I M A L S  T O  A D O P T !\n";
//		cout.width(80);
//		cout << "~~~~~~~~~~~~~~~~\n";
//
//		cout << "Health situation: ";
//		if (!otherUsed)
//			cin.ignore();
//		getline(cin, report[reportsNum].health_situation);
//		cout << "Description: "; getline(cin, report[reportsNum].description);
//
//		if (user[idxOfUser].isAdmin == true)
//		{
//			report[reportsNum].isConfirmed = 1;
//			report[reportsNum].report_user_idx = idxOfUser;
//		}
//		else
//		{
//			report[reportsNum].isConfirmed = -1;
//			report[reportsNum].report_user_idx = idxOfUser;
//		}
//		cout << "\nDo you want to add another animal (enter y/Y) ? ";
//		cin >> choice;
//
//	} while (choice == 'Y' || choice == 'y');
//	cout << "~~~~~~~~\n";
//}
//
//void addRevAdmin()
//{
//	system("cls");
//	int count = 0;
//	char y;
//	bool choice = false;
//	string adminName;
//	cout << "\n";
//	while (choice == false)
//	{
//		system("cls");
//		cout.width(91);
//		cout << "A D D I N G  O R  R E M O V I N G  A N  A D M I N !\n";
//		cout.width(92);
//		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
//		cout << "1- ADD admin\n\n2-REMOVE admin\n\nChoice number: "; cin >> y; cout << "\n";
//		string name;
//		bool Userfound = 0;
//		switch (y)
//		{
//		case '1':
//			cout << "Adding an admin...\n\n";
//			cout << "Enter the username: "; cin >> name;
//			for (int i = 0; i <= MaxUsersIdx; i++)
//			{
//				if (user[i].username == name && user[i].isAdmin == 0)
//				{
//					adminsNum++;
//					user[i].isAdmin = 1;
//					Userfound = 1;
//					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//					cout << "\nAdmin added successfully :) !\n";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//					break;
//				}
//				else if (user[i].username == name && user[i].isAdmin == 1)
//				{
//					Userfound = 1;
//					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//					cout << "\nAlready an admin :) !\n";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//					break;
//				}
//			}
//			if (Userfound == 0)
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//				cout << "No user exists with this name!\n";
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			}
//			choice = true;
//			break;
//
//		case '2':
//			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//			cout << "Removing an admin...\n\n";
//			cout << "Enter the username of the admin you want to remove: "; cin >> adminName;
//			for (int i = 0; i <= MaxUsersIdx; i++)
//			{
//				if (user[i].username == adminName && user[i].isAdmin == 1)
//				{
//					if (adminsNum > 1)
//					{
//						user[i].isAdmin = 0;
//						count++;
//						adminsNum--;
//						cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//						cout << "\nAdmin removed successfully!\n";
//						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//						if (user[idxOfUser].username == adminName)
//						{
//							removeSelf = 1;
//						}
//					}
//					else
//					{
//						cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//						cout << "\nCan't remove admin! Atleast one admin should exist!\n";
//						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//						count++;
//					}
//				}
//			}
//			if (count == 0)
//			{
//				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//				cout << "\nNo admin exists with this name!\n";
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			}
//
//			choice = true;
//			break;
//
//		default:
//			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << "\nPlease enter a valid choice :/\n\n";
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			system("pause");
//		}
//	}
//	system("pause");
//}
//
//void banuser()
//{
//	system("cls");
//	char choice;
//	int count = 0;
//
//	string username;
//	cout << "\n";
//	cout.width(85);
//	cout << "B A N N I N G  O R  U N B A N N I N G  A  U S E R !\n";
//	cout.width(85);
//	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//	cout << "\n1-Ban a user.\n2-Unban a user.\n ";
//	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//	cout << "Enter your choice: "; cin >> choice;
//	if (choice == '1')
//	{
//
//		cout << "Banning user...\n\n";
//		cout << "Enter the username of the user you want to ban: "; cin >> username;
//		for (int i = 0; i <= MaxUsersIdx; i++)
//		{
//			if (user[i].username == username)
//			{
//				if (user[i].isAdmin == 0)
//				{
//					count++;
//					user[i].authorized = 0;
//					cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//					cout << "User has been banned!\n";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//				}
//				else if (user[i].isAdmin == 1)
//				{
//					count++;
//					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//					cout << "This is an admin, if you want anything regarding this admin head to number 5 in the menu!\n";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//				}
//
//			}
//		}
//		if (count == 0)
//		{
//			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << "No user exists with this name!\n";
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//
//		}
//
//
//	}
//
//	else if (choice == '2')
//	{
//		cout << "Unbanning a user...\n\n";
//		cout << "Enter the username of the user you want to unban: "; cin >> username;
//		for (int i = 0; i <= MaxUsersIdx; i++)
//		{
//			if (user[i].username == username)
//			{
//				if (user[i].isAdmin == 0)
//				{
//					count++;
//					user[i].authorized = 1;
//					cout << "~~~~~~~~~~~~~~~~~~~~~~\n";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//					cout << "User has been unbanned!\n";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//				}
//				else if (user[i].isAdmin == 1)
//				{
//					count++;
//					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//					cout << "This is an admin, if you want anything regarding this admin head to number 5 in the menu!\n";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//				}
//			}
//		}
//		if (count == 0)
//		{
//			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << "No user exists with this name!\n";
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//		}
//	}
//
//
//
//	else
//	{
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//		cout << "Invalid choice :/\n";
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//	}
//
//
//	system("pause");
//}
//
//void Confirm()
//{
//	bool rightchoice = false;
//	int confirm, deny;
//	char n, yes;
//	int count = 0;
//	int idx[10000];
//
//	for (int i = 0; i <= reportsNum; i++)
//	{
//		if (report[i].isConfirmed == -1)
//		{
//			cout << count + 1 << "-" << report[i].type << "\t\t\t\t" << user[report[i].report_user_idx].username << "\t\t\t\t" << report[i].location << "   \t\t\tHealth situation: "
//				<< report[i].health_situation << "\n\t\t\t\t\t\t\t\t\t\t\t\tDescription: " << report[i].description << "\n\n";
//
//			idx[count] = i;
//			count++;
//		}
//	}
//	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------\n";
//	do
//	{
//		if (count > 0)
//		{
//			cout << "Do you want to:\n1- confirm 2 -Deny\n ";
//			cin >> n;
//			if (n == '1')
//			{
//				cout << "Enter the number of the report you want to confirm: \n ";
//				cin >> confirm;
//				for (int i = 0; i <= reportsNum; i++)
//				{
//					if (idx[confirm - 1] == i)
//					{
//						report[i].isConfirmed = 1;
//						rightchoice = true;
//						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//						cout << "Animal confirmed <3\n";
//						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//					}
//				}
//				if (rightchoice == false)
//				{
//					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//					cout << "This animal doesn't exist\n\n";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//					break;
//				}
//
//			}
//			else if (n == '2')
//			{
//				cout << "Enter the number of the report you want to deny: \n ";
//				cin >> deny;
//				for (int i = 0; i <= reportsNum; i++)
//				{
//					if (idx[deny - 1] == i)
//					{
//						report[i].isConfirmed = 0;
//						rightchoice = true;
//						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//						cout << "Animal denied!\n";
//						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//					}
//				}
//
//				if (rightchoice == false)
//				{
//					cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//					cout << "This animal doesn't exist\n\n";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//					break;
//				}
//			}
//			else if (n != '1' && n != '2')
//			{
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//				cout << "Enter a valid option\n~~~~~~~~~~~~~~~~~~~\n";
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			}
//		}
//		else
//		{
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//			cout << "Unfortunately no animals exist right now :(\nCome back soon!\n\n";
//			rightchoice = true;
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//		}
//	} while (rightchoice == false);
//}
//
//void AdminMenu()
//{
//
//
//	system("cls");
//	char choice;
//	bool option = false;
//	while (option == false)
//	{
//		do
//		{
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//			system("cls");
//			cout << "\n";
//			cout << "                                               WELCOME TO PAWS 'N' CLAWS <3                     \n";
//			cout << "                                                    Happy to see you :)                       \n\n";
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//			cout << " |                    MENU                      |\n";
//			cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//			cout << "  1- CHECK the lists of reports, adopted animals, donations and users.\n";
//			cout << "  2- CHECK the reports to be Accepted/Denied.\n";
//			cout << "  3- ADD new animals to adopt.\n";
//			cout << "  4- CHANGE username/password.\n";
//			cout << "  5- MAKE/REMOVE an admin.\n";
//			cout << "  6- BAN users.                \n";
//			cout << "  7- CHAT.\n";
//			cout << "  8- LOG OUT. \n";
//			cout << "  9- EXIT.\n";
//			cout << " How can we help (1-9) ? ";  cin >> choice;
//
//
//			switch (choice)
//			{
//			case '1':
//				checklists();
//				break;
//			case '2':
//				system("cls");
//				cout << "\n";
//				cout.width(90);
//				cout << "A C C E P T  O R  D E N Y  A N  A N I M A L!\n";
//				cout.width(92);
//				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
//				cout << "Reported animal:\t\tReported by user:\t\tLocation:\t\t\tDetials:\n";
//				Confirm();
//				system("pause");
//				break;
//			case '3':
//				newAnimal();
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//				cout << "\nAnimals added! :) \nThank you for your help <3\n";
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//				system("pause");
//				break;
//			case '4':
//				change();
//				system("cls");
//				break;
//			case '5':
//				addRevAdmin();
//				if (removeSelf)
//					return;
//				break;
//			case '6':
//				banuser();
//				break;
//			case '7':
//				system("cls");
//				cin.ignore();
//				viewingMessages();
//				break;
//			case '8':
//				system("cls");
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//				cout << "\n\n";
//				cout.width(75);
//				cout << "Logged out successfully!\n\n";
//				cout.width(81);
//				cout << "Thank you for using Paws 'N' Claws!\n\n";
//				cout.width(79);
//				cout << "Hope you have a great day < 3\n\n";
//				system("pause");
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//				return;
//			case '9':
//				exitFun();
//			default:
//				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//				cout << "Please enter a valid choice :/\n";
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//				system("pause");
//
//
//			}
//
//		} while (true);
//	}
//
//
//
//
//}
//
//bool isNewUsername(string& Newusername)
//{
//	for (int i = 0; i <= MaxUsersIdx; i++)
//	{
//		if (Newusername == user[i].username)
//			return 0;
//	}
//
//	return 1;
//}
//
//bool isCorrectSize(string& password)
//{
//	if (password.size() < 8 || password.size() > 20)
//		return 0;
//
//	return 1;
//}
//
//bool UsernameSignUpCheck()
//{
//	string choiceMessage = "\n Press 1 to try entering your username again OR Press any other number to Exit sign up menu";
//	char tryAgain = 0;
//	bool usernameCorrect = false;
//
//	while (true)
//	{
//		system("cls");
//		cout << " Enter username" << " : ";
//
//		if (tryAgain == '1')
//			cin.ignore();
//
//		getline(cin, tempUsername);
//
//		int specialChar = tempUsername.find_first_of("!@#?><}{:+-/&$%×÷؛");
//
//		if (specialChar >= 0)
//		{
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << "\n Sorry! username cannot have any special charachters" << endl;
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//
//			cout << choiceMessage << endl;
//			cin >> tryAgain;
//			if (tryAgain == '1')
//				continue;
//			else
//				break;
//		}
//		else if (tempUsername.find(' ') != string::npos)
//		{
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << "\n Sorry! username cannot have any spaces between charachters" << endl;
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			cout << choiceMessage << endl;
//			cin >> tryAgain;
//			if (tryAgain == '1')
//				continue;
//			else
//				break;
//		}
//		else if (tempUsername.size() < 8 || tempUsername.size() > 16)
//		{
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << "\n Sorry! username must be between 8 and 16 charachters" << endl;
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			cout << choiceMessage << endl;
//			cin >> tryAgain;
//			if (tryAgain == '1')
//				continue;
//			else
//				break;
//		}
//		else if (!isNewUsername(tempUsername))
//		{
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << "\n Sorry! the username you entered is already taken" << endl;
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			cout << choiceMessage << endl;
//			cin >> tryAgain;
//			if (tryAgain == '1')
//				continue;
//			else
//				break;
//		}
//		else
//		{
//			usernameCorrect = true;
//			break;
//		}
//	}
//
//	if (usernameCorrect)
//		return 0;
//	else
//		return 1;
//}
//
//bool NewUsernameCheck()
//{
//	cin.ignore();
//
//	string newUsername, TempNewUsername, ErrorType;
//	char choice;
//	bool returnToMenu = 0, isValidNewUsername = 0;
//
//	while (true)
//	{
//		if (returnToMenu)
//			return 1;
//
//		system("cls");
//		cout << " Enter New Username : ";
//		getline(cin, newUsername);
//
//		int specialChar = newUsername.find_first_of("!@#?><}{:+-/&$%×÷؛");
//
//		if (newUsername.size() < 8 || newUsername.size() > 16)
//			ErrorType = " Username must be between 8 and 16 characters.";
//		else if (specialChar >= 0 || newUsername.find(' ') != string::npos)
//			ErrorType = " Username cannot contain spaces or special characters.";
//		else if (newUsername == user[idxOfUser].username)
//			ErrorType = " New username is the same as your current one.";
//		else if (!isNewUsername(newUsername))
//			ErrorType = " Username is already taken.";
//		else if (isCorrectSize(newUsername))
//		{
//			TempNewUsername = newUsername;
//			hashing(TempNewUsername);
//			if (TempNewUsername == user[idxOfUser].password)
//				ErrorType = " New username can not be the same as your password.";
//			else
//				isValidNewUsername = 1;
//		}
//		else
//			isValidNewUsername = 1;
//
//		if (!isValidNewUsername)
//		{
//			system("cls");
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << ErrorType;
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			cout << "\n\n 1) Reenter username \n 2) Return to previous menu \n\n";
//			cout << "____________________________";
//			cout << "\n\n Choose an operation : ";
//
//			do
//			{
//				cin >> choice;
//				if (choice == '1')
//				{
//					newUsername.clear();
//					cin.ignore();
//				}
//				else if (choice == '2')
//					returnToMenu = 1;
//				else
//				{
//					system("cls");
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//					cout << " Invalid Choice";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//					cout << "\n\n 1) Reenter username \n 2) Return to previous menu \n\n";
//					cout << "____________________________";
//					cout << "\n\n Choose an operation : ";
//				}
//			} while (choice != '1' && choice != '2');
//		}
//		else
//		{
//			isValidNewUsername = 1;
//			break;
//		}
//	}
//
//	user[idxOfUser].username = newUsername;
//	return 0;
//}
//
//bool UsernameSignInCheck()
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//
//	string login_Username, ErrorType;
//	bool UsernameisCorrect = 0, isBanned = 0, returnTomain = 0;
//	char choice;
//
//	do
//	{
//		isBanned = 0;
//		system("cls");
//		cout << " Enter Username : ";
//		getline(cin, login_Username);
//
//		for (int j = 0; j <= MaxUsersIdx; j++)
//		{
//			if (login_Username == user[j].username)
//			{
//				if (user[j].authorized == 0)
//				{
//					isBanned = 1;
//					break;
//				}
//
//				idxOfUser = j;
//				UsernameisCorrect = 1;
//				break;
//			}
//
//		}
//
//		if (isBanned)
//			ErrorType = " User is not authorized.";
//		else if (!UsernameisCorrect)
//			ErrorType = " Username is incorrect.";
//
//		if (!UsernameisCorrect || isBanned)
//		{
//			system("cls");
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << ErrorType;
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			cout << "\n\n 1) Reenter username \n 2) Return to previous menu \n\n";
//			cout << "____________________________";
//			cout << "\n\n Choose an operation : ";
//
//			do
//			{
//				cin >> choice;
//				if (choice == '1')
//				{
//					cin.ignore();
//					login_Username.clear();
//				}
//				else if (choice == '2')
//					returnTomain = 1;
//				else
//				{
//					system("cls");
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//					cout << " Invalid Choice";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//					cout << "\n\n 1) Reenter username \n 2) Return to previous menu \n\n";
//					cout << "____________________________";
//					cout << "\n\n Choose an operation : ";
//				}
//			} while (choice != '1' && choice != '2');
//
//		}
//
//	} while (!UsernameisCorrect && !returnTomain);
//
//	if (returnTomain)
//		return 1;
//	else
//		return 0;
//
//}
//
//void getPasswordWithAsterisks(string& password, bool isSignUp)
//{
//	password = "";
//	string displayMessage;
//	char inChar[101], starsDisplay[101] = "****************************************************************************************************";
//
//	if (isSignUp)
//		displayMessage = " Enter New Password : ";
//	else
//		displayMessage = " Enter Current Password : ";
//
//	system("cls");
//	cout << displayMessage;
//	int maxCharIdx = 0;
//	inChar[maxCharIdx] = '\b';
//
//	while (inChar[maxCharIdx] == '\b')
//		inChar[maxCharIdx] = _getch();
//
//	while (inChar[maxCharIdx] != '\r')
//	{
//		if (maxCharIdx > 99)
//			break;
//
//		if (inChar[maxCharIdx] != '\b')
//		{
//			maxCharIdx++;
//
//			system("cls");
//			cout << displayMessage;
//			for (int i = 0; i < maxCharIdx; i++)
//				cout << starsDisplay[i];
//
//			inChar[maxCharIdx] = _getch();
//		}
//		else if (inChar[maxCharIdx] == '\b')
//		{
//
//			if (maxCharIdx > 0)
//				maxCharIdx--;
//
//			system("cls");
//			cout << displayMessage;
//			for (int i = 0; i < maxCharIdx; i++)
//				cout << starsDisplay[i];
//
//			inChar[maxCharIdx] = _getch();
//		}
//
//	}
//
//	for (int i = 0; i < maxCharIdx; i++)
//		password += inChar[i];
//
//}
//
//bool CurrentPasswordCheck()
//{
//	string inPassword = "";
//	bool returnTomain = 0;
//	char choice;
//
//	while (true)
//	{
//		if (returnTomain)
//			return 1;
//
//		getPasswordWithAsterisks(inPassword, 0);
//
//		if (isCorrectSize(inPassword))
//			hashing(inPassword);
//
//		if (user[idxOfUser].password != inPassword)
//		{
//			system("cls");
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << " Password in incorrect";
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			cout << "\n\n 1) Reenter password \n 2) Return to previous menu \n\n";
//			cout << "____________________________";
//			cout << "\n\n Choose an operation : ";
//
//			do
//			{
//				cin >> choice;
//				if (choice == '1')
//					inPassword.clear();
//				else if (choice == '2')
//					returnTomain = 1;
//				else
//				{
//					system("cls");
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//					cout << " Invalid Choice";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//					cout << "\n\n 1) Reenter password \n 2) Return to previous menu \n\n";
//					cout << "____________________________";
//					cout << "\n\n Choose an operation : ";
//				}
//			} while (choice != '1' && choice != '2');
//		}
//		else
//			break;
//	}
//
//	return 0;
//}
//
//bool NewPasswordCheck(bool isSignUp)
//{
//
//	string newPassword = "", ErrorType;
//	bool returnToMenu = 0, containSpaces = 0, isValidNewPassword = 0;
//	char choice;
//
//	while (true)
//	{
//		if (returnToMenu)
//			return 1;
//
//		getPasswordWithAsterisks(newPassword, 1);
//
//		for (int i = 0; i < newPassword.size(); i++)
//		{
//			if (newPassword[i] == ' ')
//			{
//				containSpaces = 1;
//				break;
//			}
//		}
//
//		if (!isCorrectSize(newPassword) || containSpaces)
//			ErrorType = " Password must me between 8 and 20 charcters and it can not contain spaces.";
//		else if (isWeak(newPassword) || (newPassword == user[idxOfUser].username && isSignUp == 0) || (newPassword == tempUsername && isSignUp == 1))
//			ErrorType = " Password is too weak or common.";
//		else
//		{
//			hashing(newPassword);
//
//			if (newPassword == user[idxOfUser].password)
//				ErrorType = " New password is the same as your current one.";
//			else
//				isValidNewPassword = 1;
//		}
//
//		if (!isValidNewPassword)
//		{
//			system("cls");
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << ErrorType;
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			cout << "\n\n 1) Reenter password \n 2) Return to previous menu \n\n";
//			cout << "____________________________";
//			cout << "\n\n Choose an operation : ";
//
//			do
//			{
//				cin >> choice;
//				if (choice == '1')
//					newPassword.clear();
//				else if (choice == '2')
//					returnToMenu = 1;
//				else
//				{
//					system("cls");
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//					cout << " Invalid Choice";
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//					cout << "\n\n 1) Reenter password \n 2) Return to previous menu \n\n";
//					cout << "____________________________";
//					cout << "\n\n Choose an operation : ";
//				}
//			} while (choice != '1' && choice != '2');
//
//		}
//		else
//			break;
//
//	}
//
//
//	if (isSignUp)
//	{
//		++MaxUsersIdx;
//		idxOfUser = MaxUsersIdx;
//		user[idxOfUser].username = tempUsername;
//	}
//
//	user[idxOfUser].password = newPassword;
//	return 0;
//
//}
//
//void signUp()
//{
//	if (UsernameSignUpCheck() || NewPasswordCheck(1))
//	{
//		return;
//	}
//	else
//	{
//		isUserMenuReq = 1;
//		return;
//	}
//}
//
//void logIn()
//{
//
//	if (UsernameSignInCheck() || CurrentPasswordCheck())
//	{
//		return;
//	}
//	else if (user[idxOfUser].isAdmin == 1)
//	{
//		isAdminMenuReq = 1;
//		return;
//	}
//	else
//	{
//		isUserMenuReq = 1;
//		return;
//	}
//
//}
//
//void changeUsername()
//{
//	if (CurrentPasswordCheck() || NewUsernameCheck())
//		return;
//	else
//	{
//		system("cls");
//		cout << "Username has been changed successfully\n";
//	}
//}
//
//void changePassword()
//{
//	if (CurrentPasswordCheck() || NewPasswordCheck(0))
//		return;
//	else
//	{
//		system("cls");
//		cout << "Password has been changed successfully\n";
//	}
//}
//
//void FilestoArray_users()
//{
//	string Transformer;
//
//	int i = 0, Trio_Counter = 1;
//
//	Users.open("users.txt", ios::in);
//
//	while (getline(Users, Transformer))
//
//	{
//		if (Trio_Counter == 1)
//		{
//			user[i].username = Transformer;
//			++Trio_Counter;
//		}
//
//		else if (Trio_Counter == 2)
//		{
//			user[i].password = Transformer;
//			++Trio_Counter;
//		}
//
//		else if (Trio_Counter == 3)
//		{
//			if (Transformer == "1")
//				user[i].isAdmin = true, adminsNum++;
//
//			else if (Transformer == "0")
//				user[i].isAdmin = false;
//
//			++Trio_Counter;
//		}
//
//		else
//		{
//			if (Transformer == "1")
//				user[i].authorized = true;
//
//			else if (Transformer == "0")
//				user[i].authorized = false;
//			Trio_Counter = 1;
//			++i;
//		}
//
//
//
//	}
//	MaxUsersIdx = i - 1;
//}
//
//void ArraytoFiles_users()
//{
//
//	Users.open("users.txt", std::ofstream::out | std::ofstream::trunc);
//	Users.close();
//
//	Users.open("users.txt", ios::out);
//	if (Users.is_open())
//	{
//		for (int i = 0; i <= MaxUsersIdx; i++)
//		{
//			Users << user[i].username + "\n";
//
//			Users << user[i].password + "\n";
//
//			if (user[i].isAdmin)
//				Users << "1\n";
//			else
//				Users << "0\n";
//
//			if (user[i].authorized)
//				Users << "1\n";
//			else
//				Users << "0\n";
//		}
//	}
//	Users.close();
//}
//
//void FilestoArray_weakPasswords()
//{
//	fstream weakPasswordsFile;
//	weakPasswordsFile.open("weakPasswords.txt", ios::in);
//
//	if (weakPasswordsFile.is_open())
//	{
//		int i = 0;
//		string line;
//		while (getline(weakPasswordsFile, line))
//		{
//			weakPasswords_arr[i] = line;
//			i++;
//			if (i >= 10000)
//				return;
//		}
//		weakPasswordsFile.close();
//	}
//}
//
//bool isWeak(string& password)
//{
//	int start = 0, end = 9999, mid;
//
//	while (start <= end)
//	{
//		mid = (start + end) / 2;
//
//		if (weakPasswords_arr[mid] == password)
//			return 1;
//		else if (weakPasswords_arr[mid] < password)
//			start = mid + 1;
//		else
//			end = mid - 1;
//	}
//
//	return 0;
//}
//
//void hashing(string& password)
//{
//	long long hashedPassword1 = 0, hashedPassword2 = 0, hashedPasswordFinal;
//	long long mod1 = 999999733, mod2 = 999985379, mod3 = 1000000007, PrimePowI;
//
//	for (int i = 0; i < 5; i++)
//	{
//		PrimePowI = ((long long int)pow(3, i)) % mod1;
//		hashedPassword1 = ((hashedPassword1 % mod1) + ((password[i] % mod1) * (PrimePowI % mod1)) % mod1) % mod1;
//	}
//
//	for (int i = 0; i < password.size(); i++)
//	{
//		PrimePowI = ((long long int)pow(5, i)) % mod2;
//		hashedPassword2 = ((hashedPassword2 % mod2) + ((password[i] % mod2) * (PrimePowI % mod2)) % mod2) % mod2;
//	}
//
//	hashedPasswordFinal = ((hashedPassword1 % mod3) * (hashedPassword2 % mod3)) % mod3;
//	password = to_string(hashedPasswordFinal);
//}
//
//void toFile_reports() {
//	reportsFile.open("reports.txt", ios::out);
//	for (int i = 0; i <= reportsNum; i++)
//
//	{
//		reportsFile << report[i].description << endl;
//		reportsFile << report[i].location << endl;
//		reportsFile << report[i].type << endl;
//		reportsFile << report[i].health_situation << endl;
//		if (report[i].isAdopted)
//		{
//			reportsFile << '1' << endl;
//			reportsFile << to_string(report[i].adoption_user_idx) << endl;
//		}
//		else
//		{
//			reportsFile << '0' << endl;
//			reportsFile << "-1" << endl;//this means : no one has adopted this animal (-1 is basically a garbage data in this situation)
//
//		}
//
//		if (report[i].isConfirmed == 1)
//			reportsFile << '1' << endl;
//		else if (report[i].isConfirmed == 0)
//			reportsFile << '0' << endl;
//		else
//			reportsFile << "-1" << endl;
//
//
//		reportsFile << to_string(report[i].report_user_idx) << endl;
//
//	}
//
//
//	reportsFile.close();
//
//
//
//}
//
//void fromFile_reports() {
//	reportsFile.open("reports.txt", ios::in);//read from file
//	for (int i = 0; i <= reportsNum; i++)
//
//	{
//		string isConfirmed_str = "is", isAdopted_str = "is", user_idx_str = "100", adopted_user_str;
//
//		getline(reportsFile, report[i].description);
//		getline(reportsFile, report[i].location);
//		getline(reportsFile, report[i].type);
//		getline(reportsFile, report[i].health_situation);
//		getline(reportsFile, isAdopted_str);
//		if (isAdopted_str == "1")
//			report[i].isAdopted = true;
//		else
//			report[i].isAdopted = false;
//		getline(reportsFile, adopted_user_str);
//		report[i].adoption_user_idx = stoi(adopted_user_str);
//		getline(reportsFile, isConfirmed_str);
//		report[i].isConfirmed = stoi(isConfirmed_str);
//		getline(reportsFile, user_idx_str);
//		report[i].report_user_idx = stoi(user_idx_str);
//
//	}
//	reportsFile.close();
//
//
//
//
//}
//
//void store_num_of_reports() {
//	reportsNumberFile.open("reportsNum.txt", ios::out);
//	reportsNumberFile << to_string(reportsNum);
//	reportsNumberFile.close();
//}
//
//void how_many_reports() {
//	string report;
//	reportsNumberFile.open("reportsNum.txt", ios::in);
//	getline(reportsNumberFile, report);
//	reportsNum = stoi(report);
//	reportsNumberFile.close();
//}
//
//void addToFile_donation() {
//	ofstream myfile;
//	myfile.open("donate.txt", ios::out);
//
//	for (int i = 0; i <= MaxUsersIdx; i++) {
//
//		myfile << i << endl;
//		myfile << donation[i] << endl;
//
//	}
//	myfile.close();
//
//}
//
//void addToArray_donation() {
//
//	int j = 1, emp_idx, emp;
//	ifstream myfile("donate.txt", ios::in);
//	while (myfile >> emp) {
//		if (j == 1) {
//			j++;
//			emp_idx = emp;
//		}
//		else if (j == 2) {
//			donation[emp_idx] = emp;
//			totalDonations += donation[emp_idx];
//			j = 1;
//		}
//	}myfile.close();
//}
//
//void messagesToFile()
//{
//	Communication.open("communication.txt", ios::out);
//
//	if (Communication.is_open())
//	{
//		for (int i = 0; i <= MaxUsersIdx; i++)
//
//			for (int j = 0; j <= user[i].totalMessages; j++)
//
//				Communication << user[i].messages[j] << endl;
//	}
//
//	Communication.close();
//}
//
//bool sendingMessages(long long targetedUser)
//{
//	string tempMessage, AdminDemo = "Admin : ", UserDemo = "User : ";
//
//	if (user[idxOfUser].isAdmin == true)
//	{
//		for (int j = 0; j <= user[targetedUser].totalMessages; j++)
//		{
//			if (user[targetedUser].messages[j] == "la fin")
//			{
//				cout << "Admin :" << "\t";
//
//				getline(cin, tempMessage);
//
//				if (tempMessage == "EXIT")
//					return 0;
//				else
//					user[targetedUser].messages[j] = AdminDemo + tempMessage;
//			}
//			else
//				continue;
//		}
//
//		user[targetedUser].messages[0] = "le debut" + to_string(targetedUser + 1);
//
//		while (true)
//		{
//			cout << "Admin :" << "\t";
//
//			getline(cin, tempMessage);
//
//			if (tempMessage == "EXIT")
//				break;
//			else
//			{
//				++user[targetedUser].totalMessages;
//
//				user[targetedUser].messages[user[targetedUser].totalMessages] = AdminDemo + tempMessage;
//			}
//		}
//		++user[targetedUser].totalMessages;
//
//		user[targetedUser].messages[user[targetedUser].totalMessages] = "la fin";
//	}
//
//	else
//	{
//		user[idxOfUser].messages[0] = "le debut" + to_string(idxOfUser + 1);
//
//		for (int j = 0; j <= user[idxOfUser].totalMessages; j++)
//		{
//			if (user[idxOfUser].messages[j] == "la fin")
//			{
//				cout << "User :" << "\t";
//
//				getline(cin, tempMessage);
//
//				if (tempMessage == "EXIT")
//					return 0;
//				else
//					user[idxOfUser].messages[j] = UserDemo + tempMessage;
//			}
//			else
//				continue;
//		}
//
//		while (true)
//		{
//			cout << "User :" << "\t";
//
//			getline(cin, tempMessage);
//
//			if (tempMessage == "EXIT")
//				break;
//			else
//			{
//				user[idxOfUser].totalMessages++;
//				user[idxOfUser].messages[user[idxOfUser].totalMessages] = UserDemo + tempMessage;
//			}
//		}
//		++user[idxOfUser].totalMessages;
//		user[idxOfUser].messages[user[idxOfUser].totalMessages] = "la fin";
//	}
//}
//
//bool viewingMessages()
//{
//	string searchingUsername;
//
//	bool isFound = true;
//
//	if (user[idxOfUser].isAdmin != 1)
//	{
//		for (int j = 0; j < user[idxOfUser].totalMessages; j++)
//		{
//			if (user[idxOfUser].messages[j] == "le debut" + to_string(idxOfUser + 1))
//				continue;
//			else
//				cout << user[idxOfUser].messages[j] << endl;
//		}
//
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//		cout << "\n" << "\t" << "\t" << "\t" << "if you wanna exit the chat at any moment please enter EXIT" << endl;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//
//		sendingMessages(idxOfUser);
//	}
//
//	else
//	{
//		cout << " Please enter the username of the user you wanna contact with : " << "\t";
//		getline(cin, searchingUsername);
//
//		for (int i = 0; i <= MaxUsersIdx; i++)
//		{
//			if (searchingUsername == user[i].username)
//			{
//				if (user[i].isAdmin != 1)
//				{
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//					cout << "\t" << "\t" << "\t" << "\t" << "\t" << "USER FOUND" << endl;
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//					foundUseridx = i;
//
//					for (int j = 0; j < user[i].totalMessages; j++)
//					{
//						if (user[foundUseridx].messages[j] == "le debut" + to_string(foundUseridx + 1))
//							continue;
//						else
//							cout << user[i].messages[j] << endl;
//					}
//
//					isFound = true;
//
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//					cout << "\n" << "\t" << "\t" << "\t" << "if you wanna exit the chat at any moment please enter EXIT" << endl;
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//
//					break;
//				}
//				else
//				{
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//					cout << "\t" << "\t" << "Sorry! the option of communication with the person you searched for is not available" << endl;
//					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//					system("pause");
//					return 0;
//				}
//			}
//
//			else
//				isFound = false;
//		}
//
//		if (!isFound)
//		{
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << "\t" << "\t" << "\t" << "\t" << " SORRY USER NOT FOUND" << endl;
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			system("pause");
//		}
//		else if (isFound)
//			sendingMessages(foundUseridx);
//	}
//}
//
//void fileToMessages()
//{
//	string messagesUploader;
//
//	long long usersCounter = 0;
//
//	bool userMessagesFound = false, continueSearching = false;
//
//	Communication.open("communication.txt", ios::in);
//
//	user[usersCounter].totalMessages = 0;
//
//	if (Communication.is_open())
//	{
//		while (getline(Communication, messagesUploader))
//		{
//			if (messagesUploader.length() == 0)
//
//				continueSearching = true;
//
//			else if (messagesUploader.length() != 0 && continueSearching == true && messagesUploader != "le debut" + to_string(usersCounter + 1))
//			{
//				for (long long bingoNum = 1; bingoNum <= MaxUsersIdx + 1; bingoNum++)
//				{
//					if (messagesUploader == "le debut" + to_string(bingoNum))
//					{
//						usersCounter = bingoNum - 1;
//
//						continueSearching = false;
//
//						break;
//					}
//				}
//			}
//			if (messagesUploader == "le debut" + to_string(usersCounter + 1) && continueSearching == false)
//
//				userMessagesFound = true;
//
//			if (userMessagesFound == true && messagesUploader != "la fin")
//			{
//				if (messagesUploader.length() != 0)
//				{
//					user[usersCounter].messages[user[usersCounter].totalMessages] = messagesUploader;
//
//					user[usersCounter].totalMessages++;
//				}
//				else
//					continue;
//			}
//			else if (userMessagesFound == true && messagesUploader == "la fin")
//			{
//				user[usersCounter].messages[user[usersCounter].totalMessages] = messagesUploader;
//
//				usersCounter++;
//
//				user[usersCounter].totalMessages = 0;
//
//			}
//		}
//	}
//
//	Communication.close();
//}
//
//void moneyValidation() {
//	int money;
//	bool goodmoney = 0;
//	while (goodmoney == 0) {
//		system("cls");
//		char option;
//		if (isActivecc) {
//			cout << " Enter the amount of money you want to donate : ";
//			cin >> money;
//			if (money < 1000 && money > 0) {
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//				cout << " Thanks for your donation " << endl;
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//				donation[idxOfUser] += money;
//				totalDonations += money;
//				system("pause");
//				return;
//			}
//			else {
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//				cout << " You must donate money between 1$ - 1000$ " << endl;
//				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//				cout << " Enter 1 to re enter or any other number to cancel : ";
//				cin >> option;
//				if (option == '1') {
//					continue;
//				}
//				else {
//					break;
//				}
//			}
//		}
//		else {
//			break;
//		}
//	}
//}
//
//void creditValidation() {
//	string creditcard;
//	int digitCnt, totaleven, totalodd, total; char choice;
//	bool isValidcc = 0, isNotnum = 0;
//
//	do {
//		system("cls");
//		cout << "Enter your credit card number (without spaces) : ";
//		cin >> creditcard;
//
//		digitCnt = creditcard.size();
//
//		for (int i = 0; i < creditcard.size(); i++)
//		{
//			switch (creditcard[i])
//			{
//			case '1': break;
//			case '2': break;
//			case '3': break;
//			case '4': break;
//			case '5': break;
//			case '6': break;
//			case '7': break;
//			case '8': break;
//			case '9': break;
//			case '0': break;
//			default: isNotnum = 1;
//			}
//
//		}
//		if (isNotnum || digitCnt > 16 || digitCnt < 13) {
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << " Wrong input " << endl;
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			cout << " Enter 1 to re enter or any number to exit :";
//
//			cin >> choice;
//			if (choice == '1') {
//				isNotnum = 0;
//				continue;
//			}
//			else {
//				isActivecc = 0;
//				break;
//			}
//		}
//		total = 0;
//		totaleven = 0;
//		totalodd = 0;
//		for (int i = 0; i < digitCnt; i++)
//		{
//
//			if (i % 2 != 0)
//			{
//				totalodd += (creditcard[i] - '0');
//			}
//			else if (i % 2 == 0 && (creditcard[i] - '0') <= 4) {
//
//
//				totaleven += (creditcard[i] - '0') * 2;
//			}
//			else if (i % 2 == 0 && (creditcard[i] - '0') > 4)
//			{
//				int x = (creditcard[i] - '0') * 2;
//				int y = x % 10;
//				x = x / 10;
//				totaleven = totaleven + (x + y);
//			}
//
//		}
//		total = totaleven + totalodd;
//		if (total % 10 == 0) {
//			isValidcc = 1;
//			isActivecc = 1;
//			cout << " Valid credit card" << endl;
//			break;
//		}
//		else {
//			isValidcc = 0;
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
//			cout << " Invalid credit card" << endl;
//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
//			cout << " Enter 1 to re enter or any number to exit :" << endl;
//			cin >> choice;
//			if (choice == '1') {
//				continue;
//			}
//			else {
//				isActivecc = 0;
//				break;
//			}
//		}
//
//
//	} while (!(digitCnt >= 13 && digitCnt <= 16 && isValidcc == 1));
//}
//
//void displayDonations_admin()
//{
//	system("cls");
//	cout << "\n";
//	cout.width(78);
//	cout << "L I S T  O F  A L L  D O N A T I O N S!\n";
//	cout.width(79);
//	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
//	if (totalDonations > 0)
//	{
//		cout << "Username:\t  Money donated:\n";
//		cout << "------------------------------------\n";
//	}
//	int count = 1;
//	for (int i = 0; i <= MaxUsersIdx; i++)
//	{
//		if (donation[i] > 0)
//		{
//			cout << count << "- " << user[i].username << "\t\t\t" << donation[i] << '\n';
//			count++;
//			cout << "------------------------------------\n";
//		}
//	}
//	cout << "TOTAL MONEY DONATED :           " << totalDonations << '\n';
//	system("pause");
//}
//
//void displayDonations_user()
//{
//	cout << " TOTAL MONEY DONATED : " << totalDonations << '\n';
//	system("pause");
//}
//
//void exitFun()
//{
//	system("cls");
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
//	cout << "\n\n";
//	cout.width(81);
//	cout << "Thank you for using Paws 'N' Claws!\n\n";
//
//	addToFile_donation();
//	store_num_of_reports();
//	toFile_reports();
//	ArraytoFiles_users();
//	messagesToFile();
//	exit(0);
//}
//
