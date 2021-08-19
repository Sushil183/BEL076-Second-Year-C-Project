#include<iostream>
#include<string.h>
#include<windows.h>
#include"login.h"
#include"home.h"
#include"criminal.h"


using namespace std;

int main(){
    system("Color 0C");
    Criminal c;
    homepage();
    PlaySound(TEXT("Welcome.wav"), NULL, SND_SYNC);
    int count = 1;
    count = login();
    if ( count ==1)
    {
        menu(c);
    }
}

