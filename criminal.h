#include<iostream>
#include<windows.h>
#include<string.h>
#include<fstream>
#include<string.h>
#include<iomanip>
#include"login.h"

using namespace std;

struct Date
{
  int d;
  int m;
  int y;
};

class Court
{
protected:
  char crime[15];
  char act[15];
  char court[15];
  char state[10];
};

class Description
{
protected:
  char colour[10];
  char face[10];
  char imark[10];
  char height[10];
  char eye_color[10];
};
struct Police
{
  char station[30];
  char fir[10];
  Date date_arrest;
};

class Criminal : public Court, public Description
{
private:
  Police pol;
  char name[20];
  char sex[3];
  char convict_no[10];
  char age[5];
  char address[20];

public:
  int alphabet_check(char ch[]);       // Checks that input is alphabetical
  int id_check(char c[]);              // Checks the convict ID
  int sex_check(char s[]);             // Checks that sex has  "M" or "F" or "m" or "f"
  int id_search(char i[]);             // Searches the convict id in file
  void input(void);                    // Takes the input from the user
  void modify();                       // Modifies  existing records
  void output(void);                   // Displays the output
  void display();                      // Displays all the entered records
  void remove();                       // Removes an entry
  void empty();                        // Enters new record while modifying
  void delete_record(char conv_no[]);  // Deletes a record
  void list();                         // Lists all records
};
void menu(Criminal c)
{
  int test;
  while (true)
  {
    system("cls");
    cout << "\n\n\n";
    cout << "\t\t";
    cout << "\n";
    cout << "\t\t\t\t\t    ----------------------------------\n";
    cout << "\t\t\t\t\t    |Kathmandu Metro Police Station    |\n";
    cout << "\t\t\t\t\t    ----------------------------------\n";
    cout << "\n\n\n\n";
    cout << "\t\t";
    cout << " 1. Add a FIR\n\n";
    cout << "\t\t";
    cout << " 2. Modify a FIR\n\n";
    cout << "\t\t";
    cout << " 3. Display a FIR\n\n";
    cout << "\t\t";
    cout << " 4. Delete a FIR\n\n";
    cout << "\t\t";
    cout << " 5. List all FIRs\n\n";
    cout << "\t\t";
    cout << " 6. Exit\n\n";
    cout << "\t\t";
    cout << "Choose:[1/2/3/4/5/6] : ";
    fflush(stdin);
    cin >> test;
    switch (test)
    {
    case 1:
    {
      c.input();
      break;
    }
    case 2:
    {
      c.modify();
      break;
    }
    case 3:
    {
      c.display();
      break;
    }
    case 4:
    {
      c.remove();
      break;
    }
    case 5:
    {
      c.list();
      break;
    }
    case 6:
      {
        callExit();
      }
      break;
    default:
    {
      cout << "\n\n\n";
      cout << "\t\t";
      cout << "Invalid input!";
      cout << "\n\n";
      cout << "\t\t";
      fflush(stdin);
      getchar();
      menu(c);
    }
    }
  }
}

int Criminal::alphabet_check(char ch[])
{
    int i;
    while (ch[i]!='\0')
  {
    if((ch[i]>='a' && ch[i]<='z') || (ch[i]>='A' && ch[i]<='Z') || ch[i] ==' ')
    {
        i++;
      continue;
    }
    else
    {
      throw 0;
    }
  }
  return 1;
}

int Criminal::sex_check(char s[])
{
  if(( (s[0]=='m')||(s[0]=='f')||(s[0]=='M')||(s[0]=='F'))&&(s[1]=='\0') )
  {
    return 1;
  }
  else
  {
    throw 0;
  }
}

void Criminal::input()
{
  empty();
  Criminal x;
  int c = 0 ;
  fflush(stdin);
  fstream createfile;
  createfile.open("records.txt",ios::app);
  while(c!=1)
  {
  cout << "\n\n\t\tEnter the FIR ID : ";
  PlaySound(TEXT("FIR_ID.wav"),NULL,SND_SYNC);
  cin >>convict_no;
  c = x.id_check(convict_no);
  fflush(stdin);
  }
  c = 0;
  cout <<"\n\n\t\tEnter the convict details\n";
  PlaySound(TEXT("Convict_details.wav"),NULL,SND_SYNC);
  while(c != 1)
  {
    cout  << "\n\t\tName : ";
    cin >> name;
    try
    {
    c = alphabet_check(name);
    }
    catch(int)
    {
        cout << "\n\t\tIncorrect input.\n";
    }
  }
  fflush(stdin);
  c = 0;
  while(c != 1)
  {
    cout << "\n\t\tSex : ";
    cin >> sex;
    try
   {
    c = sex_check(sex);
   }
   catch(int)
   {
       cout << "\n\t\tIncorrect input.\n";
   }
  }
  fflush(stdin);
  cout << "\n\t\tAddress : ";
  cin >> address;
  fflush(stdin);
  cout << "\n\t\tAge     : ";
  cin >>age;
  cout <<"\n\t\tEnter the court details\n";
  PlaySound(TEXT("Court_details.wav"),NULL,SND_SYNC);
  fflush(stdin);
  c = 0 ;
  while(c != 1)
  {
    cout <<"\n\t\tCourt of conviction : ";
    cin >> (court);
    try
    {
    c = alphabet_check(court);
    }
    catch(int)
    {
        cout << "\n\t\tIncorrect input.\n";
    }
  }
  fflush(stdin);
  c = 0;
  while(c != 1)
  {
    cout << "\n\t\tState : ";
    cin >> (this->state);
    try
    {
    c = alphabet_check(state);
    }
    catch(int)
    {
        cout << "\n\t\tIncorrect input.\n";
    }
  }
  fflush(stdin);
  c = 0;
  while(c != 1)
  {
    cout << "\n\t\tCrime : ";
    cin >> (this->crime);
    try
    {
    c = alphabet_check(crime);
    }
    catch(int)
    {
        cout << "\n\t\tIncorrect input.\n";
    }
  }
  fflush(stdin);
  cout << "\n\t\tAct no. : ";
  cin >> (this->act);
  system("cls");
  cout << "\n\t\tEnter the description of convict\n";
  PlaySound(TEXT("Description_convict.wav"),NULL,SND_SYNC);
  fflush(stdin);
  c = 0;
  while(c != 1)
  {
    cout<<"\n\t\tSkin colour : ";
    cin >> (this->colour);
    try
    {
    c = alphabet_check(colour);
    }
    catch(int)
    {
        cout << "\n\t\tIncorrect input!!\n";
    }
  }
  fflush(stdin);
  c = 0;
  while(c != 1)
  {
  cout << "\n\t\tFace description : ";
  cin >> (this->face);
  try
    {
    c = alphabet_check(face);
    }
    catch(int)
    {
    cout << "\n\t\tIncorrect input!!\n";
    }
  }
  cout << "\n\t\tEye Colour : ";
  cin >> (this->eye_color);
  fflush(stdin);
  cout << "\n\t\tHeight(Feet.inch) : ";
  cin >> (this->height);
  fflush(stdin);
  cout << "\n\t\tAny Special Marks : ";
  cin >> (this->imark);
  system("cls");
  cout << "\n\t\tEnter the police station information \n ";
  PlaySound(TEXT("Policestation_information.wav"),NULL,SND_SYNC);
  fflush(stdin);
  cout << "\n\t\tName of Police Station : ";
  cin >> (this->pol.station);
  cout <<"\n\t\tFir No. : ";
  fflush(stdin);
  cin >> (this->pol.fir);
  cout <<"\n\t\tDate of Arrest(DD/MM/YYYY)\n";
  fflush(stdin);
  c = 0;
  while(!c)
  {
    cout << "\n\t\tDay : ";
    cin >> this->pol.date_arrest.d;
    if((this->pol.date_arrest.d>31) || (this->pol.date_arrest.d<1))
    {
      cout << "\n\t\tThis date doesnot exist!!n";
      PlaySound(TEXT("Date_error.wav"),NULL,SND_SYNC);
      c = 0;
    }
    else
      c = 1;
  }
  c = 0;
  fflush(stdin);
  while(!c)
  {
    cout << "\n\t\tMonth : ";
    cin >> this->pol.date_arrest.m;
    if((this->pol.date_arrest.m>12) || (this->pol.date_arrest.m<1))
    {
      cout << "\n\t\tThis month doesnot exist!!\n";
      PlaySound(TEXT("Month_error.wav"),NULL,SND_SYNC);

      c = 0;
      continue;
    }
    else
      c = 1;
  }
  fflush(stdin);
  c = 0;
  while(!c)
  {
    cout << "\n\t\tYear(4 digits) : ";
    cin >> this->pol.date_arrest.y;
    if((this->pol.date_arrest.y <= 1990)||(this->pol.date_arrest.y>2021))
    {
      cout << "\n\t\tThis year is out of range!!\n";
      PlaySound(TEXT("Year_error.wav"),NULL,SND_SYNC);
      c = 0;
    }
    else
      c = 1;
  }
  char chh;
  do
  {
    cout << "\n\t\tDo you want to save the information?(Y/N) : ";
    PlaySound(TEXT("Save_info.wav"),NULL,SND_SYNC);
    cin >> chh;
    if(chh=='y'||chh=='Y')
    {
      cout << "\n\t\tFIR has been saved!";
      PlaySound(TEXT("FIR_saved.wav"),NULL,SND_SYNC);
      createfile.write((char*)this, sizeof(Criminal));
    }
   else
    {
      if((chh!='n')&&(chh!='N'))
      {
        cout<<"\n\t\tPress again !!\n\n";
      }
    }
  }while((chh!='y') && (chh!='Y') && (chh!='n') && (chh!='N'));
  createfile.close();
  cout << "\n\n\t\t";
  system("pause");
}

void Criminal::delete_record(char conv_no[])
{
  fstream ifile;
  fflush(stdin);
  ifile.open("records.txt",ios::in|ios::ate);
  int a = ifile.tellg();
  int b = a/sizeof(Criminal);
  fstream temp;
  temp.open("temp.txt",ios::out);
  ifile.seekg(0,ios::beg);
  for(int i=0; i<b; i++)
  {
    ifile.read((char*)this,sizeof(Criminal));
    if(strcmp(conv_no,convict_no) != 0)
    temp.write((char*)this,sizeof(Criminal));
  }
  ifile.close();
  temp.close();
  ifile.open("records.txt",ios::out);
  temp.open("temp.txt",ios::in|ios::ate);
  int x = temp.tellg();
  int size = x/sizeof(Criminal);
  temp.seekg(0,ios::beg);
  for(int k=0; k<size; k++)
  {
    temp.read((char*)this,sizeof(Criminal));
    ifile.write((char*)this,sizeof(Criminal));
  }
  ifile.close();
  temp.close();
  cout<<"\n\n\t\tThe record has been deleted.";
  PlaySound(TEXT("Record_delete.wav"),NULL,SND_SYNC);

  cout <<"\n";
  fflush(stdin);
  getchar();
}

int Criminal::id_search(char n[])
{
  system("cls");
  fstream file;
  file.open("records.txt",ios::in|ios::ate|ios::binary);

  int x = 0, count = 0, c;
  int a = file.tellg();
  c = a/sizeof(Criminal);
  file.close();
  file.open("records.txt",ios::in|ios::binary);
  for(int i=0;i<c;i++)
  {
    file.read((char*)this,sizeof(Criminal));
    count++;
    if(strcmp(n,convict_no)==0)
    {
      x++;
      break;
    }
  }
  if(x==0)
  {
    cout<<"\n\n\t\tConvict not found!! ";
    PlaySound(TEXT("Convictnotfound.wav"),NULL,SND_SYNC);
    getchar();
    return 0;
  }
  else
  {
    return count;
  }
  file.close();
}

int Criminal::id_check(char b[])
{
  fstream  file;
  char a[10];
  int check=0;
  file.open("records.txt",ios::in|ios::ate);
  int q=file.tellg();
  int size=q/sizeof(Criminal);
  file.seekg(0,ios::beg);
  for(int i=0;i<size;i++)
  {
    file.read((char*)this,sizeof(Criminal));
    strcpy(a,convict_no);
    if(strcmp(b,a)==0)
    {
      check+=1;
      break;
    }
  }
  if(check==0)
  {
    return 1;
  }
  else
  {
    cout<<"\t\tGiven convict code already exists!"<<endl;
    PlaySound(TEXT("Convict_exists.wav"),NULL,SND_SYNC);
    return 0;
  }
  file.close();
}

void Criminal::output()
{
  system("cls");
  fflush(stdin);
  cout << "\n\n\t\t----------Personal Record of Convict----------\n\n";
  cout << "\n\t\tConvict ID             :\t";
  puts(convict_no);
  cout << "\n\t\t1.Name                 :\t";
  puts(name);
  cout << "\n\t\t2.Sex                  :\t";
  puts(sex);
  cout << "\n\t\t3.Address              :\t";
  puts(address);
  cout << "\n\t\t4.Age                  :\t";
  puts(age);
  cout << "\n\t\t";
  system("pause");
  system("cls");
  PlaySound(TEXT("sucess.wav"),NULL,SND_SYNC);
  cout << "\n\t\t----------Court Information----------\n\n ";
  cout << "\n\t\t1.Court of Conviction        :\t";
  puts(court);
  cout << "\n\t\t2.State                      :\t";
  puts(state);
  cout << "\n\t\t3.Crime                      :\t";
  puts(crime);
  cout << "\n\t\t4.Act                        :\t";
  puts(act);
  cout << "\n\t\t";
  system("pause");
  system("cls");
  PlaySound(TEXT("sucess.wav"),NULL,SND_SYNC);
  cout << "\n\n\t\t----------Description----------\n\n";
  cout << "\n\t\t1.Skin Colour    :\t";
  puts(colour);
  cout << "\n\t\t2.Eye Colour          :\t";
  puts(eye_color);
  cout << "\n\t\t3.Face                :\t";
  puts(face);
  cout << "\n\t\t4.Identification Mark :\t";
  puts(imark);
  cout << "\n\t\t5.Height              :\t";
  puts(height);
  cout << "\n\t\t";
  system("pause");
  system("cls");
  PlaySound(TEXT("sucess.wav"),NULL,SND_SYNC);
  cout << "\n\n\t\t----------Police Details----------\n\n";
  cout << "\n\t\t1.Police Station    :\t";
  puts(pol.station);
  cout << "\n\t\t2.Fir No.           :\t";
  puts(pol.fir);
  cout << "\n\t\t3.Date of Arrest    :\t" << pol.date_arrest.d <<"/" << pol.date_arrest.m << "/"<<pol.date_arrest.y;
  cout << "\n\n\t\t";
  system("pause");
}

void Criminal::display()
{
  system("cls");
  fflush(stdin);
  char n[10];
  int record;
  int location;
  cout << "\n\n\t\tEnter the convict ID : ";
  PlaySound(TEXT("Convict_ID.wav"),NULL,SND_SYNC);
  gets(n);
  fstream ofile;
  record = id_search(n);
  ofile.open("records.txt",ios::in|ios::binary);
  if(record!=0)
  {
    location = (record-1)*sizeof(Criminal);
    ofile.seekg(location);
    ofile.read((char*)this,sizeof(Criminal));
    output();
  }
ofile.close();
cout <<"\n";
fflush(stdin);
}

void Criminal::remove()
{
  fflush(stdin);
  system("cls");
  char id[10];
  int s;
  cout << "\n\n\t\tEnter the convict ID : ";
  PlaySound(TEXT("Convict_ID.wav"),NULL,SND_SYNC);
  gets(id);
  s = this->id_search(id);
  if(s!=0)
  this->delete_record(id);
}


void Criminal::modify() // function to modify record
{
  system("cls");
  fflush(stdin);
  fstream file;
  char npdr[10], modcrime[10], modact[10], modstate[10], modcourt[10], modstation[10], modfir[10];
  char str[10],nprd[15],modconvno[10];
  int check,loc;
  Criminal x;
  Date D;
  fflush(stdin);
  modify_start:
  cout << "\n\n\t\tEnter the convict ID : ";
  PlaySound(TEXT("Convict_ID.wav"),NULL,SND_SYNC);
  gets(str);
  check = id_search(str);
  if(check != 0)
  {
    file.open("jail.txt",ios::out|ios::ate);
    int d = 0;
    cout << "\n\n\t\tRecord found!\n";
    PlaySound(TEXT("Record_found.wav"),NULL,SND_SYNC);
    cout << "\n\t\tEnter modified details\n";
    PlaySound(TEXT("Modified_details.wav"),NULL,SND_SYNC);

    while(d != 1)
    {
      cout << "\n\t\tEnter the convict ID : ";
      PlaySound(TEXT("Convict_ID.wav"),NULL,SND_SYNC);
      cin >> modconvno;
      d = x.id_check(modconvno);
    }
    strcpy(convict_no,modconvno);

    cout << "\n\t\tCrime      : ";
    cin >> modcrime;
    strcpy(crime,modcrime);
    cout << "\n\t\tAct   : ";
    cin >> modact;
    strcpy(act,modact);
    cout << "\n\t\tState : ";
    cin >> modstate;
    strcpy(state,modstate);
    cout << "\n\t\tCourt : ";
    cin >> modcourt;
    strcpy(court,modcourt);
    cout << "\n\t\tStation : ";
    cin >> modstation;
    strcpy(pol.station,modstation);
    cout << "\n\t\tFIR no   : ";
    cin >> modfir;
    strcpy(pol.fir,modfir);
    cout << "\n\t\tDate of Arrest(DD,MM,YYYY)  ";
    int c = 0;
    while(c != 1)
    {
      cout<<"\n\t\t Day : ";
      cin>>D.d;
      if((D.d>31)||(D.d<1))
      {
        cout << "\n\t\tThis date doesnot exist!!\n";
        PlaySound(TEXT("Date_error.wav"),NULL,SND_SYNC);
        c = 0;
      }
      else
        c = 1;
    }

    c = 0;
    while(c != 1)
    {
      cout<<"\n\t\t Month : ";
      cin >> D.m;
      if((D.m>12)||(D.m<1))
      {
        cout << "\n\t\tThis month doesnot exist!!\n";
        PlaySound(TEXT("Month_error.wav"),NULL,SND_SYNC);
        c = 0;
      }
      else
        c=1;
    }

    c = 0;
    while(c != 1)
    {
      cout<<"\n\t\t\t\t\t Year(in 4 digits) : ";
      cin >> D.y;
      if((D.y <= 1990)||(D.y>2021) )
      {
        cout << "\n\t\tYear out of range!!\n";
        PlaySound(TEXT("Year_error.wav"),NULL,SND_SYNC);
        c = 0;
      }
      else
        c = 1;
    }
    pol.date_arrest.d=D.d;
    pol.date_arrest.m=D.m;
    pol.date_arrest.y=D.y;
    loc = (check-1)*sizeof(Criminal);
    file.seekp(loc);
    file.write((char*)this,sizeof(Criminal));
    file.close();
    cout <<"\n";
    fflush(stdin);
    cout << "\n\t\tRecord Modified!";
    PlaySound(TEXT("Record_modified.wav"),NULL,SND_SYNC);

  }
  else
  {
      cout << "\n\n\t\t'Y' to try again or 'N' to go out : ";
      char ch_m;
      cin >> ch_m;
      fflush(stdin);
      if(ch_m == 'y' || ch_m == 'Y')
      {
        system("cls");
        goto modify_start;
      }
      else
      {
        callExit();
      }
  }
}

void Criminal::list() // function to list all criminal records
{
  system("cls");
  fflush(stdin);
  int j ;
  fstream file;
  file.open("records.txt",ios::in|ios::ate|ios::binary);
  int q = file.tellg();
  int c = q/sizeof(Criminal);
  file.seekg(0);
  cout<<"                            \n";
  cout<<"		                                 \n";
  cout<<"                                CONVICT  LIST    \n";
  cout<<"			                         \n";
  cout<<"                            \n";
  cout<<"\n================================================================================\n";
  cout<<"SR.\tNAME\t\t\tCONVICT NO.\t\t\tCRIME\n";
  cout<<"================================================================================\n";
  int i = 0;
  while(file.read((char*)this,sizeof(Criminal)))
  {
    i++;
    cout << i << "   ";
    for(j=0; j<strlen(name); j++)
      cout << name[j];
    cout<<"\t\t\t   ";
    for(j=0; j<strlen(convict_no); j++)
      cout << convict_no[j];
    cout << "\t\t\t   ";
    for(j=0; j<strlen(crime); j++)
      cout << crime[j];
      cout <<"\n";
      fflush(stdin);
      getchar();
    cout << "\n--------------------------------------------------------------------------------\n";
    PlaySound(TEXT("sucess.wav"),NULL,SND_SYNC);
    if((i%3)==0&&(i!=c))
    {
      system("pause");
      system("cls");
      cout << "\n================================================================================\n";
      cout << "SR.\tNAME\t\t\tCONVICT NO.\t\t\tCRIME\n";
      cout << "================================================================================\n";
    }
  }
  file.close();
  getchar();
}

void Criminal::empty()
{
  int i;
  for(i=0; i<20; i++)
    name[i]=' ';
  for(i=0; i<10; i++)
    convict_no[i]=' ';
  for(i=0; i<3; i++)
    sex[i]=' ';
  for(i=0; i<4; i++)
    age[i]=' ';
  for(i=0; i<50; i++)
    address[i]=' ';
  for(i=0; i<20; i++)
    court[i]=' ';
  for(i=0; i<20; i++)
    crime[i]=' ';
  for(i=0; i<20; i++)
    act[i]=' ';
  for(i=0; i<20; i++)
    state[i]=' ';
  for(i=0; i<20; i++)
    colour[i]=' ';
  for(i=0; i<20; i++)
    imark[i]=' ';
  for(i=0; i<20; i++)
    face[i]=' ';
  for(i=0; i<6; i++)
    height[i]=' ';
  for(i=0; i<15; i++)
    eye_color[i]=' ';
  for(i=0; i<50; i++)
    pol.station[i]=' ';
  for(i=0; i<10; i++)
  pol.fir[i]=' ';
  pol.date_arrest.m = 0;
  pol.date_arrest.d = 0;
  pol.date_arrest.y = 0;
}


