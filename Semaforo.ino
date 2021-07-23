// Definição das portas dos LEDs
int orange = 13;
int green = 11;
int red = 12;

//Função onde é definido o tipo das portas e outros dados imutaveis
void setup() {
  pinMode(orange, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

// Função principal 
void loop() {
    //Ligando somente o LED vermelho e desligando os outros LEDs
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(orange, LOW);
    // Aguardando 1000ms antes de executar as proximas linhas
    delay(1000);
    //Ligando somente o LED verde e desligando os outros LEDs
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(orange, LOW);
    // Aguardando 1000ms antes de executar as proximas linhas
    delay(1000);
    //Ligando somente o LED laranja e desligando os outros LEDs
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(orange, HIGH);
    // Aguardando 1000ms antes de executar as proximas linhas
    delay(1000);
}
