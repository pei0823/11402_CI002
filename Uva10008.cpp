#include <iostream>
#include <string>
using namespace std;
// 1  2  3  4  5  6  7  8  9 10 11 12 13 
// A  B  C  D  E  F  G  H  I  J  K  L  M 
//14 15 16 17 18 19 20 21 22 23 24 25 26 
// N  O  P  Q  R  S  T  U  V  W  X  Y  Z
int main()
{
    int round = 0;
    cin >> round;
    string txt;
    int abc[28] = { 0 };
    
    for (int rounds = 0; rounds <= round; rounds++) {
        getline(cin, txt);
        for (int i = 0; i < txt.size(); i++) {
            if (txt[i] == 'a' || txt[i] == 'A') { abc[1]++; continue; }
            if (txt[i] == 'b' || txt[i] == 'B') { abc[2]++; continue; }
            if (txt[i] == 'c' || txt[i] == 'C') { abc[3]++; continue; }
            if (txt[i] == 'd' || txt[i] == 'D') { abc[4]++; continue; }
            if (txt[i] == 'e' || txt[i] == 'E') { abc[5]++; continue; }
            if (txt[i] == 'f' || txt[i] == 'F') { abc[6]++; continue; }
            if (txt[i] == 'g' || txt[i] == 'G') { abc[7]++; continue; }
            if (txt[i] == 'h' || txt[i] == 'H') { abc[8]++; continue; }
            if (txt[i] == 'i' || txt[i] == 'I') { abc[9]++; continue; }
            if (txt[i] == 'j' || txt[i] == 'J') { abc[10]++; continue; }
            if (txt[i] == 'k' || txt[i] == 'K') { abc[11]++; continue; }
            if (txt[i] == 'l' || txt[i] == 'L') { abc[12]++; continue; }
            if (txt[i] == 'm' || txt[i] == 'M') { abc[13]++; continue; }
            if (txt[i] == 'n' || txt[i] == 'N') { abc[14]++; continue; }
            if (txt[i] == 'o' || txt[i] == 'O') { abc[15]++; continue; }
            if (txt[i] == 'p' || txt[i] == 'P') { abc[16]++; continue; }
            if (txt[i] == 'q' || txt[i] == 'Q') { abc[17]++; continue; }
            if (txt[i] == 'r' || txt[i] == 'R') { abc[18]++; continue; }
            if (txt[i] == 's' || txt[i] == 'S') { abc[19]++; continue; }
            if (txt[i] == 't' || txt[i] == 'T') { abc[20]++; continue; }
            if (txt[i] == 'u' || txt[i] == 'U') { abc[21]++; continue; }
            if (txt[i] == 'v' || txt[i] == 'V') { abc[22]++; continue; }
            if (txt[i] == 'w' || txt[i] == 'W') { abc[23]++; continue; }
            if (txt[i] == 'x' || txt[i] == 'X') { abc[24]++; continue; }
            if (txt[i] == 'y' || txt[i] == 'Y') { abc[25]++; continue; }
            if (txt[i] == 'z' || txt[i] == 'Z') { abc[26]++; continue; }

        }
    }
    for (int i = 0; i < 27; i++) {
        int max = 0;
        int nmax= 0;
        for (int j = 1; j <= 26; j++) {
            if (abc[j] > max) {
                max = abc[j];
                nmax = j;
            }
        }
        if (max == 0)break;
        if (nmax == 1) { cout << "A ";}
        else if (nmax == 2) { cout << "B "; }
        else if (nmax == 3) { cout << "C "; }
        else if (nmax == 4) { cout << "D "; }
        else if (nmax == 5) { cout << "E "; }
        else if (nmax == 6) { cout << "F "; }
        else if (nmax == 7) { cout << "G "; }
        else if (nmax == 8) { cout << "H "; }
        else if (nmax == 9) { cout << "I "; }
        else if (nmax == 10) { cout << "J "; }
        else if (nmax == 11) { cout << "K "; }
        else if (nmax == 12) { cout << "L "; }
        else if (nmax == 13) { cout << "M "; }
        else if (nmax == 14) { cout << "N "; }
        else if (nmax == 15) { cout << "O "; }
        else if (nmax == 16) { cout << "P "; }
        else if (nmax == 17) { cout << "Q "; }
        else if (nmax == 18) { cout << "R "; }
        else if (nmax == 19) { cout << "S "; }
        else if (nmax == 20) { cout << "T "; }
        else if (nmax == 21) { cout << "U "; }
        else if (nmax == 22) { cout << "V "; }
        else if (nmax == 23) { cout << "W "; }
        else if (nmax == 24) { cout << "X "; }
        else if (nmax == 25) { cout << "Y "; }
        else if (nmax == 26) { cout << "Z "; }
        cout << max << endl;
        abc[nmax] = 0;
    }

}


//更改想法 直接用ASCLL來判斷字母 
//大寫字母 (A-Z)	65 - 90
//小寫字母 (a-z)	97 - 122
//數字 (0-9)	48 - 57
int main2(){

    char alphabet[26];//by ai 快速填入a-z
    int abc[27] = { 0 };//存入a-z的次數
    for (int i = 1; i < 27; i++) {
        alphabet[i] = 'A' + i; 
    }
    


}