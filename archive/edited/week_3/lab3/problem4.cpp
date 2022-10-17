#include<iostream>
using namespace std;

//Display
class LiqRetina_6_1{
    protected:
        string displayName = "6.1-inch (15.5 cm diagonal) Liquid Retina HD LCD display";
    public:
        LiqRetina_6_1(){};

        void display(){
            cout << displayName << endl;
        }
};

class SupRetina_6_1{
    protected:
        string displayName = "6.1-inch (15.5 cm diagonal) Super Retina XDR display";
    public:
        SupRetina_6_1(){};

        void display(){
            cout << displayName << endl;
        }
};

class SupRetina_5_4{
    protected:
        string displayName = "5.4-inch (13.7 cm diagonal) Super Retina XDR display";
    public:
        SupRetina_5_4(){};

        void display(){
            cout << displayName << endl;
        }
};
//processors

class A12{
    protected:
        string processorName = "A12 Bionic chip";
    
    public:
        A12(){};

        void processor(){
            cout << processorName << endl;
        }
};

class A14{
    protected:
        string processorName = "A14 Bionic chip";
    
    public:
        A14(){};

        void processor(){
            cout << processorName << endl;
        }
};

class A13{
    protected:
        string processorName = "A13 Bionic chip";
    
    public:
        A13(){};

        void processor(){
            cout << processorName << endl;
        }
};

//front camera 
class TD7{
    protected:
        string cameraName = "7MP TrueDepth camera";

    public:
        TD7(){};

        void frontCamera(){
            cout << cameraName << endl;
        }
};

class TD12{
    protected:
        string cameraName = "12MP TrueDepth camera";

    public:
        TD12(){};

        void frontCamera(){
            cout << cameraName << endl;
        }
};

//backcamera

class MP12{
    protected:
        string cameraName = "12MP camera";

    public:
        MP12(){};

        void camera(){
            cout << cameraName << endl;
        }
};

class enhancedMP12{
    protected:
        string cameraName = "Dual 12MP camera system (Ultra Wide, Wide, and Telephoto)";

    public:
        enhancedMP12(){};

        void camera(){
            cout << cameraName << endl;
        }
};

//charging

class Qi{
    protected:
        string chargingSupported = "works with Qi chargers";
    public:
        Qi(){};

        void charging(){
            cout << chargingSupported << endl;
        }
};

class MagSafe_Qi{
    protected:
        string chargingSupported = "Compatible with MagSafe accessories and Qi wireless chargers";
    public:
        MagSafe_Qi(){};

        void charging(){
            cout << chargingSupported << endl;
        }
};

//faceid
class faceID{
    public:
        faceID(){};

        void faceid(){
            cout << "faceID supported" << endl;
        }
};

//assembly
class iPhone12_assembly : public  faceID, public MP12, public TD12, public A14, public MagSafe_Qi {};

//finalProducts using assembly
class iPhone12mini : public iPhone12_assembly, public SupRetina_5_4{};
class iPhone12 : public iPhone12_assembly, public SupRetina_6_1{};

//final Products without assembly
class iPhoneXR : public LiqRetina_6_1, public TD7, public MP12, public faceID, public A12, public Qi{};
class iPhone11 : public SupRetina_6_1, public TD12, public MP12, public faceID, public A13, public Qi{};

int main(){
    iPhone11 _iPhone11;
    iPhone12 _iPhone12;
    iPhone12mini _iPhone12mini;
    iPhoneXR _iPhoneXR;

    cout << "iPhone11" << endl;
    _iPhone11.camera();
    _iPhone11.charging();
    _iPhone11.display();
    _iPhone11.frontCamera();
    _iPhone11.processor();
    cout << endl;

    cout << "iPhone12" << endl;
    _iPhone12.camera();
    _iPhone12.charging();
    _iPhone12.display();
    _iPhone12.frontCamera();
    _iPhone12.processor();
    cout << endl;

    cout << "iPhoneXR" << endl;
    _iPhoneXR.camera();
    _iPhoneXR.charging();
    _iPhoneXR.display();
    _iPhoneXR.frontCamera();
    _iPhoneXR.processor();
    cout << endl;

    cout << "iPhone12mini" << endl;
    _iPhone12mini.camera();
    _iPhone12mini.charging();
    _iPhone12mini.display();
    _iPhone12mini.frontCamera();
    _iPhone12mini.processor();
    cout << endl;


    return 0;
}
