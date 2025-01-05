/* PROJECT NAME :- CANTEEN BILLING SYSTEM IN C++ */
/* HEADER FILES*/
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <fstream>
using namespace std;
fstream file, file1;        /* DECLARATION OF FILE FOR STORING PRODUCT DATA */
/* CLASS FOR CANTEEN */
class product
{
private:
    /* DECALARATION OF CLASS VARIABLE IN PRIVATE ACCESS SPECIFER */
    int pno;
    string name;
    float price, qty;
public: 
    /* DECALARATION OF CLASS FUNCTION IN PUBLIC ACCESS SPECIFER*/
    void create();
    void show();
    void write();
    void display();
    void admin();
    void search(int n);
    void modify(int n);
    void del(int n);
    void order();
    void menu();
};
/*                  DEFINATION OF CLASS FUNCTION                   */
    /*FUNCTION OF ADMIN SECTION */
void product ::create()         /* TO GET PRODUCT DATA FROM ADMIN */
{
    cout << "\n\n Please Enter The Product No. of The Product : ";
    cin >> pno;
    cout << "\n\n Please Enter The Name of The Product : ";
    cin >> name;
    cout << "\n\n Please Enter The Price of The Product : ";
    cin >> price;
}
void product ::show()           /* TO SHOW PRODUCT DATA TO ADMIN */
{ 
    cout << "\nProduct No. \t\t:\t" << pno;
    cout << "\nName of The Product \t:\t" << name;
    cout << "\nPrice of The Product \t:\t" << price;
}
void product ::write()          /* TO STORE PRODUCT DATA IN SHOP.TXT FILE */
{
    file.open("shop.txt", ios::out | ios::app);
    create();
    file << " " << pno << " " << name << " " << price << " ";
    file.close();
    cout << "\n\nThe Product Has Been Created ";
    getch();
}
void product ::display()        /* TO DISPLAY PRODUCT DATA FORM SHOOP.TXT FILE */ 
{
    system("cls");
    cout << "\n\n\t\tProduct Menu!!!\n\n";
    cout << "==================================================";
    file.open("shop.txt", ios::in);
    if (!file)
        admin();
    file >> pno >> name >> price;
    while (!file.eof())
    {
        show();
        cout << "\n\n==================================================";
        file >> pno >> name >> price;
    }
    file.close();
    getch();
}
void product ::search(int n)        /* TO SEARCH PRODUCT DATA IN SHOP.TXT FILE */ 
{
    int found = 0;                 /* FLAG FOR IDENTIFING PROCESS HAS BEEN DONE OR NOT */
    file.open("shop.txt", ios::in);
    if (!file)
        admin();
    file >> pno >> name >> price;
    while (!file.eof())
    {
        if (pno == n)
        {
            system("cls");
            show();
            found = 1;
        }
        file >> pno >> name >> price;
    }
    file.close();
    if (found == 0)
        cout << "\n\nRecord Not Exist...";
    getch();
}
void product ::modify(int n)            /* TO MODIFY PRODUCT DATA IN SHOP.TXT FILE */ 
{
    int found = 0;                      /* FLAG FOR IDENTIFING PROCESS HAS BEEN DONE OR NOT */
    system("cls");
    cout << "\n\n\tTo Modify";
    file.open("shop.txt", ios::in);
    if (!file)
        admin();
    file1.open("shop1.txt", ios::out | ios::app);
    file >> pno >> name >> price;
    while (!file.eof())
    {
        if (pno == n)
        {
            show();
            cout << "\n\n Please Enter The New Detail";
            create();
            file1 << " " << pno << " " << name << " " << price << " ";
            cout << "\n\n\tRecord Updated Successfully...";
            found = 1;
        }
        else
            file1 << " " << pno << " " << name << " " << price << " ";
        file >> pno >> name >> price;
    }
    file.close();
    file1.close();
    remove("shop1.txt");
    rename("shop1.txt", "shop.txt");
    if (found == 0)
        cout << "\n\n Record Not Found ";
    getch();
}
void product ::del(int n)             /* TO DELETE PRODUCT DATA IN SHOP.TXT FILE */ 
{
    int found = 0;                    /* FLAG FOR IDENTIFING PROCESS HAS BEEN DONE OR NOT */
    file.open("shop.txt", ios::in);
    if (!file)
        admin();
    file1.open("shop1.txt", ios::out);
    file >> pno >> name >> price;
    while (!file.eof())
    {
        if (pno == n)
        {
            cout << "\n\n\t Record Deleted";
            found = 1;
        }
        else
            file1 << " " << pno << " " << name << " " << price << " ";
        file >> pno >> name >> price;
    }
    file.close();
    file1.close();
    remove("shop.txt");
    rename("shop1.txt", "shop.txt");
    if (found == 0)
        cout << "\n\n Record Not Found ";
    getch();
}
void product ::admin()          /* ADMIN FUNCTION TO MANIPULATE PRODUCT DATA STORED IN SHOP.TXT FILE */
{
    system("cls");
    int choice, num;
    cout << "\t\t\t***********ADMIN MENU*************" << endl;
    cout << "\t\t\t1.Create Product" << endl;
    cout << "\t\t\t2.Display All Product" << endl;
    cout << "\t\t\t3.Search Product" << endl;
    cout << "\t\t\t4.Modify Product" << endl;
    cout << "\t\t\t5.Delete Product" << endl;
    cout << "\t\t\t6.Back To Menu" << endl;
    cout << "\t\t\t**********************************" << endl;
    cout << "\t\t\tEnter your choice :";
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        write();
        break;
    case 2:
        display();
        break;
    case 3:
        system("cls");
        cout << "Please enter the product no to search : ";
        cin >> num;
        search(num);
        break;
    case 4:
        system("cls");
        cout << "Please enter the product no to modify : ";
        cin >> num;
        modify(num);
        break;
    case 5:
        system("cls");
        cout << "Please enter the product no to delete : ";
        cin >> num;
        del(num);
        break;
    case 6:
        break;
    default:
        cout << "Invalid record";
    }
}
/* FUNCTIONS OF CUSTOMER SECTION */
void product::menu()                    /* TO DISPLAY MENU CARD TO THE CUSTOMER */
{       
    system("cls");
    file.open("shop.txt", ios::in);
    cout << "PRODUCT MENU" << endl;
    cout << "============================================" << endl;
    cout << "P.NO\t\tNAME\t\tPRICE\n";
    cout << "============================================" << endl;
    file >> pno >> name >> price;
    while (!file.eof())
    {
        cout << pno << "\t\t" << name << "\t\t" << price << endl;
        file >> pno >> name >> price;
    }
    cout << "============================================" << endl;
    file.close();
    cout << "Press Enter to Place Order ->" << endl;
    getch();
}
void product::order()                   /* TO PLACE THE ORDER FROM CUSTOMER */
{
    int order_arr[50], quan[50], c = 0;
    float amt = 0, total = 0;
    char ch;
    file.open("shop.txt", ios::in);
    if (file)
    {
        file.close();
        menu();
        cout << endl
             << "================================================================================" << endl;
        cout << "PLACE YOUR ORDER" << endl;
        cout << "================================================================================" << endl;
        do
        {
            cout << "Enter the product no. of the product : ";
            cin >> order_arr[c];
            cout << endl
                 << "Quantity in number : ";
            cin >> quan[c];
            c++;
            cout << endl
                 << "Do you want to order another product [y/n] : ";
            cin >> ch;
            cout << "=============================================================================" << endl;
        } while (ch == 'y' || ch == 'Y');
        system("cls");
        cout << endl
             << "Thank you for placing order !!!" << endl;
        cout << "==========================================================";
        cout << "\n No \t Name \t\t Quantity \tPrice \tAmount \t " << endl;
        for (int x = 0; x <= c; x++)
        {
            file.open("shop.txt", ios::in);
            file >> pno >> name >> price;
            while (!file.eof())
            {
                if (pno == order_arr[x])
                {
                    amt = price * quan[x];
                    cout << "\n"
                         << order_arr[x] << "\t" << name << "\t\t" << quan[x] << "\t\t" << price << "\t" << amt << "\t\t" << endl;
                    total += amt;
                }
                file >> pno >> name >> price;
            }
            file.close();
        }
        cout << "==========================================================" << endl;
        cout << "\n\t\t\t\tTOTAL AMOUNT : RS." << total<<endl;
        cout << "==========================================================" << endl;
        getch();
    }
}
/* MAIN FUNCTION */
int main()
{
    product p;                  /*  PRODUCT CLASS OBJECT - p */
start:
    int choice;
    system("cls");
    system("color 0E");
    cout << "\t\t************MAIN MENU*************\n";
    cout << "\t\t\t1.CUSTOMER" << endl;
    cout << "\t\t\t2.ADMIN" << endl;
    cout << "\t\t\t3.EXIT" << endl;
    cout << "\t\t*************************\n";
    cout << "\t\tEnter choice : \t";
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        p.order();
        getch();
        break;
    case 2:
        p.admin();
        break;
    case 3:
        exit(0);
    default:
        cout << "Invalid Input";
    }
    goto start;
    return 0;
}