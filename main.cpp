/*Project - Practice Test Module
Team Members: Abhinav Sen
	      Aditya C
	      Akhil B
	      Keshav Krishna M B  */

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

class scq                   //Class SCQ begins here
{
    char qn[200],opa[50],opb[50],opc[50],opd[50],ans;
public:
    void scq_c()
    {
        gets(qn);
        cout<<"Enter Option A:";
        gets(opa);
        cout<<"Enter Option B:";
        gets(opb);
        cout<<"Enter Option C:";
        gets(opc);
        cout<<"Enter Option D:";
        gets(opd);
        cout<<"Enter Answer:";
        cin>>ans;
    }
    void scq_display()
    {
        puts(qn);
        cout<<"\n";
        cout<<"A) ";
        puts(opa);
        cout<<"B) ";
        puts(opb);
        cout<<"C) ";
        puts(opc);
        cout<<"D) ";
        puts(opd);
    }
    char scq_retans()
    {
        return ans;
    }
    int scq_anscheck(char &response)
    {
        int mark=0;
        response=toupper(response);
        if(ans==response)
            mark=3;
        else if(response=='X')
            mark=0;
        else mark=-1;
        return mark;
    }
    void scq_analysis(char &response)
    {
        scq_display();
        cout<<"\nCorrect Answer:"<<ans<<endl;
        cout<<"Your Answer:"<<response<<endl;
        cout<<"Marks Scored:"<<scq_anscheck(response)<<endl;
    }
};                //Class SCQ ends here

class numerical      //Class NUMERICAL begins here
{
    char qn[250];
    double ans;
public:
    void numerical_c()
    {
        gets(qn);
        cout<<"Enter Answer:";
        cin>>ans;
    }
    void numerical_display()
    {
        puts(qn);
        cout<<endl;
    }
    double numerical_retans()
    {
        return ans;
    }
    int numerical_anscheck(double response)
    {
        int mark;
        if(response==-1) mark=0;
        else if(response>=0.98*ans && response<=1.02*ans)
            mark=3;
        else mark=0;
        return mark;
    }
    void numerical_analysis(double response)
    {
        numerical_display();
        cout<<"\nCorrect Answer:"<<ans<<endl;
        cout<<"Your Answer:"<<response<<endl;
        cout<<"Marks Scored:"<<numerical_anscheck(response)<<endl;
    }
};		//Class NUMERICAL ends here

//Functions ALPHASORT & FINDCHAR begin here
int findchar(char str[5],char &a)
{
    for(int i=0; i<strlen(str); i++)
    {
        if(str[i]==a)
            return 1;
    }
    return 0;
}
void alphasort(char a[5])
{
    char temp;
    for(int i=0; i<strlen(a); i++)
        for(int j=0; j<strlen(a)-1-i; j++)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
}	//Functions ALPHASORT and FINDCHAR end here

class mcq            //Class MCQ begins here
{
    char qn[200],opa[50],opb[50],opc[50],opd[50],ans[5];
public:
    void mcq_c()
    {
        gets(qn);
        cout<<"Enter Option A:";
        gets(opa);
        cout<<"Enter Option B:";
        gets(opb);
        cout<<"Enter Option C:";
        gets(opc);
        cout<<"Enter Option D:";
        gets(opd);
        cout<<"Enter Answer:";
        cin>>ans;
        strupr(ans);
        alphasort(ans);
    }
    void mcq_display()
    {
        puts(qn);
        cout<<"\n";
        cout<<"A) ";
        puts(opa);
        cout<<"B) ";
        puts(opb);
        cout<<"C) ";
        puts(opc);
        cout<<"D) ";
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
        cout<<"\nCorrect Answer:"<<ans<<endl;
        cout<<"Your Answer:"<<response<<endl;
        cout<<"Marks Scored:"<<mcq_anscheck(response)<<endl;
    }
};
int mcq::mcq_anscheck(char response[5])
{
    strupr(response);
    alphasort(response);
    int mark=0;
    if(strlen(ans)<strlen(response))
        mark=-1;
    else if(strcmpi(ans,response)==0)
        mark=4;
    else
    {
        mark=0;
        for(char i='A'; i<'E'; i++)
        {
            if(findchar(ans,i)==1 && findchar(response,i)==1)
                mark++;
            else if(findchar(ans,i)==0 && findchar(response,i)==1)
            {
                mark=-1;
                break;
            }
        }
    }
    return mark;
}			//Class MCQ ends here

class matrix            //Class MATRIX begins here
{
    char a[50],b[50],c[50],d[50],p[30],q[30],r[30],s[30];
public:
    char ans[4][5];
    void matrix_c();
    void matrix_display();
    int matrix_anscheck(char response[4][5]);
    void matrix_analysis(char response[4][5]);
};
void matrix::matrix_c()
{
    cout<<"Enter Qn A:";
    gets(a);
    cout<<"Enter Qn B:";
    gets(b);
    cout<<"Enter Qn C:";
    gets(c);
    cout<<"Enter Qn D:";
    gets(d);
    cout<<"Enter Option P:";
    gets(p);
    cout<<"Enter Option Q:";
    gets(q);
    cout<<"Enter Option R:";
    gets(r);
    cout<<"Enter Option S:";
    gets(s);
    for(int j=0; j<4; j++)
    {
        cout<<"Enter Answer for Qn "<<char(j+65)<<":";
        gets(ans[j]);
        strupr(ans[j]);
        alphasort(ans[j]);
    }
}
void matrix::matrix_display()
{
    int i;
    cout<<"A] "<<a;
    for(i=0; i<(45-strlen(a)); i++)
        cout<<" ";
    cout<<"\tP)"<<p<<"\n\n";
    cout<<"B] "<<b;
    for(i=0; i<(45-strlen(b)); i++)
        cout<<" ";
    cout<<"\tQ)"<<q<<"\n\n";
    cout<<"C] "<<c;
    for(i=0; i<(45-strlen(c)); i++)
        cout<<" ";
    cout<<"\tR)"<<r<<"\n\n";
    cout<<"D] "<<d;
    for(i=0; i<(45-strlen(d)); i++)
        cout<<" ";
    cout<<"\tS)"<<s<<"\n\n";
}
int matrix::matrix_anscheck(char response[4][5])
{
    int mark=0,i;
    for(i=0; i<4; i++)
    {
        strupr(response[i]);
        alphasort(response[i]);
    }
    for(i=0; i<4; i++)
    {
        if(strcmpi(ans[i],response[i])==0)
            mark+=2;
        else if(strcmpi(response[i],"X")!=0)
            mark-=1;
    }
    return mark;
}
void matrix::matrix_analysis(char response[4][5])
{
    matrix_display();
    cout<<"\nCorrect Answer:";
    for(int i=0; i<4; i++)
        cout<<ans[i]<<";";
    cout<<endl;
    cout<<"Your Answer:";
    for(int j=0; j<4; j++)
        cout<<response[j]<<";";
    cout<<endl;
    cout<<"Marks Scored:"<<matrix_anscheck(response)<<endl;
}		//Class MATRIX ends here

//class INSTITUTE_DETAILS begins here
class institute_details
{
public:
    int n_stu,n_qp1,n_qp2,n_qp3;
    char qp1_testname[20][20],qp2_testname[20][20],qp3_testname[20][20];
} MVM;
//struct INSTITUTE_DETAILS ends here

class qp1       //Class QP1 starts here
{
public:
    char testname[30];
    scq a[20];
    numerical b[5];
    void qp1_c();
    void qp1_result(char[],double[]);
    void qp1_report(char[],double[]);
} p1;
void qp1::qp1_c()
{
    int i;
    cout<<"Enter TestName:";
    gets(testname);
    cout<<"SCQ:\n";
    for(i=0; i<20; i++)
    {
        cout<<"Enter Question "<<i+1<<":";
        a[i].scq_c();
        cout<<endl;
    }
    cout<<"Numerical:\n";
    for(i=0; i<5; i++)
    {
        cout<<"Enter Question "<<i+21<<":";
        b[i].numerical_c();
        cout<<"\n";
    }
    cout<<"\nQP "<<testname<<" created.";
}
void qp1::qp1_result(char scq_res[],double num_res[])
{
    int i;
    int scq_score=0,numerical_score=0;
    int scq_correct=0,numerical_correct=0;
    int scq_wrong=0,numerical_wrong=0;
    int scq_left=0,numerical_left=0;
    for(i=0; i<20; i++)
    {
        if(a[i].scq_anscheck(scq_res[i])==3)
        {
            scq_score+=3;
            scq_correct++;
        }
        else if(a[i].scq_anscheck(scq_res[i])==-1)
        {
            scq_wrong++;
            scq_score-=1;
        }
        else
            scq_left++;
    }
    for(i=0; i<5; i++)
    {
        if(b[i].numerical_anscheck(num_res[i])==3)
        {
            numerical_score+=3;
            numerical_correct++;
        }
        else if(num_res[i]==-1)
            numerical_left++;
        else
            numerical_wrong++;
    }
    cout<<"Q_Type\t\tQns_Correct\tQns_Wrong\tQns_Left\tMarks\n";
    cout<<"SCQ\t\t"<<scq_correct<<"\t\t"<<scq_wrong<<"\t\t"<<scq_left<<"\t\t"<<scq_score<<endl;
    cout<<"Numerical\t"<<numerical_correct<<"\t\t"<<numerical_wrong<<"\t\t"<<numerical_left<<"\t\t"<<numerical_score<<endl;
    cout<<"Total\t\t"<<scq_correct+numerical_correct<<"\t\t"<<scq_wrong+numerical_wrong<<"\t\t"<<scq_left+numerical_left<<"\t\t"<<scq_score+numerical_score<<endl;
    cout<<"\nMax_Total=75";
}
void qp1::qp1_report(char scq_res[],double num_res[])
{
    int i;
    int scq_tot=0,numerical_tot=0,grand_total=0;
    cout<<"Test Report:\nQ.No\tQ_Type\tCorrect Answer\tResponse\tMarks"<<endl;
    for(i=0; i<20; i++)
    {
        cout<<i+1<<"\t"<<"SCQ\t"<<a[i].scq_retans()<<"\t\t"<<scq_res[i]<<"\t\t"<<a[i].scq_anscheck(scq_res[i])<<endl;
        scq_tot+=a[i].scq_anscheck(scq_res[i]);
    }
    cout<<"\n\nEnter any key to continue:";
    getch();
    cout<<"\n\nQ.No\tQ_Type\tCorrect Answer\tResponse\tMarks"<<endl;
    for(i=0; i<5; i++)
    {
        cout<<i+21<<"\t"<<"Numerical\t"<<b[i].numerical_retans()<<"\t"<<num_res[i]<<"\t\t"<<b[i].numerical_anscheck(num_res[i])<<endl;
        numerical_tot+=b[i].numerical_anscheck(num_res[i]);
    }
    cout<<"\nEnter any key to continue:\n\n";
    getch();
    cout<<endl;
    grand_total=numerical_tot+scq_tot;
    cout<<"Q_Type\t\tYour Marks\tMax marks"<<endl;
    cout<<"SCQ\t\t"<<scq_tot<<"\t\t"<<60<<endl;
    cout<<"Numerical\t"<<numerical_tot<<"\t\t"<<15<<endl;
    cout<<"Total\t\t"<<grand_total<<"\t\t"<<75<<endl;
}
//Class QP1 ends here

//Class QP2 begins here
class qp2
{
public:
    char testname[30];
    scq a[4];
    mcq c[8];
    numerical b[8];
    void qp2_c();
    void qp2_result(char scq_res[],char mcq_res[][5],double num_res[]);
    void qp2_report(char scq_res[],char mcq_res[][5],double num_res[]);
} p2;
void qp2::qp2_c()
{
    int i;
    cout<<"Enter TestName:";
    gets(testname);
    cout<<"SCQ:\n";
    for(i=0; i<4; i++)
    {
        cout<<"Enter Question "<<i+1<<":";
        a[i].scq_c();
        cout<<endl;
    }
    cout<<"MCQ:\n";
    for(i=0; i<8; i++)
    {
        cout<<"Enter Question "<<i+5<<":";
        c[i].mcq_c();
        cout<<"\n";
    }
    cout<<"Numerical:\n";
    for(i=0; i<8; i++)
    {
        cout<<"Enter Question "<<i+13<<":";
        b[i].numerical_c();
        cout<<"\n";
    }
    cout<<"\nQP "<<testname<<" created.";
}
void qp2::qp2_result(char scq_res[],char mcq_res[][5],double num_res[])
{
    int i;
    int scq_score=0,mcq_score=0,numerical_score=0;
    int scq_correct=0,mcq_correct=0,numerical_correct=0;
    int scq_wrong=0,mcq_wrong=0,numerical_wrong=0;
    int scq_left=0,mcq_left=0,numerical_left=0;
    int mcq_partial=0;
    for(i=0; i<4; i++)
    {
        if(a[i].scq_anscheck(scq_res[i])==3)
        {
            scq_score+=3;
            scq_correct++;
        }
        else if(a[i].scq_anscheck(scq_res[i])==-1)
        {
            scq_wrong++;
            scq_score-=1;
        }
        else
            scq_left++;
    }
    for(i=0; i<8; i++)
    {
        if(c[i].mcq_anscheck(mcq_res[i])==4)
        {
            mcq_score+=4;
            mcq_correct++;
        }
        else if(c[i].mcq_anscheck(mcq_res[i])==-1)
        {
            mcq_wrong++;
            mcq_score-=1;
        }
        else if(c[i].mcq_anscheck(mcq_res[i])==0)
            mcq_left++;
        else
        {
            mcq_score+=c[i].mcq_anscheck(mcq_res[i]);
            mcq_partial++;
        }
    }
    for(i=0; i<8; i++)
    {
        if(b[i].numerical_anscheck(num_res[i])==3)
        {
            numerical_score+=3;
            numerical_correct++;
        }
        else if(num_res[i]==-1)
            numerical_left++;
        else
            numerical_wrong++;
    }
    cout<<"Q_Type\tQns_Correct\tQns_Partial\tQns_Wrong\tQns_Left\tMarks\n";
    cout<<"SCQ\t\t"<<scq_correct<<"\t-\t\t"<<scq_wrong<<"\t\t"<<scq_left<<"\t\t"<<scq_score<<endl;
    cout<<"MCQ\t\t"<<mcq_correct<<"\t"<<mcq_partial<<"\t\t"<<mcq_wrong<<"\t\t"<<mcq_left<<"\t\t"<<mcq_score<<endl;
    cout<<"Numerical\t"<<numerical_correct<<"\t-\t\t"<<numerical_wrong<<"\t\t"<<numerical_left<<"\t\t"<<numerical_score<<endl;
    cout<<"Total\t\t"<<scq_correct+mcq_correct+numerical_correct<<"\t"<<mcq_partial<<"\t\t"<<scq_wrong+mcq_wrong+numerical_wrong<<"\t\t"<<scq_left+mcq_left+numerical_left<<"\t\t"<<scq_score+numerical_score+mcq_score<<endl;
}
void qp2::qp2_report(char scq_res[],char mcq_res[][5],double num_res[])
{
    int i;
    int scq_tot=0,mcq_tot=0,numerical_tot=0,grand_total=0;
    cout<<"Test Report:\nQ.No\tQ_Type\tCorrect Answer\tResponse\tMarks"<<endl;
    for(i=0; i<4; i++)
    {
        cout<<i<<"\t"<<"SCQ\t"<<a[i].scq_retans()<<"\t\t"<<scq_res[i]<<"\t\t"<<a[i].scq_anscheck(scq_res[i])<<endl;
        scq_tot+=a[i].scq_anscheck(scq_res[i]);
    }
    for(i=0; i<8; i++)
    {
        cout<<i+5<<"\t"<<"MCQ\t"<<c[i].mcq_retans()<<"\t\t"<<mcq_res[i]<<"\t\t"<<c[i].mcq_anscheck(mcq_res[i])<<endl;
        mcq_tot+=c[i].mcq_anscheck(mcq_res[i]);
    }
    for(i=0; i<8; i++)
    {
        cout<<i+13<<"\t"<<"Numerical"<<b[i].numerical_retans()<<"\t\t"<<num_res[i]<<"\t\t"<<b[i].numerical_anscheck(num_res[i])<<endl;
        numerical_tot+=b[i].numerical_anscheck(num_res[i]);
    }
    cout<<"Enter any key to continue:";
    getch();
    cout<<endl;
    grand_total=numerical_tot+scq_tot+mcq_tot;
    cout<<"Q_Type\tYour Marks\tMax marks"<<endl;
    cout<<"SCQ\t\t"<<scq_tot<<"\t"<<12<<endl;
    cout<<"MCQ\t\t"<<mcq_tot<<"\t"<<32<<endl;
    cout<<"Numerical\t"<<numerical_tot<<"\t"<<24<<endl;
    cout<<"Total\t\t"<<grand_total<<"\t"<<68<<endl;
}
//Class QP2 ends here

//Class QP3 begins here
class qp3
{
public:
    char testname[30];
    scq a[8];
    mcq c[5];
    numerical b[4];
    matrix d[3];
    void qp3_c();
    void qp3_report(char scq_res[8],char mcq_res[5][5],double num_res[4],char matrix_res[3][4][5]);
    void qp3_result(char scq_res[8],char mcq_res[5][5],double num_res[4],char matrix_res[3][4][5]);
} p3;
void qp3::qp3_c()
{
    int i;
    cout<<"Enter TestName:";
    gets(testname);
    cout<<"SCQ:\n";
    for(i=0; i<8; i++)
    {
        cout<<"Enter Question "<<i+1<<":";
        a[i].scq_c();
        cout<<endl;
    }
    cout<<"MCQ:\n";
    for(i=0; i<5; i++)
    {
        cout<<"Enter Question "<<i+9<<" ";
        c[i].mcq_c();
        cout<<endl;
    }
    cout<<"Numericals:\n";
    for(i=0; i<4; i++)
    {
        cout<<"Enter Question "<<i+14<<":";
        b[i].numerical_c();
        cout<<endl;
    }
    cout<<"Matrix:\n";
    for(i=0; i<3; i++)
    {
        cout<<"Enter Question "<<i+18<<" ";
        d[i].matrix_c();
        cout<<endl;
    }
    cout<<"\nQP "<<testname<<" created.";
}
void qp3::qp3_result(char scq_res[8],char mcq_res[5][5],double num_res[4],char matrix_res[3][4][5])
{
    int i;
    int matrix_score=0,mcq_score=0,numerical_score=0,scq_score=0;
    int matrix_correct=0,mcq_correct=0,numerical_correct=0,scq_correct=0;
    int matrix_wrong=0,mcq_wrong=0,numerical_wrong=0,scq_wrong=0;
    int matrix_left=0,mcq_left=0,numerical_left=0,scq_left=0;
    int matrix_partial=0,mcq_partial=0;
    for(i=0; i<8; i++)
    {
        if(a[i].scq_anscheck(scq_res[i])==3)
        {
            scq_score+=3;
            scq_correct++;
        }
        else if(a[i].scq_anscheck(scq_res[i])==-1)
        {
            scq_wrong++;
            scq_score-=1;
        }
        else
            scq_left++;
    }
    for(i=0; i<5; i++)
    {
        if(c[i].mcq_anscheck(mcq_res[i])==4)
        {
            mcq_score+=4;
            mcq_correct++;
        }
        else if(c[i].mcq_anscheck(mcq_res[i])==-1)
        {
            mcq_wrong++;
            mcq_score-=1;
        }
        else if(c[i].mcq_anscheck(mcq_res[i])==-0)
            mcq_left++;
        else
        {
            mcq_score+=c[i].mcq_anscheck(mcq_res[i]);
            mcq_partial++;
        }
    }
    for(i=0; i<4; i++)
    {
        if(b[i].numerical_anscheck(num_res[i])==3)
        {
            numerical_score+=3;
            numerical_correct++;
        }
        else if(num_res[i]==-1)
            numerical_left++;
        else
            numerical_wrong++;
    }
    for(i=0; i<3; i++)
    {
        if(d[i].matrix_anscheck(matrix_res[i])==8)
        {
            matrix_correct++;
            matrix_score+=8;
        }
        else if(d[i].matrix_anscheck(matrix_res[i])>0)
        {
            matrix_partial++;
            matrix_score+=d[i].matrix_anscheck(matrix_res[i]);
        }
        else if(d[i].matrix_anscheck(matrix_res[i])==0 && !((strcmpi(matrix_res[i][0],"X")==0) && (strcmpi(matrix_res[i][1],"X")==0)))
            matrix_partial++;
        else if(d[i].matrix_anscheck(matrix_res[i])==0)
            matrix_left++;
        else
        {
            matrix_wrong++;
            matrix_score+=d[i].matrix_anscheck(matrix_res[i]);
        }
    }
    cout<<"Q_Type\tQns_Correct\tQns_Partial\tQns_Wrong\tQns_Left\tMarks\n";
    cout<<"SCQ\t\t"<<scq_correct<<"\t\t-\t"<<scq_wrong<<"\t\t"<<scq_left<<"\t\t"<<scq_score<<endl;
    cout<<"MCQ\t\t"<<mcq_correct<<"\t\t"<<mcq_partial<<"\t"<<mcq_wrong<<"\t\t"<<mcq_left<<"\t\t"<<mcq_score<<endl;
    cout<<"Numerical\t"<<numerical_correct<<"\t\t-\t"<<numerical_wrong<<"\t\t"<<numerical_left<<"\t\t"<<numerical_score<<endl;
    cout<<"Matrix\t\t"<<matrix_correct<<"\t\t"<<matrix_partial<<"\t"<<matrix_wrong<<"\t\t"<<matrix_left<<"\t\t"<<matrix_score<<endl;
    cout<<"Total\t\t"<<matrix_correct+mcq_correct+numerical_correct+scq_correct<<"\t\t"<<matrix_partial+mcq_partial<<"\t"<<matrix_wrong+mcq_wrong+numerical_wrong+scq_wrong<<"\t\t"<<matrix_left+mcq_left+numerical_left+scq_left<<"\t\t"<<matrix_score+numerical_score+mcq_score+scq_score<<endl;
}
void qp3::qp3_report(char scq_res[8],char mcq_res[5][5],double num_res[4],char matrix_res[3][4][5])
{
    int i;
    int scq_tot=0,matrix_tot=0,mcq_tot=0,numerical_tot=0,grand_total=0;
    cout<<"Test Report:\nQ.No\tQ_Type\t\tCorrect Answer\t\tResponse\t\tMarks"<<endl;
    for(i=0; i<8; i++)
    {
        cout<<i+1<<"\t"<<"SCQ\t\t"<<a[i].scq_retans()<<"\t\t\t"<<scq_res[i]<<"\t\t\t"<<a[i].scq_anscheck(scq_res[i])<<endl;
        scq_tot+=a[i].scq_anscheck(scq_res[i]);
    }
    for(i=0; i<5; i++)
    {
        cout<<i+9<<"\t"<<"MCQ\t\t"<<c[i].mcq_retans()<<"\t\t\t"<<mcq_res[i]<<"\t\t\t"<<c[i].mcq_anscheck(mcq_res[i])<<endl;
        mcq_tot+=c[i].mcq_anscheck(mcq_res[i]);
    }
    for(i=0; i<4; i++)
    {
        cout<<i+14<<"\t"<<"Numerical\t"<<b[i].numerical_retans()<<"\t\t\t"<<num_res[i]<<"\t\t\t"<<b[i].numerical_anscheck(num_res[i])<<endl;
        numerical_tot+=b[i].numerical_anscheck(num_res[i]);
    }
    for(i=0; i<3; i++)
    {
        cout<<i+18<<"\t"<<"Matrix\t\t";
        for(int j=0; j<4; j++)
            cout<<d[i].ans[j]<<";";
        cout<<"\t\t";
        for(int k=0; k<4; k++)
            cout<<matrix_res[i][k]<<";";
        cout<<"\t\t"<<d[i].matrix_anscheck(matrix_res[i])<<endl;
        matrix_tot+=d[i].matrix_anscheck(matrix_res[i]);
    }
    cout<<"Enter any key to continue:";
    getch();
    cout<<endl;
    grand_total=scq_tot+numerical_tot+matrix_tot+mcq_tot;
    cout<<"\n\nQ_Type\t\tYour Marks\tMax marks"<<endl;
    cout<<"SCQ\t\t"<<scq_tot<<"\t\t"<<24<<endl;
    cout<<"MCQ\t\t"<<mcq_tot<<"\t\t"<<20<<endl;
    cout<<"Numerical\t"<<numerical_tot<<"\t\t"<<12<<endl;
    cout<<"Matrix_Matching\t"<<matrix_tot<<"\t\t"<<24<<endl;
    cout<<"Total\t\t"<<grand_total<<"\t\t"<<80<<"\n\n";
}
//Class QP3 ends here

class type1                   //Class type1 begins here
{
public:
    char scq_res[21];
    double num_res[5];
    char qpname[30];
    type1();
};
type1::type1()
{
    int i;
    for(i=0; i<20; i++)
        scq_res[i]='X';
    for(i=0; i<5; i++)
        num_res[i]=-1;
}		//Class type1 ends here

class type2     //Class type2 begins here
{
public:
    char scq_res[5];
    char mcq_res[8][5];
    double num_res[8];
    char qpname[30];
    type2();
};
type2::type2()
{
    int i;
    for(i=0; i<4; i++)
        scq_res[i]='X';
    for(i=0; i<8; i++)
        strcpy(mcq_res[i],"X");
    for(i=0; i<8; i++)
        num_res[i]=-1;
}
//Class type2 ends here


//Class type3 begins here
class type3
{
public:
    char scq_res[9];
    char mcq_res[5][5];
    double num_res[4];
    char matrix_res[3][4][5];
    char qpname[30];
    type3();
};
type3::type3()
{
    int i;
    for(i=0; i<8; i++)
        scq_res[i]='X';
    for(i=0; i<5; i++)
        strcpy(mcq_res[i],"X");
    for(i=0; i<4; i++)
        num_res[i]=-1;
    for(i=0; i<3; i++)
        for(int j=0; j<4; j++)
            strcpy(matrix_res[i][j],"X");
}
//Class type3 ends here

//Class STUDENT begins here
class student
{
    char name[30],id[20],password[20];
    int std;
    char section;
public:
    type1 test1[10];
    int count1;
    type2 test2[10];
    int count2;
    type3 test3[10];
    int count3;
    char request[50];
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
        strcpy(request,"X");
        count1=count2=count3=0;
    }
    void stu_display();
    void stu_edit()
    {
        cout<<"CURRENT DETAILS:\n";
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
            else
                cout<<"Invalid password!";
        }
    }
    char* ret_id()
    {
        return id;
    }
    char* ret_name()
    {
        return name;
    }
    char* ret_pass()
    {
        return password;
    }
} t,stu;
void student::stu_display()
{
    cout<<"Student name:";
    puts(name);
    cout<<"ID:";
    puts(id);
    cout<<"Std:"<<std<<endl;
    cout<<"Section:"<<section<<endl;
    cout<<"\nQPs of type 1 attempted:\n";
    int i;
    for(i=0; i<count1; i++)
        cout<<i+1<<"]"<<test1[i].qpname<<endl;
    cout<<"\nQPs of type 2 attempted:\n";
    for(i=0; i<count2; i++)
        cout<<i+1<<"]"<<test2[i].qpname<<endl;
    cout<<"\nQPs of type 3 attempted:\n";
    for(i=0; i<count3; i++)
        cout<<i+1<<"]"<<test3[i].qpname<<endl;
}
//Class STUDENT ends here

//UDF to upload newstu_details onto binary file
fstream fstu,f1,f2,f3;
void upload_newstu_details(student &a)
{
    fstu.open("Student.dat",ios::binary|ios::out|ios::ate|ios::app);
    if(!fstu)
    {
        cout<<"FNF!";
        return;
    }
    MVM.n_stu++;
    fstu.write((char*)&a,sizeof(a));
    fstu.close();
}		//End of UDF

class admin       //class ADMIN begins here
{
public:
    char userid[20];
    char password[20];
} GG;             //class ADMIN ends here

fstream ad;     //Functions to get and put admin details here
void get_admin()
{
    ad.seekg(0,ios::beg);
    ad.read((char*)&GG,sizeof(GG));
}
void put_admin()
{
    ad.seekg(0,ios::beg);
    ad.write((char*)&GG,sizeof(GG));
}

//UDF to modify stu_details in binary file
void modify_stu_details(student &a)
{
    fstu.open("Student.dat",ios::binary|ios::in|ios::out|ios::ate);
    if(!fstu)
    {
        cout<<"FNF!";
        return;
    }
    fstu.seekg(0,ios::beg);
    while(fstu.read((char*)&t,sizeof(t)))
    {
        if(!strcmpi(a.ret_id(),t.ret_id()) || !strcmpi(a.ret_name(),t.ret_name()))
        {
            fstu.seekg(-1*int(sizeof(a)),ios::cur);
            fstu.write((char*)&a,sizeof(a));
        }
    }
    fstu.close();
}

void view_stu_list()
{
    fstu.open("Student.dat",ios::in|ios::out|ios::ate|ios::binary);
    if(!fstu)
    {
        cout<<"Student FNF";
        return;
    }
    fstu.seekg(0,ios::beg);
    cout<<"List of students:\n";
    while(fstu.read((char*)&t,sizeof(t)))
        cout<<t.ret_id()<<" - "<<t.ret_name()<<endl;
    cout<<"\n";
    fstu.close();
}
//End of UDF

void test_analysis1(qp1 &,student &,int);
void test_analysis2(qp2 &,student &,int);
void test_analysis3(qp3 &,student &,int);

void instructions1()                      //Start of Instruction UDFs
{
    cout<<"General instructions:\nAfter answering a question, press:\nN to go to next question\nQ to choose which question you want to go to\nS to submit\nI to view instructions again\n\n";
    cout<<"Default answer for SCQ = X, for Numerical = -1\n";
    cout<<"Paper pattern & marking scheme:\n";
    cout<<"This test contains 20 Single Correct(SCQ) and 5 Numerical Type Questions.\n";
    cout<<"SCQ(Q 1-20): +3 for correct answer,0 if not attempted,-1 in all other cases.\n";
    cout<<"Numericals(Q 16-20): +3 for correct answer and 0 in all other cases.\n";
}
void instructions2()
{
    cout<<"General instructions:\nAfter answering a question, press:\nN to go to next question\nQ to choose which question you want to go to\nS to submit\nI to view instructions again\n\n";
    cout<<"Default answer for SCQ & MCQ= X, for Numerical = -1\n";
    cout<<"Paper pattern & marking scheme:\n";
    cout<<"This test contains 4 Single Correct(SCQ),8 MultiCorrect(MCQ) and 8 Numerical Type Questions.\n";
    cout<<"SCQ(Q 1-4): +3 for correct answer,0 if not attempted,-1 in all other cases.\n";
    cout<<"MCQ(Q 5-12):Full marks of +4 if only (all) the correct option(s) are chosen,\n";
    cout<<"Partial marks of +1 per correct option if only correct option(s) are chosen\n";
    cout<<"but all correct options are not chosen,0 marks if no option is chosen,\nand -1 in all other cases.\n";
    cout<<"Numericals(Q 13-20): +3 for correct answer and 0 in all other cases.\n";
}
void instructions3()
{
    cout<<"General instructions:\nAfter answering a question, press:\nN to go to next question\nQ to choose which question you want to go to\nS to submit\nI to view instructions again\n\n";
    cout<<"Default answer for SCQ & MCQ = X, for Numerical = -1, for Matrix \nmatching X for each row\n";
    cout<<"Paper pattern & marking scheme:\n";
    cout<<"This test contains 8 Single Correct(SCQ), 5 MultiCorrect(MCQ), 4 Numerical \nType and 3 Matrix-Matching Questions.\n";
    cout<<"SCQ(Q 1-8): +3 for correct answer,0 if not attempted,-1 in all other cases.\n";
    cout<<"MCQ(Q 9-13):\nFull marks of +4 if only (all) the correct option(s) are chosen,";
    cout<<"Partial marks of +1 per correct option if only correct option(s) are chosen \nbut all correct options are not chosen,";
    cout<<"Zero marks if no option is chosen, \nand -1 in all other cases.\n";
    cout<<"Numericals(Q 14-17): +3 for correct answer and 0 in all other cases.\n";
    cout<<"Matching(Q 18-20): For each row in Column 1 - +2 for correct answer and 0 in all other cases.\n";
}                //End of Instruction UDFs

//Display_Response_Function1 (DRF1) to display student response during test
void disp_res1(student &s,int n)
{
    clrscr();
    cout<<"Test - QPType 1 - "<<s.test1[n].qpname<<"\n";
    int i;
    for(i=0; i<20; i++)
        cout<<i+1<<"-"<<s.test1[n].scq_res[i]<<"\t";
    for(i=0; i<5; i++)
        cout<<i+21<<":"<<s.test1[n].num_res[i]<<"\t";
    cout<<endl<<endl;
}
//DRF1 ends

//Test_Procedure_Function1 (TPF1) - Runs during test
void test_procedure1(qp1 &X,student &s,int n)
{
    strcpy(s.test1[n].qpname,X.testname);
    int i=0;
    char rep='N',rep2='N';
    disp_res1(s,n);
    cout<<i+1<<"]";
    X.a[i].scq_display();
    cout<<"\nEnter Answer:";
    cin>>s.test1[n].scq_res[i];
    cout<<"Next?";
    cin>>rep;
    rep=toupper(rep);
    while(rep2!='S')
    {
        if(rep=='N')
        {
            i++;
            if(i<20)
            {
                disp_res1(s,n);
                cout<<i+1<<"]";
                X.a[i].scq_display();
                cout<<"\nEnter Answer:";
                cin>>s.test1[n].scq_res[i];
            }
            else if(i<25)
            {
                disp_res1(s,n);
                cout<<i+1<<"]";
                X.b[i-20].numerical_display();
                cout<<"\nEnter Answer:";
                cin>>s.test1[n].num_res[i-20];
            }
            else if(i==25)
                cout<<"You have reached the end of the test.";
            else cout<<"Invalid choice.";
        }
        else if(rep=='Q')
        {
            cout<<"Enter question number:";
            int q;
            cin>>q;
            if(q<1 || q>25)
                cout<<"Invalid choice.";
            else if(q<21)
            {
                disp_res1(s,n);
                i=q-1;
                cout<<i+1<<"]";
                X.a[i].scq_display();
                cout<<"\nEnter Answer:";
                cin>>s.test1[n].scq_res[i];
            }
            else
            {
                disp_res1(s,n);
                i=q-1;
                cout<<i+1<<"]";
                X.b[i-20].numerical_display();
                cout<<"\nEnter Answer:";
                cin>>s.test1[n].num_res[i-20];
            }
        }
        else if(rep=='I')
        {
            disp_res1(s,n);
            instructions1();
        }
        else if(rep=='S')
        {
            disp_res1(s,n);
            cout<<"Do you want to submit[S/N]?";
            cin>>rep2;
            rep2=toupper(rep2);
        }
        else
            cout<<"Invalid.\n";
        if(rep2!='S')
        {
            cout<<"Next?";
            cin>>rep;
            rep=toupper(rep);
        }
    }
    clrscr();
    cout<<"You've finished the test!\n\n";
    cout<<"Results:\n";
    X.qp1_result(s.test1[n].scq_res,s.test1[n].num_res);
    if(n==s.count1)
        s.count1++;
    cout<<"Uploading results...\n";
    modify_stu_details(s);
    cout<<"Results uploaded!\n";
    cout<<"Do you want to see test analysis?";
    cin>>rep;
    if(toupper(rep)=='Y')
        test_analysis1(X,s,n);
    else
        cout<<"Enter any key to end test procedure";
    getch();
}
//TPF1 ends here


//DRF2 starts here
void disp_res2(student &s,int n)
{
    clrscr();
    cout<<"Test - QPType 2 - "<<s.test2[n].qpname<<"\n";
    int i;
    for(i=0; i<4; i++)
        cout<<i+1<<"-"<<s.test2[n].scq_res[i]<<"\t";
    for(i=0; i<8; i++)
        cout<<i+5<<"-"<<s.test2[n].mcq_res[i]<<"\t";
    for(i=0; i<8; i++)
        cout<<i+13<<":"<<s.test2[n].num_res[i]<<"\t";
    cout<<endl<<endl;
}
//DRF2 ends here

//TPF2 starts here
void test_procedure2(qp2 &X,student &s,int n)
{
    strcpy(s.test2[n].qpname,X.testname);
    int i=0;
    char rep='N',rep2='N';
    disp_res2(s,n);
    cout<<i+1<<"]";
    X.a[i].scq_display();
    cout<<"\nEnter Answer:";
    cin>>s.test2[n].scq_res[i];
    cout<<"Next?";
    cin>>rep;
    rep=toupper(rep);
    while(rep2!='S')
    {
        if(rep=='N')
        {
            i++;
            if(i<4)
            {
                disp_res2(s,n);
                cout<<i+1<<"]";
                X.a[i].scq_display();
                cout<<"\nEnter Answer:";
                cin>>s.test2[n].scq_res[i];
            }
            else if(i<12)
            {
                disp_res2(s,n);
                cout<<i+1<<"]";
                X.c[i-4].mcq_display();
                cout<<"\nEnter Answer:";
                gets(s.test2[n].mcq_res[i-4]);
            }
            else if(i<20)
            {
                disp_res2(s,n);
                cout<<i+1<<"]";
                X.b[i-12].numerical_display();
                cout<<"\nEnter Answer:";
                cin>>s.test2[n].num_res[i-12];
            }
            else if(i==20)
                cout<<"You have reached the end of the test.";
            else
                cout<<"Invalid choice.";
        }
        else if(rep=='Q')
        {
            cout<<"Enter question number:";
            int q;
            cin>>q;
            if(q<1 || q>20)
                cout<<"Invalid choice.";
            else if(q<5)
            {
                disp_res2(s,n);
                i=q-1;
                cout<<i+1<<"]";
                X.a[i].scq_display();
                cout<<"\nEnter Answer:";
                cin>>s.test2[n].scq_res[i];
            }
            else if(q<13)
            {
                disp_res2(s,n);
                i=q-1;
                cout<<i+1<<"]";
                X.c[i-4].mcq_display();
                cout<<"\nEnter Answer:";
                gets(s.test2[n].mcq_res[i-4]);
            }
            else
            {
                disp_res2(s,n);
                i=q-1;
                cout<<i+1<<"]";
                X.b[i-12].numerical_display();
                cout<<"\nEnter Answer:";
                cin>>s.test2[n].num_res[i-12];
            }
        }
        else if(rep=='I')
        {
            disp_res2(s,n);
            instructions2();
        }
        else if(rep=='S')
        {
            disp_res2(s,n);
            cout<<"Do you want to submit[S/N]?";
            cin>>rep2;
            rep2=toupper(rep2);
        }
        else
            cout<<"Invalid.";
        if(rep2!='S')
        {
            cout<<"Next?";
            cin>>rep;
            rep=toupper(rep);
        }
    }
    clrscr();
    cout<<"You've finished the test.\n\n";
    cout<<"Results:\n";
    X.qp2_result(s.test2[n].scq_res,s.test2[n].mcq_res,s.test2[n].num_res);
    cout<<"Uploading details...";
    if(n==s.count2)
        s.count2++;
    modify_stu_details(s);
    cout<<"Do you want to see analysis?";
    cin>>rep;
    rep=toupper(rep);
    if(rep=='Y')
        test_analysis2(X,s,n);
    else
        cout<<"Enter any key to exit test procedure";
    getch();
}
//TPF2 ends


//DRF3 begins
void disp_res3(student &s,int n)
{
    clrscr();
    cout<<"Test - QPType 3 - "<<s.test3[n].qpname<<"\n";
    int i;
    for(i=0; i<8; i++)
        cout<<i+1<<"-"<<s.test3[n].scq_res[i]<<"\t";
    for(i=0; i<5; i++)
        cout<<i+9<<"-"<<s.test3[n].mcq_res[i]<<"\t";
    for(i=0; i<4; i++)
        cout<<i+14<<":"<<s.test3[n].num_res[i]<<"\t";
    for(i=0; i<3; i++)
    {
        cout<<i+18<<"-";
        for(int j=0; j<4; j++)
            cout<<s.test3[n].matrix_res[i][j]<<";";
        cout<<"\t";
    }
    cout<<endl<<endl;
}
//DRF3 ends

//TPF3 begins
void test_procedure3(qp3 &X,student &s,int n)
{
    strcpy(s.test3[n].qpname,X.testname);
    int i=0;
    char rep='N',rep2='N';
    disp_res3(s,n);
    cout<<i+1<<"]";
    X.a[i].scq_display();
    cout<<"\nEnter Answer:";
    cin>>s.test3[n].scq_res[i];
    cout<<"Next?";
    cin>>rep;
    rep=toupper(rep);
    while(rep2!='S')
    {
        if(rep=='N')
        {
            i++;
            if(i<8)
            {
                disp_res3(s,n);
                cout<<i+1<<"]";
                X.a[i].scq_display();
                cout<<"\nEnter Answer:";
                cin>>s.test3[n].scq_res[i];
            }
            else if(i<13)
            {
                disp_res3(s,n);
                cout<<i+1<<"]";
                X.c[i-8].mcq_display();
                cout<<"\nEnter Answer:";
                gets(s.test3[n].mcq_res[i-8]);
            }
            else if(i<17)
            {
                disp_res3(s,n);
                cout<<i+1<<"]";
                X.b[i-13].numerical_display();
                cout<<"\nEnter Answer:";
                cin>>s.test3[n].num_res[i-13];
            }
            else if(i<20)
            {
                disp_res3(s,n);
                cout<<i+1<<"]"<<endl;
                X.d[i-17].matrix_display();
                for(int j=0; j<4; j++)
                {
                    cout<<"Enter answer for "<<char(j+65)<<":";
                    gets(s.test3[n].matrix_res[i-17][j]);
                }
            }
            else if(i==20)
                cout<<"You have reached the end of the test.";
            else cout<<"Invalid choice.";
        }
        else if(rep=='Q')
        {
            cout<<"Enter question number:";
            int q;
            cin>>q;
            if(q<1 || q>20)
                cout<<"Invalid choice.";
            else if(q<9)
            {
                disp_res3(s,n);
                i=q-1;
                cout<<i+1<<"]";
                X.a[i].scq_display();
                cout<<"\nEnter Answer:";
                cin>>s.test3[n].scq_res[i];
            }
            else if(q<15)
            {
                disp_res3(s,n);
                i=q-1;
                cout<<i+1<<"]";
                X.c[i-8].mcq_display();
                cout<<"\nEnter Answer:";
                gets(s.test3[n].mcq_res[i-8]);
            }
            else if(q<18)
            {
                disp_res3(s,n);
                i=q-1;
                cout<<i+1<<"]";
                X.b[i-13].numerical_display();
                cout<<"\nEnter Answer:";
                cin>>s.test3[n].num_res[i-13];
            }
            else
            {
                disp_res3(s,n);
                i=q-1;
                cout<<i+1<<"]"<<endl;
                X.d[i-17].matrix_display();
                for(int j=0; j<4; j++)
                {
                    cout<<"Enter answer for "<<char(j+65)<<":";
                    gets(s.test3[n].matrix_res[i-17][j]);
                }
            }
        }
        else if(rep=='I')
        {
            disp_res3(s,n);
            instructions3();
        }
        else if(rep=='S')
        {
            disp_res3(s,n);
            cout<<"Enter S again to submit:";
            cin>>rep2;
            rep2=toupper(rep2);
        }
        else
            cout<<"\nInvalid.";
        if(rep2!='S')
        {
            cout<<"\nNext?";
            cin>>rep;
            rep=toupper(rep);
        }
    }
    clrscr();
    cout<<"You've finished the test.\n";
    cout<<"Results:\n";
    X.qp3_result(s.test3[n].scq_res,s.test3[n].mcq_res,s.test3[n].num_res,s.test3[n].matrix_res);
    if(n==s.count3)
        s.count3++;
    cout<<"Uploading results...";
    modify_stu_details(s);
    cout<<"\nResults uploaded!";
    cout<<"\nDo you want to see analysis?";
    cin>>rep;
    rep=toupper(rep);
    if(rep=='Y')
        test_analysis3(X,s,n);
    else
        cout<<"Enter any key to end test procedure";
    getch();
}
//TPF3 ends


//Test_Analysis_Function1(TAF1) begins
void test_analysis1(qp1 &X,student &s,int n)
{
    int i=0;
    char rep='N',rep2='N';
    clrscr();
    X.qp1_report(s.test1[n].scq_res,s.test1[n].num_res);
    cout<<"\nEnter any key to start viewing the questions:";
    getch();
    clrscr();
    cout<<"Instructions - Enter:\nN for next\nQ to choose which question you want to go to\nX to exit analysis\n\n";
    cout<<i+1<<"]";
    X.a[i].scq_analysis(s.test1[n].scq_res[i]);
    cout<<"Next?";
    cin>>rep;
    rep=toupper(rep);
    while(rep2!='X')
    {
        if(rep=='N')
        {
            i++;
            if(i<20)
            {
                clrscr();
                cout<<i+1<<"]";
                X.a[i].scq_analysis(s.test1[n].scq_res[i]);
            }
            else if(i<25)
            {
                clrscr();
                cout<<i+1<<"]";
                X.b[i-20].numerical_analysis(s.test1[n].num_res[i-20]);
            }
            else if(i==25)
                cout<<"You have reached the end of the analysis.";
            else cout<<"Invalid choice.";
        }
        else if(rep=='Q')
        {
            cout<<"Enter question number:";
            int q;
            cin>>q;
            if(q<1 || q>25)
                cout<<"Invalid Qn choice.";
            else if(q<21)
            {
                clrscr();
                i=q-1;
                cout<<i+1<<"]";
                X.a[i].scq_analysis(s.test1[n].scq_res[i]);
            }
            else
            {
                clrscr();
                i=q-1;
                cout<<i+1<<"]";
                X.b[i-20].numerical_analysis(s.test1[n].num_res[i-20]);
            }
        }
        else if(rep=='X')
        {
            cout<<"Do you want to exit[X/N]?";
            cin>>rep2;
            rep2=toupper(rep2);
        }
        else
            cout<<"Invalid.";
        if(rep2!='X')
        {
            cout<<"\nNext?";
            cin>>rep;
            rep=toupper(rep);
        }
    }
    clrscr();
}
//TAF1 ends


//TAF2 begins
void test_analysis2(qp2 &X,student &s,int n)
{
    int i=0;
    char rep='N',rep2='N';
    clrscr();
    X.qp2_report(s.test2[n].scq_res,s.test2[n].mcq_res,s.test2[n].num_res);
    cout<<"\nEnter any key to start viewing the questions:";
    getch();
    clrscr();
    cout<<"Instructions - Enter:\nN for next\nQ to choose which question you want to go to\nX to exit analysis";
    X.a[i].scq_analysis(s.test2[n].scq_res[i]);
    cout<<"Next?";
    cin>>rep;
    rep=toupper(rep);
    while(rep2!='X')
    {
        if(rep=='N')
        {
            i++;
            if(i<4)
            {
                clrscr();
                cout<<i+1<<"]";
                X.a[i].scq_analysis(s.test2[n].scq_res[i]);
            }
            else if(i<12)
            {
                clrscr();
                cout<<i+1<<"]";
                X.c[i-4].mcq_analysis(s.test2[n].mcq_res[i-4]);
            }
            else if(i<20)
            {
                clrscr();
                cout<<i+1<<"]";
                X.b[i-12].numerical_analysis(s.test2[n].num_res[i-12]);
            }
            else if(i==20)
                cout<<"You have reached the end of the analysis.";
            else cout<<"Invalid.";
        }
        else if(rep=='Q')
        {
            cout<<"Enter question number:";
            int q;
            cin>>q;
            if(q<1 || q>20)
                cout<<"Invalid Qn choice.";
            else if(q<5)
            {
                clrscr();
                i=q-1;
                cout<<i+1<<"]";
                X.a[i].scq_analysis(s.test2[n].scq_res[i]);
            }
            else if(q<13)
            {
                clrscr();
                i=q-1;
                cout<<i+1<<"]";
                X.c[i-4].mcq_analysis(s.test2[n].mcq_res[i-4]);
            }
            else
            {
                clrscr();
                i=q-1;
                cout<<i+1<<"]";
                X.b[i-12].numerical_analysis(s.test2[n].num_res[i-12]);
            }
        }
        else if(rep=='X')
        {
            cout<<"Do you want to exit[X/N]?";
            cin>>rep2;
            rep2=toupper(rep2);
        }
        else
            cout<<"Invalid.\n";
        if(rep2!='X')
        {
            cout<<"Next?";
            cin>>rep;
            rep=toupper(rep);
        }
    }
    clrscr();
}
//TAF2 ends


//TAF3 begins
void test_analysis3(qp3 &X,student &s,int n)
{
    int i=0;
    char rep='N',rep2='N';
    clrscr();
    X.qp3_report(s.test3[n].scq_res,s.test3[n].mcq_res,s.test3[n].num_res,s.test3[n].matrix_res);
    cout<<"\nEnter any key to start viewing the questions:";
    getch();
    clrscr();
    cout<<"Instructions - Enter:\nN for next\nQ to choose which question you want to go to\nX to exit analysis";
    cout<<i+1<<"]";
    X.a[i].scq_analysis(s.test3[n].scq_res[i]);
    cout<<"Next?";
    cin>>rep;
    rep=toupper(rep);
    while(rep2!='X')
    {
        if(rep=='N')
        {
            i++;
            if(i<8)
            {
                clrscr();
                cout<<i+1<<"]";
                X.a[i].scq_analysis(s.test3[n].scq_res[i]);
            }
            else if(i<13)
            {
                clrscr();
                cout<<i+1<<"]";
                X.c[i-8].mcq_analysis(s.test3[n].mcq_res[i-8]);
            }
            else if(i<17)
            {
                clrscr();
                cout<<i+1<<"]";
                X.b[i-13].numerical_analysis(s.test3[n].num_res[i-13]);
            }
            else if(i<20)
            {
                clrscr();
                cout<<i+1<<"]\n";
                X.d[i-17].matrix_analysis(s.test3[n].matrix_res[i-17]);
            }
            else if(i==20)
                cout<<"You have reached the end of the analysis.";
            else cout<<"Invalid.";
        }
        else if(rep=='Q')
        {
            cout<<"Enter question number:";
            int q;
            cin>>q;
            if(q<1 || q>20)
                cout<<"Invalid choice.";
            else if(q<9)
            {
                clrscr();
                i=q-1;
                cout<<i+1<<"]";
                X.a[i].scq_analysis(s.test3[n].scq_res[i]);
            }
            else if(q<14)
            {
                clrscr();
                i=q-1;
                cout<<i+1<<"]";
                X.c[i-8].mcq_analysis(s.test3[n].mcq_res[i-8]);
            }
            else if(q<18)
            {
                clrscr();
                i=q-1;
                cout<<i+1<<"]";
                X.b[i-13].numerical_analysis(s.test3[n].num_res[i-13]);
            }
            else
            {
                clrscr();
                i=q-1;
                cout<<i+1<<"]"<<endl;
                X.d[i-17].matrix_analysis(s.test3[n].matrix_res[i-17]);
            }
        }
        else if(rep=='X')
        {
            cout<<"Do you want to exit[X/N]?";
            cin>>rep2;
            rep2=toupper(rep2);
        }
        else
            cout<<"Invalid.\n";
        if(rep2!='X')
        {
            cout<<"Next?";
            cin>>rep;
            rep=toupper(rep);
        }
    }
    clrscr();
}
//TAF3 ends


//START_PROCEDURE Begins
void start_procedure()
{
    char r,sid[20],spass[20];
    int flag=0,i;
    view_stu_list();
    cout<<"Enter ID of student who'll attempt the test:";
    gets(sid);
    fstu.open("Student.dat",ios::binary|ios::in|ios::ate);
    if(!fstu)
    {
        cout<<"Student FNF!";
        return;
    }
    fstu.seekg(0,ios::beg);
    while(fstu.read((char*)&stu,sizeof(stu)))
    {
        if(strcmpi(stu.ret_id(),sid)==0)
        {
            flag++;
            break;
        }
    }
    fstu.close();
    if(flag==0)
    {
        cout<<"Student not found!";
        return;
    }
    flag=0;
    int type;
    char tname[30];
    cout<<"Enter QP type and QP name of test to be assigned:";
    cin>>type;
    gets(tname);
    cout<<"Downloading test...\n";
    if(type==1)
    {
        f1.open("QP1.dat",ios::binary|ios::in|ios::ate);
        if(!f1)
        {
            cout<<"FNF!";
            return;
        }
        f1.seekg(0,ios::beg);
        while(f1.read((char*)&p1,sizeof(p1)))
        {
            if(!strcmpi(p1.testname,tname))
            {
                flag++;
                break;
            }
        }
        f1.close();
        if(flag==0)
            cout<<"QP not found!";
        else
        {
            cout<<"Test successfully downloaded.\n";
            cout<<"Enter R if student is reattempting this test, else enter any key to continue:";
            cin>>r;
            if(toupper(r)=='R')
            {
                flag=0;
                for(i=0; i<stu.count1; i++)
                {
                    if(!strcmpi(tname,stu.test1[i].qpname))
                    {
                        flag++;
                        break;
                    }
                }
                if(!flag)
                {
                    cout<<"Student hasn't attempted this test before!\n";
                    i=stu.count1;
                }
                else
                {
                    int j;
                    for(j=0; j<20; j++)
                        stu.test1[i].scq_res[j]='X';
                    for(j=0; j<5; j++)
                        stu.test1[i].num_res[j]=-1;
                }
                cout<<"Enter any key to proceed:";
                getch();
            }
            else
                i=stu.count1;
            clrscr();
            cout<<"TEST - "<<p1.testname<<"\n\n";
            cout<<"Enter student ID:";
            gets(sid);
            cout<<"Enter student password:";
            gets(spass);
            if(strcmpi(stu.ret_id(),sid)==0 && strcmp(stu.ret_pass(),spass)==0)
            {
                cout<<"Press any key to view instructions:";
                getch();
                instructions1();
                cout<<"Are you ready to begin the test?\n";
                r='X';
                cout<<"Enter Y to begin testing,N to quit\n";
                cin>>r;
                if(toupper(r)=='Y')
                    test_procedure1(p1,stu,i);
                else if(r!='N')
                {
                    cout<<"Invalid,re-enter response:";
                    cin>>r;
                    if(toupper(r)=='Y')
                        test_procedure1(p1,stu,i);
                }
            }
            else
            {
                cout<<"Wrong credentials!";
                cout<<"Enter any alphanumeric to go back:";
                getch();
            }
        }
    }
    else if(type==2)
    {
        f2.open("QP2.dat",ios::binary|ios::in|ios::ate);
        if(!f2)
        {
            cout<<"FNF!";
            return;
        }
        f2.seekg(0,ios::beg);
        while(f2.read((char*)&p2,sizeof(p2)))
        {
            if(!strcmpi(p2.testname,tname))
            {
                flag++;
                break;
            }
        }
        f2.close();
        if(flag==0)
            cout<<"QP not found!";
        else
        {
            cout<<"Test successfully downloaded.\n";
            cout<<"Enter R if student is reattempting this test, else enter any key to continue:";
            cin>>r;
            if(toupper(r)=='R')
            {
                flag=0;
                for(i=0; i<stu.count2; i++)
                {
                    if(!strcmpi(tname,stu.test2[i].qpname))
                    {
                        flag++;
                        break;
                    }
                }
                if(!flag)
                {
                    cout<<"Student hasn't attempted this test before!\n";
                    i=stu.count2;
                }
                else
                {
                    int j;
                    for(j=0; j<4; j++)
                        stu.test2[i].scq_res[j]='X';
                    for(j=0; j<8; j++)
                        strcpy(stu.test2[i].mcq_res[j],"X");
                    for(j=0; j<8; j++)
                        stu.test2[i].num_res[j]=-1;
                }
                cout<<"Enter any key to proceed:";
                getch();
            }
            else
                i=stu.count2;
            clrscr();
            cout<<"TEST - "<<p2.testname<<"\n\n";
            cout<<"Enter student ID:";
            gets(sid);
            cout<<"Enter student password:";
            gets(spass);
            if(strcmpi(stu.ret_id(),sid)==0 && strcmp(stu.ret_pass(),spass)==0)
            {
                cout<<"Press any key to view instructions:";
                getch();
                instructions2();
                cout<<"Enter Y to begin testing,N to quit\n";
                cin>>r;
                if(toupper(r)=='Y')
                    test_procedure2(p2,stu,i);
                else if(r!='N')
                {
                    cout<<"Invalid,re-enter response:";
                    cin>>r;
                    if(toupper(r)=='Y')
                        test_procedure2(p2,stu,i);
                }
            }
            else
            {
                cout<<"Wrong credentials!";
                cout<<"Enter any alphanumeric to go back:";
                getch();
            }
        }
    }
    else if(type==3)
    {
        f3.open("QP3.dat",ios::binary|ios::in|ios::ate);
        if(!f3)
        {
            cout<<"FNF!";
            return;
        }
        f3.seekg(0,ios::beg);
        int flag=0;
        while(f3.read((char*)&p3,sizeof(p3)))
        {
            if(!strcmpi(p3.testname,tname))
            {
                flag++;
                break;
            }
        }
        f3.close();
        if(flag==0)
            cout<<"QP not found!";
        else
        {
            cout<<"Test successfully downloaded.\n";
            cout<<"Enter R if student is reattempting this test, else enter any key to continue:";
            cin>>r;
            if(toupper(r)=='R')
            {
                flag=0;
                for(i=0; i<stu.count3; i++)
                {
                    if(!strcmpi(tname,stu.test3[i].qpname))
                    {
                        flag++;
                        break;
                    }
                }
                if(!flag)
                {
                    cout<<"Student hasn't attempted this test before!\n";
                    i=stu.count3;
                }
                else
                {
                    int j;
                    for(j=0; j<8; j++)
                        stu.test3[i].scq_res[j]='X';
                    for(j=0; j<5; j++)
                        strcpy(stu.test3[i].mcq_res[j],"X");
                    for(j=0; j<4; j++)
                        stu.test3[i].num_res[i]=-1;
                    for(j=0; j<3; j++)
                        for(int k=0; k<4; k++)
                            strcpy(stu.test3[i].matrix_res[j][k],"X");
                }
                cout<<"Enter any key to proceed:";
                getch();
            }
            else
                i=stu.count3;
            clrscr();
            cout<<"TEST - "<<p3.testname<<"\n\n";
            cout<<"Enter student ID:";
            gets(sid);
            cout<<"Enter student password:";
            gets(spass);
            if(strcmpi(stu.ret_id(),sid)==0 && strcmp(stu.ret_pass(),spass)==0)
            {
                cout<<"Press any key to view instructions:";
                getch();
                instructions3();
                cout<<"Are you ready to begin the test?\n";
                r='X';
                cout<<"Enter Y to begin testing,N to quit\n";
                cin>>r;
                if(toupper(r)=='Y')
                    test_procedure3(p3,stu,i);
                else if(r!='N')
                {
                    cout<<"Invalid,re-enter response:";
                    cin>>r;
                    if(toupper(r)=='Y')
                        test_procedure3(p3,stu,i);
                }
            }
            else cout<<"Wrong credentials";
        }
    }
}

//UDFs for adding QPs onto the file

void add_qp1(qp1 &p)
{
    f1.open("QP1.dat",ios::binary|ios::out|ios::ate);
    if(!f1)
    {
        cout<<"FNF";
        return;
    }
    strcpy(MVM.qp1_testname[MVM.n_qp1],p.testname);
    f1.write((char*)&p,sizeof(p));
    f1.close();
    MVM.n_qp1++;
}
void add_qp2(qp2 &p)
{
    f2.open("QP2.dat",ios::binary|ios::out|ios::ate);
    if(!f2)
    {
        cout<<"FNF";
        return;
    }
    strcpy(MVM.qp2_testname[MVM.n_qp2],p.testname);
    f2.write((char*)&p,sizeof(p));
    f2.close();
    MVM.n_qp2++;
}
void add_qp3(qp3 &p)
{
    f3.open("QP3.dat",ios::binary|ios::out|ios::ate);
    if(!f3)
    {
        cout<<"FNF";
        return;
    }
    strcpy(MVM.qp3_testname[MVM.n_qp3],p.testname);
    f3.write((char*)&p,sizeof(p));
    f3.close();
    MVM.n_qp3++;
}

fstream inst;		    //File for institute
void get_institute()        //To get MVM from file
{
    inst.read((char*)&MVM,sizeof(MVM));
}
void put_institute()           //To put MVM back in file at the end
{
    inst.seekg(0,ios::beg);
    inst.write((char*)&MVM,sizeof(MVM));
}
int findqp1(char name[],qp1 &p)
{
    f1.open("QP1.dat",ios::in|ios::ate|ios::binary);
    qp1 pap1;
    f1.seekg(0,ios::beg);
    while(f1.read((char*)&pap1,sizeof(pap1)))
    {
        if(strcmpi(name,pap1.testname)==0)
        {
            p=pap1;
            f1.close();
            return 1;
        }
    }
    f1.close();
    return 0;
}
int findqp2(char name[],qp2 &p)
{
    f2.open("QP2.dat",ios::in|ios::ate|ios::binary);
    qp2 pap2;
    f2.seekg(0,ios::beg);
    while(f2.read((char*)&pap2,sizeof(pap2)))
    {
        if(strcmpi(name,pap2.testname)==0)
        {
            p=pap2;
            f2.close();
            return 1;
        }
    }
    f2.close();
    return 0;
}
int findqp3(char name[], qp3 &p)
{
    f3.open("QP3.dat",ios::in|ios::ate|ios::binary);
    qp3 pap3;
    f3.seekg(0,ios::beg);
    while(f3.read((char*)&pap3,sizeof(pap3)))
    {
        if(strcmpi(name,pap3.testname)==0)
        {
            p=pap3;
            f3.close();
            return 1;
        }
    }
    f3.close();
    return 0;
}

//MAIN FUNCTION Begins
void main()
{
    clrscr();
    inst.open("Inst.dat",ios::binary|ios::in|ios::out|ios::ate);
    ad.open("Admin.dat",ios::binary|ios::in|ios::out|ios::ate);
    get_admin();
    get_institute();
    char rep='y';
    while(rep=='y')
    {
        clrscr();
        cout<<"Login:\nAdmin(A) or Student(S)?[X to exit]:";
        char ch;
        int n;
        cin>>ch;
        char user[20],pass[20];
        ch=toupper(ch);
        if(ch=='A')
        {
            cout<<"\n\nAdmin Login\n\n";
            cout<<"Enter UserID:";
            gets(user);
            cout<<"Enter Password:";
            gets(pass);
            if(strcmpi(GG.userid,user)==0 && strcmp(pass,GG.password)==0)          //admin not in file?where is username password stored?
            {
                clrscr();
                cout<<"Admin "<<user<<" successfully logged in\n\n";
                cout<<"Choose:\n1.Create Papers\n2.View tests available\n3.Start test for student\n4.Add new student\n5.View student details\n6.Modify student details\n7.Check student requests\n8.View student test analysis\n9.Change login details\n10.Logout\n";
                cin>>n;
                while(n!=10)
                {
                    if(n==1)
                    {
                        clrscr();
                        cout<<"Admin "<<user<<"- 1.Create papers\n\n";
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
                            cout<<"Invalid QP type!\n";
                        put_institute();
                    }
                    else if(n==2)
                    {
                        clrscr();
                        cout<<"Admin "<<user<<" - 2.View available tests\n\n";
                        cout<<"Enter test type:";
                        int k;
                        cin>>k;
                        if(k==1)
                        {
                            for(int x=0; x<MVM.n_qp1; x++)
                                cout<<MVM.qp1_testname[x]<<endl;
                        }
                        else if(k==2)
                        {
                            for(int x=0; x<MVM.n_qp2; x++)
                                cout<<MVM.qp2_testname[x]<<endl;
                        }
                        else if(k==3)
                        {
                            for(int x=0; x<MVM.n_qp3; x++)
                                cout<<MVM.qp3_testname[x]<<endl;
                        }
                        else cout<<"Wrong QP type.";
                    }
                    else if(n==3)
                    {
                        clrscr();
                        cout<<"Admin "<<user<<"- 3.Start Procedure\n\n";
                        start_procedure();
                    }
                    else if(n==4)
                    {
                        clrscr();
                        cout<<"Admin "<<user<<"- 4.Enter new student\n\n";
                        stu.stu_create();
                        cout<<"New student added. Uploading student details...\n";
                        upload_newstu_details(stu);
                        cout<<"Student details uploaded!\n";
                    }
                    else if(n==5)
                    {
                        clrscr();
                        cout<<"Admin "<<user<<"- 5.View student details\n";
                        view_stu_list();
                        cout<<"Enter ID of student:";
                        char id[20];
                        gets(id);
                        int flag=0;
                        fstu.open("Student.dat",ios::in|ios::out|ios::ate|ios::binary);
                        fstu.seekg(0,ios::beg);
                        while(fstu.read((char*)&stu,sizeof(stu)))
                        {
                            if(strcmpi(stu.ret_id(),id)==0)
                            {
                                flag++;
                                break;
                            }
                        }
                        fstu.close();
                        if(flag==0)
                            cout<<"Student not found!\n";
                        else
                            stu.stu_display();
                    }
                    else if(n==6)
                    {
                        clrscr();
                        cout<<"Admin "<<user<<"- 6.Edit student details\n\n";
                        view_stu_list();
                        fstu.open("Student.dat",ios::in|ios::out|ios::ate|ios::binary);
                        cout<<"Enter ID of student:";
                        char id[20];
                        gets(id);
                        int flag=0;
                        fstu.seekg(0,ios::beg);
                        while(fstu.read((char*)&stu,sizeof(stu)))
                        {
                            if(strcmpi(stu.ret_id(),id)==0)
                            {
                                flag++;
                                break;
                            }
                        }
                        fstu.close();
                        if(flag==0)
                            cout<<"Student not found!\n";
                        else
                        {
                            stu.stu_edit();
                            cout<<"Saving changes...\n";
                            modify_stu_details(stu);
                            cout<<"Changes saved!\n";
                        }
                    }
                    else if(n==7)
                    {
                        clrscr();
                        cout<<"Admin "<<user<<"- 7.View student requests\n\n";
                        char c;
                        fstu.open("Student.dat",ios::binary|ios::in|ios::out|ios::ate);
                        if(!fstu)		cout<<"FNF";
                        else
                        {
                            fstu.seekg(0,ios::beg);
                            while(fstu.read((char*)&stu,sizeof(stu)))
                            {
                                if(strcmpi(stu.request,"X")!=0)
                                {
                                    clrscr();
                                    stu.stu_display();
                                    cout<<"\nThe above student has a request:";
                                    puts(stu.request);
                                    cout<<"Are you done with this request? Enter V to make void.Enter any key to go to next";
                                    cin>>c;
                                    if(toupper(c)=='V')
                                    {
                                        strcpy(stu.request,"X");
                                        fstu.seekg(-1*(int)sizeof(stu),ios::cur);
                                        fstu.write((char*)&stu,sizeof(stu));
                                    }
                                }
                            }
                        }
                        fstu.close();
                    }
                    else if(n==8)
                    {
                        clrscr();
                        cout<<"Admin "<<user<<"- 8.View student test analysis\n\n";
                        view_stu_list();
                        cout<<"Enter ID of student:";
                        char id[20];
                        gets(id);
                        int fl=0;
                        fstu.open("Student.dat",ios::in|ios::out|ios::ate|ios::binary);
                        fstu.seekg(0,ios::beg);
                        while(fstu.read((char*)&stu,sizeof(stu)))
                        {
                            if(strcmpi(stu.ret_id(),id)==0)
                            {
                                fl++;
                                break;
                            }
                        }
                        fstu.close();
                        if(fl==0)
                            cout<<"Student not found!\n";
                        else
                        {
                            cout<<"Enter test type:";
                            int ty,flag=0;
                            char qpname[30];
                            cin>>ty;
                            if(ty==1)
                            {
                                cout<<"Enter test name:";
                                gets(qpname);
                                int i;
                                for(i=0; i<stu.count1; i++)
                                {
                                    if(strcmpi(stu.test1[i].qpname,qpname)==0)
                                    {
                                        flag++;
                                        if(findqp1(qpname,p1)==1)
                                        {
                                            test_analysis1(p1,stu,i);
                                            break;
                                        }
                                    }
                                }
                                if(flag==0)
                                    cout<<"Test not yet attempted by student!";
                            }
                            else if(ty==2)
                            {
                                cout<<"Enter test name:";
                                gets(qpname);
                                int i;
                                for(i=0; i<stu.count2; i++)
                                {
                                    if(strcmpi(stu.test2[i].qpname,qpname)==0)
                                    {
                                        flag++;
                                        if(findqp2(qpname,p2)==1)
                                        {
                                            test_analysis2(p2,stu,i);
                                            break;
                                        }
                                    }
                                }
                                if(flag==0)
                                    cout<<"Student has not attempted this test!";
                            }
                            else if(ty==3)
                            {
                                cout<<"Enter test name:";
                                gets(qpname);
                                int i;
                                for(i=0; i<stu.count3; i++)
                                {
                                    if(strcmpi(stu.test3[i].qpname,qpname)==0)
                                    {
                                        flag++;
                                        if(findqp3(qpname,p3)==0)
                                        {
                                            test_analysis3(p3,stu,i);
                                            break;
                                        }
                                    }
                                }
                                if(flag==0)
                                    cout<<"Student has not attempted this test!";
                            }
                            else cout<<"Invalid QP type!";
                        }
                    }
                    else if(n==9)
                    {
                        char user1[20],password1[20];
                        cout<<"Enter new Userid: ";
                        gets(user1);
                        cout<<"Enter new Password: ";
                        gets(password1);
                        strcpy(GG.userid,user1);
                        strcpy(GG.password,password1);
                        cout<<"Changes accepted";
                        put_admin();
                    }
                    else if(n!=10)
                        cout<<"Invalid choice.";
                    cout<<"\n\nEnter any key to continue:";
                    getch();
                    clrscr();
                    cout<<"Admin "<<user<<"\n\n";
                    cout<<"Choose:\n1.Create Papers\n2.View tests available\n3.Start test for student\n4.Add new student\n5.View student details\n6.Modify student details\n7.Check student requests\n8.View student test analysis\n9.Change login details\n10.Logout\n";
                    cin>>n;
                }
            }
            else
                cout<<"Incorrect login credentials!\n";
            cout<<"Enter any key to go back to login screen:";
            getch();
        }
        else if(ch=='S')
        {
            cout<<"\n\nStudent Login:\n\n";
            cout<<"Enter username:";
            gets(user);
            cout<<"Enter password:";
            gets(pass);
            fstu.open("Student.dat",ios::binary|ios::in|ios::ate);
            if(!fstu)		cout<<"Student FNF!";
            else
            {
                fstu.seekg(0,ios::beg);
                int flag=0;
                while(fstu.read((char*)&stu,sizeof(stu)))
                {
                    if(strcmpi(stu.ret_id(),user)==0 && strcmp(stu.ret_pass(),pass)==0)
                    {
                        flag++;
                        break;
                    }
                }
                fstu.close();
                if(flag==0)
                {
                    cout<<"Entered credentials are wrong!\n";
                    cout<<"Enter any key to go back to login screen:";
                    getch();
                }
                else
                {
                    clrscr();
                    cout<<"Student "<<stu.ret_name()<<" logged in successfully!\n";
                    cout<<"Choose:\n1.Display profile\n2.Edit profile\n3.Send request to Admin\n4.View Test Analysis\n5.View available tests\n6.Logout";
                    cin>>n;
                    while(n!=6)
                    {
                        if(n==1)
                        {
                            clrscr();
                            cout<<"Student "<<stu.ret_name()<<" - 1.Display profile\n\n";
                            stu.stu_display();
                        }
                        else if(n==2)
                        {
                            clrscr();
                            cout<<"Student "<<stu.ret_name()<<" - 2.Edit Profile\n\n";
                            stu.stu_edit();
                            cout<<"Details edited.Saving changes...\n";
                            modify_stu_details(stu);
                            cout<<"Changes saved!\n";
                        }
                        else if(n==3)
                        {
                            clrscr();
                            cout<<"Student "<<stu.ret_name()<<" - 3.Send request to Admin\n\n";
                            cout<<"Enter request: ";
                            gets(stu.request);
                            cout<<"Request noted. Saving on server....\n";
                            modify_stu_details(stu);
                            cout<<"Changes saved!\n";
                        }
                        else if(n==4)
                        {
                            clrscr();
                            cout<<"Student "<<stu.ret_name()<<" - 4.View test analysis\n\n";
                            cout<<"Enter test type:";
                            int ty,flag=0;
                            char qpname[30];
                            cin>>ty;
                            if(ty==1)
                            {
                                cout<<"Enter test name:";
                                gets(qpname);
                                int i;
                                for(i=0; i<stu.count1; i++)
                                {
                                    if(strcmpi(stu.test1[i].qpname,qpname)==0)
                                    {
                                        flag++;
                                        if(findqp1(qpname,p1)==1)
                                        {
                                            test_analysis1(p1,stu,i);
                                            break;
                                        }
                                    }
                                }
                                if(flag==0)
                                    cout<<"You have not attempted such a test.";
                            }
                            else if(ty==2)
                            {
                                cout<<"Enter test name:";
                                gets(qpname);
                                int i;
                                for(i=0; i<stu.count2; i++)
                                {
                                    if(strcmpi(stu.test2[i].qpname,qpname)==0)
                                    {
                                        flag++;
                                        if(findqp2(qpname,p2)==1)
                                        {
                                            test_analysis2(p2,stu,i);
                                            break;
                                        }
                                    }
                                }
                                if(flag==0)
                                    cout<<"You have not attempted such a test.";
                            }
                            else if(ty==3)
                            {
                                cout<<"Enter test name:";
                                gets(qpname);
                                int i;
                                for(i=0; i<stu.count3; i++)
                                {
                                    if(strcmpi(stu.test3[i].qpname,qpname)==0)
                                    {
                                        flag++;
                                        if(findqp3(qpname,p3)==1)
                                        {
                                            test_analysis3(p3,stu,i);
                                            break;
                                        }
                                    }
                                }
                                if(flag==0)
                                    cout<<"You have not attempted such a test.";
                            }
                            else cout<<"Invalid QP type!";
                        }
                        else if(n==5)
                        {
                            cout<<"Student "<<stu.ret_name()<<" - 2.View available tests\n\n";
                            cout<<"Enter test type:";
                            int k;
                            cin>>k;
                            if(k==1)
                            {
                                for(int x=0; x<MVM.n_qp1; x++)
                                    cout<<MVM.qp1_testname[x]<<endl;
                            }
                            else if(k==2)
                            {
                                for(int x=0; x<MVM.n_qp2; x++)
                                    cout<<MVM.qp2_testname[x]<<endl;
                            }
                            else if(k==3)
                            {
                                for(int x=0; x<MVM.n_qp3; x++)
                                    cout<<MVM.qp3_testname[x]<<endl;
                            }
                            else cout<<"Wrong QP type.";
                        }
                        else if(n!=6)
                            cout<<"Invalid.";
                        cout<<"Enter any key to continue:";
                        getch();
                        clrscr();
                        cout<<"Student "<<stu.ret_name()<<"\n\n";
                        cout<<"Choose:\n1.Display profile\n2.Edit profile\n3.Request Admin for test\n4.View Test Analysis\n5.View available tests\n6.Logout";
                        cin>>n;
                    }
                }
            }
        }
        else if(ch=='X')
        {
            getch();
            put_institute();
            ad.close();
            inst.close();
            exit(0);
        }
    }
}
