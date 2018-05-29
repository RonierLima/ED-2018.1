#include <iostream>
#include <list>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "sftext.h"

using namespace std;

struct Ambiente{
    list<char> texto;
    list<char>::iterator cursor;
    Ambiente(){
        cursor = texto.end();
    }

    string toString(){
        stringstream ss;
        for(auto it = texto.begin(); it != texto.end(); it++){
            if(it == cursor)
                ss << "|";
            ss << (*it);
        }
        if(cursor == texto.end())
            ss << "|";
        return ss.str();
    }
};

int main(){

    list<Ambiente> ambientes;
    list<Ambiente>::iterator itAmb;
    Ambiente amb;
    amb.cursor = amb.texto.end();
    ambientes.push_back(amb);
    itAmb = --ambientes.end();

    sf::RenderWindow janela(sf::VideoMode(800, 600), "Janela");

    while(janela.isOpen()){

        sf::Event event;
        while(janela.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                janela.close();

            if(event.type == sf::Event::KeyPressed){
                if(event.key.control && (event.key.code == sf::Keyboard::Z)){
                    if((amb.cursor != amb.texto.begin())){
                        itAmb --;
                        ambientes.push_back(amb);
                        amb = *itAmb;
                        cout << "control z" << endl;
                    }
                }
                else if(event.key.control && (event.key.code == sf::Keyboard::R)){
                    if(itAmb != ambientes.end()){
                        amb = *itAmb++;
                        cout << "control r" << endl;
                    }
               }
                else if((event.key.code >= sf::Keyboard::A) && (event.key.code <= sf::Keyboard::Z)){
                    char tecla = (event.key.code - sf::Keyboard::A) + 'a';
                    ambientes.push_back(amb);
                    amb.texto.insert(amb.cursor, tecla);
                    itAmb = ambientes.end();
                    cout << tecla << endl;
                }
                else if((event.key.code == sf::Keyboard::Return)){
                    amb.texto.insert(amb.cursor, '\n');
                    ambientes.push_back(amb);
                    itAmb = ambientes.end();
                    cout << "espaco" << endl;
                }
                else if((event.key.code == sf::Keyboard::Space)){
                    ambientes.push_back(amb);
                    amb.texto.insert(amb.cursor, ' ');
                    itAmb = ambientes.end();
                    cout << "espaco" << endl;
                }
                else if(event.key.code == sf::Keyboard::BackSpace){
                    if(amb.cursor != amb.texto.begin()){   
                        ambientes.push_back(amb);
                        amb.texto.erase(amb.cursor++, amb.cursor--);
                        itAmb = ambientes.end();
                        cout << "backspace" << endl;
                    }

                }
                else if(event.key.code == sf::Keyboard::Delete){
                    if(amb.cursor != amb.texto.end()){
                        ambientes.push_back(amb);
                        amb.texto.erase(amb.cursor++);
                        itAmb = ambientes.end();
                        cout << "delete" << endl;
                    }
                }
                else if(event.key.code == sf::Keyboard::Left){
                    amb.cursor--;
                }
                else if(event.key.code == sf::Keyboard::Right){
                    amb.cursor++;
                }
            }
        }

        auto pos = sf::Vector2f(30, 50);
        janela.clear();
        janela.draw(sfText(pos, amb.toString(), sf::Color::White, 30));
        janela.display();
    }
    return 0;
}

