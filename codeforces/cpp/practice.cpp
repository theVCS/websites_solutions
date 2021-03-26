#include <iostream>
#include <fstream>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <direct.h>
#include <windows.h>
#include <time.h>
#include <algorithm>
using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class product_detail
{
private:
    int pid;
    string pname;
    float pquantity;

public:
    void add_product();
    void delete_product();
    void modify_product();
    void display_product();
};
void product_detail ::display_product()
{
    char choice;
    system("CLS");

    ifstream fp("PRODUCT_DETAIL.txt");

    int row = 6, found = 0;
    gotoxy(30, 2);
    cout << "LIST OF ITEMS";
    gotoxy(3, 4);
    cout << "PRODUCT ID   PRODUCT NAME    PRODUCT QUANTITY  ";
    gotoxy(2, 5);
    cout << "**************************************************";

    product_detail obj;

    while (!fp.eof())
    {
        found = 1;

        fp >> obj.pid;

        if (obj.pid == 0)
            break;

        fp >> obj.pname;
        fp >> obj.pquantity;

        gotoxy(5, row);
        cout << obj.pid;
        gotoxy(20, row);
        cout << obj.pname;
        gotoxy(37, row);
        cout << obj.pquantity;
        row++;
    }
    fp.close();
    if (found == 0)
    {
        gotoxy(5, 10);
        cout << "\nRecords not found\n";
    }
    gotoxy(1, 25);
    cout << endl;
    cout << "DO YOU WANT TO ADD ANY PRODUCT DETAIL(Y/N)\n";
    choice = getche();
    choice = toupper(choice);
    if (choice == 'Y')
    {
        product_detail c;
        c.add_product();
    }
}
void product_detail ::add_product()
{
    char choice;
    cout << "\nenter product id:";
    cin >> pid;
    cout << "enter product name:";
    cin.ignore();
    getline(cin, pname);
    transform(pname.begin(), pname.end(), pname.begin(), ::toupper);
    cout << "enter quantity of the product:";
    cin >> pquantity;
    cout << "\nDO YOU WANT TO SAVE THIS PRODUCT(Y/N)";
    choice = getche();
    choice = toupper(choice);

    if (choice == 'Y')
    {
        ofstream fp("PRODUCT_DETAIL.txt", ios::app);
        fp << pid << " " << pname << " " << pquantity << endl;
        fp.close();
    }
}
int main()
{
    system("CLS");
    char ch;
    while (1)
    {
        system("CLS");
        cout << "\n1: PRODUCT DETAIL";
        cout << "\n0: QUIT";
        cout << "\nEnter Your Choice :\n ";
        cin >> ch;
        if (ch == '1')
        {
            system("CLS");
            product_detail p;
            p.display_product();
        }
    }
    return 0;
}