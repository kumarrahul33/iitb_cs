#include<iostream>
using namespace std;

class videoIn{
    public:
        videoIn(){};

        void videoInFeature(){
            cout << "videoIn" << endl;
        }
};

class audioIn{
    public:
        audioIn(){};

        void audioInFeature(){
            cout << "audioIn" << endl;
        }
};

class internet{
    public:
        internet(){};

        void internetFeature(){
            std::cout << "internet" << std::endl;
        }
};

class videoOut{
    public:
        videoOut(){};

        void videoOutFeature(){
            cout << "videoOut" << endl;
        }
};

class audioOut{
    public:
        audioOut(){};

        void audioOutFeature(){
            cout << "audioOut" << endl;
        }
};

class cable{
    public:
        cable(){};

        void cableFeature(){
            cout << "cable" << endl;
        }
};

class TV1 : public videoIn, public audioIn{};
class TV1_1 : public TV1, public internet, public cable, public audioOut{};
class TV2 : public cable, public audioIn, public audioOut, public videoOut{};
class TV3 : public internet , public videoIn, public videoOut{};

int main() {
    TV1 a;
    TV1_1 b;
    TV2 c;
    TV3 d;

    cout << "\nTV1\n";
    b.audioInFeature();
    b.audioOutFeature();
    b.cableFeature();
    b.internetFeature();
    b.videoInFeature();

    cout << "\nTV2\n";
    a.audioInFeature();
    a.videoInFeature();

    cout << "\nTV3\n";
    c.audioInFeature();
    c.audioOutFeature();
    c.cableFeature();
    c.videoOutFeature();

    cout << "\nTV4\n";
    d.internetFeature();
    d.videoInFeature();
    d.videoOutFeature();

    return 0;
}




