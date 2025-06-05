#include <iostream>
#include <string>
using namespace std;

class Decoder {
private:
    string code;
public:
    Decoder(string code) {
        this->code = code;
    }
    string get_decode() {
        string decode = "", temp = "";
        for (int i = 0; i < code.length(); i++) {
            if (code[i] >= '1' && code[i] <= '9') {
                int times = code[i] - '0';
                for (int j = 0; j < times; j++) {
                    decode += temp;
                }
                temp = "";
            } else {
                temp += code[i];
            }
        }
        return decode;
    }
};

int main() {
    Decoder d("A3BB2CCC2");
    cout << d.get_decode();
    return 0;
}
