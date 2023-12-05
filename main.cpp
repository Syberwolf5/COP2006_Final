#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <filesystem>
#include <cstring>
#include <array>

using namespace std;

class game{
public:
    bool q=false,orbs=false,keys=false,lis=false,coins=false,doors=false,kys=false,desks=false,lis2=false;
    bool *qp = &q;
    bool *os = &orbs;
    bool *ks = &keys;
    bool *ls = &lis;
    bool *ls2 = &lis2;
    bool *cs = &coins;
    bool *ds = &doors;
    bool *des = &desks;
    bool *ks2 = &kys;
    int kl;
    int *ptr = &kl;

    void lines(){
        int i;
        for (i = 0; i <= 30; i++) {
            cout << "-";
        }
        cout<<endl;
    }

    int menu(){
        int a=0,b;
        while (a==0){
            lines();
            string o,o2;
            char in[25];
            char key1[]="start";
            char key2[]="load";
            char key3[]="exit";
            cout<<"Would you like to: \nstart\nload\nexit"<<endl;
            lines();
            cin>>in;
            if (strcmp (in,key1) == 0){
                b=1;
                save(o,b);
                break;
            }
            else if (strcmp (key2,in) == 0){
                cout<<"Load out of order"<<endl;
                /*b=2;
                save(o,b);
                break;*/
            }
            else if (strcmp (key3,in) == 0){
                cout<<"Goodbye!";
                a=1;
                b=0;
                break;
            }
            else{
                cout<<"Incorrect input!"<<endl;
            }
        }
        return 0;
    }

    void save2(string a,string b) {
        fstream file;
        string s, l, l2, savename;
        int i;
        const string txt = ".txt";
        vector<string> load{};
        if (file) {
            if (file.is_open()) {
                /*a=Action(a);
                 b=item(b);*/
                file<<a<<" "<<b<<"\n";
            }
            else{
                cout << "\nEnter the name of your save:" << endl;
                cin>>s;
                savename = s + txt;
                file.open(savename,ios::in);
                while (!file.eof()) {
                    string str;
                    file >> str;
                    load.push_back(str);
                }

                a = load.at(i);
                file.close();
                file.open(savename,ios::out);
            }
        } else {
            cout << "\nEnter the name of your save:" << endl;
            cin >> s;
            savename = s + txt;
            file.open(savename,ios::out);
        }
    }

    void save(string o,int b){
        fstream file;
        string s,l,l2,savename;
        const string txt = ".txt";
        switch (b){
            case 1:
                //cout << "\nEnter the name of your save:" << endl;
                //cin>>s;
                savename = s + txt;
                file.open(savename,ios::out);
                file.close();
                action(o);
                break;
            case 2:
                cout << "\nEnter the name of your save:" << endl;
                cin>>s;
                savename = s + txt;
                file.open(savename,ios::in);
                while (!file.eof()){
                    file >> l;
                    load_act(l,l2);
                }
                file.close();
                file.open(savename,ios::app);
                action(o);
                break;
            case 3:
                file.open(savename,ios::app);
                file<<o<<"\n";
                file.close();
                action(o);
            default:
                menu();
    }}

    int findact(string a){
        bool k,l,i,j,h,e;
        int o;
        k = a.find("lookat", 0, 6);
        l = a.find("use", 0, 3);
        i = a.find("open", 0, 4);
        j = a.find("take", 0, 4);
        h = a.find("help",0,4);
        e = a.find("exit",0,4);
        if (k==0){
            o=1;
        }
        else if (l == 0){
            o=2;
        }
        else if(i == 0){
            o=3;
        }
        else if (j == 0){
            o=4;
        }
        else if (h == 0){
            o=5;
        }
        else if(e == 0){
            o=6;
        }
        else{
            o=0;
        }
        return o;
    }

    int finditem(string a){
        bool d,w,b,r,pi,e,p,u,s,de,k,orb,c,l;
        int o=0;
        d = a.find("door", 0, 4);
        w = a.find("wall", 0, 4);
        b = a.find("bag", 0, 3);
        r = a.find("room", 0, 4);
        s = a.find("safe", 0, 4);
        e = a.find("engraving", 0, 6);
        de = a.find("desk", 0, 4);
        p = a.find("podium",0,6);
        u = a.find("shelf", 0, 5);
        pi = a.find("pile", 0, 4);
        k = a.find("key", 0, 3);
        orb = a.find("orb", 0, 3);
        c  = a.find("coin", 0, 4);
        l = a.find("light", 0, 5);
        if (d==0){
            o=1;
        }
        else if (w == 0){
            o=2;
        }
        else if(b ==0){
            o=3;
        }
        else if (r == 0){
            o=4;
        }
        else if (pi == 0){
            o=5;
        }
        else if (e == 0){
            o=6;
        }
        else if (p == 0){
            o=7;
        }
        else if (u == 0){
            o=8;
        }
        else if (s == 0){
            o=9;
        }
        else if (de == 0){
            o=10;
        }
        else if(k==0){
            o=11;
        }
        else if(orb == 0){
            o=12;
        }
        else if(c ==0){
            o=13;
        }
        else if(l ==0){
            o=14;
        }
        return o;
    }

    void lookat(int p){
        bool po = *qp;
        bool ors = *os;
        bool ligs = *ls;
        bool ligs2 = *ls2;
        bool key_state = *ks;
        bool key_state2 = *ks2;
        bool desk_state = *des;
        bool coin_state = *cs;

        switch (p){
            case 0:
                cout<<"You stare off into space."<<endl;
            case 1:
                cout<<"The door is closer to a wall than a door with no visible handles or hinges"<<endl;
                break;
            case 2:
                cout<<"In front of you is a wall with a door. Around the door is an odd engraving "<<endl;
                cout<<"There is nothing else on the walls."<<endl;
                break;
            case 3:
                cout<<"It is an average sized backpack that you woke up with"<<endl;
                break;
            case 4:
                cout<<"You look around the room and see a safe, a desk, a shelf, and a pile of trash."<<endl;
                cout<<"In front of you is a podium for something."<<endl;
                break;
            case 5:
                cout<<"It is a pile of trash, but you see a broken key in the pile."<<endl;
                break;
            case 6:
                cout<<"You look at the engraving around the door, at the top you see a glass circle, ";
                cout<<"to the right you see a key hole, and to the left you see a circular indent."<<endl;
                break;
            case 7:
                cout<<"It is a stand about waist high with an indent on the top."<<endl;
                break;
            case 8:
                cout<<"It is a plain shelf with seven cans on the top shelf, nine boxes on the middle shelf, and four ";
                cout<<"jars on the bottom shelf."<<endl;
                break;
            case 9:
                if (!po){
                    cout<<"It is a metal safe with a dail and handle on it, above the dial is the number 3."<<endl;
                }
                else if (po){
                    if(!ors){
                        cout<<"The safe is open and inside is a glassy orb."<<endl;
                    }
                    else if (ors){
                        cout<<"The safe is open and empty."<<endl;
                    }
                }
                break;
            case 10:
                if(!desk_state){
                    cout<<"It is a simple wooden desk with one drawer."<<endl;
                }
                else if (desk_state){
                    if(!coin_state){
                        cout<<"The desk has an open drawer with a coin inside"<<endl;
                    }
                    else if (coin_state){
                        cout<<"The desk has an open drawer with nothing inside"<<endl;
                    }
                }
                break;
            case 11:
                if(key_state){
                    cout<<"It is a weathered key that is broken in multiple spots."<<endl;
                }
                else if (!key_state){
                    if(!key_state2){
                        cout<<"You think you say what looks like a broken key on the floor"<<endl;
                    }
                    else if (key_state2){
                        cout<<"The key is now whole and a shiny brass color."<<endl;
                    }
                }
                break;
            case 12:
                if(ors){
                    cout<<"It is a glass orb but you are unable to see through it."<<endl;
                }
                else {
                    cout<<"What orb?"<<endl;
                }
                break;
            case 13:
                if(!desk_state){
                    cout<<"What coin?"<<endl;
                }
                else if (desk_state){
                    if(!coin_state){
                        cout<<"The coin is still in the drawer where you last saw i.t"<<endl;
                    }
                    else if (coin_state){
                        cout<<"It is a golden coin with engravings similar to those around the door."<<endl;
                    }
                }
                break;
            case 14:
                if(ligs){
                    if (ligs2){
                        cout<<"The beam of light on the floor is in the shape of a key."<<endl;
                    }
                    else{
                        cout<<"There is a beam of light shining on the the podium."<<endl;
                    }
                }
                else{
                    cout<<"The lights in the room are just bright enough to see small items."<<endl;
                }
                break;
        }
    }

    void use(int p){
        string i;
        int q,o;
        switch (p){
            case 0:
                cout<<"You use nothing on"<<endl;
                cin>>i;
                o=finditem(i);
                useon(p,o);
                break;
            case 1:
                if (ds){
                    cout<<"You use the door to escape the door."<<endl;
                    menu();
                }
                else{
                    cout<<"You can't use the door"<<endl;
                }
                break;
            case 2:
                cout<<"with"<<endl;
                cin>>i;
                o=finditem(i);
                useon(p,o);
                break;
            case 3:
                cout<<"What do you put in bag?"<<endl;
                cin>>i;
                q=finditem(i);
                bag(p+1,q);
                break;
            case 5:
                cout<<"Why would you use a pile of trash?"<<endl;
                break;
            case 6:
                cout<<"What do you use on it?"<<endl;
                cin>>i;
                o=finditem(i);
                useon(p,o);
                break;
            case 7:
                cout<<"with"<<endl;
                cin>>i;
                o=finditem(i);
                useon(p,o);
                break;
            case 8:
                cout<<"place what on shelf"<<endl;
                cin>>i;
                o=finditem(i);
                useon(p,o);
                break;
            case 9:
                safe(qp);
                break;
            case 10:
                cout<<"You can't figure out what to use the desk for."<<endl;
                break;
            case 11:
                if(ks || ks2){
                    cout<<"on"<<endl;
                    cin>>i;
                    o=finditem(i);
                    useon(p,o);
                }
                break;
            case 12:
                if (os){
                    cout<<"on"<<endl;
                    cin>>i;
                    o=finditem(i);
                    useon(p,o);
                }
                break;
            case 13:
                if(cs){
                    cout<<"on"<<endl;
                    cin>>i;
                    o=finditem(i);
                    useon(p,o);
                }
                break;
            case 14:
                if (ls){
                    cout<<"with"<<endl;
                    cin>>i;
                    o=finditem(i);
                    useon(p,o);
                }
                break;
        }
    }

    void useon(int l,int p){
        switch (p){
            case 0:
                if(l==2){
                    cout<<"You throw hands with the wall.\n.\n.\n.\n.\n.\nYour hands now hurt."<<endl;
                }
                else{
                cout<<" nothing"<<endl;
                }
                break;
            case 1:
                if(l == 11){
                    cout<<"There is no key hole on the door"<<endl;
                }
                break;
            case 2:
                if(l == p){
                    cout<<"You square the wall";
                }
                else if(l==11 || l==13){
                    cout<<"You throw it at the wall but nothing happens."<<endl;
                }
                break;
            case 3:
                if (l>=11 && l<=13){
                    bag(4,l);
                }
                else{
                    cout<<"You can't use the bag on that."<<endl;
                }
                break;
            case 4:
                cout<<"You can't use that on the room"<<endl;
                break;
            case 5:
                if(ks ||ks2){
                    cout<<"You don't want to rifle through the pile anymore than you had to."<<endl;
                }
                else{
                    cout<<"It does nothing."<<endl;
                }
                break;
            case 6:
                if (l==11){
                    if (ks2){
                        cout<<"You slot the key in the hole in the engraving and the door suddenly slides upward."<<endl;
                        *ds=true;
                    }
                    else{
                        cout<<"With how the key is broken, it is impossible to slot in."<<endl;
                    }
                }
                else if (l==13){
                    cout<<"You slot the coin in the engraving and a beam of light shines from the door to the podium."<<endl;
                    *ls = true;
                }
                else{
                    cout<<"You can't use that on the engraving."<<endl;
                }
                break;
            case 7:
                if(l==12){
                    if (ls){
                        cout<<"You place the orb on the podium and the beam of light shines onto the orb."<<endl;
                        cout<<"The light projects a shape onto the floor behind the podium."<<endl;
                        *ls2 = true;
                    }
                    else{
                        cout<<"The orb is a perfect fit but nothing happens."<<endl;
                    }
                }
                else if (l==13 || l==11){
                    cout<<"You place it on the podium but nothing happens."<<endl;
                }
                else{
                    cout<<"You can't place that on the podium."<<endl;
                }
                break;
            case 8:
                if(l >= 11 && l <= 13){
                    cout<<"You place it on the shelf but nothing happens."<<endl;
                }
                else{
                    cout<<"You can't place that on shelf."<<endl;
                }
                break;
            case 9:
                if (l==11){
                    if (ks2){
                        cout<<"You look around the safe and find a hole you can slot the key in."<<endl;
                        cout<<"The safe opens and inside is an orb."<<endl;
                        *qp=true;
                    }
                    else{
                        cout<<"With how the key is broken, it is impossible to slot in."<<endl;
                    }
                }
                else{
                    cout<<"You can't use that on the safe."<<endl;
                }
                break;
            case 10:
                cout<<"You can't use that on the desk."<<endl;
                break;
            case 11:
                if (l==2){
                    cout<<"You throw the key at the wall in frustration."<<endl;
                    if(ks2){
                        cout<<"The key breaks"<<endl;
                        *ks2= false;
                        *ks =true;
                    }
                }
                else if(l == 8){
                    cout<<"You place it on the shelf but nothing happens."<<endl;
                }
                else if (l==9){
                    if (ks2){
                        cout<<"You look around the safe and find a hole you can slot the key in."<<endl;
                        cout<<"The safe opens and inside is an orb."<<endl;
                        *qp=true;
                    }
                    else{
                        cout<<"With how the key is broken, it is impossible to slot in."<<endl;
                    }
                }
                else if(l==6){
                    if (ks2){
                        cout<<"You slot the key in the hole in the engraving and the door suddenly slides upward."<<endl;
                        *ds=true;
                    }
                    else{
                        cout<<"With how the key is broken, it is impossible to slot in."<<endl;}
                }
                else if(l == 1){
                    cout<<"There is no key hole on the door"<<endl;
                }
                else {
                    cout<<"You can't use that with the key."<<endl;
                }
                break;
            case 12:
                if (l==2){
                    cout<<"You throw the orb at the wall"<<endl;
                    cout<<"The orb shatters on impact, trapping you in the room forever."<<endl;
                    menu();
                }
                else if(l == 8){
                    cout<<"You place it on the shelf but nothing happens."<<endl;
                }
                break;
            case 13:
                if (l==2){
                    cout<<"You throw the coin at the wall in frustration."<<endl;
                }
                else if(l == 8){
                    cout<<"You place it on the shelf but nothing happens."<<endl;
                }
                break;
            case 14:
                if (l==11){
                    if(ls2){
                        cout<<"You place the key in the light and by some miracle the key looks brand new."<<endl;
                        *ks = false;
                        *ks2 = true;
                    }
                    else{
                        cout<<"Nothing happens."<<endl;
                    }
                }
                else{
                    cout<<"Nothing happens."<<endl;
                }
                break;
        }
    }

void take(int j,int p){
    switch (p){
        case 0:
            cout<<"You can't take nothing."<<endl;
        case 1:
            cout<<"The door can't be removed from the wall."<<endl;
            break;
        case 2:
            cout<<"It's too heavy"<<endl;
            break;
        case 3:
            cout<<"You already have the bag."<<endl;
            break;
        case 5:
            cout<<"You don't want random trash in you bag."<<endl;
            break;
        case 6:
            cout<<"You can't take something attached to the wall."<<endl;
            break;
        case 7:
            cout<<"It is attached to the floor and can't be taken."<<endl;
            break;
        case 8:
            cout<<"It is too big to take."<<endl;
            break;
        case 9:
            cout<<"It's too heavy too take"<<endl;
            break;
        case 10:
            cout<<"It is too big to take."<<endl;
            break;
        case 11:
            if (!ks || !ks2){
                bag(j,p);
            }
            else{
                cout<<"What key?";
            }
            break;
        case 12:
            if(qp){
                if(!os){
                    bag(j,p);
                }
                else{
                    cout<<"You already have it."<<endl;
                }
            }
            else{
                cout<<"What orb?";
            }
            break;
        case 13:
            if(!cs){
                bag(j,p);
            }else{
                cout<<"What coin?";
            }
            break;
        case 14:
            cout<<"It's too light to hold."<<endl;
            break;
    }
    }

    void open(int p){
        int o;
        switch (p){
            case 0:
                cout<<"You open up to no one"<<endl;
            case 1:
                cout<<"No matter which angle you try, it doesn't open"<<endl;
                break;
            case 2:
                cout<<"You open up to the wall.";
                cout<<"\n.\n.\n.\n.\n.\nIt doesn't respond."<<endl;
                break;
            case 3:
                bag(p,o);
                break;
            case 5:
                cout<<"You can't because it is already out in the open"<<endl;
                break;
            case 6:
                cout<<"It is attached to the wall and can't be opened."<<endl;
                break;
            case 7:
                cout<<"There aren't any drawers to open."<<endl;
                break;
            case 8:
                cout<<"It is a shelf without anything to open."<<endl;
                break;
            case 9:
                safe(qp);
                break;
            case 10:
                cout<<"You open the drawer and inside is an engraved coin"<<endl;
                break;
            case 11:
                cout<<"The key is too small to open, not that there is anything to open."<<endl;
                break;
            case 12:
                if (qp){
                    cout<<"You break open the orb.\n.\n.\n.\n.\n.\n.\nThere wasn't anything inside."<<endl;
                    cout<<"Since the orb is broken you are unable to escape."<<endl;
                    menu();
                }
                else{
                    cout<<"What orb?"<<endl;
                }
                break;
            case 13:
                if(cs){
                    cout<<"You try opening the coin in many ways and all you end up with is sore fingers."<<endl;
                }
                else{
                    cout<<"What coin?"<<endl;
                }
                break;
            case 14:
                cout<<"How would you open light?"<<endl;
                break;
        }
    }

    bool safe(bool *q){
        int a=0,e,r,t,c1=9,c2=7,c3=4;
        string y;
        bool change;
        while (a==0){
            cout<<"Enter the first number"<<endl;
            cin>>e;
            cout<<"Enter the second number"<<endl;
            cin>>r;
            cout<<"Enter the third number"<<endl;
            cin>>t;
            if(e==c1 && r==c2 && t==c3){
                a=1;
                cout<<"The safe opens with a click and inside is an glass orb"<<endl;
                change = true;
                *qp = &change;
                *os = true;
                return q;
            }
            else{
                cout<<"The safe remains closed."<<endl;
                cout<<"Try again? yes or no"<<endl;
                cin>>y;
                if (y == "no"){
                    a=1;
                    return q;
                }
                else if(y!="yes" || y!="no"){
                    cout<<"Invalid Input"<<endl;
                }
            }
        }
    }

    void bag(int p,int o){
        bool a,b,c;
        if(p==4){
            if(o==11){
                a=true;
                *ks = &a;
            }
            else if(o==12){
                b=true;
                *os = &b;
            }
            else if(o==13){
                c=true;
                *cs = &c;
            }
            else{
                cout<<"You can't put that in the bag."<<endl;
            }
            }
        else if(p==3){
            cout<<"Bag: ";
            if (*ks){
                cout<<" broken key,";
            }
            if (*cs){
                cout<<" coin,";
            }
            if (*os){
                cout<<" orb";
            }
            cout<<endl;
        }
    }

    void load_act(string a,string b){
        int j,p;
        j = findact(a);
        p = finditem(b);
        switch (j){
            case 1:
                lookat(p);
                load_act(a,b);
                break;
            case 2:
                cout<<"use";
                load_act(a,b);
                break;
            case 3:
                open(p);
                load_act(a,b);
                break;
            case 4:
                cout<<"take";
                load_act(a,b);
                break;
            default:
                cout<<"Error";
        }
    }

    void action(string a){
        lines();
        string b;
        ofstream file;
        string c,d;
        d = ' ';
        int j,p;

        if (*ptr == 0){
            cout<<"You awaken in a stone brick room with no windows."<<endl;
            lookat(4);
            cout<<"On your back is a bag."<<endl;
            cout<<"Actions: lookat,use,take,open,exit game"<<endl;
            lines();
            *ptr +=1;
        }

        cout<<"What would you like to do: (Type 'help game' for reopen context)"<<endl;
        cin>>a>>b;
        j = findact(a);
        p = finditem(b);
        c = a + d + b;
        switch (j){
            case 0:
                cout<<"Incorrect Input"<<endl;
                action(a);
                break;
            case 1:
                lookat(p);
                //save(c,3);
                action(a);
                break;
            case 2:
                use(p);
                action(a);
                //save(c,3);
                break;
            case 3:
                open(p);
                action(a);
               // save(c,3);
                break;
            case 4:
                take(j,p);
                action(a);
                //save(c,3);
                break;
            case 5:
                *ptr = 0;
                action(a);
                //save(c,3);
                break;
            case 6:
                cout<<"Goodbye";
                //file.close();
                menu();
                break;
        }
    }

};

int main() {
    game g1;
    int a;
    cout << "Welcome to (Unnamed Puzzle Game)" << endl;
    a=g1.menu();
    cout<<a;
    return 0;
}