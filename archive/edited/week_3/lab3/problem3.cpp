#include<iostream>
using namespace std;

//processors
class Intel_i5_8250U{
    protected:
        string processorName = "Intel Core i5-8250U 1.6-3.4Ghz";
    public:
        Intel_i5_8250U(){};

        void processor(){
            cout << processorName << endl; 
        }

};

class AMD_R5_2500U{
    protected:
        string processorName = "AMD Ryzen 5 2500U 2.0-3.6Ghz";
    public:
        AMD_R5_2500U(){};

        void processor(){
            cout << processorName << endl; 
        }

};

class Intel_i5_7200U{
    protected:
        string processorName = "Intel Core i5-8250U 2.5-3.1Ghz";
    public:
        Intel_i5_7200U(){};

        void processor(){
            cout << processorName << endl; 
        }

};

//storage
class SSD256{
    protected:
        string storageName = "256GB SSD";
    
    public:
        SSD256(){};

        void storage(){
            cout << storageName << endl;
        }
};

class HDD1000{
    protected:
        string storageName = "1TB HDD";
    
    public:
        HDD1000(){};

        void storage(){
            cout << storageName << endl;
        }
};

//Graphics
class NVIDIA_GF_MX150_2GB{
    protected:
        string graphicsName = "NVIDIA GeForce MX150 2GB GDDR5";
    
    public:
        NVIDIA_GF_MX150_2GB(){};

        void graphics(){
            cout << graphicsName << endl;
        }
};

class NVIDIA_GF_940MX_2GB{
    protected:
        string graphicsName = "NVIDIA GeForce 940MX 2GB GDDR5";
    
    public:
        NVIDIA_GF_940MX_2GB(){};

        void graphics(){
            cout << graphicsName << endl;
        }
};

class AMD_Radeon_Vega8{
    protected:
        string graphicsName = "AMD Radeon Vega 8";
    
    public:
        AMD_Radeon_Vega8(){};

        void graphics(){
            cout << graphicsName << endl;
        }
};

//Display

class matte_15_6{
    protected:
        string displayName = "15.6 TN matte 1920 X 1080";

    public:
        matte_15_6(){};

        void display(){
            cout << displayName << endl;
        }
};

class matte_17_3_IPS{
    protected:
        string displayName = "17.3 IPS matte 1920 X 1080";

    public:
        matte_17_3_IPS(){};
        
        void display(){
            cout << displayName << endl;
        }
};

//ram
class DDR4_8GB{
    protected:
        string ramProp = "8GB DDR4";
    
    public:
        DDR4_8GB(){};

        void ram(){
            cout << ramProp << endl;
        }
};

class DDR3L_8GB{
    protected:
        string ramProp = "8GB DDR3L";
    
    public:
        DDR3L_8GB(){};
        
        void ram(){
            cout << ramProp << endl;
        }
};

//Assemblies

class Acer_Aspire : public Intel_i5_8250U, public SSD256, public NVIDIA_GF_MX150_2GB{};
class Intel7200U_GF940_8D4_SSD_IPS : public Intel_i5_7200U, public SSD256, public NVIDIA_GF_940MX_2GB, public DDR4_8GB, public matte_17_3_IPS{};
class AMDR5_RV8_HDD : public AMD_R5_2500U, public HDD1000, public matte_15_6, public DDR4_8GB, public AMD_Radeon_Vega8{};
class Intel8250U_GF150_8D3L_SSD : public Intel_i5_8250U, public SSD256, public NVIDIA_GF_MX150_2GB, public DDR3L_8GB, public matte_15_6{};

//Acer_Aspire_series
class Acer_Aspire5_5504 : public Acer_Aspire, public DDR4_8GB, public matte_15_6{};
class Acer_Aspire5_E : public Acer_Aspire , public matte_15_6, public DDR3L_8GB{};
class Acer_Aspire5_53V6 : public Acer_Aspire5_5504{};



int main()
{
    //making the final products
    Intel7200U_GF940_8D4_SSD_IPS Acer_Aspire5_54GK_1;
    Acer_Aspire5_53V6 Acer_Aspirre5_53V6_1;
    Acer_Aspire5_5504 Acer_Aspire5_5504_1;
    Acer_Aspire5_E Acer_AspireE_1;
    AMDR5_RV8_HDD Acer_Aspire3_1;

    cout << "Acer_Aspire5_54GK" << endl;
    Acer_Aspire5_54GK_1.display();
    Acer_Aspire5_54GK_1.graphics();
    Acer_Aspire5_54GK_1.processor();
    Acer_Aspire5_54GK_1.ram();
    Acer_Aspire5_54GK_1.storage();

    cout << endl;

    cout << "Acer_Aspirre5_53V6" << endl;
    Acer_Aspirre5_53V6_1.display();
    Acer_Aspirre5_53V6_1.graphics();
    Acer_Aspirre5_53V6_1.processor();
    Acer_Aspirre5_53V6_1.ram();
    Acer_Aspirre5_53V6_1.storage();

    cout << endl;

    cout << "Acer_Aspire5_5504" << endl;
    Acer_Aspire5_5504_1.display();
    Acer_Aspire5_5504_1.graphics();
    Acer_Aspire5_5504_1.processor();
    Acer_Aspire5_5504_1.ram();
    Acer_Aspire5_5504_1.storage();

    cout << endl;

    cout << "Acer_AspireE" << endl;
    Acer_AspireE_1.display();
    Acer_AspireE_1.graphics();
    Acer_AspireE_1.processor();
    Acer_AspireE_1.ram();
    Acer_AspireE_1.storage();

    cout << endl;

    cout << "Acer_Aspire3" << endl;
    Acer_Aspire3_1.display();
    Acer_Aspire3_1.graphics();
    Acer_Aspire3_1.processor();
    Acer_Aspire3_1.ram();
    Acer_Aspire3_1.storage();

    return 0;
}

