#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
// void aya_khaled(){
//     ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r" , stdin), freopen("output.txt" ,"w" , stdout);
//     #endif
// }

class student{
    public:
    int age, id;
    char name[10];
};

void write_text(){
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////// ================================ write into the file =========================== /////////////
/*=======nonexist = create && exist with old content = create & del old content & write new ===========*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////

    ofstream f;
    f.open("test.txt" , ios::out);
    f<<"hello world";
    f.close();
}

void write_with_appeand(){
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////// ========================= write into the file & save the old content  ===================================== /////////////
/*======= ios::app = appeand means to write in existed file with no data loss if found && ios::out if not exist create ===========*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ofstream f;
    f.open("test.txt" , ios::out | ios::app);
    f<<"hello world";
    f.close();
}

// void read_file(){
//         ifstream in;
//         char ch , str[10];
// if(in.is_open()){
//     in.open("test.txt", ios::in);
//     in>>str;
//     cout<< str <<endl;
//     in.get(ch);
//     cout<< ch << endl;
//     in.get(str,10);
//     cout<< str <<endl;
// }
// else{
//     cout<<"can't specify the file";
// }
// }

void student_records(){
    student s1;
    fstream fileopen;
    char c;
    fileopen.open("student.txt", ios::out | ios::app);
    do{
        cout<<"enter the student id: ";
        cin>> s1.id;
        cout<<"enter the student name: ";
        cin>> s1.name;
            cout<<"enter the student age: ";
        cin>> s1.age;
        fileopen.write((char*)&s1 , sizeof(s1)); //serialization
        cout<<"enter records again?[y/n]";
        cin>>c;

    }while(c=='y');

    fileopen.close();
}

void search_student(){
            student s1;
        ifstream in;
        char str[10];
        bool found = false;
        cout<<"enter the name"<<endl;
        cin>>str;
        in.open("student.txt", ios::in);
        if(in.is_open()){
            cout<<"ID/name/age"<<endl;
            in.read((char*) &s1 , sizeof(s1));
            while(!in.eof()){
                if(strcmp(str , s1.name)==0){
                    cout<<s1.id << "\t" << s1.name<<"\t"<<s1.age<<endl;
                    found = true;
                    //break;
                }
                    in.read((char*) &s1 , sizeof(s1));
            }
                if(!found)
                        cout<<"name not found"<<endl;
                        
                        in.close();
        }
        else{
            cout<<"cant specify the file";
        }
}

int length_og_file(){
    ifstream in("test.txt");
    if(in.is_open()){
            in.seekg(0 , ios::end);
            cout<<"the length of the file is : "<<in.tellg();
        }
}

int main(){
    // aya_khaled();
    char ch;
    ifstream in("test.txt" , ios::in);
    ofstream out("copytest.txt" , ios::out);
    if(in.is_open()){
        while (in.get(ch))
        {
            out.put(ch);
            in.close();
            out.close();
        }
        
    }


    return 0;
}