/*
MIT License

Copyright (c) 2022 Elvin Suleymanov

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <iostream>
#include <string>
#include "additional_files/user.h"
#include "additional_files/figure.h"
#include "additional_files/menus.h"
#include "additional_files/functions.h"
#include "additional_files/figures/pawn.h"
#include "additional_files/figures/horse.h"
#include "additional_files/figures/elephant.h"
#include "additional_files/figures/rook.h"
#include "additional_files/figures/queen.h"
#include "additional_files/figures/king.h"
using namespace std;

int main()
{
    string sys; // Your System Name
    
	// Creating figures(objects)

	Pawn w_p1, w_p2, w_p3, w_p4, w_p5, w_p6, w_p7, w_p8, b_p1, b_p2, b_p3, b_p4, b_p5, b_p6, b_p7, b_p8;
	Horse w_h1, w_h2, b_h1, b_h2;
	Elephant w_e1, w_e2, b_e1, b_e2;
	Rook w_r1, w_r2, b_r1, b_r2;
	Queen w_Q, b_Q;
	King w_K, b_K;

    // Creating arrays
    // 1. Board with figures
    // 2. White killed figures
    // 3. Black killed figures
    
    Figure** board_arr[8][8] = {
        {*b_r1, *b_h1, *b_e1, *b_Q, *b_K, *b_e2, *b_h2, *b_r2},
        {*b_p1, *b_p2, *b_p3, *b_p4, *b_p5, *b_p6, *b_p7, *b_p8},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr},
        {*w_p1, *w_p2, *w_p3, *w_p4, *w_p5, *w_p6, *w_p7, *w_p8},
        {*w_r1, *w_h1, *w_e1, *w_Q, *w_K, *w_e2, *w_h2, *w_r2},
    };

    Figure* killed_white_figures_arr[15] = {};
    Figure* killed_black_figures_arr[15] = {};

    // Creating user & data for it
    User user;
    string usrnm = " ";
    string pass = " ";
    int lvl = 0;

    // Data for cycle
    int welcome_choose = 0;
    int menu_choose = 0;

    // Entering system name
    cout << "Ou. Hello! Enter your system name:~> ";
    cin >> sys;
    
    // Cycle
    while (true)
    {
        clear(sys);
        banner();
        
        if (user.get_regbool() == false) 
        {
            welcome();
            cout << "    choose(welcome):~> ";
            cin >> welcome_choose;
            
            if (welcome_choose == 1)
            {
                int registration_choose = 0;
                clear(sys);
                banner();
                reg_and_login();
    
                cout << "    choose(registration):~> ";
                cin >> registration_choose;
    
                if (registration_choose == 1)
                {
                    // Registering
                    clear(sys);
                    cout << "    enter nickname:~> ";
                    cin >> usrnm;
                    user.set_username(usrnm);
                    clear(sys);
                    cout << "    enter password:~> ";
                    cin >> pass;
                    user.set_password(pass);
                    clear(sys);
                    cout << "    enter level:~> ";
                    cin >> lvl;
                    user.set_level(lvl);
                    clear(sys);

                    // Setting regisration bool (true)
                    user.set_regbool(true);
    
                    // Resul
                    user.inf0();

                    usrnm = " ";
                    pass = " ";
                    lvl = 0;
                }
    
                else if (registration_choose == 2)
                {
                    // Registering as Guest
                    clear(sys);
                    user.set_username("Guest");
                    user.set_password("guest123");
                    user.set_level(0000000);
                    clear(sys);

                    // Setting regisration bool (true)
                    user.set_regbool(true);
                    
                    // Result
                    user.inf0();
                }
    
                else if (registration_choose == 3)
                {
                    continue;
                }
                
                press_to_continue();
            }
                
            else if (welcome_choose == 2)
            {
                clear(sys);
                boardinfo();
                press_to_continue();
            }
                
            else if (welcome_choose == 3)
            {
                clear(sys);
                banner();
                about();
                press_to_continue();
            }
                
            else if (welcome_choose == 4)
            {
                clear(sys);
                license();
                press_to_continue();
            }
                
            else if (welcome_choose == 5)
            {
                clear(sys);
                cout << "Auf Wiedersehen!" << endl;
                exit(0);
            }
                
            else
            {
                clear(sys);
                cout << "Err: 0002B" << endl;
                error();
                exit(0);
            }
        }
            
        else if (user.get_regbool() == true)
        {
            menu();
            cout << "    choose(menu):~> ";
            cin >> menu_choose;
            
            if (menu_choose == 1)
            {
                int profile_choose = 0;
                clear(sys);
                banner();
                profile(user);

                cin >> profile_choose;
                
                if (profile_choose == 1)
                {
                    string temp_password = 0;
                    cout << "Please enter user password:~> ";
                    cin >> temp_password;
                        
                    if (user.get_password() == temp_password)
                    {
                        cout << "    enter new username:~> ";
                        cin >> usrnm;
                        user.set_username(usrnm);
                    }

                    else
                    {
                        cout << " Sorry, but password is wrong.";
                        press_to_continue();
                    }
                }

                else if (profile_choose == 2)
                {
                    string temp_password = 0;
                    cout << "Please enter user password:~> ";
                    cin >> temp_password;
                        
                    if (user.get_password() == temp_password)
                    {
                        cout << "    enter new password:~> ";
                        cin >> pass;
                        user.set_username(pass);
                    }

                    else
                    {
                        cout << " Sorry, but password is wrong.";
                        press_to_continue();
                    }
                }

                else if (profile_choose == 3)
                {
                    string temp_password = 0;
                    cout << "Please enter user password:~> ";
                    cin >> temp_password;
                        
                    if (user.get_password() == temp_password)
                    {
                        cout << "    enter new level:~> ";
                        cin >> usrnm;
                        user.set_username(usrnm);
                    }

                    else
                    {
                        cout << " Sorry, but password is wrong.";
                        press_to_continue();
                    }
                }

                else if (profile_choose == 4)
                {
                    continue;
                }

                else
                {
                    cout << "Err: 0003C" << endl;
                    exit(0);
                }
            }

            else if (menu_choose == 2)
            {
                continue;
            }

            else if (menu_choose == 3)
            {
                continue;
            }

            else if (menu_choose == 4)
            {
                clear(sys);
                user.set_username(" ");
                user.set_password(" ");
                user.set_level(0);
                user.set_regbool(false);
                continue;
            }

            else if (menu_choose == 5)
            {
                clear(sys);
                banner();
                about();
                press_to_continue();
            }

            else if (menu_choose == 6)
            {
                clear(sys);
                license();
                press_to_continue();
            }

            else if (menu_choose == 7)
            {
                clear(sys);
                cout << "Auf Wiedersehen!" << endl;
                exit(0);
            }
        }

        else 
        {
            cout << "Err: 0001A" << endl;
            exit(0);
        }
    }
    return 0;
}