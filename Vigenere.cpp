#include <iostream>
#include <string>

std::string Encrypt(std::string PlainText, std::string Key){
    int cipherLen = PlainText.length();
    int keyLen = Key.length();
    std::string cipher;
    for(int i = 0; i < cipherLen; i++){
        cipher.push_back(char(((int(PlainText[i]) + int(Key[i % keyLen])) % 26) + 65));
    }
    return cipher;
}

std::string Decrypt(std::string Cipher, std::string Key){
    int cipherLen = Cipher.length();
    int keyLen = Key.length();
    std::string decrypt;
    for(int i = 0; i < cipherLen; i++){
        decrypt.push_back(char(((int(Cipher[i]) - int(Key[i % keyLen]) + 26) % 26) + 65));
    }
    return decrypt;
}

int main(int argc, char* argv[]){
    std::string PlainText, Key, encryption, decryption, tbd;
    Key = argv[2];
    PlainText = argv[1];
    tbd = argv[3];
    if(tbd == "encrypt"){
        encryption = Encrypt(PlainText, Key);
        std::cout << "Encrypted: " << encryption << std::endl;
    }
    else if(tbd == "decrypt"){
        decryption = Decrypt(PlainText, Key);
        std::cout << "Decrypted: " << decryption << std::endl;
    }
    else{
        std::cout << "Invalid command" << std::endl;
    }

    /*
    encryption = Encrypt(PlainText, Key);
    decryption = Decrypt(encryption, Key);
    std::cout << "Encrypted: " << encryption << std::endl;
    std::cout << "Decrypted: " << decryption;
     */
    return 0;
}