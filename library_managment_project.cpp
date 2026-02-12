#include<iostream>
#include<string>
#include<fstream>
using namespace std;
ofstream file("data.txt");
//declare Multiple Arrays
struct Book {
	string title;
	string ISSN;
	string publisher;
	string cost;
	bool isIssued;
	string StudentName;
};
// add new book in file handling
void addbook(Book books[],int & n)
{	
	string title,ISSN,publisher;
	string cost;
	cout<<"Enter title:";
	getline(cin,title);
	file<<"Dated: "<<__DATE__<<endl;
	file<<"Time: "<<__TIME__<<endl;
	file<<"Title :"<<title<<endl;
	cout<<"Enter ISSN:";
	getline(cin,ISSN);
	file<<"ISSN :"<<ISSN<<endl;
	cout<<"Enter publisher:";
	getline(cin,publisher);
	file<<"Publisher :"<<publisher<<endl;
	cout<<"Enter cost:";
	cin>>cost;
	file<<"Cost :"<<cost<<endl;
	file<<"-----------------------------------"<<endl;
	cin.ignore();
	Book newbook = 	{title,ISSN,publisher,cost,false,""};
	books[n]=newbook;
	n++;
}
// Display book record
void viewBook(Book books[],int n)
{
	for(int i=0;i<n;i++){
		cout<<"Title :"<<books[i].title<<endl;
		cout<<"ISSN:"<<books[i].ISSN<<endl;
		cout<<"publisher:"<<books[i].publisher<<endl;
		cout<<"cost:"<<books[i].cost<<endl;
	}
}
// Search book
void searchBook(Book books[],int n)
{
string name;
string title;
cout<<"Enter the title of the book you want to search for:";
getline(cin,title);
for(int i=0;i<n;i++)
{
	if(books[i].title == title)
	{
	cout<<"Title:"<<books[i].title<<endl;
	cout<<"ISSN:"<<books[i].ISSN<<endl;
	cout<<"publisher:"<<books[i].publisher<<endl;
	cout<<"cost:"<<books[i].cost<<endl;
	}
}
}
//issue book and does not issue book which is already issued
void issueBook(Book books[],int n){
	string name;
	string title;
	cout<<"Enter studentName:";
	getline(cin,name);
 cout<<"Enter title:";
 getline(cin, title);
 for(int i=0;i<n;i++)
 {
  if
(books[i].title==title && !books[i].isIssued)
 {
 books[i].isIssued=true;
 books[i].StudentName=name;
 cout<<"Book issued successfully to "<< name <<endl;
 return;
  }
}
	cout<<"Sorry, the Book is not available."<<endl;
}
//delete book 
void deleteBook(Book books[],int n)
{
string title;
cout<<"Enter the book title to remove:"<<endl;
getline(cin,title);
for(int i=0;i<n;i++)
{
if(books[i].title == title)
{
cout<<"Title:"<<books[i].title<<endl;
cout<<"ISSN:"<<books[i].ISSN<<endl;
cout<<"publisher:"<<books[i].publisher<<endl;
cout<<"cost:"<<books[i].cost<<endl; 
books[i].title =true;
books[i].ISSN =true;
books[i].publisher =true;
books[i].cost =true;
cout<<"Record deleted!"<<endl;
return;
}
}
cout<<"Record not found!"<<endl;
}
int main(){
	Book books[55];
	int n=0;
	int choice;
	cout<<"######### LIBRARY MANAGEMENT SYSTEM ##########"<<endl;
	while(true){
		cout<<"================================================="<<endl;
		cout<<"############# MENU BAR ############### "<<endl;
		cout<<"Press 1 for addbook"<<endl;
		cout<<"Press 2 for viewBook"<<endl;
		cout<<"Press 3 for searchBook"<<endl;
		cout<<"Press 4 for issueBook"<<endl;
		cout<<"Press 5 for deleteBook"<<endl;
  cout<<"Press 6 for Exit"<<endl;
		cin>>choice;
		cin.ignore();
		switch(choice){
			case 1:
				addbook(books,n);
				break;
			case 2:
				viewBook(books,n);
				break;
			case 3:
				searchBook(books,n);
				break;
			case 4:
				issueBook(books,n);
				break;
			case 5:
     deleteBook(books,n);
     break;
   case 6:
				exit(0);
				break;
			default:
			cout<<"Invalid choice!\n";
			break;
		}
}
	return 0;
}
    
