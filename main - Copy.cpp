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
                cout<<"Load out of order";
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
                cout << "\nEnter the name of your save:" << endl;
                cin>>s;
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

    string getob(){
        string l;
        cin>>l;
        return l;
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
        switch (p){
            case 0:
                cout<<"You look at nothing."<<endl;
            case 1:
                cout<<"The door is closer to a wall than a door with no visible handles or hinges"<<endl;
                break;
            case 2:
                cout<<"In front of you is a wall with a door. Around the door is an odd engraving "<<endl;
                cout<<"There is nothing else on the walls."<<endl;
                break;
            case 3:
                cout<<"It is an average sized backpack, you guess it can hold about 10 items."<<endl;
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
                cout<<"It is a stand about waist high with a bowl on the top."<<endl;
                break;
            case 8:
                cout<<"It is a plain shelf with seven cans on the top shelf, nine boxes on the middle shelf, and four ";
                cout<<"jars on the bottom shelf."<<endl;
                break;
            case 9:
                cout<<"It is a metal safe with a dail and handle on it, above the dial is the number 3."<<endl;
                break;
            case 10:
                cout<<"It is a simple wooden desk with one drawer."<<endl;
                break;
            case 11:
                cout<<"It is a weathered key that is broken in multiple spots."<<endl;
                break;
            case 12:
                cout<<"It is a glass orb but you are unable to see through it."<<endl;
                break;
            case 13:
                cout<<"It is a golden coin with engravings similar to those around the door."<<endl;
                break;
            case 14:
                cout<<"The beam of light on the floor is in the shape of a key."<<endl;
                break;
        }
    }

    void use(int p){
        string i;
        int q;
        switch (p){
            case 0:
                cout<<"You use nothing on"<<endl;
                cin>>i;
                useon(p,i);break;
            case 1:
                cout<<"You can't use the door"<<endl;
                break;
            case 2:
                cout<<"with"<<endl;
                cin>>i;
                useon(p,i);
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
                useon(p,i);
                break;
            case 7:
                cout<<"with"<<endl;
                cin>>i;
                useon(p,i);
                break;
            case 8:
                cout<<"place what on shelf"<<endl;
                cin>>i;
                useon(p,i);
                break;
            case 9:
                safe();
                break;
            case 10:
                cout<<"You can't figure out what to use the desk for."<<endl;
                break;
            case 11:
                cout<<"with"<<endl;
                cin>>i;
                useon(p,i);
                break;
            case 12:
                cout<<"with"<<endl;
                cin>>i;
                useon(p,i);
                break;
            case 13:
                cout<<"with"<<endl;
                cin>>i;
                useon(p,i);
                break;
            case 14:
                cout<<"with"<<endl;
                cin>>i;
                useon(p,i);
                break;
        }
    }

    void useon(int l,string p){
        bool d,w,b,r,pi,e,po,u,s,de,k,orb,c,li;
        int o=0;
        d = p.find("door", 0, 4);
        w = p.find("wall", 0, 4);
        b = p.find("bag", 0, 3);
        r = p.find("room", 0, 4);
        s = p.find("safe", 0, 4);
        e = p.find("engraving", 0, 6);
        de = p.find("desk", 0, 4);
        p = p.find("podium",0,6);
        u = p.find("shelf", 0, 5);
        pi = p.find("pile", 0, 4);
        k = p.find("key", 0, 3);
        orb = p.find("orb", 0, 3);
        c = p.find("coin", 0,4);
        li = p.find("light", 0, 5);
        if (d==0){
            o=1;
        }
        else if (w == 0){
            o=2;
        }
        else if(b ==0){
            o=10;
        }
        else if (r == 0){
            o=3;
        }
        else if (pi == 0){
            o=5;
        }
        else if (e == 0){
            o=6;
        }
        else if (po == 0){
            o=7;
        }
        else if (u == 0){
            o=8;
        }
        else if (s == 0){
            o=9;
        }
        else if (de == 0){
            o=4;
        }
        else if(k==0){
            o=11;
        }
        else if(orb == 0){
            o=12;
        }
        else if(c==0){
            o=13;
        }
        else if(li == 0){
            o=14;
        }
        switch (o){
            case 0:
                cout<<" nothing"<<endl;break;
            case 1:
                cout<<"The door is closer to a wall than a door with no visible handles or hinges"<<endl;
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

                break;
            case 10:
                cout<<"You can't use the bag on that."<<endl;
                break;
            case 11:
                cout<<"You throw the key at the wall in frustration."<<endl;
                break;
            case 12:
                cout<<"The orb shatters on impact, trapping you in the room forever."<<endl;
                menu();
                break;
            case 13:
                cout<<"You throw the coin at the wall in frustration."<<endl;
                break;
            case 14:
                cout<<"You can't throw light.";
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
            bag(j,p);
            break;
        case 12:
            bag(j,p);
            break;
        case 13:
            bag(j,p);
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
                safe();
                break;
            case 10:
                cout<<"You open the drawer and inside is an engraved coin"<<endl;
                break;
            case 11:
                cout<<"The key is too small to open, not that there is anything to open."<<endl;
                break;
            case 12:
                cout<<"You break open the orb.\n.\n.\n.\n.\n.\n.\nThere wasn't anything inside."<<endl;
                cout<<"Since the orb is broken you are unable to escape."<<endl;
                menu();
                break;
            case 13:
                cout<<"You try opening the coin in many ways and all you end up with is sore fingers."<<endl;
                break;
            case 14:
                cout<<"How would you open light?"<<endl;
                break;
        }
    }

    void safe(){
        int a,e,r,t,c1=9,c2=7,c3=4;
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
            }
        }
    }

    void bag(int p,int o){
        int i;
        array <string,3> bag{};
        if(p==3){
            cout<<"Bag:";
            for(i=0;i<=2;i++){
                cout<<bag[i]<<" ";
            }
        }
        else if(p==4){
            if(o==11){
                bag[1]="key";
            }
            else if(o==12){
                bag[2]="orb";
            }
            else if(o==13){
                bag[3]="coin";
            }
            else{
                cout<<"You can't put that in the bag."<<endl;
            }
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
        cout<<"What would you like to do: (Type 'help game' for actions and 'exit game' to quit)"<<endl;
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
                cout<<"Actions(lookat,use,open,take)"<<endl;
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