//Project - Practice Test Module
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//struct INSTITUTE_DETAILS begins here
struct institute_details
{
public:
    int n_students,n_qp1,n_qp2,n_qp3;
    char qp1_testname[10][20],qp2_testname[10][20],qp3_testname[10][20];
    float qp1_avg[10],qp2_avg[10],qp3_avg[10];
    void initial()
    {
        n_students=0;
        n_qp1=0;
        n_qp2=0;
        n_qp3=0;
    }
} MVM;
//struct INSTITUTE_DETAILS ends here
void put_institute()                     //to put mvm back in file at the end
{
    fstream inst("Inst.dat",ios::binary|ios::in|ios::out|ios::ate);
    if(!inst)
    {
        cout<<"FNF!";
        return;
    }
    inst.seekg(0,ios::beg);
    inst.write((char*)&MVM,sizeof(MVM));
}
//class ADMIN begins here
class admin
{
public:
    char userid[20];
    char password[20];
    void initial()
    {
        strcpy(userid,"23419");
        strcpy(password,"P");
    }
} GG;
//class ADMIN ends here

//functions to get and put admin here
void put_admin()
{
    fstream ad("Admin.dat",ios::binary|ios::in|ios::out|ios::ate);
    ad.seekg(0,ios::beg);
    ad.write((char*)&GG,sizeof(GG));
}
void main()
{
    clrscr();
    MVM.initial();
    GG.initial();
    put_institute();
    put_admin();
    getch();
}
