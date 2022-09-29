
/* Homework #2 Steven Howell */
#include <iostream>
#include <vector>
#include <sstream>
#include <list>

template<typename T>
class Stack {

public:
    std::list<T> pool;
    //int size_c = 0;
    Stack() {
    }
    void clear() {
        pool.clear();
    }
    bool isEmpty() const {
        return pool.empty();
    }
    T& topEl() {
        return pool.back();
    }
    T pop() {
        T el = pool.back();
        pool.pop_back();
        return el;
    }
    void push(const T& el) {
        pool.push_back(el);
    }
    int size(){
       return pool.size();
    }


};





std::vector<int> binary(int dec){
    std::vector<int> yeet;
    int tmp = dec;
    //int loc;
    while(tmp>0){
        //std::cout<<tmp%2<<std::endl;
        yeet.push_back(tmp % 2);
        tmp = tmp/2;
        //std::cout<<tmp<<std::endl;

        //loc++;
    }

    return yeet;
}

std::vector<int> octagional(int dec){
    std::vector<int> yeet;
    int tmp = dec;
    //int loc;
    while(tmp>0){
        yeet.push_back(tmp % 8);
        tmp = tmp/8;
        //loc++;
    }

    return yeet;
}
std::vector<char> hexadecimal(int dec){
    std::vector<char> yeet;
    int tmp = dec;
    //int loc;
    while(tmp>0){
        int convert = (tmp % 16);
        if(convert>=10){
            yeet.push_back(convert+55);
        }
        else{
            yeet.push_back(convert+48);
        }
        tmp = tmp/16;
        //loc++;
    }

    return yeet;
}

void menu(){
    std::cout.width(25);
    std::cout<<"MENU"<<std::endl<<std::endl<<"Binary (0), Octal (1), Hexadecimal (2)"<<std::endl;
    std::cout<<"Exit Program (3)"<<std::endl<<"Choose?";

}
int STI(std::string str){
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}
Stack<int> dec;
Stack<int> oct;
Stack<char> hex;

std::string decision(const std::string& user_input){
    std::string key = "null";

    std::string del = " ";//parameter to use
    std::stringstream ss(user_input);
    std::string word;
    std::vector<std::string> wordlist{};//command vector
/*
while (!ss.eof()) {

    getline(ss, word, del);
    std::cout << word << std::endl;
}
*/

    while (ss >> word) {//splits string by space
        //std::cout << word << std::endl;

        wordlist.push_back(word);//puts the individual strings into a vector
        if(wordlist.size()>2){//if there is are 3 detected inputs then return error
            std::cout<<"Input has too many parameters. Please try again."<<std::endl;
            //wordlist.empty();
            return key;
            //break;
        }
    }
    //checks if the first input matches the command number and is a valid input
    if((wordlist.at(0) == ("0")||
        wordlist.at(0) == ("1")||
        wordlist.at(0) == ("2"))&&
        wordlist.size()!=2){
        std::cout<<"No input parameter"<<std::endl;
        return key;
    }
    /*
    else if ((wordlist.at(0) == ("2")||
              wordlist.at(0) == ("3")||
              wordlist.at(0) == ("5")||
              wordlist.at(0) == ("8")||
              wordlist.at(0) == ("9")||
              wordlist.at(0) == ("11"))&&
             wordlist.size()!=1){
        std::cout<<"too many inputs"<<std::endl;
        return key;

    }
     */

    if(wordlist.size() == 2){
        for(char i : wordlist.at(1)){
            if(!std::isdigit(i)){
                std::cout<<"input is not a int or char"<<std::endl;
                return key;
            }
        }

    }

        if(wordlist.at(0) == "0"){
            std::vector<int> yee = binary(STI(wordlist.at(1)));
            for(int j = yee.size()-1;j>=0;j--) {
                //std::cout<<yee.at(j)<<std::endl;
                dec.push(yee.at(j));
                //std::cout<<dec.topEl()<<std::endl;
                //std::cout<<dec.size()<<std::endl;
                //dec.push(1);
            }
            while(dec.size()>0) {
                std::cout << dec.pop() << " ";
            }
            std::cout<<std::endl;
        }

        else if(wordlist.at(0) == "1"){
            std::vector<int> yee = octagional(STI(wordlist.at(1)));
            for(int j = yee.size()-1;j>=0;j--) {
                oct.push(yee.at(j));
                //dec.push(1);
            }
            while(oct.size()>0) {
                std::cout << oct.pop() << " ";
            }
            std::cout<<std::endl;
        }

        else if(wordlist.at(0) == "2"){
            std::vector<char> yee = hexadecimal(STI(wordlist.at(1)));
            for(int j = 0;j<yee.size();j++) {
                hex.push(yee.at(j));
                //dec.push(1);
            }
            while(hex.size()>0) {
                std::cout << hex.pop() << " ";
            }
        }
        else if(wordlist.at(0) == "3"){
            key = "exit"; //pass exit code
        }

        return key;
}

int main() {
    //menu();
    std::string exit = "go";


    while(exit != "exit"){//if exit is caught then stop loop
        menu();
        std::string u_input;
        getline(std::cin,u_input);//get input line
        //std::cout<<"decision"<<std::endl;


        exit = decision(u_input);//decide on output checks if it should exit

    }
    std::cout<<"Program finished have a nice day!"<<std::endl;//a friendly message
    return 0;
}
