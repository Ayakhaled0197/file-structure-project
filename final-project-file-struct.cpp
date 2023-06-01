#include<iostream>
#include<fstream>
#include<string.h>
#define nl "\n"
#define t  "\t"
using namespace std ;
// item quantity price 




class grocery{
public:
int quantity,price ; 
char items [10] ; 
};
// Read   like cin 
// write  like cout


// write text 
void write(){
ofstream f ; 
f.open("test.txt" , ios:: out);
f << "haahha";
f.close();
}
// read text
void read(){
ifstream read ; 
read.open(/*"NAME OF FILE"*/ "grocery.txt", ios :: in );
if(read.is_open()){
char reading[12];
read.get(reading,12)  ;cout <<reading ; 
}
else{
 cout <<"the file cannot be opened";
}
}
// write records 
void write_record(){
// open file 
fstream file ;  // fstream file("grocery.txt", ios :: out | ios :: app)  it can open file too 
file.open("grocery.txt", ios :: out | ios :: app);
// info 
grocery s1 ; 
string h ;   
// to take values
do{
cout << "Enter item: ";
cin >> s1.items; 
cout << "Enter quantity: ";
cin >> s1 . quantity ; 
cout << "Enter price: ";
cin >> s1 .price ; 
file.write((char * ) & s1 , sizeof(s1) );
cout << "YES / NO ";
cin >> h ; 
}
while(h == "YES" || h == "yes"); // condition to take or stop taking values
file.close();

}
void read_record(){
grocery g1 ; 
ifstream reading ; 
reading.open("grocery.txt" , ios :: in );
if(reading.is_open()){ // is_open to check file is found or not
 cout <<"items"<<" "<< "quantity"<<" "<<  "price" <<nl ; 
 // columns 
 reading.read((char *) & g1 , sizeof(g1));
 while(!reading.eof()){ // eof to check if i reached to the end of the file or not
   cout << g1.items << "   " << g1.quantity<<"      "<< g1.price <<nl ; 
  reading.read((char *) & g1 , sizeof(g1));
 }
}
else{
cout <<"FILE NOT FOUND" << nl ;
}
}
void search(){
char search[10] ;// array to have my word to compare 
cout << "Enter the column "<< nl;
cin >> search ; 
grocery g1 ; 
ifstream  searching ; 
searching.open("grocery.txt" , ios :: in );
if(searching.is_open()){
searching.read((char*) &g1 , sizeof(g1)  );
while(!searching.eof()){
if(strcmp(search , g1.items ) == 0 ){ // when the 2 strings are same it returns 0
cout <<"items"<<" "<< "quantity"<<" "<<  "price" <<nl ; 
return void(cout << g1.items << "   " << g1.quantity<<"      "<< g1.price <<nl  );
searching.read((char *) & g1 , sizeof(g1));
}
searching.read((char*) &g1 ,sizeof(g1));
}
cout << "NOT FOUND" ;
cout << nl ;
searching.close(); 
}
else{
cout <<"FILE NOT FOUND"  <<nl ;
}
}
void update(){
char search[10] ;// array to have my word to compare 
cout << "Enter the column "<< nl;
cin >> search ; 
grocery g1 ; 
fstream  updating ; 
updating.open("grocery.txt" , ios :: in | ios :: out  );
if(updating.is_open()){
updating.read((char*) &g1 , sizeof(g1)  );
while(!updating.eof()){
if(strcmp(search , g1.items ) == 0 ){ // when the 2 strings are same it returns 0

cout <<"enter the new items instead of " << search <<nl; 
cin >> g1.items  ;

int curr_poistion =  updating.tellg(); 
int record_size = sizeof(g1);

updating.seekp(curr_poistion - record_size , ios :: beg);
updating.write((char*) &g1, sizeof(g1)) ;

updating.seekp(curr_poistion - record_size , ios :: beg);
updating.read((char*) &g1, sizeof(g1)) ;

cout <<"items"<<" "<< "quantity"<<" "<<  "price" <<nl ; 
return void(cout << g1.items << "   " << g1.quantity<<"      "<< g1.price <<nl  );

}
updating.read((char*) &g1 ,sizeof(g1));
}
cout << "NOT FOUND" <<nl ;
updating.close(); 
}
else{
cout <<"FILE NOT FOUND" <<nl;
}
}
void remove_record(){

char search[10] ;// array to have my word to compare 
cout << "Enter the column "<< nl;
cin >> search ; 
bool flag = 0 ; 
grocery g1 ; 
ifstream  old ; 
ofstream  New ; 
old.open("grocery.txt" , ios :: in );
New .open("temp.txt" , ios :: out );
if(old.is_open()){
old.read((char*) &g1 , sizeof(g1)  );
while(!old.eof()){
if( ! (strcmp(search , g1.items ) == 0) ){ // when the 2 strings are same it returns 0
New .write((char*) &g1 , sizeof((g1)));
flag = 1; 

}
old.read((char*) &g1 , sizeof(g1)  );
}
if(! flag )
return void(cout << "NOT FOUND" << nl );
old.close(); 
New.close(); 
remove("grocery.txt") ;
rename("temp.txt" ,"grocery.txt" );
}
else{
cout <<"FILE NOT FOUND" <<nl ;
}
read_record() ;
}

void accepted(){
char c;
do{
cout<< "to write press : 1" <<nl;
cout<< "to read press  : 2" << nl ;
cout<< "to search press : 3" << nl ;
cin >> c ;
switch(c){
case '1' : 
write_record();
break; 
case '2' : 
read_record();
break; 
case '3' : 
search();
break; 
case '4' :
return  ; 
}
} while(c != '4' ) ;

}




int main(){
 accepted();
}
/*string s ; cin >> s; 
int x  ; 
char search[10] ;// array to have my word to compare 
if(s == "item"){
cout << "Enter the item "<< nl;
cin >> search ; 
}
else if(s == "quantity"){
cout << "enter the quantity"<< nl;
cin >> x; 
}
else if(s == "price"){
cout << "enter the price"<< nl;
cin >> x; 
}*/
/*three ways to print 
object  << 
object.put('char")
pbject.write(pinter on  char , size )
*/


/*three ways to print 
object  << 
object.put('char")
pbject.write(pinter on  char , size )
*/