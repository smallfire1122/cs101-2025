#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class myString 
{

};

class ReadClass {
public:
    vector<string> classname;

    void showClass() {
        ifstream in("Q3.cpp");
        string line;
        while (getline(in, line)) {
            if (line.find("class") == 0) {
                classname.push_back(line.substr(0, line.find("{"))); 
            }
        }
        cout << classname.size() << endl;
        for (const string& name : classname)
            cout << name << endl;
    }
};

int main() {
    ReadClass r;
    r.showClass();
    return 0;
}

