#include <iostream>
#include<bits/stdc++.h>
#include <conio.h>
using namespace std;



int menuOption;

void menu(int numberAlgorithm);
void encryptDecrypt(int menuOpt, int numberAlgorithm);
//void decrypt(int menuOpt, int numberAlgorithm);

void caesarCipher(int menuOpt, string text);
void vigenereCipher(int menuOpt, string text);
	string generateKey(string str, string key);
void railFence(int menuOpt, string text);
string cipherText(string str, string key)
{
    string cipher_text;
 
    for (int i = 0; i < str.size(); i++)
    {
        // converting in range 0-25
        char x = (str[i] + key[i]) %26;
 
        // convert into alphabets(ASCII)
        x += 'A';
 
        cipher_text.push_back(x);
    }
    return cipher_text;
}

int main() {
	
	bool loop = true;
	while(true) {
		system("cls");
		cout << "\nMenu Enkripsi Dekripsi" << endl;
		cout << "1. Caesar Cipher" << endl;
		cout << "2. Vigenere Cipher" << endl;
		cout << "3. Rail Fence" << endl;
		cout << "0. Keluar" << endl;
		cout << "Pilih: ";
		cin >> menuOption;
		cin.ignore();
		if(menuOption >= 1  && menuOption <= 3) {
			menu(menuOption);
		} else if (menuOption == 0) {
			
			break;
		} else {
			cout << "Salah input" << endl;
			getch();
		}
		
	}

}

void menu(int numberAlgorithm){
	int menuOpt;
	bool loop = true;
	while(loop){
			system("cls");
			cout << "1. Enkripsi" << endl;
			cout << "2. Dekripsi" << endl;
			cout << "0. Keluar" << endl;
			cout << "Pilih: ";
			cin >> menuOpt;
			if (menuOpt == 1 || menuOpt == 2) {
				encryptDecrypt(menuOpt, numberAlgorithm);
			} else if (menuOpt == 0) {
				loop = false;
				break;
			} else {
				cout << "Salah input" << endl;
				getch();
			}
	}
}

void encryptDecrypt(int menuOpt, int numberAlgorithm) {
	string text;cin.ignore();
	cout << "Input text: ";
	getline(cin, text);
	
	switch(numberAlgorithm) {
		case 1: caesarCipher(menuOpt, text);
				break;
		case 2: vigenereCipher(menuOpt, text);
				break;
		case 3: railFence(menuOpt, text);
				break;
	}
}


void caesarCipher(int menuOpt, string text){
	int shift, s;
	string result = "";
	
	cout << "\nKey: ";
	
	cin >> shift;
	shift = shift % 26;
	if (menuOpt == 1){
		s = shift;
	} else if(menuOpt == 2){
		s = 26-shift;
	}
	
	 
    // traverse text
    for (int i = 0; i < text.length(); i++) {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i])) {
        	 result += char(int(text[i] + s - 65) % 26 + 65);
		} else if (islower(text[i])){
		 	// Encrypt Lowercase letters
            result += char(int(text[i] + s - 97) % 26 + 97);
        } else if (isspace(text[i])) {
        	result += " ";
		}
    }
 
	cout << "\nResult: " << result;	
	getch();	
}

void vigenereCipher(int menuOpt, string text) {
	string keyword =  "", result = "";
	cout << "Key: ";
	cin >> keyword;
	string key = generateKey(text, keyword);
	if (menuOpt == 1) {
		result = cipherText(text, key);
	} else if (menuOpt == 2) {
		for (int i = 0 ; i < text.size(); i++) {
	        // converting in range 0-25
	        char x = (text[i] - key[i] + 26) %26;
	 
	        // convert into alphabets(ASCII)
	        x += 'A';
	        result.push_back(x);
    	}
	}
	
	cout << "Result: " << result << endl;
	getch();
 }
 
string generateKey(string str, string key)
{
    int x = str.size();
 
    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (str.size() == key.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}
void railFence(int menuOpt, string text) {
	
}


