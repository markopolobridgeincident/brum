#include <iostream>
using namespace std;


int main(){
    cout << "=========Vitej do hry!=========\n\n";
    cout << "Vyber si postavu:\n ";

    int zivoty;
    int mana;
    int utok;
    int zlato;
    int vpostavy;
    bool cheal;
    bool odraz;
    bool dvadamage;
    do{
    cout << "1)\n----Bojovnik----\n=  Zivoty: 150\n=  Mana: 140\n=  Special perk: Odrazeni utoku\n\n";
    cout << "2) \n----Carodej----\n=  Zivoty: 90\n=  Mana: 200\n=  Special perk: Heal (Vyhealuje do max hp + 50 hp)\n\n";
    cout << "3)\n ----Tank----\n= Zivoty: 250\n=  Mana: 50\n=  Special perk: Ultra utok (Da 2x vetsi damage)";
    cout << "\n\n Vyber: ";
    cin >> vpostavy; 
    cout << endl;
    switch (vpostavy){
        case 1:
            cout << "Zvolen Bojovnik!";
            zivoty = 150;
            mana = 140;
            odraz = true;
            break;
        case 2:
            cout << "Zvolen Carodej!";
            zivoty = 90;
            mana = 200;
            cheal = true;
            break;
        case 3:
            cout << "Zvolen Tank!";
            zivoty = 250;
            mana = 50;
            dvadamage = true;

            break;
        default:
            cout << "Spatna hodnota!";
            break;
    }
    }while(vpostavy < 1 || vpostavy > 3);
//vesnice
    cout << "\n\nVybirani postavy ti zabralo cely den, a tak uz je vecer.\n";
    cout << "\n==== Po nejake dobe hledani jsi nasel vesnici! ====\n Zde si muzes doplnit zasoby, vylepsit si postavu, nebo doplnit energii na tvoje dobrodruzstvi!\n";

    int volbav;
    int cenahospoda = 50;
    int pocetls = 0;
    int pocetlo = 0;
    int pocetlr = 0;
    bool gatata = false;
    bool chestplate = false;
    bool helma = false;
    bool rukavy = false;
    bool namesti = true;
    do{
    cout << "\n 1) Odpocinek v nedaleke krcme\n 2) Navstiveni baby korenarky\n 3) Bez za kovarem\n 4) Pokracovani pres noc za dalsim dobrodruzstvim.\n Zvol moznost: ";
    cin >> volbav;
    switch(volbav){
        case 1:
            cout << "\nZaplatil jsi hospodskemu " << cenahospoda << " zlata, aby te nechal prespat v hospode.";
            cout << "\nRano jsi se probudil odpocaty a muzes pokracovat na sve ceste.";
            zivoty = 100;
            mana = 100;
            cenahospoda += 40;
            break;
        case 2:
            cout << "\n=== Prisel jsi k babce korenarce ===\n";
            cout << " \nAhoj poutniku! Koukni, co mam v nabidce:\n 1) Lektvar sily - Prida ti silu v boji | 25 zlata\n 2) Lektvar oziveni - ozivi te v boji | 40 zlata\n 3) Lektvar regenerace - doplni ti manu | 20 zlata \n";
            int vyberb;
            do{
            cout << "vyber: ";
            cin >> vyberb;
            if(vyberb == 1){
               pocetls ++;
               zlato -=25;
            }  
            else if (vyberb == 2){
                pocetlo ++;
                zlato -=40;
            } 
            else if (vyberb == 3){
                pocetlr ++;
                zlato -=20;
            } 
            }while(vyberb <1 || vyberb >3);
            break;
        case 3:
            cout << "=== Prisel jsi do kovarny ===";
            cout << "Hledas nejakou vyzbroj poutniku? Koukni na moji nabidku!\n 1) Zelezna helma - prida ti 40 hp\n  CENA: 200\n\n 2) Zelezne rukavy - prida ti 25 hp\n  CENA: 100\n\n 3) Zelezny chestplate - prida ti 80 hp\n  CENA: 300\n 4) Zelezne nohavice - prida ti 40 hp\n  CENA: 250\n\n 5) Odchod\n\nVyber: ";
            int vyberk;
            do{
            cin >> vyberk;
            if(vyberk == 1){
              helma = true;
              zivoty +=40;
              zlato -=200;
              
            }else if (vyberk == 2){
            rukavy = true;
            zivoty +=25;
            zlato -=100;
            
            }else if (vyberk == 3){
                chestplate = true;
                zivoty +=80;
                zlato -=300;
                
            }else if(vyberk == 4){
                gatata = true;
                zivoty +=40;
                zlato -=250;
                
            }else if(vyberk == 5){
                cout << "\nZase navidenou!";
                namesti = true;
            }else{
                cout << "Musis si neco vybrat!";
            }
            }while(vyberk <1 || vyberk >5);
            if(vyberk >=1 && vyberk <=4){ 
                cout << "\nNakup uspesny!\n";
            }
            break;
        default:
            namesti = false;
            cout << "Pokracujes tedy dale.\n";
    }

    }while(namesti == true);


}


