/*************************************
 Program:   VENDING_MACHINE_SIMULATOR.cpp
 Course:    Programming Fundamentals
 Year:      2014/15 Trimester 2
 Name:      MAH SIEW CHIN
 ID:        1132702455
 Lecture:   TC01
 Lab:       TT01
 Email:     chris88chris88@hotmail.com
 Phone:     012-329 7678
 *************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

void MMU_Soda(); //MMU_soda function
void MMU_Orange(); //MMU_Orange function
void MMU_Lychee(); //MMU_lychee function
float soda_price = 0.80; //initialized MMU soda price RM0.80
float orange_price = 1.00; //initialized MMU Orange price RM1.00
float lychee_price = 1.40; //initialized MMU Lychee price RM1.40
int qty_ringgit_5 = 0; //initialized quantity zero units in RM5.00 storage bin (max store 20 units)
int qty_ringgit_1 = 10; //initialized quantity 10 units in RM1.00 storage bin (max store 20 units)
int qty_cts_50 = 10; //initialized quantity 10 units in RM0.50 storage bin (max store 20 units)
int qty_cts_20 = 10; //initialized quantity 10 units in RM0.20 storage bin (max store 20 units)
int qty_cts_10 =  0; //initialized quantity 0 units in RM0.10 storage bin (max store 20 units)
int initial_qty_soda = 5; //initialized quantity 5 units MMU soda drink
int initial_qty_orange = 4; //initialized quantity 4 units MMU orange drink
int initial_qty_lychee = 3; //initialized quantity 3 units MMU Lychee drink
float ringgit_5 = 5.00; //set variable RM5.00 easy to re-use
float ringgit_1 = 1.00; //set variable RM1.00 easy to re-use
float cts_50 = 0.50; //set variable RM0.50 easy to re-use
float cts_20 = 0.20; //set variable RM0.20 easy to re-use
float cts_10 = 0.10; //set variable RM0.10 easy to re-use

//main menu page
int main ()
{
    char purchase; //selection variable

    system("cls"); //clear screen
    cout << fixed << setprecision(2); //set 2 digits of precision
    cout << "a)" << setw(3) << "" << "MMU Soda  " << setw(6) << "" << "RM" << soda_price << setw(3) << "" << (initial_qty_soda == 0 ? " [ Sold Out ]" : "") << endl; //if initial qty soda drink is zero. it displays sold out.
    cout << "b)" << setw(3) << "" << "MMU Orange" << setw(6) << "" << "RM" << orange_price << setw(3) << ""<< (initial_qty_orange == 0 ? " [ Sold Out ]" : "") << endl; //if initial qty orange drink is zero. it displays sold out.
    cout << "c)" << setw(3) << "" << "MMU Lychee" << setw(6) << "" << "RM" << lychee_price << setw(3) << ""<< (initial_qty_lychee == 0 ? " [ Sold Out ]" : "") << endl; //if initial qty lychee drink is zero. it displays sold out.
    cout << "d)" << setw(3) << "" << "Quit" << endl << endl;

    cout << "Purchase (a to c) => ";
    cin  >> purchase;

        if ((purchase == 'A') || (purchase == 'a') && (initial_qty_soda > 0))
            MMU_Soda(); //call MMU_soda function
        else if ((purchase == 'B') || (purchase == 'b') && (initial_qty_orange > 0))
            MMU_Orange(); //call MMU_Orange function
        else if ((purchase == 'C') || (purchase == 'c') && (initial_qty_lychee > 0))
            MMU_Lychee(); //call MMU_Lychee function
        else if ((purchase == 'D') || (purchase == 'd'))
            exit (0); //Exit the program
        else
        {
            cout << "Selected item sold out or invalid selection." << endl;
            system("pause");
            main(); //return to main menu page
        }

        return 0;
}

//MMU soda menu
void MMU_Soda()
{

    float amt_paid = 0.00; //initialized amount paid RM0.00
    char amt_insert; //variable for amount insert
    float change = 0.00; //variable for amount change dispense
    float return_change = 0.00;  //variable for amount return
    int qty_dispensed_ringgit5 = 0; //initialized quantity dispense zero units for RM5.00
    int qty_dispensed_ringgit1 = 0; //initialized quantity dispense zero units for RM1.00
    int qty_dispensed_cts50 = 0; //initialized quantity dispense zero units for RM0.50
    int qty_dispensed_cts20 = 0; //initialized quantity dispense zero units for RM0.20
    int qty_dispensed_cts10 = 0; //initialized quantity dispense zero units for RM0.10

    //amount insert menu for insert amount while amount paid is less than MMU soda price
    while (amt_paid < soda_price)
    {
        //Amount insert page
        system("cls");
        cout << fixed << setprecision(2);
        cout << "Purchase of MMU Soda" << setw(3) << "" << "RM" << soda_price << endl;
        cout << "Amount paid         " << setw(3) << "" << "RM" << amt_paid << endl << endl;
        cout << "Insert" << endl;
        cout << "a)" << setw(3) << "" << "RM5" << endl;
        cout << "b)" << setw(3) << "" << "RM1" << endl;
        cout << "c)" << setw(3) << "" << "RM0.50" << endl;
        cout << "d)" << setw(3) << "" << "RM0.20" << endl;
        cout << "e)" << setw(3) << "" << "RM0.10" << endl;
        cout << "f)" << setw(3) << "" << "Cancel order" << endl << endl;
        cout << "Pay (a to f) => ";
        cin  >> amt_insert;

        //update the amount paid and quantity in storage bin according selection make
        if (((amt_insert == 'A') || (amt_insert == 'a')) && (qty_ringgit_5 < 20))
        {
            amt_paid = amt_paid + ringgit_5;
            qty_ringgit_5 += 1;
        }
        else if (((amt_insert == 'B') || (amt_insert == 'b')) && (qty_ringgit_1 < 20))
        {
            amt_paid = amt_paid + ringgit_1;
            qty_ringgit_1 += 1;
        }
        else if (((amt_insert == 'C') || (amt_insert == 'c')) && (qty_cts_50 < 20))
        {
            amt_paid = amt_paid + cts_50;
            qty_cts_50 += 1;
        }

        else if (((amt_insert == 'D') || (amt_insert == 'd')) && (qty_cts_20 < 20))
        {
            amt_paid = amt_paid + cts_20;
            qty_cts_20 += 1;
        }

        else if (((amt_insert == 'E') || (amt_insert == 'e')) && (qty_cts_10 < 20))
        {
            amt_paid = amt_paid + cts_10;
            qty_cts_10 += 1;

        }
        //user can cancel order either had insert some amount or none as long as not more than or equal to MMU soda price
        else if ((amt_insert == 'F') || (amt_insert == 'f'))
        {
            //Order cancel page
            cout << endl;
            cout << "Order Canceled !" << endl << endl;
            cout << "Payment returned : RM " << amt_paid << endl << endl;

            //calculate amount return to user if the user had insert some amount and update the qty of storage bin accordingly
            while (abs(amt_paid) > 0.0001)
            {
                if (amt_paid >= ringgit_5)
                {
                    amt_paid = amt_paid - ringgit_5;
                    qty_ringgit_5 -=1;
                }
                else if (amt_paid >= ringgit_1)
                {
                    amt_paid = amt_paid - ringgit_1;
                    qty_ringgit_1 -=1;
                }
                else if (amt_paid  >= cts_50)
                {
                    amt_paid = amt_paid - cts_50;
                    qty_cts_50 -=1;
                }
                else if (amt_paid >= cts_20)
                {
                    amt_paid = amt_paid - cts_20;
                    qty_cts_20 -=1;
                }
                else
                {
                    amt_paid = amt_paid - cts_10;
                    qty_cts_10 -=1;
                }
            }
            system("pause");
            main(); //return to main menu
        }
        else
        {
            //amt_paid won't store in the full storage bin and only return payment for storage bin less than 20 units//
            cout << "Sorry !" << endl;
            cout << "Payment returned : " << amt_paid << endl;

            //display full for notes and coins that their storage bin is full
            if (qty_ringgit_5 >= 20)
                cout << "RM5.00 full" << endl;
            if (qty_ringgit_1 >= 20)
                cout << "RM1.00 full" << endl;
            if (qty_cts_50 >= 20)
                cout << "RM0.50 full" << endl;
            if (qty_cts_20 >= 20)
                cout << "RM0.20 full" << endl;
            if (qty_cts_10 >= 20)
                cout << "RM0.10 full" << endl;

            //calculate amount return due to full storage bin and update the storage bin accordingly
            while (abs(amt_paid) > 0.0001)
            {
                if (amt_paid >= ringgit_5)
                {
                    amt_paid = amt_paid - ringgit_5;
                    qty_ringgit_5 -=1;
                }
                if (amt_paid >= ringgit_1)
                {
                    amt_paid = amt_paid - ringgit_1;
                    qty_ringgit_1 -=1;
                }
                if (amt_paid >= cts_50)
                {
                    amt_paid = amt_paid - cts_50;
                    qty_cts_50 -=1;
                }
                if (amt_paid >= cts_20)
                {
                    amt_paid = amt_paid - cts_20;
                    qty_cts_20 -=1;
                }
                if (amt_paid >= cts_10)
                {
                    amt_paid = amt_paid - cts_10;
                    qty_cts_10 -=1;
                }
            }
            system("pause");
            main(); //return to main menu
        }
    }

    change = amt_paid - soda_price; //calculate the balance change after amount insert

    //if balance change is zero, display order success and update the initial qty of MMU soda
    if (abs(change) < 0.0001)
    {
        //Order success page
        system("cls");
        initial_qty_soda -=1;
        cout << "Order Success !" << endl << endl;
        system ("pause");
        main();
    }
    else
    {
        //calculate balance change if more than zero by qty dispensed accordingly and update storage bin
        while (abs(change) > 0.0001)
        {

            if ((change >= ringgit_5) && (qty_ringgit_5 > 0))
            {
                change = change - ringgit_5;
                qty_dispensed_ringgit5 +=1;
                qty_ringgit_5 -=1;
            }

            else if ((change >= ringgit_1) && (qty_ringgit_1 > 0))
            {
                change = change - ringgit_1;
                qty_dispensed_ringgit1 +=1;
                qty_ringgit_1 -=1;
            }
            else if ((change + 0.0001 >= cts_50) && (qty_cts_50 > 0)) //added 0.0001 due to floating point can't calculate accurate amount
            {
                change = change - cts_50;
                qty_dispensed_cts50 +=1;
                qty_cts_50 -=1;
            }
            else if ((change + 0.0001 >= cts_20) && (qty_cts_20 > 0)) //added 0.0001 due to floating point can't calculate accurate amount
            {
                change = change - cts_20;
                qty_dispensed_cts20 +=1;
                qty_cts_20 -=1;
            }
            else if ((change + 0.00001 >= cts_10)&& (qty_cts_10 >0)) //added 0.0001 due to floating point can't calculate accurate amount
            {
                change = change - cts_10;
                qty_dispensed_cts10 +=1;
                qty_cts_10 -=1;
            }
            else //calculate amount return if one of the initial qty of storage bin found empty in qty dispense calculation and update storage bin
            {
                //Payment returned page
                system ("cls"); //clear screen
                cout << fixed << setprecision(2);
                cout << "Purchase of MMU Soda" << setw(3) << "" << "RM" << soda_price << endl;
                cout << "Amount paid         " << setw(3) << "" << "RM" << amt_paid << endl << endl;
                cout << "Payment returned    " << setw(3) << "" << "RM" << amt_paid << endl << endl;

                qty_ringgit_5 = qty_ringgit_5 + qty_dispensed_ringgit5;
                qty_ringgit_1 = qty_ringgit_1 + qty_dispensed_ringgit1;
                qty_cts_50    = qty_cts_50 + qty_dispensed_cts50;
                qty_cts_20    = qty_cts_20 + qty_dispensed_cts20;
                qty_cts_10    = qty_cts_10 + qty_dispensed_cts10;

                return_change = amt_paid - soda_price; //calculate amount return

                //display amount return change according notes and coins
                while (abs(return_change) > 0.0001)
                {
                    if (return_change >= ringgit_5)
                    {
                        return_change = return_change - ringgit_5;
                        cout << "Unable to dispense  " << setw(3) << "" << "RM" << ringgit_5 << " x 1" << endl;
                    }
                    else if (return_change >= ringgit_1)
                    {
                        return_change = return_change - ringgit_1;
                        cout << "Unable to dispense  " << setw(3) << "" << "RM" << ringgit_1 << " x 1" << endl;
                    }
                    else if (return_change >= cts_50)
                    {
                        return_change = return_change - cts_50;
                        cout << "Unable to dispense  " << setw(3) << "" << "RM" << cts_50 << " x 1" << endl;
                    }
                    else if (return_change >= cts_20)
                    {
                        return_change = return_change - cts_20;
                        cout << "Unable to dispense  " << setw(3) << "" << "RM" << cts_20 << " x 1" << endl;
                    }
                    else
                    {
                        return_change = return_change - cts_10;
                        cout << "Unable to dispense  " << setw(3) << "" << "RM" << cts_10 << " x 1" << endl;
                    }
                }

                //update storage bin accordingly from amount paid return
                while (abs(amt_paid) > 0.0001)
                {
                    if (amt_paid >= ringgit_5)
                    {
                        amt_paid = amt_paid - ringgit_5;
                        qty_ringgit_5 -=1;
                    }
                    else if (amt_paid >= ringgit_1)
                    {
                        amt_paid = amt_paid - ringgit_1;
                        qty_ringgit_1 -=1;
                    }
                    else if (amt_paid >= cts_50)
                    {
                        amt_paid = amt_paid - cts_50;
                        qty_cts_50 -=1;
                    }
                    else if (amt_paid >= cts_20)
                    {
                        amt_paid = amt_paid - cts_20;
                        qty_cts_20 -=1;
                    }
                    else
                    {
                        amt_paid = amt_paid - cts_10;
                        qty_cts_10 -=1;
                    }
                }

                cout << endl;
                system("pause");
                main(); //return main menu

            }
        }

        //change dispensed menu for display total qty dispensed accordingly if all storage bin is available to dispense accordingly
        if ((qty_dispensed_ringgit5 > 0) || (qty_dispensed_ringgit1 > 0)|| (qty_dispensed_cts50 > 0)|| (qty_dispensed_cts20 > 0) || (qty_dispensed_cts10 > 0))
        {
            //Change dispensed page
            system("cls"); //clear screen
            initial_qty_soda -=1; //order success and update initial qty MMU soda
            cout << fixed << setprecision(2);
            cout << "Purchase of MMU Soda" << setw(3) << "" << "RM" << soda_price << endl;
            cout << "Amount paid         " << setw(3) << "" << "RM" << amt_paid << endl << endl;
            cout << "Order Success !" << endl << endl;
            cout << "Change dispensed" << endl;

            //display qty dispensed accordingly
            if (qty_dispensed_ringgit5 > 0)
                cout << "RM5.00 x " << qty_dispensed_ringgit5 << endl;
            if (qty_dispensed_ringgit1 > 0)
                cout << "RM1.00 x " << qty_dispensed_ringgit1 << endl;
            if (qty_dispensed_cts50 > 0)
                cout << "RM0.50 x " << qty_dispensed_cts50 << endl;
            if (qty_dispensed_cts20 > 0)
                cout << "RM0.20 x " << qty_dispensed_cts20 << endl;
            if (qty_dispensed_cts10 > 0)
                cout << "RM0.10 x " << qty_dispensed_cts10 << endl;
            system("pause");
            main(); //return main menu
        }
    }
    return;
}


//MMU Orange menu
void MMU_Orange()
{
    float amt_paid = 0.00; //initialized amount paid RM0.00
    char amt_insert; //variable for amount insert
    float change = 0.00; //variable for amount change dispense
    float return_change = 0.00;  //variable for amount return
    int qty_dispensed_ringgit5 = 0; //initialized quantity dispense zero units for RM5.00
    int qty_dispensed_ringgit1 = 0; //initialized quantity dispense zero units for RM1.00
    int qty_dispensed_cts50 = 0; //initialized quantity dispense zero units for RM0.50
    int qty_dispensed_cts20 = 0; //initialized quantity dispense zero units for RM0.20
    int qty_dispensed_cts10 = 0; //initialized quantity dispense zero units for RM0.10

    //amount insert menu for insert amount while amount paid is less than MMU Orange price
    while (amt_paid < orange_price)
    {
        //Amount insert page
        system("cls");
        cout << fixed << setprecision(2);
        cout << "Purchase of MMU Orange" << setw(3) << "" << "RM" << orange_price << endl;
        cout << "Amount paid           " << setw(3) << "" << "RM" << amt_paid << endl << endl;
        cout << "Insert" << endl;
        cout << "a)" << setw(3) << "" << "RM5" << endl;
        cout << "b)" << setw(3) << "" << "RM1" << endl;
        cout << "c)" << setw(3) << "" << "RM0.50" << endl;
        cout << "d)" << setw(3) << "" << "RM0.20" << endl;
        cout << "e)" << setw(3) << "" << "RM0.10" << endl;
        cout << "f)" << setw(3) << "" << "Cancel order" << endl << endl;
        cout << "Pay (a to f) => ";
        cin  >> amt_insert;

        //update the amount paid and quantity in storage bin according selection make
        if (((amt_insert == 'A') || (amt_insert == 'a')) && (qty_ringgit_5 < 20))
        {
            amt_paid = amt_paid + ringgit_5;
            qty_ringgit_5 += 1;
        }
        else if (((amt_insert == 'B') || (amt_insert == 'b')) && (qty_ringgit_1 < 20))
        {
            amt_paid = amt_paid + ringgit_1;
            qty_ringgit_1 += 1;
        }
        else if (((amt_insert == 'C') || (amt_insert == 'c')) && (qty_cts_50 < 20))
        {
            amt_paid = amt_paid + cts_50;
            qty_cts_50 += 1;
        }

        else if (((amt_insert == 'D') || (amt_insert == 'd')) && (qty_cts_20 < 20))
        {
            amt_paid = amt_paid + cts_20;
            qty_cts_20 += 1;
        }

        else if (((amt_insert == 'E') || (amt_insert == 'e')) && (qty_cts_10 < 20))
        {
            amt_paid = amt_paid + cts_10;
            qty_cts_10 += 1;

        }
        //user can cancel order either had insert some amount or none as long as not more than or equal to MMU orange price
        else if ((amt_insert == 'F') || (amt_insert == 'f'))
        {
            //Order canceled page
            cout << endl;
            cout << "Order Canceled !" << endl << endl;
            cout << "Payment returned : RM " << amt_paid << endl << endl;

            //calculate amount return to user if the user had insert some amount and update the qty of storage bin accordingly
            while (abs(amt_paid) > 0.0001)
            {
                if (amt_paid >= ringgit_5)
                {
                    amt_paid = amt_paid - ringgit_5;
                    qty_ringgit_5 -=1;
                }
                else if (amt_paid >= ringgit_1)
                {
                    amt_paid = amt_paid - ringgit_1;
                    qty_ringgit_1 -=1;
                }
                else if (amt_paid  >= cts_50)
                {
                    amt_paid = amt_paid - cts_50;
                    qty_cts_50 -=1;
                }
                else if (amt_paid >= cts_20)
                {
                    amt_paid = amt_paid - cts_20;
                    qty_cts_20 -=1;
                }
                else
                {
                    amt_paid = amt_paid - cts_10;
                    qty_cts_10 -=1;
                }
            }
            system("pause");
            main(); //return to main menu
        }
        else
        {
            //amt_paid won't store in the full storage bin and only return payment for storage bin less than 20 units//
            cout << "Sorry !" << endl;
            cout << "Payment returned : " << amt_paid << endl;

            //display full for notes and coins that their storage bin is full
            if (qty_ringgit_5 >= 20)
                cout << "RM5.00 full" << endl;
            if (qty_ringgit_1 >= 20)
                cout << "RM1.00 full" << endl;
            if (qty_cts_50 >= 20)
                cout << "RM0.50 full" << endl;
            if (qty_cts_20 >= 20)
                cout << "RM0.20 full" << endl;
            if (qty_cts_10 >= 20)
                cout << "RM0.10 full" << endl;

            //calculate amount return due to full storage bin and update the storage bin accordingly
            while (abs(amt_paid) > 0.0001)
            {
                if (amt_paid >= ringgit_5)
                {
                    amt_paid = amt_paid - ringgit_5;
                    qty_ringgit_5 -=1;
                }
                if (amt_paid >= ringgit_1)
                {
                    amt_paid = amt_paid - ringgit_1;
                    qty_ringgit_1 -=1;
                }
                if (amt_paid >= cts_50)
                {
                    amt_paid = amt_paid - cts_50;
                    qty_cts_50 -=1;
                }
                if (amt_paid >= cts_20)
                {
                    amt_paid = amt_paid - cts_20;
                    qty_cts_20 -=1;
                }
                if (amt_paid >= cts_10)
                {
                    amt_paid = amt_paid - cts_10;
                    qty_cts_10 -=1;
                }
            }
            system("pause");
            main(); //return to main menu
        }
    }

    change = amt_paid - orange_price; //calculate the balance change after amount insert

    //if balance change is zero, display order success and update the initial qty of MMU orange
    if (abs(change) < 0.0001)
    {
        //Order success page
        system("cls");
        initial_qty_orange -=1;
        cout << "Order Success !" << endl << endl;
        system ("pause");
        main();
    }
    else
    {
        //calculate balance change if more than zero by qty dispensed accordingly and update storage bin
        while (abs(change) > 0.0001)
        {

            if ((change >= ringgit_5) && (qty_ringgit_5 > 0))
            {
                change = change - ringgit_5;
                qty_dispensed_ringgit5 +=1;
                qty_ringgit_5 -=1;
            }

            else if ((change >= ringgit_1) && (qty_ringgit_1 > 0))
            {
                change = change - ringgit_1;
                qty_dispensed_ringgit1 +=1;
                qty_ringgit_1 -=1;
            }
            else if ((change + 0.0001 >= cts_50) && (qty_cts_50 > 0)) //added 0.0001 due to floating point can't calculate accurate amount
            {
                change = change - cts_50;
                qty_dispensed_cts50 +=1;
                qty_cts_50 -=1;
            }
            else if ((change + 0.0001 >= cts_20) && (qty_cts_20 > 0)) //added 0.0001 due to floating point can't calculate accurate amount
            {
                change = change - cts_20;
                qty_dispensed_cts20 +=1;
                qty_cts_20 -=1;
            }
            else if ((change + 0.00001 >= cts_10)&& (qty_cts_10 >0)) //added 0.0001 due to floating point can't calculate accurate amount
            {
                change = change - cts_10;
                qty_dispensed_cts10 +=1;
                qty_cts_10 -=1;
            }
            else //calculate amount return if one of the initial qty of storage bin found empty in qty dispense calculation and update storage bin
            {
                //Payment returned page
                system ("cls"); //clear screen
                cout << fixed << setprecision(2);
                cout << "Purchase of MMU Orange" << setw(3) << "" << "RM" << orange_price << endl;
                cout << "Amount paid           " << setw(3) << "" << "RM" << amt_paid << endl << endl;
                cout << "Payment returned      " << setw(3) << "" << "RM" << amt_paid << endl << endl;

                qty_ringgit_5 = qty_ringgit_5 + qty_dispensed_ringgit5;
                qty_ringgit_1 = qty_ringgit_1 + qty_dispensed_ringgit1;
                qty_cts_50    = qty_cts_50 + qty_dispensed_cts50;
                qty_cts_20    = qty_cts_20 + qty_dispensed_cts20;
                qty_cts_10    = qty_cts_10 + qty_dispensed_cts10;

                return_change = amt_paid - orange_price; //calculate amount return

                //display amount return change according notes and coins
                while (abs(return_change) > 0.0001)
                {
                    if (return_change >= ringgit_5)
                    {
                        return_change = return_change - ringgit_5;
                        cout << "Unable to dispense    " << setw(3) << "" << "RM" << ringgit_5 << " x 1" << endl;
                    }
                    else if (return_change >= ringgit_1)
                    {
                        return_change = return_change - ringgit_1;
                        cout << "Unable to dispense    " << setw(3) << "" << "RM" << ringgit_1 << " x 1" << endl;
                    }
                    else if (return_change >= cts_50)
                    {
                        return_change = return_change - cts_50;
                        cout << "Unable to dispense    " << setw(3) << "" << "RM" << cts_50 << " x 1" << endl;
                    }
                    else if (return_change >= cts_20)
                    {
                        return_change = return_change - cts_20;
                        cout << "Unable to dispense    " << setw(3) << "" << "RM" << cts_20 << " x 1" << endl;
                    }
                    else
                    {
                        return_change = return_change - cts_10;
                        cout << "Unable to dispense    " << setw(3) << "" << "RM" << cts_10 << " x 1" << endl;
                    }
                }

                //update storage bin accordingly from amount paid return
                while (abs(amt_paid) > 0.0001)
                {
                    if (amt_paid >= ringgit_5)
                    {
                        amt_paid = amt_paid - ringgit_5;
                        qty_ringgit_5 -=1;
                    }
                    else if (amt_paid >= ringgit_1)
                    {
                        amt_paid = amt_paid - ringgit_1;
                        qty_ringgit_1 -=1;
                    }
                    else if (amt_paid >= cts_50)
                    {
                        amt_paid = amt_paid - cts_50;
                        qty_cts_50 -=1;
                    }
                    else if (amt_paid >= cts_20)
                    {
                        amt_paid = amt_paid - cts_20;
                        qty_cts_20 -=1;
                    }
                    else
                    {
                        amt_paid = amt_paid - cts_10;
                        qty_cts_10 -=1;
                    }
                }

                cout << endl;
                system("pause");
                main(); //return main menu

            }
        }

        //change dispensed menu for display total qty dispensed accordingly if all storage bin is available to dispense accordingly
        if ((qty_dispensed_ringgit5 > 0) || (qty_dispensed_ringgit1 > 0)|| (qty_dispensed_cts50 > 0)|| (qty_dispensed_cts20 > 0) || (qty_dispensed_cts10 > 0))
        {
            //Change dispensed page
            system("cls"); //clear screen
            initial_qty_orange -=1; //order success and update initial qty MMU orange
            cout << fixed << setprecision(2);
            cout << "Purchase of MMU Orange" << setw(3) << "" << "RM" << orange_price << endl;
            cout << "Amount paid           " << setw(3) << "" << "RM" << amt_paid << endl << endl;
            cout << "Order Success !" << endl << endl;
            cout << "Change dispensed" << endl;

            //display qty dispensed accordingly
            if (qty_dispensed_ringgit5 > 0)
                cout << "RM5.00 x " << qty_dispensed_ringgit5 << endl;
            if (qty_dispensed_ringgit1 > 0)
                cout << "RM1.00 x " << qty_dispensed_ringgit1 << endl;
            if (qty_dispensed_cts50 > 0)
                cout << "RM0.50 x " << qty_dispensed_cts50 << endl;
            if (qty_dispensed_cts20 > 0)
                cout << "RM0.20 x " << qty_dispensed_cts20 << endl;
            if (qty_dispensed_cts10 > 0)
                cout << "RM0.10 x " << qty_dispensed_cts10 << endl;
            system("pause");
            main(); //return main menu
        }
    }
    return;

}

//MMU Lychee menu
void MMU_Lychee()
{

    float amt_paid = 0.00; //initialized amount paid RM0.00
    char amt_insert; //variable for amount insert
    float change = 0.00; //variable for amount change dispense
    float return_change = 0.00;  //variable for amount return
    int qty_dispensed_ringgit5 = 0; //initialized quantity dispense zero units for RM5.00
    int qty_dispensed_ringgit1 = 0; //initialized quantity dispense zero units for RM1.00
    int qty_dispensed_cts50 = 0; //initialized quantity dispense zero units for RM0.50
    int qty_dispensed_cts20 = 0; //initialized quantity dispense zero units for RM0.20
    int qty_dispensed_cts10 = 0; //initialized quantity dispense zero units for RM0.10

    //amount insert menu for insert amount while amount paid is less than MMU Lychee price
    while (amt_paid < lychee_price)
    {
        //Amount insert page
        system("cls");
        cout << fixed << setprecision(2);
        cout << "Purchase of MMU Lychee" << setw(3) << "" << "RM" << lychee_price << endl;
        cout << "Amount paid           " << setw(3) << "" << "RM" << amt_paid << endl << endl;
        cout << "Insert" << endl;
        cout << "a)" << setw(3) << "" << "RM5" << endl;
        cout << "b)" << setw(3) << "" << "RM1" << endl;
        cout << "c)" << setw(3) << "" << "RM0.50" << endl;
        cout << "d)" << setw(3) << "" << "RM0.20" << endl;
        cout << "e)" << setw(3) << "" << "RM0.10" << endl;
        cout << "f)" << setw(3) << "" << "Cancel order" << endl << endl;
        cout << "Pay (a to f) => ";
        cin  >> amt_insert;

        //update the amount paid and quantity in storage bin according selection make
        if (((amt_insert == 'A') || (amt_insert == 'a')) && (qty_ringgit_5 < 20))
        {
            amt_paid = amt_paid + ringgit_5;
            qty_ringgit_5 += 1;
        }
        else if (((amt_insert == 'B') || (amt_insert == 'b')) && (qty_ringgit_1 < 20))
        {
            amt_paid = amt_paid + ringgit_1;
            qty_ringgit_1 += 1;
        }
        else if (((amt_insert == 'C') || (amt_insert == 'c')) && (qty_cts_50 < 20))
        {
            amt_paid = amt_paid + cts_50;
            qty_cts_50 += 1;
        }

        else if (((amt_insert == 'D') || (amt_insert == 'd')) && (qty_cts_20 < 20))
        {
            amt_paid = amt_paid + cts_20;
            qty_cts_20 += 1;
        }

        else if (((amt_insert == 'E') || (amt_insert == 'e')) && (qty_cts_10 < 20))
        {
            amt_paid = amt_paid + cts_10;
            qty_cts_10 += 1;

        }
        //user can cancel order either had insert some amount or none as long as not more than or equal to MMU Lychee price
        else if ((amt_insert == 'F') || (amt_insert == 'f'))
        {
            //Order canceled page
            cout << endl;
            cout << "Order Canceled !" << endl << endl;
            cout << "Payment returned : RM " << amt_paid << endl << endl;

            //calculate amount return to user if the user had insert some amount and update the qty of storage bin accordingly
            while (abs(amt_paid) > 0.0001)
            {
                if (amt_paid >= ringgit_5)
                {
                    amt_paid = amt_paid - ringgit_5;
                    qty_ringgit_5 -=1;
                }
                else if (amt_paid >= ringgit_1)
                {
                    amt_paid = amt_paid - ringgit_1;
                    qty_ringgit_1 -=1;
                }
                else if (amt_paid  >= cts_50)
                {
                    amt_paid = amt_paid - cts_50;
                    qty_cts_50 -=1;
                }
                else if (amt_paid >= cts_20)
                {
                    amt_paid = amt_paid - cts_20;
                    qty_cts_20 -=1;
                }
                else
                {
                    amt_paid = amt_paid - cts_10;
                    qty_cts_10 -=1;
                }
            }
            system("pause");
            main(); //return to main menu
        }
        else
        {
            //amt_paid won't store in the full storage bin and only return payment for storage bin less than 20 units//
            cout << "Sorry !" << endl;
            cout << "Payment returned : " << amt_paid << endl;

            //display full for notes and coins that their storage bin is full
            if (qty_ringgit_5 >= 20)
                cout << "RM5.00 full" << endl;
            if (qty_ringgit_1 >= 20)
                cout << "RM1.00 full" << endl;
            if (qty_cts_50 >= 20)
                cout << "RM0.50 full" << endl;
            if (qty_cts_20 >= 20)
                cout << "RM0.20 full" << endl;
            if (qty_cts_10 >= 20)
                cout << "RM0.10 full" << endl;

            //calculate amount return due to full storage bin and update the storage bin accordingly
            while (abs(amt_paid) > 0.0001)
            {
                if (amt_paid >= ringgit_5)
                {
                    amt_paid = amt_paid - ringgit_5;
                    qty_ringgit_5 -=1;
                }
                if (amt_paid >= ringgit_1)
                {
                    amt_paid = amt_paid - ringgit_1;
                    qty_ringgit_1 -=1;
                }
                if (amt_paid >= cts_50)
                {
                    amt_paid = amt_paid - cts_50;
                    qty_cts_50 -=1;
                }
                if (amt_paid >= cts_20)
                {
                    amt_paid = amt_paid - cts_20;
                    qty_cts_20 -=1;
                }
                if (amt_paid >= cts_10)
                {
                    amt_paid = amt_paid - cts_10;
                    qty_cts_10 -=1;
                }
            }
            system("pause");
            main(); //return to main menu
        }
    }

    change = amt_paid - lychee_price; //calculate the balance change after amount insert

    //if balance change is zero, display order success and update the initial qty of MMU Lychee
    if (abs(change) < 0.0001)
    {
        //order success page
        system("cls");
        initial_qty_lychee -=1;
        cout << "Order Success !" << endl << endl;
        system ("pause");
        main();
    }
    else
    {
        //calculate balance change if more than zero by qty dispensed accordingly and update storage bin
        while (abs(change) > 0.0001)
        {

            if ((change >= ringgit_5) && (qty_ringgit_5 > 0))
            {
                change = change - ringgit_5;
                qty_dispensed_ringgit5 +=1;
                qty_ringgit_5 -=1;
            }

            else if ((change >= ringgit_1) && (qty_ringgit_1 > 0))
            {
                change = change - ringgit_1;
                qty_dispensed_ringgit1 +=1;
                qty_ringgit_1 -=1;
            }
            else if ((change + 0.0001 >= cts_50) && (qty_cts_50 > 0)) //added 0.0001 due to floating point can't calculate accurate amount
            {
                change = change - cts_50;
                qty_dispensed_cts50 +=1;
                qty_cts_50 -=1;
            }
            else if ((change + 0.0001 >= cts_20) && (qty_cts_20 > 0)) //added 0.0001 due to floating point can't calculate accurate amount
            {
                change = change - cts_20;
                qty_dispensed_cts20 +=1;
                qty_cts_20 -=1;
            }
            else if ((change + 0.00001 >= cts_10)&& (qty_cts_10 >0)) //added 0.0001 due to floating point can't calculate accurate amount
            {
                change = change - cts_10;
                qty_dispensed_cts10 +=1;
                qty_cts_10 -=1;
            }
            else //calculate amount return if one of the initial qty of storage bin found empty in qty dispense calculation and update storage bin
            {
                //Payment returned page
                system ("cls"); //clear screen
                cout << fixed << setprecision(2);
                cout << "Purchase of MMU Lychee" << setw(3) << "" << "RM" << lychee_price << endl;
                cout << "Amount paid           " << setw(3) << "" << "RM" << amt_paid << endl << endl;
                cout << "Payment returned      " << setw(3) << "" << "RM" << amt_paid << endl << endl;

                qty_ringgit_5 = qty_ringgit_5 + qty_dispensed_ringgit5;
                qty_ringgit_1 = qty_ringgit_1 + qty_dispensed_ringgit1;
                qty_cts_50    = qty_cts_50 + qty_dispensed_cts50;
                qty_cts_20    = qty_cts_20 + qty_dispensed_cts20;
                qty_cts_10    = qty_cts_10 + qty_dispensed_cts10;

                return_change = amt_paid - lychee_price; //calculate amount return

                //display amount return change according notes and coins
                while (abs(return_change) > 0.0001)
                {
                    if (return_change >= ringgit_5)
                    {
                        return_change = return_change - ringgit_5;
                        cout << "Unable to dispense    " << setw(3) << "" << "RM" << ringgit_5 << " x 1" << endl;
                    }
                    else if (return_change >= ringgit_1)
                    {
                        return_change = return_change - ringgit_1;
                        cout << "Unable to dispense    " << setw(3) << "" << "RM" << ringgit_1 << " x 1" << endl;
                    }
                    else if (return_change >= cts_50)
                    {
                        return_change = return_change - cts_50;
                        cout << "Unable to dispense    " << setw(3) << "" << "RM" << cts_50 << " x 1" << endl;
                    }
                    else if (return_change >= cts_20)
                    {
                        return_change = return_change - cts_20;
                        cout << "Unable to dispense    " << setw(3) << "" << "RM" << cts_20 << " x 1" << endl;
                    }
                    else
                    {
                        return_change = return_change - cts_10;
                        cout << "Unable to dispense    " << setw(3) << "" << "RM" << cts_10 << " x 1" << endl;
                    }
                }

                //update storage bin accordingly from amount paid return
                while (abs(amt_paid) > 0.0001)
                {
                    if (amt_paid >= ringgit_5)
                    {
                        amt_paid = amt_paid - ringgit_5;
                        qty_ringgit_5 -=1;
                    }
                    else if (amt_paid >= ringgit_1)
                    {
                        amt_paid = amt_paid - ringgit_1;
                        qty_ringgit_1 -=1;
                    }
                    else if (amt_paid >= cts_50)
                    {
                        amt_paid = amt_paid - cts_50;
                        qty_cts_50 -=1;
                    }
                    else if (amt_paid >= cts_20)
                    {
                        amt_paid = amt_paid - cts_20;
                        qty_cts_20 -=1;
                    }
                    else
                    {
                        amt_paid = amt_paid - cts_10;
                        qty_cts_10 -=1;
                    }
                }

                cout << endl;
                system("pause");
                main(); //return main menu

            }
        }

        //change dispensed menu for display total qty dispensed accordingly if all storage bin is available to dispense accordingly
        if ((qty_dispensed_ringgit5 > 0) || (qty_dispensed_ringgit1 > 0)|| (qty_dispensed_cts50 > 0)|| (qty_dispensed_cts20 > 0) || (qty_dispensed_cts10 > 0))
        {
            //Change dispensed page
            system("cls"); //clear screen
            initial_qty_lychee -=1; //order success and update initial qty MMU Lychee
            cout << fixed << setprecision(2);
            cout << "Purchase of MMU Lychee" << setw(3) << "" << "RM" << lychee_price << endl;
            cout << "Amount paid           " << setw(3) << "" << "RM" << amt_paid << endl << endl;
            cout << "Order Success !" << endl << endl;
            cout << "Change dispensed" << endl;

            //display qty dispensed accordingly
            if (qty_dispensed_ringgit5 > 0)
                cout << "RM5.00 x " << qty_dispensed_ringgit5 << endl;
            if (qty_dispensed_ringgit1 > 0)
                cout << "RM1.00 x " << qty_dispensed_ringgit1 << endl;
            if (qty_dispensed_cts50 > 0)
                cout << "RM0.50 x " << qty_dispensed_cts50 << endl;
            if (qty_dispensed_cts20 > 0)
                cout << "RM0.20 x " << qty_dispensed_cts20 << endl;
            if (qty_dispensed_cts10 > 0)
                cout << "RM0.10 x " << qty_dispensed_cts10 << endl;
            system("pause");
            main(); //return main menu
        }
    }
    return;
}


