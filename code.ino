int speakerPin = 9;//it's the number of pin
int length = 28;//it's the length of the music
int evolution;
char notes[] =  "GGAGcB GGAGdc GGxecBA yyecdc*";//it's the order of notes in a table
float beats[] = {2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 8, 16, 1, 2, 2, 8, 8, 8, 16, };//this is the time that each note will play
int tempo = 350;//it's the tempo

void playNote(char note, float duration) {
  
   char names[] =   { 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'x', 'y','*', };// it's the name of notes in a table
   double tones[] = {65.4, 73.4, 82.4, 87.3, 98, 110, 123.5, 130.8, 146.8, 164.8, 174.6, 196, 220, 246.9, 261.6, 293.7,};// it's frequency of notes in a table
   int evolution;

   while (names[evolution]!= '*'){
    if (names[evolution] == note){
      double TDM = 1000000/tones[evolution]/3;//it's the time of a half-units in microseconds
      Serial.println(names[evolution]);
      for (long a = 0; a < tones[evolution]*duration; a++){
        digitalWrite(speakerPin, HIGH); 
        delayMicroseconds(TDM); 
        digitalWrite(speakerPin, LOW);
        delayMicroseconds(TDM); 
      }
    }
    evolution ++;
   }
}
void setup() {
  
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  double TBS = 1./((double)tempo/60);// it's the time of a beat in second
  for (int evolution = 0; notes[evolution]!= '*'; evolution ++){// evolution of notes
    Serial.print(TBS);//                     |
    Serial.print("\t");//                    |
    Serial.print(evolution);//               |
    Serial.print("\t");//                    |
    Serial.print(beats[evolution]);//        } informations for the user
    Serial.print("\t");//                    |
    Serial.print(notes[evolution]);//        |
    Serial.print("\t");//                    |
    Serial.println(beats[evolution]*TBS);//  |
    playNote(notes[evolution], beats[evolution]*TBS);
    float decimalPart = beats[evolution] - (int)beats[evolution];// we keep the decimal part of beats's evolution
    if(decimalPart!=0){
      Serial.println(decimalPart);
      decimalPart= 1-decimalPart;
      Serial.println(decimalPart);
    }
  }  
}
