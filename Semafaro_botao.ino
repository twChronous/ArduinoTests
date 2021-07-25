// Definição das portas dos LEDs
int orange = 13;
int green = 11;
int red = 12;
int button = 10;

// Define um estado para o botão
int buttonState = 0;

// Função onde é definido o tipo das portas e outros dados imutaveis
void setup() {

  // Define os pinos como saida de dados
  pinMode(orange, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);

  // Define os pinos como entrada de dados
  pinMode(button, INPUT);
}

// Função principal
void loop() {

  // Leitura do botão é passada a variavel de estado buttonState
  buttonState = digitalRead(button);

  // Quando o estado for igual a LOW ou seja o botão não estiver pressionado o semafaro irá funcionar
  if (buttonState == LOW) {
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
    // Quando o estado for diferente a LOW ou seja o botão estiver pressionado o semafaro não irá funcionar
  } else {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(orange, LOW);
  }
}
