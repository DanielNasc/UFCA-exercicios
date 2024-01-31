#define CURTO 250
#define LONGO 500
#define OPT_LED 5
#define OPT_BUZZER 6
#define P99_PROTECT(...) __VA_ARGS__ 
#define NEXT_BEEP_DELAY 350
#define NEXT_LETTER_DELAY 1000

#define DL(l, la, arr, arr_size) int la[] = arr; \
  struct letra l = { \
    .s=arr_size, .beeps=la \
  };

struct letra {
  int s;
  int *beeps;
};

void otpt_letra(struct letra *l) {
  for (int i = 0; i < l->s; i++) {
    digitalWrite(OPT_LED, HIGH); // ligar LED
    tone(OPT_BUZZER,392); // iniciar nota no buzzer
    delay(l->beeps[i]); // esperar pelo tempo do beep (LONGO ou CURTO)
    digitalWrite(OPT_LED, LOW); // desligar LED
    noTone(OPT_BUZZER); // terminar nota no buzzer

    delay(NEXT_BEEP_DELAY);
  }

  delay(NEXT_LETTER_DELAY);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {

  DL(a, LA, P99_PROTECT({ CURTO, LONGO }), 2)
  DL(e, LE, P99_PROTECT({ CURTO }), 1)
  DL(o, LO, P99_PROTECT({ LONGO, LONGO, LONGO }), 3)
  DL(u, LU, P99_PROTECT({ CURTO, CURTO, LONGO }), 3)

  DL(t, LT, P99_PROTECT({ LONGO }), 1)
  DL(m, LM, P99_PROTECT({ LONGO, LONGO }), 2)

  otpt_letra(&e);
  otpt_letra(&u);
  otpt_letra(&t);
  otpt_letra(&e);
  otpt_letra(&a);
  otpt_letra(&m);
  otpt_letra(&o);

  delay(2000);
}
