#include <iostream>
#include <fstream>
#include <climits>
#include <sstream>
using namespace std;

struct stud{
    string name;
    int roll;
    string address;
};

class Students {
    public:
    // class functions
    fstream file;
    Students(){
        file.open("studentsdb.txt", ios::out | ios::trunc);
        file << "Roll No" << "\t\t" << "Name" << "\t\t" << "Address" << endl;
        file.close();
    }
    void displayData();
    void insertData();
    void deleteData();
    string searchData(int roll);
    void modifyData();
    void copyToOriginal();
};

void Students::insertData(){
    file.open("studentsdb.txt", ios::out | ios::app);
    cout << "Enter the number of students to enter: ";
    int n; 
	cin >> n;
    for(int i = 0; i < n; i++)
	{
        stud s;
        cout << "Roll No: "; 
		cin >> s.roll;
        cout << "Name: "; 
		cin >> s.name;
        cout << "Address: "; 
		cin >> s.address;
        cout << endl;
        file << s.roll << "\t\t" << s.name << "\t\t" << s.address << endl;
    }
    file.close();
}

void Students::displayData(){
    file.open("studentsdb.txt");
    while(file){
        string line;
        getline(file, line);
        cout << line << endl;
    }
    file.close();
}

string Students::searchData(int roll){
    file.open("studentsdb.txt");
    while(file){
        string line;
        getline(file, line);
        stringstream str(line);
        string temp;
        string arr[3];
        for(int i = 0; i < 3; i++)
		{
            str >> temp;
            arr[i] = temp;
        }
        if(arr[0] == to_string(roll))
		{
            return line;
        }
    }
    return "-1";
    file.close();
}

void Students::copyToOriginal(){
    fstream tempFile;
    tempFile.open("tempdb.txt");
    file.open("studentsdb.txt", ios::out | ios::trunc);
    while(tempFile){
        string line;
        getline(tempFile, line);
        file << line << endl;
    }
    tempFile.close();
    file.close();
}

void Students::modifyData(){
    cout << "Enter the roll no to modify: ";
    int roll; cin >> roll;
    string result = searchData(roll);
    if(result == "-1"){
        cout << "Roll Not Found!" << endl;
    } else {
        cout << "The current data is: " << endl;
        cout << result << endl << endl;
        cout << "Enter the new data: " << endl;
        stud s;
        cout << "Roll No: "; cin >> s.roll;
        cout << "Name: "; cin >> s.name;
        cout << "Address: "; cin >> s.address;
        cout << endl;
        file.close();
        fstream tempFile;
        file.open("studentsdb.txt");
        tempFile.open("tempdb.txt", ios::out | ios::trunc);
        while(file){
            string line;
            getline(file, line);
            stringstream str(line);
            string temp;
            string arr[3];
            for(int i = 0; i < 3; i++){
                str >> temp;
                arr[i] = temp;
            }
            if(arr[0] == to_string(roll)){
                tempFile << s.roll << "\t\t" << s.name << "\t\t" << s.address << endl;
            } else {
                tempFile << line << endl;
            }
        }
        tempFile.close();
        file.close();
        copyToOriginal();
    }
}

void Students::deleteData(){
    cout << "Enter the roll no to delete the record: ";
    int roll; cin >> roll;
    string result = searchData(roll);
    if(result == "-1"){
        cout << "Roll Not Found!" << endl;
    } else {
        cout << "The current data is: " << endl;
        cout << result << endl << endl;
        file.close();
        fstream tempFile;
        file.open("studentsdb.txt");
        tempFile.open("tempdb.txt", ios::out | ios::trunc);
        while(file){
            string line;
            getline(file, line);
            stringstream str(line);
            string temp;
            string arr[3];
            for(int i = 0; i < 3; i++){
                str >> temp;
                arr[i] = temp;
            }
            if(arr[0] != to_string(roll)){
                tempFile << line << endl;
            }
        }
        tempFile.close();
        file.close();
        copyToOriginal();
    }
}

int main(){
    Students studDB;
    bool flag = true;
    while(flag){
        cout << "1. Insert Student Data" << endl;
        cout << "2. Display Student Database" << endl;
        cout << "3. Delete Student Record" << endl;
        cout << "4. Modify Student Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        int choice; cin >> choice;
        cout << endl;
        switch(choice){
            case 1:
                studDB.insertData();
                break;
            case 2:
                studDB.displayData();
                break;
            case 3:
                studDB.deleteData();
                cout << "Student Record deleted successfully..." << endl;
                break;
            case 4:
                studDB.modifyData();
                cout << "Student Record modified successfully..." << endl;    
                break;
            default:
                flag = false;
        }
    }
    cout << "Program Exited!" << endl;
    return 0;
}
