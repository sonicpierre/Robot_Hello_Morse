#include <Arduino.h>
#include <string>
#include <vector>

int court = 300;
int lon = 3 * court;
int vide_same_letter = court;
int vide_same_word = 3 * court;
int vide_between_words = 7 * court;

std::string world = "RIP";
int LETTER = 0;

std::vector<std::vector<int>> alphabet (26);

int to_int(char lettre) {
  return static_cast<int>(lettre) - 65;
}

std::vector<std::vector<int>> alphabet_init(std::vector<std::vector<int>>) {

  alphabet[to_int('P')] = {court, lon, lon, court};
  alphabet[to_int('I')] = {court, court};
  alphabet[to_int('E')] = {court};
  alphabet[to_int('R')] = {court, lon, court};

  return alphabet;
}

void setup() {
  // permet l'ouverture du port du micro-controller pour communiquer avec l'ordinateur
  Serial.begin(115200);
  pinMode(D0, OUTPUT);
  alphabet = alphabet_init(alphabet);
}

/*
Augmente progressivement la vitesse de 
*/

void loop() {
  // run while the card
  // build -> upload -> serial monitor

  if( LETTER == static_cast<int>(world.size())) {
    delay(vide_between_words);
    LETTER = 0;
  }

  for (auto i : alphabet[to_int(world[LETTER])]) {
    digitalWrite(D0, HIGH);
    delay(i);
    digitalWrite(D0, LOW);
    delay(vide_same_letter);
  }

  delay(vide_same_word);
  
  LETTER += 1;
}