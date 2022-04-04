#include <iostream>
using namespace std;

int modulo (int num, int den);
void cipher ();
void decipher ();

int main() {

    return 0;
}

int modulo (int num, int den)
{
    int rem = num % den;

    if (abs(num) == abs(den))
        return 0;
    else if (num >= 0 && den > 0 || num <= 0 && den < 0)
        return rem;
    else if ((num >= 0 && den < 0) || num <= 0 && den > 0)
        return den + rem;
    else
        return 0;
}

void cipher ()
{
    string s, enc;
    cout << "Please, enter a message to cipher: " << endl;
    getline(cin >> ws, s);

    for (int i = 0; i < s.length(); i++) {
        int x, l;
        if (s[i] >= 'A' && s[i] <= 'Z') {
            x = s[i] - 'A';
            l = modulo(5 * x + 8, 26);
            enc += char(l + 'A');
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            x = s[i] - 'a';
            l = modulo(5 * x + 8, 26);
            enc += char(l + 'a');
        } else {
            enc += s[i];
        }
    }

    cout << "Cipher: " << enc << endl;
}

void decipher ()
{
    string s, dec;
    cout << "Please, enter a message to decipher: " << endl;
    getline(cin >> ws, s);

    for (int i = 0; i < s.length(); i++) {
        int y, l;
        if (s[i] >= 'A' && s[i] <= 'Z') {
            y = s[i] - 'A';
            l = modulo(21 * (y - 8), 26);
            dec += char (l + 'A');
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            y = s[i] - 'a';
            l = modulo(21 * (y - 8), 26);
            dec += char (l + 'a');
        } else {
            dec += s[i];
        }
    }

    cout << "Decipher: " << dec << endl;
}
