#include "Info.h"

Info::Info(int n){
    ips = new HashTable(n);
}

//O(1)
unsigned long long int Info::convertIp(string ip) {

    unsigned long long int ipNumber = 0;
    string newIP;
    string element;
    int i = 0;

    if (ip.length() < 4) {
        cout << "Ip inexistente" << endl;
    }
    else {
        stringstream s(ip);
        while (getline(s, element, '.')) {
            if (i == 3) {
                stringstream e(element);
                getline(e, element, ':');
            }

            if (element.length() == 1)
                newIP += "00" + element;
            else if (element.length() == 2)
                newIP += "0" + element;
            else if (element.length() == 3)
                newIP += element;
        
            i++;
        }

        stringstream ss(newIP);
        ss >> ipNumber;
    }

    return ipNumber;
}

//O(n)
void Info::readData(string fileName){

    string line, temp, ip, previousIp = "";
    unsigned long long int ipKey;
    int counter = 1, i = 0;

    fstream file;

    file.open(fileName, ios::in);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream s(line);

            getline(s, temp, ',');
            getline(s, temp, ',');
            getline(s, temp, ',');
            getline(s, temp, ',');

            stringstream s1(temp);

            getline(s1, ip, ':');

            if (i != 0)
                if (previousIp == ip)
                    counter++;
                else {
                    ipKey = convertIp(previousIp);
                    HashNode tempNode = { ipKey, previousIp, counter };
                    ips->insert(tempNode);
                    counter = 1;
                }

            i++;
            previousIp = ip;
        }

        file.close();
    }
    else
        cout << "No se pudo abrir el archivo" << endl;
}

//O(n)
void Info::printData(){
    ips->printElements();
}

//O(1)
void Info::findIp(string ip){
    ips->find(convertIp(ip));
}
