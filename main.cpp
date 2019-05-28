//Kūrė Dominykas Rakūnas :D
#include <bits/stdc++.h>

using namespace std;

string convert(int R, int G, int B); //konvertuoja visus
string convert(int color); //konvertuoja po viena

int main()
{
    ifstream in("U1.txt");
    ofstream out("U1rez.txt");

    int rows;
    int colms;
    int R, G, B;

    in>>rows;
    in>>colms;

    for(int i=0; i<rows; i++){ // kiekviena cikla veda is naujos eilutes
        for(int j=0; j<colms; j++){ // kiekviena cikla desimtaini koda konvertuoja i 16-taini
            in>>R>>G>>B;
            out<<convert(R, G, B); //iraso koda i faila
            if(j+1<colms){//atskiria kodus, jei ne prie pabaigos
                out<<";";
            }
        }
        out<<endl;
    }
    in.close();
    out.close();
    return 0;
}
string convert(int R, int G, int B){
    return convert(R)+convert(G)+convert(B); //konvertuoja po viena ir grazina ju suma
}
string convert(int color){
    stringstream name;
    int first;
    int second;
    switch(color/16){ //konvertuoja i 16-taini
        case 10:
            return "AA";
        break;
        case 11:
            return "BB";
        break;
        case 12:
            return "CC";
        break;
        case 13:
            return "DD";
        break;
        case 14:
            return "EE";
        break;
        case 15:
            return "FF";
        break;
        default: //jei uz ribu
            first = color/16; //tai gauna sveika dali
            second = color%16; //ir liekana
            name<<first<<second; // juos iraso i stringstream
            return name.str(); //ir tada konvertuoja i string
        break;
    }
}
