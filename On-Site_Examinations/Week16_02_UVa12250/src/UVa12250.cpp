#include <iostream>
#include <string>
using namespace std;

int main()
{
    string eng = "HELLO";
    string spa = "HOLA";
    string ger = "HALLO";
    string fre = "BONJOUR";
    string ita = "CIAO";
    string rus = "ZDRAVSTVUJTE";
    int count = 1;
    while (true) {
        string in;
        cin >> in;
        if (in == "#")break;
        if (count != 1)cout << endl;
        cout << "Case " << count << ": ";
        if (in == eng) cout << "ENGLISH";
        else if (in == spa) cout << "SPANISH";
        else if (in == ger) cout << "GERMAN";
        else  if (in == fre) cout << "FRENCH";
        else if (in == ita) cout << "ITALIAN";
        else if (in == rus) cout << "RUSSIAN";
        else cout << "UNKNOWN";
        count++;
    }
    //Case 1: ENGLISH
}//12250