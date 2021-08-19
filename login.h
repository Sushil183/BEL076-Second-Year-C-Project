#include<iostream>
#include<string.h>
#include<windows.h>
#pragma once
using namespace std;


void callExit()
{
  int process = 0;
  system("cls");
  cout <<"\n\n";
  cout <<"\t\tTaking You Out of The System";
  system("cls");
  cout <<"\n\n";
  cout <<"\t\t";
  cout <<"You are out of the System.\n";
  cout <<"\t\t";
  cout << "Thank You !";
  cout <<"\n\n";
  cout <<"\t\t";
  system("pause");
  exit(0);
}

int login()
{
  char username[30];
  char password[30];
  //int true1 = 1;
  int try1 = 0;
  int i=0;
  do
  {
    system("cls");
    cout << "\n\n\n\n\n\n";
    cout <<"\t\t\t\t\t    ----------------------------------\n";
    cout <<"\t\t\t\t\t    |KATHMANDU METRO POLICE STATION   |\n";
    cout <<"\t\t\t\t\t    ----------------------------------\n";
    cout <<"\n\n";
    cout << "\t\t";
    cout << "Username : ";
    cin >> username;
    cout << "\t\t";
    cout << "\n";
    cout << "\t\t";
    cout << "Password : ";
    cin >> password;
    if(strcmp(username,"pulchowk")==0 && strcmp(password,"bel076")==0)
      {
        PlaySound(TEXT("sucessful.wav"), NULL, SND_SYNC);
        cout << "\n\n";
        cout << "\t\t";
        cout << "Congratulations! You are now accessed to our system.\n\n";
        PlaySound(TEXT("Congratulations.wav"), NULL, SND_SYNC);
        cout << "\t\t";
        system("pause");
        system("cls");
        //true1 = 0;
        return 1;
      }
      else
      {
        system("cls");
        try1 = try1+1;
        cout << "\n\n\n\n";
        cout << "\t\t";
        PlaySound(TEXT("incorrect.wav"), NULL, SND_SYNC);
        cout << "No. of attempts remain: " << 3-try1;
        cout << "\n\n";
        cout << "\t\t";
        system("pause");
        if(try1>=3)
        {
          cout << "\t\t";
          cout << "\n";
          cout << "\t\t";
          PlaySound(TEXT("Redirected.wav"),NULL,SND_SYNC);
          cin.get();
          cout << "No permission to enter the system!\n\n";
          PlaySound(TEXT("No_permission.wav"), NULL, SND_SYNC);
          cout << "\t\t";
          system("pause");
          callExit();
        }
      }
    }
 while(try1<3);
}




