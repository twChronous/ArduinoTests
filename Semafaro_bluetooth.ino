// Definição das portas dos LEDs
int orange = 13;
int green = 11;
int red = 12;

// Porta do bluetooth
char Incoming_value = 0;

//Função onde é definido o tipo das portas e outros dados imutaveis
void setup() {
  Serial.begin(9600);
  pinMode(orange, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

// Função que liga e desliga os LEDs
void Semaforo(bool start) {
  if (start) {
    // Escrevendo no terminal que os LEDs estão acesas para que quem está no bluetooth saiba sem precisar olhar
    Serial.print("Ligando luzes...");
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
  if (!start) {
    // Escrevendo no terminal que os LEDs estão apagadas para que quem está no bluetooth saiba sem precisar olhar
    Serial.print("Desligando luzes...");
    // Desligando todos os LEDs
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(orange, LOW);
  }
}
//Função principal
void loop() {
    //Verifica se existe sinal do bluetooth
  if (Serial.available() > 0) {
    Incoming_value = Serial.read();
     //Escreve os dados recebidos saltando uma linha entre eles
    Serial.print(Incoming_value);
    Serial.print("\n");
    // Caso algum desses sinais seja 1 ou 0 os LEDs se ligam ou desligam
    if (Incoming_value == '1') Semaforo(true);
    else if (Incoming_value == '0') Semaforo(false);
  }
}
