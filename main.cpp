
#include <iostream>
#include "src/RC4.h"
#include "src/FileManager.h"
#include "stdio.h"
#include <string>

using namespace std;

int main() {

    string content = "";
    string key = "";
    string path = "";
    string file_path = __FILE__;
    string dir_path = file_path.substr(0, file_path.rfind("/"));
    path = dir_path + "/src/file.txt";

    cout << "entrer la cle" << endl;
    cin >> key;

    FileManager fileManager(path);
    cout << "contenu du fichier" << endl;

    content = fileManager.read();
    cout << content << endl;

    RC4 rc4(key);
    rc4.setContent(content);
    rc4.ksa();

    cout << "cryptage en cours" << endl;
    //fileManager.write("banana");
    fileManager.write(rc4.prga());

    cout << "contenu du fichier" << endl;
    content = fileManager.read();
    cout << content << endl;

    //rc4.setContent(content);
    //rc4.ksa();

    cout << "decryptage en cours" << endl;
    //fileManager.write(rc4.prga());

    cout << "contenu du fichier" << endl;
    content = fileManager.read();
    cout << content << endl;

    return 0;
}