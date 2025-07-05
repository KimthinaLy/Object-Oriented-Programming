#include <iostream>
#include <cstring>
using namespace std;

class Address
{
    char **houseNo;
    char road[30];
    char village[30];
    char subDistr[30];
    char district[30];
    char province[30];
    int postCode;

public:
    Address()
    {
        houseNo = nullptr;
        setHouseNo((char *)"No data");
        setRoad((char *)"");
        setVillage((char *)"");
        setSubDistr((char *)"");
        setDistr((char *)"");
        setProvince((char *)"");
        setPostCode(0);
    }
    Address(char *houseNum, char *r, char *vil, char *subD, char *d, char *p, int pCode)
    {
        houseNo = nullptr;
        setHouseNo(houseNum);
        setRoad(r);
        setVillage(vil);
        setSubDistr(subD);
        setDistr(d);
        setProvince(p);
        setPostCode(pCode);
    }
    Address(char *r, char *vil, char *subD, char *d, char *p, int pCode)
    {
        houseNo = nullptr;
        setHouseNo((char *)"No data");
        setRoad(r);
        setVillage(vil);
        setSubDistr(subD);
        setDistr(d);
        setProvince(p);
        setPostCode(pCode);
    }
    Address(char *vil, char *subD, char *d, char *p, int pCode)
    {
        houseNo = nullptr;
        setHouseNo((char *)"No data");
        setRoad((char *)"");
        setVillage(vil);
        setSubDistr(subD);
        setDistr(d);
        setProvince(p);
        setPostCode(pCode);
    }
    Address(char *subD, char *d, char *p, int pCode)
    {
        houseNo = nullptr;
        setHouseNo((char *)"No data");
        setRoad((char *)"");
        setVillage((char *)"");
        setSubDistr(subD);
        setDistr(d);
        setProvince(p);
        setPostCode(pCode);
    }
    Address(char *p, int pCode)
    {
        houseNo = nullptr;
        setHouseNo((char *)"No data");
        setRoad((char *)"");
        setVillage((char *)"");
        setSubDistr((char *)"");
        setDistr((char *)"");
        setProvince(p);
        setPostCode(pCode);
    }
    void setHouseNo(char *houseNum)
    {
        if (houseNo != nullptr)
        {
            delete[] houseNo[0];
            delete[] houseNo;
        }
        if (strcmp(houseNum, "") == 0)
        {
            houseNo = new char *[1];
            houseNo[0] = new char[strlen("unknown") + 1];
            strcpy(houseNo[0], (char *)"unknown");
        }
        houseNo = new char *[1];
        houseNo[0] = new char[strlen(houseNum) + 1];
        strcpy(houseNo[0], houseNum);
    }
    void setRoad(char *r)
    {
        strcpy(road, r);
    }
    void setVillage(char *vil)
    {
        strcpy(village, vil);
    }
    void setSubDistr(char *subDis)
    {
        strcpy(subDistr, subDis);
    }
    void setDistr(char *Dis)
    {
        strcpy(district, Dis);
    }
    void setProvince(char *prov)
    {
        strcpy(province, prov);
    }
    void setPostCode(int pCode)
    {
        postCode = pCode;
    }
    char *getHouseNo()
    {
        return houseNo[0];
    }
    char *getRoad()
    {
        return road;
    }
    char *getVillage()
    {
        return village;
    }
    char *getSubDistr()
    {
        return subDistr;
    }
    char *getDistr()
    {
        return district;
    }
    char *getProvince()
    {
        return province;
    }
    int getpostCode()
    {
        return postCode;
    }
    void showAddress()
    {
        cout << "---Address---: " << endl;
        cout << "House No.:" << houseNo[0] << endl; // cout<<*houseNo(the first char of houseNo only)
        cout << "Road: " << road << endl;
        cout << "Village: " << village << endl;
        cout << "Sub-District: " << subDistr << endl;
        cout << "District: " << district << endl;
        cout << "Province: " << province << endl;
        cout << "PostCode= " << postCode << endl;
    }
    ~Address()
    {
        if (houseNo != nullptr)
        {
            delete[] houseNo[0];
            delete[] houseNo;
        }

        cout << "Destructor: Address " << endl;
    }

    //----------------------------------hw9------------------------------------
    Address &operator+=(const Address &addr)
    {
        this->postCode += addr.postCode;
        return *this;
    }
    Address &operator=(const Address &addr)
    {
        if (this == &addr)
            return *this;
        if (houseNo != nullptr)
        {
            delete[] houseNo[0];
            delete[] houseNo;
        }

        if (addr.houseNo != nullptr)
        {
            this->houseNo = new char *[1];
            houseNo[0] = new char[strlen(addr.houseNo[0]) + 1];
            strcpy(houseNo[0], addr.houseNo[0]);
        }
        else
        {
            this->houseNo = new char *[1];
            houseNo[0] = new char[strlen("no data") + 1];
            strcpy(houseNo[0], (char *)"no data");
        }
        strcpy(this->road, addr.road);
        strcpy(this->village, addr.village);
        strcpy(this->subDistr, addr.subDistr);
        strcpy(this->district, addr.district);
        strcpy(this->province, addr.province);
        this->postCode = addr.postCode;
        return *this;
    }
    Address(const Address &addr)
    {
        cout << "copy constructor of class Address is called" << endl;
        if (addr.houseNo != 0)
        {
            this->houseNo = new char *[1];
            houseNo[0] = new char[strlen(addr.houseNo[0]) + 1];
            strcpy(houseNo[0], addr.houseNo[0]);
        }
        else
        {
            this->houseNo = new char *[1];
            houseNo[0] = new char[strlen("no data") + 1];
            strcpy(houseNo[0], (char *)"no data");
        }
        strcpy(this->road, addr.road);
        strcpy(this->village, addr.village);
        strcpy(this->subDistr, addr.subDistr);
        strcpy(this->district, addr.district);
        strcpy(this->province, addr.province);
        this->postCode = addr.postCode;
    }
    void print(ostream &os)
    {
        os << "---Address---: " << endl;
        os << "House No.:" << houseNo[0];
        os << ", Road: " << road;
        os << ", Village: " << village;
        os << ", Sub-District: " << subDistr;
        os << ", District: " << district;
        os << ", Province: " << province;
        os << ", PostCode= " << postCode << endl;
    }
    void Input(istream &is)
    {
        char tempHouseNo[30];
        cout << "Enter house number: ";
        is >> tempHouseNo;
        setHouseNo(tempHouseNo);
        cout << "Enter road ";
        is >> road;
        cout << "Enter village ";
        is >> village;
        cout << "Enter sub-district ";
        is >> subDistr;
        cout << "Enter District ";
        is >> district;
        cout << "Enter Province ";
        is >> province;
        cout << "Enter postcode ";
        is >> postCode;
    }
};
ostream &operator<<(ostream &os, Address &addr)
{
    addr.print(os);
    return os;
}
istream &operator>>(istream &is, Address &addr)
{
    addr.Input(is);
    return is;
}

/*
int main()
{
    Address a1, A1("aaaa", "1", "1", "1", "1", "1", 1), a3;
    a1.showAddress();
    A1.showAddress();
    a1 += A1;
    a1.showAddress();
    a1 = A1;
    a1.showAddress();
    cin >> a3;
    cout << a3;
}
    */
