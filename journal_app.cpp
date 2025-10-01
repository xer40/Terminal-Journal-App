#include <iostream>
#include <fstream>
#include <ctime>
#include <random>
#include <string>

using namespace std;

int main() {
    //initializing variables
    time_t currentTime = time(0);
    char* sTime = ctime(&currentTime);
    int min=1,max=4;
    random_device device;
    mt19937 rand(device());
    uniform_int_distribution<> distribution(min,max);
    int randNum = distribution(rand);

    //open file and get ready for input
    ofstream file;
    file.open("journal.txt",ios::app);

    //make sure file is actually open and then get title and entry
    if(file.is_open()){
        file<<sTime<<endl;
        string title,entry;
        entry.reserve(100000);
        cout<<"Enter a title for this entry: ";
        getline(cin,title);
        file<<title<<endl<<endl;
        switch (randNum) {
            case 1:
                cout<<"Great Choice! ";
                break;
            case 2:
                cout<<"That's perfect! ";
                break;
            case 3:
                cout<<"Yeah, checks out. ";
                break;
            case 4:
                cout<<"Works for me. ";
                break;
            default:
                break;
        }
        cout<<endl<<"Lets hear what you have to say..."<<endl;
        getline(cin,entry);
        file<<entry<<endl<<endl;
    }
    file.close();
}
