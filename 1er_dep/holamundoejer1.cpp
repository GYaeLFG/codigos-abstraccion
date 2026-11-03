#include <iostream>
using namespace std;

class fundamentos {
public:
    void holaMundo() {
        cout << "Hola mundo" << endl;
    }
};

int main() {
    fundamentos app;
    app.holaMundo();
    return 0;
}
