#include<iostream>
#include<string.h>
#include<windows.h>
using namespace std;
void homepage()
{
  int process=0;
  system("cls");
  //date1();
  cout << "\n";
  cout <<"\t\t\t\t\t      ----------------------------------\n";
  cout <<"\t\t\t\t\t      |KATHMANDU METRO POLICE STATION  |\n";
  cout <<"\t\t\t\t\t      ----------------------------------\n";
  cout <<"\n\n\n";
  cout <<"\t\t";
  cout <<"Prepared By  ";
  cout <<" : ";
  cout <<"Rachana(033)| Shashwot(043)| Sushil(047)";
  cout <<"\n\n";
  cout <<"\t\t";
  cout <<"Project Name ";
  cout <<" : ";
  cout <<"Computerized FIR System";
  cout <<"\n\n";
  cout <<"\t\t";
  cout <<"\n\n";
  cout <<"\n\n";
  cout <<"\t\t";
  system("pause");
  cout <<"\n\t\tPlease wait";

  for(process=0;process<18;process++)
  {
    Sleep(100);
    PlaySound(TEXT("beep.wav"), NULL, SND_SYNC);
    cout <<" .";

  }

}
