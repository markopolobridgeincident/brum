#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

//level up
void hrac_level(int &xp, int &level, int &zivoty, int &mana, int &max_zivoty, int &max_mana){
    while (xp >= level * 400){
        level++;
        max_zivoty += 50;
        max_mana += 50;
        zivoty += 50;
        mana += 50;
        cout << "\n====================================\n";
        cout << "Dosahl jsi levelu " << level << "!\n";
        cout << "Ziskal jsi:\n 50 hp navic\n 50 many navic\n";
        cout << "====================================\n";
        sleep(2);
    }
}

//vesnice
void vesnice(int &zivoty, int &mana, int &max_zivoty, int &max_mana, int &zlato, int &spentpenize, int &pocetls, int &pocetlo, int &pocetlr, int level){
    cout << "\n\nVybirani postavy/Cesta ti zabrala nejaky cas, a tak uz je vecer.\n";
    sleep(2);
    cout << "\n==== Prisel jsi do vesnice! ====\n";
    cout << "--- Tvuj level: " << level << " ---\n";
    cout << "Zde si muzes doplnit zasoby, vylepsit si postavu, nebo doplnit energii na tvoje dobrodruzstvi!\n";
    sleep(2);
    
    int volbav;
    static int cenahospoda = 50;
    bool gatata = false;
    bool chestplate = false;
    bool helma = false;
    bool rukavy = false;
    bool namesti = true;
    
    do{
        cout << "\nZlato: " << zlato << " | HP: " << zivoty << "/" << max_zivoty << " | Mana: " << mana << "/" << max_mana << "\n";
        cout << " 1) Odpocinek v nedaleke krcme\n 2) Navstiveni baby korenarky\n 3) Bez za kovarem\n 4) Pokracovani pres noc za dalsim dobrodruzstvim.\n Zvol moznost: ";
        cin >> volbav;
        switch(volbav){
            case 1:
                if(zlato >= cenahospoda){
                    cout << "\nZaplatil jsi hospodskemu " << cenahospoda << " zlata, aby te nechal prespat v hospode.";
                    cout << "\nRano jsi se probudil odpocaty a muzes pokracovat na sve ceste.";
                    zivoty = max_zivoty;
                    mana = max_mana;
                    zlato -= cenahospoda;
                    spentpenize += cenahospoda;
                    cenahospoda += 20;
                }else{
                    cout << "\nNemas dostatek zlata! Padej pryc!\n";
                    sleep(1);
                }
                break;
            case 2:
                cout << "\n=== Prisel jsi k babce korenarce ===\n";
                cout << " \nAhoj poutniku! Koukni, co mam v nabidce:\n 1) Lektvar sily - Prida ti silu v boji | 25 zlata\n 2) Lektvar oziveni - obnovi ti hp | 40 zlata\n 3) Lektvar regenerace - doplni ti manu | 20 zlata \n";
                int vyberb;
                do{
                    cout << "vyber: ";
                    cin >> vyberb;
                    if(vyberb == 1){
                        if(zlato >= 25){ 
                            pocetls++;
                            zlato -= 25;
                            spentpenize += 25;
                            cout << "Koupeno!\n";
                             }else{ 
                            cout << "\nNemas dostatek zlata! Padej pryc!\n";
                            sleep(1);
                            }
                    }else if(vyberb == 2){
                        if(zlato >= 40){
                            pocetlo++;
                            zlato -= 40;
                            spentpenize += 40;
                            cout << "Koupeno!\n";
                        }else{
                            cout << "\nNemas dostatek zlata! Padej pryc!\n";
                            sleep(1); }
                    }else if(vyberb == 3){
                        if(zlato >= 20){
                            pocetlr++; zlato -= 20;
                            spentpenize += 20;
                            cout << "Koupeno!\n";
                        }else{
                            cout << "\nNemas dostatek zlata! Padej pryc\n";
                            sleep(1);
                        }
                    }
                }while(vyberb < 1 || vyberb > 3);
                break;
            case 3:
                cout << "\n=== Prisel jsi do kovarny ===\n";
                cout << "Hledas nejakou vyzbroj poutniku? Koukni na moji nabidku!\n 1) Zelezna helma - prida ti 40 hp\n  CENA: 200\n\n 2) Zelezne rukavy - prida ti 25 hp\n  CENA: 100\n\n 3) Zelezny chestplate - prida ti 80 hp\n  CENA: 300\n 4) Zelezne nohavice - prida ti 40 hp\n  CENA: 250\n\n 5) Odchod\n\nVyber: ";
                int vyberk;
                do{
                    cin >> vyberk;
                    if(vyberk == 1){
                        if(zlato >= 200 && !helma){
                            cout << "Zpracovani transakce";
                            sleep(1);
                            cout << "\nNakup uspesny!\n";
                            helma = true;
                             max_zivoty += 40;
                             zivoty += 40;
                             zlato -= 200;
                             spentpenize += 200;
                        }else cout << "\nNemas dostatek zlata nebo uz to mas! Padej pryc!\n";
                        sleep(1);
                    }else if(vyberk == 2){
                        if(zlato >= 100 && !rukavy){
                            cout << "Zpracovani transakce";
                            sleep(1);
                            cout << "\nNakup uspesny!\n";
                            rukavy = true;
                            max_zivoty += 25;
                            zivoty += 25;
                            zlato -= 100;
                            spentpenize += 100;
                        }else cout << "\nNemas dostatek zlata nebo uz to mas! Padej pryc!\n";
                        sleep(1);
                    }else if(vyberk == 3){
                        if(zlato >= 300 && !chestplate){
                            cout << "Zpracovani transakce";
                            sleep(1);
                            cout << "\nNakup uspesny!\n";
                            chestplate = true;
                            max_zivoty += 80;
                            zivoty += 80;
                            zlato -= 300;
                            spentpenize += 300;
                        }else cout << "\nNemas dostatek zlata nebo uz to mas! Padej pryc!\n";
                        sleep(1);
                    }else if(vyberk == 4){
                        if(zlato >= 250 && !gatata){
                            cout << "Zpracovani transakce";
                            sleep(1);
                            cout << "\nNakup uspesny!\n";
                            gatata = true;
                            max_zivoty += 40;
                            zivoty += 40;
                            zlato -= 250;
                            spentpenize += 250;
                        }else cout << "\nNemas dostatek zlata nebo uz to mas! Padej pryc!\n";
                        sleep(1);
                    }else if(vyberk == 5){
                        cout << "\nZase navidenou!\n";
                    }else{
                        cout << "Musis si neco vybrat!\n";
                    }
                }while(vyberk < 1 || vyberk > 5);
                break;
            default:
                namesti = false;
                cout << "Pokracujes tedy dale.\n";
        }  
    }while(namesti == true);
}

//battle s 1 enemy
bool boj_s_1_enemy(int &zivoty, int &mana, int &max_zivoty, int &max_mana, int &zlato, int &spentpenize, int &enemykilled, int &xp, bool odraz, bool cheal, bool dvadamage, int &pocetls, int &pocetlo, int &pocetlr){
    int edamage1;
    bool odrazedlo = false;
    int hpenemy1 = 100;
    int vyberu;
    bool chciplnamanu = false;
    bool attack = false;
    int snautok;
    int damage = 0;
    int bonus_dmg = 0;
    int cislohlasky;
    int zlatosance = 0;
    string hlaskynetrefa[] ={"Netrefils!", "Proboha! Nauc se mirit!", "Jak jsi to mohl netrefit!", "O pet metru vedle!", "Zkus to priste!"};

    cout << "\n====Nasel jsi enemaka!====";
    cout << "\n\nCus pic clovece! Rozkopu ti drzku abys vedel.";
    sleep(1);
    
    do{   
        cout << "\n\n====Staty battlu====";
        cout << "\nTvoje HP: " << zivoty << "/" << max_zivoty << "\nMana: " << mana << "/" << max_mana << "\nEnemy HP: " << hpenemy1 << endl;
        if(bonus_dmg > 0) cout << "(Lektvar sily aktivni: +" << bonus_dmg << " dmg)\n";
        sleep(1);
        cout << "\nVyber utok!\n 1) Lehky (75 procent na hit; - 15 many)\n 2) Stredni (60 procent na hit; -25 many)\n 3) Heavy (35 procent na hit; -40 many)\n";
        if(odraz == true) cout << " 4) Odrazeni utoku (odrazi pristi enemy utok; -60 many)\n";
        else if(cheal == true) cout << " 4) Blesk (Zasahne vsechny enemy najednou heavy utokem (50 procent na hit); -80 many)\n";
        else if(dvadamage == true) cout << " 4) Ultra utok (2x damage z predesleho utoku (50 procent na hit); - 60 many)\n";
        cout << " 5) Pouzit lektvar\n";

        if(mana <= 0 && zivoty > 0) chciplnamanu = true;
    
        if(chciplnamanu == false){
            do{
                cout << "Vyber: ";
                cin >> vyberu;
                if(vyberu < 1 || vyberu > 5) cout << "\nZadal jsi spatnou hodnotu!\n";
            }while(vyberu < 1 || vyberu > 5);
        
            if(vyberu == 1){
                if(mana >= 15){
                    mana -= 15; snautok = rand() % 100; attack = true;
                    if(snautok <= 75){ damage = 1 + (rand() % 35) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi enemy " << damage << " hp!"; hpenemy1 -= damage; }
                    else{ cislohlasky = rand() % 5; cout << hlaskynetrefa[cislohlasky]; }
                }else cout << "Nedostatek many!";
            }else if(vyberu == 2){
                if(mana >= 25){
                    attack = true; mana -= 25; snautok = rand() % 100;
                    if(snautok <= 60){ damage = 20 + (rand() % 50) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi enemy " << damage << " hp!"; hpenemy1 -= damage; }
                    else{ cislohlasky = rand() % 5; cout << hlaskynetrefa[cislohlasky]; }
                }else cout << "Nedostatek many!";
            }else if(vyberu == 3){
                if(mana >= 40){
                    attack = true; mana -= 40; snautok = rand() % 100;
                    if(snautok <= 35){ damage = 50 + (rand() % 50) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi enemy " << damage << " hp!"; hpenemy1 -= damage; }
                    else{ cislohlasky = rand() % 5; cout << hlaskynetrefa[cislohlasky]; }
                }else cout << "Nedostatek many";
            }else if(vyberu == 4){
                if(odraz == true){
                    if(mana >= 60){ attack = true; mana -= 60; cout << "Abilita pouzita\n"; odrazedlo = true; }
                    else cout << "Nedostatek many!";
                }else if(cheal == true){
                    if(mana >= 80){
                        attack = true; mana -= 80; snautok = rand() % 100;
                        if(snautok <= 50){ damage = 50 + (rand() % 50) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi enemy " << damage << " hp!"; hpenemy1 -= damage; }
                        else{ cislohlasky = rand() % 5; cout << hlaskynetrefa[cislohlasky]; }
                    }else cout << "Nedostatek many!";
                }else if(dvadamage == true){
                    if(mana >= 50){
                        attack = true; mana -= 50; snautok = rand() % 100;
                        if(snautok <= 50){ damage = (damage > 0 ? damage * 2 : 20 * 2) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi enemy " << damage << " hp!"; hpenemy1 -= damage; }
                        else{ cislohlasky = rand() % 5; cout << hlaskynetrefa[cislohlasky]; }
                    }else cout << "Nedostatek many";
                }
            }else if(vyberu == 5){
                cout << "\nJakej lektvar chces pouzit?\n 1) Lektvar sily (" << pocetls << "x)\n 2) Lektvar oziveni (" << pocetlo << "x)\n 3) Lektvar regenerace (" << pocetlr << "x)\n Zpet jinou klavesou\nVyber: ";
                int vyberl; cin >> vyberl;
                if(vyberl == 1 && pocetls > 0){ pocetls--; bonus_dmg += 20; cout << "Vypil jsi lektvar sily! Tve utoky nyni davaji o 20 vice poskozeni.\n"; }
                else if(vyberl == 2 && pocetlo > 0){ pocetlo--; zivoty = max_zivoty; cout << "Vypil jsi lektvar oziveni! Tve zivoty jsou opet plne.\n"; }
                else if(vyberl == 3 && pocetlr > 0){ pocetlr--; mana = max_mana; cout << "Vypil jsi lektvar regenerace! Tva mana je plna.\n"; }
                else cout << "Tento lektvar nemas nebo spatna volba. Ztracis tah!\n";
            }
        }
        
        attack = false;
        if(mana < 0) mana = 0;
        if(hpenemy1 < 0) hpenemy1 = 0;

        if(hpenemy1 != 0 && chciplnamanu == false){
            sleep(1); cout << "\n\nNa rade je enemy!"; sleep(1); cout << "\nEnemak se rozprahuje!\n";
            edamage1 = 1 + (rand() % 60);
            sleep(1);
            if(odrazedlo == false){ cout << "A dal ti za " << edamage1 << "!\n"; zivoty -= edamage1; }
            else{ cout << "Pouzil jsi svuj stit a odrazil utok.\n"; odrazedlo = false; }
        }
        if(zivoty <= 0){ zivoty = 0; sleep(1); }
    }while(zivoty > 0 && hpenemy1 > 0 && chciplnamanu == false);

    if(chciplnamanu == true || zivoty == 0){
        if(chciplnamanu == true) cout << "V BOJI JSI PADL VYCERPANIM!\n";
        if(zivoty == 0) cout << "ENEMY TE ZABIL!\n";
        cout << "====Tvoje staty====\n Zabiti enemaci: " << enemykilled << "\n Utracene penize: " << spentpenize << endl;
        return false;
    } 
    
    cout << endl; sleep(1);
        
    if(hpenemy1 == 0){
        enemykilled++;
        xp += 90;
        zlatosance = rand() % 2;
        if(zlatosance == 1) zlato += 100;
    }
    if(zlatosance == 1) cout << "Podarilo se ti zdolat enemaka!\n Ziskal jsi 100 zlata a 90 xp!\n";
    else cout << "Podarilo se ti zdolat enemaka!\n Ziskal jsi 90 xp!\n";
    
    return true;
}

//battle se 2 enemy
bool boj_s_2_enemy(int &zivoty, int &mana, int &max_zivoty, int &max_mana, int &zlato, int &spentpenize, int &enemykilled, int &xp, bool odraz, bool cheal, bool dvadamage, int &pocetls, int &pocetlo, int &pocetlr){
    cout << "\nJak jsi sel dal, nasel jsi dalsi protivniky!";
    sleep(1);
    cout << "\n\nHAHA, na nas nemas jedinou sanci cloveku!";
    sleep(0.4);
    cout << "\n====BOJ PROTI 2 PROTIVNIKUM====";
    sleep(1);

    int bonus_dmg = 0;
    string hlaskynetrefa[] ={"Netrefils!", "Proboha! Nauc se mirit!", "Jak jsi to mohl netrefit!", "O pet metru vedle!", "Zkus to priste!"};

    for(int i = 1; i <= 2; i++){
        int hpenemy = 100;
        int damage = 0;
        bool odrazedlo = false;
        bool chciplnamanu = false;
        
        cout << "\n---Pribehl " << i << ". nepritel! ---\n";
        
        do{   
            cout << "\n\n====Staty battlu====";
            cout << "\nTvoje HP: " << zivoty << "/" << max_zivoty << "\nMana: " << mana << "/" << max_mana << "\nEnemy " << i << " HP: " << hpenemy << endl;
            if(bonus_dmg > 0) cout << "(Lektvar sily aktivni: +" << bonus_dmg << " dmg)\n";
            sleep(1);
            
            cout << "\nVyber utok!\n 1) Lehky (75 procent na hit; - 15 many)\n 2) Stredni (60 procent na hit; -25 many)\n 3) Heavy (35 procent na hit; -40 many)\n";
            if(odraz == true) cout << " 4) Odrazeni utoku (odrazi pristi enemy utok; -60 many)\n";
            else if(cheal == true) cout << " 4) Blesk (Zasahne aktualniho enemy heavy utokem; -80 many)\n";
            else if(dvadamage == true) cout << " 4) Ultra utok (2x damage z predesleho utoku; - 60 many)\n";
            cout << " 5) Pouzit lektvar\n";
        
            if(mana <= 0 && zivoty > 0) chciplnamanu = true;
        
            if(chciplnamanu == false){
                int vyberu;
                do{
                    cout << "Vyber: "; cin >> vyberu;
                    if(vyberu < 1 || vyberu > 5) cout << "\nZadal jsi spatnou hodnotu!\n";
                }while(vyberu < 1 || vyberu > 5);
            
                if(vyberu == 1){
                    if(mana >= 15){
                        mana -= 15; int snautok = rand() % 100;
                        if(snautok <= 75){ damage = 1 + (rand() % 35) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi enemy " << damage << " hp!"; hpenemy -= damage; }
                        else{ cout << hlaskynetrefa[rand() % 5]; }
                    }else cout << "Nedostatek many!";
                }else if(vyberu == 2){
                    if(mana >= 25){
                        mana -= 25; int snautok = rand() % 100;
                        if(snautok <= 60){ damage = 20 + (rand() % 50) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi enemy " << damage << " hp!"; hpenemy -= damage; }
                        else{ cout << hlaskynetrefa[rand() % 5]; }
                    }else cout << "Nedostatek many!";
                }else if(vyberu == 3){
                    if(mana >= 40){
                        mana -= 40; int snautok = rand() % 100;
                        if(snautok <= 35){ damage = 50 + (rand() % 50) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi enemy " << damage << " hp!"; hpenemy -= damage; }
                        else{ cout << hlaskynetrefa[rand() % 5]; }
                    }else cout << "Nedostatek many";
                }else if(vyberu == 4){
                    if(odraz == true){
                        if(mana >= 60){ mana -= 60; cout << "Abilita pouzita\n"; odrazedlo = true; }
                        else cout << "Nedostate many!";
                    }else if(cheal == true){
                        if(mana >= 80){
                            mana -= 80; int snautok = rand() % 100;
                            if(snautok <= 50){ damage = 50 + (rand() % 50) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi enemy " << damage << " hp!"; hpenemy -= damage; }
                            else{ cout << hlaskynetrefa[rand() % 5]; }
                        }else cout << "Nedostatek many!";
                    }else if(dvadamage == true){
                        if(mana >= 50){
                            mana -= 50; int snautok = rand() % 100;
                            if(snautok <= 50){ damage = (damage > 0 ? damage * 2 : 20 * 2) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi enemy " << damage << " hp!"; hpenemy -= damage; }
                            else{ cout << hlaskynetrefa[rand() % 5]; }
                        }else cout << "Nedostatek many";
                    }
                }else if(vyberu == 5){
                    cout << "\nJakej lektvar chces pouzit?\n 1) Lektvar sily (" << pocetls << "x)\n 2) Lektvar oziveni (" << pocetlo << "x)\n 3) Lektvar regenerace (" << pocetlr << "x)\n Zpet jinou klavesou\nVyber: ";
                    int vyberl; cin >> vyberl;
                    if(vyberl == 1 && pocetls > 0){ pocetls--; bonus_dmg += 20; cout << "Vypil jsi lektvar sily! Tve utoky nyni davaji o 20 vice poskozeni.\n"; }
                    else if(vyberl == 2 && pocetlo > 0){ pocetlo--; zivoty = max_zivoty; cout << "Vypil jsi lektvar oziveni! Tve zivoty jsou opet plne.\n"; }
                    else if(vyberl == 3 && pocetlr > 0){ pocetlr--; mana = max_mana; cout << "Vypil jsi lektvar regenerace! Tva mana je plna.\n"; }
                    else cout << "Tento lektvar nemas nebo spatna volba. Ztracis tah!\n";
                }
            }
            
            if(mana < 0) mana = 0;
            if(hpenemy < 0) hpenemy = 0;

            if(hpenemy != 0 && chciplnamanu == false){
                sleep(1); cout << "\n\nNa rade je " << i << ". enemy!"; sleep(1); cout << "\nEnemak se rozprahuje!\n";
                int edamage = 1 + (rand() % 60);
                sleep(1);
                if(odrazedlo == false){ cout << "A dal ti za " << edamage << "!\n"; zivoty -= edamage; }
                else{ cout << "Pouzil jsi svuj stit a odrazil utok.\n"; odrazedlo = false; }
            }
            if(zivoty <= 0){ zivoty = 0; sleep(1); }
            
        }while(zivoty > 0 && hpenemy > 0 && chciplnamanu == false);

        if(chciplnamanu == true || zivoty == 0){
            if(chciplnamanu == true) cout << "V BOJI SI PADL VYCERPANIM!\n";
            if(zivoty == 0) cout << "ENEMY TE ZABIL!\n";
            cout << "====Tvoje staty====\n Zabiti enemaci: " << enemykilled << "\n Utracene penize: " << spentpenize << endl;
            return false;
        }

        if(hpenemy == 0){
            enemykilled++;
            xp += 90;
            cout << "\nPorazil jsi " << i << ". nepritele!\n";
            sleep(1);
        }
    }

    int zlatosance = rand() % 2;
    if(zlatosance == 1){
        zlato += 200;
        cout << "\nUspesne jsi porazil celou skupinu!\n Ziskal jsi 200 zlata a spoustu xp!\n";
    }else{
        cout << "\nUspesne jsi porazil celou skupinu!\n Ziskal jsi spoustu xp!\n";
    }
    return true;
}

//battle se 3 enemy
bool boj_s_3_enemy(int &zivoty, int &mana, int &max_zivoty, int &max_mana, int &zlato, int &spentpenize, int &enemykilled, int &xp, bool odraz, bool cheal, bool dvadamage, int &pocetls, int &pocetlo, int &pocetlr){
    cout << "\nJak jsi sel dal, nasel jsi celou hordu protivniku!";
    sleep(1);
    cout << "\n\nHAHA, na nas nemas jedinou sanci cloveku!";
    sleep(0.4);
    cout << "\n====BOJ PROTI 3 PROTIVNIKUM====";
    sleep(1);

    int bonus_dmg = 0;
    string hlaskynetrefa[] ={"Netrefils!", "Proboha! Nauc se mirit!", "Jak jsi to mohl netrefit!", "O pet metru vedle!", "Zkus to priste!"};

    for(int i = 1; i <= 3; i++){
        int hpenemy = 100;
        int damage = 0;
        bool odrazedlo = false;
        bool chciplnamanu = false;
        
        cout << "\n---Pribehl " << i << ". nepritel! ---\n";
        
        do{   
            cout << "\n\n====Staty battlu====";
            cout << "\nTvoje HP: " << zivoty << "/" << max_zivoty << "\nMana: " << mana << "/" << max_mana << "\nEnemy " << i << " HP: " << hpenemy << endl;
            if(bonus_dmg > 0) cout << "(Lektvar sily aktivni: +" << bonus_dmg << " dmg)\n";
            sleep(1);
            
            cout << "\nVyber utok!\n 1) Lehky (75 procent na hit; - 15 many)\n 2) Stredni (60 procent na hit; -25 many)\n 3) Heavy (35 procent na hit; -40 many)\n";
            if(odraz == true) cout << " 4) Odrazeni utoku (odrazi pristi enemy utok; -60 many)\n";
            else if(cheal == true) cout << " 4) Blesk (Zasahne aktualniho enemy heavy utokem; -80 many)\n";
            else if(dvadamage == true) cout << " 4) Ultra utok (2x damage z predesleho utoku; - 60 many)\n";
            cout << " 5) Pouzit lektvar\n";
        
            if(mana <= 0 && zivoty > 0) chciplnamanu = true;
        
            if(chciplnamanu == false){
                int vyberu;
                do{
                    cout << "Vyber: "; cin >> vyberu;
                    if(vyberu < 1 || vyberu > 5) cout << "\nZadal jsi spatnou hodnotu!\n";
                }while(vyberu < 1 || vyberu > 5);
            
                if(vyberu == 1){
                    if(mana >= 15){
                        mana -= 15; int snautok = rand() % 100;
                        if(snautok <= 75){ damage = 1 + (rand() % 35) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi enemy " << damage << " hp!"; hpenemy -= damage; }
                        else{ cout << hlaskynetrefa[rand() % 5]; }
                    }else cout << "Nedostatek many!";
                }else if(vyberu == 2){
                    if(mana >= 25){
                        mana -= 25; int snautok = rand() % 100;
                        if(snautok <= 60){ damage = 20 + (rand() % 50) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi enemy " << damage << " hp!"; hpenemy -= damage; }
                        else{ cout << hlaskynetrefa[rand() % 5]; }
                    }else cout << "Nedostatek many!";
                }else if(vyberu == 3){
                    if(mana >= 40){
                        mana -= 40; int snautok = rand() % 100;
                        if(snautok <= 35){ damage = 50 + (rand() % 50) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi enemy " << damage << " hp!"; hpenemy -= damage; }
                        else{ cout << hlaskynetrefa[rand() % 5]; }
                    }else cout << "Nedostatek many";
                }else if(vyberu == 4){
                    if(odraz == true){
                        if(mana >= 60){ mana -= 60; cout << "Abilita pouzita\n"; odrazedlo = true; }
                        else cout << "Nedostate many!";
                    }else if(cheal == true){
                        if(mana >= 80){
                            mana -= 80; int snautok = rand() % 100;
                            if(snautok <= 50){ damage = 50 + (rand() % 50) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi enemy " << damage << " hp!"; hpenemy -= damage; }
                            else{ cout << hlaskynetrefa[rand() % 5]; }
                        }else cout << "Nedostatek many!";
                    }else if(dvadamage == true){
                        if(mana >= 50){
                            mana -= 50; int snautok = rand() % 100;
                            if(snautok <= 50){ damage = (damage > 0 ? damage * 2 : 20 * 2) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi enemy " << damage << " hp!"; hpenemy -= damage; }
                            else{ cout << hlaskynetrefa[rand() % 5]; }
                        }else cout << "Nedostatek many";
                    }
                }else if(vyberu == 5){
                    cout << "\nJakej lektvar chces pouzit?\n 1) Lektvar sily (" << pocetls << "x)\n 2) Lektvar oziveni (" << pocetlo << "x)\n 3) Lektvar regenerace (" << pocetlr << "x)\n Zpet jinou klavesou\nVyber: ";
                    int vyberl; cin >> vyberl;
                    if(vyberl == 1 && pocetls > 0){ pocetls--; bonus_dmg += 20; cout << "Vypil jsi lektvar sily! Tve utoky nyni davaji o 20 vice poskozeni.\n"; }
                    else if(vyberl == 2 && pocetlo > 0){ pocetlo--; zivoty = max_zivoty; cout << "Vypil jsi lektvar oziveni! Tve zivoty jsou opet plne.\n"; }
                    else if(vyberl == 3 && pocetlr > 0){ pocetlr--; mana = max_mana; cout << "Vypil jsi lektvar regenerace! Tva mana je plna.\n"; }
                    else cout << "Tento lektvar nemas nebo spatna volba. Ztracis tah!\n";
                }
            }
            
            if(mana < 0) mana = 0;
            if(hpenemy < 0) hpenemy = 0;

            if(hpenemy != 0 && chciplnamanu == false){
                sleep(1); cout << "\n\nNa rade je " << i << ". enemy!"; sleep(1); cout << "\nEnemak se rozprahuje!\n";
                int edamage = 1 + (rand() % 60);
                sleep(1);
                if(odrazedlo == false){ cout << "A dal ti za " << edamage << "!\n"; zivoty -= edamage; }
                else{ cout << "Pouzil jsi svuj stit a odrazil utok.\n"; odrazedlo = false; }
            }
            if(zivoty <= 0){ zivoty = 0; sleep(1); }
            
        }while(zivoty > 0 && hpenemy > 0 && chciplnamanu == false);

        if(chciplnamanu == true || zivoty == 0){
            if(chciplnamanu == true) cout << "V BOJI SI PADL VYCERPANIM!\n";
            if(zivoty == 0) cout << "ENEMY TE ZABIL!\n";
            cout << "====Tvoje staty====\n Zabiti enemaci: " << enemykilled << "\n Utracene penize: " << spentpenize << endl;
            return false;
        }

        if(hpenemy == 0){
            enemykilled++;
            xp += 90;
            cout << "\nPorazil jsi " << i << ". nepritele!\n";
            sleep(1);
        }
    }

    int zlatosance = rand() % 2;
    if(zlatosance == 1){
        zlato += 300;
        cout << "\nUspesne jsi porazil celou skupinu!\n Ziskal jsi 300 zlata a spoustu xp!\n";
    }else{
        cout << "\nUspesne jsi porazil celou skupinu!\n Ziskal jsi spoustu xp!\n";
    }
    return true;
}

//mini-boss
bool mini_boss(int &zivoty, int &mana, int &max_zivoty, int &max_mana, int &zlato, int &spentpenize, int &enemykilled, int &xp, bool odraz, bool cheal, bool dvadamage, int &pocetls, int &pocetlo, int &pocetlr){
    int hpenemy = 200;
    bool chciplnamanu = false;
    int damage = 0;
    int bonus_dmg = 0;
    bool odrazedlo = false;
    string hlaskynetrefa[] ={"Netrefils!", "Proboha! Nauc se mirit!", "Jak jsi to mohl netrefit!", "O pet metru vedle!", "Zkus to priste!"};

    cout << "\n==== NARAZIL JSI NA MINI-BOSSE ====\n";
    sleep(1);
    cout << "Mini-boss utoci prvni!\n";
    int edamage = 10 + (rand() % 40);
    sleep(1);
    cout << "Mini-boss ti ubral " << edamage << " HP!\n";
    zivoty -= edamage;
    
    if(zivoty <= 0){
        cout << "Mini-Boss te zabil driv nez jsi stacil zautocit!\n";
        return false;
    }

    do{
        cout << "\n\n====Staty battlu====";
        cout << "\nTvoje HP: " << zivoty << "/" << max_zivoty << "\nMana: " << mana << "/" << max_mana << "\nMini-Boss HP: " << hpenemy << endl;
        if(bonus_dmg > 0) cout << "(Lektvar sily aktivni: +" << bonus_dmg << " dmg)\n";
        sleep(1);
        
        cout << "\nVyber utok!\n 1) Lehky (75 procent na hit; - 15 many)\n 2) Stredni (60 procent na hit; -25 many)\n 3) Heavy (35 procent na hit; -40 many)\n";
        if(odraz == true) cout << " 4) Odrazeni utoku (odrazi pristi enemy utok; -60 many)\n";
        else if(cheal == true) cout << " 4) Blesk (Zasahne vsechny enemy najednou heavy utokem (50 procent na hit); -80 many)\n";
        else if(dvadamage == true) cout << " 4) Ultra utok (2x damage z predesleho utoku (50 procent na hit); - 60 many)\n";
        cout << " 5) Pouzit lektvar\n";

        if(mana <= 0 && zivoty > 0) chciplnamanu = true;
    
        if(chciplnamanu == false){
            int vyberu;
            do{
                cout << "Vyber: "; cin >> vyberu;
                if(vyberu < 1 || vyberu > 5) cout << "\nZadal jsi spatnou hodnotu!\n";
            }while(vyberu < 1 || vyberu > 5);
        
            if(vyberu == 1){
                if(mana >= 15){
                    mana -= 15; int snautok = rand() % 100;
                    if(snautok <= 75){ damage = 1 + (rand() % 35) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi bossovi " << damage << " hp!"; hpenemy -= damage; }
                    else{ cout << hlaskynetrefa[rand() % 5]; }
                }else cout << "Nedostatek many!";
            }else if(vyberu == 2){
                if(mana >= 25){
                    mana -= 25; int snautok = rand() % 100;
                    if(snautok <= 60){ damage = 20 + (rand() % 50) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi bossovi " << damage << " hp!"; hpenemy -= damage; }
                    else{ cout << hlaskynetrefa[rand() % 5]; }
                }else cout << "Nedostatek many!";
            }else if(vyberu == 3){
                if(mana >= 40){
                    mana -= 40; int snautok = rand() % 100;
                    if(snautok <= 35){ damage = 50 + (rand() % 50) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi bossovi " << damage << " hp!"; hpenemy -= damage; }
                    else{ cout << hlaskynetrefa[rand() % 5]; }
                }else cout << "Nedostatek many";
            }else if(vyberu == 4){
                if(odraz == true){
                    if(mana >= 60){ mana -= 60; cout << "Abilita pouzita\n"; odrazedlo = true; }
                    else cout << "Nedostatek many!";
                }else if(cheal == true){
                    if(mana >= 80){
                        mana -= 80; int snautok = rand() % 100;
                        if(snautok <= 50){ damage = 50 + (rand() % 50) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi bossovi " << damage << " hp!"; hpenemy -= damage; }
                        else{ cout << hlaskynetrefa[rand() % 5]; }
                    }else cout << "Nedostatek many!";
                }else if(dvadamage == true){
                    if(mana >= 50){
                        mana -= 50; int snautok = rand() % 100;
                        if(snautok <= 50){ damage = (damage > 0 ? damage * 2 : 20 * 2) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi bossovi " << damage << " hp!"; hpenemy -= damage; }
                        else{ cout << hlaskynetrefa[rand() % 5]; }
                    }else cout << "Nedostatek many";
                }
            }else if(vyberu == 5){
                cout << "\nJakej lektvar chces pouzit?\n 1) Lektvar sily (" << pocetls << "x)\n 2) Lektvar oziveni (" << pocetlo << "x)\n 3) Lektvar regenerace (" << pocetlr << "x)\n Zpet jinou klavesou\nVyber: ";
                int vyberl; cin >> vyberl;
                if(vyberl == 1 && pocetls > 0){ pocetls--; bonus_dmg += 20; cout << "Vypil jsi lektvar sily!\n"; }
                else if(vyberl == 2 && pocetlo > 0){ pocetlo--; zivoty = max_zivoty; cout << "Vypil jsi lektvar oziveni!\n"; }
                else if(vyberl == 3 && pocetlr > 0){ pocetlr--; mana = max_mana; cout << "Vypil jsi lektvar regenerace!\n"; }
                else cout << "Tento lektvar nemas nebo spatna volba. Ztracis tah!\n";
            }
        }
        
        if(mana < 0) mana = 0;
        if(hpenemy < 0) hpenemy = 0;

        if(hpenemy != 0 && chciplnamanu == false){
            sleep(1); cout << "\n\nNa rade je Mini-Boss!"; sleep(1); cout << "\nMini-Boss se rozprahuje!\n";
            edamage = 10 + (rand() % 50);
            sleep(1);
            if(odrazedlo == false){ cout << "A dal ti za " << edamage << "!\n"; zivoty -= edamage; }
            else{ cout << "Pouzil jsi svuj stit a odrazil utok.\n"; odrazedlo = false; }
        }
        if(zivoty <= 0){ zivoty = 0; sleep(1); }
        
    }while(zivoty > 0 && hpenemy > 0 && chciplnamanu == false);

    if(chciplnamanu == true || zivoty == 0){
        if(chciplnamanu == true) cout << "V BOJI SI PADL VYCERPANIM!\n";
        if(zivoty == 0) cout << "MINI-BOSS TE ZABIL!\n";
        return false;
    }

    enemykilled++;
    xp += 150;
    zlato += 100;
    cout << "\nPorazil jsi Mini-Bosse!\n Ziskal jsi zarucenych 100 zlata a 150 xp!\n";
    return true;
}

//hlavni_boss
bool hlavni_boss(int &zivoty, int &mana, int &max_zivoty, int &max_mana, int &zlato, int &spentpenize, int &enemykilled, int &xp, bool odraz, bool cheal, bool dvadamage, int &pocetls, int &pocetlo, int &pocetlr){
    int hpenemy = 400;
    bool chciplnamanu = false;
    int damage = 0;
    int bonus_dmg = 0;
    bool odrazedlo = false;
    string hlaskynetrefa[] ={"Netrefils!", "Proboha! Nauc se mirit!", "Jak jsi to mohl netrefit!", "O pet metru vedle!", "Zkus to priste!"};

    int kolo = 1;
    int boss_dmg_stack = 0;

    cout << "\n==== HLAVNI BOSS ====\n";
    sleep(1);
    cout << "Zjevil se ti Geargrind - ozubeny kolos, ktery se rozjizdi pomalu, ale s drtivou silou.\n";
    sleep(2);

    do{
        cout << "\n\n====Staty battlu====";
        cout << "\nTvoje HP: " << zivoty << "/" << max_zivoty << "\nMana: " << mana << "/" << max_mana << "\nGeargrind HP: " << hpenemy << endl;
        if(bonus_dmg > 0) cout << "(Lektvar sily aktivni: +" << bonus_dmg << " damage)\n";
        sleep(1);
        
        cout << "\nVyber utok!\n 1) Lehky (75 procent na hit; - 15 many)\n 2) Stredni (60 procent na hit; -25 many)\n 3) Heavy (35 procent na hit; -40 many)\n";
        if(odraz == true) cout << " 4) Odrazeni utoku (odrazi pristi enemy utok; -60 many)\n";
        else if(cheal == true) cout << " 4) Blesk (Zasahne vsechny enemy najednou heavy utokem (50 procent na hit); -80 many)\n";
        else if(dvadamage == true) cout << " 4) Ultra utok (2x damage z predesleho utoku (50 procent na hit); - 60 many)\n";
        cout << " 5) Pouzit lektvar\n";

        if(mana <= 0 && zivoty > 0) chciplnamanu = true;
    
        if(chciplnamanu == false){
            int vyberu;
            do{
                cout << "Vyber: "; cin >> vyberu;
                if(vyberu < 1 || vyberu > 5) cout << "\nZadal jsi spatnou hodnotu!\n";
            }while(vyberu < 1 || vyberu > 5);
        
            if(vyberu == 1){
                if(mana >= 15){
                    mana -= 15; int snautok = rand() % 100;
                    if(snautok <= 75){ damage = 1 + (rand() % 35) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi Geargrindovi " << damage << " hp!"; hpenemy -= damage; }
                    else{ cout << hlaskynetrefa[rand() % 5]; }
                }else cout << "Nedostatek many!";
            }else if(vyberu == 2){
                if(mana >= 25){
                    mana -= 25; int snautok = rand() % 100;
                    if(snautok <= 60){ damage = 20 + (rand() % 50) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi Geargrindovi " << damage << " hp!"; hpenemy -= damage; }
                    else{ cout << hlaskynetrefa[rand() % 5]; }
                }else cout << "Nedostatek many!";
            }else if(vyberu == 3){
                if(mana >= 40){
                    mana -= 40; int snautok = rand() % 100;
                    if(snautok <= 35){ damage = 50 + (rand() % 50) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi Geargrindovi " << damage << " hp!"; hpenemy -= damage; }
                    else{ cout << hlaskynetrefa[rand() % 5]; }
                }else cout << "Nedostatek many";
            }else if(vyberu == 4){
                if(odraz == true){
                    if(mana >= 60){ mana -= 60; cout << "Abilita pouzita\n"; odrazedlo = true; }
                    else cout << "Nedostatek many!";
                }else if(cheal == true){
                    if(mana >= 80){
                        mana -= 80; int snautok = rand() % 100;
                        if(snautok <= 50){ damage = 50 + (rand() % 50) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi Geargrindovi " << damage << " hp!"; hpenemy -= damage; }
                        else{ cout << hlaskynetrefa[rand() % 5]; }
                    }else cout << "Nedostatek many!";
                }else if(dvadamage == true){
                    if(mana >= 50){
                        mana -= 50; int snautok = rand() % 100;
                        if(snautok <= 50){ damage = (damage > 0 ? damage * 2 : 20 * 2) + bonus_dmg; sleep(1); cout << "Uspech!\nUbral jsi Geargrindovi " << damage << " hp!"; hpenemy -= damage; }
                        else{ cout << hlaskynetrefa[rand() % 5]; }
                    }else cout << "Nedostatek many";
                }
            }else if(vyberu == 5){
                cout << "\nJakej lektvar chces pouzit?\n 1) Lektvar sily (" << pocetls << "x)\n 2) Lektvar oziveni (" << pocetlo << "x)\n 3) Lektvar regenerace (" << pocetlr << "x)\n Zpet jinou klavesou\nVyber: ";
                int vyberl; cin >> vyberl;
                if(vyberl == 1 && pocetls > 0){ pocetls--; bonus_dmg += 20; cout << "Vypil jsi lektvar sily!\n"; }
                else if(vyberl == 2 && pocetlo > 0){ pocetlo--; zivoty = max_zivoty; cout << "Vypil jsi lektvar oziveni!\n"; }
                else if(vyberl == 3 && pocetlr > 0){ pocetlr--; mana = max_mana; cout << "Vypil jsi lektvar regenerace!\n"; }
                else cout << "Tento lektvar nemas nebo spatna volba. Ztracis tah!\n";
            }
        }
        
        if(mana < 0) mana = 0;
        if(hpenemy < 0) hpenemy = 0;

        if(hpenemy != 0 && chciplnamanu == false){
            sleep(1); cout << "\n\nNa rade je Geargrind!"; sleep(1);
            
            boss_dmg_stack += 3;
            int edamage = 15 + boss_dmg_stack + (rand() % 20);
            
//prehrati
            if(kolo % 4 == 0){
                int prehreje = rand() % 2;
                if(prehreje == 1){
                    cout << "\nGeargrind je na hranici roztrzeni, ale utoci jako nikdy predtim!\n";
                    hpenemy -= 10;
                    edamage *= 2;
                    sleep(1);
                }
            }

            cout << "\nGeargrind drti vse co mu stoji v ceste!\n";
            sleep(1);
            if(odrazedlo == false){ cout << "A dal ti za " << edamage << "!\n"; zivoty -= edamage; }
            else{ cout << "Pouzil jsi svuj stit a odrazil ten masivni utok.\n"; odrazedlo = false; }
        }
        
        if(zivoty <= 0){ zivoty = 0; sleep(1); }
        kolo++;
        
    }while(zivoty > 0 && hpenemy > 0 && chciplnamanu == false);

    if(chciplnamanu == true || zivoty == 0){
        if(chciplnamanu == true) cout << "V BOJI SI PADL VYCERPANIM!\n";
        if(zivoty == 0) cout << "GEARGRIND TE ROZDRTIL!\n";
        return false;
    }

    enemykilled++;
    cout << "\n!!! PORAZIL JSI HLAVNIHO BOSSE GEARGRINDA WOOOO DAMN SON WHERE'D YOU FIND THIS !!!\n";
    return true;
}


int main(){
    srand(time(0));
    cout << "=========Vitej do hry=========\n";
    cout << "Vyber si postavu:\n ";

    int zivoty = 0, max_zivoty = 0;
    int mana = 0, max_mana = 0;
    int zlato = 0;
    int vpostavy;
    bool cheal = false;
    bool odraz = false;
    bool dvadamage = false;
    int enemykilled = 0;
    int spentpenize = 0;
    int xp = 0;
    int level = 1;
    int pocetls = 0;
    int pocetlo = 0;
    int pocetlr = 0;

    do{
        cout << "1)\n----Bojovnik----\n=  Zivoty: 150\n=  Mana: 140\n=  Special perk: Odrazeni utoku\n\n";
        cout << "2) \n----Carodej----\n=  Zivoty: 90\n=  Mana: 200\n=  Special perk: Blesk (Zasahne vsechny enemy najednou)\n\n";
        cout << "3)\n----Tank----\n=  Zivoty: 250\n=  Mana: 100\n=  Special perk: Ultra utok (Da 2x vetsi damage)";
        cout << "\n\n Vyber: ";
        cin >> vpostavy; 
        cout << endl;
        switch(vpostavy){
            case 1:
                cout << "Zvolen Bojovnik!\n";
                max_zivoty = 150; zivoty = 150;
                max_mana = 140; mana = 140;
                odraz = true;
                break;
            case 2:
                cout << "Zvolen Carodej!\n";
                max_zivoty = 90; zivoty = 90;
                max_mana = 200; mana = 200;
                cheal = true;
                break;
            case 3:
                cout << "Zvolen Tank!\n";
                max_zivoty = 250; zivoty = 250;
                max_mana = 100; mana = 100;
                dvadamage = true;
                break;
            default:
                cout << "Spatna hodnota!\n";
                break;
        }
    }while(vpostavy < 1 || vpostavy > 3);

    vesnice(zivoty, mana, max_zivoty, max_mana, zlato, spentpenize, pocetls, pocetlo, pocetlr, level);
    
    if(!boj_s_1_enemy(zivoty, mana, max_zivoty, max_mana, zlato, spentpenize, enemykilled, xp, odraz, cheal, dvadamage, pocetls, pocetlo, pocetlr)) return 0; 
    hrac_level(xp, level, zivoty, mana, max_zivoty, max_mana);
    
    if(!boj_s_1_enemy(zivoty, mana, max_zivoty, max_mana, zlato, spentpenize, enemykilled, xp, odraz, cheal, dvadamage, pocetls, pocetlo, pocetlr)) return 0; 
    hrac_level(xp, level, zivoty, mana, max_zivoty, max_mana);
    
    if(!boj_s_2_enemy(zivoty, mana, max_zivoty, max_mana, zlato, spentpenize, enemykilled, xp, odraz, cheal, dvadamage, pocetls, pocetlo, pocetlr)) return 0; 
    hrac_level(xp, level, zivoty, mana, max_zivoty, max_mana);
    
    if(!mini_boss(zivoty, mana, max_zivoty, max_mana, zlato, spentpenize, enemykilled, xp, odraz, cheal, dvadamage, pocetls, pocetlo, pocetlr)) return 0; 
    hrac_level(xp, level, zivoty, mana, max_zivoty, max_mana);
    
    vesnice(zivoty, mana, max_zivoty, max_mana, zlato, spentpenize, pocetls, pocetlo, pocetlr, level);

    if(!boj_s_1_enemy(zivoty, mana, max_zivoty, max_mana, zlato, spentpenize, enemykilled, xp, odraz, cheal, dvadamage, pocetls, pocetlo, pocetlr)) return 0; 
    hrac_level(xp, level, zivoty, mana, max_zivoty, max_mana);

    if(!boj_s_2_enemy(zivoty, mana, max_zivoty, max_mana, zlato, spentpenize, enemykilled, xp, odraz, cheal, dvadamage, pocetls, pocetlo, pocetlr)) return 0; 
    hrac_level(xp, level, zivoty, mana, max_zivoty, max_mana);

    if(!boj_s_2_enemy(zivoty, mana, max_zivoty, max_mana, zlato, spentpenize, enemykilled, xp, odraz, cheal, dvadamage, pocetls, pocetlo, pocetlr)) return 0; 
    hrac_level(xp, level, zivoty, mana, max_zivoty, max_mana);

    if(!mini_boss(zivoty, mana, max_zivoty, max_mana, zlato, spentpenize, enemykilled, xp, odraz, cheal, dvadamage, pocetls, pocetlo, pocetlr)) return 0; 
    hrac_level(xp, level, zivoty, mana, max_zivoty, max_mana);

    vesnice(zivoty, mana, max_zivoty, max_mana, zlato, spentpenize, pocetls, pocetlo, pocetlr, level);

    if(!boj_s_2_enemy(zivoty, mana, max_zivoty, max_mana, zlato, spentpenize, enemykilled, xp, odraz, cheal, dvadamage, pocetls, pocetlo, pocetlr)) return 0; 
    hrac_level(xp, level, zivoty, mana, max_zivoty, max_mana);

    if(!boj_s_2_enemy(zivoty, mana, max_zivoty, max_mana, zlato, spentpenize, enemykilled, xp, odraz, cheal, dvadamage, pocetls, pocetlo, pocetlr)) return 0; 
    hrac_level(xp, level, zivoty, mana, max_zivoty, max_mana);

    if(!boj_s_3_enemy(zivoty, mana, max_zivoty, max_mana, zlato, spentpenize, enemykilled, xp, odraz, cheal, dvadamage, pocetls, pocetlo, pocetlr)) return 0; 
    hrac_level(xp, level, zivoty, mana, max_zivoty, max_mana);

    vesnice(zivoty, mana, max_zivoty, max_mana, zlato, spentpenize, pocetls, pocetlo, pocetlr, level);

    if(!hlavni_boss(zivoty, mana, max_zivoty, max_mana, zlato, spentpenize, enemykilled, xp, odraz, cheal, dvadamage, pocetls, pocetlo, pocetlr)) return 0; 
    hrac_level(xp, level, zivoty, mana, max_zivoty, max_mana);


    cout << "\n\nGRATULUJI! PROSEL JSI CELOU HRU AZ DO KONCE!\n";
    cout << "Tvoje finalni staty:\nZabiti enemaci: " << enemykilled << "\nUtracene penize: " << spentpenize << "\nDosazeny  Level: " << level << endl;
}