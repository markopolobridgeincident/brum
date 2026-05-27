#include <iostream>
#include <ctime>
#include <unistd.h>
using namespace std;


int main(){
    srand(time(0));
    cout << "=========Vitej do hry;\n";
    cout << "Vyber si postavu:\n ";

    int zivoty;
    int mana;
    int utok;
    int zlato =0;
    int vpostavy;
    bool cheal;
    bool odraz;
    bool dvadamage;
    int enemykilled = 0;
    int spentpenize =0;
    int xp = 0;
    int zlatosance;
    do{
    cout << "1)\n----Bojovnik----\n=  Zivoty: 150\n=  Mana: 140\n=  Special perk: Odrazeni utoku\n\n";
    cout << "2) \n----Carodej----\n=  Zivoty: 90\n=  Mana: 200\n=  Special perk: Blesk (Zasahne vsechny enemy najednou)\n\n";
    cout << "3)\n----Tank----\n=  Zivoty: 250\n=  Mana: 100\n=  Special perk: Ultra utok (Da 2x vetsi damage)";
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
            mana = 100;
            dvadamage = true;

            break;
        default:
            cout << "Spatna hodnota!\n";
            break;
    }
    }while(vpostavy < 1 || vpostavy > 3);
//vesnice
    
    cout << "\n\nVybirani postavy ti zabralo cely den, a tak uz je vecer.\n";
    sleep(2);
    cout << "\n==== Po nejake dobe hledani jsi nasel vesnici! ====\n Zde si muzes doplnit zasoby, vylepsit si postavu, nebo doplnit energii na tvoje dobrodruzstvi!\n";
    sleep(2);
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
        if(zlato >=cenahospoda){
            cout << "\nZaplatil jsi hospodskemu " << cenahospoda << " zlata, aby te nechal prespat v hospode.";
            cout << "\nRano jsi se probudil odpocaty a muzes pokracovat na sve ceste.";
            zivoty = 100;
            mana = 100;
            zlato = zlato - cenahospoda;
            spentpenize = spentpenize + cenahospoda;
            cenahospoda += 40;
            }else{
                cout << "\nNemas dostatek zlata! Padej pryc!\n";
                sleep(1);
            }
            break;
        case 2:
            cout << "\n=== Prisel jsi k babce korenarce ===\n";
            cout << " \nAhoj poutniku! Koukni, co mam v nabidce:\n 1) Lektvar sily - Prida ti silu v boji | 25 zlata\n 2) Lektvar oziveni - ozivi te v boji | 40 zlata\n 3) Lektvar regenerace - doplni ti manu | 20 zlata \n";
            int vyberb;
            do{
            cout << "vyber: ";
            cin >> vyberb;
            if(vyberb == 1){
                if(zlato >=25){
               pocetls ++;
               zlato -=25;
               spentpenize =+25;
               }else{
                cout << "\nNemas dostatek zlata! Padej pryc!\n";
                sleep(1);
               }
            }  
            else if (vyberb == 2){
                if(zlato >=40){
                pocetlo ++;
                zlato -=40;
                spentpenize =+40;
                }else{
                    cout << "\nNemas dostatek zlata! Padej pryc!\n";
                    sleep(1);
                }
            } 
            else if (vyberb == 3){
                if(zlato >= 20){
                pocetlr ++;
                zlato -=20;
                spentpenize =+20;
                }else{
                    sleep(1);
                    cout << "\nNemas dostatek zlata! Padej pryc\n";
                    sleep(1);
                }
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
                if(zlato >=200){
                    cout << "Zpracovani transakce";
                    sleep(1);
                    cout << "\nNakup uspesny!\n";
                helma = true;
                zivoty +=40;
                zlato -=200;
                spentpenize =+200;
                }else cout << "\nNemas dostatek zlata! Padej pryc!\n";
                sleep(1);
              
            }else if (vyberk == 2){
                if(zlato >=100){
                    cout << "Zpracovani transakce";
                    sleep(1);
                    cout << "\nNakup uspesny!\n";
                    rukavy = true;
                    zivoty +=25;
                    zlato -=100;
                    spentpenize =+100;
            }else cout << "\nNemas dostatek zlata! Padej pryc!\n";
            sleep(1);
            
            }else if (vyberk == 3){
                if(zlato >=300){
                    cout << "Zpracovani transakce";
                    sleep(1);
                    cout << "\nNakup uspesny!\n";
                chestplate = true;
                zivoty +=80;
                zlato -=300;
                spentpenize =+300;
                }else cout << "\nNemas dostatek zlata! Padej pryc!\n";
                sleep(1);
            }else if(vyberk == 4){
                if(zlato >=250){
                    cout << "Zpracovani transakce";
                    sleep(1);
                    cout << "\nNakup uspesny!\n";
                gatata = true;
                zivoty +=40;
                zlato -=250;
                spentpenize =+250;
                }else cout << "\nNemas dostatek zlata! Padej pryc!\n";
                sleep(1);
            }else if(vyberk == 5){
                cout << "\nZase navidenou!";
                namesti = true;
            }else{
                cout << "Musis si neco vybrat!";
            }
            }while(vyberk <1 || vyberk >5);
            break;
        default:
            namesti = false;
            cout << "Pokracujes tedy dale.\n";
        }   
    }while(namesti == true);
//konec vesnice
    int edamage1;
    int edamage2;
    int edamage3;
    bool odrazedlo = false;
    int hpenemy1 = 100;
    int vyberu;
    bool chciplnamanu = false;
    bool attack = false;
    int snautok;
    int damage = 0;
    int cislohlasky;
    int hpenemy2 = 100;
    int hpenemy3 = 100;
    string hlaskynetrefa[] = {"Netrefils!", "Proboha! Nauc se mirit!", "Jak jsi to mohl netrefit!", "O pet metru vedle!", "Zkus to priste!"};
//boj s 1 enemy
    
    
    cout << "\n====Nasel jsi sveho prvniho enemaka!====";
    cout << "\n\nCus pic clovece! Rozkopu ti drzku abys vedel.";
    sleep(1);
    
        
        
        cout << "\n\n====Staty battlu====";
        cout << "\nTvoje HP: "<< zivoty << endl << "Mana: " << mana << endl << "Enemy HP: " << hpenemy1 << endl;
        sleep(1);
        cout << "\nVyber utok!\n 1) Lehky (75 procent na hit; - 15 many)\n 2) Stredni (60 procent na hit; -25 many)\n 3) Heavy (35 procent na hit; -40 many)\n";
            if(odraz == true){
                cout << " 4) Odrazeni utoku (odrazi pristi enemy utok; -60 many)\n";
            }else if (cheal == true){
                cout << " 4) Blesk (Zasahne vsechny enemy najednou heavy utokem (50 procent na hit); -80 many)\n";
            }else if(dvadamage == true){
                cout << " 4) Ultra utok (2x damage z predesleho utoku (50 procent na hit); - 60 many)\n";
            }
//chcipl na manu
    
    if(mana <=0 && zivoty >0){
        chciplnamanu = true;
    }
    
if(chciplnamanu == false){
do{   
    do{
    cout << "Vyber: ";
    cin >> vyberu;
    if(vyberu <1 || vyberu >4) cout << "\nZadal jsi spatnou hodnotu!\n";
    }while(vyberu <1 || vyberu >4);
    
    
    if(vyberu ==1){
        if(mana >=15){
            mana = mana -15;
        snautok = rand() % 100;
        attack = true;
        if(snautok <=75){
            damage = 1+(rand() % 35);
            sleep(1);
            cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
            hpenemy1 = hpenemy1 - damage;
        }else{
            cislohlasky = rand() % 5;
            cout << hlaskynetrefa[cislohlasky];
        }
        }else{
            cout << "Nedostatek many!";
        }

    }else if(vyberu == 2){
        if(mana >=25){
            attack = true;
            mana = mana -25;
        snautok = rand() % 100;
        if(snautok <=60){
            damage = 20+(rand() % 50);
            sleep(1);
            cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
            hpenemy1 = hpenemy1 - damage;
        }else{
            cislohlasky = rand() % 5;
            cout << hlaskynetrefa[cislohlasky];
        }
        }else{
            cout << "Nedostatek many!";
        }
    }else if(vyberu == 3){
        if(mana >=40){
            attack = true;
            mana = mana -40;
        snautok = rand() % 100;
        if(snautok <=35){
            damage =50+(rand() % 50);
            sleep(1);
            cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
            hpenemy1 = hpenemy1 - damage;
        }else{
            cislohlasky = rand() % 5;
            cout << hlaskynetrefa[cislohlasky];
        }
        }else{
            cout << "Nedostatek many";
        }
    }else if(vyberu == 4){
        //ability: bojovnik
        if(odraz == true){
            if(mana >=60){
                attack = true;
                mana = mana -60;
                cout << "Abilita pouzita\n";
                odrazedlo = true;
            }else{
                cout << "Nedostate many!";
            }
        //ability: carodej
        }else if(cheal == true){
            if(mana >=80){
                attack = true;
                mana = mana -80;
            snautok = rand() % 100;
            if(snautok <=50){
                damage =50+(rand() % 50);
                sleep(1);
                cout << "Uspech!\nUbral jsi vsem enemy " << damage << " hp!";
                hpenemy1 = hpenemy1 - damage;
                //hpenemy2 = hpenemy2 - damage;
                //hpenemy3 = hpenemy3 - damage;
                
            }else{
                cislohlasky = rand() % 5;
                cout << hlaskynetrefa[cislohlasky];
            }
            }else{
                cout << "Nedostatek many!";
            }
        //ability: TANK
        }else if(dvadamage == true){
            if(mana >=50){
                attack = true;
                mana = mana -60;
            snautok = rand() % 100;
            if(snautok <=50){
                damage = damage*2;
                sleep(1);
                cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
                hpenemy1 = hpenemy1 - damage;
            }else{
                cislohlasky = rand() % 5;
                cout << hlaskynetrefa[cislohlasky];
            }
            }else{
            cout << "Nedostatek many";
            }
        }
    }
    
  }while(attack == false && mana>=15);
    attack = false;
    if(mana <0) mana = 0;
    if(hpenemy1 < 0){ 
        hpenemy1 = 0;
        }
//na rade je enemy
    

    if(hpenemy1 !=0){
    
    sleep(1);
    cout << "\n\nNa rade je enemy!";
    sleep(1);
    cout << "\nEnemak se rozprahuje!\n";
    edamage1 =1+(rand() % 60);
    sleep(1);
    if(odrazedlo == false){
    cout << "A dal ti za " << edamage1 << "!\n";
    zivoty = zivoty - edamage1;
    }else{
        cout << "Pouzil jsi svuj stiti a odrazil utok.";
        odrazedlo = false;
    }

    }
    if(zivoty <=0){
        zivoty = 0;
        sleep(1);
    }

    }while(zivoty > 0 || hpenemy1 > 0);
//staty smrt + chcipl na manu
        if(chciplnamanu == true || zivoty ==0){
            if(chciplnamanu == true) cout << "V BOJI SI PADL VYCERPANIM!\n";
            if(zivoty == 0) cout << "ENEMY TE ZABIL!\n";
            cout << "====Tvoje staty====\n Zabiti enemaci: " << enemykilled << "\n Utracene penize: " << spentpenize;
            return 0;
        }  
    cout << endl;
    sleep(1);
        
        
if(hpenemy1 == 0){

        xp = xp + 90;
        zlatosance = rand() % 2;
        if(zlatosance == 2){
            zlato = zlato + 100;
        }
    }
    if( zlatosance == 2){
        cout << "Podarilo se ti zdolat enemaka!\n Ziskal jsi 100 zlata a 100 xp!";
    } else{
        cout << "Podarilo se ti zdolat enemaka!\n Ziskal jsi 100 xp!";
    }
    

 //konec battle s 1 enemy
 
 

//BATTLE S 2 ENEMY

    
    
    cout << "Jak jsi sel do lesa, nasel jsi dalsi protivniky!";
    sleep(1);
    cout << "\n\nHAHA, na nas nemas jedinou sanci cloveku!";
    sleep(0.4);
    cout << "\n====BOJ PROTI DVEMA PROTIVNIKUM====";
    sleep(1);
    
        
        
        cout << "\n\n====Staty battlu====";
        cout << "\nTvoje HP: "<< zivoty << endl << "Mana: " << mana << endl << "Enemy HP: " << hpenemy1 << endl;
        sleep(1);
        cout << "\nVyber utok!\n 1) Lehky (75 procent na hit; - 15 many)\n 2) Stredni (60 procent na hit; -25 many)\n 3) Heavy (35 procent na hit; -40 many)\n";
            if(odraz == true){
                cout << " 4) Odrazeni utoku (odrazi pristi enemy utok; -60 many)\n";
            }else if (cheal == true){
                cout << " 4) Blesk (Zasahne vsechny enemy najednou heavy utokem (50 procent na hit); -80 many)\n";
            }else if(dvadamage == true){
                cout << " 4) Ultra utok (2x damage z predesleho utoku (50 procent na hit); - 60 many)\n";
            }
//chcipl na manu
    
    if(mana <=0 && zivoty >0){
        chciplnamanu = true;
    }
    
if(chciplnamanu == false){
do{   
    do{
    cout << "Vyber: ";
    cin >> vyberu;
    if(vyberu <1 || vyberu >4) cout << "\nZadal jsi spatnou hodnotu!\n";
    }while(vyberu <1 || vyberu >4);
    
    
    if(vyberu ==1){
        if(mana >=15){
            mana = mana -15;
        snautok = rand() % 100;
        attack = true;
        if(snautok <=75){
            damage = 1+(rand() % 35);
            sleep(1);
            cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
            hpenemy1 = hpenemy1 - damage;
        }else{
            cislohlasky = rand() % 5;
            cout << hlaskynetrefa[cislohlasky];
        }
        }else{
            cout << "Nedostatek many!";
        }

    }else if(vyberu == 2){
        if(mana >=25){
            attack = true;
            mana = mana -25;
        snautok = rand() % 100;
        if(snautok <=60){
            damage = 20+(rand() % 50);
            sleep(1);
            cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
            hpenemy1 = hpenemy1 - damage;
        }else{
            cislohlasky = rand() % 5;
            cout << hlaskynetrefa[cislohlasky];
        }
        }else{
            cout << "Nedostatek many!";
        }
    }else if(vyberu == 3){
        if(mana >=40){
            attack = true;
            mana = mana -40;
        snautok = rand() % 100;
        if(snautok <=35){
            damage =50+(rand() % 50);
            sleep(1);
            cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
            hpenemy1 = hpenemy1 - damage;
        }else{
            cislohlasky = rand() % 5;
            cout << hlaskynetrefa[cislohlasky];
        }
        }else{
            cout << "Nedostatek many";
        }
    }else if(vyberu == 4){
        //ability: bojovnik
        if(odraz == true){
            if(mana >=60){
                attack = true;
                mana = mana -60;
                cout << "Abilita pouzita\n";
                odrazedlo = true;
            }else{
                cout << "Nedostate many!";
            }
        //ability: carodej
        }else if(cheal == true){
            if(mana >=80){
                attack = true;
                mana = mana -80;
            snautok = rand() % 100;
            if(snautok <=50){
                damage =50+(rand() % 50);
                sleep(1);
                cout << "Uspech!\nUbral jsi vsem enemy " << damage << " hp!";
                hpenemy1 = hpenemy1 - damage;
                hpenemy2 = hpenemy2 - damage;
                //hpenemy3 = hpenemy3 - damage;
                
            }else{
                cislohlasky = rand() % 5;
                cout << hlaskynetrefa[cislohlasky];
            }
            }else{
                cout << "Nedostatek many!";
            }
        //ability: TANK
        }else if(dvadamage == true){
            if(mana >=50){
                attack = true;
                mana = mana -60;
            snautok = rand() % 100;
            if(snautok <=50){
                damage = damage*2;
                sleep(1);
                cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
                hpenemy1 = hpenemy1 - damage;
            }else{
                cislohlasky = rand() % 5;
                cout << hlaskynetrefa[cislohlasky];
            }
            }else{
            cout << "Nedostatek many";
            }
        }
    }
    
  }while(attack == false && mana>=15);
    attack = false;
    if(mana <0) mana = 0;
    if(hpenemy1 < 0){ 
        hpenemy1 = 0;
        }
//na rade je enemy
    

    if(hpenemy1 !=0){
    
    sleep(1);
    cout << "\n\nNa rade je enemy!";
    sleep(1);
    cout << "\nEnemak se rozprahuje!\n";
    edamage1 =1+(rand() % 60);
    sleep(1);
    if(odrazedlo == false){
    cout << "A dal ti za " << edamage1 << "!\n";
    zivoty = zivoty - edamage1;
    }else{
        cout << "Pouzil jsi svuj stiti a odrazil utok.";
        odrazedlo = false;
    }

    }
    if(zivoty <=0){
        zivoty = 0;
        sleep(1);
    }

    }while(zivoty > 0 || hpenemy1 > 0);
//2. enemy v battlu o 2 enemy
    do{
    
    
        cout << "\n\n====Staty battlu====";
        cout << "\nTvoje HP: "<< zivoty << endl << "Mana: " << mana << endl << "Enemy HP: " << hpenemy2 << endl;
        sleep(1);
        cout << "\nVyber utok!\n 1) Lehky (75 procent na hit; - 15 many)\n 2) Stredni (60 procent na hit; -25 many)\n 3) Heavy (35 procent na hit; -40 many)\n";
            if(odraz == true){
                cout << " 4) Odrazeni utoku (odrazi pristi enemy utok; -60 many)\n";
            }else if (cheal == true){
                cout << " 4) Blesk (Zasahne vsechny enemy najednou heavy utokem (50 procent na hit); -80 many)\n";
            }else if(dvadamage == true){
                cout << " 4) Ultra utok (2x damage z predesleho utoku (50 procent na hit); - 60 many)\n";
            }
//chcipl na manu
    
    if(mana <=0 && zivoty >0){
        chciplnamanu = true;
    }
   // 
if(chciplnamanu == false){
do{   
    do{
    cout << "Vyber: ";
    cin >> vyberu;
    if(vyberu <1 || vyberu >4) cout << "\nZadal jsi spatnou hodnotu!\n";
    }while(vyberu <1 || vyberu >4);
    
    
    if(vyberu ==1){
        if(mana >=15){
            mana = mana -15;
        snautok = rand() % 100;
        attack = true;
        if(snautok <=75){
            damage = 1+(rand() % 35);
            sleep(1);
            cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
            hpenemy2 = hpenemy2 - damage;
        }else{
            cislohlasky = rand() % 5;
            cout << hlaskynetrefa[cislohlasky];
        }
        }else{
            cout << "Nedostatek many!";
        }

    }else if(vyberu == 2){
        if(mana >=25){
            attack = true;
            mana = mana -25;
        snautok = rand() % 100;
        if(snautok <=60){
            damage = 20+(rand() % 50);
            sleep(1);
            cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
            hpenemy2 = hpenemy2 - damage;
        }else{
            cislohlasky = rand() % 5;
            cout << hlaskynetrefa[cislohlasky];
        }
        }else{
            cout << "Nedostatek many!";
        }
    }else if(vyberu == 3){
        if(mana >=40){
            attack = true;
            mana = mana -40;
        snautok = rand() % 100;
        if(snautok <=35){
            damage =50+(rand() % 50);
            sleep(1);
            cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
            hpenemy2 = hpenemy2 - damage;
        }else{
            cislohlasky = rand() % 5;
            cout << hlaskynetrefa[cislohlasky];
        }
        }else{
            cout << "Nedostatek many";
        }
    }else if(vyberu == 4){
        //ability: bojovnik
        if(odraz == true){
            if(mana >=60){
                attack = true;
                mana = mana -60;
                cout << "Abilita pouzita\n";
                odrazedlo = true;
            }else{
                cout << "Nedostate many!";
            }
        //ability: carodej
        }else if(cheal == true){
            if(mana >=80){
                attack = true;
                mana = mana -80;
            snautok = rand() % 100;
            if(snautok <=50){
                damage =50+(rand() % 50);
                sleep(1);
                cout << "Uspech!\nUbral jsi vsem enemy " << damage << " hp!";
            hpenemy2 = hpenemy2 - damage;
            //hpenemy3 = hpenemy3 - damage;
                
            }else{
                cislohlasky = rand() % 5;
                cout << hlaskynetrefa[cislohlasky];
            }
            }else{
                cout << "Nedostatek many!";
            }
        //ability: TANK
        }else if(dvadamage == true){
            if(mana >=50){
                attack = true;
                mana = mana -60;
            snautok = rand() % 100;
            if(snautok <=50){
                damage = damage*2;
                sleep(1);
                cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
                hpenemy1 = hpenemy1 - damage;
            }else{
                cislohlasky = rand() % 5;
                cout << hlaskynetrefa[cislohlasky];
            }
            }else{
            cout << "Nedostatek many";
            }
        }
    }
    
  }while(attack == false && mana>=15);
    attack = false;
    if(mana <0) mana = 0;
    if(hpenemy1 < 0){ 
        hpenemy1 = 0;
        }
//na rade je enemy
    

    if(hpenemy1 !=0){
    
    sleep(1);
    cout << "\n\nNa rade je enemy!";
    sleep(1);
    cout << "\nEnemak se rozprahuje!\n";
    edamage1 =1+(rand() % 60);
    sleep(1);
    if(odrazedlo == false){
    cout << "A dal ti za " << edamage1 << "!\n";
    zivoty = zivoty - edamage1;
    }else{
        cout << "Pouzil jsi svuj stiti a odrazil utok.";
        odrazedlo = false;
    }

    }
    if(zivoty <=0){
        zivoty = 0;
        sleep(1);
    }


    }while(zivoty >0 || hpenemy2);

//staty smrt + chcipl na manu
        if(chciplnamanu == true || zivoty ==0){
            if(chciplnamanu == true) cout << "V BOJI SI PADL VYCERPANIM!\n";
            if(zivoty == 0) cout << "ENEMY TE ZABIL!\n";
            cout << "====Tvoje staty====\n Zabiti enemaci: " << enemykilled << "\n Utracene penize: " << spentpenize;
            return 0;
        }  
    cout << endl;
    sleep(1);
        
        
if(hpenemy1 == 0){

        xp = xp + 90;
        zlatosance = rand() % 2;
        if(zlatosance == 2){
            zlato = zlato + 100;
        }
    }
    if( zlatosance == 2){
        cout << "Podarilo se ti zdolat enemaka!\n Ziskal jsi 100 zlata a 100 xp!";
    } else{
        cout << "Podarilo se ti zdolat enemaka!\n Ziskal jsi 100 xp!";
    }
    

 //konec battle s 2 enemy


//BATTLE S 3 ENEMY
   
    
    
    cout << "Jak jsi sel do lesa, nasel jsi dalsi protivniky!";
    sleep(1);
    cout << "\n\nHAHA, na nas nemas jedinou sanci cloveku!";
    sleep(0.4);
    cout << "\n====BOJ PROTI DVEMA PROTIVNIKUM====";
    sleep(1);
    
        
        
        cout << "\n\n====Staty battlu====";
        cout << "\nTvoje HP: "<< zivoty << endl << "Mana: " << mana << endl << "Enemy HP: " << hpenemy1 << endl;
        sleep(1);
        cout << "\nVyber utok!\n 1) Lehky (75 procent na hit; - 15 many)\n 2) Stredni (60 procent na hit; -25 many)\n 3) Heavy (35 procent na hit; -40 many)\n";
            if(odraz == true){
                cout << " 4) Odrazeni utoku (odrazi pristi enemy utok; -60 many)\n";
            }else if (cheal == true){
                cout << " 4) Blesk (Zasahne vsechny enemy najednou heavy utokem (50 procent na hit); -80 many)\n";
            }else if(dvadamage == true){
                cout << " 4) Ultra utok (2x damage z predesleho utoku (50 procent na hit); - 60 many)\n";
            }
//chcipl na manu
    
    if(mana <=0 && zivoty >0){
        chciplnamanu = true;
    }
    
if(chciplnamanu == false){
do{   
    do{
    cout << "Vyber: ";
    cin >> vyberu;
    if(vyberu <1 || vyberu >4) cout << "\nZadal jsi spatnou hodnotu!\n";
    }while(vyberu <1 || vyberu >4);
    
    
    if(vyberu ==1){
        if(mana >=15){
            mana = mana -15;
        snautok = rand() % 100;
        attack = true;
        if(snautok <=75){
            damage = 1+(rand() % 35);
            sleep(1);
            cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
            hpenemy1 = hpenemy1 - damage;
        }else{
            cislohlasky = rand() % 5;
            cout << hlaskynetrefa[cislohlasky];
        }
        }else{
            cout << "Nedostatek many!";
        }

    }else if(vyberu == 2){
        if(mana >=25){
            attack = true;
            mana = mana -25;
        snautok = rand() % 100;
        if(snautok <=60){
            damage = 20+(rand() % 50);
            sleep(1);
            cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
            hpenemy1 = hpenemy1 - damage;
        }else{
            cislohlasky = rand() % 5;
            cout << hlaskynetrefa[cislohlasky];
        }
        }else{
            cout << "Nedostatek many!";
        }
    }else if(vyberu == 3){
        if(mana >=40){
            attack = true;
            mana = mana -40;
        snautok = rand() % 100;
        if(snautok <=35){
            damage =50+(rand() % 50);
            sleep(1);
            cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
            hpenemy1 = hpenemy1 - damage;
        }else{
            cislohlasky = rand() % 5;
            cout << hlaskynetrefa[cislohlasky];
        }
        }else{
            cout << "Nedostatek many";
        }
    }else if(vyberu == 4){
        //ability: bojovnik
        if(odraz == true){
            if(mana >=60){
                attack = true;
                mana = mana -60;
                cout << "Abilita pouzita\n";
                odrazedlo = true;
            }else{
                cout << "Nedostate many!";
            }
        //ability: carodej
        }else if(cheal == true){
            if(mana >=80){
                attack = true;
                mana = mana -80;
            snautok = rand() % 100;
            if(snautok <=50){
                damage =50+(rand() % 50);
                sleep(1);
                cout << "Uspech!\nUbral jsi vsem enemy " << damage << " hp!";
                hpenemy1 = hpenemy1 - damage;
                hpenemy2 = hpenemy2 - damage;
                //hpenemy3 = hpenemy3 - damage;
                
            }else{
                cislohlasky = rand() % 5;
                cout << hlaskynetrefa[cislohlasky];
            }
            }else{
                cout << "Nedostatek many!";
            }
        //ability: TANK
        }else if(dvadamage == true){
            if(mana >=50){
                attack = true;
                mana = mana -60;
            snautok = rand() % 100;
            if(snautok <=50){
                damage = damage*2;
                sleep(1);
                cout << "Uspech!\nUbral jsi enemy " << damage << " hp!";
                hpenemy1 = hpenemy1 - damage;
            }else{
                cislohlasky = rand() % 5;
                cout << hlaskynetrefa[cislohlasky];
            }
            }else{
            cout << "Nedostatek many";
            }
        }
    }
    
  }while(attack == false && mana>=15);
    attack = false;
    if(mana <0) mana = 0;
    if(hpenemy1 < 0){ 
        hpenemy1 = 0;
        }
//na rade je enemy
    

    if(hpenemy1 !=0){
    
    sleep(1);
    cout << "\n\nNa rade je enemy!";
    sleep(1);
    cout << "\nEnemak se rozprahuje!\n";
    edamage1 =1+(rand() % 60);
    sleep(1);
    if(odrazedlo == false){
    cout << "A dal ti za " << edamage1 << "!\n";
    zivoty = zivoty - edamage1;
    }else{
        cout << "Pouzil jsi svuj stiti a odrazil utok.";
        odrazedlo = false;
    }

    }
    if(zivoty <=0){
        zivoty = 0;
        sleep(1);
    }

    }while(zivoty > 0 || hpenemy1 > 0);
//2. enemy v battlu o 2 enemy
    do{
        if(hpenemy2 !=0){
    
    sleep(1);
    cout << "\n\nNa rade je 2. enemy!";
    sleep(1);
    cout << "\nEnemak se rozprahuje!\n";
    edamage2 =1+(rand() % 60);
    sleep(1);
    if(odrazedlo == false){
    cout << "A dal ti za " << edamage1 << "!\n";
    zivoty = zivoty - edamage1;
    }else{
        cout << "Pouzil jsi svuj stiti a odrazil utok.";
        odrazedlo = false;
    }

    }
    if(zivoty <=0){
        zivoty = 0;
        sleep(1);
    }

    }while(zivoty >0 || hpenemy2);

    do{







    }while(zivoty >0 || hpenemy3);

//staty smrt + chcipl na manu
        if(chciplnamanu == true || zivoty ==0){
            if(chciplnamanu == true) cout << "V BOJI SI PADL VYCERPANIM!\n";
            if(zivoty == 0) cout << "ENEMY TE ZABIL!\n";
            cout << "====Tvoje staty====\n Zabiti enemaci: " << enemykilled << "\n Utracene penize: " << spentpenize;
            return 0;
        }  
    cout << endl;
    sleep(1);
        
        
if(hpenemy1 == 0){

        xp = xp + 90;
        zlatosance = rand() % 2;
        if(zlatosance == 2){
            zlato = zlato + 100;
        }
    }
    if( zlatosance == 2){
        cout << "Podarilo se ti zdolat enemaka!\n Ziskal jsi 100 zlata a 100 xp!";
    } else{
        cout << "Podarilo se ti zdolat enemaka!\n Ziskal jsi 100 xp!";
    } 





}



// TO DO: FIX BOOLINY (JE MOZNE ZE ZUSTANOU TRUE KDYZ MAJI BYT FALSE), 3x enemy, Mini-Boss, Mega-Boss