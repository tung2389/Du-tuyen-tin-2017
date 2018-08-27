#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    SetConsoleTitleA("Crackme");
    long long Input;
    long long Key = 123456789999;
    while(1)
    {
    cin >> Input;
    if(Input ==  Key)
    {
        cout << "Status successful" << "\n";
        MessageBoxA(0,"Authentication Successful !","Success",0);
        cout << "Congratulation !" << "\n";
        break;
    }
    else
    {
        cout << "Wrong Key" << "\n";
        MessageBoxA(0,"Invalid Key",0,0);
        cout << "Try harder next time !" << "\n";
    }
    }
}
