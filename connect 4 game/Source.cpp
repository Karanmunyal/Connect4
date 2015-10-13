#include<iostream>
using namespace std;

char place[6][7];
void display();
void display(){
	
		cout << " 1   2   3   4   5   6   7\n";
	
		for (int a = 0; a <= 5; a++)
			
		{
		
				for (int b = 0; b <= 6; b++) cout << char(218) << char(196) << char(191) << " ";
					cout << '\n';
			
				for (int b = 0; b <= 6; b++) cout << char(179) << place[a][b] << char(179) << " ";
			
				cout << '\n';
			
				for (int b = 0; b <= 6; b++) cout << char(192) << char(196) << char(217) << " ";
			
				cout << '\n';
			
		}
	
}
void main()
{
	display();
}