// Multi-Threading The Space Race.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Code By Kelley Kramer

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

using namespace std;
mutex m;

void mainBase(int i)
{
    m.lock();
    printf("Rocket Launched from Main Base! Rocket ID:%d Rocekt #:%d\n\n", this_thread::get_id(),i);
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Transfering launch control to Rocket Pad Space Cadet!\n" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    m.unlock();
}

void rocketPad(int i)
{
    m.lock();
    printf("Rocket Launched from Rocket Pad! Rocket ID:%d, Rocket #:%d\n\n", this_thread::get_id(),i);
    this_thread::sleep_for(chrono::seconds(3));
    m.unlock();
}

int main()
{
    string userAnswer;

    cout << "\t\t*** Space Flight Center: Rocket Control ***\n\n" << endl;
    cout << "This is the lauch control program for a sequence of 10 rocket launshes.\n"
        << "The first lauch will launch from our main complex, and the reset\n"
        << "from our Rocket Pad Space Cadet.\n"<< endl;
    cout << "Once activated the sequece will count down from 10, then initiat lauch.\n"
        "There will be a 3 second delay between launches, and the trasfer of control\n"
        "to the lauch site will take 2 seconds.  Total time: 32seconds.\n" << endl;

    cout << "Are you ready to start the lauch sequence? Press 'y' or 'Y' for Yes" << endl;

    cin >> userAnswer;
 
    if (userAnswer == "y" || userAnswer == "Y")
    {
        cout << "\t LAUNCH SEQUENCE INITIATED" << endl;
        int counter = 10;
        Sleep(1000);
        while (counter >= 1)
        {
            cout <<"\t"<<counter << endl;
            Sleep(1000);
            counter--;
        }

        thread r1(mainBase, 1);
        thread r2(rocketPad, 2);
        thread r3(rocketPad, 3);
        thread r4(rocketPad, 4);
        thread r5(rocketPad, 5);
        thread r6(rocketPad, 6);
        thread r7(rocketPad, 7);
        thread r8(rocketPad, 8);
        thread r9(rocketPad, 9);
        thread r10(rocketPad, 10);

        r10.join();
        r9.join();
        r8.join();
        r7.join();
        r6.join();
        r5.join();
        r4.join();
        r3.join();
        r2.join();
        r1.join();

        cout << " Launch sequence complete!  All 10 rockets launched.  Have a great day!" << endl;

    }
    else
    {
        cout << "Terminating comunication.  Good Bye!" << endl;
    }
}
