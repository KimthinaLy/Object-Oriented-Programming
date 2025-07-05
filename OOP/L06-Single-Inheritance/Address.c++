#include <iostream>
#include<string.h>
using namespace std;
class Address {
    char houseNo[30];
    char road[30];
    char village[30];
    char subDistr[30];
    char district[30];
    char province[30];
    int postCode;
public:
    Address() {
        setHouseNo((char*)""); setRoad((char*)""); setVillage((char*)""); setSubDistr((char*)"");
        setDistr((char*)""); setProvince((char*)""); setPostCode(0);
    }
    Address(char* houseNum, char* r, char* vil, char* subD, char* d, char* p, int pCode) {
        setHouseNo(houseNum); setRoad(r); setVillage(vil); setSubDistr(subD);
        setDistr(d); setProvince(p); setPostCode(pCode);
    }
    Address( char* r, char* vil, char* subD, char* d, char* p, int pCode) {
        setHouseNo((char*)""); setRoad(r); setVillage(vil); setSubDistr(subD);
        setDistr(d); setProvince(p); setPostCode(pCode);
    }
    Address( char* vil, char* subD, char* d, char* p, int pCode) {
        setHouseNo((char*)""); setRoad((char*)""); setVillage(vil); setSubDistr(subD);
        setDistr(d); setProvince(p); setPostCode(pCode);
    }
    Address( char* subD, char* d, char* p, int pCode) {
        setHouseNo((char*)""); setRoad((char*)""); setVillage((char*)""); setSubDistr(subD);
        setDistr(d); setProvince(p); setPostCode(pCode);
    }
    Address( char* p, int pCode) {
        setHouseNo((char*)""); setRoad((char*)""); setVillage((char*)""); setSubDistr((char*)"");
        setDistr((char*)""); setProvince(p); setPostCode(pCode);
    }
    void setHouseNo (char* houseNum) {
        strcpy(houseNo, houseNum);
    }
    void setRoad(char* r) {
        strcpy(road, r);
    }
    void setVillage(char* vil) {
        strcpy(village, vil);
    }
    void setSubDistr(char* subDis) {
        strcpy(subDistr, subDis);
    }
    void setDistr(char* Dis) {
        strcpy(district, Dis);
    }
    void setProvince(char* prov) {
        strcpy(province, prov);
    }
    void setPostCode(int pCode) {
        postCode= pCode;
    }
    char* getHouseNo() {
        return houseNo;
    }
    char* getRoad() {
        return road;
    }
    char* getVillage() {
        return village;
    }
    char* getSubDistr() {
        return subDistr;
    }
    char* getDistr() {
        return district;
    }
    char* getProvince() {
        return province;
    }
    int getpostCode() {
        return postCode;
    }
    void showAddress() {
        cout << "Address: " << endl;
        cout << "House No.:" << houseNo << endl;
        cout << "Road: " << road << endl;
        cout << "Village: " << village << endl;
        cout << "Sub-District: " << subDistr << endl;
        cout << "District: " << district << endl;
        cout << "Province: " << province << endl;
    }
    ~Address() {
        cout << "Destructor: Address " << endl;
    }
};
