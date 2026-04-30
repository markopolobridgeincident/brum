#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;


int main(){
    srand(time(0));
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
    int enemykilled = 0;
    int spentpenize =0;
    do{
    cout << "1)\n----Bojovnik----\n=  Zivoty: 150\n=  Mana: 140\n=  Special perk: Odrazeni utoku\n\n";
    cout << "2) \n----Carodej----\n=  Zivoty: 90\n=  Mana: 200\n=  Special perk: Heal (Vyhealuje do max hp + 50 hp)\n\n";
    cout << "3)\n ----Tank----\n=  Zivoty: 250\n=  Mana: 50\n=  Special perk: Ultra utok (Da 2x vetsi damage)";
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
            cout << "Spatna hodnota!\n";
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
            zlato = zlato - cenahospoda;
            spentpenize = spentpenize + cenahospoda;
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
               spentpenize =+25;
            }  
            else if (vyberb == 2){
                pocetlo ++;
                zlato -=40;
                spentpenize =+40;
            } 
            else if (vyberb == 3){
                pocetlr ++;
                zlato -=20;
                spentpenize =+20;
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
              spentpenize =+200;
              
            }else if (vyberk == 2){
            rukavy = true;
            zivoty +=25;
            zlato -=100;
            spentpenize =+100;
            
            }else if (vyberk == 3){
                chestplate = true;
                zivoty +=80;
                zlato -=300;
                spentpenize =+300;
                
            }else if(vyberk == 4){
                gatata = true;
                zivoty +=40;
                zlato -=250;
                spentpenize =+250;
                
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
//boj s 1 enemy
    int hpenemy = 100;
    cout << "\n====Nasel jsi sveho prvniho enemaka!====";
    cout << "\n\nCus pic clovece! Rozkopu ti drzku abys vedel.";
    sleep(2);

    do{
        int vyberu;
        do{
    cout << "\nVyber utok!\n 1) Lehky (75 procent na hit)\n 2) Stredni (60 procent na hit)\n 3) Heavy (35 procent na hit)\n  Vyber: ";
    
    cin >> vyberu;
    if(vyberu <1 || vyberu >3) cout << "\nZadal jsi spatnou hodnotu!\n";
    }while(vyberu <1 || vyberu >3);
    int snautok;
    int damage;
    int cislohlasky;
    string hlaskynetrefa[] = {"Netrefils!", "Proboha! Nauc se mirit!", "Jak jsi to mohl netrefit!", "O pet metru vedle!", "Zkus to priste!"};
    if(vyberu ==1){
        snautok = rand() % 100;
        if(snautok <=75){
            damage = 1+(rand() % 35);
            sleep(1);
            cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
            hpenemy = hpenemy - damage;
        }else{
            cislohlasky = rand() % 5;
            cout << hlaskynetrefa[cislohlasky];
        }

    }else if(vyberu == 2){
        snautok = rand() % 100;
        if(snautok <=60){
            damage = 20+(rand() % 50);
            sleep(1);
            cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
            hpenemy = hpenemy - damage;
        }else{
            cislohlasky = rand() % 5;
            cout << hlaskynetrefa[cislohlasky];
        }
    }else if(vyberu == 3){
        snautok = rand() % 100;
        if(snautok <=35){
            damage =50+(rand() % 50);
            sleep(1);
            cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
            hpenemy = hpenemy - damage;
        }else{
            cislohlasky = rand() % 5;
            cout << hlaskynetrefa[cislohlasky];
        }
    }
    if(hpenemy < 0){ 
        hpenemy = 0;
        }
//na rade je enemy
    if(hpenemy !=0){
    int edamage;
    sleep(1);
    cout << "\nNa rade je enemy!\n";
    sleep(1);
    cout << "\nEnemak se rozprahuje!\n";
    edamage =1+(rand() % 60);
    sleep(1);
    cout << "A dal ti za " << edamage << "!";
    zivoty = zivoty - edamage;
    if(zivoty <=0){
        zivoty = 0;
        sleep(1);
        cout << "\n\nZemrel jsi! Ja vedel ze to nedohrajes!\n";
        cout << "====Tvoje staty====\n Zabiti enemaci: " << enemykilled << "\n Utracene penize: " << spentpenize;
        return 0;
    }
    cout << endl;
    sleep(1);
        }
//
        cout << "\n\n====Staty battlu====";
        cout << "\nTvoje HP: "<< zivoty << endl << "Mana: " << mana << endl << "Enemy HP: " << hpenemy << endl; 
    }while(zivoty != 0 || hpenemy != 0);
    cout << "Podarilo se ti zdolat enemaka! Gud job bro";
}


