#include <iostream>
using namespace std;
char grades(int marks[],int i){
    char grade;
    if(marks[i]>=85){
        grade='A';
    }
    else if(marks[i]>=75&&marks[i]<85){
        grade='B';
    }
    else if(marks[i]>=55&&marks[i]<75){
        grade='C';
    }
    else if(marks[i]>=40&&marks[i]<55){
        grade='D';
    }
    else if(marks[i]>=0){
        grade='F';
    }
    else{
        grade='-';
    }
    return grade;
}
int main (){
    int o=0;
    string students[5];
    int marks[5];
    char grade[5];
    for(int a=0;a<5;a++){
        students[a]="NV";
        marks[a]=-1;
        grade[a]='-';
    }
    unsigned int num;
    string name,update,del,UserName,Password;
    for(int b=0;b<5;b++){
        grade[b]=grades(marks,b);
    }
    cout<<"=====================================================================\n\t\t     University Grading System"<<endl;
    cout<<"=====================================================================\n\t    Please Enter The Administration Cridentials!\n"<<endl;
    cout<<"=====================================================================\nEnter UserName : ";
    cin>>UserName;
    cout<<"Enter Password : ";
    cin>>Password;

    if(UserName=="Administration"&&Password=="PF2025"){
        do{
            cout<<"====================================================================="<<endl;
			cout<<"\t      Chose from the following menu:\nEnter 1 to add a student\nEnter 2 to search a student"<<endl;
            cout<<"Enter 3 to delete a student\nEnter 4 to update the data of a student\nEnter 5 to display number of students in the system"<<endl;
            cout<<"Enter 6 to display list of all students without grade\nEnter 7 to display list of all students with grade"<<endl;
            cout<<"Enter 0 to close program\n=====================================================================\nPlease enter input: ";
            cin>>num;

            switch(num){
            case 1:{
                if(o<5){
                	cout<<"\n\t\tAdd a student\n";
                    cout<<"Enter the student's name  : ";
                    cin>>students[o];
                    cout<<"Enter the student's marks : ";
                    cin>>marks[o];
                    grade[o]=grades(marks,o);
                    o+=1;
                    cout<<"=====================================================================\nHere's the updated list of students:\n";
                    for(int i=0;i<5;i++){
                        if(students[i]!="NV"){
                            cout<<i+1<<") "<<students[i]<<endl;
                        }
                    }
                }
                else{
                    cout<<"No space left!\n"<<endl;
                }
                break;
            }
            case 2:{
            	cout<<"\t\tSearch a student"<<endl;
                cout<<"\t Please enter your name: ";
                cin>>name;
                cout<<endl;
                bool check2=true;
                for(int c=0;c<5;c++){
                    if(marks[c]!=-1){
                        grade[c]=grades(marks,c);
                    }
                    if(name==students[c]){
                        cout<<"Name\t: "<<students[c]<<"\nMarks\t: "<<marks[c]<<"\nGrade\t: "<<grade[c]<<endl;
                        check2=false;
                        break;
                    }
                }
                if(check2){
                    cout<<"No data found\n---------------------------------------------------------------------"<<endl;
                }
                break;
            }
            case 3:{
            	cout<<"====================================================================="<<endl;
                cout<<"\t   enter the student you want to delete:"<<endl;
                for(int d=0;d<5;d++){
                    if(students[d]!="NV"){
                        cout<<d+1<<") "<<students[d]<<endl;
                    }
                }
                cin>>del;
                bool check=false;
                for(int e=0;e<5;e++){
                    if(del==students[e]){
                        students[e]="NV";
                        marks[e]=-1;
                        grade[e]=grades(marks,e);
                        cout<<"Student deleted successfully!\n---------------------------------------------------------------------"<<endl;
                        cout<<"Here is the updated list of students: "<<endl;
                        for(int d=0;d<5;d++){
                            if(students[d]!="NV"){
                                cout<<d+1<<") "<<students[d]<<endl;
                            }
                        }
                        check=true;
                        break;
                    }
                }
                if(check==false) {
                    cout<<"Record not found!\n"<<endl;
                }
                break;
            }
            case 4:{
                cout<<"====================================================================="<<endl;
				cout<<"\t\tUpdate Student Record\n\t   Enter student name : ";
                cin>>update;
                bool check1=false;
                for(int f=0;f<5;f++){
                    if(update==students[f]){
                        cout<<"Student name: "<<students[f]<<"\nStudent marks: "<<marks[f]<<"\nEnter updated marks: ";
                        cin>>marks[f];
                        grade[f]=grades(marks,f);
                        cout<<"\t    -------------------------------"<<endl;
						cout<<"Student updated successfully!\nName  : "<<students[f]<<"\nMarks : "<<marks[f]<<endl;
                        check1=true;
                        break;
                    }
                }
                if(check1==false){
                    cout<<"Record not found!\n"<<endl;
                }
                break;
            }
            case 5:{
                int count=0;
                for(int z=0;z<5;z++){
                    if(students[z]!="NV"){
                        count+=1;
                    }
                }
                cout<<"====================================================================="<<endl;
				cout<<"total number of students in system: "<<count<<"\n"<<endl;
                if(count==5){ cout<<"memory is full\n\n"<<endl;}
                break;
            }
            case 6:{
                cout<<"====================================================================="<<endl;
                cout<<"Student Name\t\t     Marks\n---------------------------------------------------------------------"<<endl;
                for(int h=0;h<5;h++){
                    if(students[h]!="NV"){
                        cout<<students[h];
                        cout<<"   \t\t\t"<<marks[h]<<endl;
                    }
                }
                break;
            }
            case 7:{
                for(int j=0;j<5;j++){
                    grade[j]=grades(marks,j);
                }
                cout<<"====================================================================="<<endl;
                cout<<"Student Name\t\tMarks    \tgrade\n---------------------------------------------------------------------"<<endl;
                for(int k=0;k<5;k++){
                    if(students[k]!="NV"){
                        cout<<students[k];
                        cout<<"  \t\t\t"<<marks[k]<<"     \t"<<grade[k]<<endl;
                    }
                }
                break;
            }
            case 0:{
                cout<<"====================================================================="<<endl;
                break;}
            default:{
                cout<<"input is invalid"<<endl;
                break;
            }
        }
    }
        while(num!=0);
        cout<<"        ----------Program closed successfully----------"<<endl;
    }
    else{
        cout<<"                        Cridentials are invalid!\n                            Login failed!"<<endl;
        cout<<"====================================================================="<<endl;
    }
    return 0;
}

