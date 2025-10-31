const unsigned long TEMPO_VERMELHO = 6000; 
const unsigned long TEMPO_VERDE    = 4000; 
const unsigned long TEMPO_AMARELO  = 2000; 

const int PINO_VERMELHO = 8;
const int PINO_AMARELO  = 9;
const int PINO_VERDE    = 10;

class Luz {
  int pino;
  unsigned long duracao;
public:
  Luz(int p, unsigned long d) : pino(p), duracao(d) {}

  void begin() {
    pinMode(pino, OUTPUT);
    digitalWrite(pino, LOW);
  }

  void acender() {
    digitalWrite(pino, HIGH);
    delay(duracao);
    digitalWrite(pino, LOW);
  }
};


class Semaforo {
  Luz &vermelho;
  Luz &verde;
  Luz &amarelo;
public:
  Semaforo(Luz &v, Luz &vd, Luz &a) 
    : vermelho(v), verde(vd), amarelo(a) {}

  void begin() {
    vermelho.begin();
    verde.begin();
    amarelo.begin();
  }

  void ciclo() {
    vermelho.acender(); 
    verde.acender();    
    amarelo.acender();  
  }
};


Luz luzVermelha(PINO_VERMELHO, TEMPO_VERMELHO);
Luz luzVerde(PINO_VERDE, TEMPO_VERDE);
Luz luzAmarela(PINO_AMARELO, TEMPO_AMARELO);


Semaforo semaforo(luzVermelha, luzVerde, luzAmarela);

void setup() {
  semaforo.begin();
}

void loop() {
  semaforo.ciclo();
}
