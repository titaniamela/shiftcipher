#include<iostream>
#include<string.h>

using namespace std;

void enkripsi()
{
    string plainteks, cipherteks;
    int i, k;
    char c;

    cout<<"Masukkan pesan : ";
    cin.ignore(); getline (cin, plainteks);
    cout<<"Masukkan K      : "; cin >> k;
    cipherteks = " ";

    for (i=0; i < plainteks.length(); i++)
    {
        c = plainteks[i];
        if (isalpha(c))
        {
            c = toupper(c);
            c = c - 65;
            c = (c + k) % 26;
            c = c + 65;
        }
        cipherteks = cipherteks + c;
    }
    cout << "cipherteks : "<<cipherteks<<endl;
}

void dekripsi()
{
    string plainteks, cipherteks;
    int i, k;
    char c;

    cout<<"Ketikan cipherteks : ";
    cin.ignore(); getline (cin, cipherteks);
    cout<<"Masukkan K          : "; cin>>k;
    plainteks = "";

    for (i=0; i<cipherteks.length(); i++)
    {
        c = cipherteks[i];
        if (isalpha(c))
        {
            c = toupper(c);
            c = c - 65;
            if (c - k < 0)
                c = 26 + (c - k);
            else
                c = (c - k) % 26;
            c = c + 65;
            c = tolower(c);
        }
        plainteks = plainteks + c;
    }
    cout<<"plainteks : "<<plainteks<<endl;
}

int main ()
{
    int pil;
    bool stop;
    stop = false;

    while (!stop)
    {
        cout<<endl;
        cout<<"======================================="<<endl;
        cout<<"Program Shift Cipher"<<endl;
        cout<<"Menu : "<<endl;
        cout<<"1. Enkripisi "<<endl;
        cout<<"2. Dekripsi "<<endl;
        cout<<"Pilih menu : "; cin>>pil;
        switch(pil)
        {
            case 1 : enkripsi();break;
            case 2 : dekripsi();break;
        }
    }
}

