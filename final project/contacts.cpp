#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

struct person{
	string name;
	string tel;
	string email;

};

int main(){

	struct person p[10];
	struct person q[10];
	char a;

	cout<< "add: "<<'\t'<<"1"<<endl;
	cout<< "save: "<<'\t'<<"2"<<endl;
	cout<< "search: "<<"3"<<endl;
	cout<< "exit: "<<'\t'<<"4"<<endl;

	while(1){

	cout << "enter the number: ";
	int d;
	cin >> d;

	switch(d){
		case 1:
		{
			
			for(int i=0 ; i<10 ; i++){

                cout << "name("<<i+1<<"): ";
				cin >> p[i].name;
				cout <<"tel("<<i+1<<"): ";
				cin >> p[i].tel;
				cout << "email("<<i+1<<"): ";
				cin >> p[i].email;
        	
			}

			cout <<"do you want to add 11th contact? (y/n): ";
			
			cin>> a;
			if (a == 'y'){
				
				cout << "name(11): ";
				cin >> q[0].name;
				cout <<"tel(11): ";
				cin >> q[0].tel;
				cout << "email(11): ";
				cin >> q[0].email;

			}
			
			break;
		}
		
		case 2:
		{
			ofstream out;
			out.open("file1.txt");
			
			for(int i=0; i<10; i++){
				out << p[i].name <<"\t"<< p[i].tel <<"\t"<< p[i].email <<endl;
			}
			out.close();
			
			if(a == 'y'){
				out.open("file1.txt" , ios::app);
				out << q[0].name <<"\t"<< q[0].tel <<"\t"<< q[0].email <<endl;
				out.close();
			}
			
			break;
		}

		case 3:
		{
			ifstream in;
			in.open("file1.txt");

			cout << "Enter the name for searching in the list: ";
			string s;
			cin >> s;
			int n=0;
			while(s[n] != '\0'){
				n++;
			}
			bool flag;

			string name;
			string tel;
			string email;

			while(in >> name >> tel >> email){

				for(int i=0 ; i<n  ; i++){
					if(name[i] == s[i]){
						flag = 1 ;
					}
					else{
						flag = 0;
						break;
					}
			 	}

				if(flag == 1){
					cout << name <<'\t'<< tel <<'\t'<< email <<endl;
					break;
				}

			}

			if (flag==0){
				cout <<"Not Found!" <<endl;
			}

			in.close();
			break;
		}

		case 4:
		{
			exit(1);
		}

	}

	}

	return 0;
}
