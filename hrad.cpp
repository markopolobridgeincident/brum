#include <iostream>
using namespace std;

int main(){
    cout << "=========Vitej do hry!=========\n\n";
    cout << "Vyber si postavu:\n ";
    int zivoty = 100;
    int mana = 100
    int utok = 5;
//vesnice
    cout << "\n\nVybirani postavy ti zabralo cely den, a tak uz je vecer.\n==== Po nejake dobe hledani jsi nasel vesnici! ====\n Zde si muzes doplnit zasoby, vylepsit si postavu, nebo doplnit energii na tvoje dobrodruzstvi!\n";
    cout << "\n 1) Odpocinek v nedaleke hospode - Doplni ti manu.\n 2) Navstiveni baby korenarky - zvysi ti max. manu.\n 3) Bez za kovarem - zvysi ti max. zivoty.\n Zvol moznost: ";
    int volbav;
    int cenahospoda = 50;

    cin >> volbav;
    switch(volbav){
        case 1:
            cout << "\nZaplatil jsi hospodskemu " << cenahospoda << " zlata, aby te nechal prespat v hospode.";
            cout << "\nRano jsi se probudil odpocaty a muzes pokracovat na sve ceste.";
            zivoty = 100;
            mana = 100;
            break;

    }




}

