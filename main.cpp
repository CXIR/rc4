
#include <iostream>
#include "src/RC4.h"
#include "stdio.h"
#include <string>

using namespace std;

int main() {

    string content = "";
    string key = "";

    cout << "texte en clair " << endl;
    cin >> content;

    cout << "entrer la cle" << endl;
    cin >> key;

    RC4 rc4(content, key);
    rc4.ksa();

    cout << "resultat" << endl;
    cout << rc4.prga();

    return 0;
}