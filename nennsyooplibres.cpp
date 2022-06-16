

#include <iostream>
#include <string>
using namespace std;

class library_user {
protected:
	string fio;
	int NumberTicket;
	string faculty;
	string Birthday;
	string telephone;
public:
	library_user() {
		fio = "";
		NumberTicket = 0;
		faculty = "";
		Birthday = "";
		telephone = "";
	}
	library_user(string fio, int Number, string faculty, string Birthday, string telephone) {
		this->fio = fio;
		this->NumberTicket = Number;
		this->faculty = faculty;
		this->Birthday = Birthday;
		this->telephone = telephone;

	}
	library_user(const library_user& user) {
		this->fio = user.fio;
		this->NumberTicket = user.NumberTicket;
		this->faculty = user.faculty;
		this->Birthday = user.Birthday;
		this->telephone = user.telephone;

	}

	~library_user() {

	}

};


class list_of_users : library_user{

	static int size;
public:

	list_of_users() :library_user() {

	}
	list_of_users(string fio, int Number, string faculty, string Birthday, string telephone) : library_user(fio, Number, faculty, Birthday, telephone){
		size++;

	}
	void SetList(string fio, int Number, string faculty, string Birthday, string telephone) {
		this->fio = fio;
		this->NumberTicket = Number;
		this->faculty = faculty;
		this->Birthday = Birthday;
		this->telephone = telephone;
	}
	string GetName() {
		return fio;
	}
	static int Size() {
		return size;
	}
	
	void print(list_of_users arr, int n);

	~list_of_users() {
	}

};
void self(list_of_users* arr, int n);


int list_of_users::size = 0;
void self(list_of_users* arr, int n) {
	for (int i = 0; i < n; ++i) {
		list_of_users a;
		int Num;
		string fio, fac, birt, tel;
		cout << i + 1 << "St: " << endl;
		cin >> fio >> Num >> fac >> birt >> tel;
		a.SetList(fio , Num, fac, birt, tel);
		arr[i] = a;
	}
}
void list_of_users::print(list_of_users arr, int n) {
	cout << arr.fio << "\t"  << arr.NumberTicket << "\t" <<  arr.faculty << "\t" << arr.Birthday << "\t" << arr.telephone << endl;



}
void search(string name, list_of_users* arr, int n) {
	for (int i = 0; i < n; ++i) {
		if (arr[i].GetName() == name) {
			arr[i].print(arr[i], n);
		}
	}

}



int main()
{
	int n;
	cin >> n;
	list_of_users* arr = new list_of_users[n];
	self(arr, n);
	for (int i = 0; i < n; ++i) {
		arr[i].print(arr[i], n);
	}
	cout << "search: " << endl;
	string name;
	cin >> name;
	search(name, arr, n);

	delete[]arr;
	
}

/*
Ivan 22 III 13.02.2003 89113615677
Pavel 32 RII 23/04/2003 89115755677
Roman 10 ITT 30/01/2000 89275755677
*/