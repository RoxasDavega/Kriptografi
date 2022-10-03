#include <iostream>
#include <conio.h>
#include<algorithm>
#include<bits/stdc++.h>
#include <string>
using namespace std;


int menuOption;

void menu(int numberAlgorithm);
void encryptDecrypt(int menuOpt, int numberAlgorithm);


string caesarCipher(int menuOpt, string text, int key);
string vigenereCipher(int menuOpt, string text, string keyword);
	string generateKeyVigenere(string k);
string railFence(int menuOpt, string text, int key);
string superEncrypt(int menuOpt, string text);


int main() {
	
	bool loop = true;
	while(true) {
		system("cls");
		cout << "\nMenu Enkripsi Dekripsi" << endl;
		cout << "1. Caesar Cipher" << endl;
		cout << "2. Vigenere Cipher" << endl;
		cout << "3. Rail Fence" << endl;
		cout << "4. Super Enkripsi" << endl;
		cout << "0. Keluar" << endl;
		cout << "Pilih: ";
		cin >> menuOption;
		
		if(menuOption >= 1  && menuOption <= 4) {
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
			cout << endl;
			if (numberAlgorithm == 1) {
				cout << "Caesar Cipher" << endl;
			} else if (numberAlgorithm == 2) {
				cout << "Vigenere Cipher" << endl;
			} else if (numberAlgorithm == 3) {
				cout << "Rail Fence" << endl;
			} else if (numberAlgorithm == 4) {
				cout << "Super Enkripsi" << endl;
			}
			cout << endl;
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
	string text, keyword, result;
	cin.ignore();
	int key;
	
	cout << "Input text: ";
	getline(cin, text);
	switch(numberAlgorithm) {
		case 1: cout << "\nKey Shift: ";
				cin >> key;
				//cin.ignore();
				result = caesarCipher(menuOpt, text, key);
				break;
		case 2: cout << "Key: ";
				cin >> keyword;
				result = vigenereCipher(menuOpt, text, keyword);
				break;
		case 3: cout << "\nKey: "; 
				cin >> key;
				result = railFence(menuOpt, text, key);
				break;
		case 4: result = superEncrypt(menuOpt, text);
				break;
	}
	cout << "\nResult: " << result;
	getch();
}


string caesarCipher(int menuOpt, string text, int key){
	int shift = key, s;
	string result;
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
    
	return result;
}

string vigenereCipher(int menuOpt, string text, string keyword) {
	string result;
	string key = generateKeyVigenere(keyword);
	if (menuOpt == 1) {
		
      	for (int i = 0, j = 0; i < text.length(); ++i) {
         char c = text[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         result += (c + key[j] - 2 * 'A') % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
         j = (j + 1) % key.length();
      }
      
	} else if (menuOpt == 2) {
		for (int i = 0, j = 0; i < text.length(); ++i) {
         char c = text[i];
         if (c >= 'a' && c <= 'z')
            c += 'A' - 'a';
         else if (c < 'A' || c > 'Z')
            continue;
         result += (c - key[j] + 26) % 26 + 'A';//added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
         j = (j + 1) % key.length();
      }
	}
	
	return result;
 }
 
string generateKey(string str, string key)
{
    int x = str.size();
 
    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

string railFence(int menuOpt, string text, int key) {
	string result = "";
	text.erase(remove(text.begin(), text.end(),' '), text.end());

	char rail[key][(text.length())];
	if (menuOpt == 1) {
	
    for (int i=0; i < key; i++)
        for (int j = 0; j < text.length(); j++) {
            rail[i][j] = '\n';
        }
 
    // to find the direction
    bool dir_down = false;
    int row = 0, col = 0;
 
    for (int i=0; i < text.length(); i++)
    {
        // check the direction of flow
        // reverse the direction if we've just
        // filled the top or bottom rail
        if (row == 0 || row == key-1)
            dir_down = !dir_down;
 
        // fill the corresponding alphabet
        rail[row][col++] = text[i];
 
        // find the next row using direction flag
        dir_down?row++ : row--;
    }
 
    //now we can construct the cipher using the rail matrix
    
    for (int i=0; i < key; i++)
        for (int j=0; j < text.length(); j++)
            if (rail[i][j]!='\n')
                result.push_back(rail[i][j]);
	} else if(menuOpt == 2) {
			 // filling the rail matrix to distinguish filled
	    // spaces from blank ones
	    for (int i=0; i < key; i++)
	        for (int j=0; j < text.length(); j++)
	            rail[i][j] = '\n';
	 
	    // to find the direction
	    bool dir_down;
	 
	    int row = 0, col = 0;
	 
	    // mark the places with '*'
	    for (int i=0; i < text.length(); i++)
	    {
	        // check the direction of flow
	        if (row == 0)
	            dir_down = true;
	        if (row == key-1)
	            dir_down = false;
	 
	        // place the marker
	        rail[row][col++] = '*';
	 
	        // find the next row using direction flag
	        dir_down?row++ : row--;
	    }
	 
	    // now we can construct the fill the rail matrix
	    int index = 0;
	    for (int i=0; i<key; i++)
	        for (int j=0; j<text.length(); j++)
	            if (rail[i][j] == '*' && index<text.length())
	                rail[i][j] = text[index++];
	 
	 
	    // now read the matrix in zig-zag manner to construct
	    // the resultant text
	
	 
	    row = 0, col = 0;
	    for (int i=0; i< text.length(); i++)
	    {
	        // check the direction of flow
	        if (row == 0)
	            dir_down = true;
	        if (row == key-1)
	            dir_down = false;
	 
	        // place the marker
	        if (rail[row][col] != '*')
	            result.push_back(rail[row][col++]);
	 
	        // find the next row using direction flag
	        dir_down?row++: row--;
	    }
	 
	}
	return result;
}

string generateKeyVigenere(string k) {
	string y;
	for (int i = 0; i < k.size(); ++i) {
         if (k[i] >= 'A' && k[i] <= 'Z')
            y += k[i];
         else if (k[i] >= 'a' && k[i] <= 'z')
            y += k[i] + 'A' - 'a';
      }
    return y;
}

string superEncrypt(int menuOpt, string text) {
	string result, keyString;
	int key;
	cout << "Key Shift: ";
	cin >> key;
	cin.ignore();
	cout << "Key String: ";
	getline(cin, keyString);


	result = caesarCipher(menuOpt, text, key);
	result = vigenereCipher(menuOpt, result, keyString);
	result = railFence(menuOpt, result, key);

	return result;
}


