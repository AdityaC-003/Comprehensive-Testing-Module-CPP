//Project - Practice Test Module
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


//Class SCQ begins here
class scq
{
   char qn[200];
   char opa[50],opb[50],opc[50],opd[50];
   char ans;
   int mark;
   public:
   void scq_c(char QN[200],char OPA[50],char OPB[50],char OPC[50],char OPD[50],char ANS)
   {
      strcpy(qn,QN);
      strcpy(opa,OPA);
      strcpy(opb,OPB);
      strcpy(opc,OPC);
      strcpy(opd,OPD);
      ans=ANS;
   }
   void scq_display()
   {
      puts(qn);
      puts(opa);
      puts(opb);
      puts(opc);
      puts(opd);
   }
   char scq_retans()
   {
      return ans;
   }
   int scq_anscheck(char response)
   {
      if(ans==response)
      mark=3;
      else if(response=='X' || response=='x')
      mark=0;
      else mark=-1;
      return mark;
   }
   void scq_analysis(char response)
   {
      scq_display();
      cout<<"Correct Answer:"<<ans<<endl;
      cout<<"Your Answer:"<<response<<endl;
      cout<<"Marks Scored:"<<mark<<endl;
   }
};
//Class SCQ ends here


//Class NUMERICAL begins here
class numerical
{
   char qn[200];
   float ans;
   int mark;
   public:
   void numerical_c(char QN[200],float ANS)
   {
      strcpy(qn,QN);
      ans=ANS;
   }
   void numerical_display()
   {
      puts(qn);
   }
   float numerical_retans()
   {
      return ans;
   }
   int numerical_anscheck(float response)
   {
      if(response==-1) mark=0;
      else if(response>=0.98*ans && response<=1.02*ans)
      mark=3;
      else mark=0;
      return mark;
   }
   void numerical_analysis(float response)
   {
      numerical_display();
      cout<<"Correct Answer:"<<ans<<endl;
      cout<<"Your Answer:"<<response<<endl;
      cout<<"Marks Scored:"<<mark<<endl;
   }
};
//Class NUMERICAL ends here


//Functions ALPHASORT & FINDCHAR begin here
int findchar(char str[20],char a)
{
   int flag=0;
   for(int i=0;i<strlen(str);i++)
   {
      if(str[i]==a)
      {
	 flag=1;
	 break;
      }
   }
   return flag;
}
void alphasort(char a[20])
{
   char temp;
   for(int i=0;i<strlen(a);i++)
   for(int j=0;j<strlen(a)-1-i;j++)
   if(a[j]>a[j+1])
   {
	temp=a[j];
	a[j+1]=a[j];
	a[j+1]=temp;
   }
}
//Functions ALPHASORT and FINDCHAR end here


//Class MCQ begins here
class mcq
{
   char qn[200];
   char opa[50],opb[50],opc[50],opd[50];
   char ans[5];
   int mark;
   public:
   void mcq_c(char QN[200],char OPA[50],char OPB[50],char OPC[50],char OPD[50],char ANS[5])
   {
      strcpy(qn,QN);
      strcpy(opa,OPA);
      strcpy(opb,OPB);
      strcpy(opc,OPC);
      strcpy(opd,OPD);
      strcpy(ans,ANS);
   }
   void mcq_display()
   {
      puts(qn);
      puts(opa);
      puts(opb);
      puts(opc);
      puts(opd);
   }
   char* mcq_retans()
   {
	return ans;
   }
   int mcq_anscheck(char response[5]);
   void mcq_analysis(char response[5])
   {
      mcq_display();
      cout<<"Correct Answer:"<<ans<<endl;
      cout<<"Your Answer:"<<response<<endl;
      cout<<"Marks Scored:"<<mark<<endl;
   }
};
int mcq::mcq_anscheck(char response[5])
{
   for(int i=0;i<5;i++)
   toupper(response[i]);
   alphasort(response);
   if(strlen(ans)<strlen(response))
   mark=-1;
   else if(strcmpi(ans,response)==0)
   mark=4;
   else
   {
      mark=0;
      for(char i='A';i<'E';i++)
      {
	 if(findchar(ans,i)==1 && findchar(response,i)==1)
	 mark++;
	 else if(findchar(ans,i)==0 && findchar(response,i)==1)
	 {
	    mark=-1;
	    return mark;
	 }
      }
   }
   return mark;
}
//Class MCQ ends here


//Class MATRIX begins here
class matrix
{
   char a[50],b[50],c[50],d[50],p[30],q[30],r[30],s[30];
   int mark;
   public:
   char ans[4][5];
   void matrix_c(char A[50],char B[50],char C[50],char D[50],char P[30],char Q[30],char R[30],char S[30],char ANS[4][5]);
   void matrix_display()
   {
      cout<<a<<"\t"<<p<<"\n";
      cout<<b<<"\t"<<q<<"\n";
      cout<<c<<"\t"<<r<<"\n";
      cout<<d<<"\t"<<s<<"\n";
   }
   int matrix_anscheck(char response[4][5]);
   void matrix_analysis(char response[4][5]);
};
void matrix::matrix_c(char A[50],char B[50],char C[50],char D[50],char P[30],char Q[30],char R[30],char S[30],char ANS[4][5])
{
   strcpy(a,A);
   strcpy(b,B);
   strcpy(c,C);
   strcpy(d,D);
   strcpy(p,P);
   strcpy(q,Q);
   strcpy(r,R);
   strcpy(s,S);
   for(int i=0;i<4;i++)
   strcpy(ans[i],ANS[i]);
}
int matrix::matrix_anscheck(char response[4][5])
{
   int i;
   for(i=0;i<4;i++)
   {
      for(int j=0;i<5;j++)
      toupper(response[i][j]);
      alphasort(response[i]);
   }
   mark=0;
   for(i=0;i<4;i++)
   if(strcmpi(ans[i],response[i])==0)
   mark+=2;
   else if(response[i]!="X")
   mark-=1;
   return mark;
}
void matrix::matrix_analysis(char response[4][5])
{
   matrix_display();
   cout<<"Correct Answer:";
   for(int i=0;i<4;i++)
   cout<<ans[i]<<";";
   cout<<endl;
   cout<<"Your Answer:";
   for(int j=0;j<4;j++)
   cout<<response[i]<<";";
   cout<<endl;
   cout<<"Marks Scored:"<<mark<<endl;
}
//Class MATRIX end here


//Class QP1 starts here
class qp1
{
   public:
   char testname[20];
   scq a[15];
   numerical b[5];
   void qp1_c();
   void qp1_result(char scq_res[15],float num_res[5]);
}p1;
void qp1::qp1_c()
{
   char QN[200],OPA[50],OPB[50],OPC[50],OPD[50],ANS1;
   int i;float ANS2;
   cout<<"Enter TestName:";
   gets(testname);
   cout<<"SCQ:\n";
   for(i=0;i<15;i++)
   {
      cout<<"Enter Question:"<<i+1;
      gets(QN);
      cout<<"Enter Option A:";
      gets(OPA);
      cout<<"Enter Option B:";
      gets(OPB);
      cout<<"Enter Option C:";
      gets(OPC);
      cout<<"Enter Option D:";
      gets(OPD);
      cout<<"Enter Answer:";
      cin>>ANS1;
      a[i].scq_c(QN,OPA,OPB,OPC,OPD,ANS1);
   }
   cout<<"Numerical:\n";
   for(i=0;i<5;i++)
   {
     cout<<"Enter Question:"<<i+16;
     gets(QN);
     cout<<"Enter Answer:";
     cin>>ANS2;
     b[i].numerical_c(QN,ANS2);
   }
}
void qp1::qp1_result(char scq_res[15],float num_res[5])
{
   int i;
   int scq_tot=0,numerical_tot=0,grand_total=0;
   cout<<"Q.No\tQ_Type\tCorrect Answer\tResponse\tMarks"<<endl;
   for(i=0;i<15;i++)
   {
      cout<<i<<"\t"<<"SCQ"<<a[i].scq_retans()<<"\t"<<scq_res[i]<<"\t"<<a[i].scq_anscheck(scq_res[i])<<endl;
      scq_tot+=a[i].scq_anscheck(scq_res[i]);
   }
   for(i=0;i<5;i++)
   {
      cout<<i+11<<"\t"<<"Numerical"<<b[i].numerical_retans()<<"\t"<<num_res[i]<<"\t"<<b[i].numerical_anscheck(num_res[i])<<endl;
      numerical_tot+=b[i].numerical_anscheck(num_res[i]);
   }
   grand_total=numerical_tot+scq_tot;
   cout<<"Q_Type\tYour Marks\tMax marks"<<endl;
   cout<<"SCQ\t"<<scq_tot<<"\t"<<45<<endl;
   cout<<"Numerical\t"<<numerical_tot<<"\t"<<15<<endl;
   cout<<"Total\t"<<grand_total<<"\t"<<60<<endl;
}
//Class QP1 ends here


//Class QP2 begins here
class qp2
{
   public:
   char testname[20];
   scq a[4];
   mcq c[8];
   numerical b[8];
   void qp2_c();
   void qp2_result(char scq_res[4],char mcq_res[8][5],float num_res[8]);
}p2;
void qp2::qp2_c()
{
   char QN[200],OPA[50],OPB[50],OPC[50],OPD[50],ANS1,ANS2[5];
   int i;
   float ANS3;
   cout<<"Enter TestName:";
   gets(testname);
   cout<<"SCQ:\n";
   for(i=0;i<4;i++)
   {
      cout<<"Enter Question:"<<i+1;
      gets(QN);
      cout<<"Enter Option A:";
      gets(OPA);
      cout<<"Enter Option B:";
      gets(OPB);
      cout<<"Enter Option C:";
      gets(OPC);
      cout<<"Enter Option D:";
      gets(OPD);
      cout<<"Enter Answer:";
      cin>>ANS1;
      a[i].scq_c(QN,OPA,OPB,OPC,OPD,ANS1);
   }
   cout<<"MCQ:\n";
   for(i=0;i<8;i++)
   {
      cout<<"Enter Question:"<<i+5;
      gets(QN);
      cout<<"Enter Option A:";
      gets(OPA);
      cout<<"Enter Option B:";
      gets(OPB);
      cout<<"Enter Option C:";
      gets(OPC);
      cout<<"Enter Option D:";
      gets(OPD);
      cout<<"Enter Answer:";
      gets(ANS2);
      c[i].mcq_c(QN,OPA,OPB,OPC,OPD,ANS2);
   }
   cout<<"Numerical:\n";
   for(i=0;i<8;i++)
   {
      cout<<"Enter Question:"<<i+13;
      gets(QN);
      cout<<"Enter Answer:";
      cin>>ANS3;
      b[i].numerical_c(QN,ANS3);
   }
}
void qp2::qp2_result(char scq_res[4],char mcq_res[8][5],float num_res[8])
{
   int i;
   int scq_tot=0,mcq_tot=0,numerical_tot=0,grand_total=0;
   cout<<"Q.No\tQ_Type\tCorrect Answer\tResponse\tMarks"<<endl;
   for(i=0;i<4;i++)
   {
      cout<<i<<"\t"<<"SCQ"<<a[i].scq_retans()<<"\t"<<scq_res[i]<<"\t"<<a[i].scq_anscheck(scq_res[i])<<endl;
      scq_tot+=a[i].scq_anscheck(scq_res[i]);
   }
   for(i=0;i<8;i++)
   {
      cout<<i+5<<"\t"<<"MCQ"<<c[i].mcq_retans()<<"\t"<<mcq_res[i]<<"\t"<<c[i].mcq_anscheck(mcq_res[i])<<endl;
      mcq_tot+=c[i].mcq_anscheck(mcq_res[i]);
   }
   for(i=0;i<8;i++)
   {
      cout<<i+13<<"\t"<<"Numerical"<<b[i].numerical_retans()<<"\t"<<num_res[i]<<"\t"<<b[i].numerical_anscheck(num_res[i])<<endl;
      numerical_tot+=b[i].numerical_anscheck(num_res[i]);
   }
   grand_total=numerical_tot+scq_tot+mcq_tot;
   cout<<"Q_Type\tYour Marks\tMax marks"<<endl;
   cout<<"SCQ\t"<<scq_tot<<"\t"<<12<<endl;
   cout<<"MCQ\t"<<mcq_tot<<"/t"<<32<<endl;
   cout<<"Numerical\t"<<numerical_tot<<"\t"<<24<<endl;
   cout<<"Total\t"<<grand_total<<"\t"<<68<<endl;
}
//Class QP2 ends here


//Class QP3 begins here
class qp3
{
   public:
   char testname[20];
   mcq c[8];
   numerical b[8];
   matrix d[2];
   void qp3_c();
   void qp3::qp3_result(char mcq_res[8][5],float num_res[8],char matrix_res[2][4][5]);
}p3;
void qp3::qp3_c()
{
   char QN[200],OPA[50],OPB[50],OPC[50],OPD[50],ANS1[5];
   int i;
   float ANS2;
   char P[50],Q[50],R[50],S[50],ANS3[4][5];
   cout<<"Enter TestName:";
   gets(testname);
   cout<<"MCQ:\n";
   for(i=0;i<8;i++)
   {
      cout<<"Enter Question:"<<i+1;
      gets(QN);
      cout<<"Enter Option A:";
      gets(OPA);
      cout<<"Enter Option B:";
      gets(OPB);
      cout<<"Enter Option C:";
      gets(OPC);
      cout<<"Enter Option D:";
      gets(OPD);
      cout<<"Enter Answer:";
      cin>>ANS1;
      c[i].mcq_c(QN,OPA,OPB,OPC,OPD,ANS1);
   }
   cout<<"Numericals:\n";
   for(i=0;i<8;i++)
   {
      cout<<"Enter Question:"<<i+9;
      gets(QN);
      cout<<"Enter Answer:";
      cin>>ANS2;
      b[i].numerical_c(QN,ANS2);
   }
}
void qp3::qp3_result(char mcq_res[8][5],float num_res[8],char matrix_res[2][4][5])
{
   int i;
   int matrix_tot=0,mcq_tot=0,numerical_tot=0,grand_total=0;
   cout<<"Q.No\tQ_Type\tCorrect Answer\tResponse\tMarks"<<endl;
   for(i=0;i<8;i++)
   {
      cout<<i<<"\t"<<"MCQ"<<c[i].mcq_retans()<<"\t"<<mcq_res[i]<<"\t"<<c[i].mcq_anscheck(mcq_res[i])<<endl;
      mcq_tot+=c[i].mcq_anscheck(mcq_res[i]);
   }
   for(i=0;i<8;i++)
   {
      cout<<i+9<<"\t"<<"Numerical"<<b[i].numerical_retans()<<"\t"<<num_res[i]<<"\t"<<b[i].numerical_anscheck(num_res[i])<<endl;
      numerical_tot+=b[i].numerical_anscheck(num_res[i]);
   }
   for(i=0;i<2;i++)
   {
      cout<<i+17<<"\t"<<"Matrix";
      for(int j=0;j<4;j++)
      cout<<d[i].ans[j]<<";";
      cout<<"\t";
      for(int k=0;k<4;k++)
      cout<<matrix_res[i][k]<<";";
      cout<<"\t"<<d[i].matrix_anscheck(matrix_res[i])<<endl;
      matrix_tot+=d[i].matrix_anscheck(matrix_res[i]);
   }
   grand_total=numerical_tot+matrix_tot+mcq_tot;
   cout<<"Q_Type\tYour Marks\tMax marks"<<endl;
   cout<<"MCQ\t"<<mcq_tot<<"/t"<<32<<endl;
   cout<<"Numerical\t"<<numerical_tot<<"\t"<<24<<endl;
   cout<<"Matrix_Matching\t"<<matrix_tot<<"\t"<<16<<endl;
   cout<<"Total\t"<<grand_total<<"\t"<<62<<endl;
}         //Class QP3 ends here


class type1                   //Class type1 begins here
{
   public:
   char scq_res[16];
   float num_res[5];
   qp1 ob1;
   type1();
};
type1::type1()
{
   int i;
   for(i=0;i<15;i++)
   scq_res[i]='X';
   for(i=0;i<5;i++)
   num_res[i]=-1;
}
//Class type1 ends here


//Class type2 begins here
class type2
{
   public:
   char scq_res[5];
   char mcq_res[8][5];
   float num_res[8];
   qp2 ob2;
   type2();
};
type2::type2()
{
   int i;
   for(i=0;i<4;i++)
   scq_res[i]='X';
   for(i=0;i<8;i++)
   strcpy(mcq_res[i],"X");
   for(i=0;i<8;i++)
   num_res[i]=-1;
}
//Class type2 ends here


//Class type3 begins here
class type3
{
   public:
   char mcq_res[8][5];
   float num_res[8];
   char matrix_res[2][4][5];
   qp3 ob3;
   type3();
};
type3::type3()
{
  int i;
  for(i=0;i<8;i++)
  strcpy(mcq_res[i],"X");
  for(i=0;i<8;i++)
  num_res[i]=-1;
  for(i=0;i<2;i++)
  for(int j=0;j<4;j++)
  strcpy(matrix_res[i][j],"X");
}
//Class type3 ends here


//Class STUDENT begins here
class student
{
   char name[30],id[10],password[20];
   int std;
   char section;
   public:
   type1 test1[2];	int count1;
   type2 test2[2];      int count2;
   type3 test3[2];      int count3;
   char request[30];
   void stu_create()
   {
      cout<<"Enter Student Name:";
      gets(name);
      cout<<"Enter ID:";
      gets(id);
      cout<<"Enter Std:";
      cin>>std;
      cout<<"Enter Section:";
      cin>>section;
      cout<<"Enter Password:";
      gets(password);
      strcpy(request,"x");
      count1=count2=count3=0;
   }
   void stu_display();
   void stu_edit()
   {
      cout<<"CURRENT DETAILS:";
      stu_display();
      char x[20];
      cout<<"Enter field to be edited:";
      gets(x);
      if(strcmpi(x,"name")==0)
      {
	 cout<<"Enter new name:";
	 gets(name);
      }
      else if(strcmpi(x,"id")==0)
      {
	 cout<<"Enter new ID:";
	 gets(id);
      }
      else if(strcmpi(x,"std")==0)
      {
	 cout<<"Enter new std:";
	 cin>>std;
      }
      else if(strcmpi(x,"section")==0)
      {
	 cout<<"Enter new section:";
	 cin>>section;
      }
      else if(strcmpi(x,"password")==0)
      {
	 cout<<"Enter current password:";
	 char h[20];
	 gets(h);
	 if(strcmpi(h,password)==0)
	 {
	    cout<<"Enter new password:";
	    gets(password);
	 }
      }
   }
   char* ret_id()
   {
      return id;
   }
   char* ret_pass()
   {
      return password;
   }
};
void student::stu_display()
{
   cout<<"Student name:";
   puts(name);
   cout<<"ID:";
   puts(id);
   cout<<"Std:"<<std<<endl;
   cout<<"Section:"<<section<<"\n\n";
   cout<<"QPs of type 1 attempted:\n";
   int i;
   for(i=0;i<count1;i++)
   cout<<test1[i].ob1.testname<<endl;
   cout<<"QPs of type 2 attempted:\n";
   for(i=0;i<count2;i++)
   cout<<test2[i].ob2.testname<<endl;
   cout<<"QPs of type 3 attempted:\n";
   for(i=0;i<count3;i++)
   cout<<test3[i].ob3.testname<<endl;
}
//Class STUDENT ends here


//struct INSTITUTE_DETAILS begins here
struct institute_details
{
   public:
   int n_students,n_qp1,n_qp2,n_qp3;
   char qp1_testname[10][20],qp2_testname[10][20],qp3_testname[10][20];
   float qp1_avg[10],qp2_avg[10],qp3_avg[10];
}MVM;
//struct INSTITUTE_DETAILS ends here


//UDF to upload newstu_details onto binary file
void upload_newstu_details(student a)
{
   fstream fout("Student.dat",ios::binary|ios::out|ios::ate|ios::app);
   if(!fout)	{   cout<<"FNF!";	return;	}
   MVM.n_students++;
   fout.write((char*)&a,sizeof(a));
   fout.close();
}
//End of UDF


//class ADMIN begins here
class admin
{
   public:
   char userid[10];
   char password[20];

}GG;
//class ADMIN ends here

fstream ad;                        //functions to get and put admin here
void get_admin()
{
ad.read((char*)&GG,sizeof(GG));
}

void put_admin()
{
ad.seekg(0,ios::cur);
ad.write((char*)&GG,sizeof(GG));
}

//UDF to modify stu_details in binary file
void modify_stu_details(student &a)
{
   fstream f("Student.dat",ios::binary|ios::in|ios::out|ios::ate);
   if(!f)	{   cout<<"FNF!";	return;	}
   f.seekg(0,ios::beg);
   student t;
   while(f.read((char*)&t,sizeof(t)))
   {
      if(!strcmpi(a.ret_id(),t.ret_id()))
      {
	 f.seekg(-1*int(sizeof(a)),ios::cur);
	 f.write((char*)&a,sizeof(a));
      }
   }
   f.close();
}
//End of UDF

void test_analysis1(qp1,student &);
void test_analysis2(qp2,student &);
void test_analysis3(qp3,student &);

void instructions1()                      //Start of Instruction UDFs
{
   cout<<"General instructions:\nAfter answering a question, press:N to go to next question,Q to choose which question you want to go to,S to submit, I to view instructions again\n\n";
   cout<<"Default answer for SCQ = X, for Numerical -1\n";
   cout<<"Paper pattern & marking scheme:\n";
   cout<<"This test contains 15 Single Choice(SCQ) and 5 Numerical Type Questions.\n";
   cout<<"SCQ(Q 1-15): +3 for correct answer,0 if not attempted and -1 in all other cases.";
   cout<<"Numericals(Q 16-20): +3 for correct answer and 0 in all other cases.\n";
}
void instructions2()
{
   cout<<"General instructions:\nAfter answering a question, press:N to go to next question,Q to choose which question you want to go to,S to submit, I to view instructions again\n\n";
   cout<<"Default answer for SCQ & MCQ= X, for Numerical -1, for Matrix matching X for each row\n";
   cout<<"Paper pattern & marking scheme:\n";
   cout<<"This test contains 4 Single Choice(SCQ),8 Multiple Choice(MCQ) and 8 Numerical Type Questions.\n";
   cout<<"SCQ(Q 1-4): +3 for correct answer,0 if not attempted and -1 in all other cases.";
   cout<<"Numericals(Q 5-12): +3 for correct answer and 0 in all other cases.\n";
   cout<<"MCQ(Q 13-20):\nFull marks of +4 if only (all) the correct option(s) are chosen,";
   cout<<"Partial marks of +1 per correct option if only correct option(s) are chosen but all correct options are not chosen,";
   cout<<"Zero marks if no option is chosen, and -1 in all other cases.\n";
}
void instructions3()
{
   cout<<"General instructions:\nAfter answering a question, press:N to go to next question,Q to choose which question you want to go to,S to submit, I to view instructions again\n\n";
   cout<<"Default answer for MCQ= X, for Numerical -1, for Matrix matching X for each row\n";
   cout<<"Paper pattern & marking scheme:\n";
   cout<<"This test contains 8 Multiple Choice(MCQ), 8 Numerical Type and 2 Matrix-Matching Questions.\n";
   cout<<"Numericals(Q 9-16): +3 for correct answer and 0 in all other cases.\n";
   cout<<"MCQ(Q 1-8):\nFull marks of +4 if only (all) the correct option(s) are chosen,";
   cout<<"Partial marks of +1 per correct option if only correct option(s) are chosen but all correct options are not chosen,";
   cout<<"Zero marks if no option is chosen, and -1 in all other cases.\n";
   cout<<"Matching(Q 17,18): For each row in Column 1 - +2 for correct answer and 0 in all other cases.\n";
}                //End of Instruction UDFs


//Display_Response_Function1 (DRF1) to display student response during test
void disp_res1(student &s)
{
   clrscr();
   int i;
   for(i=0;i<15;i++)
   cout<<i+1<<"-"<<s.test1[s.count1].scq_res[i]<<"\t";
   for(i=0;i<5;i++)
   cout<<i+16<<"-"<<s.test1[s.count1].num_res[i]<<"\t";
   cout<<endl;
}
//DRF1 ends


//Test_Procedure_Function1 (TPF1) - Runs during test
void test_procedure1(qp1 &X,student &s)
{
   s.test1[s.count1].ob1=X;
   int i=0;
   char rep='N',rep2='N';
   clrscr();
   disp_res1(s);
   X.a[i].scq_display();
   cin>>s.test1[s.count1].scq_res[i];
   cout<<"Next?";
   cin>>rep;
   toupper(rep);
   while(rep!='S')
   {
      if(rep=='N')
      {
	 i++;
	 if(i<15)
	 {
	    disp_res1(s);
	    X.a[i].scq_display();
	    cin>>s.test1[s.count1].scq_res[i];
	 }
	 else if(i>=15 && i<20)
	 {
	    disp_res1(s);
	    X.b[i-15].numerical_display();
	    cin>>s.test2[s.count2].num_res[i-15];
	 }
	 else if(i==20)
	 cout<<"You have reached the end of the test.";
	 else cout<<"Invalid";
      }
      else if(rep=='Q')
      {
	 cout<<"Enter question number:";
	 int q;
	 cin>>q;
	 if(q<1 || q>20)
	 {
	    cout<<"Invalid choice, reenter q_no:";
	    cin>>q;
	 }
	 else if(q<16)
	 {
	    disp_res1(s);
	    i=q-1;
	    X.a[i].scq_display();
	    cin>>s.test1[s.count1].scq_res[i];
	 }
	 else
	 {
	    disp_res1(s);
	    i=q-1;
	    X.b[i-15].numerical_display();
	    cin>>s.test1[s.count1].num_res[i-15];
	 }
      }
      else if(rep=='I')
      {
	 disp_res1(s);
	 instructions1();
      }
      else if(rep=='S')
      {
	 cout<<"Do you want to submit[Y/N]?";
	 cin>>rep2;
	 toupper(rep2);
      }
      else
      cout<<"Invalid\n";
      if(rep2!='S')
      {
	 cout<<"Next?";
	 cin>>rep;
	 toupper(rep);
      }
   }


   clrscr();
   cout<<"Congrats!You've finished the test.";
   cout<<"Do you want to view your results:\n";
   cin>>rep;
   toupper(rep);
   if(rep=='Y')
   s.test1[s.count1].ob1.qp1_result(s.test1[s.count1].scq_res,s.test1[s.count1].num_res);
   s.count1++;
   cout<<"Uploading results...\n";
   modify_stu_details(s);
   cout<<"Do you want to see test analysis?\n";
   cin>>rep;
   toupper(rep);
   if(rep=='Y')
   test_analysis1(X,s);
}
//TPF1 ends here


//DRF2 starts here
void disp_res2(student &s)
{
   clrscr();
   int i;
   for(i=0;i<4;i++)
   cout<<i+1<<"-"<<s.test2[s.count2].scq_res[i]<<"\t";
   for(i=0;i<8;i++)
   cout<<i+5<<"-"<<s.test2[s.count2].mcq_res[i]<<"\t";
   for(i=0;i<8;i++)
   cout<<i+13<<"-"<<s.test2[s.count2].num_res[i]<<"\t";
   cout<<endl;
}
//DRF2 ends here


//TPF2 starts here
void test_procedure2(qp2 X,student &s)
{
   s.test2[s.count2].ob2=X;
   int i=0;
   char rep='N',rep2='N';
   clrscr();
   disp_res2(s);
   X.a[i].scq_display();
   cin>>s.test2[s.count2].scq_res[i];
   cout<<"Next?";
   cin>>rep;
   toupper(rep);
   while(rep2!='S')
   {
      if(rep=='N')
      {
	 i++;
	 if(i<4)
	 {
	    clrscr();
	    disp_res2(s);
	    X.a[i].scq_display();
	    cin>>s.test2[s.count2].scq_res[i];
	 }
	 else if(i>=4 && i<12)
	 {
	    disp_res2(s);
	    X.c[i-4].mcq_display();
	    gets(s.test2[s.count2].mcq_res[i-4]);
	 }
	 else if(i>=12 && i<20)
	 {
	    disp_res2(s);
	    X.b[i-12].numerical_display();
	    cin>>s.test2[s.count2].num_res[i-12];
	 }
	 else if(i==20)
	 cout<<"You have reached the end of the test.";
	 else
	 cout<<"Invalid";
      }
      else if(rep=='Q')
      {
	 cout<<"Enter question number:";
	 int q;
	 cin>>q;
	 if(q<1 || q>20)
	 {
	    cout<<"Invalid choice, reenter q_no:";
	    cin>>q;
	 }
	 else if(q<5)
	 {
	    disp_res2(s);
	    i=q-1;
	    X.a[i].scq_display();
	    cin>>s.test2[s.count2].scq_res[i];
	 }
	 else if(q<13)
	 {
	    disp_res2(s);
	    i=q-1;
	    X.c[i-4].mcq_display();
	    gets(s.test2[s.count2].mcq_res[i-4]);
	 }
	 else
	 {
	    disp_res2(s);
	    i=q-1;
	    X.b[i-12].numerical_display();
	    cin>>s.test2[s.count2].num_res[i-12];
	 }
      }
      else if(rep=='I')
      {
	 disp_res2(s);
	 instructions2();
      }
      else if(rep=='S')
      {
	 cout<<"Do you want to submit[S/N]?";
	 cin>>rep2;
	 toupper(rep2);
      }
      else
      cout<<"Invalid";
      if(rep2!='S')
      {
	 cout<<"Next?";
	 cin>>rep;
	 toupper(rep);
      }
   }
   clrscr();
   cout<<"Congrats!You've finished the test.";
   cout<<"Do you want to view Results?\n";
   cin>>rep;
   toupper(rep);
   if(rep=='Y')
   s.test2[s.count2].ob2.qp2_result(s.test2[s.count2].scq_res,s.test2[s.count2].mcq_res,s.test2[s.count2].num_res);
   s.count2++;
   cout<<"Uploading details...";
   modify_stu_details(s);
   cout<<"Do you want to see analysis?";
   cin>>rep;
   toupper(rep);
   if(rep=='Y')
   test_analysis2(X,s);
}
//TPF2 ends


//DRF3 begins
void disp_res3(student &s)
{
   clrscr();
   int i;
   for(i=0;i<8;i++)
   cout<<i+1<<"-"<<s.test3[s.count3].mcq_res[i]<<"\t";
   for(i=0;i<8;i++)
   cout<<i+9<<"-"<<s.test3[s.count3].num_res[i]<<"\t";
   for(i=0;i<2;i++)
   {
      cout<<i+17<<"-";
      for(int j=0;j<4;j++)
      cout<<s.test3[s.count3].matrix_res[i][j]<<";";
      cout<<"\t";
   }
   cout<<endl;
}
//DRF3 ends


//TPF3 begins
void test_procedure3(qp3 X,student &s)
{
   s.test3[s.count3].ob3=X;
   int i=0;
   char rep='N',rep2='N';
   clrscr();
   disp_res3(s);
   X.c[i].mcq_display();
   cin>>s.test3[s.count3].mcq_res[i];
   cout<<"Next?";
   cin>>rep;
   toupper(rep);
   while(rep2!='S')
   {
      if(rep=='N')
      {
	 i++;
	 if(i<8)
	 {
	    disp_res3(s);
	    X.c[i].mcq_display();
	    gets(s.test3[s.count3].mcq_res[i]);
	 }
	 else if(i<16)
	 {
	    disp_res3(s);
	    X.b[i-8].numerical_display();
	    cin>>s.test3[s.count3].num_res[i-8];
	 }
	 else if(i==16 || i==17)
	 {
	    disp_res3(s);
	    X.d[i-16].matrix_display();
	    char ch='A';
	    for(int j=0;j<4;j++,ch++)
	    {
	       cout<<ch;
	       gets(s.test3[s.count2].matrix_res[i-16][j]);
	    }
	 }
	 else if(i==18)
	 cout<<"You have reached the end of the test.";
	 else cout<<"Invalid";
      }
      else if(rep=='Q')
      {
	 cout<<"Enter question number:";
	 int q;
	 cin>>q;
	 if(q<1 || q>18)
	 {
	    cout<<"Invalid choice, reenter q_no:";
	    cin>>q;
	 }
	 else if(q<9)
	 {
	    disp_res3(s);
	    i=q-1;
	    X.c[i].mcq_display();
	    gets(s.test3[s.count3].mcq_res[i]);
	 }
	 else if(q<17)
	 {
	    disp_res3(s);
	    i=q-1;
	    X.b[i-8].numerical_display();
	    cin>>s.test3[s.count3].num_res[i-8];
	 }
	 else
	 {
	    clrscr();
	    disp_res3(s);
	    i=q-1;
	    X.d[i-16].matrix_display();
	    char ch='A';
	    for(int j=0;j<4;j++)
	    {
	       cout<<ch;
	       gets(s.test3[s.count3].matrix_res[i-16][j]);
	       ch++;
	    }
	 }
      }
      else if(rep=='I')
      {
	 disp_res3(s);
	 instructions3();
      }
      else if(rep=='S')
      {
	 cout<<"Do you want to submit[Y/N]?";
	 cin>>rep2;
	 toupper(rep2);
      }
      else
      cout<<"Invalid";
      if(rep2!='S')
      {
	 cout<<"Next?";
	 cin>>rep;
	 toupper(rep);
      }
   }
   clrscr();
   cout<<"Congrats!You've finished the test.";
   cout<<"Do you want to view Results?\n";
   cin>>rep;
   toupper(rep);
   if(rep=='Y')
   s.test3[s.count3].ob3.qp3_result(s.test3[s.count3].mcq_res,s.test3[s.count3].num_res,s.test3[s.count3].matrix_res);
   s.count3++;
   cout<<"Uploading results...";
   modify_stu_details(s);
   cout<<"Do you want to see analysis?";
   cin>>rep;
   toupper(rep);
   if(rep=='Y')
   test_analysis3(X,s);
}
//TPF3 ends


//Test_Analysis_Function1(TAF1) begins
void test_analysis1(qp1 X,student &s)
{
   int i=0;
   char rep='N',rep2='N';
   clrscr();
   cout<<"Instructions: Enter N for next, Q to choose which question you want to go to, and X to exit analysis";
   X.a[i].scq_analysis(s.test1[s.count1-1].scq_res[i]);
   cout<<"Next?";
   cin>>rep;
   toupper(rep);
   while(rep2!='X')
      {
	 if(rep=='N')
	 {
	    i++;
	    if(i<15)
	    {
	       clrscr();
	       X.a[i].scq_analysis(s.test1[s.count1-1].scq_res[i]);
	    }
	    else if(i>=15 && i<20)
	    {
	       clrscr();
	       X.b[i-15].numerical_analysis(s.test1[s.count1-1].num_res[i-15]);
	    }
	    else if(i==20)
	    {
	       cout<<"You have reached the end of the analysis.";
	    }
	    else cout<<"Invalid";
	 }
	 else if(rep=='Q')
	 {
	    cout<<"Enter question number:";
	    int q;
	    cin>>q;
	    if(q<1 || q>20)
	    {
	       cout<<"Invalid choice, reenter q_no:";
	       cin>>q;
	    }
	    else if(q<16)
	    {
	       clrscr();
	       i=q-1;
	       X.a[i].scq_analysis(s.test1[s.count1-1].scq_res[i]);
	    }
	    else
	    {
	       clrscr();
	       i=q-1;
	       X.b[i-15].numerical_analysis(s.test1[s.count1-1].num_res[i-15]);
	    }
	 }
      else if(rep=='X')
      {
	 cout<<"Do you want to exit[Y/N]?";
	 cin>>rep2;
	 toupper(rep2);
      }
      else
      cout<<"Invalid\n";
      if(rep2!='X')
      {
	 cout<<"Next?";
	 cin>>rep;
	 toupper(rep);
      }
   }
   clrscr();
}
//TAF1 ends


//TAF2 begins
void test_analysis2(qp2 X,student &s)
{
   int i=0;
   char rep='N',rep2='N';
   clrscr();
    cout<<"Instructions: Enter N for next, Q to choose which question you want to go to, and X to exit analysis";
   X.a[i].scq_analysis(s.test2[s.count2-1].scq_res[i]);
   cout<<"Next?";
   cin>>rep;
   toupper(rep);
   while(rep2!='X')
      {
	 if(rep=='N')
	 {
	    i++;
	    if(i<4)
	    {
	       clrscr();
	       X.a[i].scq_analysis(s.test2[s.count2-1].scq_res[i]);
	    }
	    else if(i>=4 && i<12)
	    {
	       clrscr();
	       X.c[i-4].mcq_analysis(s.test2[s.count2-1].mcq_res[i-4]);
	    }
	    else if(i>=12 && i<20)
	    {
	       clrscr();
	       X.b[i-12].numerical_analysis(s.test2[s.count2-1].num_res[i-12]);
	    }
	    else if(i==20)
	    {
	       cout<<"You have reached the end of the analysis.";
	    }
	    else cout<<"Invalid";
	 }
	 else if(rep=='Q')
	 {
	    cout<<"Enter question number:";
	    int q;
	    cin>>q;
	    if(q<1 || q>20)
	    {
	       cout<<"Invalid choice, reenter q_no:";
	       cin>>q;
	    }
	    else if(q<5)
	    {
	       clrscr();
	       i=q-1;
	       X.a[i].scq_analysis(s.test2[s.count2-1].scq_res[i]);
	    }
	    else if(q<13)
	    {
	       clrscr();
	       i=q-1;
	       X.c[i-4].mcq_analysis(s.test2[s.count2-1].mcq_res[i-4]);
	    }
	    else
	    {
	       clrscr();
	       i=q-1;
	       X.b[i-12].numerical_analysis(s.test2[s.count2-1].num_res[i-12]);
	    }
	 }
      else if(rep=='X')
      {
	 cout<<"Do you want to exit[Y/N]?";
	 cin>>rep2;
	 toupper(rep2);
      }
      else
      cout<<"Invalid\n";
      if(rep2!='X')
      {
	 cout<<"Next?";
	 cin>>rep;
	 toupper(rep);
      }
   }
   clrscr();
}
//TAF2 ends


//TAF3 begins
void test_analysis3(qp3 X,student &s)
{
   int i=0;
   char rep='N',rep2='N';
   clrscr();
   X.c[i].mcq_analysis(s.test3[s.count3-1].mcq_res[i]);
   cout<<"Next?";
   cin>>rep;
   toupper(rep);
   while(rep2!='X')
      {
	 if(rep=='N')
	 {
	    i++;
	    if(i<8)
	    {
	       clrscr();
	       X.c[i].mcq_analysis(s.test3[s.count3-1].mcq_res[i]);
	    }
	    else if(i<16)
	    {
	       clrscr();
	       X.b[i-8].numerical_analysis(s.test3[s.count3-1].num_res[i-8]);
	    }
	    else if(i==16 || i==17)
	    {
	       clrscr();
	       X.d[i-16].matrix_analysis(s.test3[s.count3-1].matrix_res[i-16]);
	    }
	    else if(i==18)
	    {
	       cout<<"You have reached the end of the analysis.";
	    }
	    else cout<<"Invalid";
	 }
	 else if(rep=='Q')
	 {
	    cout<<"Enter question number:";
	    int q;
	    cin>>q;
	    if(q<1 || q>18)
	    {
	       cout<<"Invalid choice, reenter q_no:";
	       cin>>q;
	    }
	    else if(q<9)
	    {
	       clrscr();
	       i=q-1;
	       X.c[i].mcq_analysis(s.test3[s.count3-1].mcq_res[i]);
	    }
	    else if(q<17)
	    {
	       clrscr();
	       i=q-1;
	       X.b[i-8].numerical_analysis(s.test3[s.count3-1].num_res[i-8]);
	    }
	    else
	    {
	       clrscr();
	       i=q-1;
	       X.d[i-16].matrix_analysis(s.test3[s.count3-1].matrix_res[i-16]);
	    }

	 }
	 else if(rep=='X')
      {
	 cout<<"Do you want to exit[Y/N]?";
	 cin>>rep2;
	 toupper(rep2);
      }
      else
      cout<<"Invalid\n";
      if(rep2!='X')
      {
	 cout<<"Next?";
	 cin>>rep;
	 toupper(rep);
      }
   }
   clrscr();
}
//TAF3 ends



//START_PROCEDURE Begins
void start_procedure()
{
   char id[10];
   int flag=0;
   student t;
   cout<<"Enter ID of student who'll attempt the test:";
   gets(id);
   fstream fin("Student.dat",ios::binary|ios::in|ios::ate);
   if(!fin)	{	cout<<"FNF!";	return;	}
   while(fin.read((char*)&t,sizeof(t)))
   {
      if(strcmpi(t.ret_id(),id)==0)
      {
	 flag++;
	 break;
      }
   }
   fin.close();
   if(flag==0)
   cout<<"Student not found!";
   else
   {
      int n1;
      char n2[20];
      cout<<"Enter QP type and QP name of test to be assigned:";
      cin>>n1;
      gets(n2);
      cout<<"Downloading test...\n";
      if(n1==1)
      {
	 fstream fin("QP1.dat",ios::binary|ios::in|ios::ate);
	 if(!fin)	{	cout<<"FNF!";	return;	}
	 qp1 temp;
	 int flag1=0;
	 while(fin.read((char*)&temp,sizeof(temp)))
	 {
	    if(!strcmpi(temp.testname,n2))
	    {
	       flag1++;
	       break;
	    }
	 }
	 fin.close();
	 if(flag1==0)
	 cout<<"QP not found!";
	 else
	 {
	    char r,qwerty[10],asd[20];
	    cout<<"Test successfully downloaded.";
	     cout<<"Enter student ID:";
	    gets(qwerty);
	    cout<<"Enter student password:";
	    gets(asd);
	    if(strcmpi(t.ret_id(),qwerty)==0 && strcmp(t.ret_pass(),asd)==0)
	    {
	    cout<<"Press any key to view instructions:";
	    cin>>r;
	    instructions1();
	    cout<<"Are you ready to begin the test?\n";
	    r='X';
	    do
	    {
	       cout<<"Enter Y to begin testing,N to quit\n";
	       cin>>r;
	       toupper(r);
	       if(r=='Y')
	       test_procedure1(temp,t);
	       else if(r=='N')
	       break;
	       else
	       {
		  cout<<"Invalid,re-enter response:";
		  cin>>r;
	       }
	    }while(r!='Y');
	    }
	    else
	    cout<<"Wrong credentials!";
	 }
      }
      else if(n1==2)
      {
	 fstream fin("QP2.dat",ios::binary|ios::in|ios::ate);
	 if(!fin)	{	cout<<"FNF!";	return;	}
	 qp2 temp;
	 int flag2=0;
	 while(fin.read((char*)&temp,sizeof(temp)))
	 {
	    if(!strcmpi(temp.testname,n2))
	    {
	       flag2++;
	       break;
	    }
	 }
	 fin.close();
	 if(flag2==0)
	 cout<<"QP not found!";
	 else
	 {
	    char r,qwerty[10],asd[20];
	    cout<<"Test successfully downloaded.";
	    cout<<"Enter student ID:";
	    gets(qwerty);
	    cout<<"Enter student password:";
	    gets(asd);
	    if(strcmpi(t.ret_id(),qwerty)==0 && strcmp(t.ret_pass(),asd)==0)
	    {
	       cout<<"Press any key to view instructions:";
	       cin>>r;
	       instructions2();
	       cout<<"Are you ready to begin the test?\n";
	       r='X';
	       do
	       {
		  cout<<"Enter Y to begin testing,N to quit\n";
		  cin>>r;
		  toupper(r);
		  if(r=='Y')
		  test_procedure2(temp,t);
		  else if(r=='N')
		  break;
		  else
		  {
		    cout<<"Invalid,re-enter response:";
		    cin>>r;
		  }
	       }while(r!='Y');
	    }
	    else
	    cout<<"Wrong credentials!";
	 }
      }
      else if(n1==3)
      {
	 fstream fin("QP3.dat",ios::binary|ios::in|ios::ate);
	 if(!fin)	{	cout<<"FNF!";	return;	}
	 qp3 temp;
	 int flag3=0;
	 while(fin.read((char*)&temp,sizeof(temp)))
	 {
	    if(!strcmpi(temp.testname,n2))
	    {
	       flag3++;
	       break;
	    }
	 }
	 fin.close();
	 if(flag3==0)
	 cout<<"QP not found!";
	 else
	 {
	    char r,qwerty[10],asd[20];
	    cout<<"Test successfully downloaded.";
	    cout<<"Enter student ID:";
	    gets(qwerty);
	    cout<<"Enter student password:";
	    gets(asd);
	    if(strcmpi(t.ret_id(),qwerty)==0 && strcmp(t.ret_pass(),asd)==0)
	    {
	    cout<<"Press any key to view instructions:";
	    cin>>r;
	    instructions3();
	    cout<<"Are you ready to begin the test?\n";
	    r='X';
	    do
	    {
	       cout<<"Enter Y to begin testing,N to quit\n";
	       cin>>r;
	       toupper(r);
	       if(r=='Y')
	       test_procedure3(temp,t);
	       else if(r=='N')
	       break;
	       else
	       {
		  cout<<"Invalid,re-enter response:";
		  cin>>r;
	       }
	    }while(r!='Y');
	    }
	    else cout<<"Wrong credentials";
	 }
      }
   }
}

void add_qp1(qp1 p1)
{
   fstream fout("QP1.dat",ios::binary|ios::out|ios::ate);
   if(!fout)	{	cout<<"FNF";	return;	}
   strcpy(MVM.qp1_testname[MVM.n_qp1],p1.testname);
   fout.write((char*)&p1,sizeof(p1));
   fout.close();
   MVM.n_qp1++;
}
void add_qp2(qp2 p2)
{
   fstream fout("QP2.dat",ios::binary|ios::out|ios::ate);
   if(!fout)	{	cout<<"FNF";	return;	}
   strcpy(MVM.qp2_testname[MVM.n_qp2],p2.testname);
   fout.write((char*)&p2,sizeof(p2));
   fout.close();
   MVM.n_qp2++;
}
void add_qp3(qp3 p3)
{
   fstream fout("QP3.dat",ios::binary|ios::out|ios::ate);
   if(!fout)	{	cout<<"FNF";	return;	}
   strcpy(MVM.qp3_testname[MVM.n_qp3],p3.testname);
   fout.write((char*)&p3,sizeof(p3));
   fout.close();
   MVM.n_qp3++;
}

fstream inst;				//file for institute

void get_institute()                         //to get mvm from file
{
   inst.read((char*)&MVM,sizeof(MVM));

}
void put_institute()                     //to put mvm back in file at the end
{
	inst.seekg(0,ios::cur);
	inst.write((char*)&MVM,sizeof(MVM));
}


//MAIN FUNCTION Begins
void main()
{
   clrscr();
   inst.open("institute.dat",ios::binary|ios::in|ios::out|ios::ate);
   ad.open("admin.dat",ios::binary|ios::in|ios::out|ios::ate);
   get_admin();
   get_institute();
   cout<<"Welcome!\n";
   char rep='y';
   while(rep=='y')
   {
   cout<<"Admin(A) or Student(S)?:";
   char ch;
   int n;
   cin>>ch;
   char user[10],pass[20];
   if(ch=='A')
   {
      cout<<"Enter UserID:";
      gets(user);
      cout<<"Enter Password:";
      gets(pass);
      if(strcmpi(GG.userid,user)==0 && strcmp(pass,GG.password)==0)          //admin not in file?where is username password stored?
      {
	 cout<<"Admin successfully logged in\n";
	 cout<<"Choose:\n1.Create Papers\n2.Start test for student\n3.Add new student\n4.View student details\n5.Modify student details\n6.Check student requests\n7.View student test analysis\n8.Logout\n9.change password";
	 cin>>n;
	 while(n!=8)
	 {
	    if(n==1)
	    {
	       cout<<"Enter paper type(1/2/3):";
	       int m;
	       cin>>m;
	       if(m==1)
	       {
		  p1.qp1_c();
		  add_qp1(p1);
	       }
	       else if(m==2)
	       {
		  p2.qp2_c();
		  add_qp2(p2);
	       }
	       else if(m==3)
	       {
		  p3.qp3_c();
		  add_qp3(p3);
	       }
	       else
	       cout<<"Invalid QP type,try again!\n";
	    }
	    else if(n==2)
	    start_procedure();
	    else if(n==3)
	    {
	       cout<<"Enter new student details:\n";
	       student stu;
	       stu.stu_create();
	       cout<<"New student added. Uploading student details...\n";
	       upload_newstu_details(stu);
	       cout<<"Stu details uploaded\n";
	    }
	    else if(n==4)
	    {
	       cout<<"Enter ID of student:";
	       char id[10];
	       gets(id);
	       int flag=0;
	       fstream fin("Student.dat",ios::binary|ios::in|ios::ate);
	       if(!fin)
	       cout<<"FNF!";
	       else
	       {
		  student stu;
		  while(fin.read((char*)&stu,sizeof(stu)))
		  {
		     if(strcmpi(stu.ret_id(),id)==0)
		     {
			flag++;
			break;
		     }
		  }
		  fin.close();
		  if(flag==0)
		  cout<<"Student not found!\n";
		  else
		  stu.stu_display();
	       }
	    }
	    else if(n==5)
	    {
	       cout<<"Enter ID of student:";
	       char id[10];
	       gets(id);
	       int flag=0;
	       fstream fin("Student.dat",ios::binary|ios::in|ios::ate);
	       if(!fin)
	       cout<<"FNF!";
	       else
	       {
		  student stu;
		  while(fin.read((char*)&stu,sizeof(stu)))
		  {
		     if(strcmpi(stu.ret_id(),id)==0)
		     {
			flag++;
			break;
		     }
		  }
		  fin.close();
		  if(flag==0)
		  cout<<"Student not found!\n";
		  else
		  {
		     stu.stu_edit();
		     cout<<"Details edited.Saving changes...\n";
		     modify_stu_details(stu);
		     cout<<"Changes saved!\n";
		  }
	       }
	    }
	    else if(n==6)
	    {   char c;student stu;
		fstream fin("student.dat",ios::binary|ios::in|ios::ate);
		if(!fin)
		cout<<"fnf";
		else
		{
			while(fin.read((char*)&stu,sizeof(stu)))
			{
				if (!strcmp(stu.request,"x")==0)
				clrscr();
				stu.stu_display();
				cout<<"\nthe above student has a request\n";
				puts(stu.request);
				cout<<"are you done with this request? enter v to make void.enter any key to go to next";
				cin>>c;
				if (c=='v')
				{
					strcpy(stu.request,"x");
					fin.seekg(-(int*)sizeof(stu),ios::cur);
					fin.write((char*)&stu,sizeof(stu));
				}
			}
		}
	    fin.close();

	    }
	    else if(n==7)
	    {
	       cout<<"Enter ID of student:";
	       char id[10];
	       gets(id);
	       int fl=0;
	       student t;
	       fstream fin("Student.dat",ios::binary|ios::in|ios::ate);
	       if(!fin)
	       cout<<"FNF!";
	       else
	       {
		  student stu;                                 //why stu present? logical error?!!
		  while(fin.read((char*)&t,sizeof(t)))
		  {
		     if(strcmpi(stu.ret_id(),id)==0)
		     {
			fl++;
			break;
		     }
		  }
		  fin.close();
		  if(fl==0)
		  cout<<"Student not found!\n";
		  else
		  {
		     cout<<"Enter test type:";
		     int ty,flag=0;
		     char qpname[20];
		     cin>>ty;
		     if(ty==1)
		     {
			cout<<"Enter test name:";
			gets(qpname);
			int i;
			for(i=0;i<t.count1;i++)
			{

			   if(strcmpi(t.test1[i].ob1.testname,qpname)==0)
			   {
			      flag++;
			      test_analysis1(t.test1[i].ob1,t);
			      break;
			   }
			}
			if(flag==0)
			cout<<"QP not found!";
		     }
		     else if(ty==2)
		     {
			cout<<"Enter test name:";
			gets(qpname);
			int i;
			for(i=0;i<t.count2;i++)
			{

			   if(strcmpi(t.test2[i].ob2.testname,qpname)==0)
			   {
			      flag++;
			      test_analysis2(t.test2[i].ob2,t);
			      break;
			   }
			}
			if(flag==0)
			cout<<"QP not found!";
		     }
		     else if(ty==3)
		     {
			cout<<"Enter test name:";
			gets(qpname);
			int i;
			for(i=0;i<t.count3;i++)
			{

			   if(strcmpi(t.test3[i].ob3.testname,qpname)==0)
			   {
			      flag++;
			      test_analysis3(t.test3[i].ob3,t);
			      break;
			   }
			}
			if(flag==0)
			cout<<"QP not found!";
		     }
		     else cout<<"Invalid QP type!";
		  }
	       }
	    }
	    else if(n==9)
	    {
		char user1[10];char password1[20];
		cout<<"enter new userid: ";
		gets(user1);
		cout<<"enter new password: ";
		gets(password1);
		strcpy(GG.userid,user1);
		strcpy(GG.password,password1);
		cout<<"changes accepted";
	    }
	    else if(n!=8)
	    cout<<"Invalid choice";
	    cout<<"Choose:\n1.Create Papers\n2.Start test for student\n3.Add new student\n4.View student details\n5.Modify student details\n6.Check student requests\n7.View student test analysis\n8.Logout";
	    cin>>n;
	 }
      }
      else
      cout<<"Invalid login credentials!";
   }
   else if(ch=='S')
   {
      cout<<"Enter username:";
      gets(user);
      cout<<"Enter password:";
      gets(pass);
      fstream fin("Student.dat",ios::binary|ios::in|ios::ate);
      if(!fin)
      cout<<"FNF!";
      else
      {
	 student t;
	 int flag=0;
	 while(fin.read((char*)&t,sizeof(t)))
	 {
	    if(strcmpi(t.ret_id(),user)==0 && strcmp(t.ret_pass(),pass)==0)
	    {
		flag++;
		break;
	    }
	 }
	 fin.close();
	 if(flag==0)
	 cout<<"Entered credentials are wrong!";
	 else
	 {
	    cout<<"Congrats!You've logged in successfully!";
	    cout<<"Choose:\n1.Display profile\n2.Edit profile\n3.Request Admin for test\n4.View Test Analysis\n5.Logout";
	    cin>>n;
	    while(n!=5)
	    {
		  if(n==1)
		  t.stu_display();
		  else if(n==2)
		  {
		     t.stu_edit();
		     cout<<"Details edited.Saving changes...\n";
		     modify_stu_details(t);
		     cout<<"Changes saved!\n";
		  }
		  else if(n==3)                                     //request func
		  {	cout<<"enter request: ";
			char req[30];
			strcpy(t.request,req);
			cout<<"request noted. saving on server....\n";
			modify_stu_details(t);
			cout<<"changes saved!\n";
		  }
		  else if(n==4)
		  {
		     cout<<"Enter test type:";
		     int ty,flag=0;
		     char qpname[20];
		     cin>>ty;
		     if(ty==1)
		     {
			cout<<"Enter test name:";
			gets(qpname);
			int i;
			for(i=0;i<t.count1;i++)
			{

			   if(strcmpi(t.test1[i].ob1.testname,qpname)==0)
			   {
			      flag++;
			      test_analysis1(t.test1[i].ob1,t);
			      break;
			   }
			}
			if(flag==0)
			cout<<"QP not found!";
		     }
		     else if(ty==2)
		     {
			cout<<"Enter test name:";
			gets(qpname);
			int i;
			for(i=0;i<t.count2;i++)
			{

			   if(strcmpi(t.test2[i].ob2.testname,qpname)==0)
			   {
			      flag++;
			      test_analysis2(t.test2[i].ob2,t);
			      break;
			   }
			}
			if(flag==0)
			cout<<"QP not found!";
		     }
		     else if(ty==3)
		     {
			cout<<"Enter test name:";
			gets(qpname);
			int i;
			for(i=0;i<t.count3;i++)
			{

			   if(strcmpi(t.test3[i].ob3.testname,qpname)==0)
			   {
			      flag++;
			      test_analysis3(t.test3[i].ob3,t);
			      break;
			   }
			}
			if(flag==0)
			cout<<"QP not found!";
		     }
		     else cout<<"Invalid QP type!";
		  }
		  else if(n!=5)
		  cout<<"Invalid";
		  cout<<"Choose:\n1.Display profile\n2.Edit profile\n3.Request Admin for test\n4.View Test Analysis\n5.Logout";
		  cin>>n;
	    }
	 }
      }
   }
   }
   getch();
   put_institute();
   put_admin();
   ad.close();
   inst.close();
}
